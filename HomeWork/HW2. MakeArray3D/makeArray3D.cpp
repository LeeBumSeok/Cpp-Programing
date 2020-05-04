// 소프트웨어학부
// 20171664
// 이범석

#include <iostream>
#include <cstdlib>
using namespace std;

int ***makeArray3D(int *sz);
void destroyArray3D(int ***arr, int *sz);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "usage : ./str 1d 2d 3d ... nd \n";
    }

    int i, dim = argc - 1;
    int *size = new int[dim];

    for (i = 1; i < argc; i++)
        size[i - 1] = atoi(argv[i]);

    int ***arr3d = NULL;

    arr3d = makeArray3D(size);
    for (int i = 0; i < size[0]; i++)
        for (int j = 0; j < size[1]; j++)
            for (int k = 0; k < size[2]; k++)
                arr3d[i][j][k] = (i * size[1] + j) * size[2] + k;
    for (int i = 0; i < size[0]; i++)
    {
        cout << "i : " << i << endl;
        for (int j = 0; j < size[1]; j++)
        {
            for (int k = 0; k < size[2]; k++)
                cout << arr3d[i][j][k] << ' ';
            cout << endl;
        }
        cout << endl;
    }
    destroyArray3D(arr3d, size);
    return 0;
}

int ***makeArray3D(int *sz)
{
    int n1 = sz[0];
    int n2 = sz[1];
    int n3 = sz[2];
    int ***arr = new int **[n1];
    for (int i = 0; i < n1; i++)
    {
        arr[i] = new int *[n2];
        for (int j = 0; j < n2; j++)
            arr[i][j] = new int[n3];
    }
    return arr;
}

void destroyArray3D(int ***arr, int *sz)
{
    int n1 = sz[0];
    int n2 = sz[1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;
}

// int *makeArray1D(int *sz);
// void destroyArray1D(int *arr, int *sz);

// int main(int argc, char *argv[])
// {
//     if (argc < 2)
//     {
//         cout << "usage : ./str 1d 2d 3d ... nd \n";
//         return -1;
//     }

//     int i, dim = argc - 1;
//     int *size = new int[dim];

//     for (i = 1; i < argc; i++)
//         size[i - 1] = atoi(argv[i]);

//     int *arr1d = NULL;

//     arr1d = makeArray1D(size);
//     for (int i = 0; i < size[0]; i++)
//         arr1d[i] = i;
//     for (int i = 0; i < size[0]; i++)
//         cout << arr1d[i] << " ";
//     cout << endl;
//     destroyArray1D(arr1d, size);
//     return 0;
// }

// int *makeArray1D(int *sz)
// {
//     int n = sz[0];
//     int *arr = new int[n];
//     return arr;
// }
// void destroyArray1D(int *arr, int *sz)
// {
//     delete[] arr;
// }

// int **makeArray2D(int *sz);
// void destroyArray2D(int **arr, int *sz);

// int main(int argc, char *argv[])
// {
//     if (argc < 2)
//     {
//         cout << "usage : ./str 1d 2d 3d ... nd \n";
//         return -1;
//     }

//     int i, dim = argc - 1;
//     int *size = new int[dim];

//     for (i = 1; i < argc; i++)
//         size[i - 1] = atoi(argv[i]);

//     int **arr2d = NULL;

//     arr2d = makeArray2D(size);
//     for (int i = 0; i < size[0]; i++)
//         for (int j = 0; j < size[1]; j++)
//             arr2d[i][j] = i + size[i] + j;
//     for (int i = 0; i < size[0]; i++)
//         for (int j = 0; j < size[1]; j++)
//             cout << arr2d[i][j] << " ";
//     cout << endl;
//     destroyArray2D(arr2d, size);
//     return 0;
// }

// int **makeArray2D(int *sz)
// {
//     int n1 = sz[0];
//     int n2 = sz[1];
//     int **arr = new int *[n1];
//     for (int i = 0; i < n1; i++)
//         arr[i] = new int[n2];
//     return arr;
// }

// void destroyArray2D(int **arr, int *sz)
// {
//     int n1 = sz[0];
//     for (int i = 0; i < n1; i++)
//         delete[] arr[i];
//     delete[] arr;
// }