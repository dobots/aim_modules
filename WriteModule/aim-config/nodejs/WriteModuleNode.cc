#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <WriteModuleExt.h>

using namespace v8;
using namespace rur;

void RegisterModule(Handle<Object> exports) {
  WriteModuleExt::NodeRegister(exports);
}

NODE_MODULE(WriteModule, RegisterModule)
