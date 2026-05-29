#include <iostream>
#include <string>
#include <vector>
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
   vector<Carro> carros;
 
   ifstream Lcarros("C:\\Users\\Usuario\\Desktop\\EUUU\\[Projeto-pratico-IALG]\\carro.csv");

   //#id;nome;marca;ano_de_lançamento;descrição

   // Verifica se o arquivo foi aberto corretamente
   if (!Lcarros.is_open()){
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
   }
   
   Carro c;
   char lixo;
   string cabecalho;
   getline(Lcarros, cabecalho);

   while (Lcarros >> c.id)
   {
      
      Lcarros >> lixo;
      getline(Lcarros, c.nome, ';');
      getline(Lcarros, c.marca, ';');
      Lcarros >> c.ano;
      Lcarros >> lixo;
      getline(Lcarros, c.descricao, '\n');

      carros.push_back(c);
   }

   int opc;
   string nome, marca, descricao;
   int ano;
  do
     {
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
        cin>>descricao;

        c.id = carros.size() + 1;
        c.nome = nome;
        c.marca = marca;
        c.ano = ano;
        c.descricao = descricao;
         carros.push_back(c);
         }
        break;

        case 2:{   

               for(int i = 0; i< int(carros.size()); i++){
                  cout<<"-----------------------------"<<endl;
                  cout << "Carro no indice 1: " << carros[i].nome << endl;
                  cout << "Descricao: " << carros[i].descricao << endl;
                  cout << "Marca: " << carros[i].marca << endl;
                  cout << "Ano: " << carros[i].ano << endl;
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
