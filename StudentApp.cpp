#include <iostream>
#include <windows.h>
using namespace std;
int main()
 {
 HMODULE dll = NULL;
 int choice;
do
{
    cout << "\n=== СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ ===\n";
    cout << "1. Загрузить DLL\n";
    cout << "2. Создать группу студентов\n";
    cout << "3. Заполнить демо-данными\n";
    cout << "4. Показать всех студентов\n";
    cout << "5. Рассчитать средние баллы\n";
    cout << "6. Найти лучшего студента\n";
    cout << "7. Показать должников\n";
    cout << "8. Отфильтровать по баллу (> 4.0)\n";
    cout << "9. Отсортировать студентов\n";
    cout << "10. Выгрузить DLL\n";
    cout << "0. Выход\n";

    cout << "\nВыбор: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        dll = LoadLibraryA("StudentDLL.dll");

        if (dll)
            cout << "DLL успешно загружена!\n";
        else
            cout << "Ошибка загрузки DLL!\n";
        break;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        if (!dll)
        {
            cout << "Сначала загрузите DLL!\n";
        }
        else
        {
            cout << "Функция выбрана.\n";
        }
        break;

    case 10:
        if (dll)
        {
            FreeLibrary(dll);
            dll = NULL;
            cout << "DLL выгружена.\n";
        }
        break;

    case 0:
        if (dll)
            FreeLibrary(dll);
        break;

    default:
        cout << "Неверный пункт меню.\n";
    }

} while (choice != 0);

return 0;
}

