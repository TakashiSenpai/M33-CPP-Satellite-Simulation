package SatSim;

import simtg.simops.base.SimopsException;

public class Test extends BaseTest {

	public static void main(String[] args) {
		new Test().run();
	}

	protected void test() throws SimopsException {
		
		float sunPos[] = {(float)-1, (float)0, (float)-1};
		double norm = Math.sqrt(Math.pow(sunPos[0], 2) + Math.pow(sunPos[1], 2) + Math.pow(sunPos[2], 2));
		sunPos[0] /= (float) norm;
		sunPos[1] /= (float) norm;
		sunPos[2] /= (float) norm;
		
		String sat = "o";
		sim.createObject("SatSim", "Satellite", "o");
		sim.writeFloatArray("o.In.initialSunDirection", sunPos);
		
		//sim.init();
		//sim.createResSampler(1, 0.1, "sampler");
		//sim.addToSampler("sampler", "o.Out.out_measuredCurrents");
		//sim.openResSampler("sampler", "testSamples.res", true);
		
		//sim.init();
		sim.activateMethodCyclically(sat + ".step", 1);
		

		for (int i=0; i<10; i++){
			sim.timeStep(1);
		}

		//sim.closeSampler("sampler");
		
		//float out[] = sim.readFloatArray("o.Out.out_measuredCurrents");	
		//float out2[] = sim.readFloatArray("o.Out.out_cssSunDirection");
		//float az = sim.readFloat("o.Out.out_azimuth");
		//float el = sim.readFloat("o.Out.out_elevation");
		//float k[] = sim.readFloatArray("o.Out.out_test");
		//System.out.printf("%f %f %f %f\n", out[0], out[1], out[2], out[3]);
		//System.out.printf("%f %f %f\n", out2[0], out2[1], out2[2]);
		//System.out.printf("az %f, el %f\n", az, el);	
		//System.out.printf("%f, %f, %f, %f\n", k[0], k[1], k[2], k[3]);
		
		System.out.println("Success!");
	}
}
