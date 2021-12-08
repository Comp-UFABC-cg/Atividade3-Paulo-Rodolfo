# Relatório - Atividade 3 - Aplicação 3D #

Este repositório contém o código fonte e link da aplicação rodando em <br>
WebAssembly.

A aplicação foi implementada utilizando a seguinte arquitetura: C++, OpenGL e a biblioteca ABCG. <br>

__Membros:__

__Nome:__ Paulo Alexander Simões, <b>RA:</b>11084915 <br>
__Nome:__ Rodolfo Azevedo dos Santos, <b>RA:</b> 11093514

__Link para a aplicação:__  https://comp-ufabc-cg.github.io/Atividade3-Paulo-Rodolfo/public/ 
(caso encontre problemas ao abrir, é necessário tentar outras vezes recarregando a página)

<br>__Aplicação:__ Vila Medieval

<br>__Teoria e Implementação:__


- O modelo 3D desenvolvido com a biblioteca ABCG utiliza conceitos de álgebra linear para a construção e renderização do objeto.</li>
- A orientação da superfície é determinada utilizando a pipeline do OpenGL.
- Dentro da classe OpenGlWindow::handleEvent implementamos a movimentação pelo cenário através da movimentação da câmera, conforme abaixo:
  - A movimentação pelo cenário ocorre utilizando as teclas: W (anda para frente), S (anda para trás), A (anda para esquerda), S (anda para a direita). O evento dessas teclas é capturado através dos comandos <b>SDLK_w</b>, <b>SDLK_s</b>,<b>SDLK_a</b>,<b>SDLK_d</b>. A movimentação em torno do próprio eixo Y é capturado através do <b>SDLK_LEFT </b> e <b>SDLK_RIGHT.</b> Adicionalmente, é possível correr pelo cenário através da tecla espaço, capturado através do comando <b>SDLK_SPACE</b>.
   - Os eventos de <b>SDLK_w</b> e <b>SDLK_s</b> refletem em movimentar a câmera para frente e para a trás (chamada de movimentação dolly) na direção ± ^n. Sendo, +1.0f para a frente e -1.0f para a trás. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_dollySpeed</b>.
   - Os eventos de <b>SDLK_a</b> e <b>SDLK_d</b> refletem em movimentar a câmera para os lados (chamada de movimentação truck) (esquerda e direita, respectivamente) na direção ±û. Sendo, -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação nesta direção: <b>m_truckSpeed</b>.
  - Os eventos de <b>SDLK_LEFT</b> e <b>SDLK_RIGHT</b> refletem em movimentar a câmera em torno do próprio eixo y (chamada de movimentação Pan), realizada no vetor ^v (sem movimentar pelo cenário). Sendo atribuídos -1.0f para a esquerda e +1.0f para a direita. Os valores são atribuídos a variável responsável pela movimentação neste vetor: <b>m_panSpeed</b>.
  - O evento de <b>SDLK_SPACE</b> reflete em correr para frente ao pressionar W + Espaço. Para isto, é atribuído 4.0f ao <b>m_dollySpeed</b>.


