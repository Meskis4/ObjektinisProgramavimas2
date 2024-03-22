![33](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/56a20c52-6a91-48ea-ae9a-482b52ad5ed6)# ObjektinisProgramavimas 

# v0.4

# 1 Tyrimas 
![Screenshot 2024-03-08 181802](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/b10fee62-70a7-448a-b8b2-e9b07fc53108)

# 2 Tyrimas

![Screenshot 2024-03-08 192520](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/771d97bb-6104-438f-95cd-15fbc39244c0)

![Screenshot 2024-03-08 191511](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/0a8fb722-8b81-4f3e-bfb7-ab981e90d3ec)


# v1.0

**Sistemos parametrai:** 
* CPU: AMD Ryzen 7 5800H, 3201 Mhz, 8 Cores
* RAM: 32GB DDR4-3200 dual channel
* Storage: 1TB M.2 NVME M.2 SSD

**1 strategija (Vector)**

![Screenshot 2024-03-20 141750](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/bcb5800a-ebad-4099-b465-33518363a459)

**1 strategija (List)**

![Screenshot 2024-03-20 144559](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/c9df7161-381b-405e-b01e-c39f012c2948)

**1 strategija (Deque)**

![Screenshot 2024-03-20 150809](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/63dc06e3-b9e8-4f57-b821-85bef05a3392)

Atlikus tyrimą su pirmąja strategija, pastebėjau, kad naudojant std::vector konteinerius, rezultatai buvo beveik dvigubai greitesni. 

**2 strategija (Vector)**

2 Strategijos nepavyko pilnai įgyvendinti naudojant std::vector konteinerius, kadangi bandant padalinti 1000000 studentų į 2 grupes nepavyko sulaukti rezultato, net laukiant virš 30 min.

     
![vector2,1](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/ecb889cd-9bde-4f51-843b-c11175ce5ece)
![vector2](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/49ee24cb-51c6-4293-8ece-3775227b436e)

**2 strategija (List)**

![list2 1](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/7b7f5450-1d71-4f83-b8a0-be9ba7e95fc1)
![List2](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/a2b49b95-df86-4a3d-a4cb-f891827d72cf)

**2 strategija (Deque)**

![Screenshot 2024-03-22 151758](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/9c8ca290-5418-4ed7-a9d5-309cfbbe2fa6)

![Screenshot 2024-03-22 151823](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/f3c8bebc-4237-4134-9f2b-65cfdb501879)

Išvada: naudojant 2 strategiją su std::vector konteineriais nepavyko gauti tyrimų rezultų, todėl manau, kad ši strategija yra netinkama naudoti su std::vector konteineriais be tam tikrų algoritmų, kurie padeda optimizuoti elementų trynimą iš std::vector konteinerių. O naudojant std::list ir std::deque konteinerius, rezultatai yra panašūs į 1 strategijos rezultatus. Tačiau 2 strategijos paskirstymas į grupes yra spartesnis. 


  **3 strategija (Vector)**

    
  Panaudojus std::find_if algoritmą pavyko paspartinti programą.
  
  ![3333](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/0dc17d2c-39a3-4b51-917a-1c6f8b988ade)


  ![3](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/fc6e254b-9fee-493b-8990-9cf3d9cc92c3)

**Visų tyrimų rezultatai**

![333333](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/98f2574f-27e4-4a6b-87cc-e89add38f129)



  








