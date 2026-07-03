# Parâmetros da distribuição Binomial conforme image_b0776a.png
n <- 15
p <- 0.4

# Criando o espaço de suporte de X (de 0 a n) e suas probabilidades correspondentes
X <- 0:n
px <- dbinom(X, size = n, prob = p)

# a. P(X >= 14)
# Soma as probabilidades onde X é maior ou igual a 14 (ou seja, 14 e 15)
prob_a <- sum(px[X >= 14])
cat("a. P(X >= 14) =", prob_a, "\n")

# b. P(8 < X <= 10)
# Valores de X maiores que 8 e menores ou iguais a 10 (ou seja, 9 e 10)
prob_b <- sum(px[X > 8 & X <= 10])
cat("b. P(8 < X <= 10) =", prob_b, "\n")

# c. P(X < 2 ou X >= 11)
prob_c <- sum(px[X < 2 | X >= 11])
cat("c. P(X < 2 ou X >= 11) =", prob_c, "\n")

# d. P(X >= 11 ou X > 13)
# Note que X > 13 já está contido em X >= 11, o 'ou' (união) resulta no próprio X >= 11
prob_d <- sum(px[X >= 11 | X > 13])
cat("d. P(X >= 11 ou X > 13) =", prob_d, "\n")

# e. P(X > 3 e X < 6)
# Valores de X maiores que 3 E menores que 6 (ou seja, 4 e 5)
prob_e <- sum(px[X > 3 & X < 6])
cat("e. P(X > 3 e X < 6) =", prob_e, "\n")

# f. P(X <= 13 | X >= 11) -> Probabilidade Condicional
# P(A | B) = P(A e B) / P(B)
prob_intersecao <- sum(px[X <= 13 & X >= 11]) # Probabilidade de ser 11, 12 ou 13
prob_condicao <- sum(px[X >= 11])             # Probabilidade de ser 11, 12, 13, 14 ou 15

prob_f <- prob_intersecao / prob_condicao
cat("f. P(X <= 13 | X >= 11) =", prob_f, "\n")