# lanny
lanny is a work in progress c++ 2d game engine designed for flexibility and customizability in mind
lanny uses an entity component system for handling objects and for general architecture
## dependancies
SFML (used for graphics, audio, and IO)

## build
requirements
1. visual studio 2019 or beyond
2. SFML 
3. machine with x64 architecture

### step one
downloaded the github repo onto any windows, macos, or linux device

### step two
create a Visual studio project from the github repo that was just downloaded

(link for how to do that)
https://docs.microsoft.com/en-us/cpp/build/how-to-create-a-cpp-project-from-existing-code?view=msvc-170

### step three
import SFML into the visual studio project

(link for how to do that)
https://www.sfml-dev.org/tutorials/2.5/start-vc.php

### step four
set the visual studio solution platform to x64 and then set the build type to release
finally the engine can be built by just navigating to the VS build menu and pressing build solution

## todo
here is a list of things that lanny needs implemented
1. implement a texture entity component
2. implement a colision entity component using SAT colision detection
3. rework the shape component to allow more shapes than just rectangles
4. implement a mouse/keyboard entity component
5. implement a wraper class for handling all generic entity component handlers

### roadmap
this is like a todo, but more long term, this list will probably be updated in the future
1. finish all basic entity components
2. abstract scene class that is used to designate different sections of an app with different logic
3. implement system for creating custom app specific entity components
