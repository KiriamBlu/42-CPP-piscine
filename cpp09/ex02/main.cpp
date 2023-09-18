
int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    MergeInsortMaker<std::vector<int> > maker(vec, getNumberVector, insertNumberInPosVector, sizeVector);

    // Usar la clase MergeInsortMaker con un vector

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);

    MergeInsortMaker<std::list<int> > maker2(lst, getNumberList, insertNumberInPosList, sizeList);

    // Usar la clase MergeInsortMaker con una lista

    return 0;
}

// Funciones para obtener un número de un iterador en un vector
int getNumberVector(typename std::vector<int>::iterator it) {
    return *it;
}

void insertNumberInPosVector(typename std::vector<int>::iterator it, bool flag , int num = 0 ) {
    if (flag == INSERT)
        it = _contenedor.insert(it, num); // Corrección: Utilizar _contenedor en lugar de vec
    else
        it = _contenedor.emplace(it, num); // Corrección: Utilizar emplace en lugar de insert
}

size_t sizeVector(const std::vector<int>& v) {
    return v.size();
}

// Funciones para obtener un número de un iterador en una lista
int getNumberList(typename std::list<int>::iterator it) {
    return *it;
}

void insertNumberInPosList(typename std::list<int>::iterator it, bool flag ,int num = 0) {
    if (flag == INSERT)
        it = _contenedor.insert(it, num); // Corrección: Utilizar _contenedor en lugar de lst
    else
        it = _contenedor.emplace(it, num); // Corrección: Utilizar emplace en lugar de insert
}

size_t sizeList(const std::list<int>& l) {
    return l.size();
}
