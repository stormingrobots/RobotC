
// this sample will allow interface with either NXT color sensor  ONLY

const tSensors ColorEye = S2;
//tMotor LeftMotor= motorA;
//tMotor RightMotor= motorC;

//const int R=0, G=1, B=2;
enum enColor { R, G, B };

//================================
task main()
{
	short rgb[4];

	clearDebugStream();
	writeDebugStreamLine("R   G   B");
	displayBigTextLine(2, "R   G   B");

	SensorType[ColorEye] = sensorColorNxtFULL;
	while (true)
	{
		getColorSensorData(ColorEye, colorRaw, rgb);
		writeDebugStreamLine( "%3d, %3d, %3d.  G/R: %.2f.  G/B:%.2f ", rgb[0],rgb[1],rgb[2], rgb[G]/rgb[R], rgb[G]/rgb[B]);
		displayBigTextLine(6, "%3d %3d %3d",  rgb[R],rgb[G],rgb[B]);
		delay(10);
	}
}
