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

#include "CameraSettingsWindow.h"
#include "ui_CameraSettingsWindow.h"

#include "GuiController.h"
#include <ntk/camera/rgbd_grabber.h>
#include <ntk/camera/rgbd_processor.h>

using namespace ntk;

CameraSettingsWindow::CameraSettingsWindow(GuiController& controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraSettingsWindow),
    m_controller(controller)
{
	double value;
	QString s;
	int index = 0;

	ui->setupUi(this);
		
	std::vector<double> settings;
	m_controller.grabber().getCameraSettings(settings);

	value = settings[index++];s.setNum(value);
	ui->autoexposureCheckBox->setChecked((bool)value);

	value = settings[index++];s.setNum(value);
	ui->autowhitebalanceCheckBox->setChecked((bool)value);

	value = settings[index++];s.setNum(value);
	ui->exposureEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->brightnessEdit->setText(s);
    
	value = settings[index++];s.setNum(value);
	ui->contrastEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->gainEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->gammaEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->hueEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->saturationEdit->setText(s);

	value = settings[index++];s.setNum(value);
	ui->sharpnessEdit->setText(s);
	
	value = settings[index++];
	long lvalue = (long)value;
	s.setNum(lvalue);
	ui->whitebalanceEdit->setText(s);

	autoexposure_modified = false;
	autowhitebalance_modified = false;

	connect(ui->OKpushButton, SIGNAL(clicked()), this, SLOT(OK()));
	connect(ui->CancelpushButton, SIGNAL(clicked()), this, SLOT(Cancel()));	
	connect(ui->resetpushButton, SIGNAL(clicked()), this, SLOT(Reset()));
	connect(ui->autoexposureCheckBox, SIGNAL(clicked()), this, SLOT(autoexposureChecked()));
	connect(ui->autowhitebalanceCheckBox, SIGNAL(clicked()), this, SLOT(autowhitebalanceChecked()));
}

CameraSettingsWindow::~CameraSettingsWindow()
{
  delete ui;
}

void CameraSettingsWindow::OK()
{
	std::vector<double> settings;
	std::vector<bool> modified;
	QString s;
	double value;
	bool ischecked;

    ischecked = ui->autoexposureCheckBox->isChecked();
	settings.push_back((double)ischecked);
	modified.push_back(autoexposure_modified);

    ischecked = ui->autowhitebalanceCheckBox->isChecked();
	settings.push_back((double)ischecked);
	modified.push_back(autowhitebalance_modified);

	s = ui->exposureEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->exposureEdit->isModified());

	s = ui->brightnessEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->brightnessEdit->isModified());

	s = ui->contrastEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->contrastEdit->isModified());

	s = ui->gainEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->gainEdit->isModified());

	s = ui->gammaEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->gammaEdit->isModified());

	s = ui->hueEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->hueEdit->isModified());

	s = ui->saturationEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->saturationEdit->isModified());

	s = ui->sharpnessEdit->text();
	value = s.toDouble();settings.push_back(value);
	modified.push_back(ui->sharpnessEdit->isModified());

	s = ui->whitebalanceEdit->text();
	long lvalue = s.toLong();settings.push_back((double)lvalue);
	modified.push_back(ui->whitebalanceEdit->isModified());

	m_controller.grabber().setCameraSettings(settings,modified);

	hide();	

}
void CameraSettingsWindow::Cancel()
{
	hide();	
}
void CameraSettingsWindow::Reset()
{
	std::vector<double> settings;
	std::vector<bool> modified;
	m_controller.grabber().setCameraSettings(settings,modified);
	hide();	
}
void CameraSettingsWindow::autoexposureChecked()
{
autoexposure_modified = true;
}
void CameraSettingsWindow::autowhitebalanceChecked()
{
autowhitebalance_modified = true;
}
