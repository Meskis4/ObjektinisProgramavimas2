# ObjektinisProgramavimas 

 # v.pradinė
 
 Tai pradinė programos versija
1. Programa suskaičiuoja galutinį studento balą naudojant egzamino įvertinimą bei pažymių vidurkį / medianą. 
2. Naudojamos **iostream**, **iomanip** ir **algorithm** bibliotekos.

# v0.1
Tai patobulinta v.pradinė versija.
1. Programa leidžia vartotojui pasirinkti, kokiu būdu užpildyti duomenis apie studentą (Rankiniu / Pažymiu generavimas / Vardo, pavardės bei pažymių generavimas)
2. Vietoj masyvų naudojami vektoriai, todėl vartotojas pats gali nuspręsti, kelių studentų informaciją įrašys.
3. Pridėti apribojimai, kurie neleidžia įvesti klaidingų duomenų.
4. Pridėtos **vector**, **random**, **cctype** ir **string** bibliotekos.

# v0.2

Tai patobulinta v0.1 versija.

1. Programa suteikia galimybę nuskaityti duomenis apie studentą iš failo.
2. Pridėta galimybė surūšiuoti rezultatus, pagal vardą, pavardę, galutinį balą.
3. Pasirinkus duomenų skaitymą iš failo, programos pabaigoje yra atspausdinamas skaitymo laikas, spausdinimo laikas.
4. Pridėtos **fstream**, **sstream**, **ctime** bibliotekos.

   # v0.3

Tai patobulinta v0.2 versija.

1. Programa yra padalinta į atskirus failus: *Vektorius.cpp*, *Studentai.h*, *Funkcijos.h*, *Funkcijos.cpp*.
2. Programoje pridėtos funkcijos, kurios patikrina ar įvesti tik sveikieji skaičiai kur jų reikia. Taip pat patikrina ar vedant vardą bei pavardę yra įvedamos tik raidės. 
3. Dabar failo pavadinimą iš kurio nori nuskaityti duomenis įveda vartotojas. Yra aprašyta funckija, kuri patikrina ar failas egzistuoja, jei ne - prašoma įvesti failo pavadinimą iš naujo.

# v0.4
Tai patobulinta v0.3 versija.

1. Pridėtas failų generatorius, kuris sugeneruoja 5, įvairių dydžių failus.
2. Kiekvienas failas pagal studentų galutinį balą yra paskirstomas į gerus bei blogus studentus.
3. Yra fiksuojamas failo generavimo, skaitymo, paskirstymo į grupes, rūšiavimo, paskirstytų grupių surašymas į failus bei bendras laikas.
4. Pridėta **chrono** biblioteka.

Buvo atlikti tyrimai, norint nustatyti failo generavimo, skaitymo, paskirstymo į grupes, rūšiavimo bei paskirstytų grupių surašymo į failus bendras laikas.

# 1 Tyrimas (Failo generavimas)
![Screenshot 2024-03-08 181802](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/b10fee62-70a7-448a-b8b2-e9b07fc53108)

# 2 Tyrimas (Failo apdorojimas)

![Screenshot 2024-03-08 192520](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/771d97bb-6104-438f-95cd-15fbc39244c0)

![Screenshot 2024-03-08 191511](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/0a8fb722-8b81-4f3e-bfb7-ab981e90d3ec)


# v1.0

Tai patobulinta v0.4 versija.

1) Programa realizuota ne tik naudojant std::vector, tačiau sukurti ir 2 nauji failai, kuriuose naudojami std::list bei std::deque konteineriai.
2) Yra atliekami tyrimai norint nustatyti programos spartą su skirtingais konteineriais.
3) Naudojamos 3 skirtingos strategijos: 1 -> Studentų skaidymas į du naujus konteinerius. 2 -> Skaidymas sukuriant naują konteineri, o perkelti studentai ištrinami iš bendro konteinerio. 3 -> Optimizuota 2 strategija naudojnat std::vector konteinerius bei panaudojus std::find_if algoritmą.

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

Atlikus tyrimą su pirmąja strategija, pastebėjau, kad naudojant std::vector konteinerius, rezultatai buvo greitesni. 

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

   **3 strategija (List)**

![list33](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/b4a1f48d-b375-4113-a6b1-9c214ebaa679)

![list3](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/d3b71f05-07f0-4d90-9ca9-bcdce07d27a0)

**3 strategija (Deque)**

Nepavyko pasiekti spartesnių rezultatų už 2 strategijos rezultatus.




**Visų tyrimų rezultatai**

![Strategijos](https://github.com/Meskis4/ObjektinisProgramavimas/assets/147125301/e4ef8f5f-8657-4b7a-865f-2706edc53db5)


# v1.1

Šioje versijoje struktūra "Studentas" yra pakeičiama į klasę.
Ištestuota programų sparta (naudojant struktūrą bei klasę), naudojant skirtingus optimizavimo flag'us. Nuskaitomi failai buvo vienodi, juose buvo 100000 bei 1000000 studentų duomenys. Gauti rezultatai yra pateikti lentelėje.


![Screenshot 2024-04-12 103951](https://github.com/Meskis4/ObjektinisProgramavimas2/assets/147125301/31d6c363-f40d-40d6-ad44-dd254a3b7d79)

# v1.2

Šioje versijoje pridėjau copy bei move konstruktorius, taip pat jų priskyrimo operatorius. 

![Copy_Const](https://github.com/Meskis4/ObjektinisProgramavimas2/assets/147125301/42b88d0f-0a18-4dd0-bc18-4bbb69e7e3f2)

![move_const](https://github.com/Meskis4/ObjektinisProgramavimas2/assets/147125301/9e889d92-25f7-4181-944f-9f0c9d65d172)

# v1.5

Šioje versijoje pridėta bazinė klasė Žmogus. Naudojant ją nėra galimybės sukurti naujo objekto: 

![Zmogus](https://github.com/Meskis4/ObjektinisProgramavimas2/assets/147125301/00c5e7e0-3868-49eb-80c3-040a7d54aca5)

Taip pat perdaryti konstruktoriai bei priskyrimo operatoriai, kad veiktų pridėjus bazinę klasę "Zmogus": 

![Screenshot 2024-04-19 222840](https://github.com/Meskis4/ObjektinisProgramavimas2/assets/147125301/10af124d-6b2c-44be-a825-2468091623cb)

# v2.0

Šioje versijoje pridėta "Doxygen" dokumentacija, klasėms "Studentas" bei "Zmogus". Dokumentacija yra pateikiama HTML bei TeX kalbomis.



# Naudojimo instrukcija
1) Atsisiųskite .zip failą.
2) Atsidarykite norimos versijos: std::vector, std::list, std::deque aplanką.
3) Paleiskite run.bat failą (turite turėti savo sistemoje instaliuotą CMAKE).
4) Paleidus programą būsite paprašyti pasirinkti duomenų užpildymo būdą.
5) Pasirinkite kaip norite surūšiuoti rezultatus.
6) Pasirinkite galutinio balo skaičiavimo metodą.
7) Įveskite tai ko prašo programa (priklauso nuo pasirinkto duomenų užpildymo būdo)
8) Gausite rezultatus ( jei pasirinkote generuoti failus, jie bus sugeneruoti "Debug" aplanke )

# Dokumentacijos atidarymas  
HTML: 
1) Atidarykite katalogą "Dokumentacija".
2) Atidarykite katalogą "html"
3) Atidarykite failą "index.html"










