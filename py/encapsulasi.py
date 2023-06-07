class Hero:
    __jumlah = 0

    def __init__(self, name, health, attPower, armorNumber):
        self.__name = name
        self.__health = health
        self.__attPower = attPower
        self.__armor = armorNumber
        Hero.__jumlah += 1
    
    def getName(self):
        return self.__name

    def getJumlah():
        return Hero.__jumlah

Ling = Hero("Ling", 2200, 100, 30)
Nana = Hero("Nana", 2200, 100, 30)
Alu = Hero("Alu", 2200, 100, 30)
Cho = Hero("Cho", 2200, 100, 30)

# Ling.__name = "Nanaa"
# print(Ling.getName()) 
# print(Ling.__dict__) 
print(Hero.getJumlah())