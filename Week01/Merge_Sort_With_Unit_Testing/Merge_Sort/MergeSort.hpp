template<typename T>
void Merge(T* firstArr, size_t firstSize, T* secondArr, size_t secondSize, T* resultArr)
{
    size_t resultIter = 0; 
    size_t firstIter = 0;
    size_t secondIter = 0;

    while (firstIter < firstSize && secondIter < secondSize)
        resultArr[resultIter++] = (firstArr[firstIter] <= secondArr[secondIter]) ? firstArr[firstIter++] : secondArr[secondIter++];

    while (firstIter < firstSize)
        resultArr[resultIter++] = firstArr[firstIter++];

    while (secondIter < secondSize)
        resultArr[resultIter++] = secondArr[secondIter++];
}

template<typename T>
void MergeSortStep(T* pArr, size_t size, T* pBuffer)
{
    if (size <= 1)
        return;

    unsigned middle = size / 2;

    MergeSortStep<T>(pArr, middle, pBuffer);
    MergeSortStep<T>(pArr + middle, size - middle, pBuffer + middle);
    Merge<T>(pArr, middle, pArr + middle, size - middle, pBuffer);

    for (size_t i = 0; i < size; ++i)
        pArr[i] = pBuffer[i];
}

template<typename T>
void MergeSort(T* arr, size_t size)
{
    if (!arr || size == 0)
        return;

    T* pBuffer = new T[size];

    MergeSortStep<T>(arr, size, pBuffer);

    delete[] pBuffer;
}