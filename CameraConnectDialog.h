#ifndef CAMERACONNECTDIALOG_H
#define CAMERACONNECTDIALOG_H

#include "ui_CameraConnectDialog.h"

class CameraConnectDialog : public QDialog, private Ui::CameraConnectDialog
{
    Q_OBJECT

public:
    CameraConnectDialog(QWidget *parent = 0);
    void setDeviceNumber();
    void setImageBufferSize();
    int getDeviceNumber();
    int getImageBufferSize();
    bool getDropFrameCheckBoxState();
    int getCaptureThreadPrio();
    int getProcessingThreadPrio();
public slots:
    void resetToDefaults();
private:
    void setupComboBoxes();
};

#endif // CAMERACONNECTDIALOG_H
