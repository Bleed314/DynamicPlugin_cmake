#include "PluginRegister.h"

#include <windows.h>

PluginRegister* PluginRegister::_instance = nullptr;
std::mutex PluginRegister::_mutex;

PluginRegister* PluginRegister::getInstance()
{
	if (!_instance)
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (!_instance)
		{
			_instance = new PluginRegister();
		}
	}
	return _instance;
}

void PluginRegister::registerPlugin(const std::string pluginName, CreatePluginFunc func)
{
	if (!func)
	{
		return;
	}
	_creatPluginFun[pluginName] = func;

}

PluginInterface* PluginRegister::createPlugin(const std::string pluginName)
{
	CreatePluginFunc func = _creatPluginFun[pluginName];
	if (!func)
	{
		return nullptr;
	}
	PluginInterface* plugin = func();
	return plugin;
}


PluginRegister::PluginRegister()
{

}


