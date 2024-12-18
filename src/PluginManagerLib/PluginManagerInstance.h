#pragma once

#include <windows.h>

#include <mutex>
#include <map>
#include <vector>

#include "pluginmanagerlib_global.h"

#include "BasePluginLib/PluginInterface.h"

//�̰߳�ȫ����
class PLUGINMANAGERLIB_EXPORT PluginManagerInstance
{
public:
	~PluginManagerInstance();
	static PluginManagerInstance* getInstance();


	//************************************
	// Method:    registerPlgin
	// FullName:  PluginManagerInstance::registerPlgin
	// Access:    public 
	// Returns:   int  0,ע��ɹ���1�����ز����̬��ʧ�ܣ�2����ʼ�����
	// Qualifier:
	// Parameter: const std::string pluginName Ҫע�����Ķ�̬������
	// Parameter: CreatePluginFunc ��ʼ������ĺ���ָ��
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
	//�洢ע�ᶯ̬��ľ��
	std::map<std::string, HMODULE> _pluginAndHmoule;
	//�洢ע��Ĳ��
	std::map<std::string, PluginInterface*> _plugins;
	
};

