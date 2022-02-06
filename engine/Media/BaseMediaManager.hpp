#pragma once
#include <string>

namespace lny {
	/*
	* Asset manager abstract base class used to derive all other asset manager classes
	* only contains methods for setting asset files, child classes are to implement methods to handle such assets
	*/
	class BaseMediaManager {
	private:
		template<class ...T>
		friend class MediaHub;
		void setDirectory(std::string newdir) {
			assetFolder = newdir;
		}
	protected:
		//folder containing all assets
		std::string assetFolder;
	public:
		BaseMediaManager() :assetFolder("") {};
		
	};
}