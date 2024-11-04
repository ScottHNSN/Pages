// Pages @ HNSN  >>> example of a home page and a control center using the pages compositor
// SPDX-FileCopyrightText: 2024 Scott Henssen scotthenssen@HNSN.com
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef P1CONTROLCENTER_H
#define P1CONTROLCENTER_H

#include <qwidget.h>
#include <QScopedPointer>

namespace Ui
{
class P1controlcenter;
}

class P1controlcenter : public QWidget
{
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    P1controlcenter() {

    };
    const QMetaObject* metaObject() const override;

private:
    QScopedPointer<Ui::P1controlcenter> m_ui;
};

#endif // P1CONTROLCENTER_H
