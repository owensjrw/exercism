using System;

public class SpaceAge
{
	int seconds = 0;
	
    public SpaceAge(int seconds)
    {
		this.seconds = seconds;
    }

    public double OnEarth()
    {
		return (seconds / 31557600.00);
    }

    public double OnMercury()
    {
        return (seconds / (31557600.00 * 0.2408467));
    }

    public double OnVenus()
    {
        return (seconds / (31557600.00 * 0.61519726));
    }

    public double OnMars()
    {
        return (seconds / (31557600.00 * 1.8808158));
    }

    public double OnJupiter()
    {
        return (seconds / (31557600.00 * 11.862615));
    }

    public double OnSaturn()
    {
        return (seconds / (31557600.00 * 29.447498));
    }

    public double OnUranus()
    {
        return (seconds / (31557600.00 * 84.016846));
    }

    public double OnNeptune()
    {
        return (seconds / (31557600.00 * 164.79132));
    }
}