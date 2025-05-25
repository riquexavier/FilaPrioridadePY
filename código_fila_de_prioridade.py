import heapq

lista = [(-18, "Fulano da Silva"), (-26, "Ciclano dos Santos"), (-47, "Beltrano Carvalho")]

heapq.heapify(lista)

qnt = int(input("Numero de pacientes: "))

for i in range(qnt):
    nome = input("Nome do paciente: ")
    idade = int(input("Idade do paciente: "))
    heapq.heappush(lista, (-idade, nome))

print("\nLista de priodidade: \n")

while lista:
    idade, nome = heapq.heappop(lista)
    print(f"{nome}")