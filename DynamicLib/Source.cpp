#include <iostream>
#include <windows.h>

int main() {
    HINSTANCE load;
    load = LoadLibrary(L"Staticlib.dll");

    if (load == NULL) {
        std::cerr << "Не удалось загрузить библиотеку: " << GetLastError() << std::endl;
        return 1;
    }

    typedef void(*func)();
    func Func;
    Func = (func)GetProcAddress(load, "func");

    if (Func == NULL) {
        std::cerr << "Не удалось получить адрес функции: " << GetLastError() << std::endl;
        return 1;
    }
    double test[4][4];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> test[i][j];
        }
    }
    Func();
    return 0;
}