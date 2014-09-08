/*
 * QForceStudio - Explore Force Feedback on Linux.
 *
 * Copyright (C) 2014 Logitech Europe S.A.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * To Contact Logitech Europe S.A. please send an email to
 * devtechsupport@logitech.com or via mail at EPFL - Quartier de
 * l'Innovation Daniel Borel Innovation Center CH - 1015 Lausanne,
 * Attention Roland Bosa.
 *
 */

#ifndef FGWCONSTANT_H
#define FGWCONSTANT_H

#include <QWidget>
#include "ForceEffect.h"
#include "DragHandle.h"

class FGWConstant : public QWidget
{
    Q_OBJECT
public:
    explicit FGWConstant(QWidget *parent = 0);

    void setForce(ForceEffect *force);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void resizeEvent(QResizeEvent *);

protected slots:
    void onPosDragged(int handleId, QPointF newPos);
    void updateTransforms(void);

private:
    ForceEffect *m_force;
    qreal m_handleRadius;
    double m_displayedDuration;
    QTransform m_model2View;
    QTransform m_view2Model;
    DragHandler *m_dragHandler;
};

#endif // FGWCONSTANT_H
