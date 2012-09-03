/*
  * Copyright (C) 2012 Cameron White
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

#ifndef EDITFILEINFORMATION_H
#define EDITFILEINFORMATION_H

#include <QUndoCommand>
#include <boost/shared_ptr.hpp>
#include <powertabdocument/powertabfileheader.h>

class PowerTabDocument;

class EditFileInformation : public QUndoCommand
{
public:
    EditFileInformation(boost::shared_ptr<PowerTabDocument> doc,
                        const PowerTabFileHeader& newHeader);

    virtual void undo();
    virtual void redo();

private:
    const boost::shared_ptr<PowerTabDocument> doc;
    const PowerTabFileHeader oldHeader;
    const PowerTabFileHeader newHeader;
};

#endif // EDITFILEINFORMATION_H