/**
 ******************************************************************************
 *
 * @file       minim4.cpp
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2013
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup Boards_Yackou Yackou boards support Plugin
 * @{
 * @brief Plugin to support boards by Yackou
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "minim4.h"

#include <uavobjectmanager.h>
#include "uavobjectutil/uavobjectutilmanager.h"
#include <extensionsystem/pluginmanager.h>

#include "hwminim4.h"

/**
 * @brief MiniM4::MiniM4
 *  This is the MiniM4 board definition
 */
MiniM4::MiniM4(void)
{
    // Initialize our USB Structure definition here:
    USBInfo board;
    board.vendorID = 0x20A0;
    board.productID = 0x41d0;

    setUSBInfo(board);

    boardType = 0x91;

    // Define the bank of channels that are connected to a given timer
    channelBanks.resize(6);
    channelBanks[0] = QVector<int> () << 1 << 2 << 3 << 4;
    channelBanks[1] = QVector<int> () << 5 << 6;
    channelBanks[2] = QVector<int> () << 7;
    channelBanks[3] = QVector<int> () << 8;
}

MiniM4::~MiniM4()
{

}

QString MiniM4::shortName()
{
    return QString("minim4");
}

QString MiniM4::boardDescription()
{
    return QString("minim4 flight control rev. 1 by Yackou" );
}

//! Return which capabilities this board has
bool MiniM4::queryCapabilities(BoardCapabilities capability)
{
    switch(capability) {
    case BOARD_CAPABILITIES_GYROS:
        return true;
    case BOARD_CAPABILITIES_ACCELS:
        return true;
    case BOARD_CAPABILITIES_MAGS:
        return true;
    case BOARD_CAPABILITIES_BAROS:
        return true;
    case BOARD_CAPABILITIES_RADIO:
        return false;
    }
    return false;
}


/**
 * @brief MiniM4::getSupportedProtocols
 *  TODO: this is just a stub, we'll need to extend this a lot with multi protocol support
 * @return
 */
QStringList MiniM4::getSupportedProtocols()
{

    return QStringList("uavtalk");
}

QPixmap MiniM4::getBoardPicture()
{
    return QPixmap(":/yackou/images/minim4.png");
}

QString MiniM4::getHwUAVO()
{
    return "HwMiniM4";
}

int MiniM4::queryMaxGyroRate()
{
    ExtensionSystem::PluginManager *pm = ExtensionSystem::PluginManager::instance();
    UAVObjectManager *uavoManager = pm->getObject<UAVObjectManager>();
    HwMiniM4 *hwMiniM4 = HwMiniM4::GetInstance(uavoManager);
    Q_ASSERT(hwMiniM4);
    if (!hwMiniM4)
        return 0;

    HwMiniM4::DataFields settings = hwMiniM4->getData();

    switch(settings.GyroRange) {
    case HwMiniM4::GYRORANGE_250:
        return 250;
    case HwMiniM4::GYRORANGE_500:
        return 500;
    case HwMiniM4::GYRORANGE_1000:
        return 1000;
    case HwMiniM4::GYRORANGE_2000:
        return 2000;
    default:
        return 500;
    }
}
