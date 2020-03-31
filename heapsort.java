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

public class heapsort{

	private Personagem[] array;
	private int quantidade;
	private int tamanho;
	public int mov;
	public int comp;

	heapsort(){
	}

	heapsort(int tamanho)
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

	public void heap()
	{
		for(int tam = 2; tam <= quantidade; tam++)
		{
			constroi(tam);
		}
	}

	public void constroi(int tamHeap)
	{
		for(int i = tamHeap; i > 1 && array[i].getAltura() > array[i/2].getAltura(); i /= 2)
		{
			Personagem tmp = new Personagem();
			tmp = tmp.clone(array[i]);
			array[i] = array[i].clone(array[i/2]);
			array[i/2] = array[i/2].clone(tmp);
		}
	}

	public void reconstroi(int tamHeap)
	{
		int i = 1, filho = 0;
		while(i <= (tamHeap/2))
		{
			if(array[2*i].getAltura() > array[2*i+1].getAltura() || 2*i == tamHeap)
			{
				filho = 2*i;
			} else{
				filho = 2*i + 1;	
			}

			if(array[i].getAltura() < array[filho].getAltura())
			{

				Personagem tmp = new Personagem();
				tmp = tmp.clone(array[i]);
				array[i] = array[i].clone(array[filho]);
				array[filho] = array[filho].clone(tmp);
				i = filho;
			} else{
				i = tamHeap;
			}
		}
	}

	public void heapsort(int quant) 
	{
		heapsort tmp = new heapsort(quant+1);

		//Alterar o vetor ignorando a posicao zero
		for(int i = 0; i < quant; i++){
			tmp.array[i+1] = tmp.array[i+1].clone(array[i]);
		}
		array = tmp.array;

		//Contrucao do heap
		for(int tamHeap = 2; tamHeap <= quantidade; tamHeap++){
			constroi(tamHeap);
		}

		//Ordenacao propriamente dita
		int tamHeap = quant;
		while(tamHeap > 1){
			Personagem tmp2 = new Personagem();
			tmp2 = tmp2.clone(array[1]);
			array[1] = array[1].clone(array[tamHeap]);
			array[tamHeap] = array[tamHeap].clone(tmp2);
			tamHeap--;
			reconstroi(tamHeap);
		}

		//Alterar o vetor para voltar a posicao zero
		tmp.array = array;
		for(int i = 0; i < quantidade; i++){
			array[i] = array[i].clone(tmp.array[i+1]);
		}
	}

	void desempate() {
		int indice = 0;
		for (int i = 0; i < (quantidade - 1); i++) {
			indice = i;
			for (int j = (i + 1); j < quantidade; j++){
				if(  array[indice].getNome().compareTo( array[j].getNome()) > 0 
						&& array[i].getAltura() == array[j].getAltura()){
					indice = j;
					comp++;
						}
			}
			Personagem tmp = new Personagem();
			tmp = tmp.clone(array[indice]);
			mov++;
			array[indice] = array[indice].clone(array[i]);
			mov++;
			array[i] = array[i].clone(tmp);
			mov++;
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

	public static void main (String[] Args)
	{
		MyIO.setCharset("utf-8");
		String[] linha = new String[100];
		Personagem personagem = new Personagem();
		int numEntrada = 0;

		long startTime = System.nanoTime();

		do {
			linha[numEntrada] = MyIO.readLine();
		} while (isFim(linha[numEntrada++]) == false);
		numEntrada--;

		heapsort lista = new heapsort(numEntrada);
		lista.construirLista(linha,numEntrada);
		lista.heapsort(numEntrada);
		lista.desempate();
		lista.mostrarArray();
	}
}
