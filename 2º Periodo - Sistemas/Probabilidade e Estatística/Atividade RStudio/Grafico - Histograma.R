# Vetores com os dados da tabela
classes <- c("0|-2", "2|-4", "4|-6", "6|-8", "8|-10")
frequencias <- c(14, 28, 27, 11, 4)

# ---------------------------------------------------------
# a. Construa o histograma
# ---------------------------------------------------------
# Usamos barplot com space = 0 para encostar as barras, 
# característica fundamental de um histograma contínuo.
barplot(frequencias, 
        names.arg = classes, 
        space = 0, 
        col = "steelblue", 
        border = "black",
        main = "Histograma das Notas de Matemática",
        xlab = "Notas (Classes)", 
        ylab = "Frequência de Alunos")

# ---------------------------------------------------------
# b. Porcentagem de aprovação (nota mínima = 5)
# ---------------------------------------------------------
total_alunos <- sum(frequencias)

# A classe "4|-6" possui 27 alunos.
# Como a nota 5 divide o intervalo [4, 6] exatamente ao meio, 
# assumimos que 50% dos alunos dessa classe atingiram a nota 5 ou mais.
aprovados_classe_4_6 <- frequencias[3] / 2  # 27 / 2 = 13.5 alunos

# Somamos essa estimativa com os alunos que já estão nas classes acima de 6
aprovados_acima_de_6 <- frequencias[4] + frequencias[5] # 11 + 4 = 15 alunos

total_aprovados <- aprovados_classe_4_6 + aprovados_acima_de_6

# Cálculo da porcentagem
porcentagem <- (total_aprovados / total_alunos) * 100

# Exibindo os resultados no console
cat("Total de alunos na turma:", total_alunos, "\n")
cat("Estimativa de alunos aprovados (nota >= 5):", total_aprovados, "\n")
cat("b. Porcentagem de aprovação:", round(porcentagem, 2), "%\n")