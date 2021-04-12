#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Matrix {
public:
  Matrix() : num_rows(0), num_cols(0) {}

  Matrix(int _num_rows, int _num_cols) {
    if(_num_rows < 0 || _num_cols < 0) {
      throw out_of_range("Out of range.");
    }
    num_rows = _num_rows;
    num_cols = _num_cols;
  }

  int At(int row, int col) const {
    if(!(row >= 0 && row <= num_rows && col >= 0 && col <= num_cols)) {
      throw out_of_range("Out of range");
    }
    return matrix.at(row).at(col);
  }

  int& At(int row, int col) {
    if(!(row >= 0 && row <= num_rows && col >= 0 && col <= num_cols)) {
      throw out_of_range("Out of range");
    }
    return matrix.at(row).at(col);
  }

  void Reset(int _num_rows, int _num_cols) {
    if(_num_rows < 0 || _num_cols < 0) {
      throw out_of_range("Out of range.");
    }
    num_rows = _num_rows;
    num_cols = _num_cols;
    for(int i = 0; i < num_rows; ++i) {
      vector<int> v = {};
      for(int j = 0; j < num_cols; ++j) {
        v.push_back(0);
      }
      matrix.push_back(v);
    }
  }

  int GetNumRows() const {
    return num_rows;
  }

  int GetNumColumns() const {
    return num_cols;
  }

  void Print() const {
    cout << num_rows << " " << num_cols << endl;
    for(const auto& v : matrix) {
      for(const auto& i : v) {  
        cout << i << " ";
      }
      cout << endl;
    }
  }
private:
  int num_rows, num_cols;
  vector<vector<int>> matrix;
};

istream& operator >> (istream& is, Matrix& matrix) {
  int _num_rows, _num_cols;
  cin >> _num_rows >> _num_cols;
  matrix.Reset(_num_rows, _num_cols);
  for(int i = 0; i < _num_rows; ++i) {
    for(int j = 0; j < _num_cols; ++j) {
      is >> matrix.at(i, j);
    }
  }
  return is;
}

ostream& operator << (ostream& os, const Matrix& matrix) {
  for(int i = 0; i < matrix.GetNumRows(); ++i) {
    for(int j = 0; j < matrix.GetNumColumns(); ++j) {
      os << matrix.At(i, j) << " ";
    }
    os << endl;
  }
  return matrix;
}

bool operator == (const Matrix& lhs, const Matrix& rhs) {
  for(int i = 0; i < lhs)
}

int main() {
  try {
    Matrix m(3, 2);
    m.At(3, 1);
  } catch (out_of_range& oor) {
    cerr << oor.what() << endl;
  }

  return 0;
}