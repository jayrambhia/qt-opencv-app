

#ifndef IMAGEPROCESSINGSETTINGSDIALOG_H
#define IMAGEPROCESSINGSETTINGSDIALOG_H

#include "ui_ImageProcessingSettingsDialog.h"
#include "Structures.h"

class ImageProcessingSettingsDialog : public QDialog, private Ui::ImageProcessingSettingsDialog
{
    Q_OBJECT

public:
    ImageProcessingSettingsDialog(QWidget *parent = 0);
    void updateDialogSettingsFromStored();
private:
    ImageProcessingSettings imageProcessingSettings;
public slots:
    void resetAllDialogToDefaults();
    void updateStoredSettingsFromDialog();
private slots:
    void resetSmoothDialogToDefaults();
    void resetDilateDialogToDefaults();
    void resetErodeDialogToDefaults();
    void resetFlipDialogToDefaults();
    void resetCannyDialogToDefaults();
    void validateDialog();
    void smoothTypeChange(QAbstractButton *);
signals:
    void newImageProcessingSettings(struct ImageProcessingSettings p_settings);
};

#endif // IMAGEPROCESSINGSETTINGSDIALOG_H
