class Personagem {
    
    private String nome;
    private int altura;
    private double peso;
    private String corDoCabelo;
    private String corDaPele;
    private String corDosOlhos;
    private String anoNascimento;
    private String Genero;
    private String homeworld;

    public Personagem ( String x )
    {
        nome = x;
    }

    public Personagem ( )
    {

    }

    public void lerArquivo ( String filename )
    {
        Arq.openRead ( filename, "utf-8");
        String linha = Arq.readLine();
        
        /*do
        {
            linha = Arq.readLine();
        }while(linha.indexOf("url") == -1);*/
        Arq.close();
        MyIO.print(linha);
    }

    public static boolean isFim(String s){
        return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
     }
        public static void main(String[] args) {
            
            String[] linha = new String[1000];
            int numEntrada = 0;
            Personagem personagem = new Personagem();

            do {
                linha[numEntrada] = MyIO.readLine();
                // MyIO.println("A linha e :"+linha[numEntrada]);
            } while (isFim(linha[numEntrada++]) == false);
            numEntrada--;
            personagem.lerArquivo(linha[0]);
    }
}