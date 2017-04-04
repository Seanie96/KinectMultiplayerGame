#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Skeletal/Skeletal.h"

void Skeletal::setup(int width, int height) {
	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();
	kinect.initInfraredSource();
	kinect.initBodySource();
	kinect.initBodyIndexSource();

	previewWidth = width;
	previewHeight = height;
}

/*
 * This method gets the hand positions of all the bodies infront of the Kinect. It returns a list of pairs,
 *  each pair containing a hand posiiton and a given body index.
 */
vector< pair<int, ofVec2f> > Skeletal::gethandPositions(ofxKFW2::ProjectionCoordinates proj) {
	int numOfBodies = 0;
	vector<ofxKFW2::Data::Body> bodies;
	bodies = kinect.getBodySource()->getBodies();
	for (auto body : bodies) {
		numOfBodies++;
	}

	handPositions.clear();

	int w, h;
	w = 1920;
	h = 1080;

	coordinateMapper = kinect.getBodySource()->getCoordinateMapper();
	int i = 0;
	for (auto & body : bodies) {
		if (!body.tracked) continue;

		map<JointType, ofVec2f> jntsProj;

		for (auto & j : body.joints) {
			ofVec2f & p = jntsProj[j.second.getType()] = ofVec2f();

			TrackingState state = j.second.getTrackingState();
			if (state == TrackingState_NotTracked) continue;

			p.set(j.second.getProjected(coordinateMapper, ofxKFW2::ProjectionCoordinates::ColorCamera));
			p.x = 0 + p.x / w * previewWidth;
			p.y = 0 + p.y / h * previewHeight;
		}
		handPositions.push_back(pair<int, ofVec2f>(i, jntsProj[JointType_HandLeft]));
		handPositions.push_back(pair<int, ofVec2f>(i, jntsProj[JointType_HandRight]));
		i++;
	}
	return handPositions;
}

/*
 * Update the Data stream by taking another frame from the KinectV2 camera.
 */
void Skeletal::update() {
	kinect.update();
}

/*
 * Draw the frames from the kinectV2 camera.
 */
void Skeletal::drawBodies() {
	kinect.getColorSource()->draw(0, 0, previewWidth, previewHeight);
}