
// this sample will allow interface with either EV3 or NXT color sensor
// using a user-define color array

const tSensors colorLink = S2;
//tMotor LeftMotor= motorA;
//tMotor RightMotor= motorC;

enum enColor { R, G, B };

//================================
//****************
// the following getRGB is for students who know about pointers in C & reference in C++
//*****************


void readRGB(tSensors link, short *s)
{
#ifdef EV3
	getColorRGB(link, (long)s[R], (long)s[B], (long)s[B]);
#else
	getColorSensorData(link, colorRaw, s);
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
	short myEye[] = {0,0,0};

	setup(colorLink);

	clearDebugStream();
	writeDebugStreamLine("R   G   B");
	displayBigTextLine(2, "R   G   B");

	while (true)
	{
		readRGB(colorLink, myEye);

		writeDebugStreamLine( "%3d, %3d, %3d. G/R = %.2f.  G/B = %.2f ",
				myEye[R], myEye[G], myEye[B], myEye[G]/myEye[R], myEye[G]/myEye[B] );
		displayBigTextLine(6, "%3d %3d %3d",  myEye[R], myEye[G], myEye[B] );
		delay(10);
	}
}
