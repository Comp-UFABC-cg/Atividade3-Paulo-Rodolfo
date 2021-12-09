# Relatório - Atividade 3 - Aplicação 3D #

Este repositório contém o código fonte e link da aplicação rodando em <br>
WebAssembly.

A aplicação foi implementada utilizando a seguinte arquitetura: C++, OpenGL e a biblioteca ABCG. <br>

__Membros:__

__Nome:__ Paulo Alexander Simões, <b>RA:</b>11084915 <br>
__Nome:__ Rodolfo Azevedo dos Santos, <b>RA:</b> 11093514

__Link para a aplicação:__  https://comp-ufabc-cg.github.io/Atividade3-Paulo-Rodolfo/public/ <br>
(caso encontre problemas ao abrir, é necessário tentar outras vezes recarregando a página)

<br>__Aplicação:__ Explorador 3D

- Print da tela da aplicação: <br>
![image](https://user-images.githubusercontent.com/30665585/145312745-9c2b67de-3e32-4221-9ef5-47e8e086ef60.png)


<br>__Funcionalidades (Manual de uso):__
- Tecla A: Movimenta para a esquerda
- Tecla D: Movimenta para a direita
- Tecla W: Movimenta para a frente
- Tecla S: Movimenta para a trás
- Seta para direita: Olha para a direita (movimentando em torno do eixo y)
- Seta para esquerda: Olha para a esquerda (movimentando em torno do eixo y)
- Espaço: Acelera na direção atual.
- Back-face culling: Para otimizar a renderização, habilitamos a seleção do face culling através do checkbox. Caso habilitado, o face culling é ativado a partir da função abcg::glEnable(GL_CULL_FACE). O Face Culling consiste em descartar todos os triângulos que não estão de frente para a câmera.
- Front Face: Checkbox que permite escolher a orientação dos vértices: CW (sentido horário) ou CCW (sentido anti horário). Habilitado através da função abcg::glFrontFace(GL_CW) e abcg::glFrontFace(GL_CCW) conforme escolha do usuário.
- Texture: Seletor de textura
- UV Mapping: Mapeamento de textura.
- Arquivo: 
  - Load 3D Model: Carrega um modelo 3D. A aplicação permite a seleção de um dos 4 objetos da pasta, conforme abaixo: <br>
![image](https://user-images.githubusercontent.com/30665585/145311931-cb574a38-a607-44c5-88cd-cf04f9c49197.png)
  - Load Diffuse Texture: Carrega uma textura 3D. A aplicação permite a selação de uma das texturas da pasta, conforme abaixo: <br>
![image](https://user-images.githubusercontent.com/30665585/145312022-f19fa84e-4a60-48ef-bd4c-a8545db20673.png)
 - Light properties: Permite alterar os parâmetros de luz (Ia,Id,Is) e parâmetros do objeto: Ka,Kd,Ks, conforme abaixo. Adicionalmente, é possível alterar o brilho (shininess): <br>
 ![image](https://user-images.githubusercontent.com/30665585/145312299-0d15c173-2463-48dd-81cf-b3da3466dde0.png)
- O manual pode ser habilitado a qualquer momento a partir do checkbox "Exibir Manual" que exibe na tela o modo de operação da aplicação. <br>
![image](https://user-images.githubusercontent.com/30665585/145311356-38674c86-c8c3-4c2f-a4c3-22f8ca8628aa.png) <BR>


<br>__Motivação:__ 
   - Criar uma aplicação para explorar um acervo de objetos 3D com utilização de textura e iluminação. A exploração é feita a partir da visão em primeira pessoa.

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
     - Texture: Utilização de shader que utiliza textura em conjunto com o modelo de reflexão Blinn-Phong.
     - Blinnphong: Utilização do modelo Blinn-Phong.
     - Phong: Utilização do modelo Phong.
     - Gourad: Utilização do sombreamento Gourad.
     - Normal: Visualização de vetores normais como cores. 
     - Depth: Utilização do modelo depth.<br>
   O modelo de <b>Blinn-Phong</b> (Blinn 1977) é uma modificação do modelo de Phong. Este modelo é mais eficiente que o modelo de Phong. A diferença visível entre os dois é referente a forma do brilho especular: No Phong é sempre redondo na superfície plana, já no Blinn-Phong é redondo quando a superfície é vista de frente e alongado verticalmente quando a direção da visão e a direção à fonte de luz estão rentes à superfície. <br>
   Dado a simplicidade do modelo e maior eficiência se comparado ao Phong, sugerimos a sua utilização em nossa aplicação pois é o mais utilizado em aplicações de tempo real. Entretanto, o usuário pode escolher o modelo desejado. <br>
   O modelo está implementado em <b>texture.frag</b> (função: BlinnPhong) e <b>blinnphong.frag</b> (além de seus arquivos de cabeçalho de mesmo nome cuja extensão é .hpp). <br>
   Para o cálculo de normais: Utilizamos a função <b>Model::computeNormals</b> que calcula os vetores normais para cada vértice. Esta função está implementada dentro de model.cpp. Caso o objeto já possua as normais calculadas, a identificação booleana <b>(m_hasNormals)</b> não irá calcular as normais (poupa processamento e otimiza o código). Por fim, o <b>normal.vert</b> converte as coordenadas do vértice resultante (cada um deles) em uma cor RGB. <br>
   O modelo Phong é implementado através de <b> phong.frag </b> e <b>phong.vert </b>. É um modelo de iluminação local que através de mapeamento empírico calcula a quantidade de luz refletida de um ponto P de uma superfície em direção v^ até a câmera. Sua equação é dada abaixo: <br>
![image](https://user-images.githubusercontent.com/30665585/145314339-d3947b2e-32d1-4286-972d-da0915965caf.png) <br>
alfa (a): constante de espalhamento de brilho especular.
m: número de fontes de luz,
Ka,Kd,Ks: Coeficientes de reflexão do material (propriedades do material).
Ia,Id,Is: Intensidade da luz.

   
 - Textura:
     - Conforme citado acima, utilizamos a textura em conjunto com o modelo de reflexão Blinn-Phong.
     - O carregamento das texturas é feito a partir da função importada da biblioteca abcg: <b>abcg::opengl::loadTexture</b>.
     - Nossos modelos possuem o .mtl, que é a descrição das propriedades do objeto. Especifica os seguintes parâmetros: <b>Ns</b> (brilho especular), <b>Ka</b> (propriedade de reflexão do ambiente), <b>Kd</b> (difusa) e <b>Ks</b> (especular).
     - Em <b>Model::loadObj</b> prioriza-se as propriedades do material (caso houver). Caso não possua, são setados valores padrão dos parâmetros citados acima.
     - O modo default de carregamento de textura é o 3 (from mesh) - para que o arquivo obj carregue sua textura caso possua.
     - Mapeamento: 
      - O mapeamento consiste em mapear pontos do espaço 3D (x,y,z) em pontos do espaço 2D (u,v). É necessário para a inclusão da textura. A aplicação possui 4 deles: <br>
       - Planar: É uma projeção linear e paralela dos pontos do espaço 3D para o plano do espaço de textura 2D. A aplicação possui o mapeamento triplanar que é uma combinação dos mapeamentos planares de x,y e z. <br>
       - Cilíndrico: É o mapeamento equivalente a envolver a área lateral de uma cilindro com textura.<br>
       - Esférico: É o mapeamento equivalente a envolver uma esfera.<br>
       - Mapeamento UV Unwrap: Define diretamente quais coordenadas (u,v) são pertencentes a cada vértice da malha geométrica (mesh).<br>
       Todos mapeamentos são armazenados na variáveis <b> m_mappingMode </b> em <b>openglwindow.cpp</b>.  <br>
       Resultado da utilização de textura: <br>
![image](https://user-images.githubusercontent.com/30665585/145146090-260f6793-a9fb-468a-8ddf-415aa097cb49.png) <br>

<br>__Referências:__ <br>
1) Terra: https://www.cgtrader.com/items/2408222/download-page
2) Alien - https://comp-ufabc-cg.github.io/Atividade3-Paulo-Rodolfo/public/ <br>
3) Casa Medieval - https://www.cgtrader.com/free-3d-models/exterior/house/medieval-house-ba1c8fd4-d6ee-4666-83de-23c1684fe6aa <br>
4) Mustang - https://www.cgtrader.com/items/2729539/download-page <br>
5) Site da disciplina do professor Bruno Dorta https://www.brunodorta.com.br/cg/ 



