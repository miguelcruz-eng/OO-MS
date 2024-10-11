#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

typedef struct{
    string nome;
    double valor_unitario;
    int quantidade;
    string data_de_vencimento;
    string nome_do_fabricante;
}tInsumos;

typedef struct
{
    tInsumos Dados;
    string tecnologia;
    string doses_necessarias;
    int intervalo_dias;
}tVacinas_Armazenadas;

typedef struct
{
    tInsumos Dados;
    string tecnologia;
    string doses_necessarias;
    int intervalo_dias;
    string estado;
}tVacinas_Distribuidos;

typedef struct
{
    tInsumos Dados;
    string dosagem;
    string administracao;
    string disponibilizacao;
}tMedicamentos_Armazenadas;

typedef struct
{
    tInsumos Dados;
    string dosagem;
    string administracao;
    string disponibilizacao;
    string estado;
}tMedicamentos_Distribuidos;

typedef struct
{
    tInsumos Dados;
    string tipo;
    string especificacao;
}tEPI_Armazenadas;

typedef struct
{
    tInsumos Dados;
    string tipo;
    string especificacao;
    string estado;
}tEPI_Distribuidos;

int vacinas=0;
int medicamentos=0;
int EPI=0;
int vacinasD=0;
int medicamentosD=0;
int EPID=0;

tVacinas_Armazenadas Vac[100];
tMedicamentos_Armazenadas Med[100];
tEPI_Armazenadas EPIs[100];
tVacinas_Distribuidos VacD[100];
tMedicamentos_Distribuidos MedD[100];
tEPI_Distribuidos EPIsD[100];

void Menu_opcoes();
void Menu_Ms();
void Menu_Estadual();
void Cadastro_de_Insumos();
void Consulta_de_Insumos();
void Descricao_de_Insumos();
void Consulta_de_Insumos_Estadual();
void Descricao_de_Insumos_Estadual();
void Consulta_de_Insumos_por_Estado();
void Cadastro_de_Insumos_Estadual();
int Cadastro_de_Vacinas(int m);
int Cadastro_de_Medicamentos(int m);
int Cadastro_de_EPIs(int m);
void Consulta_de_Vacinas(int n);
void Consulta_de_Medicamentos(int n);
void Consulta_de_EPIs(int n);
void Descricao_de_Vacinas(int n);
void Descricao_de_Medicamentos(int n);
void Descricao_de_EPIs(int n);
void Consulta_de_Vacinas_Estadual(int n);
void Consulta_de_Medicamentos_Estadual(int n);
void Consulta_de_EPIs_Estadual(int n);
void Descricao_de_Vacinas_Estadual(int n);
void Descricao_de_Medicamentos_Estadual(int n);
void Descricao_de_EPIs_Estadual(int n);
void Consulta_de_Vacinas_por_Estado(int n);
void Consulta_de_Medicamentos_por_Estado(int n);
void Consulta_de_EPIs_por_Estado(int n);
int Cadastro_de_Vacinas_Estadual(int m, int cont);
int Cadastro_de_Medicamentos_Estadual(int m, int contador);
int Cadastro_de_EPIs_Estadual(int m, int contador);
void salvar();
void salvaDados(string n);

int main(){
    Menu_opcoes();
}

void Menu_opcoes(){
    int option;
    do{
        system("CLS");
        cout<<"|---------- Seja bem vindo ao banco de dados do Ministerio da Saude(MS) ----------|"<<endl;
        cout<< "\nAbaixo se encontra o menu:\n\n" << "1.Estoque do MS. \n" << "2.Informacao de distribuicao estadual. \n" << "3.sair." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Menu_Ms();
            break;
        case 2:
            Menu_Estadual();
            break;
        case 3:
            salvar();
            exit(0);
        default:
            break;
        }
    }while (1);
}

void Menu_Ms(){
    int option;
    do{
        system("CLS");
        cout<<"|-|-|-|-|Estoque do Ms|-|-|-|-| \n"<<"1.Cadastro de insumos. \n"<<"2.Colsutar insumos disponiveis \n"<<"3.Descricao dos insumos disponiveis \n"<<"4.voltar "<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Cadastro_de_Insumos();
            break;
        case 2:
            Consulta_de_Insumos();
            break;
        case 3:
            Descricao_de_Insumos();
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }while (1);
}

