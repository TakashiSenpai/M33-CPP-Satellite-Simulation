package SatSim;

import simtg.simops.base.SimopsException;

public class Test extends BaseTest {

	public static void main(String[] args) {
		new Test().run();
	}

	protected void test() throws SimopsException {
		sim.createObject("SatSim", "Satellite", "o");
		
		float sunPos[] = {(float)0, (float)1, (float)0};
		
		sim.writeFloatArray("o.In.input_sunDirection", sunPos);
		sim.timeStep(1);
		float out[] = sim.readFloatArray("o.Out.out_measuredCurrents");	
		float out2[] = sim.readFloatArray("o.Out.out_cssSunDirection");
		float az = sim.readFloat("o.Out.out_azimuth");
		float el = sim.readFloat("o.Out.out_elevation");
		float k[] = sim.readFloatArray("o.Out.out_test");
		System.out.printf("%f %f %f %f\n", out[0], out[1], out[2], out[3]);
		System.out.printf("%f %f %f\n", out2[0], out2[1], out2[2]);
		System.out.printf("az %f, el %f\n", az, el);
		System.out.printf("%f, %f\n", k[0], k[39]);
		System.out.println("Success!");
	}
}
