# Relatório - Atividade 3 - Aplicação 3D #

Este repositório contém o código fonte e link da aplicação rodando em <br>
WebAssembly.

A aplicação foi implementada utilizando a seguinte arquitetura: C++, OpenGL e a biblioteca ABCG. <br>

__Membros:__

__Nome:__ Paulo Alexander Simões, <b>RA:</b>11084915 <br>
__Nome:__ Rodolfo Azevedo dos Santos, <b>RA:</b> 11093514

__Link para a aplicação:__   (caso encontre problemas ao abrir, é necessário tentar outras vezes recarregando a página)

<br>__Aplicação:__

<br>__Teoria:__


- O modelo 3D desenvolvido com a biblioteca ABCG utiliza conceitos de álgebra linear para a construção e renderização do objeto.</li>
- A orientação da superfície é determinada utilizando a pipeline do OpenGL.
- Dentro da classe OpenGlWindow::handleEvent implementamos a movimentação pelo cenário através da movimentação da câmera, conforme abaixo:
  - A movimentação pelo cenário ocorre utilizando as teclas: W (anda para frente), S (anda para trás), A (anda para esquerda), S (anda para a direita). O evento dessas teclas é capturado através dos comandos <b>SDLK_w</b>, <b>SDLK_s</b>,<b>SDLK_a</b>,<b>SDLK_d</b>. A movimentação em torno do próprio eixo Y é capturado através do <b>SDLK_LEFT </b> e <b>SDLK_RIGHT.</b>
   - Os eventos de <b>SDLK_w</b> e <b>SDLK_s</b> refletem em movimentar a câmera para frente e para a trás (chamada de movimentação dolly) na direção ± ^n. Sendo, +1.0f para a frente e -1.0f para a trás. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_dollySpeed</b>.
   - Os eventos de <b>SDLK_a</b> e <b>SDLK_d</b> refletem em movimentar a câmera para os lados (chamada de movimentação truck) (esquerda e direita, respectivamente) na direção ±û. Sendo, -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_truckSpeed</b>.
  - Os eventos de <b>SDLK_LEFT</b> e <b>SDLK_RIGHT</b> refletem em movimentar a câmera em torno do próprio eixo y (chamada de movimentação Pan), realizada no vetor ^v (sem movimentar pelo cenário). Sendo atribuídos -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação neste vetor: <b>m_panSpeed</b>.


![image](https://user-images.githubusercontent.com/30665585/144721323-a6f9a77e-21f8-4e9d-baa4-27dd440e8277.png)
<br>Fonte imagem: https://www.brunodorta.com.br/cg/lookatproject.html
  




<br>__Funcionalidades:__




<br>__Implementação:__

