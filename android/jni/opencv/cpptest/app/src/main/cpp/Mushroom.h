#ifndef CPPTEST_MUSHROOM_H
#define CPPTEST_MUSHROOM_H
#include <vector>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
/**
 * a mushroom to be detected by the app
 */
class Mushroom {
public:
    /** default constructor */
    Mushroom();
    /** copy constructor */
    Mushroom(const Mushroom&);

    /** assignment operator */
    Mushroom& operator=(const Mushroom& other);

    /** BGR color */
    Vec3b color;
    string mushRoomName;
    bool round; //ist der Pilz Rund, 1 ja, 0 nein
};

#endif //CPPTEST_MUSHROOM_H
