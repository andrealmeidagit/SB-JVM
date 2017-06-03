# SB-JVM
Repositório para a JVM

**Requisitos do programa:**

Os alunos deverão implementar em C99, um “leitor de arquivo ponto class e exibidor de bytecode Java” e uma máquina virtual (JVM) para executar programas Java no formato ponto class.

**JVM com opção de leitor/exibidor**
Desenvolvida e defendida em grupo de até 5 membros. Não será apresentada
especificação por escrito. O programa será executado para avaliação da corretude no sistema operacional Windows e com bytecode gerado pelo Javac e da qualidade da documentação apresentada.

**Critérios de correção do leitor/exibidor e da JVM**
Compilação com o GCC com opções –std=c99 e execução para análise da sua corretude. Serão elaborados pequenos programas Java que serão compilados com o Javac.

**ATRIBUIÇÃO DA NOTA**
- Leitor de ponto class e exibidor de bytecode - 1 (100) - 
Exibição das estruturas internas montadas após a leitura de um arquivo ponto class (70%) e os mnemônicos em assembly associado aos bytecodes Java (30).
- Corretude da máquina virtual (100)
- Leitor de ponto class e exibidor de bytecode - 2 (20)
- Instruções: instruções com categorias 1 e 2, arrays (uni e multidimensionais), strings, métodos estáticos e dinâmicos
e atributos de classe ou de instância, herança, polimorfismo, reescrita, objetos, simulação de impressão (80). Não incluem debug, chamadas às API do Java ou S.O. checagem dinâmica de tipos ou coletor de lixo.
- Defesa individual (100) - 
Cada membro do grupo será argüido e avaliado em separado sobre a teoria da JVM, formato ponto class e a implementação propriamente dita. A resposta deve indicar funções e estruturas de dados no código elaborado.
- Documentação / site (100) - 
Páginas web descrevendo cada função implementada na JVM abrangendo um diagrama de ativação (diagrama de
comunicação entre os módulos) e a descrição das principais estruturas de dados utilizadas. Para CADA FUNÇÃO deverá ser elaborada um frame contendo: nome da função, objetivo, parâmetros de entrada, parâmetros de saída, descrição do algoritmo que implementa, e links para a função chamadora e para as funções chamadas.
- Atribuição de nota para a JVM:0,1*leitor-exibidor + 0,4*corretude + 0,4*defesa individual+ 0,1*site

**DEADLINE: 26/06**



**Bibliografia**

- https://docs.oracle.com/javase/specs/jvms/se7/jvms7.pdf - livro
- https://en.wikipedia.org/wiki/List_of_Java_virtual_machines - lista de JVMs open source
- https://www.youtube.com/watch?v=rPyqB1l4gko - video sobre bytecode
- https://www.youtube.com/watch?v=DXykPdFt1KY - video sobre bytecode

- https://www.codeproject.com/Articles/24029/Home-Made-Java-Virtual-Machine (TEM VÍRUS NO SITE!! CUIDADO!!)
- https://1drv.ms/f/s!Aqn_fz2oxhxZg5gIOFuokeRlEomRMw (MATERIAL DO SITE ACIMA - SEM VÍRUS!!)
- https://github.com/MykolaBova/java.jvm.CodeProject (github do projeto acima)
