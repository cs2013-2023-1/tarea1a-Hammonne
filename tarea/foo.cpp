#include "foo.h"

Matriz2D::Matriz2D():filas(3), columnas(3){
    // Constructor por defecto
    ptr=new float*[filas];

    //crear cada fila
    for (int i=0;i<filas;i++)
        ptr[i]=new float[columnas];

    //inicializar matriz
    for (int i=0; i<filas;i++){
        for (int j=0; j<columnas;j++){
            float num=rand()%100;
            ptr[i][j]=num/100;}
    }


}

Matriz2D::Matriz2D(int n):filas(n), columnas(n){
    // Constructor con un parametro
    ptr=new float*[filas];
    //crear cada fila
    for (int i=0;i<filas;i++)
        ptr[i]=new float[columnas];
    //inicializar matriz
    for (int i=0; i<filas;i++){
        for (int j=0; j<columnas;j++){
            float num=rand()%100;
            ptr[i][j]=num/100;}
    }

}

Matriz2D::Matriz2D(int n, int m):filas(n), columnas(m){
    // Constructor con dos parametros
    // Constructor por defecto
    ptr=new float*[filas];

    //crear cada fila
    for (int i=0;i<filas;i++)
        ptr[i]=new float[columnas];

    //inicializar matriz
    for (int i=0; i<filas;i++){
        for (int j=0; j<columnas;j++){
            float num=rand()%100;
            ptr[i][j]=num/100;}
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas=m.filas;
    columnas=m.columnas;

    ptr=new float * [filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float [columnas];
       for (int j=0;j<columnas;j++)
           ptr[i][j]=m.ptr[i][j];
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas=m.filas;
    columnas=m.columnas;
    ptr=m.ptr;

    m.ptr= nullptr;
    m.filas=0;
    m.columnas=0;

}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D transpuesta(m.columnas, m.filas);
    for (int i=0;i<transpuesta.filas;i++) {
        for (int j = 0; j < transpuesta.columnas; j++) {
            transpuesta.ptr[i][j] = m.ptr[j][i];
        }
    }
    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i=0; i<m.filas;i++) {
        for (int j = 0; j < m.columnas;j++)
            os << m.ptr[i][j] << " ";
        os<<endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    if(m1.filas!=m2.filas or m1.columnas!=m2.columnas)
        cout<<"Las matrices deben ser de las mismas dimensiones.";
    else {
        Matriz2D resultado(m1.filas, m1.columnas);
        for (int i = 0; i < m1.filas; i++)
            for (int j = 0; j < m1.columnas; j++)
                resultado.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        return resultado;
    }
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    if(m1.filas!=m2.filas or m1.columnas!=m2.columnas)
        cout<<"Las matrices deben ser de las mismas dimensiones.";
    else {
        Matriz2D resultado(m1.filas, m1.columnas);
        for (int i = 0; i < m1.filas; i++)
            for (int j = 0; j < m1.columnas; j++)
                resultado.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        return resultado;
    }
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    if(m1.columnas!=m2.filas)cout<<"No se pueden multiplicar las matrices";
    else {
        Matriz2D resultado(m1.filas, m2.columnas);
        for(int i=0;i<m1.filas;i++)
            for (int j=0; j<m2.columnas;j++)
                for (int k=0; k<m1.columnas; k++)
                    resultado.ptr[i][j]+=m1.ptr[i][k]*m2.ptr[k][j];
        return resultado;
    }
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D resultado(m.filas, m.columnas);
    for (int i=0; i<m.filas; i++){
        for (int j=0; j<m.columnas; j++)
            resultado.ptr[i][j]=m.ptr[i][j]+n;
    }
    return resultado;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D resultado(m.filas, m.columnas);
    for (int i=0; i<m.filas; i++){
        for (int j=0; j<m.columnas; j++)
            resultado.ptr[i][j]=m.ptr[i][j]-n;
    }
    return resultado;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D resultado(m.filas, m.columnas);
    for (int i=0; i<m.filas; i++){
        for (int j=0; j<m.columnas; j++)
            resultado.ptr[i][j]=m.ptr[i][j]*n;
    }
    return resultado;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D resultado(m.filas, m.columnas);
    for (int i=0; i<m.filas; i++){
        for (int j=0; j<m.columnas; j++)
            resultado.ptr[i][j]=m.ptr[i][j]/n;
    }
    return resultado;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
