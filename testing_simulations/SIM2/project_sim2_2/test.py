import forward_euler_module # Import the module
import csv
import matplotlib.pyplot as plt


# Define the Lotka-Volterra system of differential equations
def lotka_volterra_system(t, values):
    alpha = 0.1  # Prey birth rate
    beta = 0.02  # Predation rate
    gamma = 0.3  # Predator death rate
    delta = 0.01 # Predator reproduction rate

    x, y = values
    dxdt = alpha * x - beta * x * y
    dydt = delta * x * y - gamma * y
    return [dxdt, dydt]

def main():
    initial_values = [40, 9]  # x0 = 40 (prey), y0 = 9 (predators)
    t0 = 0                    # Initial time
    tf = 200                  # Final time
    dt = 0.05                 # Timestep

    # Create an instance of ForwardEuler from the forward_euler_module
    solver = forward_euler_module.ForwardEuler(initial_values, t0, tf, dt, lotka_volterra_system)

    # Solve the system
    solver.solve()

    # Retrieve and save the solution in a csv file
    solution = solver.get_solution()
    with open('lotka_volterra_solution.csv', 'w') as file:
        file.write('prey,predator\n')
        for values in solution:
            file.write(','.join([str(value) for value in values]) + '\n')

    # load the data from csv file
    with open("lotka_volterra_solution.csv", "r") as f:
        reader = csv.reader(f)
        data = list(reader)[1:] # ignore the first row
        #convert data from string to float
        data = [[float(x) for x in row] for row in data]

    # plot the data
    plt.plot(data[0], data[1], label='prey')
    plt.plot(data[0], data[2], label='predator')
    plt.xlabel('time')
    plt.ylabel('population')
    plt.legend()
    plt.title('Lotka-Volterra model')
    plt.grid()
    plt.savefig('lotka_volterra_solution.png')
    plt.show()

if __name__ == "__main__":
    main()




# # Plot the result
# import matplotlib.pyplot as plt
# import numpy as np

# # load the data from csv file
# data = np.loadtxt('lotka_volterra_solution.csv', delimiter=',')

# # plot the data
# plt.plot(data[:,0], data[:,1], label='prey')
# plt.plot(data[:,0], data[:,2], label='predator')
# plt.xlabel('time')
# plt.ylabel('population')
# plt.legend()
# plt.title('Lotka-Volterra model')
# plt.grid()
# plt.savefig('lotka_volterra_solution.png')
# plt.show()

