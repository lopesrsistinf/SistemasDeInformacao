# Parâmetros da Distribuição Normal
media <- 90
desvio_padrao <- 20

# a. Quantos são esperados passar?
# O candidato passa se o tempo for menor que 80 minutos: P(X < 80)
prob_passar <- pnorm(80, mean = media, sd = desvio_padrao)

# O valor esperado (esperança) é a probabilidade multiplicada pelo número total de tentativas/candidatos
total_candidatos <- 65
esperados_passar <- prob_passar * total_candidatos

cat("a. Probabilidade de passar:", prob_passar, "\n")
cat("a. Número esperado de candidatos a passar (de 65):", esperados_passar, "\n")
# Opcional: round(esperados_passar) para ter um número inteiro de pessoas.


# b. Tempo para estar entre os 5% melhores
# Atenção à lógica: em um teste de tempo, os "melhores" são os mais rápidos.
# Isso significa que eles levam o MENOR tempo possível.
# Portanto, queremos o limite de tempo que separa os 5% iniciais da cauda inferior da curva.
tempo_top5 <- qnorm(0.05, mean = media, sd = desvio_padrao)

cat("b. O candidato deve completar o teste em menos de:", tempo_top5, "minutos\n")