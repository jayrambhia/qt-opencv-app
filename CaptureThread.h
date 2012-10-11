
#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

// Qt header files
#include <QThread>
#include <QtGui>
// OpenCV header files
#include "opencv/highgui.h"

using namespace cv;

class ImageBuffer;

class CaptureThread : public QThread
{
    Q_OBJECT

public:
    CaptureThread(ImageBuffer *buffer);
    bool connectToCamera(int);
    void disconnectCamera();
    void stopCaptureThread();
    int getAvgFPS();
    bool isCameraConnected();
    int getInputSourceWidth();
    int getInputSourceHeight();
private:
    void updateFPS(int);
    ImageBuffer *imageBuffer;
    VideoCapture cap;
    Mat grabbedFrame;
    QTime t;
    QMutex stoppedMutex;
    int captureTime;
    int avgFPS;
    QQueue<int> fps;
    int sampleNo;
    int fpsSum;
    volatile bool stopped;
protected:
    void run();
};

#endif // CAPTURETHREAD_H
