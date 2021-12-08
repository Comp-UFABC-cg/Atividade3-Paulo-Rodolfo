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
  - A movimentação pelo cenário ocorre utilizando as teclas: W (anda para frente), S (anda para trás), A (anda para esquerda), S (anda para a direita). O evento dessas teclas é capturado através dos comandos <b>SDLK_w</b>, <b>SDLK_s</b>,<b>SDLK_a</b>,<b>SDLK_d</b>. A movimentação em torno do próprio eixo Y é capturado através do <b>SDLK_LEFT </b> e <b>SDLK_RIGHT.</b>Adicionalmente, é possível correr pelo cenário através da tecla espaço, capturado através do comando <b>SDLK_SPACE</b>.
   - Os eventos de <b>SDLK_w</b> e <b>SDLK_s</b> refletem em movimentar a câmera para frente e para a trás (chamada de movimentação dolly) na direção ± ^n. Sendo, +1.0f para a frente e -1.0f para a trás. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_dollySpeed</b>.
   - Os eventos de <b>SDLK_a</b> e <b>SDLK_d</b> refletem em movimentar a câmera para os lados (chamada de movimentação truck) (esquerda e direita, respectivamente) na direção ±û. Sendo, -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_truckSpeed</b>.
  - Os eventos de <b>SDLK_LEFT</b> e <b>SDLK_RIGHT</b> refletem em movimentar a câmera em torno do próprio eixo y (chamada de movimentação Pan), realizada no vetor ^v (sem movimentar pelo cenário). Sendo atribuídos -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação neste vetor: <b>m_panSpeed</b>.
  - O evento de <b>SDLK_SPACE</b> reflete em correr para frente ao pressionar W + Espaço. Para isto, é atribuído 4.0f ao <b>m_dollySpeed</b>.


![image](https://user-images.githubusercontent.com/30665585/144721323-a6f9a77e-21f8-4e9d-baa4-27dd440e8277.png)
<br>Fonte imagem: https://www.brunodorta.com.br/cg/lookatproject.html
  
  - Para a implementação da movimentação da câmera é necessário utilizar os espaços do OpenGL: Espaço do objeto, espaço do mundo e espaço da câmera.
    - Espaço do objeto: É o local da definição do obj importado na aplicação. Segue o RHS (right-handed coordinate system - em português: Regra da mão direita). O objeto é renderizado no centro da tela. A renderização é realizada pela função OpenGLWindow::loadModel. O modelo padrão (default), carregado assim que a aplicação é executada é a casa medieval (medieval.obj) com a textura difusa (através da chamada a função loadDiffuseTexture).
    - Espaço do mundo: É o frame no qual renderizamos o objeto. Em nossa aplicação podemos renderizar um objeto por vez dentro do frame (mundo). O espaço do mundo também segue a orientação RHS.
    - Espaço da câmera: É o frame da câmera da aplicação (que simula o ponto de vista em primeira pessoa e possibilita a navegação pelo mundo).

TO-DO:
- LOOKAT
- ILUMINAÇÃO
- TEXTURA

<br>__Funcionalidades:__
- Tecla A: Movimenta para a esquerda
- Tecla D: Movimenta para a direita
- Tecla W: Movimenta para a frente
- Tecla S: Movimenta para a trás
- Seta para direita: Olha para a direita (movimentando em torno do eixo y)
- Seta para esquerda: Olha para a esquerda (movimentando em torno do eixo y)
- Espaço: Corre para frente (W + espaço).




<br>__Implementação:__