![image](https://user-images.githubusercontent.com/30665585/144721323-a6f9a77e-21f8-4e9d-baa4-27dd440e8277.png)
<br>Fonte imagem: https://www.brunodorta.com.br/cg/lookatproject.html
  
  - Para a implementação da movimentação da câmera é necessário utilizar os espaços do OpenGL: Espaço do objeto, espaço do mundo e espaço da câmera.
    - Espaço do objeto: É o local da definição do obj importado na aplicação. Segue o <b>RHS (right-handed coordinate system - em português: Regra da mão direita)</b>. O objeto é renderizado no centro da tela. A renderização é realizada pela função <b>OpenGLWindow::loadModel</b>. O modelo padrão (default), carregado assim que a aplicação é executada é a casa medieval (medieval.obj) com a textura difusa (através da chamada a função <b>loadDiffuseTexture</b>).
    - Espaço do mundo: É o frame no qual renderizamos o objeto. Em nossa aplicação podemos renderizar um objeto por vez dentro do frame (mundo). O espaço do mundo também segue a orientação RHS.
    - Espaço da câmera: É o frame da câmera da aplicação (que simula o ponto de vista em primeira pessoa e possibilita a navegação pelo mundo).
 - Câmera: 
    - Implementada em câmera.cpp e câmera.hpp calcula a matriz de visão (é uma mudança de frame: do espaço do mundo para o espaço da câmera). A matriz de visão é a inversa da matriz M (que converte as coordenadas do espaço da câmera para o espaço do mundo). Ou seja, <b>Mview = M^-1</b>. A sua fórmula é a inversa pois a finalidade é justamente o oposto (queremos converter as coordenadas do espaço do mundo para o espaço da câmera). Isto é implementado através da função <br>glm::lookAt</br> (importada da biblioteca GLM), o cálculo, portanto, é realizado conforme abaixo: <br>
    ![image](https://user-images.githubusercontent.com/30665585/145130652-9f043382-13ef-4c68-9897-b1727c2fc180.png) <br>
    
    - Os parâmetros <b>m_eye</b>, <b>m_at</b> e <b>m_up</b> equivalem, respectivamente a posição da câmera, posição para onde a câmera está olhando e direção para cima da câmera. As posições iniciais são descritas abaixo:
     - m_eye: (0,0,2,5)
     - m_at: (0,0,0)
     - m_up: (0,1,0)
    - As funções dolly, truck, pan são utilizadas dentro do <b>OpenGLWindow</b> para capturar e refletir (através da atualização das variáveis <b>m_eye</b> e <b>m_up</b>) a movimentação da entrada do teclado. A finalidade dessas funções foi descrita no início do relatório. A implementação delas foi realizada dentro de camera.cpp.    
 - Iluminação:
    - Conceitualmente, a interação de luz entre as superfícies dos objetos e a fonte de luz é modelada matemáticamente através da equação de renderização (Kajiya 1986).
    - Na aplicação existem três opções de iluminação (dentro da opção shader):
     - Textura: Utilização de shader que utiliza textura em conjunto com o modelo de reflexão Blinn-Phong.
     - Iluminação: Utilização do modelo Blinn-Phong.
     - Normal: Visualização de vetores normais como cores.
   O modelo de <b>Blinn-Phong</b> (Blinn 1977) é uma modificação do modelo de Phong. Este modelo é mais eficiente que o modelo de Phong. A diferença visível entre os dois é referente a forma do brilho especular: No Phong é sempre redondo na superfície plana, já no Blinn-Phong é redondo quando a superfície é vista de frente e alongado verticalmente quando a direção da visão e a direção à fonte de luz estão rentes à superfície. <br>
   Dado a simplicidade do modelo e maior eficiência se comparado ao Phong, implementamos em nossa aplicação pois é o mais utilizado em aplicações de tempo real. <br>
   O modelo está implementado em <b>texture.frag</b> (função: BlinnPhong) e <br>blinnphong.frag</b> (além de seus arquivos de cabeçalho de mesmo nome cuja extensão é .hpp). <br>
   Para o cálculo de normais: Utilizamos a função <b>Model::computeNormals</b> que calcula os vetores normais para cada vértice. Esta função está implementada dentro de model.cpp. Caso o objeto já possua as normais calculadas, a identificação booleana <b>(m_hasNormals)</b> não irá calcular as normais (poupa processamento e otimiza o código). Por fim, o <b>normal.vert</b> converte as coordenadas do vértice resultante (cada um deles) em uma cor RGB.
 - Textura:
     - Conforme citado acima, utilizamos a textura em conjunto com o modelo de reflexão Blinn-Phong.
     - O carregamento das texturas é feito a partir da função importada da biblioteca abcg: <b>abcg::opengl::loadTexture</b>.
     - Nossos modelos possuem o .mtl, que é a descrição das propriedades do objeto. Especifica os seguintes parâmetros: <b>Ns</b> (brilho especular), <b>Ka</b> (propriedade de reflexão do ambiente), <b>Kd</b> (difusa) e <b>Ks</b> (especular).
     - Em <b>Model::loadObj</b> prioriza-se as propriedades do material (caso houver). Caso não possua, são setados valores padrão dos parâmetros citados acima.
     - O modo default de carregamento de textura é o 3 (from mesh) - para que o arquivo obj carregue sua textura caso possua.

<br>__Funcionalidades:__
- Tecla A: Movimenta para a esquerda
- Tecla D: Movimenta para a direita
- Tecla W: Movimenta para a frente
- Tecla S: Movimenta para a trás
- Seta para direita: Olha para a direita (movimentando em torno do eixo y)
- Seta para esquerda: Olha para a esquerda (movimentando em torno do eixo y)
- Espaço: Corre para frente (W + espaço).


