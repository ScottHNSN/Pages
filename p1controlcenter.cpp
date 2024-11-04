// <one line to give the program's name and a brief idea of what it does.>
// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "p1controlcenter.h"
#include "ui_p1controlcenter.h"

P1controlcenter::P1controlcenter()
    : m_ui(new Ui::P1controlcenter)
{
    m_ui->setupUi(this);
}

const QMetaObject* P1controlcenter::metaObject() const
{
}
