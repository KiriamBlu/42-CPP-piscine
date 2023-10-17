#include <iostream>
#include <vector>
#include <list>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

template <typename container>
class MergeInsortMaker {
private:
    container _contenedor;
    typename container::iterator _current;
    size_t _itPos;

public:
    MergeInsortMaker(container contenedor) : _contenedor(contenedor) {
        begin();
    }

    void mergeInShort() {
        container contenedor;
        size_t length = size();
        
        // Utiliza length en lugar de calcular size() varias veces
        merge(contenedor, (length % 2 == 0) ? length : length - 1);
        
        // Combina los elementos de contenedor directamente en _contenedor
        _contenedor.insert(_contenedor.end(), contenedor.begin(), contenedor.end());
        
        // No es necesario borrar contenedor, ya que se reemplazará
    }

    void merge(container &contenedor, size_t threshold, size_t lap = 0) {
        if (lap >= threshold - 1)
            return;

        merge(contenedor, threshold, lap + 2);
        int package[2] = {getNumber(lap), getNumber(lap + 1)};
        int pos = (package[0] > package[1]) ? lap : lap + 1;
        int number = getNumber(pos);

        if (contenedor.empty()) {
            contenedor.push_back(number);
            insertNumberInPos(pos, 0, DELETE);
            return;
        }

        typename container::iterator it = contenedor.begin();
        typename container::iterator end = contenedor.end();

        while (it != end && *it < number)
            it++;

        if (it != end) {
            contenedor.insert(it, number);
        } else {
            contenedor.push_back(number);
        }

        insertNumberInPos(pos, 0, DELETE);
    }

    // Simplifica la función insert
    void insert(int num, int flag = INSERT) {
        if (flag != DELETE) {
            _contenedor.insert(_current, num);
        } else {
            _contenedor.erase(_current);
        }
    }

    // El resto del código se mantiene igual
    // ...

    size_t size() const {
        return _contenedor.size();
    }
    // ...
};
