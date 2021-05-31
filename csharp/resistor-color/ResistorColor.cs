using System;

public static class ResistorColor
{
	static string[] colors = new string[10]{"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
	
    public static int ColorCode(string color)
    {
		int index = Array.IndexOf(colors, color);
		return index;
    }

    public static string[] Colors()
    {
        return colors;
    }
}