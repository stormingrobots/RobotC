
// this sample will allow interface with either EV3 color sensor ONLY

const tSensors ColorEye = S2;
//tMotor LeftMotor= motorA;
//tMotor RightMotor= motorC;

//const int R=0, G=1, B=2;
enum enColor { R, G, B };

//================================
//****************
// the following getRGB is for students who know about pointers in C & reference in C++
//*****************

//================================

void setup()
{
	long r, g, b;
		SensorType[ColorEye] =  sensorEV3_Color;
		SensorMode[ColorEye] =  modeEV3Color_RGB_Raw;

  // important:  it requires to perform a few initial probes in order to ensure it
	// remains in the seame color mode
	time1[T1] = 0;
	while (time1[T1] <200)
	{
		getColorRGB(S1, r, g, b);
		sleep(5);
	}
}


//================================
task main()
{
	long rgb[4];
	setup();

	clearDebugStream();
	writeDebugStreamLine("R   G   B");
	displayBigTextLine(2, "R   G   B");

	while (true)
	{
		getColorRGB(ColorEye, rgb[0], rgb[1], rgb[2]);  // using C++ reference
		writeDebugStreamLine( "%3d, %3d, %3d.  G/R: %.2f.  G/B:%.2f ", rgb[0],rgb[1],rgb[2], rgb[G]/rgb[R], rgb[G]/rgb[B]);
		displayBigTextLine(6, "%3d %3d %3d",  rgb[R],rgb[G],rgb[B]);
		delay(10);
	}
}
