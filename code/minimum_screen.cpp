#include "minimum_screen.h"

/* Edited by: Shruti Naik */

minimum_screen::minimum_screen()
{
    // triggered
    setWindowTitle("Minimum Screen");

    setLayout(videoLayout);
    videoLayout->addWidget(videoWidget);
}

void minimum_screen::setUI()
{
    player->setVideoOutput(videoWidget);
}
