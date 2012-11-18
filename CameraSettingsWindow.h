/**
* This file is part of the rgbdemo project.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Author: Cristóbal Bellés (C) 2012
*/

#ifndef CAMERASETTINGSWINDOW_H
#define CAMERASETTINGSWINDOW_H

#include <QMainWindow>

namespace Ui {
    class CameraSettingsWindow;
}

class GuiController;

class CameraSettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CameraSettingsWindow(GuiController& controller, QWidget *parent = 0);
    ~CameraSettingsWindow();

private:
    Ui::CameraSettingsWindow *ui;
    GuiController& m_controller;

	bool autoexposure_modified;
	bool autowhitebalance_modified;

private slots:

	void OK();
	void Cancel();
	void Reset();
	void autoexposureChecked();
	void autowhitebalanceChecked();

};

#endif // CAMERASETTINGSWINDOW_H
