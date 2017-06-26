#ifndef _MenuBuilders_H
#define _MenuBuilders_H

#include "ui_FileMenuBuilders.h"
#include "ui_MainControlsToolbar.h"
#include "ui_SettingMenuBuilders.h"
#include "ui_AxesToolbar.h"
#include "ui_selectToolBar.h"
#include "ui_pointCloudEditToolBar.h"


#include "LoadImages.h"
#include "changeColor.h"
#include "axecToolBarFuncImple.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>

class QMenu;
class QWidget;
class QMainWindow;

class MenuBuilder
{
public:
	MenuBuilder();
	~MenuBuilder();
	/// Builds standard File menu.
  static void buildFileMenu(QMenu& menu);

  /// Builds the standard Edit menu.
  static void buildEditMenu(QMenu& menu);

  /// Builds and adds all standard  toolbars.
  static void buildToolbars(QMainWindow& mainWindow);

  ///Builds the standard Setting menu.
  static void buildSettingMenu(QMenu& menu);

  ///
private:
};
#endif