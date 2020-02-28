public class Personagem {

	private String file;
	private String nome;
	private int altura; 
	private double peso;
	private String corDoCabelo;
	private String corDaPele;
	private String corDosOlhos;
	private String anoNascimento; 
	private String genero;
	private String homeworld;

	public Personagem()
	{
	}

	public Personagem(String nome)
	{
		this.nome = nome;
	}

	public void lerArquivo(String filename)
	{
		Arq.openRead(filename,"utf-8");
		String linha = Arq.readLine();
		Arq.close();
		file = linha;
		MyIO.println(linha);
	}

	public static boolean isFim(String s){
		return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
	}
	
	public static void main (String[] Args)
	{
		String[] linha = new String[100];
		int numEntrada = 0;
		Personagem personagem = new Personagem();
		do {
			linha[numEntrada] = MyIO.readLine();
		} while (isFim(linha[numEntrada++]) == false);
		numEntrada--;
		personagem.lerArquivo(linha[0]);
	}

}
