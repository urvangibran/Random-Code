class Hero:
    def __init__(self, name, health, attPower, armorNumber):
        self.name = name
        self.health = health
        self.attPower = attPower
        self.armor = armorNumber
    
    def attack(self, target):
        print(f"""
            {self.name} menyerang {target.name} dengan attack {self.attPower}
            yang menyebabkan darah {target.name} berkurang dari {target.health}
            menjadi {target.health - self.attPower}
            """)
        target.diserang(self)

    def diserang(self, target):
        print(f"{self.name} diserang oleh {target.name}")

Nana = Hero("Nana", 1000, 40, 11)
Ling = Hero("Ling", 2200, 100, 40)

print(Nana.attack(Ling))