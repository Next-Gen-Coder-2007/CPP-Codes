#include <iostream>
using namespace std;

class Heap {
    private:
        int* H;
        int size;

    public:
        Heap() {
            H = new int[100];
            size = 0;
        }

        void Insert(int k) {
            size++;
            int i = size;
            int temp = k;

            while(i > 1 && temp > H[i/2]) {
                H[i] = H[i/2];
                i = i/2;
            }

            H[i] = temp;
        }

        int Delete() {
            int val = H[1];
            int x = H[size];

            size--;

            int i = 1;
            int j = 2;

            while(j <= size){
                if(j < size && H[j + 1] > H[j]){
                    j++;
                }
                if(x < H[j]){
                    H[i] = H[j];
                    i = j;
                    j = 2 * i;
                }else {
                    break;
                }
            }

            H[i] = x;
            return val;
        }

        ~Heap(){
            delete[] H;
        }
};

int main() {
    Heap h;

    int A[] = {2, 5, 3, 1, 10};
    int n = 5;

    for (int i = 0; i < n; i++) {
        h.Insert(A[i]);
    }

    for (int i = 0; i < n; i++) {
        A[i] = h.Delete();
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}