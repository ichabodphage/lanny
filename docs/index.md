# todo
1. implement method of allowing scenes to use different components from one another and transfer component management to scenes from the engine
2. implement a render system that is more in line with standard ECS architecture
3. implement texture atlassing support

# lanny engine documentation
here you can find the documentation for the classes and functions that lanny implements

every class or function within the engine uses namespace `lny`

## classes

### general engine function classes
- LannyEngine
- BaseScene

### render system classes
- RenderSystem
- RenderBatch
- RenderRect
- Texture

### media management classes
- MediaHub
- BaseMediaManager(template)
  - TextureManager
  - MusicManager

### input management classes
- Event
- InputHandler
- InputManager

### Entity classes
- Entity
- ComponentManager
- EntityManager

### entity component classes
- Component
- CompBB
- CompMovement
- CompShape
- CompTransform


