# Parâmetros da Distribuição Hipergeométrica
m <- 3  # Número de peças defeituosas
n <- 9  # Número de peças boas (12 - 3)
k <- 4  # Tamanho da amostra retirada

# a. Pelo menos 2 defeituosas: P(X >= 2)
# Como o máximo de defeituosas na caixa é 3, X pode ser 2 ou 3.
prob_a <- sum(dhyper(2:3, m = m, n = n, k = k))
# Alternativa usando probabilidade acumulada: phyper(1, m, n, k, lower.tail = FALSE)
cat("a. Pelo menos 2 defeituosas =", prob_a, "\n")

# b. No máximo 1 defeituosa: P(X <= 1)
# Significa tirar 0 ou 1 defeituosa. A função phyper calcula o acumulado direto.
prob_b <- phyper(1, m = m, n = n, k = k)
cat("b. No máximo 1 defeituosa =", prob_b, "\n")

# c. No mínimo 1 boa
# Se tiramos 4 peças, e só existem 3 defeituosas no total, é IMPOSSÍVEL tirar 4 defeituosas.
# Logo, em qualquer sorteio de 4 peças, obrigatoriamente teremos pelo menos 1 peça boa.
# Matematicamente, a probabilidade é 100% (ou 1).
# Podemos provar isso calculando P(X <= 3 defeituosas), que abrange todos os cenários possíveis:
prob_c <- phyper(3, m = m, n = n, k = k)
cat("c. No mínimo 1 boa =", prob_c, "\n")