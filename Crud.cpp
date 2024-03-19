//Nesta parte, incluímos todas as bibliotecas necessárias, como iostream, vector, string e fstream.
//Além disso, incluímos todas as classes que iremos usar para organizar o nosso CRUD.
#include <iostream>
using namespace std; 
#include <string>
#include "Android.h"
#include "Crud.h"    
#include "Ios.h"
#include "Telefone.h"
#include <fstream>
#include "Cliente.h"
#include <vector>


//Aqui é o nosso construtor.
Crud::Crud() { }


// Esse é um metodo de pesquisa dos nomes dos aparelhos dentro do vetor.
int Crud::pesquisaTel(string nome) {

    for (int i = 0; i < telefones.size(); i++) {
        if (telefones[i]->getNomeTel() == nome) {
            return i;
        }
    }
    return -1;
}

// Esse outro método de pesquisa é responsável por ir dentro do vetor de clientes e pesquisar os dados nome e login/senha, tratamos essa última variável de duas formas.
int Crud::pesquisaCliente(string nome, string login){
  
    
    for(int i = 0; i < pessoas.size(); i++){
      Cliente *clientTemp = dynamic_cast<Cliente *>(pessoas[i]);
        if (pessoas[i]->getNome() == nome && clientTemp->getLogin() == login){
  
          return i;
       }
      }
  return -1;
}


