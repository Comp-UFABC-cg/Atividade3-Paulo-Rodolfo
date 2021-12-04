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
  - A movimentação pelo cenário ocorre utilizando as teclas: W (anda para frente), S (anda para trás), A (anda para esquerda), S (anda para a direita). O evento dessas teclas é capturado através do SDLK_w, SDLK_s,SDLK_a,SDLK_d). 
   - Os eventos de SDLK_w e SDLK_s refletem em atribuir uma velocidade positiva ao m_dollyspeed de +1.0f, e -1.0f respectivamente. O dolly é a movimentação de câmera na direção ± ^n. 
   - Os eventos de SDLK_a e SDLK_d refletem em movimentar a câmera para os lados (chamada de movimentação truck) (esquerda e direita, respectivamente) na direção ±û. Sendo, -1.0f para a esquerda e +1.0f para a direita.
  - A movimentação em torno do próprio eixo y (chamada de movimentação Pan), no vetor ^v (sem movimentar pelo cenário) é obtida através das setas do teclado (esquerda e direita). Sendo atribuídos -1.0f (esquerda) e +1.0f (direita) ao m_panSpeed. 
  
![image](https://user-images.githubusercontent.com/30665585/144721323-a6f9a77e-21f8-4e9d-baa4-27dd440e8277.png)
Fonte imagem: https://www.brunodorta.com.br/cg/lookatproject.html
  




<br>__Funcionalidades:__




<br>__Implementação:__

