# Turul Calului în Șah

    Acest program în C++ simulează problema Turului Calului pe o tablă de șah. Turul Calului este o problemă matematică în care obiectivul este ca calul să viziteze fiecare pătrat al tablei de șah exact o singură dată.

# Cum să Utilizați

1. Generare Tablă Inițială:
    Rulați programul și alegeți opțiunea 1 din meniu.
    Introduceți o dimensiune validă N pentru tabla de șah (condiții: N > 0, N != 2, N != 3, N != 4).
    Programul va afișa tabla de șah inițială.

2. Alegere Poziție Inițială:
    Alegeți opțiunea 2 din meniu.
    Introduceți poziția inițială (i, j) pentru cal pe tabla de șah (unde i și j sunt mai mici decât N).
    Programul va afișa tabla de șah cu poziția inițială a calului marcată cu 1.

3. Afișare Turului Calului:
    Alegeți opțiunea 3 din meniu.
    Programul va încerca să găsească o soluție pentru problema Turului Calului și va afișa tabla de șah cu mișcările calului.
4. Ieșire:
    Alegeți opțiunea 0 pentru a ieși din program.
# Funcții
1. generare()
    Generează tabla de șah inițială cu dimensiunile N x N.
2. pozitia(int i, int j)
    Permite utilizatorului să aleagă poziția inițială a calului pe tabla de șah.
3. verifica(int x, int y)
    Verifică dacă o poziție dată (x, y) reprezintă o mutare validă pentru cal.
4. solve(int x, int y, int movei)
    Încearcă recursiv să găsească o soluție pentru problema Turului Calului.
5. afisare()
    Afișează tabla de șah cu turul calului dacă se găsește o soluție.
6. main()
    Programul principal cu meniul interactiv care permite utilizatorului să genereze tabla inițială, să aleagă poziția inițială și să afișeze turul calului.
# Observații
    Programul folosește o abordare de tip backtracking pentru a găsi o soluție la problema Turului Calului.
    Meniul permite utilizatorului să interacționeze în mod interactiv pentru a efectua pașii de generare a tablei, alegere a poziției inițiale și afișare a soluției.







