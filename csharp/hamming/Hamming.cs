using System;

public static class Hamming
{
    public static int Distance(string firstStrand, string secondStrand)
    {
        if(firstStrand.Length != secondStrand.Length)
		{
				throw new ArgumentException();
		}
		
		int index, count;
		index = count = 0;
		
		while(index < firstStrand.Length)
		{
			if(firstStrand[index] != secondStrand[index])
			{
				++count;
			}
			++index;
		}
		return count;
	}
}