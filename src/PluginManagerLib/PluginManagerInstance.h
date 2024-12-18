#pragma once

#include <windows.h>

#include <mutex>
#include <map>
#include <vector>

#include "pluginmanagerlib_global.h"

#include "BasePluginLib/PluginInterface.h"

//线程安全单例
class PLUGINMANAGERLIB_EXPORT PluginManagerInstance
{
public:
	~PluginManagerInstance();
	static PluginManagerInstance* getInstance();


	//************************************
	// Method:    registerPlgin
	// FullName:  PluginManagerInstance::registerPlgin
	// Access:    public 
	// Returns:   int  0,注册成功；1，加载插件动态库失败；2，初始化插件
	// Qualifier:
	// Parameter: const std::string pluginName 要注册插件的动态库名称
	// Parameter: CreatePluginFunc 初始化该类的函数指针
	//************************************
	int registerPlginDll(const std::string pluginDllName);

	PluginInterface* getOnePlugin(const std::string pluginName);

	std::vector<PluginInterface*> getAllPlugins();

	void destoryAllPlgins();

private:
	PluginManagerInstance();
	
private:
	static std::mutex _mutex;
	static PluginManagerInstance* _instance;
	//存储注册动态库的句柄
	std::map<std::string, HMODULE> _pluginAndHmoule;
	//存储注册的插件
	std::map<std::string, PluginInterface*> _plugins;
	
};

