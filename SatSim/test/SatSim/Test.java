package SatSim;

import simtg.simops.base.SimopsException;

public class Test extends BaseTest {

	public static void main(String[] args) {
		new Test().run();
	}

	protected void test() throws SimopsException {
		
		/*
		 * Create Satellite Object in the simulation
		 */
		String project = "SatSim";
		String objClass = "Satellite";
		String objName = "sat";
		sim.createObject(project, objClass, objName);
		
		/*
		 * Generate initial sun position
		 */
		float sunPos[] = {(float)1, (float)0, (float)-1};
		double norm = Math.sqrt(Math.pow(sunPos[0], 2) + Math.pow(sunPos[1], 2) + Math.pow(sunPos[2], 2));
		sunPos[0] /= (float) norm;
		sunPos[1] /= (float) norm;
		sunPos[2] /= (float) norm;
		
		/*
		 * Initialize simulation
		 */		
		sim.writeFloatArray(objName + ".In.in_sunDirection", sunPos);
		sim.init();
		
		/*
		 * Simulation loop
		 */		
		float outSunPos[];
		float measuredCurrents[] = {0,0,0,0};
		float baffleCoefficients[] = {0, 0, 0, 0};
		float cssSunDir[];
		float sunAz, sunEl;
		int sector;
		float normalVector[][] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
		float controlSignal[];
		
		// Check initialization
		System.out.println("\nInitial parameters:");
		normalVector[0] = sim.readFloatArray(objName + ".SunSensor.Cell_PlusY.State.normalVector");
		normalVector[1] = sim.readFloatArray(objName + ".SunSensor.Cell_MinusY.State.normalVector");
		normalVector[2] = sim.readFloatArray(objName + ".SunSensor.Cell_PlusZ.State.normalVector");
		normalVector[3] = sim.readFloatArray(objName + ".SunSensor.Cell_MinusZ.State.normalVector");
		System.out.printf("Cell_+Y normal vector: %f, %f, %f\n", normalVector[0][0], normalVector[0][1], normalVector[0][2]);
		System.out.printf("Cell_-Y normal vector: %f, %f, %f\n", normalVector[1][0], normalVector[1][1], normalVector[1][2]);
		System.out.printf("Cell_+Z normal vector: %f, %f, %f\n", normalVector[2][0], normalVector[2][1], normalVector[2][2]);
		System.out.printf("Cell_-Z normal vector: %f, %f, %f\n", normalVector[3][0], normalVector[3][1], normalVector[3][2]);
		
		int nSteps = 5;
		for (int i=0; i<nSteps; i++){
			System.out.println("\nStep " + i);
			sim.step();
			
			// retrieve values from the simulation
			outSunPos = sim.readFloatArray(objName + ".Out.out_sunDirection");
			cssSunDir = sim.readFloatArray(objName + ".SunSensor.Orientation.Out.out_cssSunDirection");
			sunAz = sim.readFloat(objName + ".SunSensor.Orientation.Out.out_sunAz");
			sunEl = sim.readFloat(objName + ".SunSensor.Orientation.Out.out_sunEl");
			sector = sim.readInt(objName + ".SunSensor.Baffle.State.sector");
			
			measuredCurrents[0] = sim.readFloat(objName + ".SunSensor.Cell_PlusY.Out.out_measuredCurrent");
			measuredCurrents[1] = sim.readFloat(objName + ".SunSensor.Cell_MinusY.Out.out_measuredCurrent");
			measuredCurrents[2] = sim.readFloat(objName + ".SunSensor.Cell_PlusZ.Out.out_measuredCurrent");
			measuredCurrents[3] = sim.readFloat(objName + ".SunSensor.Cell_MinusZ.Out.out_measuredCurrent");
			
			baffleCoefficients[0] = sim.readFloat(objName + ".SunSensor.Baffle.Out.out_baffleCoefficientPlusY");
			baffleCoefficients[1] = sim.readFloat(objName + ".SunSensor.Baffle.Out.out_baffleCoefficientMinusY");
			baffleCoefficients[2] = sim.readFloat(objName + ".SunSensor.Baffle.Out.out_baffleCoefficientPlusZ");
			baffleCoefficients[3] = sim.readFloat(objName + ".SunSensor.Baffle.Out.out_baffleCoefficientMinusZ");
			
			controlSignal = sim.readFloatArray(objName + ".SunSensor.Out.out_controlSignal");
			
			System.out.printf("SAT Sun direction: %f, %f, %f\n", outSunPos[0], outSunPos[1], outSunPos[2]);
			System.out.printf("CSS Sun direction: %f, %f, %f\n", cssSunDir[0], cssSunDir[1], cssSunDir[2]);
			System.out.printf("Sun Azimuth: %f deg, Elevation: %f deg\n", sunAz*180/Math.PI, sunEl*180/Math.PI);
			System.out.printf("Out measured currents: +Y = %f, -Y = %f, +Z = %f, -Z = %f\n", measuredCurrents[0], measuredCurrents[1], measuredCurrents[2], measuredCurrents[3]);
			System.out.printf("Baffle sector: %d\n", sector);
			System.out.printf("Baffle coefficients: %f, %f, %f, %f\n", baffleCoefficients[0], baffleCoefficients[1], baffleCoefficients[2], baffleCoefficients[3]);
			System.out.printf("Control signal Y: %f, Z: %f\n", controlSignal[0], controlSignal[1]);
			
			// update the Sun's position for the next step
			sim.writeFloatArray(objName + ".In.in_sunDirection", outSunPos); 
		}
		
		System.out.println("\nTest finished");
	}
}