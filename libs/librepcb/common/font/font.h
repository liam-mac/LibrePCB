/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/


#ifndef RS_FONT_H
#define RS_FONT_H

#include <iosfwd>
#include <QStringList>
#include <QMap>
#include "../geometry/polygon.h"
//#include "rs_blocklist.h"

namespace librepcb {

/**
 * Class for representing a font. This is implemented as a RS_Graphic
 * with a name (the font name) and several blocks, one for each letter
 * in the font.
 *
 * @author Andrew Mustun
 */
class RS_Font {
public:
    RS_Font(const QString& name, bool owner=true);
    //RS_Font(const char* name);

    /** @return the fileName of this font. */
    QString getFileName() const {
        return fileName;
    }
	
    /** @return the fileLicense of this font. */
    QString getFileLicense() const {
        return fileLicense;
    }

    /** @return the creation date of this font. */
    QString getFileCreate() const {
        return fileCreate;
    }

    /** @return the encoding of this font. */
    QString getEncoding() const {
        return encoding;
    }
	
    /** @return the alternative names of this font. */
    const QStringList& getNames() const {
        return names;
    }
	
    /** @return the author(s) of this font. */
    const QStringList& getAuthors() const {
        return authors;
    }

    /** @return Default letter spacing for this font */
    double getLetterSpacing() {
        return letterSpacing;
    }

    /** @return Default word spacing for this font */
    double getWordSpacing() {
        return wordSpacing;
    }

    /** @return Default line spacing factor for this font */
    double getLineSpacingFactor() {
        return lineSpacingFactor;
    }

    bool loadFont();

    void generateAllFonts();

    const QHash<QString, QList<Polygon*>>& getLetters() const noexcept {return letterList;}

private:
    void readLFF();
    /*RS_Block*/ void generateLffFont(const QString& ch);

private:
    //raw lff font file list, not processed into blocks yet
    QMap<QString, QStringList> rawLffFontList;

    //! block list (letters)
    //RS_BlockList letterList;
    QHash<QString, QList<Polygon*>> letterList;

    //! Font file name
    QString fileName;
	
    //! Font file license
    QString fileLicense;

    //! Font file license
    QString fileCreate;

    //! Font encoding (see docu for QTextCodec)
    QString encoding;

	//! Font names
    QStringList names;
	
	//! Authors
    QStringList authors;

    //! Is this font currently loaded into memory?
    bool loaded;

    //! Default letter spacing for this font
    double letterSpacing;

    //! Default word spacing for this font
    double wordSpacing;

    //! Default line spacing factor for this font
    double lineSpacingFactor;
};

}

#endif
