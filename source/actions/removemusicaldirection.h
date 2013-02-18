/*
  * Copyright (C) 2013 Cameron White
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REMOVEMUSICALDIRECTION_H
#define REMOVEMUSICALDIRECTION_H

#include <QUndoCommand>

#include <boost/shared_ptr.hpp>

class Direction;
class System;

class RemoveMusicalDirection : public QUndoCommand
{
public:
    RemoveMusicalDirection(boost::shared_ptr<System> system,
                           boost::shared_ptr<Direction> direction);

    virtual void redo();
    virtual void undo();

private:
    boost::shared_ptr<System> system;
    boost::shared_ptr<Direction> direction;
};

#endif // REMOVEMUSICALDIRECTION_H
