#pragma once
#include "Audio/MusicManager.hpp"
#include "Texture/TextureManager.hpp"
#include "BaseMediaManager.hpp"
namespace lny {
	/*
	* MediaHub class used for holding all of the engines 
	* media managers. used to make engine media easier to maintain
	*/

	template <class ...managers>
	class MediaHub {
	private:
		//root asset path
		std::string assetFolder;
		std::tuple<managers...> mediaManagers;
	public:

		//constructor using asset folder path
		MediaHub(std::string pathOne):
			assetFolder(pathOne){};

		template <class managerType>
		managerType& get() {
			return std::get<managerType>(mediaManagers);
		}
		template <class managerType>
		void setFolder(std::string path) {
			get<managerType>().setDirectory(assetFolder +"/"+path);
		}
		
	};
#define GLOBAL_MEDIA MediaHub<lny::TextureManager,lny::MusicManager>
}