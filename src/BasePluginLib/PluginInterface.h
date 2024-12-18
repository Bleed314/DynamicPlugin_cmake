#ifndef PluginInterface_h__
#define PluginInterface_h__

#include <string>

#include <memory>

#include "basepluginlib_global.h"

using namespace std;

class BASEPLUGINLIB_EXPORT PluginInterface
{

public:
	virtual ~PluginInterface() = default;

	//定义插件必须实现的功能
	virtual const string getPluginName() const= 0;

	virtual void execute() = 0;

};

//工厂函数类型，用于创建插件示例
typedef PluginInterface* (*CreatePluginFunc)();
//typedef std::shared_ptr<PluginInterface>(*CreatePluginFunc)();

#endif // PluginInterface_h__