void Cadastro_de_Insumos(){
    int option;
    do{
        system("CLS");
        cout<< "Cadastro de Insumos: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            vacinas=Cadastro_de_Vacinas(vacinas);
            break;
        case 2:
            medicamentos = Cadastro_de_Medicamentos(medicamentos);
            break;
        case 3:
            EPI=Cadastro_de_EPIs(EPI);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Menu_Estadual(){
    int option;
    do{
        system("CLS");
        cout<< "Informacao de distribuicao estadual: \n" <<"1. Consultar insumos para estados\n2. consultar descricao dos insumos distribuidos para os estados\n3. Consultar insumos em um estado especifico\n4. Ceder insumo a um estado\n5. voltar" <<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Consulta_de_Insumos_Estadual();
            break;
        case 2:
            Descricao_de_Insumos_Estadual();
            break;
        case 3:
            Consulta_de_Insumos_por_Estado();
            break;
        case 4:
            Cadastro_de_Insumos_Estadual();
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }while (1);
}

void Consulta_de_Insumos(){
    int option;
    do{
        system("CLS");
        cout<< "Consultar insumos disponiveis: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Consulta_de_Vacinas(vacinas);
            break;
        case 2:
            Consulta_de_Medicamentos(medicamentos);
            break;
        case 3:
            Consulta_de_EPIs(EPI);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Descricao_de_Insumos(){
    int option;
    do{
        system("CLS");
        cout<< "Consultar descricao dos insumos disponiveis: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Descricao_de_Vacinas(vacinas);
            break;
        case 2:
            Descricao_de_Medicamentos(medicamentos);
            break;
        case 3:
            Descricao_de_EPIs(EPI);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Consulta_de_Insumos_Estadual(){
    int option;
    do{
        system("CLS");
        cout<< "Consultar insumos disponiveis para os estados: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Consulta_de_Vacinas_Estadual(vacinasD);
            break;
        case 2:
            Consulta_de_Medicamentos_Estadual(medicamentosD);
            break;
        case 3:
            Consulta_de_EPIs_Estadual(EPID);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Descricao_de_Insumos_Estadual(){
    int option;
    do{
        system("CLS");
        cout<< "Consultar descricao dos insumos disponiveis: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Descricao_de_Vacinas_Estadual(vacinasD);
            break;
        case 2:
            Descricao_de_Medicamentos_Estadual(medicamentosD);
            break;
        case 3:
            Descricao_de_EPIs_Estadual(EPID);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Consulta_de_Insumos_por_Estado(){
    int option;
    do{
        system("CLS");
        cout<< "Consultar insumos disponiveis para os estados: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Consulta_de_Vacinas_por_Estado(vacinasD);
            break;
        case 2:
            Consulta_de_Medicamentos_por_Estado(medicamentosD);
            break;
        case 3:
            Consulta_de_EPIs_por_Estado(EPID);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

void Cadastro_de_Insumos_Estadual(){
    int option;
    do{
        system("CLS");
        cout<< "Cadastro de Insumos: \n" << "1.Vacinas. \n" << "2.Medicamentos. \n" << "3.EPIs.\n" << "4.voltar." << endl;
        cin>>option;
        switch (option)
        {
        case 1:
            Cadastro_de_Vacinas_Estadual(vacinas,vacinasD);
            break;
        case 2:
            medicamentos = Cadastro_de_Medicamentos_Estadual(medicamentos,medicamentosD);
            break;
        case 3:
            EPID=Cadastro_de_EPIs_Estadual(EPI,EPID);
            break;
        case 4:
            return;
        default:
            break;
        }
    }while (1);
}

int Cadastro_de_Vacinas(int m){
    system("CLS"); //limpa a tela de saída de todo o programa

    int i, N;

    cout<<"Quantas Vacinas serao armazenadas? " << endl;
    cin >> N;

    for(i = m;i < N+m;i++){
        getchar();
        cout<<"Digite o nome da vacina:" << endl;
        getline(cin,Vac[i].Dados.nome);

        cout<<"Digite o valor da vacina(em real):" << endl;
        cin>>Vac[i].Dados.valor_unitario;

        cout<<"Serao quantas vacinas?" << endl;
        cin>>Vac[i].Dados.quantidade;

        cout<<"Digite a data de vencimento da vacina:" << endl;
        getchar();
        getline(cin,Vac[i].Dados.data_de_vencimento);

        cout<<"Qual o nome do fabricante da vacina?" << endl;
        getline(cin,Vac[i].Dados.nome_do_fabricante);

        cout<<"Agora digite a tecnologia da vacina:" << endl;
        getline(cin,Vac[i].tecnologia);

        cout<<"Digite as doses necessarias da vacina :" << endl;
        getline(cin,Vac[i].doses_necessarias);

        cout<<"Digite o intervalo de dias entre as dosagens da vacina :" << endl;
        cin>>Vac[i].intervalo_dias;

    }
    return N+m;
}

int Cadastro_de_Medicamentos(int antigo){
    int numb;
    cout << "quantos medicamentos a serem armazenados?\n";
    cin >> numb;
    for(int i=antigo;i<numb+antigo; i++){
        cout << "Digite o nome e valor unitario:\n";
        getchar();
        getline(cin,Med[i].Dados.nome);
        cin >>Med[i].Dados.valor_unitario;
        cout << "Digite agora a quantidade e depois, a data de vencimento:\n";
        cin >> Med[i].Dados.quantidade;
        getchar();
        getline(cin,Med[i].Dados.data_de_vencimento);
        cout <<"Agora digite o nome do fabricante e a dosagem:\n";
        getline(cin,Med[i].Dados.nome_do_fabricante);
        getline(cin,Med[i].dosagem);
        cout << "Agora digite a forma de administra o medicamento e a forma disponibilizada:\n";

        getline(cin,Med[i].administracao);
        getline(cin, Med[i].disponibilizacao);
    }
    return numb = numb+antigo;
}

int Cadastro_de_EPIs(int m){
    system("CLS");
    int i;
    int n;
    cout<<"Digite a quantidade de EPIs a serem cadastrados"<<endl;
    cin>>n;
    getchar();
    for(i=m;i<m+n;i++){
        cout<<"Digite o nome do EPI:"<<endl;
        getline(cin,EPIs[i].Dados.nome);
        cout<<"Digite o valor em real EPI:"<<endl;
        cin>>EPIs[i].Dados.valor_unitario;
        cout<<"Digite a quantidade desse EPI:"<<endl;
        cin>>EPIs[i].Dados.quantidade;
        cout<<"Digite a data de vencimento desse EPI:"<<endl;
        getchar();
        getline(cin,EPIs[i].Dados.data_de_vencimento);
        cout<<"Digite o nome do fabricante desse EPI:"<<endl;
        getline(cin,EPIs[i].Dados.nome_do_fabricante);
        cout<<"Digite o tipo do EPI:"<<endl;
        getline(cin,EPIs[i].tipo);
        cout<<"Digite a informacao sobre esse EPI:"<<endl;
        getline(cin,EPIs[i].especificacao);
    }
    return n+m;
}

void Consulta_de_Vacinas(int n){
    system("CLS");// limpa a tela de saída de todo o programa

    int retorno , i;

    cout << "Agora vamos consultar as vacinas." << endl;

    if(n == 0){
        cout << "O sistema nao possui dados salvos." << endl;
    }else{
        cout << "Insumos Disponiveis:" << endl;

    for(i = 0; i < n; i++){
        if(Vac[i].Dados.quantidade>0){
            cout << Vac[i].Dados.nome << ":" << Vac[i].Dados.quantidade << " unidades." << endl;
        }else{
            cout << Vac[i].Dados.nome << ":" << " nenhuma unidade. " << endl;
        }
    }
    }

    //Determina a saída da função e o retorno ao programa
    while (1){
    cout << "1.voltar" << endl;

    cin >> retorno;

    switch(retorno){
    case 1:
        return;
        break;
    default:
        break;
    }
    }
}

void Consulta_de_Medicamentos(int n){
     system("CLS");
    int button=0;
    int i;
    cout<<"Consulta de medicamentos: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(Med[i].Dados.quantidade>0){
            cout<<Med[i].Dados.nome<<": "<<Med[i].Dados.quantidade<<" unidades."<<endl;
        }else{
            cout<<Med[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }
    }

}

void Consulta_de_EPIs(int n){
    system("CLS");
    int button=0;
    int i;
    cout<<"Consulta de EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(EPIs[i].Dados.quantidade>0){
            cout<<EPIs[i].Dados.nome<<": "<<EPIs[i].Dados.quantidade<<" unidades."<<endl;
        }else{
            cout<<EPIs[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Descricao_de_Vacinas(int n){
    system("CLS");

    int retorno = 0, i;

    cout << "Consultaremos agora a descricao das vacinas: " << endl;

    if(n == 0){
        cout << "O sistema nao possui dados salvos." << endl;
    }else{
        cout << "Insumos Disponiveis:" << endl;
    for(i = 0;i < n;i++){
        cout << Vac[i].Dados.nome<<": \n"<< "Descricao: "
        << Vac[i].doses_necessarias << " a cada " << Vac[i].intervalo_dias
        << "dia(s)/Tecnologia: "<< Vac[i].tecnologia << endl;
    }
    }
    while (1)
    {
    cout << "1.voltar" << endl;

    cin >> retorno;

    switch (retorno)
    {
    case 1:
        return;
        break;
    default:
        break;
    }
    }
}

void Descricao_de_Medicamentos(int n){
        system("CLS");
    int button=0;
    int i;
    cout<<"Consulta da descricao dos medicamentos: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        cout<<Med[i].Dados.nome<<": \n"<< "Descricao: " <<Med[i].dosagem << ", " << Med[i].administracao << ", " << Med[i].disponibilizacao<<endl;
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Descricao_de_EPIs(int n){
    system("CLS");
    int button=0;
    int i;
    cout<<"Consulta da descricao dos EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        cout<<EPIs[i].Dados.nome<<": \n"<< "Descricao: " <<EPIs[i].especificacao<<endl;
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Consulta_de_Vacinas_Estadual(int n){
    system("CLS");

    int retorno = 0, i;

    cout << "Consulta de Vacinas." << endl;

    if(n == 0){
        cout << "O sistema nao possui dados salvos." << endl;
    }else{
        cout << "Insumos Disponiveis:" << endl;
    for(i = 0;i < n;i++){
        if(VacD[i].Dados.quantidade>0){
            cout << VacD[i].Dados.nome << ": " << VacD[i].Dados.quantidade << " unidades" <<endl;
        }else{
            cout << VacD[i].Dados.nome << ": " << " fora de estoque." << endl;
        }
    }
    }
    while (1){
    cout << "1.voltar" << endl;

    cin >> retorno;
    switch (retorno)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Consulta_de_Medicamentos_Estadual(int n){
        system("CLS");
    int button=0;
    int i;
    cout<<"Consulta de medicamentos: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(MedD[i].Dados.quantidade>0){
            cout<<MedD[i].Dados.nome<<": "<<MedD[i].Dados.quantidade<<" unidades " << MedD[i].estado <<endl;
        }else{
            cout<<MedD[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }


}
}

void Consulta_de_EPIs_Estadual(int n){
    system("CLS");
    int button=0;
    int i;
    cout<<"Consulta de EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(EPIsD[i].Dados.quantidade>0){
            cout<<EPIsD[i].Dados.nome<<": "<<EPIsD[i].Dados.quantidade<<" unidades"<<endl;
        }else{
            cout<<EPIsD[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Descricao_de_Vacinas_Estadual(int n){
    system("CLS");

    int retorno = 0, i;
    cout << "Consulta da descricao das Vacinas: " << endl;
    if(n == 0){
        cout << "O sistema nao possui dados salvos." << endl;
    }else{
        cout << "Insumos Disponiveis:" << endl;
    for(i = 0;i < n;i++){
        if(VacD[i].Dados.quantidade>0){
            cout << VacD[i].Dados.nome << ": \n" << "Descricao: "
            << VacD[i].doses_necessarias << " a cada " << VacD[i].intervalo_dias << "dia(s)/"
            "Tecnologia: "<< VacD[i].tecnologia << endl;
        }
    }
    }
    while (1){
    cout<<"1.voltar."<<endl;

    cin >> retorno;
    switch (retorno){
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Descricao_de_Medicamentos_Estadual(int n){
        system("CLS");
    int button=0;
    int i;
    cout<<"Consulta da descricao dos medicamentos: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(MedD[i].Dados.quantidade>0){
            cout<<MedD[i].Dados.nome<<": \n"<< "Descricao: " <<MedD[i].dosagem << ", " << MedD[i].administracao << ", " << MedD[i].disponibilizacao<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }

}

void Descricao_de_EPIs_Estadual(int n){
    system("CLS");
    int button=0;
    int i;
    cout<<"Consulta da descricao dos EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis:"<<endl;
    for(i=0;i<n;i++){
        if(EPIsD[i].Dados.quantidade>0){
            cout<<EPIsD[i].Dados.nome<<": \n"<< "Descricao: " <<EPIsD[i].especificacao<<endl;
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

void Consulta_de_Vacinas_por_Estado(int n){
    system("CLS");

    string Estado;
    int retorno = 0, i;
    cout << "Digite o nome do Estado: " << endl;

    getchar();

    getline(cin, Estado);
    cout << "Consulta de Vacinas: " << endl;
    if(n == 0){
        cout << "O sistema nao possui dados salvos." << endl;
    }else{
        cout << "Insumos Disponiveis para " << Estado << ":" << endl;
    for(i = 0;i < n;i++){
        if(VacD[i].estado == Estado){
        if(VacD[i].Dados.quantidade > 0){
            cout << VacD[i].Dados.nome << ": " << VacD[i].Dados.quantidade << " unidades" << endl;
        }else{
            cout << VacD[i].Dados.nome << ": " << " fora de estoque." << endl;
        }
        }
    }
    }
    while (1){
    cout << "1.voltar." << endl;

    cin >> retorno;
    switch (retorno){
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}


void Consulta_de_Medicamentos_por_Estado(int n ){
      system("CLS");
    string Estado;
    int button=0;
    int i;
    cout<<"Digite o nome do Estado: "<<endl;
    getchar();
    getline(cin,Estado);
    cout<<"Consulta de EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis para"<<Estado<<":"<<endl;
    for(i=0;i<n;i++){
        if(MedD[i].estado==Estado){
        if(MedD[i].Dados.quantidade>0){
            cout<<MedD[i].Dados.nome<<": "<<MedD[i].Dados.quantidade<<" unidades"<<endl;
        }else{
            cout<<MedD[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }

}

void Consulta_de_EPIs_por_Estado(int n){
    system("CLS");
    string Estado;
    int button=0;
    int i;
    cout<<"Digite o nome do Estado: "<<endl;
    getchar();
    getline(cin,Estado);
    cout<<"Consulta de EPIs: "<<endl;
    if(n==0){
        cout<<"Nao ha dados salvos."<<endl;

    }else{
        cout<<"Insumos Disponiveis para"<<Estado<<":"<<endl;
    for(i=0;i<n;i++){
        if(EPIsD[i].estado==Estado){
        if(EPIsD[i].Dados.quantidade>0){
            cout<<EPIsD[i].Dados.nome<<": "<<EPIsD[i].Dados.quantidade<<" unidades"<<endl;
        }else{
            cout<<EPIsD[i].Dados.nome<<": "<<" fora de estoque."<<endl;
        }
        }
    }
    }
    while (1)
    {
    cout<<"1.voltar"<<endl;
    cin>>button;
    switch (button)
    {
    case 1:
        return;
        break;
    default:
        break;
    }

    }
}

int Cadastro_de_Vacinas_Estadual(int m, int cont){
    system("CLS");

    int i;
    int n;

    cout << "Vacinas disponiveis para envio estadual:" << endl;
    for(i = 0;i < m; i++){
        cout << i+1 << "." << Vac[i].Dados.nome << "|" << Vac[i].Dados.quantidade << " unidades." << endl;
    }
    cout << "Escolha a Vacina para distribuicao: " << endl;
    cin >> n;

    n = n - 1;
    getchar();

    cout << "Digite o Estado para qual enviar: " << endl;
    getline(cin, VacD[cont].estado);

    //Vai copiar todos os dados para a estrutura (struct) atual
    VacD[cont].Dados.nome = Vac[n].Dados.nome;
    VacD[cont].Dados.valor_unitario = Vac[n].Dados.valor_unitario;
    VacD[cont].Dados.data_de_vencimento = Vac[n].Dados.data_de_vencimento;
    VacD[cont].Dados.nome_do_fabricante = Vac[n].Dados.nome_do_fabricante;
    VacD[cont].tecnologia = Vac[n].tecnologia;
    VacD[cont].doses_necessarias = Vac[n].doses_necessarias;
    VacD[cont].intervalo_dias = Vac[n].intervalo_dias;

    cout<<"Digite quantas dessa vacina enviar"<<endl;
    cin>>VacD[cont].Dados.quantidade;
    Vac[n].Dados.quantidade-=VacD[cont].Dados.quantidade;
    cont = cont + 1;

    return cont;
}

int Cadastro_de_Medicamentos_Estadual(int m, int contador){
        system("CLS");
    int i,n;
    cout<<"medicamentos disponiveis para envio estadual:"<<endl;
    for(i=0;i<m;i++){
        cout<<i+1<<"."<<Med[i].Dados.nome<<"|"<<Med[i].Dados.quantidade<<" unidades."<<endl;
    }
    cout<<"Escolha o medicamentos para distribuir:"<<endl;
    cin>>n;
    n--;
    getchar();
    cout<<"Digite o estado para qual enviar"<<endl;
    getline(cin,MedD[contador].estado);
    //copia todos os dados para a struct estadual
    MedD[contador].Dados.nome=Med[n].Dados.nome;
    MedD[contador].Dados.valor_unitario=Med[n].Dados.valor_unitario;
    MedD[contador].Dados.data_de_vencimento=Med[n].Dados.data_de_vencimento;
    MedD[contador].Dados.nome_do_fabricante=Med[n].Dados.nome_do_fabricante;
    MedD[contador].dosagem=Med[n].dosagem;
    MedD[contador].administracao=Med[n].administracao;
    MedD[contador].disponibilizacao=Med[n].disponibilizacao;

    cout<<"Escreva quantos desse medicamentos enviar"<<endl;
    cin>>MedD[contador].Dados.quantidade;
    Med[n].Dados.quantidade-=MedD[contador].Dados.quantidade;
    contador++;

    return contador;
}

int Cadastro_de_EPIs_Estadual(int m, int contador){
    system("CLS");
    int i,n;
    cout<<"EPIs disponiveis para envio estadual:"<<endl;
    for(i=0;i<m;i++){
        cout<<i+1<<"."<<EPIs[i].Dados.nome<<"|"<<EPIs[i].Dados.quantidade<<" unidades."<<endl;
    }
    cout<<"Escolha o EPI para distribuir:"<<endl;
    cin>>n;
    n--;
    getchar();
    cout<<"Digite o estado para qual enviar"<<endl;
    getline(cin,EPIsD[contador].estado);
    //copia todos os dados para a struct estadual
    EPIsD[contador].Dados.nome=EPIs[n].Dados.nome;
    EPIsD[contador].Dados.valor_unitario=EPIs[n].Dados.valor_unitario;
    EPIsD[contador].Dados.data_de_vencimento=EPIs[n].Dados.data_de_vencimento;
    EPIsD[contador].Dados.nome_do_fabricante=EPIs[n].Dados.nome_do_fabricante;
    EPIsD[contador].tipo=EPIs[n].tipo;
    EPIsD[contador].especificacao=EPIs[n].especificacao;

    cout<<"Digite quantos desse EPI enviar"<<endl;
    cin>>EPIsD[contador].Dados.quantidade;
    EPIs[n].Dados.quantidade-=EPIsD[contador].Dados.quantidade;
    contador++;

    return contador;
}
void salvar(){
    int confirmacao;
    string nome_Arquivo;
    do{
    system("CLS");
    cout<<"Deseja salvar todas as alteracoes?\n1.sim\n2.nao "<<endl;
    cin>>confirmacao;
    switch(confirmacao){
    case 1:
    cout<<"Qual o nome do arquivo que sera criado? "<<endl;
    cin>>nome_Arquivo;
    nome_Arquivo+=".txt";
    salvaDados(nome_Arquivo);
    return;
    break;
    case 2:
    return;
    break;
    default:
    cout<<"Opçao invalida, tente novamente."<<endl;
    break;
    }
    }while(1);
}
void salvaDados(string NOme_do_Arquivo){
    int i;
    // entrada.
ifstream in; // in é uma variável.
in.open(NOme_do_Arquivo); // o arquivo que será usado
//in>>x;  //carrega os valores da primeira linha e envia para a variavel x;

//saida

ofstream out; // out é uma variavel.
out.open(NOme_do_Arquivo); // o arquivo que será criado;
    for(i=0;i<vacinas;i++){
        out<<"Estoque de vacinas do MS:"<<endl;
        out<<"Nome\tValor\tQuantidade\tData de Vencimento\tFabricante\tTecnologia\tDoses\tIntervalo de Dias"<<endl;
        out<<Vac[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<Vac[i].Dados.valor_unitario<<"\t";
        out<<Vac[i].Dados.quantidade<<"\t";
        out<<Vac[i].Dados.data_de_vencimento<<"\t";
        out<<Vac[i].Dados.nome_do_fabricante<<"\t";
        out<<Vac[i].tecnologia<<"\t";
        out<<Vac[i].doses_necessarias<<"\t";
        out<<Vac[i].intervalo_dias<<endl<<endl;
    }

    for(i=0;i<vacinasD;i++){
        out<<"Vacinas distribuidas para estados:"<<endl;
        out<<"Nome\tValor\tQuantidade\tData de Vencimento\tFabricante\tTecnologia\tDoses\tIntervalo de Dias\tEstado"<<endl;
        out<<VacD[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<VacD[i].Dados.valor_unitario<<"\t";
        out<<VacD[i].Dados.quantidade<<"\t";
        out<<VacD[i].Dados.data_de_vencimento<<"\t";
        out<<VacD[i].Dados.nome_do_fabricante<<"\t";
        out<<VacD[i].tecnologia<<"\t";
        out<<VacD[i].doses_necessarias<<"\t";
        out<<VacD[i].intervalo_dias;
        out<<VacD[i].estado<<endl<<endl;
    }

    for(i=0;i<medicamentos;i++){
        out<<"Estoque de medicamentos do MS:"<<endl;
        out<<"Nome\tValor\tQuantidade\tData de Vencimento\tFabricante,Dosagem\tAdministracao\tDisponibilidade"<<endl;
        out<<Med[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<Med[i].Dados.valor_unitario<<"\t";
        out<<Med[i].Dados.quantidade<<"\t";
        out<<Med[i].Dados.data_de_vencimento<<"\t";
        out<<Med[i].Dados.nome_do_fabricante<<"\t";
        out<<Med[i].dosagem<<"\t";
        out<<Med[i].administracao<<"\t";
        out<<Med[i].disponibilizacao<<endl<<endl;
    }

    for(i=0;i<medicamentosD;i++){
        out<<"Medicamentos distribuidos para estados:"<<endl;
        out<<"Nome,Valor\tQuantidade\tData de Vencimento\tFabricante\tDosagem\tAdministracao\tDisponibilidade\tEstado"<<endl;
        out<<MedD[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<MedD[i].Dados.valor_unitario<<"\t";
        out<<MedD[i].Dados.quantidade<<"\t";
        out<<MedD[i].Dados.data_de_vencimento<<"\t";
        out<<MedD[i].Dados.nome_do_fabricante<<"\t";
        out<<MedD[i].dosagem<<"\t";
        out<<MedD[i].administracao<<"\t";
        out<<MedD[i].disponibilizacao;
        out<<MedD[i].estado<<endl<<endl;
    }

    for(i=0;i<EPI;i++){
        out<<"Estoque de EPIs do MS:"<<endl;
        out<<"Nome\tValor\tQuantidade\tData de Vencimento\tFabricante\tTipo\tDescrição"<<endl;
        out<<EPIs[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<EPIs[i].Dados.valor_unitario<<"\t";
        out<<EPIs[i].Dados.quantidade<<"\t";
        out<<EPIs[i].Dados.data_de_vencimento<<"\t";
        out<<EPIs[i].Dados.nome_do_fabricante<<"\t";
        out<<EPIs[i].tipo<<"\t";
        out<<EPIs[i].especificacao<<endl<<endl;
    }

    for(i=0;i<EPID;i++){
        out<<"EPIs distribuidas para estados:"<<endl;
        out<<"Nome\tValor\tQuantidade\tData de Vencimento\tFabricante\tTipo\tDescrição\tEstado"<<endl;
        out<<EPIsD[i].Dados.nome<<"\t";  // saida de uma variavel
        out<<EPIsD[i].Dados.valor_unitario<<"\t";
        out<<EPIsD[i].Dados.quantidade<<"\t";
        out<<EPIsD[i].Dados.data_de_vencimento<<"\t";
        out<<EPIsD[i].Dados.nome_do_fabricante<<"\t";
        out<<EPIsD[i].tipo<<"\t";
        out<<EPIsD[i].especificacao;
        out<<EPIsD[i].estado<<endl<<endl;
    }



out.close(); // não oesqueça de fechar...

}