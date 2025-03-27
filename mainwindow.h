#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <links.h>
#include <errorwindow.h>

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT

    ErrorWindow* errWindow;

    QWidget *identification;
    QWidget *deepfake;
    QWidget *virtualCamera;

    QLabel *portrait;
    QLabel *identitiy;
    QLabel *passTemp;
    QLabel *portrait_2;
    QLabel *platform;
    QLabel *videoMode;
    QLabel* qualityMode;
    QLabel* recomendation;
    QLabel* identDoc;
    QLabel* videoKYC;

    QPushButton* browse;
    QPushButton* none;
    QPushButton* effect;
    QPushButton* run;
    QPushButton* getSmt;
    QPushButton* save;
    QPushButton* browse_2;
    QPushButton* createVideo;
    QPushButton* emptyBtn;
    QPushButton* browseDoc;
    QPushButton* browseKYC;
    QPushButton* connectBr;
    QPushButton* connectEm;

    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_1;
    QFrame *frame_2_1;

    QComboBox *countryComboBox;

    QCheckBox *menCheckBox;
    QCheckBox *womenCheckBox;
    QCheckBox *fastMode;
    QCheckBox *proMode;
    QCheckBox *expertMode;
    QCheckBox *sd;
    QCheckBox *mp4;
    QCheckBox *hdMp4;

    QHBoxLayout *checkBoxsLayout;
    QHBoxLayout *btnsLayout;
    QHBoxLayout *mainLayout;
    QHBoxLayout *mainLayout_2;
    QHBoxLayout* videoModesLayout;
    QHBoxLayout* qualityModesLayout;
    QHBoxLayout* docLayout;
    QHBoxLayout* KYCLayout;
    QHBoxLayout* connectLayout;

    QVBoxLayout *layout1;
    QVBoxLayout *layout1_2;
    QVBoxLayout *layout1_3;
    QVBoxLayout *layout2;
    QVBoxLayout *layout2_1;
    QVBoxLayout *layout2_2;
    QVBoxLayout *layout3;
    QVBoxLayout* identificationLayout;
    QVBoxLayout* deepfakeLayout;
    QVBoxLayout* identityLayout;
    QVBoxLayout* cameraLayout;

    QComboBox *passportComboBox;

    QListWidget* listWidget;

    QTextEdit* editArea;
    QTextEdit* inputDoc;
    QTextEdit* inputKYC;

    QTabWidget *tabWidget;

    QVector<QPushButton*> btns;

    QMenu *menu;

public:
    MainWindow(QWidget *parent = nullptr);
    void initPortraitAndIdentity();
    void initPassTemplate();
    void initBtnsAndFrame();
    void initIdentificationPage();
    void initPrtAndFr();
    void initKYCAndList();
    void initModes();
    void initDeepfakePage();
    void initDocumentAndKYC();
    void initButtons();
    void initVirtualCameraPage();
    ~MainWindow();
};
#endif // MAINWINDOW_H
