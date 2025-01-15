package SatSim;

import java.util.Properties;



//SimTG specific import
import simtg.simops.base.Simops;
import simtg.simops.base.SimopsException;
import simtg.simops.base.SimopsTest;
import simtg.simops.plugin.kernel.KernelSeqPlugin;
import simtg.simops.plugin.sys.SysSeqPlugin;

public abstract class BaseTest extends SimopsTest {
	
	/** A System plugin: I/F with the system */
	public final SysSeqPlugin sys;

	/** A Kernel plugin: I/F with the kernel */
	public final KernelSeqPlugin sim;
	
	/**
	* Ctor of ExampleTest class
	* @throws SimopsException
	*/
	public BaseTest() {
		
		/* Set Simops properties */
		Properties p = new Properties();
		p.setProperty("simtg.simops.activators", "simtg.simops.plugin.sys.SysActivator simtg.simops.plugin.kernel.KernelActivator");
		p.setProperty("simtg.simops.plugin.sys.ids", "sys");
		p.setProperty("simtg.simops.plugin.kernel.ids", "sim");
		p.setProperty("simtg.simops.plugin.kernel.sim.sys", "sys");
		try {
			Simops.start(p);
		} catch (SimopsException e) {
			e.printStackTrace();
		}
		
		/* Create plugins */
		sys = new SysSeqPlugin("sys");
		sim = new KernelSeqPlugin("sim", sys);
	}
	
	/**
	 * Override this to perform the test.
	 * @throws SimopsException		Error case.
	 */
	protected abstract void test() throws SimopsException;
	
	@Override
	public void sequence() throws SimopsException {
		System.out.println("DEBUG: " + this.getClass().getSimpleName());
		//sim.run(this.getClass().getSimpleName());
		sim.run("simtg");
		test();
		sim.disconnect();
	}

	/**
	 * Pause the test for time ms.
	 * @param time		Pause time (in ms).
	 */
	protected void pause(long time) {
		try {
			Thread.sleep(1000000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}		
	}
	
}
