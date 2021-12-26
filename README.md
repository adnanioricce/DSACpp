# Estruturas de dados em C++

Algumas estruturas de dados "clássicas" implementadas em C++.

# Para compilar e executar

## Requisitos

- CMake versão 3.20.4 ou maior
- Algum compilador C++(GCC,MSVC ou outro).

## Crie os projetos

vá até a pasta ``scripts`` e execute o script ``configure.bat`` ou ``configure.sh``, se estiver no linux.

Windows:

```bash
cd scripts && ./configure.bat;
```

Linux:

```bash
# lembre-se de fazer o script executavel.
# chmod +x configure.sh
cd scripts && ./configure.sh;
```

## Compile o projeto gerado

isso vai depender do projeto gerado. No windows, por padrão script cria um projeto do visual studio, você pode compilar o mesmo abrindo o arquivo e compilando com ctrl + shift + b.

No Linux, um arquivo ``Makefile`` será gerado, para usa-lo vá até a pasta onde o arquivo se encontra e execute ``make``

```bash
cd out/build/Makefile/;make . ;
```

## Execute o projeto

No caso do windows, os projetos em Visual Studio podem ser executados abrindo o arquivo ``.sln``, e teclando F5.

No linux, execute o binário gerado. 

```bash
# em bin/ , na raiz do projeto
./bin/DataStructures.exe
```

## Executando os testes

os testes podem ser executados no Visual Studio, selecionando o projeto "unit_tests" e executando-o, ou executando o script ``test.bat``

```bash
# na raiz do projeto...
cd scripts && ./test.bat
```



No Linux , o testes podem ser executados com o binário compilado durante execução do Make:

```bash
# em out/build/Makefile/
cd tests && ./DataStructures_unit_tests.exe
# ou...
# na raiz do projeto
cd scripts && ./test.sh
```

