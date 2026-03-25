% cp = coluna pivot
% lp = linha pivot
% nl = numero de linhas
% nc = numero de colunas
% lm = linhas do maximo
% em = elemento maximo
% vl = variaveis livres
vl = 0;
[nl nc]=size(A);

if nl!=nc
  printf("Matriz não é quadrada\n")
  return
end

A=[A eye(nl)]

for cp = 1:nc
  lp = cp-vl;
  [em lm]=max(abs(A(lp:nl,cp)));
  if abs(em)<10e-15 || lp > nl
    vl=vl+1
    continue
  end
  lm = lm +(lp-1);
  A([lp lm],:) = A([lm lp],:);
  A(lp,:) = A(lp,:)/A(lp,cp);

  for j = lp+1:nl
    A(j,:)=A(j,:)-A(lp,:)*A(j,cp);
  end
  for j = 1:lp-1
    A(j,:)=A(j,:)-A(lp,:)*A(j,cp);
  end
end

if vl > 0
    printf("Matriz não é inversível\n")
    return
end

printf("Matriz é inversível. A inversa é:\n")
A(:,nc+1:2*nc)

