
# Wine Quality Classifier — TensorFlow Lite Micro (RP2040)

Este projeto demonstra a aplicação de aprendizado de máquina embarcado utilizando uma rede neural treinada para classificar vinhos em três classes distintas. O modelo foi convertido para TensorFlow Lite Micro e executado diretamente na Raspberry Pi Pico W, permitindo inferências sem depender de sistemas operacionais ou alto poder computacional.

## 🔍 Propósito

O projeto foi desenvolvido com foco educacional, visando compreender:

- Como treinar um modelo de Machine Learning.
- Como converter o modelo para `.tflite` e depois para array C.
- Como realizar inferência embarcada utilizando o TensorFlow Lite Micro.
- Como analisar resultados reais em ambiente de microcontrolador.

## 📊 Sobre o Dataset

Foi utilizada uma versão reduzida do *Wine Quality Dataset*, contendo 30 amostras com valores físico-químicos do vinho.  
As amostras foram normalizadas usando média e desvio padrão calculados previamente no treino, e os mesmos valores foram enviados ao firmware para garantir coerência com o modelo original.

O dataset possui **3 classes** de qualidade (Classe 0, 1 e 2) e foi usado para treinar um modelo simples de classificação, posteriormente convertido para uso no RP2040.

## 🛠 Tecnologias Utilizadas

- Raspberry Pi Pico W (RP2040)
- TensorFlow Lite Micro
- Conversão de modelo para C (`model_data.h`)
- Normalização dos dados embarcada
- Saída via comunicação Serial

## 📌 Resultado Obtido no Dispositivo

A Pico W processou todas as amostras e retornou o seguinte resultado:

```
Amostra  1: Real=Classe_2, Predito=Classe_1 [0.93] ERRO
Amostra  2: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra  3: Real=Classe_1, Predito=Classe_1 [0.98] OK
Amostra  4: Real=Classe_1, Predito=Classe_1 [0.98] OK
Amostra  5: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra  6: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra  7: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra  8: Real=Classe_1, Predito=Classe_1 [0.99] OK
Amostra  9: Real=Classe_2, Predito=Classe_2 [1.00] OK
Amostra 10: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 11: Real=Classe_2, Predito=Classe_2 [0.92] OK
Amostra 12: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 13: Real=Classe_2, Predito=Classe_2 [0.82] OK
Amostra 14: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 15: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 16: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 17: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 18: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 19: Real=Classe_0, Predito=Classe_0 [0.95] OK
Amostra 20: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 21: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 22: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 23: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 24: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 25: Real=Classe_1, Predito=Classe_1 [1.00] OK
Amostra 26: Real=Classe_0, Predito=Classe_0 [1.00] OK
Amostra 27: Real=Classe_2, Predito=Classe_2 [1.00] OK
Amostra 28: Real=Classe_1, Predito=Classe_1 [0.99] OK
Amostra 29: Real=Classe_2, Predito=Classe_2 [1.00] OK
```

### Matriz de Confusão

|       | Pred0 | Pred1 | Pred2 |
|-------|------:|------:|------:|
| Real0 |  11   |   0   |   0   |
| Real1 |   0   |  13   |   0   |
| Real2 |   0   |   1   |   5   |

**Acurácia Geral:** `96.7%`

Esse repositório demonstra na prática o funcionamento de TinyML, destacando como modelos treinados em Python podem ser embarcados em dispositivos extremamente limitados com precisão satisfatória.
