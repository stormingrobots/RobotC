
// this sample will allow interface with either EV3 or NXT color sensor
// using a user-define color structure

const tSensors ColorEye = S2;
//tMotor LeftMotor= motorA;
//tMotor RightMotor= motorC;

typedef struct {
	short r;
	short g;
	short b;
} myColor ;

//================================
//****************
// the following getRGB is for students who know about pointers in C & reference in C++
//*****************



void readRGB(tSensors link, myColor *s)
{

#ifdef EV3
	getColorRGB(link, (long)(s->r), (long)(s->g), (long)(s->b));
#else

short rgb[4];
	getColorSensorData(link, colorRaw, rgb);
	s->r = rgb[0];
	s->g = rgb[1];
	s->b = rgb[2];
#endif

}

#ifdef EV3
void setup(tSensors p)
{
	long r, g, b;
		SensorType[p] =  sensorEV3_Color;
		SensorMode[p] =  modeEV3Color_RGB_Raw;

  // important:  it requires to perform a few initial probes in order to ensure it
	// remains in the seame color mode
	time1[T1] = 0;
	while (time1[T1] <200)
	{
		getColorRGB(S1, r, g, b);
		sleep(5);
	}
}
#else

#define setup(p)     	SensorType[p] = sensorColorNxtFULL

#endif


//================================
task main()
{
	myColor s;
	setup(ColorEye);

	clearDebugStream();
	writeDebugStreamLine("R   G   B");
	displayBigTextLine(2, "R   G   B");

	while (true)
	{
		readRGB(ColorEye, &s);

		writeDebugStreamLine( "%3d, %3d, %3d. G/R = %.2f.  G/B = %.2f ", s.r,s.g, s.b, s.g/s.r, s.g/s.b );
		displayBigTextLine(6, "%3d %3d %3d",  s.r, s.g, s.b);
		delay(10);
	}
}
