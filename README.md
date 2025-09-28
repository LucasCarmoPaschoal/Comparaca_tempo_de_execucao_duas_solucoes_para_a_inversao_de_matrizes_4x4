# Comparação de tempo de execução entre duas soluções de execução de uma inversa de matriz 4x4 
Solução 1 disponivel em :https://lxjk.github.io/2017/09/03/Fast-4x4-Matrix-Inverse-with-SSE-SIMD-Explained.html  
solução 2 disponivel em :https://github.com/niswegmann/small-matrix-inverse/tree/master  

Foi criado arquivos FAST4X4_H.cpp e utilizado o arquivo invert4x4_llvm.h gerando com eles a função de inversão de matriz das soluçoes 1 e 2 respectivamente e como test utilizou os arquivos inverse_Fast4x4.cpp ,matrix_inverse.cpp para fazer uma main com um for que repete a mesma inversão 1 bilhão de vezes termando mais vizivel a duração de execução.   
Foram compilados com "clang-cl /O2 /EHsc /arch:AVX inverse_Fast4x4.cpp /Fe:inverse_Fast4x4.exe" e  
"clang-cl /EHsc /arch:AVX matrix_inverse.cpp -o matrix_inverse.exe"   
      
Foi utilizado Vtune como ferramenta para medição de tempo de execução para comparação.
    
     
     
Resultados da solução 1 temos :   
     
    


<img width="1161" height="765" alt="image" src="https://github.com/user-attachments/assets/91955cb3-aa6c-4eab-a8fd-d25ead6df4bc" />

Resultados da solução 2 temos :   



       
<img width="1156" height="779" alt="image" src="https://github.com/user-attachments/assets/52b7185d-e708-46fd-87b7-69784f455542" />


Na comparação dos dois codigos, observa-se que o código otimizado Solução 1 apresentou tempo de execução muito menor (0,3 s) em relação ao código solução 2 (37,7 s). A diferença drástica não está no fato de a operação de inversão ser diferente, mas sim na forma como os dados são processados. A Solução 1 utiliza instruções vetoriais que trabalham com vários elementos em paralelo, além de aproveitar melhor o cache de dados(devido a mesma matriz ser usada) e de instruções .  

Consideração final:  
FAST4X4_H.cpp

Utiliza uma matriz [4][4] com acesso sequencial linha por linha, o que favorece a localidade espacial.
Toda a matriz é pequena o suficiente para caber no cache L1, reduzindo drasticamente os cache misses.
Resultado: tempo de execução muito previsível e eficiente, aproveitando ao máximo o cache, mesmo sem instruções SIMD complexas.

invert4x4_llvm.h

Utiliza um array linear [16] combinado com operações vetoriais (SIMD) e shuffles, que frequentemente acessam elementos não contíguos na memória.
Isso quebra a localidade espacial, gerando mais cache misses, e faz com que a CPU precise buscar dados na memória com mais frequência.
Apesar do uso de SIMD, que processa múltiplos elementos em paralelo, a sobrecarga de acessos não sequenciais pode diminuir a eficiência do cache.
Resultado: em algumas arquiteturas, o tempo de execução pode ser comparativamente maior ou menos previsível do que FAST4X4, mesmo sendo otimizado para vetores.