// Método que vamos usar como a base para o nosso CRUD, vai ser ele vai controlar basicamente o nosso programa.
void Crud::imprimirCrud() {

  contador = 0;

  fstream arquivoTelefones("telefones.txt", ios::in); // Por meio da biblioteca fstream e a sua função fstream, realizamos aqui a abertura do nosso arquivo, no modo apenas de leitura.

  // Esse if que criamos verifica a abertura do arquivo.
  if (!arquivoTelefones) {
      cerr << "Erro ao abrir o arquivo." << endl;
      throw runtime_error("Não foi possível abrir o arquivo 'telefones.txt'."); 
  } else {}

  string line;
  string tipo0, marca0, nome0, tamTela0, conectividade0, processador0, digital0, versaoIos0, versaoAnd0, faceID0, bateria0, mram0, camFrontal0;
  string camTraseira0, memoria0, preco0;
  string quant0;

  
   // Esta lógica utiliza várias verificações para passar aquilo que está no arquivo para o vetor, telefones. O while lê cada linha do arquivo até encontrar uma linha vazia, esse conjunto de condições verificam se uma string está vazia() caso positivo, atribuem a informação lida do arquivo a essa string), essa leitura acontece de forma que a ordem de cada condição vai obedecer a sequência de cada item que está no arquivo.
   while (getline(arquivoTelefones, line)) {
    if (line.empty()) {
        continue;
    }
    if (tipo0.empty()) {
        tipo0 = line;
    }
    else if (marca0.empty()) {
        marca0 = line;
    }
    else if (nome0.empty()) {
        nome0 = line;
    }
    else if (preco0.empty()) {
        preco0 = line;
    }
    else if (tamTela0.empty()) {
        tamTela0 = line;
    }
    else if (bateria0.empty()) {
          bateria0 = line;
    }
    else if (mram0.empty()) {
          mram0 = line;
    }
    else if (camFrontal0.empty()) {
          camFrontal0 = line;
    }
    else if (camTraseira0.empty()) {
          camTraseira0 = line;
    }
    else if (conectividade0.empty()) {
          conectividade0 = line;
    }
    else if (processador0.empty()) {
            processador0 = line;
    }
    else if (memoria0.empty()) {
            memoria0 = line;
    } 
    else if(quant0.empty()){
            quant0 = line;
    }
    else {

        if (line == "/") {
            Telefone *t;
            if (tipo0 == "Android") {
                t = new Android(tipo0, marca0, nome0, preco0, tamTela0, bateria0, mram0, camFrontal0, camTraseira0, conectividade0, processador0, memoria0, quant0, digital0, versaoAnd0);
            }

            else if (tipo0 == "iOS") {
                t =new Ios(tipo0, marca0, nome0, preco0, tamTela0, bateria0, mram0, camFrontal0, camTraseira0, conectividade0, processador0, memoria0, quant0, faceID0, digital0, versaoIos0);
            }
            contador++;
            telefones.push_back(t)

            tipo0.clear();
            marca0.clear();
            nome0.clear();
            preco0.clear();
            tamTela0.clear();
            conectividade0.clear();
            processador0.clear();
            digital0.clear();
            versaoIos0.clear();
            versaoAnd0.clear();
            faceID0.clear();
            bateria0.clear();
            mram0.clear();
            camFrontal0.clear();
            camTraseira0.clear();
            memoria0.clear();
            quant0.clear();
        }

        else {
            if (tipo0 == "iOS") {
                if (faceID0.empty()) {
                    faceID0 = line;
                }

                else if (digital0.empty()) {
                    digital0 = line;
                }

                else if (versaoIos0.empty()) {
                    versaoIos0 = line;
                }   
            }

            else if (tipo0 == "Android") {
                if (digital0.empty()) {
                    digital0 = line;
                }

                else if (versaoAnd0.empty()) {
                    versaoAnd0 = line;
                }
            }
        }
    }
}

        // Nessa parte, vamos reutilizar a mesma lógica descrita anteriormente para ler o arquivo e passar os seus dados para um vetor.
        int cont2 = 0;
        string line1;
        string name0, CPF0, nasc0, login0 , numCel0, end0, email0;

  fstream arquivoClientes("clientes.txt", ios::in); // Vamos abrir o arquivo

  // Aqui verifica se o arquivo abriu corretamente
  if (!arquivoClientes) {
      cerr << "Erro ao abrir o arquivo." << endl;
      throw runtime_error("Não foi possível abrir o arquivo 'clientes.txt'."); 
  } else {}

  while (getline(arquivoClientes, line1)) {
      if (line1.empty()) {
          continue;
      }
      if (name0.empty()) {
          name0 = line1;
      }
      else if (CPF0.empty()) {
          CPF0 = line1;
      }
      else if (nasc0.empty()) {
          nasc0 = line1;
      }
      else if (login0.empty()) {
            login0 = line1;
      } 
      else if (numCel0.empty()) {
          numCel0 = line1;
      }
      else if (end0.empty()) {
          end0 = line1;
      }
      else if (email0.empty()) {
          email0 = line1;
      } 

      else {
          if (line1 == "|") {
              pessoas.push_back(new Cliente(name0, CPF0, nasc0, login0, numCel0, end0, email0));

              cont2++;
          }
          name0.clear();
          CPF0.clear();
          nasc0.clear();
          login0.clear();
          numCel0.clear();
          end0.clear();
          email0.clear();
      }
  }


arquivoClientes.close();
arquivoTelefones.close();

    // Criando aqui variáveis que vamos utilizar ao longo de nosso CRUD.
    int opcao = 0;
    int opcao2 = 0;
    int qtd = 0;
    int posicao = 0;
    int posicaoadicionar = 0;
    int quantmais = 0;
    int opcaoadicionar = 0;
    string tipo, marca, nome, tamTela, conectividade, processador, digital, versaoIos, versaoAnd, faceID;
    string bateria, mram, camFrontal, camTraseira, memoria, preco, quant;


  // O nosso CRUD vai ser baseado nesse while, que só encerrará seu loop por meio de uma opção de saída dentro dele.
    while (opcao != 7) {

      // O menu inicial.
      cout << "**************************" << endl;
      cout << "*   Menu Inicial         *" << endl;
      cout << "**************************" << endl;
      cout << "* 1. Inserir             *" << endl;
      cout << "* 2. Listar todos        *" << endl;
      cout << "* 3. Pesquisar Telefone  *" << endl;
      cout << "* 4. Alterar             *" << endl;
      cout << "* 5. Pedido              *" << endl;
      cout << "* 6. Exibir Relatorio    *" << endl;
      cout << "* 7. Sair                *" << endl;
      cout << "**************************" << endl;
      cout << "\n";
      cout << "* Escolha uma opção: ";
      cin >> opcao;
      cout << "\n";

        // Dependendo da escolha a partir do menu, um case diferente vai ser selecionado .
        switch (opcao) {

          // O case 1 permite ao usuário inserir um telefone no estoque.
            case 1:

              // Menu de inserção
              cout << "***********************************" << endl;
              cout << "*         Menu de Inserção        *" << endl;
              cout << "***********************************" << endl;
              cout << "* 1. Inserir um Android           *" << endl;
              cout << "* 2. Inserir um iOS               *" << endl;
              cout << "***********************************" << endl;
              cout << "\n";
              cout << "* Escolha uma opção: ";
              cin >> opcao2;
              cout << "\n";

                // Escolhendo essa opção temos a escolha de inserir um Android. 
                if (opcao2 == 1) {

                    cout << "***********************************" << endl;
                    cout << "*        Inserir Androids         *" << endl;
                    cout << "***********************************" << endl;
                    cout << "* Quantos androids deseja inserir?*" << endl;
                    cout << "***********************************" << endl;
                    cout << "\n";
                    cout << "* Digite aqui a quantidade: ";
                    cin >> qtd;
                    cout << "\n";


                    // Um for que se baseia na quantidade que o usuário deseja inserir
                    for (int i = 0; i < qtd; i++) {

                        cin.ignore();
                        cout << "\n" << "* Digite a marca: ";
                        getline(cin, marca);
                        cout << "* Digite o nome: ";
                        getline(cin, nome);

                      // Aqui verifica-se se o telefone que o usuário deseja inserir já existe no estoque, em caso verdadeiro, o usuário apenas é possibilitado a incrementar uma quantidade do telefone , em vez de cadastrar um novo telefone.
                      if (pesquisaTel(nome) != -1) {
                        posicaoadicionar = pesquisaTel(nome);
                        cout << posicaoadicionar << endl;
                        cout << "\n* Um produto com esse nome já está cadastrado em nossa loja!\n" << "* Você deseja adicionar uma quantidade deste produto? \n" << endl;
                        cout << "* 1. Sim           *" << endl;
                        cout << "* 2. Não           *" << endl;
                        cout << "\n";
                        cout << "* Escolha uma opção: ";
                        cin >> opcaoadicionar;
                        if (opcaoadicionar == 1){
                          cout << "* Digite aqui a quantidade: ";
                          cin >> quantmais;

                          string quantidadeAtualStr = telefones[posicaoadicionar]->getQuantidade();
                          int quantidadeAtual = stoi(quantidadeAtualStr);

                          telefones[posicaoadicionar]->setQuantidade(std::to_string(quantidadeAtual + quantmais));

                          cout << "* Quantidade do produto atualizada para: " << telefones[posicaoadicionar]->getQuantidade() << "\n\n";

                        }
                        // Em caso falso, ou seja o telefone que está tentando ser cadastrado não existe no estoque o usuario termina de fazer o cadastro.
                      } else {
                        cout << "* Digite o tamanho da tela em polegadas (apenas o numero): ";
                        getline(cin, tamTela);
                        cout << "* Digite a Conectividade (4G, 5G ou 6G): ";
                        getline(cin, conectividade);
                        cout << "* Digite o Processador: ";
                        getline(cin, processador);
                        cout << "* Possui Digital? (sim ou nao) ";
                        getline(cin, digital);
                        cout << "* Digite a versao do android (apenas o numero): ";
                        getline(cin, versaoAnd);
                        tipo = "Android";

                        cout << "* Digite a capacidade da bateria em mAh (apenas o numero): ";
                        getline(cin, bateria);;
                        cout << "* Digite a memoria RAM em gigabytes (apenas o numero): ";
                        getline(cin, mram);
                        cout << "* Digite a qualidade da camera frontal em megapixels (apenas o numero): ";
                        getline(cin, camFrontal);
                        cout << "* Digite a qualidade da camera traseira em megapixels (apenas o numero): ";
                        getline(cin, camTraseira);
                        cout << "* Digite a memoria interna em gigabytes (apenas o numero): ";
                        getline(cin, memoria);
                        cout << "* Digite o preço em reais (apenas o numero): ";
                        getline(cin, preco);
                        cout << "* Digite a quantidade de produtos que você deseja inserir: ";
                        getline(cin, quant);
                        cout << "\n";

                      // Aqui adicionamos ao vetor cada especificação do celular.
                      telefones.push_back(new Android(tipo, marca, nome, preco, tamTela, bateria, mram, camFrontal, camTraseira, conectividade, processador, memoria,quant, digital, versaoAnd));
                        contador++;

                        cout << "* Telefone #" << contador << " adicionado!";
                        cout << "\n" << "\n";
                      }
                    }
                }

                  // Escolhendo essa opção temos a escolha de inserir um iO's. A lógica utilizada é a mesma que a anterior.
                else if (opcao2 == 2) {

                    cout << "***********************************" << endl;
                    cout << "*          Inserir iOS's          *" << endl;
                    cout << "***********************************" << endl;
                    cout << "* Quantos iOS's deseja inserir?   *" << endl;
                    cout << "***********************************" << endl;
                    cout << "\n";
                    cout << "* Digite aqui a quantidade: ";
                    cin >> qtd;
                    cout << "\n";

                    for (int i = 0; i < qtd; i++) {

                        cin.ignore();
                        cout << "\n" << "* Digite a marca: ";
                        getline(cin, marca);
                        cout << "* Digite o nome: ";
                        getline(cin, nome);

                      if (pesquisaTel(nome) != -1) {
                        posicaoadicionar = pesquisaTel(nome);
                        cout << posicaoadicionar << endl;
                        cout << "\n* Um produto com esse nome já está cadastrado em nossa loja!\n" << "* Você deseja adicionar uma quantidade deste produto? \n" << endl;
                        cout << "* 1. Sim           *" << endl;
                        cout << "* 2. Não           *" << endl;
                        cout << "\n";
                        cout << "* Escolha uma opção: ";
                        cin >> opcaoadicionar;
                        if (opcaoadicionar == 1){
                          cout << "* Digite aqui a quantidade: ";
                          cin >> quantmais;

                          string quantidadeAtualStr = telefones[posicaoadicionar]->getQuantidade();
                          int quantidadeAtual = stoi(quantidadeAtualStr);
                      
                          telefones[posicaoadicionar]->setQuantidade(std::to_string(quantidadeAtual + quantmais));

                          cout << "* Quantidade do produto atualizada para: " << telefones[posicaoadicionar]->getQuantidade() << "\n\n";

                        } 

                      } else {
                        cout << "* Digite o tamanho da tela em polegadas (apenas o numero): ";
                        getline(cin, tamTela);
                        cout << "* Digite a Conectividade (4G, 5G ou 6G): ";
                        getline(cin, conectividade);
                        cout << "* Digite o Processador: ";
                        getline(cin, processador);
                        cout << "* Possui Digital? (sim ou nao) ";
                        getline(cin, digital);
                        cout << "* Digite a versao do iOS (apenas o numero): ";
                        getline(cin, versaoIos);
                        cout << "* Possui FaceID? (sim ou nao) ";
                        getline(cin, faceID);
                        tipo = "iOS";

                        cout << "* Digite a capacidade da bateria em mAh (apenas o numero): ";
                        getline(cin, bateria);;
                        cout << "* Digite a memoria RAM em gigabytes (apenas o numero): ";
                        getline(cin, mram);
                        cout << "* Digite a qualidade da camera frontal em megapixels (apenas o numero): ";
                        getline(cin, camFrontal);
                        cout << "* Digite a qualidade da camera traseira em megapixels (apenas o numero): ";
                        getline(cin, camTraseira);
                        cout << "* Digite a memoria interna em gigabytes (apenas o numero): ";
                        getline(cin, memoria);
                        cout << "* Digite o preço em reais (apenas o numero): ";
                        getline(cin, preco);
                        cout << "* Digite a quantidade de produtos que você deseja inserir: ";
                        getline(cin, quant);
                        cout << "\n";

                          telefones.push_back(new Ios(tipo, marca, nome, preco, tamTela, bateria, mram, camFrontal, camTraseira, conectividade, processador, memoria,quant, faceID, digital, versaoIos));
                        contador++;

                        cout << "* Telefone #" << contador << " adicionado!";
                        cout << "\n" << "\n";
                      }
                    }
                }
                break;

          
            // Com o usuário escolhendo essa opção, todos os celulares, que estão no estoque, são exibidos na tela.
            case 2:
              cout << "***********************************" << endl;
              cout << "*             Telefones           *" << endl;
              cout << "***********************************" << endl;
              cout << "\n";

              if (contador > 0) {
                for (int i = 0; i < contador; i++) {
                  telefones[i]->imprimirInfo();
                  cout << "\n";
                }
              }
              else {
                cout << "Sem telefones cadastrados." << endl;
                cout << "\n";
              }

              break;

            // Ao escolher esta opção, o usuário pode pesquisar e verificar se um determinado celular está disponível no estoque, se for encontrado, todas as características desse celular são exibidas na tela.
            case 3:
              cout << "************************************************" << endl;
              cout << "*            Pesquisa de Telefone              *" << endl;
              cout << "************************************************" << endl;
              cout << "* Digite o nome do Telefone a ser pesquisado: ?*" << endl;
              cout << "************************************************" << endl;
              cout << "\n";
              cout << "Digite aqui o nome: ";
              cin.ignore();
              getline(cin, nome);
              cout << "\n";
              if (pesquisaTel(nome) != -1) {
                posicao = pesquisaTel(nome);
                telefones[posicao]->imprimirInfo();
              }
              else {
                cout << "Telefone nao encontrado!" << endl;
                cout << "\n";
              }
              break;

          // Esta opção permite ao usuário fazer alterações nas especificações dos produtos.
            case 4:

              cout << "************************************************" << endl;
              cout << "*              Alterar Produto                 *" << endl;
              cout << "************************************************" << endl;
              cout << "\n";
              cout << "Digite o nome do Telefone a ser Alterado: ";
              cin.ignore();
              getline(cin, nome);
              cout << "\n";

              // Essa condição aqui serve para verificar se o telefone que vai ser alterado realmente existe no sistema, sendo essa condiçaõ verdadeira
              if (pesquisaTel(nome) != -1) {
                posicao = pesquisaTel(nome);
                telefones[posicao]->imprimirInfo();
                
                // Neste caso, verificamos o tipo de celular que o usuário deseja alterar, pois os celulares Android e iOS têm especificações diferentes.
                if (telefones[posicao]->getTipo() == "Android") {
                   Android *andTemp = (Android*)telefones[posicao];

                  cout << "************************************************" << endl;
                  cout << "*              O que você quer alterar?        *" << endl;
                  cout << "************************************************" << endl;
                  cout << "* 1. Nome                                      *" << endl;
                  cout << "* 2. Tamanho da tela                           *" << endl;
                  cout << "* 3. Conectividade                             *" << endl;
                  cout << "* 4. Processador                               *" << endl;
                  cout << "* 5. Digital                                   *" << endl;
                  cout << "* 6. Versão do Android                         *" << endl;
                  cout << "* 7. Bateria                                   *" << endl;
                  cout << "* 8. Memória RAM                               *" << endl;
                  cout << "* 9. Câmera Frontal                            *" << endl;
                  cout << "* 10. Câmera Traseira                          *" << endl;
                  cout << "* 11. Memória interna                          *" << endl;
                  cout << "* 12. Preço                                    *" << endl;
                  cout << "************************************************" << endl;
                  cout << "* Digite a opção desejada:                     *" << endl;
                  cout << "************************************************" << endl;
                  cout << "\n";
                  cout << "Escolha uma opção: ";
                  cin >> opcao2;
                  cout << "\n";

                  // Aqui verificamos a opção escolhida pelo usuário e, com base nela, uma especificação diferente do celular será modificada usando o método "set" e apontando para a posição específica do telefone no vetor.
                  if (opcao2 == 1) {
                    cout << "* Digite o novo nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "\n";
                    telefones[posicao]->setNomeTel(nome);
                    cout << "* Nome alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 2) {
                    cout << "* Digite o novo tamanho da tela: ";
                    cin.ignore();
                    getline(cin, tamTela);
                    cout << "\n";
                    telefones[posicao]->setTamTela(tamTela);
                    cout << "* Tamanho da tela alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 3) {
                    cout << "* Digite a nova conectividade: ";
                    cin.ignore();
                    getline(cin, conectividade);
                    cout << "\n";
                    telefones[posicao]->setConectividade(conectividade);
                    cout << "* Conectividade alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 4) {
                    cout << "* Digite o novo Processador: ";
                    cin.ignore();
                    getline(cin, processador);
                    cout << "\n";
                    telefones[posicao]->setProcessador(processador);
                    cout << "* Processador alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 5) {
                    cout << "* Digite se tem digital ou nao: ";
                    cin.ignore();
                    getline(cin, digital);
                    cout << "\n";
                    andTemp->setDigital(digital);
                    cout << "* Digital alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 6) {
                    cout << "* Digite a nova versao do android: ";
                    cin.ignore();
                    getline(cin, versaoAnd);
                    cout << "\n";
                    andTemp->setVersaoAnd(versaoAnd);
                    cout << "* Versao do android alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 7) {
                    cout << "* Digite a nova capacidade da bateria: ";
                    cin.ignore();
                    getline(cin, bateria);
                    cout << "\n";
                    telefones[posicao]->setBateria(bateria);
                    cout << "* Bateria alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 8) {
                    cout << "* Digite a nova memoria RAM: ";
                    cin.ignore();
                    getline(cin, mram);
                    cout << "\n";
                    telefones[posicao]->setMRam(mram);
                    cout << "* Memoria RAM alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 9) {
                    cout << "* Digite a nova qualidade da camera frontal: ";
                    cin.ignore();
                    getline(cin, camFrontal);
                    cout << "\n";
                    telefones[posicao]->setCamFrontal(camFrontal);
                    cout << "* Camera frontal alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 10) {
                    cout << "* Digite a nova qualidade da camera traseira: ";
                    cin.ignore();
                    getline(cin, camTraseira);
                    cout << "\n";
                    telefones[posicao]->setCamTraseira(camTraseira);
                    cout << "* Camera traseira alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 11) {
                    cout << "* Digite a nova memoria interna: ";
                    cin.ignore();
                    getline(cin, memoria);
                    cout << "\n";
                    telefones[posicao]->setMemoria(memoria);
                    cout << "* Memoria interna alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 12) {
                    cout << "* Digite o novo preço: ";
                    cin.ignore();
                    getline(cin, preco);
                    cout << "\n";
                    telefones[posicao]->setPreco(preco);
                    cout << "* Preço alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                }

                  // Esta condição verifica se o usuário escolheu modificar um telefone do tipo iOS. Apesar de haver especificações diferentes em comparação com o Android, a lógica do programa é a mesma utilizada anteriormente e já explicada.
                else if(telefones[posicao]->getTipo() == "iOS") {
                  Ios *iosTemp = (Ios*)telefones[posicao];

                  cout << "************************************************" << endl;
                  cout << "*              O que você quer alterar?        *" << endl;
                  cout << "************************************************" << endl;
                  cout << "* 1. Nome                                      *" << endl;
                  cout << "* 2. Tamanho da tela                           *" << endl;
                  cout << "* 3. Conectividade                             *" << endl;
                  cout << "* 4. Processador                               *" << endl;
                  cout << "* 5. Digital                                   *" << endl;
                  cout << "* 6. Versão do iOS                             *" << endl;
                  cout << "* 7. FaceID                                    *" << endl;
                  cout << "* 8. Bateria                                   *" << endl;
                  cout << "* 9. Memória RAM                               *" << endl;
                  cout << "* 10. Câmera Frontal                           *" << endl;
                  cout << "* 11. Câmera Traseira                          *" << endl;
                  cout << "* 12. Memória interna                          *" << endl;
                  cout << "* 13. Preço                                    *" << endl;
                  cout << "************************************************" << endl;
                  cout << "* Digite a opção desejada:                     *" << endl;
                  cout << "************************************************" << endl;
                  cout << "\n";
                  cout << "Escolha uma opção: ";
                  cin >> opcao2;
                  cout << "\n";

                  if (opcao2 == 1) {
                    cout << "* Digite o novo nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "\n";
                    telefones[posicao]->setNomeTel(nome);
                    cout << "* Nome alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 2) {
                    cout << "* Digite o novo tamanho da tela: ";
                    cin.ignore();
                    getline(cin, tamTela);
                    cout << "\n";
                    telefones[posicao]->setTamTela(tamTela);
                    cout << "* Tamanho da tela alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 3) {
                    cout << "* Digite a nova conectividade: ";
                    cin.ignore();
                    getline(cin, conectividade);
                    cout << "\n";
                    telefones[posicao]->setConectividade(conectividade);
                    cout << "* Conectividade alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 4) {
                    cout << "* Digite o novo Processador: ";
                    cin.ignore();
                    getline(cin, processador);
                    cout << "\n";
                    telefones[posicao]->setProcessador(processador);
                    cout << "* Processador alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 5) {
                    cout << "* Digite se tem digital ou nao: ";
                    cin.ignore();
                    getline(cin, digital);
                    cout << "\n";
                    iosTemp->setDigital(digital);
                    cout << "* Digital alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 6) {
                    cout << "* Digite a nova versao do iOS: ";
                    cin.ignore();
                    getline(cin, versaoIos);
                    cout << "\n";
                    iosTemp->setVersaoIos(versaoIos);
                    cout << "* Versao do iOS alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 7) {
                    cout << "* Digite se possui FaceID ou nao: ";
                    cin.ignore();
                    getline(cin, faceID);
                    cout << "\n";
                    iosTemp->setFaceID(faceID);
                    cout << "* FaceID alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 8) {
                    cout << "* Digite a nova capacidade da bateria: ";
                    cin.ignore();
                    getline(cin, bateria);
                    cout << "\n";
                    telefones[posicao]->setBateria(bateria);
                    cout << "* Bateria alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 9) {
                    cout << "* Digite a nova memoria RAM: ";
                    cin.ignore();
                    getline(cin, mram);
                    cout << "\n";
                    telefones[posicao]->setMRam(mram);
                    cout << "* Memoria RAM alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 10) {
                    cout << "* Digite a nova qualidade da camera frontal: ";
                    cin.ignore();
                    getline(cin, camFrontal);
                    cout << "\n";
                    telefones[posicao]->setCamFrontal(camFrontal);
                    cout << "* Camera frontal alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 11) {
                    cout << "* Digite a nova qualidade da camera traseira: ";
                    cin.ignore();
                    getline(cin, camTraseira);
                    cout << "\n";
                    telefones[posicao]->setCamTraseira(camTraseira);
                    cout << "* Camera traseira alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 12) {
                    cout << "* Digite a nova memoria interna: ";
                    cin.ignore();
                    getline(cin, memoria);
                    cout << "\n";
                    telefones[posicao]->setMemoria(memoria);
                    cout << "* Memoria interna alterada com sucesso!" << endl;
                    cout << "\n";
                  }
                  if (opcao2 == 13) {
                    cout << "* Digite o novo preço: ";
                    cin.ignore();
                    getline(cin, preco);
                    cout << "\n";
                    telefones[posicao]->setPreco(preco);
                    cout << "* Preço alterado com sucesso!" << endl;
                    cout << "\n";
                  }
                }
              }

              else {
                cout << "* Telefone não encontrado!" << endl;
                cout << "\n";
              }
              break;

           // Esta opção permite ao usuário fazer um pedido para um cliente, ou seja seria a opção remover.
            case 5:{

               int resp, quant;

                cout << "***********************************" << endl;
                cout << "*          Menu de Pedido         *" << endl;
                cout << "***********************************" << endl;
                cout << "* 1. O Cliente já tem login       *" << endl;
                cout << "* 2. Fazer o cadastro do Cliente  *" << endl;
                cout << "***********************************" << endl;
                cout << "\n";
                cout << "* Escolha uma opção: ";

                cin >> resp;

                // A condição abaixo ele vai depender se o cliente vai possuir login, ou não e vai ter que fazer um cadastro.
                if(resp ==  1) {

                  string nomeProcurado, loginProcurado, posicaoProcurado;
                  cout << "\n* Digite o nome do Cliente: ";
                  cin.ignore();
                  getline(cin, nomeProcurado);
                  cout << "\n";
                  cout << "* Digite a Senha: ";
                  getline(cin,loginProcurado);

                  // Essa outra condição verifica se o foi feito da forma correta pelo usuário, se essa condição for tida como verdadeira, o programa executa por meio de um "for" uma lista com todos os telefones disponíveis. A partir disso o usuário escolhe um telefone, existe uma verificação se esse telefone escolhido existe no estoque, se existir o usuário é conduzido a escolher a quantidade do produto que o cliente deseja, assim subtraímos essa quantidade do estoque e o pedido é concretizado.
                  if (pesquisaCliente(nomeProcurado, loginProcurado) != -1){
                    posicaoProcurado = pesquisaCliente(nomeProcurado, loginProcurado);
                    
                    cout << "\n* Login feito com sucesso\n " << endl;
                    for (int i = 0; i < contador; i++) {
                      telefones[i]->imprimirInfo();
                      cout << "\n\n";
                    }
                      string nomePedido;
                      int newQuant = 0;
                      cout << "* Qual celular o cliente deseja: ";
                      getline(cin, nomePedido);
                      if(pesquisaTel(nomePedido) != -1){
      cout << "* Digite a aqui a quantidade desse produto que o cliente deseja: ";
        cin >> quant;
                      if(quant <= stoi(telefones[pesquisaTel(nomePedido)]->getQuantidade())) {
                        int quantInt = stoi(telefones[pesquisaTel(nomePedido)]->getQuantidade());
                        newQuant = quantInt - quant;
                        

                        telefones[pesquisaTel(nomePedido)]->setQuantidade(to_string(newQuant));

                        // Aqui abrimos o arquivo "vendas.txt" em modo de escrita, adicionando itens na primeira linha vazia, se existir.
                        fstream arquivoVendas;
                        arquivoVendas.open("vendas.txt", ios::out | ios::app);

                        // Aqui escrevemos no arquivo
                        arquivoVendas << "#" << to_string(quant) << " " << nomePedido << " foi vendido para: " << nomeProcurado  << " de Login:" << loginProcurado <<" ." << endl;
                        arquivoVendas << "***********************************************************************" << endl;

                        cout << "* Pedido feito com sucesso\n " << endl;
                        arquivoVendas.close();
                      } else {
                        cout << "* Estoque insuficiente\n " << endl;
                      }
                        
                      } else{
                        cout << "*\n Aparelho não encontrado no estoque: " << endl;
                      }
                  } else {
                    cout << "\n* A tentativa de login não ocorreu da forma correta!" << endl;
                    break;
                  }

                  
                  

                // Essa condição é dada caso o cliente não possua um login e deverá fazer um cadastro. Colocamos uma verificação ainda, se o cliente que etá sendo cadastrado, já possui ou não um login, caso não exista colocamos todas as informações do usuário dentro do vetor clientes. Além disso, a lógica para fazer o pedido é a mesma do item anterior.
                } else if(resp == 2) {

                      string name, CPF, nasc, login, numCel, end, email;
                      cout << "\n* Digite aqui o nome do Cliente: ";
                      cin.ignore();
                      getline(cin, name);
                      cout << "\n";
                      cout << "* Digite a Senha: ";
                      getline(cin, login);
                      

                  
                      if (pesquisaCliente(name,login) != -1 ){
                        cout << "\n* Essas informações já pertencem a uma conta cadastrada!" << endl;
                        while (pesquisaCliente(name, login) != -1 ){
                          int opcaoescolha = 0;
                          cout << "\n* Você deseja tentar fazer novamente o cadastro?";
                          cout << "\n* 1. Sim           *" << endl;
                          cout << "* 2. Não           *" << endl;
                          cout << "\n";
                          cout << "* Escolha uma opção: ";
                          cin >> opcaoescolha;
                          if (opcaoescolha == 1){
                            cout << "\n* Digite aqui o nome do Cliente: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "\n";
                            cout << "* Digite a Senha: ";
                            getline(cin, login);
                            if (pesquisaCliente(name,login) != -1 ){
                              cout << "\n* Essas informações já pertencem a uma conta cadastrada!" << endl;
                              cout <<"\n* Como de forma seguida você tentou cadastrar dois usuários que já estavam no nosso sistema, então o programa vai voltar para o menu por motivos de segurança!\n";
                              break;
                            }
                            
                          } 
                          
                        }
                      } 
                  
                      cout << "\n";
                      cout << "* Digite o CPF: ";
                      getline(cin, CPF);
                      cout << "\n";
                      cout << "* Digite a data de nascimento: ";                
                      getline(cin, nasc);
                      cout << "\n";
                      cout << "* Digite o número de celular: ";
                      getline(cin, numCel);
                      cout << "\n";
                      cout << "* Digite o endereço: ";
                      getline(cin, end);
                      cout << "\n";
                      cout << "* Digite o email: ";
                      getline(cin, email);
                      cout << "\n";

                    pessoas.push_back(new Cliente(name, CPF, nasc, login, numCel, end, email));
                    cout << "* Cliente cadastrado com sucesso!\n" << endl;
                  cont2++;
                  

                  for (int i = 0; i < contador; i++) {
                    telefones[i]->imprimirInfo();
                    cout << "\n\n";
                  }
                    string nomePedido;
                    int newQuant = 0;
                    cout << "* Qual celular o cliente deseja: ";
                    getline(cin, nomePedido);
                    if(pesquisaTel(nomePedido) != -1){
                  cout << "* Digite a aqui a quantidade desse produto que o cliente deseja: ";
                  cin >> quant;
                    if(quant <= stoi(telefones[pesquisaTel(nomePedido)]->getQuantidade())) {
                      int quantInt = stoi(telefones[pesquisaTel(nomePedido)]->getQuantidade());
                      newQuant = quantInt - quant;


                      telefones[pesquisaTel(nomePedido)]->setQuantidade(to_string(newQuant));

                      // Como no item anterior aqui abrimos o arquivo "vendas.txt" como um arquivo de escrita e com a característica de adicionar os itens na primeira linha vazia.
                      fstream arquivoVendas;
                      arquivoVendas.open("vendas.txt", ios::out | ios::app);

                      // Escrevemos no arquivo.
                      arquivoVendas << "#" << to_string(quant) << " " << nomePedido << " foi vendido para: " << name << " de Login:" << login <<" ." << endl;
                      arquivoVendas << "***********************************************************************" << endl;
      
                      cout << "* Pedido feito com sucesso\n " << endl;
                      arquivoVendas.close();
                    } else {
                      cout << "* Estoque insuficiente\n " << endl;
                      break;
                    }

                    } else{
                      cout << "*\n Aparelho não encontrado no estoque: " << endl;
                    }
                }

                break;
            }

            // Essa opção escolhida pelo usuário fornece um relatório dos produtos vendidos.
            case 6:{     
              
                cout << "***********************************" << endl;
                cout << "*             Relatorio           *" << endl;
                cout << "***********************************" << endl;
                cout << "\n";

                // Aqui abrimos o arquivo "vendas.txt" como um arquivo de leitura.
                fstream arquivoRelatorio;
                arquivoRelatorio.open("vendas.txt", ios::in | ios::app);

                string line;

                // Aqui imprimos ao usuário cada linha do arquivo.
                while(getline(arquivoRelatorio, line)) {
                  cout << line << endl;
                }
                arquivoRelatorio.close();
              cout << endl << endl;
                
              
                break;
            }
            // Por fim essa, ao usuário escolher essa opção o programado é encerrado, mas antes ele salva tudo nos arquivos.
            case 7:
                cout << "* Saindo..." << endl;

              // Abrimos por meio da função "ofstream" o arquivo como de leitura, e por meio da função "trunc" apagamos tudo que está no arquivo e colocamos tudo que está no vetor. Fazemos isso, pois o arquivo possui todas as informações, então temos que apagar tudo que está no arquivo e escrever por cima, haja vista que se apenas adicionássemos informações haveriam informações repetidas.
                ofstream arquivoTelefones("telefones.txt", ios::trunc);
                if (!arquivoTelefones) {
                    cerr << "Erro ao abrir o arquivo de saída." << endl;
                    return;
                }

              // Aqui usamos as funções "get" para retornar os valores e escrevê-los no arquivo.
                for (int i = 0; i < contador; i++) {
                  if (stoi(telefones[i]->getQuantidade()) > 0){
                    arquivoTelefones << telefones[i]->getTipo() << endl;
                    arquivoTelefones << telefones[i]->getMarca() << endl;
                    arquivoTelefones << telefones[i]->getNomeTel() << endl;
                    arquivoTelefones << telefones[i]->getPreco() << endl;
                    arquivoTelefones << telefones[i]->getTamTela() << endl;
                    arquivoTelefones << telefones[i]->getBateria() << endl;
                    arquivoTelefones << telefones[i]->getMRam() << endl;
                    arquivoTelefones << telefones[i]->getCamFrontal() << endl;
                    arquivoTelefones << telefones[i]->getCamTraseira() << endl;
                    arquivoTelefones << telefones[i]->getConectividade() << endl;
                    arquivoTelefones << telefones[i]->getProcessador() << endl;
                    arquivoTelefones << telefones[i]->getMemoria() << endl;
                    arquivoTelefones << telefones[i]->getQuantidade() << endl;

                    // Como usamos o polimorfismo devemos criar esses ponteiros para cada tipo diferente e somente após isso colocar as informações no arquivo. Essas condições são colocadas para verificar o tipo do telefone para colocar no arquivo as especificações corretas de cada tipo.
                    if (telefones[i]->getTipo() == "Android") {
                        Android *andTemp = dynamic_cast<Android *>(telefones[i]);
                        arquivoTelefones << andTemp->getDigital() << endl;
                        arquivoTelefones << andTemp->getVersaoAnd() << endl;
                    } else if (telefones[i]->getTipo() == "iOS") {
                        Ios *iosTemp = dynamic_cast<Ios *>(telefones[i]);
                        arquivoTelefones << iosTemp->getFaceID() << endl;
                        arquivoTelefones << iosTemp->getDigital() << endl;
                        arquivoTelefones << iosTemp->getVersaoIos() << endl;
                    }

                    arquivoTelefones << "/\n";
                }
                }
                arquivoTelefones.close();

                if(cont2!=0){


                // A lógica utilizada nesse arquivo é a mesma que utilizamos no caso anterior.
                ofstream arquivoClientes("clientes.txt", ios::trunc);

                if (!arquivoClientes) {
                    cerr << "Erro ao abrir o arquivo de clientes." << endl;
                    return;
                } else {}


                for (int i = 0; i < cont2 ; i++) {
                    arquivoClientes << pessoas[i]->getNome() << endl;
                    arquivoClientes << pessoas[i]->getCpf() << endl;
                    arquivoClientes << pessoas[i]->getNascimento() << endl;

                    Cliente *clienteTemp = dynamic_cast<Cliente *>(pessoas[i]);
                    arquivoClientes << clienteTemp->getLogin() << endl;
                    arquivoClientes << clienteTemp->getNumCelular() << endl;
                    arquivoClientes << clienteTemp->getEndereco() << endl;
                    arquivoClientes << clienteTemp->getEmail() << endl;
                    arquivoClientes << "|" << "\n";                
                }

              arquivoClientes.close();
                }

                  break;
            }  
        }
              // Utilizamos esse loop para liberar a memória alocada dinamicamente pelos objetos telefone.
              for (auto& telefone : telefones) {
                  delete telefone;
              }
  telefones.clear();
}