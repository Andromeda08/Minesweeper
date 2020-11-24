# Aknakereső Felhasználói Dokumentáció
> Ez az Aknakereső játék **macOS** és különböző **Linux** disztribúciók alatt fut.
### A játék célja
A játék célja az, hogy minden aknát megtaláljon a játékos a mezők felfedésével, amik a pályán véletlenszerűen vannak elhelyezve.
### A Főmenüben
- (1) Új játékot indíthatunk, a játékos megadhatja a pálya méretét és aknák számát.  
- (2) Kiléphetünk a játékból.
### A Játékmenet
A játék során két lépést tehet a játékos:
- (1) Egy adott mezőt felderíthet, ha az nem akna volt, automatikusan felfedi a környező nem akna mezőket.
- (2) Megjelölhet egy mezőt a játékos amit aknának gondol.

A lépését a játékosnak ebben a formátumban kell megadnia:
> \<x> \<y> \<cmd>  

(X koordináta, Y koordináta, Lépés fajtája)

### A Játék Vége
A játékos **nyert**, ha nincs már felfedezhető mező, **veszített**, ha olyan mezőt próbál felfedni ahol akna van.