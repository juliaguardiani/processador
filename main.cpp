#include <iostream>

using namespace std;

struct Instrucao{
    int opcode,endereco;
};
int main(){

    Instrucao I;

    /// Criacao dos registradores e da memoria
    int MBR,MAR,IR,MQ,AC,PC=0;
    int Memoria[1024] = {0};

    /// ARMAZENAMENTO DAS INSTRUCOES NA MEMORIA
    /// ----INTRUCOES----
    Memoria[300] = 9602;
    Memoria[301] = 11601;
    Memoria[302] = 10000;
    Memoria[303] = 5600;
    Memoria[304] = 33607;
    Memoria[305] = 9604;
    Memoria[306] = 11605;
    Memoria[307] = 10000;
    Memoria[308] = 33608;
    Memoria[309] = 1603;
    Memoria[310] = 6608;
    Memoria[311] = 33609;
    Memoria[312] = 1603;
    Memoria[313] = 6608;
    Memoria[314] = 33609;
    Memoria[315] = 1607;
    Memoria[316] = 12609;
    Memoria[317] = 33607;
    Memoria[318] = 10000;
    Memoria[319] = 33606;

    /// ARMAZENAMENTO DOS DADOS NA MEMORIA
    /// ----DADOS----
    Memoria[600] = 37;
    Memoria[601] = 80;
    Memoria[602] = 23;
    Memoria[603] = 16;
    Memoria[604] = 63;
    Memoria[605] = 11;


    /// Inicializacao do PC com o primeiro endecereco de instrucao
    PC = 300;

    /// Inicializacao do processo

    while(PC!=320){

    /// Busca de instrucao(micro-operacoes)
    MAR = PC;
    MBR = Memoria[MAR];
    PC++;
    IR = MBR;

    /// Separacao da instrucao em opcode e endereco

    I.opcode = IR/1000;
    I.endereco = IR%1000;

    /// Unidade de controle
    /// Execucao da instrucao

    switch(I.opcode){
    case 10:
        AC = MQ;
        cout << "LOAD MQ" << endl;
        break;
    case 9:
        //MQ = M[x]
        MQ = Memoria[I.endereco];
        cout << "LOAD MQ," << I.endereco << endl;
        break;
    case 33:
        //M[X] = AC
        Memoria[I.endereco] = AC;
        cout << "STOR " << I.endereco << endl;
        break;
    case 1:
        //AC = M[X]
        AC = Memoria[I.endereco];
        cout << "LOAD " << I.endereco <<endl;
        break;
    case 5:
        //AC = AC + M[X]
        AC = AC + Memoria[I.endereco];
        cout << "ADD " << I.endereco << endl;
        break;
    case 6:
        //AC = AC - M[X]
        AC = AC - Memoria[I.endereco];
        cout << "SUB " << I.endereco << endl;
        break;
    case 11:
        //AC,MQ = MQ * M[X](MBR)
        AC = MQ * Memoria[I.endereco];
        MQ = AC;
        cout << "MUL " << I.endereco <<endl;
        break;
    case 12:
        //AC/M[X]
        AC = AC / Memoria[I.endereco];
        cout << "DIV " << I.endereco << endl;
        break;
    default:
        return 0;
    }
}
    /// Resultado
    cout << "Resultado: " << Memoria[607] << endl;
}
