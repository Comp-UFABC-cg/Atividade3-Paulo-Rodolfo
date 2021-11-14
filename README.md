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

Slider para controle de rotação:
- Permite o controle da velocidade no sentido horário (velocidade positiva) e anti horário (velocidade negativa). A velocidade é medida em radianos.

![image](https://user-images.githubusercontent.com/30665585/141034382-8a2d9000-5aad-4c27-95c6-23c344e81c35.png)

Alterar cor do carro: (TO-DO)

<br>__Implementação:__<br>
Para carregar o Mustang (carro) de nossa aplicação 3D, utilizamos a função "loadModelFromFile". O obj (modelo 3D) foi obtido no site Cgtrader (https://www.cgtrader.com/items/2729539/download-page)

O slider para controle de rotação é implementado a partir do ImGui. O intervalo varia de -500 a +500 radianos (intervalo contínuo, ou seja, tipo float). Ao selecionar uma velocidade positiva o carro rotaciona para a direita (sentido horário), caso contrário, rotaciona para a esquerda (sentido anti-horário).

