/***************************************************************************
                          equation.h  -  description
                             -------------------
    begin                : Sat Aug 23 2003
    copyright            : (C) 2003 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef SPGLOBALPAR_H
#define SPGLOBALPAR_H

#include "component.h"


class SpiceGlobalParam : public Component  {

public:
  SpiceGlobalParam();
  ~SpiceGlobalParam();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  static void splitEqn(QString &eqn, QStringList &tokens);
  QString getExpression(bool isXyce);

private:
  bool containNodes(QStringList &tokens);
  void convertNodeNames(QStringList &tokens, QStringList &dep_vars);

protected:
  QString vhdlCode(int) { return QString(""); }
  QString verilogCode(int) { return QString(""); }
  QString netlist() { return QString(""); }
};

#endif
