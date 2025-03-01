import random

def tahmin_oyini():
    max_son = 100
    tasodifiy_son = random.randint(1, max_son)
    urinishlar = 0
    
    print(" Men 1 dan 100 gacha bir son o‘yladim. Uni topa olasanmi?")

    while True:
        try:
            taxmin = int(input(" Sonni kiriting: "))
            urinishlar += 1
            
            if taxmin < tasodifiy_son:
                print(" Men o‘ylagan son bundan kattaroq!")
            elif taxmin > tasodifiy_son:
                print(" Men o‘ylagan son bundan kichikroq!")
            else:
                print(f" Tabriklayman! To‘g‘ri topding!  ({urinishlar} urinishda)")
                break  
        except ValueError:
            print(" Iltimos, butun son kiriting!")

tahmin_oyini()

