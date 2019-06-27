#ifndef PAGINAINSERIMENTO_H
#define PAGINAINSERIMENTO_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QCheckBox>

#include "cardgame.h"
#include "virtualgame.h"
#include "physicalgame.h"
#include "itemwidget.h"


class paginainserimento: public QWidget
{
    Q_OBJECT
private:
public slots:
public:
    paginainserimento(QWidget* parent);
};

#endif // PAGINAINSERIMENTO_H
