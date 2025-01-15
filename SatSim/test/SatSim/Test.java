package SatSim;

import simtg.simops.base.SimopsException;

public class Test extends BaseTest {

	public static void main(String[] args) {
		new Test().run();
	}

	protected void test() throws SimopsException {
		sim.createObject("SatSim", "Satellite", "o");
		
		float sunPos[] = {(float)0.414, (float)0.414, (float)0};
		
		sim.writeFloatArray("o.In.input_sunDirection", sunPos);
		sim.timeStep(1);
		float out[] = sim.readFloatArray("o.Out.out_measuredCurrents");		
		System.out.printf("%f %f %f %f\n", out[0], out[1], out[2], out[3]);
		System.out.println("Success!");
	}
}
