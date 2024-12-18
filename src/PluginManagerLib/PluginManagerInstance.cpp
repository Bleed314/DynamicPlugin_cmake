#include "PluginManagerInstance.h"

#include <iostream>

#include "BasePluginLib/PluginRegister.h"

PluginManagerInstance* PluginManagerInstance::_instance = nullptr;
std::mutex PluginManagerInstance::_mutex;

PluginManagerInstance::PluginManagerInstance()
{
}


PluginManagerInstance::~PluginManagerInstance()
{
	std::cout << "~PluginManagerInstance()" << std::endl;
}

PluginManagerInstance* PluginManagerInstance::getInstance()
{
	if (!_instance)
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (!_instance)
		{
			_instance = new PluginManagerInstance();
		}
	}
	return _instance;
}

int PluginManagerInstance::registerPlginDll(const std::string pluginName)
{
	std::string dllName = pluginName + ".dll";
	std::wstring wideDllName = std::wstring(dllName.begin(), dllName.end());

	// 加载插件对应dll
	HMODULE handle = LoadLibraryW(wideDllName.c_str());
	if (!handle) {
		DWORD errorCode = GetLastError();
		std::cerr <<"Load " <<dllName <<" failed!------>"<<"Error code:"<< errorCode<<std::endl;
		return 1;
	}

	//初始化插件
	PluginInterface* plugin= PluginRegister::getInstance()->createPlugin(pluginName);
	if (!plugin)
	{
		std::cerr <<pluginName<< " class failed to initial!" << std::endl;
		return 2;
	}

	_pluginAndHmoule.insert(std::make_pair(pluginName, handle));
	_plugins[pluginName] = plugin;

	return 0;
}

PluginInterface * PluginManagerInstance::getOnePlugin(const std::string pluginName)
{
	return _plugins[pluginName];
}

std::vector<PluginInterface*> PluginManagerInstance::getAllPlugins()
{
	std::vector<PluginInterface*> allPlugins;
	std::map<std::string, PluginInterface*>::iterator it = _plugins.begin();

	while (it != _plugins.end())
	{
		if (it->second)
		{
			allPlugins.push_back(it->second);
		}
		it++;
	}
	return allPlugins;
}

void PluginManagerInstance::destoryAllPlgins()
{
	std::map<std::string, PluginInterface*>::iterator it = _plugins.begin();
	while (it != _plugins.end())
	{
		if (it->second)
		{
			if (_pluginAndHmoule[it->first])
			{
				std::string pluginName = it->first;
				delete it->second;
				FreeLibrary(_pluginAndHmoule[pluginName]);
			}
		}
		it++;
	}
}
