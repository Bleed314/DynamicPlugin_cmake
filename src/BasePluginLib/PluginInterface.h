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

	//����������ʵ�ֵĹ���
	virtual const string getPluginName() const= 0;

	virtual void execute() = 0;

};

//�����������ͣ����ڴ������ʾ��
typedef PluginInterface* (*CreatePluginFunc)();
//typedef std::shared_ptr<PluginInterface>(*CreatePluginFunc)();

#endif // PluginInterface_h__