#include "Renderer.hpp"

using namespace lny;

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> win,lny::EntityManager* manager,size_t max):localWindow(win),entityManager(manager),maxSize(max){};

void Renderer::insertEntity(lny::Entity& entity){
	
	if(entity.hasComponent<lny::CompShape>()){
		lny::RenderRect entShape = entity.getComponent<lny::CompShape>().shape;
	sf::Texture* entTexture = entShape.getTexture();
		if(entity.hasComponent<lny::CompTransform>()){
			entShape.setPos(entity.getComponent<lny::CompTransform>().pos);
		}
		try{
			//insert the entities verticies into the batchmap if a batch for the texture exists
			batchMap.at(entTexture).addVerticies(entShape);
		}catch(std::exception e){
			//create new batch if entities texture does not fit into any map
			batchMap.insert(
				std::pair<sf::Texture*,lny::RenderBatch>(entTexture,
				lny::RenderBatch(maxSize,entTexture)));
			batchMap.at(entTexture).addVerticies(entShape);
		}
	}
};


void Renderer::makeBatches(){
	for(auto &entity : entityManager->entities){
		insertEntity(entity);
	}
}

void Renderer::render(){
	localWindow->clear();
	makeBatches();
	for( auto & [key,value]: batchMap){
		localWindow->draw(value);
	}
	clearBatches();
	localWindow->display();
}

void Renderer::clearBatches(){
	for( auto & [key,value]: batchMap){
	value.clear();	
	}
}