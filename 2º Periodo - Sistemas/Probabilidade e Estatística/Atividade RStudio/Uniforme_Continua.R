# Parâmetros da rede (Distribuição Uniforme Contínua de 0 a 10 km)
limite_inf <- 0
limite_sup <- 10

# a. Qual é a probabilidade de a pane ocorrer nos primeiros 500 metros?
# 500 metros = 0.5 km. A função punif calcula P(X <= q).
prob_a1 <- punif(0.5, min = limite_inf, max = limite_sup)
cat("a1. Probabilidade nos primeiros 500m (0,5 km):", prob_a1, "\n")

# a. E de ocorrer nos 3 quilômetros centrais da rede?
# O meio da rede é o km 5. Os "3 km centrais" se estendem 1.5 km para cada lado do centro.
# Portanto, o intervalo vai do km 3,5 ao km 6,5.
# P(3.5 < X < 6.5) = P(X < 6.5) - P(X < 3.5)
prob_a2 <- punif(6.5, min = limite_inf, max = limite_sup) - 
           punif(3.5, min = limite_inf, max = limite_sup)
cat("a2. Probabilidade nos 3 km centrais (3,5 a 6,5 km):", prob_a2, "\n")

# b. Qual é o custo médio do conserto?
# O custo médio é o Valor Esperado (Esperança Matemática), calculado pela soma dos 
# custos multiplicados pelas probabilidades de a pane ocorrer em cada intervalo.

# 1. Probabilidade de ser até 3 km (P(X <= 3))
prob_custo1 <- punif(3, min = limite_inf, max = limite_sup)

# 2. Probabilidade de ser entre 3 e 8 km (P(3 < X <= 8))
prob_custo2 <- punif(8, min = limite_inf, max = limite_sup) - 
               punif(3, min = limite_inf, max = limite_sup)

# 3. Probabilidade de ser acima de 8 km (P(X > 8))
prob_custo3 <- punif(10, min = limite_inf, max = limite_sup) - 
               punif(8, min = limite_inf, max = limite_sup)
# (Ou simplesmente 1 - punif(8, min, max))

# Cálculo do custo médio
custo_medio <- (200 * prob_custo1) + (400 * prob_custo2) + (1000 * prob_custo3)

cat("b. O custo médio do conserto é: R$", custo_medio, "\n")