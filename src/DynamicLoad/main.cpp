#include <QtCore/QCoreApplication>

#include <windows.h>
#include <iostream>

#include "PluginManagerLib/PluginManagerInstance.h"
#include "BasePluginLib/PluginRegister.h"

int main(int argc, char *argv[]) {


	QCoreApplication a(argc, argv);

	PluginManagerInstance::getInstance()->registerPlginDll("MyPlugin");

	std::vector<PluginInterface*> allPlugins = PluginManagerInstance::getInstance()->getAllPlugins();
	for (auto it=allPlugins.begin();it!=allPlugins.end();it++)
	{
		(*it)->execute();
	}

	PluginManagerInstance::getInstance()->destoryAllPlgins();

	return a.exec();
}

