#importazione del modulo project_sim2
import project_sim2
import matplotlib.pyplot as plt


# Funzione di decadimento esponenziale
def decay_function(t, y):
    k = 0.1
    return [-k * y[0]]


# Creazione e utilizzo dell'oggetto ForwardEuler1
decaysolver = project_sim2.ForwardEuler1(decay_function)
decaysolver.setInitialValue([5.0])
decaysolver.solve(0, 10, 0.1)

#stampa la soluzione a terminale - SCONSIGLIATO!
#print(decaysolver.getSolution())


# Funzione Lotka-Volterra
def lotka_volterra(t, y):
    alpha = 1.0
    beta = 0.1
    delta = 0.075
    gamma = 1.5
    return [alpha * y[0] - beta * y[0] * y[1], delta * y[0] * y[1] - gamma * y[1]]

#Creazione e utilizzo dell'oggetto ForwardEuler2 (Lotka Volterra)
lovolsolver = project_sim2.ForwardEuler2(lotka_volterra)
lovolsolver.setInitialValue([40, 9])
lovolsolver.solve(0, 10, 0.1)
#stampo la soluzione A TERMINALE - SCONSIGLIATO!
#print(lovolsolver.getSolution())

#Creo un ciclo for per stampare la soluzione in un file di testo

with open('results.txt', 'w') as file:
    for point in decaysolver.getSolution():
        file.write(f"Decadimento esponenziale, y = {point[0]}\n")

    file.write("\n\n")

    for point in lovolsolver.getSolution():
        file.write(f"Lotka-Volterra, Prede: {point[0]}, Predatori: {point[1]}\n")

#Stampo a terminale il percorso del file
print("Il file è stato scritto in: ", file.name)

#Avviso finale
print("!!! ATTENZIONE !!! : \n!!!!!!!!!!\n")
print("RINOMINA IL FILE PER SALVARE I RISULTATI PRIMA DI RILANCIARE IL PROGRAMMA")
print("ALTRIMENTI I RISULTATI VERRANNO SOVRASCRITTI\n")



# Funzione di visualizzazione
def plot_simulation(time, values, title, xlabel, ylabel, legend):
    for i, value_series in enumerate(values):
        if isinstance(value_series[0], float):  # Controlla se il primo elemento è un float
            y_values = value_series
        else:
            y_values = [value[0] for value in value_series]  # Assumendo che ogni 'value' sia un array con un singolo elemento
        plt.plot(time, y_values, label=legend[i])
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend()
    plt.grid(True)
    plt.savefig(title)
    plt.close()
    #plt.show() # Scommentare questa riga per visualizzare i grafici in una finestra separata
    #Dove si possono effettuare modifiche di visualizzazione e salvataggio
    

# Preparazione dei dati per il tracciamento
time = [i * 0.1 for i in range(int(10 / 0.1) + 1)] # questo è un modo per creare una lista di valori da 0 a 10 con passo 0.1
decay_values = [point[0] for point in decaysolver.getSolution()] #decay values è una lista di y per decadiemnto esponenziale
prey_values = [point[0] for point in lovolsolver.getSolution()] #prey values è una lista di valori di y per le prede
predator_values = [point[1] for point in lovolsolver.getSolution()] # predator values è una lista di valori di y per i predatori

# Tracciamento delle funzioni
#Questi due grafici vengono plottati in due finestre diverse
plot_simulation(time, [decay_values], "Decay Function", "Time", "Value", ["Decay"])
plot_simulation(time, [prey_values, predator_values], "Lotka-Volterra", "Time", "Population", ["Prey", "Predators"])


print("I grafici sono stati salvati come immagini png con i seguenti nomi:")
print("Decay Function.png")
print("Lotka-Volterra.png")
print("Nelle cartelle di lavoro correnti")

#Fine del programma