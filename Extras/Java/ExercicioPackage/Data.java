public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano){
        if(dataValida(dia,mes,ano)){
            this.dia = 1;
            this.mes = 1;
            this.ano = 1;
        } else {
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }
    }

    private boolean dataValida(int dia, int mes, int ano){
        if(dia < 1|| ano < 1 || mes < 1 || mes > 12) return false;
        int[] diasMes = {31,28,31,30,31,30,31,31,30,31,30,31};
        if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) diasMes[1] = 29;
        return dia <= diasMes[mes-1];
    }

    public int compara(Data outraData){
        if(this.ano > outraData.getAno()) return 1;
        if (this.ano < outraData.getAno()) return -1;
        
        if (this.mes > outraData.getMes()) return 1;
        if (this.mes < outraData.getMes()) return -1;
        
        if (this.dia > outraData.getDia()) return 1;
        if (this.dia < outraData.getDia()) return -1;
        
        return 0;
    }

    public int getDia() {
        return this.dia;
    }

    public int getMes() {
        return this.mes;
    }

    public int getAno() {
        return this.ano;
    }
    public String getMesExtenso() {
        String[] meses = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        };
        return meses[this.mes - 1];
    }

    public Data clone() {
        return new Data(this.dia, this.mes, this.ano);
    }
}
