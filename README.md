# 🚗 Sistema de Cadastro de Veículos em Arquivos C++

> Um sistema completo de gerenciamento de veículos desenvolvido em **C++** com persistência de dados em arquivos **CSV**, implementando algoritmos de ordenação e busca otimizados.
---

## 📋 Sobre o Projeto

Este projeto implementa um **sistema de cadastro e gerenciamento de veículos** com funcionalidades completas de CRUD (Create, Read, Update, Delete). Os dados são armazenados em arquivos CSV, permitindo persistência entre execuções do programa.

### 🎯 Objetivos Educacionais
- Aplicar conceitos de **Estruturas de Dados** (structs)
- Implementar algoritmos de **Ordenação** (Insertion Sort)
- Aplicar técnicas de **Busca Otimizada** (Busca Binária)
- Trabalhar com **Manipulação de Arquivos** em C++
- Gerenciar **Memória Dinâmica**

---

## ✨ Funcionalidades

### 1. **Cadastrar Veículo** 
Adicione novos veículos ao sistema informando:
- Nome do veículo
- Marca
- Ano de lançamento
- Descrição/Cor

### 2. **Listar Veículos**
Visualize todos os veículos cadastrados com opção de:
- Listar todos os registros
- Listar veículos em um intervalo específico

### 3. **Buscar Veículo**
Localize veículos de forma rápida e eficiente por:
- **ID**: usando busca binária em O(log n)
- **Nome**: usando busca binária em O(log n)

Suporta múltiplos veículos com o mesmo nome.

### 4. **Ordenar Veículos**
Organize os registros por:
- ID (ordem numérica)
- Nome (ordem alfabética)

Utiliza o algoritmo **Insertion Sort** para melhor performance em listas pequenas.

### 5. **Deletar Veículo**
Remove veículos do sistema usando **deleção lógica** (ID negativo).

### 6. **Salvar Alterações**
Persiste todas as modificações no arquivo CSV.

### 7. **Sair**
Encerra a aplicação de forma segura.

---

## 🏗️ Estrutura do Projeto

```
Sistema-de-Cadastro-de-Carros-em-Arquivos-CPP/
│
├── main.cpp                 # Arquivo principal com toda a lógica
├── carro.csv               # Arquivo de dados (CSV)
├── README.md               # Este arquivo
└── .gitignore              # Configuração Git
```

### Estrutura de Dados

```cpp
struct Carro {
    int id;              // Identificador único do veículo
    string nome;         // Nome/Modelo do veículo
    string marca;        // Marca do veículo
    int ano;             // Ano de lançamento
    string descricao;    // Descrição (ex: cor)
};
```

---

## 🔧 Requisitos

- **Compilador C++**: GCC, Clang ou MSVC
- **Padrão C++**: C++11 ou superior
- **Sistema Operacional**: Windows, Linux ou macOS
- **Arquivo CSV**: Configurado com o caminho correto

---

## 📦 Instalação e Execução

### 1. Clone o repositório
```bash
git clone https://github.com/joao-Devr/Sistema-de-Cadastro-de-Carros-em-Arquivos-CPP.git
cd Sistema-de-Cadastro-de-Carros-em-Arquivos-CPP
```

### 2. Compile o programa
```bash
g++ -o cadastro_carros main.cpp
```

### 3. Execute
```bash
./cadastro_carros
```
---

## 📊 Formato do Arquivo CSV

O arquivo `carro.csv` deve seguir este formato:

```csv
#id;nome;marca;ano_de_lançamento;descrição
1;Civic;Honda;2018;"Prata"
2;Corolla;Toyota;2020;"Preto"
3;Gol;Volkswagen;2019;"Vermelho"
```

### Estrutura das Colunas:
- **id**: Identificador único (inteiro)
- **nome**: Nome do modelo (texto)
- **marca**: Marca do veículo (texto)
- **ano_de_lançamento**: Ano (inteiro)
- **descrição**: Cor ou descrição (texto entre aspas)

---

## 🧮 Algoritmos Implementados

### Insertion Sort
Utilizado para ordenação de veículos por ID ou Nome.
- **Complexidade**: O(n²) no pior caso, O(n) no melhor caso
- **Estabilidade**: Sim
- **Uso**: Adequado para listas pequenas a médias

```cpp
void InsertionSort_ID(Carro vetor[], int tamanho)
void InsertionSort_Nome(Carro vetor[], int tamanho)
```

### Busca Binária
Implementada recursivamente para buscar veículos por ID ou Nome.
- **Complexidade**: O(log n)
- **Pré-requisito**: Array ordenado
- **Recurso especial**: Encontra múltiplos registros com o mesmo nome

```cpp
int Busca_binaria_numero(Carro vetor[], int inicio, int fim, int procurado)
int Busca_binaria_string(Carro vetor[], int inicio, int fim, string procurado)
```

### Deleção Lógica
Em vez de remover registros fisicamente, o ID é negado:
```cpp
carros[i].id = -carros[i].id;
```

Isso preserva a integridade dos dados e permite recuperação posterior.

---

## 🎓 Conceitos Aplicados

| Conceito | Descrição |
|----------|-----------|
| **Structs** | Organização de dados relacionados |
| **Ponteiros** | Gerenciamento dinâmico de memória |
| **Alocação Dinâmica** | Crescimento automático do array |
| **Algoritmos de Ordenação** | Insertion Sort |
| **Algoritmos de Busca** | Busca Binária Recursiva |
| **I/O de Arquivos** | Leitura e escrita em CSV |
| **Tratamento de Erros** | Validação de entrada e arquivo |

---

## 👥 Autores

| Nome | Função |
|------|--------|
| **Guilherme Oliveira de Brito Silva** | Desenvolvedor |
| **David Marques Alves de Jesus** | Desenvolvedor |
| **João Pedro Campolina Rodrigues** | Desenvolvedor |

---

<div align="center">

Desenvolvido com ❤️ em C++

Se este projeto foi útil para você, considere dar uma ⭐!

</div>
