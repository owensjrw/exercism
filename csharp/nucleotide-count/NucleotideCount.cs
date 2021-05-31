using System;
using System.Collections.Generic;

public static class NucleotideCount
{
	public static IDictionary<char, int> Dna = new Dictionary<char, int>();
	
    public static IDictionary<char, int> Count(string sequence)
    {
		Dna['A'] = 0;
		Dna['C'] = 0;
		Dna['G'] = 0;
		Dna['T'] = 0;
		
		foreach(char c in sequence)
		{
			if(c != 'A' && c != 'C' && c != 'G' && c != 'T')
			{
				throw new ArgumentException();
			}
			++Dna[c];
		}
		
		return Dna;				
    }
}