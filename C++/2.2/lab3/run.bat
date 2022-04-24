g++ -c client/Client.cpp -o build/Client.o
g++ -c component/Component.cpp -o build/Component.o
g++ -shared build/Component.o -o build/Component.dll
g++ build/Client.o build/Component.dll -o build/Main.exe
