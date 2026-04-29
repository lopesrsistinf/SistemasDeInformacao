classdef Vetor
  properties
    x %Lista de números reais
    n %Quantidade de elementos
  end
  methods
    %Construtor
    function este = Vetor(x)
      este.x = x;
      este.n = size(x,2);
    end

    %Soma de Vetor
    function r = soma(este,outro)
      if este.n != outro.n
        fprintf("Dimensões inconsistentes\n");
        return
      end
      r = Vetor(zeros(1,este.n));
      for i=1:este.n
        r.x(i) = este.x(i) + outro.x(i);
      end
    end

    %Produto Escalar
    function r = produto(este,outro)
      if este.n != outro.n
        fprintf("Dimensões inconsistentes\n");
        return
      end
      r = 0;
      for i=1:este.n
        r += este.x(i)*outro.x(i);
      end
    end

    %Norma
    function r = norma(este)
      r = 0;
      for i=1:este.n
        r += (este.x(i)*este.x(i));
      end
      r = sqrt(r);
    end

    %Angulo
    function r = angulo(este,outro)
      if este.n != outro.n
        fprintf("Dimensões Inconsistentes");
        return
      end
      produtoEsc = este.produto(outro);
      norms = este.norma() * outro.norma();
      r = acos(produtoEsc/norms);
    end

    %Multiplicação Escalar
    function r = multescalar(este,c)
      r = Vetor(zeros(1, este.n));
      for i=1:este.n
        r.x(i) = este.x(i) * c;
      end
    end

    %Projeção
    function r = proj(este,outro)
      if este.n != outro.n
        fprintf("Dimensões Inconsistentes");
        return
      end
      produtoEscProj = este.produto(outro);
      normaA = outro.norma()^2;
      r = outro.multescalar(produtoEscProj/normaA);
    end

    %Display do Vetor
    function disp(este)
      fprintf('%g ', este.x);
    end
  end
end
