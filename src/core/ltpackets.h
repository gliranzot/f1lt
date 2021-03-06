/*******************************************************************************
 *                                                                             *
 *   F1LT - unofficial Formula 1 live timing application                       *
 *   Copyright (C) 2012-2013  Mariusz Pilarek (pieczaro@gmail.com)             *
 *                                                                             *
 *   This program is free software: you can redistribute it and/or modify      *
 *   it under the terms of the GNU General Public License as published by      *
 *   the Free Software Foundation, either version 3 of the License, or         *
 *   (at your option) any later version.                                       *
 *                                                                             *
 *   This program is distributed in the hope that it will be useful,           *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *   GNU General Public License for more details.                              *
 *                                                                             *
 *   You should have received a copy of the GNU General Public License         *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                             *
 *******************************************************************************/





#ifndef LTDATA_H
#define LTDATA_H

/*!
 * \brief The LTPackets class defines enums and methods used to manipulate data obtained from the LT server.
 */
class LTPackets
{
public:
    enum CarPacket
    {
        CAR_POSITION_UPDATE	= 0,
        CAR_POSITION_HISTORY = 15
    };

    enum RacePacket
    {
        RACE_POSITION = 1,
        RACE_NUMBER,
        RACE_DRIVER,
        RACE_GAP,
        RACE_INTERVAL,
        RACE_LAP_TIME,
        RACE_SECTOR_1,
        RACE_PIT_LAP_1,
        RACE_SECTOR_2,
        RACE_PIT_LAP_2,
        RACE_SECTOR_3,
        RACE_PIT_LAP_3,
        RACE_NUM_PITS
    };

    enum PracticePacket
    {
        PRACTICE_POSITION	= 1,
        PRACTICE_NUMBER,
        PRACTICE_DRIVER,
        PRACTICE_BEST,
        PRACTICE_GAP,
        PRACTICE_SECTOR_1,
        PRACTICE_SECTOR_2,
        PRACTICE_SECTOR_3,
        PRACTICE_LAP
    };

    enum QualifyingPacket
    {
        QUALI_POSITION= 1,
        QUALI_NUMBER,
        QUALI_DRIVER,
        QUALI_PERIOD_1,
        QUALI_PERIOD_2,
        QUALI_PERIOD_3,
        QUALI_SECTOR_1,
        QUALI_SECTOR_2,
        QUALI_SECTOR_3,
        QUALI_LAP
    };


    enum SystemPacket
    {
        SYS_EVENT_ID		= 1,
        SYS_KEY_FRAME       = 2,
        SYS_VALID_MARKER    = 3,
        SYS_COMMENTARY      = 4,
        SYS_REFRESH_RATE    = 5,
        SYS_NOTICE          = 6,
        SYS_TIMESTAMP       = 7,
        SYS_WEATHER         = 9,
        SYS_SPEED           = 10,
        SYS_TRACK_STATUS    = 11,
        SYS_COPYRIGHT       = 12
    };

    enum WeatherPacket
    {
        WEATHER_SESSION_CLOCK	= 0,
        WEATHER_TRACK_TEMP,
        WEATHER_AIR_TEMP,
        WEATHER_WET_TRACK,
        WEATHER_WIND_SPEED,
        WEATHER_HUMIDITY,
        WEATHER_PRESSURE,
        WEATHER_WIND_DIRECTION
    };

    enum SpeedPacket
    {
        SPEED_SECTOR1 = 1,
        SPEED_SECTOR2,
        SPEED_SECTOR3,
        SPEED_TRAP,
        FL_CAR,
        FL_DRIVER,
        FL_TIME,
        FL_LAP
    };

    enum EventType
    {
        RACE_EVENT = 1,
        PRACTICE_EVENT,
        QUALI_EVENT
    };

    enum FlagStatus
    {
        GREEN_FLAG = 1,
        YELLOW_FLAG,
        SAFETY_CAR_STANDBY,
        SAFETY_CAR_DEPLOYED,
        RED_FLAG
    };

    enum Colors
    {
        DEFAULT,
        WHITE,
        PIT,
        GREEN,
        VIOLET,
        CYAN,
        YELLOW,
        RED,
        BACKGROUND,
        BACKGROUND2
    };

    static int getPacketType(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return (arr[0] >> 5) | ((arr[1] & 0x01) << 3);
    }
    static int getCarPacket(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return arr[0] & 0x1f;
    }
    static int getLongPacketData(const QByteArray &)
    {
        return 0;
    }
    static int getShortPacketData(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return (arr[1] & 0x0e) >> 1;
    }
    static int getSpecialPacketData(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return arr[1] >> 1;
    }
    static int getLongPacketLength(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return arr[1] >> 1;
    }
    static int getShortPacketLength(const QByteArray &buf)
    {
        unsigned char arr[2] = {(unsigned char)(buf[0]), (unsigned char)(buf[1])};
        return (arr[1] & 0xf0) == 0xf0 ? -1 : (arr[1] >> 4);
    }
    static int getSpecialPacketLength(const QByteArray &)
    {
        return 0;
    }
};

#endif // LTDATA_H
