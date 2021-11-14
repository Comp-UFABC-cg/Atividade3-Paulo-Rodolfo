# Relatório - Atividade 2 - Aplicação 3D #

Este repositório contém o código fonte e link da aplicação rodando em <br>
WebAssembly.

A aplicação foi implementada utilizando a seguinte arquitetura: C++, OpenGL e a biblioteca ABCG. <br>

__Membros:__

__Nome:__ Paulo Alexander Simões, <b>RA:</b>11084915 <br>
__Nome:__ Rodolfo Azevedo dos Santos, <b>RA:</b> 11093514

__Link para a aplicação:__ 

<br>__Aplicação:__ Mustang 3D

<br>__Funcionalidades:__

1) Slider para controle de rotação:
- Permite o controle da velocidade no sentido horário (velocidade positiva) e anti horário (velocidade negativa). A velocidade é medida em radianos.

![image](https://user-images.githubusercontent.com/30665585/141701203-1e683108-a29b-4c94-82ca-1dcfffdc1bfb.png)

2) Quantidade de triangulos para renderizar a imagem: <br>
- Permite selecionar a quantidade de triângulos da aplicação 3D.
![image](https://user-images.githubusercontent.com/30665585/141701226-26846580-c62c-4aa2-bd80-13e9c3da758f.png)



<br>__Implementação:__<br>
Para carregar o Mustang (carro) de nossa aplicação 3D, utilizamos a função "loadModelFromFile". O modelo 3d foi obtido no site Cgtrader (https://www.cgtrader.com/items/2729539/download-page).
A edição do arquivo e transformação em obj foi realizada no MeshLab.

O slider para controle de rotação é implementado a partir do ImGui. O intervalo varia de -500 a +500 radianos (intervalo contínuo, ou seja, tipo float). Ao selecionar uma velocidade positiva o carro rotaciona para a direita (sentido horário), caso contrário, rotaciona para a esquerda (sentido anti-horário).

O slider para controle de triangulos também é implementado a partir do ImGui. O intervalo aceita números inteiros.
