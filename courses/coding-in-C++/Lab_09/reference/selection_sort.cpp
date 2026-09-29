#include <iostream>

int main()
{
    const int SIZE = 4;
    int zahlen[SIZE] = {29, 10, 14, 37};

    // Array vor dem Sortieren ausgeben
    std::cout << "Unsortiert: ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << zahlen[i] << " ";
    std::cout << "\n";

    // Selection Sort
    for (int i = 0; i < SIZE - 1; ++i)
    {
        // Index des kleinsten Elements im Restbereich suchen
        int minIndex = i;
        for (int j = i + 1; j < SIZE; ++j)
        {
            if (zahlen[j] < zahlen[minIndex])
                minIndex = j;
        }

        // Kleinstes Element an die aktuelle Position tauschen
        if (minIndex != i)
        {
            int temp = zahlen[i];
            zahlen[i] = zahlen[minIndex];
            zahlen[minIndex] = temp;
        }
    }

    // Array nach dem Sortieren ausgeben
    std::cout << "Sortiert:   ";
    for (int i = 0; i < SIZE; ++i)
        std::cout << zahlen[i] << " ";
    std::cout << "\n";

    return 0;
}
