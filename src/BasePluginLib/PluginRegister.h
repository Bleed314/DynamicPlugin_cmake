#pragma once

#include <iostream>
#include <memory>
#include <mutex>
#include <map>

#include "PluginInterface.h"

class BASEPLUGINLIB_EXPORT PluginRegister
{
public:
	~PluginRegister() { std::cout << "~PluginRegister()" << std::endl; }

	static PluginRegister* getInstance();

	void registerPlugin(const std::string pluginName, CreatePluginFunc func);

	PluginInterface* createPlugin(const std::string pluginName);

private:
	PluginRegister();

private:
	static std::mutex _mutex;
	static PluginRegister* _instance;
	std::map<std::string, CreatePluginFunc> _creatPluginFun;

};

// ×¢²á²å¼þ
#define REGISTER_PLUGIN(NAME, FUNC) \
    static struct Register { \
        Register() { PluginRegister::getInstance()->registerPlugin(NAME, FUNC); } \
    } reg;

