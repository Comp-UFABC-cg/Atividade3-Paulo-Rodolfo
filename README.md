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
 - Câmera: 
    - Implementada em câmera.cpp e câmera.hpp calcula a matriz de visão (é uma mudança de frame: do espaço do mundo para o espaço da câmera). A matriz de visão é a inversa da matriz M (que converte as coordenadas do espaço da câmera para o espaço do mundo). Ou seja, Mview = M^-1. A sua fórmula é a inversa pois a finalidade é justamente o oposto (queremos converter as coordenadas do espaço do mundo para o espaço da câmera). Isto é implementado através da função glm::lookAt (importada da biblioteca GLM), o cálculo, portanto, é realizado conforme abaixo: <br>
    ![image](https://user-images.githubusercontent.com/30665585/145130652-9f043382-13ef-4c68-9897-b1727c2fc180.png) <br>
    - Os parâmetros m_eye, m_at e m_up equivalem, respectivamente a posição da câmera, posição para onde a câmera está olhando e direção para cima da câmera. As posições iniciais são descritas abaixo:
     - m_eye: (0,0,2,5)
     - m_at: (0,0,0)
     - m_up: (0,1,0)
    - As funções dolly, truck, pan são utilizadas dentro do OpenGLWindow para capturar e refletir (através da atualização das variáveis m_eye e m_up) a movimentação da entrada do teclado.
 
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

