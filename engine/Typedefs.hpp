#include "Entity/Managers/ComponentManager.hpp"
#include "Media/MediaHub.hpp"

namespace lny{
	// check for custom component manager instance
#ifdef COMPONENT_MANAGER
		typedef COMPONENT_MANAGER ComponentMgr;
#else
		typedef DEFAULT_MANAGER ComponentMgr;
#endif 
		typedef std::unique_ptr <ComponentMgr> ComponentManagerPtr;
}