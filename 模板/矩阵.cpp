template <typename T, int n>
struct Matrix{
    T data[n][n];
    explicit Matrix(const T& w = T()){
        for(auto& arr : data){
            for(auto& x: arr){
                x = w;
            }
        }
        return;
    }
    void unit(){
        frep(i, 0, n){
            frep(j, 0, n){
                data[i][j] = (i == j);
            }
        }
        return;
    }
    const T* operator[] (int x) const {
        return data[x];
    }
    T* operator[] (int x){
        return data[x];
    }
    Matrix operator* (const Matrix& other) const {
        Matrix ans;
        frep(i, 0, n){
            frep(k, 0, n){
                frep(j, 0, n){
                    ans[i][j] = ans[i][j] + data[i][k] * other[k][j];
                }
            }
        }
        return ans;
    }
    friend ostream& operator<< (ostream& os, const Matrix& m){
        for(const auto& arr : m.data){
            os << "|";
            for(const auto& x : arr){
                os << x << ", ";
            }
            os << "|" << endl;
        }
        return os;
    }
};
