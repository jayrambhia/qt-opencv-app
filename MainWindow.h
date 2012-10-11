
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"
#include "Structures.h"

#define QUOTE_(x) #x
#define QUOTE(x) QUOTE_(x)

class CameraConnectDialog;
class ImageProcessingSettingsDialog;
class Controller;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeImageProcessingFlagsStructure();
    void initializeTaskDataStructure();
    void setInitialGUIState();
    void signalSlotsInit();
private:
    CameraConnectDialog *cameraConnectDialog;
    ImageProcessingSettingsDialog *imageProcessingSettingsDialog;
    Controller *controller;
    ImageProcessingFlags imageProcessingFlags;
    TaskData taskData;
    QString appVersion;
    int sourceWidth;
    int sourceHeight;
    int deviceNumber;
    int imageBufferSize;
    bool isCameraConnected;
public slots:
    void connectToCamera();
    void disconnectCamera();
    void about();
    void clearImageBuffer();
    void setGrayscale(bool);
    void setSmooth(bool);
    void setDilate(bool);
    void setErode(bool);
    void setFlip(bool);
    void setCanny(bool);
    void setImageProcessingSettings();
    void updateMouseCursorPosLabel();
    void newMouseData(struct MouseData);
private slots:
    void updateFrame(const QImage &frame);
signals:
    void newImageProcessingFlags(struct ImageProcessingFlags imageProcessingFlags);
    void newTaskData(struct TaskData taskData);
};

#endif // MAINWINDOW_H
