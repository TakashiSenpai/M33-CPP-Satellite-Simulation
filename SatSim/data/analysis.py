import matplotlib.pyplot as plt
import glob

files = glob.glob('*.csv')

for f in files:
    with open(f, "r") as file:
        lines = file.readlines()

    t = []
    x = []
    y = []
    z = []
    yMinusI = []
    zMinusI = []
    yPlusI = []
    zPlusI = []
    mode = []
    for i, line in enumerate(lines):
        values = line.split(',')
        t.append(i)
        x.append(float(values[0]))
        y.append(float(values[1]))
        z.append(float(values[2]))
        yMinusI.append(float(values[3]))
        yPlusI.append(float(values[4]))
        zMinusI.append(float(values[5]))
        zPlusI.append(float(values[6]))
        mode.append(int(values[7]))

    fig, ax_pos = plt.subplots()
    ax_pos.plot(t, x, label='x')
    ax_pos.plot(t, y, label='y')
    ax_pos.plot(t, z, label='z')
    ax_pos2 = ax_pos.twinx()
    ax_pos2.plot(t, mode, label='mode', c='C6')
    ax_pos2.set_ylim(-1, 2)
    ax_pos.set_xlabel('Steps')
    ax_pos.set_ylabel('Component magnitude')
    ax_pos.legend()
    plt.savefig(f.strip('.csv') + 'pos' +'.png', dpi=150, bbox_inches='tight')

    fig, ax_cur = plt.subplots()
    ax_cur.plot(t, yMinusI, label='-Y')
    ax_cur.plot(t, yPlusI, label='+Y')
    ax_cur.plot(t, zMinusI, label='-Z')
    ax_cur.plot(t, zPlusI, label='+Z')
    ax_cur2 = ax_cur.twinx()
    ax_cur2.plot(t, mode, label='mode', c='C6')
    ax_cur2.set_ylim(-1, 2)
    ax_cur.set_xlabel('Steps')
    ax_cur.set_ylabel('Current magnitude')
    ax_cur.legend()
    plt.savefig(f.strip('.csv') + 'cur' + '.png', dpi=150, bbox_inches='tight')

plt.show()

