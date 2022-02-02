clang++ -std=c++17 -Wno-switch -LSFML-2.5.1/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o main -ISFML-2.5.1/include -g $(find ./ -type f -iregex ".*\.cpp")
chmod 744 ./main
export LD_LIBRARY_PATH=./SFML-2.5.1/lib
./main