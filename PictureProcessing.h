//
// Created by Sveta Morkva on 9/10/20.
//

#ifndef KPI_LAB1_PICTUREPROCESSING_H
#define KPI_LAB1_PICTUREPROCESSING_H

#include <opencv2/opencv.hpp>

class PictureProcessing {
public:
    void saveVideoFromCam();
    cv::VideoCapture loadVideoFromDisk();
    void processVideo(cv::VideoCapture cap);

    void saveImgFromCam();
    cv::Mat loadImgFromDisk();
    void processImg(cv::Mat &img);

private:
    enum objects {
        ob_line = 0,
        ob_rectangle,
        ob_circle
    };
    std::string originWinName = "Origin";
    std::string resultWinName = "Result";
};


#endif //KPI_LAB1_PICTUREPROCESSING_H
