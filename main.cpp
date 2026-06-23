/*
 Equipe: Guilherme Oliveira de Brito Silva, David Marques Alves de Jesus, João Pedro Campolina Rodrigues
 Turma: 10A - Professora Marluce
 Tema: Sistema de Cadastro de Veículos (carro.csv)
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Carro
{
   int id;
   string nome;
   string marca;
   int ano;
   string descricao;
};

// adiciona o insertion sort 
void InsertionSort_ID(Carro vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        Carro chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].id > chave.id) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

// função pra ordenar por nome
void InsertionSort_Nome(Carro vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        Carro chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j].nome > chave.nome) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int Busca_binaria_numero(Carro vetor[], int inicio, int fim, int procurado) {     

   int valor_meio;
   
   if (inicio <= fim){
        int meio = (inicio+fim)/2;

         while (vetor[meio].id < 0 && meio < fim)
            meio++;

        if (vetor[meio].id < 0) return -1;

         valor_meio = vetor[meio].id;

        if (procurado > valor_meio)
            return Busca_binaria_numero(vetor,meio+1,fim,procurado);

        else if (procurado < valor_meio)

            return Busca_binaria_numero(vetor,inicio,meio-1,procurado);

        else
            return meio;
    }
    return -1;
}

int Busca_binaria_string(Carro vetor[], int inicio, int fim, string procurado) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        while (vetor[meio].id < 0 && meio < fim) meio++;
        if (vetor[meio].id < 0) return -1;

        string valor_meio = vetor[meio].nome;

        if (procurado > valor_meio)
            return Busca_binaria_string(vetor, meio+1, fim, procurado);
        else if (procurado < valor_meio)
            return Busca_binaria_string(vetor, inicio, meio-1, procurado);
        else
            return meio;
    }
    return -1;
}

int main()
{
    int id=0,ano,opc,inicial=0,final=0;
      string nome, marca, descricao;
   
   ifstream Lista_carros("carro.csv");

   // Verifica se o arquivo foi aberto corretamente
   if (!Lista_carros.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
   }
   
   int capacidade=40,tamanho=0;
   Carro* carros=new Carro [capacidade];

   string cabecalho;
   char lixo;
    
    getline(Lista_carros,cabecalho);
   while (Lista_carros >> id)
   {  
      carros[tamanho].id=id;
      Lista_carros >> lixo;
      getline(Lista_carros,carros[tamanho].nome,';');
      getline(Lista_carros,carros[tamanho].marca,';');
      Lista_carros>>carros[tamanho].ano;
      Lista_carros>>lixo;
      Lista_carros>>lixo;
      getline(Lista_carros,carros[tamanho].descricao,'"');

      tamanho++;

      if(tamanho>=capacidade){
          capacidade+=5;
          Carro* cTemp=new Carro [capacidade];

        for(int i=0;i<tamanho;i++){

        cTemp[i].id=carros[i].id;
        cTemp[i].nome=carros[i].nome;
        cTemp[i].marca=carros[i].marca;
        cTemp[i].ano=carros[i].ano;
        cTemp[i].descricao=carros[i].descricao;

        }
        delete[] carros;
        carros=cTemp;
      }
    }

   
  do
     {
      cout<<"-----------------------------"<<endl;
      cout<<"Escolha uma opcao: "<<endl;  
      cout<<"1. Cadastrar veiculo (informa nome, marca,ano e descricao (cor) )"<<endl;
      cout<<"2. Listar veiculos (imprime nome, marca, ano e descricao de todos os veiculos)"<<endl;
      cout<<"3. Buscar Veiculo "<<endl;
      cout<<"4. Ordenar "<<endl;
      cout<<"5. Apagar Veiculo "<<endl;
      cout<<"6. Salvar alteracoes"<<endl;
      cout<<"7. Sair"<<endl;
      cin>>opc;

      switch(opc){
         case 1:{
         cout<<"digite um nome"<<endl;
        cin>>nome;
        cout<<"digite uma marca"<<endl;
        cin>>marca;
        cout<<"digite um ano "<<endl;
        cin>>ano;
        cout<<"digite uma descricao "<<endl;
        cin.ignore();
        getline(cin, descricao);

         if(tamanho>=capacidade){
          capacidade+=5;
          Carro* cTemp=new Carro [capacidade];

        for(int i=0;i<tamanho;i++){

        cTemp[i] = carros[i];

        }
        delete[] carros;
        carros=cTemp;
      }
      
        carros[tamanho].id=tamanho+1;
        carros[tamanho].nome=nome;
        carros[tamanho].marca=marca;
        carros[tamanho].ano=ano;
        carros[tamanho].descricao=descricao;
        tamanho++;
        }
        break;

        case 2:{   
                  cout<<"Deseja listar os carros em um intervalo? "<<endl;
                  cout<<"1. Sim"<<endl;
                  cout<<"2. Nao"<<endl;
                  int opcao;
                  cin>>opcao;
                  if(opcao==1){
                      cout<<"Digite o inicio do intervalo: "<<endl;
                      cin>>inicial;
                      cout<<"Digite o final do intervalo: "<<endl;
                      cin>>final;
                  }
                  else{
                      inicial=0;
                      final=tamanho;
                  }

               for(int i = inicial; i<final; i++){
                  if (carros[i].id > 0) {
                     cout<<"-----------------------------"<<endl;
                     cout << "Carro do ID " << carros[i].id << ": " << carros[i].nome << endl;
                     cout << "Marca: " << carros[i].marca << endl;
                     cout << "Ano: " << carros[i].ano << endl;
                     cout << "Descricao: " << carros[i].descricao << endl;
                  }
               }

        }
        break;

        case 3:{ 
               int resultado;
               string nome_procurar;
               Carro* cpesquisa = new Carro[tamanho];
                        for(int i=0;i<tamanho;i++){

                        cpesquisa[i] = carros[i];
                     }
               cout<<"Como deseja buscar o veiculo?"<<endl;
               cout<<"1. Por ID"<<endl;
               cout<<"2. Por nome"<<endl;
               int opcao;
               cin>>opcao;
                  if(opcao==1){
                     //chamando a ordenação antes da busca
                     InsertionSort_ID(cpesquisa, tamanho);
                     cout<<"Digite o ID do carro que deseja buscar: "<<endl;
                     int id_procurar;
                     cin>>id_procurar;
                     resultado = Busca_binaria_numero(cpesquisa, 0, tamanho-1, id_procurar);
                  }
                  if(opcao==2){
                     
                     InsertionSort_Nome(cpesquisa, tamanho);
                     cout<<"Digite o nome do carro que deseja buscar: "<<endl;
                    
                     cin.ignore();
                     getline(cin, nome_procurar);
                     resultado = Busca_binaria_string(cpesquisa, 0, tamanho-1, nome_procurar);
                  }

                  if(resultado==-1)
                           cout<<"Carro nao encontrado."<<endl;

                  else{
                           // Encontra o PRIMEIRO com esse nome (expande para cima)
                           int inicio = resultado;
                           while(inicio > 0 && cpesquisa[inicio-1].id > 0 && 
                                 cpesquisa[inicio-1].nome == nome_procurar){
                              inicio--;
                           }
                           
                           // Encontra o ÚLTIMO com esse nome (expande para baixo)
                           int fim = resultado;
                           while(fim < tamanho-1 && cpesquisa[fim+1].id > 0 && 
                                 cpesquisa[fim+1].nome == nome_procurar){
                              fim++;
                           }
                           
                           // Imprime todos encontrados
                           int quantidade = fim - inicio + 1;
                           cout<<"Encontrados " << quantidade << " carro(s):"<<endl;
                           
                           for(int i = inicio; i <= fim; i++){
                              if(cpesquisa[i].id > 0){  // Verifica se não foi deletado
                                          
                           cout << "Carro do ID " << cpesquisa[i].id << ": " << cpesquisa[i].nome << endl;
                           cout << "Marca: " << cpesquisa[i].marca << endl;
                           cout << "Ano: " << cpesquisa[i].ano << endl;
                           cout << "Descricao: " << cpesquisa[i].descricao << endl;
                              }
                        }
                  }
                  delete[] cpesquisa;
               }
        break;

        case 4: { 
            cout<<"Como deseja ordenar os veiculos?"<<endl;
            cout<<"1. Por ID"<<endl;
            cout<<"2. Por Nome"<<endl;
            int opcao_ord;
            cin >> opcao_ord;
            
            if(opcao_ord == 1){
                InsertionSort_ID(carros, tamanho);
                cout << "Veiculos ordenados por ID com sucesso!" << endl;
            } else if(opcao_ord == 2){
                InsertionSort_Nome(carros, tamanho);
                cout << "Veiculos ordenados por Nome com sucesso!" << endl;
            } else {
                cout << "Opcao invalida." << endl;
            }
        }
         break;
         case 5: { 
                  cout<<"Digite o ID do carro que deseja apagar: "<<endl;
                  int id_apagar;
                  cin>>id_apagar;

                     bool encontrado = false;
          
                        for (int i = 0; i < tamanho && !encontrado; i++) {

                           if (carros[i].id == id_apagar) {

                                 carros[i].id = -carros[i].id;
                                 cout << "Carro removido com sucesso!" << endl;
                                 encontrado = true;
                                 }
                        }
                           if (!encontrado)
                              cout << "ID nao encontrado." << endl;
         }
         break;
         case 6: { 
            // cria o csv 
            ofstream arquivo_saida("carro.csv");
            if (!arquivo_saida.is_open()) {
                cout << "Erro ao abrir o arquivo para salvar!" << endl;
            } else {
                // escreve o cabecalho
                arquivo_saida << "#id;nome;marca;ano_de_lançamento;descrição\n";
                for (int i = 0; i < tamanho; i++) {
                    // ignora os apagados
                    if (carros[i].id > 0) {
                        arquivo_saida << carros[i].id << ";"
                                      << carros[i].nome << ";"
                                      << carros[i].marca << ";"
                                      << carros[i].ano << ";\""
                                      << carros[i].descricao << "\"\n";
                    }
                }
                cout << "Alteracoes salvas com sucesso no arquivo carro.csv!" << endl;
                arquivo_saida.close();
            }
         }
         break;
         case 7: cout<<"Saindo..."<<endl;
         break;
      }
}while(opc!=7);

   delete[] carros;
   return 0;
}
