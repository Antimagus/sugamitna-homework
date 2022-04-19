g++ -c client/Client.cpp -o build/Client.o
g++ -c component/Component.cpp -o build/Component.o
g++ -shared build/Component.o -o build/Component.dll -Wl,--kill-at
g++ build/Client.o build/Component.o -o build/Main.exe