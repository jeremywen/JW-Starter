#include "JWModules.hpp"

Plugin *pluginInstance;

void init(rack::Plugin *p)
{
	pluginInstance = p;
	p->addModel(modelAdd5);
}
