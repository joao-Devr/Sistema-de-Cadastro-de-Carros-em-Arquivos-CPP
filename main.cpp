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

int main()
{
    int id=0,ano,opc;
      string nome, marca, descricao;
   
   ifstream Lista_carros("C:\\Users\\Usuario\\Desktop\\EUUU\\Projeto-pratico-IALG\\carro.csv");

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
      cout<<"id: "<<carros[tamanho].id<<endl;
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
      cout<<"1. Cadastrar veiculo (informa nome, marca,ano e descrição (cor) )"<<endl;
      cout<<"2. Listar veiculos (imprime nome, marca, ano e descrição de todos os veiculos)"<<endl;
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

               for(int i = 0; i<tamanho; i++){
                  cout<<"-----------------------------"<<endl;
                  cout << "Carro do ID " << carros[i].id << ": " << carros[i].nome << endl;
                  cout << "Marca: " << carros[i].marca << endl;
                  cout << "Ano: " << carros[i].ano << endl;
                  cout << "Descricao: " << carros[i].descricao << endl;
               }

        }
        break;

        case 3:{
        }
        break;

        case 4: {
        }
         break;
         case 5: {
         }
         break;
         case 6: {
         }
         break;
         case 7: cout<<"Saindo..."<<endl;
         break;
     }
}while(opc!=7);

   return 0;
}
