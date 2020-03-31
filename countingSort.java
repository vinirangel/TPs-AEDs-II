class Personagem {

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

	public Personagem clone( Personagem personagem)
	{
		Personagem personagem2 = new Personagem();
		personagem2.file = personagem.file;
		personagem2.nome = personagem.nome;
		personagem2.altura = personagem.altura;
		personagem2.peso = personagem.peso;
		personagem2.corDoCabelo = personagem.corDoCabelo;
		personagem2.corDaPele = personagem.corDaPele;
		personagem2.corDosOlhos = personagem.corDosOlhos;
		personagem2.anoNascimento = personagem.anoNascimento;
		personagem2.genero = personagem.genero;
		personagem2.homeworld = personagem.homeworld;
		return personagem2;
	}

	public void lerArquivo(String filename)
	{
		Arq.openRead(filename,"iso-8859-1");
		String linha = Arq.readLine();
		Arq.close();
		file = linha;

	}

	public void setNome()
	{
		String[] temp = file.split(",");
		String[] tmp = temp[0].split(":");
		if(tmp[1].contains("'"))
		{
			nome = tmp[1].replace("'","").trim();
		}
	}

	public String getNome()
	{
		return nome;
	}

	public void setAltura()
	{
		String[] temp = file.split("height':");
		String[] tmp = temp[1].split(",");
		String tp = tmp[0].replace("'","");
		tp = tp.replace(" ","");

		if(tp.contains("unknown")) 
		{	
			altura = 0;
		}
		else{
			altura = Integer.parseInt(tp);
		}
	}

	public int getAltura()
	{
		return altura;
	}

	public void setPeso()
	{
		String[] temp = file.split("mass':");
		String[] tmp = temp[1].split(",");
		String weight = tmp[0].replace("'","").trim();

		if (weight.contains("unknown"))
		{
			peso = 0;
		}
		else{
			peso = Double.parseDouble(weight);
		}
	}

	public double getPeso()
	{
		return peso;
	}

	public void setCorDoCabelo()
	{
		String[] temp = file.split("hair_color':");
		String[] tmp = temp[1].split("',");
		corDoCabelo = tmp[0].replace("'","").trim();
	}

	public String getCorDoCabelo()
	{
		return corDoCabelo;
	}

	public void setCorDaPele()
	{
		String[] temp = file.split("skin_color':");
		String[] tmp = temp[1].split("',");
		tmp[0] = tmp[0].replace("'","");
		corDaPele = tmp[0].trim();
	}

	public String getCorDaPele()
	{
		return corDaPele;
	}

	public void setCorDosOlhos()
	{
		String[] temp = file.split("eye_color':");
		String[] tmp = temp[1].split("',");
		corDosOlhos = tmp[0].replace("'","").trim();
	}

	public String getCorDosOlhos()
	{
		return corDosOlhos;
	}

	public void setAnoNascimento()
	{
		String[] temp = file.split("birth_year':");
		String[] tmp = temp[1].split(",");
		anoNascimento = tmp[0].replace("'","").trim();
	}

	public String getAnoNascimento()
	{
		return anoNascimento;
	}

	public void setGenero()
	{
		String[] temp = file.split("gender':");
		String[] tmp = temp[1].split(",");
		genero = tmp[0].replace("'","").trim();
	}

	public String getGenero()
	{
		return genero;
	}

	public void setHomeworld()
	{
		String[] temp = file.split("homeworld':");
		String[] tmp = temp[1].split(",");
		homeworld = tmp[0].replace("'","").trim();
	}

	public String getHomeworld()
	{
		return homeworld;
	}

	public void setAll()
	{
		setNome();
		setAltura();
		setPeso();
		setCorDoCabelo();
		setCorDaPele();
		setCorDosOlhos();
		setAnoNascimento();
		setGenero();
		setHomeworld();

	}

	public void imprimir()
	{
		MyIO.print(" ## "+nome);
		MyIO.print(" ## "+altura);

		if(String.valueOf(peso).contains(".0"))
		{
			MyIO.print(" ## "+String.valueOf(peso).replace(".0",""));
		}
		else{
			MyIO.print(" ## "+peso);
		}
		MyIO.print(" ## "+corDoCabelo);
		MyIO.print(" ## "+corDaPele);
		MyIO.print(" ## "+corDosOlhos);
		MyIO.print(" ## "+anoNascimento);
		MyIO.print(" ## "+genero);
		MyIO.print(" ## "+homeworld+" ## "+"\n");
	}
}

//=========================================================FIM DA CLASSE PERSONAGEM=========================================================================

public class countingSort{

	private Personagem[] array;
	private int quantidade;
	private int tamanho;
	public int mov;
	public int comp;

	countingSort(){
	}

	countingSort(int tamanho)
	{
		array = new Personagem[tamanho];
		quantidade = 0;

		for(int x = 0; x < array.length; x++)
		{
			array[x] = new Personagem();
		}
	}

	public void construirLista(String[] linha,int numEntrada)
	{
		for(int x = 0; x < numEntrada; x++)
		{
			array[x].lerArquivo(linha[x]);
			array[x].setAll();
			quantidade++;
		}
	}

	public void mostrarArray()
	{
		for(int x = 0; x < quantidade; x++)
		{
			array[x].setAll();
		}
		for(int y = 0; y < quantidade; y++)
		{
			//MyIO.print("["+y+"] ");
			array[y].imprimir();
		}
	}

	public static boolean isFim(String s){
		return (s.length() >= 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
	}

	public double getMaior()
	{
		double maior = array[0].getPeso();
		for(int i = 0; i < quantidade; i++)
		{
			if(maior < array[i].getPeso()){
				maior = array[i].getPeso();
			}
		}
		return maior;
	}

	public void countingSort()
	{
		double[] count = new double[(int)(getMaior()+1)];
		//double[] ordenado = new double[quantidade];
		Personagem[] ordenado = ordenado.clone(array);

		for(int i = 0; i < count.length; count[i] = 0, i++);

		for(int i = 0; i < quantidade; count[(int)array[i].getPeso()]++, i++);

		for(int i = 1; i < count.length; count[i] += count[i-1], i++);
		//ordenando
		for(int i = quantidade-1; i >= 0; ordenado[count[array[i]]-1] = array[i].getPeso(), count[array[i].getPeso()]--, i--);
		//transferindo
		for(int i = 0; i < quantidade; array[i] = ordenado[i], i++); 
	}

	public static void main (String[] Args)
	{
		MyIO.setCharset("utf-8");
		String[] linha = new String[100];
		countingSort lista = new countingSort(100);
		Personagem personagem = new Personagem();
		int numEntrada = 0;

		do {
			linha[numEntrada] = MyIO.readLine();
		} while (isFim(linha[numEntrada++]) == false);
		numEntrada--;


		long startTime = System.nanoTime();
		lista.construirLista(linha,numEntrada);
		lista.countingSort();
		lista.mostrarArray();

		//long endTime = System.nanoTime();
		//long execTime= (endTime - startTime);
		//Arq.openWriteClose("668007_selecao.txt", "UTF-8", "Matricula: 668007\t"+"Tempo de execucao:\t"+execTime+"\t"+"Movimentacoes: \t"+lista.mov+"Comparacoes:\t"+lista.comp);
	}
}
