taxa <- 1/20

prob_T_maior_15 <- pexp(15, rate = taxa, lower.tail = FALSE)
prob_T_maior_10 <- pexp(10, rate = taxa, lower.tail = FALSE)

prob_condicional <- prob_T_maior_15 / prob_T_maior_10
cat("Fórmula Condicional:", prob_condicional, "\n")