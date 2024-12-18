#include <iostream>

#include <memory>

#include "BasePluginLib/PluginInterface.h"

#include "mypluginlib_global.h"

class MYPLUGINLIB_EXPORT MyPlugin : public PluginInterface {

public:
	MyPlugin() {
		std::cout << "MyPlugin is builded!" << std::endl;
	};

	~MyPlugin() { 
		std::cout << "MyPlugin is destoryed!" << std::endl; 
	};

	const string getPluginName() const override {
		return "MyPlugin";
	}

	void execute() override {
		std::cout << "MyPlugin is executing!" << std::endl;
	}
};

// ��������
extern "C" __declspec(dllexport) PluginInterface* createPlugin() {
	return new MyPlugin();
}

//C����ʶc++������ָ��
//extern "C" __declspec(dllexport) std::shared_ptr<PluginInterface> createPlugin() {
//	std::shared_ptr<PluginInterface> it = std::make_shared<PluginInterface>();
//	return it;
//}


// ���ٺ���
extern "C" void __declspec(dllexport) destroyPlugin(PluginInterface* plugin) {
	delete plugin;
}


