#include "PictureProcessing.h"

int main() {
    PictureProcessing helper;
    helper.saveVideoFromCam();
    auto loadVideo = helper.loadVideoFromDisk();
    helper.processVideo(loadVideo);

    return 0;
}
