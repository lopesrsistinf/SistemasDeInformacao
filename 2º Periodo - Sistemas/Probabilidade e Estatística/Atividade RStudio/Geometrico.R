# Probabilidade de sucesso (cara) em uma moeda equilibrada
p <- 0.5

# a. P(X <= 2)
# Usamos pgeom() que calcula a probabilidade acumulada P(X <= x)
prob_a <- pgeom(2, prob = p)
cat("a. P(X <= 2) =", prob_a, "\n")

# b. P(X > 1)
# Equivalente a 1 - P(X <= 1). No R, lower.tail = FALSE calcula P(X > x)
prob_b <- pgeom(1, prob = p, lower.tail = FALSE)
cat("b. P(X > 1) =", prob_b, "\n")

# c. P(3 < X <= 5)
# Isso significa que X pode ser 4 ou 5. 
# Podemos fazer P(X <= 5) - P(X <= 3) ou somar as probabilidades pontuais:
prob_c <- sum(dgeom(4:5, prob = p))
cat("c. P(3 < X <= 5) =", prob_c, "\n")

# d. Mínimo de lançamentos para garantir ocorrência com prob >= 0,8
# Queremos encontrar o menor número de lançamentos (n) onde a probabilidade acumulada seja pelo menos 0,8.
# A função qgeom(probabilidade, p) retorna o valor de X (número de falhas) para atingir essa probabilidade.
falhas_X <- qgeom(0.8, prob = p)

# O número total de lançamentos é o número de falhas antes da cara (X) + o próprio lançamento da cara (+1).
lancamentos_minimos <- falhas_X + 1
cat("d. Lançamentos mínimos para prob >= 0,8:", lancamentos_minimos, "\n")