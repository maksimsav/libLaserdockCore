/**
    libLaserdockCore
    Copyright(c) 2018 Wicked Lasers

    This file is part of libLaserdockCore.

    libLaserdockCore is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libLaserdockCore is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libLaserdockCore.  If not, see <https://www.gnu.org/licenses/>.
**/

#ifndef LDFILTERMANAGER_H
#define LDFILTERMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QMutex>

#include "ldCore/ldCore_global.h"

#include "ldFilterBasicGlobal.h"
#include "ldFilterBasicData.h"
#include "ldFilterMovement.h"

class ldFilter;

class ldHardwareFilter;

class LDCORESHARED_EXPORT ldFilterManager : public QObject
{
    Q_OBJECT

public:
    explicit ldFilterManager(QObject *parent = 0);
    ~ldFilterManager();

    ldFilter *preGlobalFilter() const;
    void setPreGlobalFilter(ldFilter *globalFilter);

    ldFilter *globalFilter() const;
    void setGlobalFilter(ldFilter *globalFilter);

    ldFilterBasicData *dataFilter();

    // get existing filter by device id, or allocate a new one if a new device
    ldHardwareFilter *getFilterById(QString device_id);
    // remove an existing filter by device id
    void removeFilterById(QString device_id);

    void setFrameModes(int frameModes);

    void processFrame1(ldVertexFrame &frame);
    void processFrame2(ldVertexFrame &frame);

    void resetFilters();

    ldColorCurveFilter *colorCurveFilter() const;
    ldColorFaderFilter *colorFaderFilter() const;
    ldStrobeFilter *strobeFilter() const;
    ldHueFilter *hueFilter() const;
    ldHueShiftFilter *hueShiftFilter() const;
    ldFilterMovement *movementFilter() const;
    ld3dRotateFilter *rotate3dFilter() const;
    ldScaleFilter *globalScaleFilter() const;
    ldPowerFilter *globalPowerFilter() const;
    ldSoundLevelFilter *soundLevelFilter() const;
    ldRotateFilter *rotateFilter() const;
    ldTracerFilter *tracerFilter() const;

    void setHueFiltersActive(bool active);

    void lock();
    void unlock();

private:
    ldFilterBasicGlobal m_basicGlobalFilter;
    ldFilterBasicData m_dataFilter;
    ldFilter* m_preGlobalFilter = nullptr;
    ldFilter* m_globalFilter = nullptr;
    QMap<QString,QSharedPointer<ldHardwareFilter>> m_filtermap;

    std::unique_ptr<ld3dRotateFilter> m_3dRotateFilter;
    std::unique_ptr<ldFilterMovement> m_movementFilter;

    QMutex m_mutex;
};

#endif // LDFILTERMANAGER_H
