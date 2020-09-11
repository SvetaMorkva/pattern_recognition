//
// Created by Sveta Morkva on 9/10/20.
//

#include "PictureProcessing.h"

using namespace cv;

void PictureProcessing::saveImgFromCam() {
    VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera!" << std::endl;
        return;
    }

    Mat frame;
    camera >> frame;
    if (frame.empty()) {
        return;
    }

    imshow(originWinName, frame);
    imwrite(originWinName + ".jpg", frame);
}

Mat PictureProcessing::loadImgFromDisk() {
    return imread(originWinName + ".jpg", 1 );
}

void PictureProcessing::processImg(Mat &img) {
    if (img.empty()) {
        std::cerr << "ERROR: Could not process image!" << std::endl;
        return;
    }
    cvtColor(img, img, COLOR_BGR2GRAY);
    cvtColor(img, img, COLOR_GRAY2BGR);
    int objNum = rand() % 20 + 1;
    for (int i = 0; i < objNum; i++) {
        Point first = Point(rand() % img.cols, rand() % img.rows);
        Point second = Point(rand() % img.cols, rand() % img.rows);
        Scalar color = Scalar(rand() % 255, rand() % 255, rand() % 255);
        int radius = rand() % img.rows / 4;
        int objType = rand() % 4;
        switch(objType) {
        case ob_line:
            line(img, first, second, color);
            break;
        case ob_rectangle:
            rectangle(img, first, second, color);
            break;
        case ob_circle:
            circle(img, first, radius, color);
            break;
        default:
            break;
        }
    }
}

void PictureProcessing::saveVideoFromCam() {
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        std::cout << "Error opening video stream" << std::endl;
        return;
    }

    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);

    VideoWriter video(originWinName + ".avi", VideoWriter::fourcc('M','J','P','G'),
                      10, Size(frame_width,frame_height));
    while (1) {
        Mat frame;
        cap >> frame;

        if (frame.empty()) {
            break;
        }

        video.write(frame);
        imshow(originWinName, frame);

        // Press  ESC on keyboard to  exit
        char c = (char)waitKey(1);
        if( c == 27 ) {
            break;
        }
    }

    cap.release();
    video.release();
}

VideoCapture PictureProcessing::loadVideoFromDisk() {
    return VideoCapture(originWinName + ".avi");
}

void PictureProcessing::processVideo(VideoCapture cap) {
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream" << std::endl;
        return;
    }

    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    int fps = cap.get(CAP_PROP_FPS);

    VideoWriter video(resultWinName + ".avi", VideoWriter::fourcc('M','J','P','G'),
                      fps, Size(frame_width,frame_height));

    while (1) {
        Mat frame;
        cap >> frame;
        char c = (char)waitKey(1);
        if( c == 27 ) {
            break;
        }
        if (!frame.empty()) {
            processImg(frame);
            imshow(resultWinName, frame);
            video.write(frame);
        }
    }

    cap.release();
    video.release();
}
