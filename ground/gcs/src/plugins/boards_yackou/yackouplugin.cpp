/**
 ******************************************************************************
 *
 * @file       yackouplugin.h
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

#include "yackouplugin.h"
#include "minim4.h"
#include <QtPlugin>


YackouPlugin::YackouPlugin()
{
   // Do nothing
}

YackouPlugin::~YackouPlugin()
{
   // Do nothing
}

bool YackouPlugin::initialize(const QStringList& args, QString *errMsg)
{
   Q_UNUSED(args);
   Q_UNUSED(errMsg);
   return true;
}

void YackouPlugin::extensionsInitialized()
{
    /**
     * Create the board objects here.
     *
     */
    MiniM4* minim4 = new MiniM4();
    addAutoReleasedObject(minim4);

}

void YackouPlugin::shutdown()
{
}

Q_EXPORT_PLUGIN(YackouPlugin)
