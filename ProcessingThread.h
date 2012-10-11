
#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

#include "Structures.h"

// Qt header files
#include <QThread>
#include <QtGui>
// OpenCV header files
#include <opencv/highgui.h>

using namespace cv;

class ImageBuffer;

class ProcessingThread : public QThread
{
    Q_OBJECT

public:
    ProcessingThread(ImageBuffer *imageBuffer, int inputSourceWidth, int inputSourceHeight);
    ~ProcessingThread();
    void stopProcessingThread();
    int getAvgFPS();
    int getCurrentSizeOfBuffer();
    Rect getCurrentROI();
private:
    void updateFPS(int);
    void setROI();
    void resetROI();
    ImageBuffer *imageBuffer;
    volatile bool stopped;
    int inputSourceWidth;
    int inputSourceHeight;
    int currentSizeOfBuffer;
    Mat currentFrame;
    Mat currentFrameGrayscale;
    Rect originalROI;
    Rect currentROI;
    QImage frame;
    QTime t;
    int processingTime;
    QQueue<int> fps;
    int fpsSum;
    int sampleNo;
    int avgFPS;
    QMutex stoppedMutex;
    QMutex updateMembersMutex;
    Size frameSize;
    Point framePoint;
    // Image processing flags
    bool grayscaleOn;
    bool smoothOn;
    bool dilateOn;
    bool erodeOn;
    bool flipOn;
    bool cannyOn;
    // Image processing settings
    int smoothType;
    int smoothParam1;
    int smoothParam2;
    double smoothParam3;
    double smoothParam4;
    int dilateNumberOfIterations;
    int erodeNumberOfIterations;
    int flipCode;
    double cannyThreshold1;
    double cannyThreshold2;
    int cannyApertureSize;
    bool cannyL2gradient;
    // Task data
    bool setROIFlag;
    bool resetROIFlag;
    Rect selectionBox;
protected:
    void run();
private slots:
    void updateImageProcessingFlags(struct ImageProcessingFlags);
    void updateImageProcessingSettings(struct ImageProcessingSettings);
    void updateTaskData(struct TaskData);
signals:
    void newFrame(const QImage &frame);
};

#endif // PROCESSINGTHREAD_H
