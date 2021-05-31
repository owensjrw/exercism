using System;
using System.Collections.Generic;
using System.Linq;

public class HighScores
{	
	public List<int> HighScoresList = new List<int>();
	
    public HighScores(List<int> list)
    {
		HighScoresList = list;
    }
   
	public List<int> Scores()
    {
        return HighScoresList;
    }

    public int Latest()
    {
        return HighScoresList[(HighScoresList.Count - 1)];
    }

    public int PersonalBest()
    {
		HighScoresList.Sort();
		HighScoresList.Reverse();
		return HighScoresList[0];
    }

    public List<int> PersonalTopThree()
    {
		HighScoresList.Sort();
		HighScoresList.Reverse();
		List<int> TopThree = new List<int>();

		foreach(int num in HighScoresList)
		{
			TopThree.Add(num);
		}

		if(TopThree.Count > 3)
		{
			TopThree.RemoveRange(3, (TopThree.Count - 3));
		}
		return TopThree;
    }
}