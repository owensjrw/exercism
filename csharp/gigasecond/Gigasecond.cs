using System;

public static class Gigasecond
{
    public static DateTime Add(DateTime moment)
	{
		TimeSpan aGigasecond = new System.TimeSpan(0,0,0,1000000000);
		return moment.Add(aGigasecond);
	}
}