from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

data = np.loadtxt("wave1DOutput.dat", skiprows = 4)
dataSplited = np.split(data,[0,1])
x = dataSplited[1]
y = dataSplited[2:]
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(0, 120))
line, = ax.plot([], [], lw=3)


def init(): 
	# creating an empty plot/frame 
	line.set_data([], []) 
	return line, 

def animate(i):
    xData = x
    yData = y[0][i]

    line.set_data(xData, yData)

    return line,

# setting a title for the plot 
plt.title('Onde 1D') 
# hiding the axis details 
plt.axis('on') 

# call the animator	 
anim = FuncAnimation(fig, animate, init_func=init, 
							frames=600, interval=100, blit=True) 

# save the animation as mp4 video file 
anim.save('wave.gif') 