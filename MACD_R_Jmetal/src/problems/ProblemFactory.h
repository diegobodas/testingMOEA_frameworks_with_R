//  ProblemFactory.h
//
//  Author:
//       Esteban L�pez <esteban@lcc.uma.es>
//
//  Copyright (c) 2011 Antonio J. Nebro, Juan J. Durillo
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __PROBLEM_FACTORY__
#define __PROBLEM_FACTORY__

#include "Problem.h"
#include <stdio.h>
#include <string.h>

#include <RInside.h>

//Don't forget to include here the R problems
#include "RKursawe.h"
#include "testMACD.h"
#include "testMACDserial.h"
//-------------------------------------------

class ProblemFactory {

public:
  static Problem * getProblem(char * name, RInside & R);
  static Problem * getProblem(int argc, char ** argv, RInside & R);
  static Problem * getProblem(char * name, int argc, char ** argv, RInside & R);
};

#endif // __PROBLEM_FACTORY__

