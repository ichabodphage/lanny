#include "Renderer.hpp"

using namespace lny;

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> win,lny::EntityManager* manager,size_t max):localWindow(win),entityManager(manager),maxSize(max){};

void Renderer::insertEntity(lny::Entity& entity){

	//an entity without a shape component cannot be rendered
	if(entity.hasComponent<lny::CompShape>()){
		
		lny::RenderRect entShape = 
		entity.getComponent<lny::CompShape>().shape;
		
		sf::Texture* entTexture = entShape.getTexture();
		//move the entity shape to its correct position
		
		if(entity.hasComponent<lny::CompTransform>()){
			entShape.setPos(
			entity.getComponent<lny::CompTransform>().pos);
		}
		
		try{
			
			/*
			insert the entities verticies into the batchmap if a batch
			for the texture exists
			*/
			batchMap.at(entTexture).addVerticies(entShape);
		}catch(std::exception e){
			/*
			create new batch if entities texture does not fit into any
			map
			*/
			batchMap.insert(
				std::pair<sf::Texture*,lny::RenderBatch>(entTexture,
				lny::RenderBatch(maxSize,entTexture)));
			batchMap.at(entTexture).addVerticies(entShape);
		}
	}
};


void Renderer::makeBatches(){
	//insert every entity into a render batch
	for(auto &entity : entityManager->entities){
		insertEntity(entity);
	}
}

void Renderer::render(){
	localWindow->clear();
	makeBatches();

	//draw each batch
	for( auto & [key,value]: batchMap){
		localWindow->draw(value);
	}
	//display the window and clear the batches
	localWindow->display();
	clearBatches();
}

void Renderer::clearBatches(){
	for( auto & [key,value]: batchMap){
		value.clear();	
	}
}