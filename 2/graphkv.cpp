template<class T>
int R;
struct vertCoord
{
    int x, y;
};
vertCoord vertC[20];
void answer(int*** mat, int n, int** help, int* path)
{

    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            int min = 1000000;
            for (int j = 0; j < n; j++)
                if (mat[i][j] && min > *mat[i][j])
                    min = *mat[i][j];
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    *mat[i][j] -= min;
        }
        for (int j = 0; j < n; j++)
        {
            int min = 1000000;
            for (int i = 0; i < n; i++)
                if (mat[i][j] && min > *mat[i][j])
                    min = *mat[i][j];
            for (int i = 0; i < n; i++)
                if (mat[i][j])
                    *mat[i][j] -= min;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                help[i][j] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] && !*mat[i][j])
                {
                    int hmin = 1000000;
                    int vmin = 1000000;

                    for (int l = 0; l < n; l++)
                        if (l != i && mat[l][j] && hmin > *mat[l][j])
                            hmin = *mat[l][j];

                    for (int l = 0; l < n; l++)
                        if (l != j && mat[i][l] && vmin > *mat[i][l])
                            vmin = *mat[i][l];

                    help[i][j] = hmin + vmin;
                }
            }

        int mcost = 0, mi = 0, mj = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] && mcost < help[i][j])
                {
                    mcost = help[i][j];
                    mi = i;
                    mj = j;
                }
        path[mi] = mj;

        for (int i = 0; i < n; i++)
            mat[i][mj] = nullptr;

        for (int i = 0; i < n; i++)
            mat[mi][i] = nullptr;

        mat[mj][mi] = nullptr;
    }
}
void preparation(int***& mat, int& n, int**& help, int*& result)
{
    n = amountVerts;

    help = new int* [n];

    result = new int[n];

    mat = new int** [n];

    for (int i = 0; i <= n; i++)
    {
        help[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        mat[i] = new int* [n];
        for (int j = 0; j < n; j++)
        {
            if (GraphA.adjMatrix[i][j] == 0) {
                mat[i][j] = nullptr;
                continue;
            }
            mat[i][j] = new int(GraphA.adjMatrix[i][j]);
        }
    }
}
void tsalesman(int*** mat, int n, int** help, int* result)
{
    preparation(mat, n, help, result);
    int s = 0;
    answer(mat, n, help, result);
    cout << "\nОтрезки путей: ";
    for (int i = 0, j = 0; i < n; i++)
    {
        j = result[i];
        cout << i + 1 << " -> " << j + 1 << '\t';
        s += GraphA.adjMatrix[i][j];
    }
    //cout << endl;
    //cout << "\nКратчайший путь: ";
    int temp = 0;
    for (int l = 0; l < n;)
    {
        for (int i = 0, j = 0; i < n; i++)
        {
            if (temp == 0 || i + 1 == temp)
            {
                if (temp == 0)// cout << i + 1;
                j = result[i];
                temp = j + 1;
                if (temp > 0)	//cout << " -> " << temp;
                l++;
            }
        }
    }
    //cout << "\nРасстояние: " << s;
    //cout << endl;
}
//template<class T>
//std::vector<T> GRAPHKV<T>::GetNbrs(const T& vertex) {
//	std::vector<T> nbrsList; // создание списка соседей
//	int vertPos = this->GetVertPos(vertex); // вычисление позиции vertex в матрице смежности
//	if (vertPos != (-1)) {
//
//		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
//			if (this->adjMatrix[vertPos][i] != 0 &&
//				this->adjMatrix[i][vertPos] != 0) // вычисление соседей
//
//				nbrsList.push_back(this->vertList[i]);
//
//		}
//	}
//	return nbrsList;
//}
template<class T>
void GRAPHKV<T>::InsertVertex(const T& vertex) {
    if (!this->IsFull()) {
        this->vertList.push_back(vertex);
    }
    else {
        cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
        return;
    }
}
template<class T>
void GRAPHKV<T>::DeleteVertex() {

    this->vertList.pop_back();

}
//template<class T>
//int GRAPHKV<T>::GetAmountEdges() {
//	int amount = 0; // обнуляем счетчик
//	if (!this->IsEmpty()) { // проверяем, что граф не пуст
//		for (int i = 0, vertListSize = this->vertList.size();
//			i < vertListSize; ++i) {
//			for (int j = 0; j < vertListSize; ++j) {
//				if (this->adjMatrix[i][j] ==
//					this->adjMatrix[j][i] &&
//					this->adjMatrix[i][j] != 0) //находим рёбра
//					amount += 1; // считаем количество рёбер
//			}
//		}
//		return (amount / 2); // приводим счетчик к корректному результату и возвращаем его
//	}
//	else
//		return 0; // если граф пуст, возвращаем 0
//}

//template<class T>
//int GRAPHKV<T>::GetWeight(const T& vertex1, const T& vertex2) {
//	if (!this->IsEmpty()) {
//		int vertPos1 = GetVertPos(vertex1);
//		int vertPos2 = GetVertPos(vertex2);
//		return adjMatrix[vertPos1][vertPos2];
//	}
//	return 0;
//}
template<class T>
int GRAPHKV<T>::GetAmountVerts() {
    return this->vertList.size();
}
template<class T>
bool GRAPHKV<T>::IsEmpty() {
    if (this->vertList.size() != 0)
        return false;
    else
        return true;
}
template<class T>
bool GRAPHKV<T>::IsFull() {
    return (vertList.size() == maxSize);
}
template <class T>
int GRAPHKV<T>::GetVertPos(const T& vertex) {
    for (int i = 0; i < this->vertList.size(); ++i) {
        if (this->vertList[i] == vertex)
            return i;
    }
    return -1;
}
template<class T>
GRAPHKV<T>::GRAPHKV() {
    for (int i = 0; i < maxSize; ++i)
    {
        for (int j = 0; j < maxSize; ++j)
        {
            this->adjMatrix[i][j] = 0;
        }
    }
}
template<class T>
GRAPHKV<T>::~GRAPHKV() {

}
GRAPHKV<int> makeGRAPHKV()
{
    GRAPHKV<int> GRAPHKV; // создание графа, содержащего вершины с номерами целого типа
    int amountEdges, sourceVertex, targetVertex, edgeWeight; // ñсоздание необходимых для ввода графа переменных
    cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl; // ввод количества рёбер графа в переменную amountVerts
    cout << "Введите количество ребер графа : "; cin >> amountEdges; cout << endl; //ввод количества рёбер графа в переменную amountEdges
    for (int i = 1; i <= amountVerts; ++i) {
        int* vertPtr = &i; // запоминаем адрес вершины с помощью указателя
        GRAPHKV.InsertVertex(*vertPtr); //передаём ссылку на вершину в функцию InsertVertex; происходит вставка вершины в вектор вершин
    }

    for (int i = 0; i < amountEdges; ++i) {
        cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl; // ввод исходной вершины
        int* sourceVertPtr = &sourceVertex; // запоминаем адрес исходной вершины
        cout << "Конечная вершина: "; cin >> targetVertex; cout << endl; // ввод вершины, до которой будет идти ребро от исходной вершины
        int* targetVertPtr = &targetVertex; // запоминаем адрес конечной вершины (до которой будет идти ребро от исходной вершины)

        cout << "Вес ребра: "; cin >> edgeWeight; cout << endl; // ввод числового значения веса ребра в переменную edgeWeight
        GRAPHKV.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // вставка ребра весом edgeWeight между исходной и конечной вершинами
    }
    cout << endl;
    return GRAPHKV;
}
template<class T>
void GRAPHKV<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
    if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
        int vertPos1 = GetVertPos(vertex1);
        int vertPos2 = GetVertPos(vertex2);
        if (this->adjMatrix[vertPos1][vertPos2] != 0
            && this->adjMatrix[vertPos2][vertPos1] != 0) {
            cout << "Обеих вершин (или одной из них) нет в графе" << endl;
            return;
        }
        else {
            this->adjMatrix[vertPos1][vertPos2] = weight;
            this->adjMatrix[vertPos2][vertPos1] = weight;
        }
    }
    else {
        cout << "Обеих вершин (или одной из них) нет в графе " << endl;
        return;
    }
}

template<class T>
void GRAPHKV<T>::Print() {
    if (!this->IsEmpty()) {
        cout << "Матрица смежности графа: " << endl;
        for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
            cout << this->vertList[i] << " ";
            for (int j = 0; j < vertListSize; ++j) {
                cout << " " << this->adjMatrix[i][j] << " ";
            }
            cout << endl;
        }

    }

}
