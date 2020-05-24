# Double Linked Lists
Polynomials will be represented by lists of monomials. The following structure (see the monome.h file) is provided to represent a monome:

```
#define MONOME_DEGRE_TYPE unsigned int
typedef MONOME_DEGRE_TYPE monome_degre_type;
#define MONOME_COEFFICIENT_TYPE double
typedef MONOME_COEFFICIENT_TYPE monome_coefficient_type;
struct monome
{
	/** \brief Degré du monome. */
	monome_degre_type degre;
	/** \brief Coefficient du monome. */
	monome_coefficient_type coefficient;
};
typedef struct monome monome;
```

The following functions (see the monome.h file) are also provided to manipulate these:

```
monome monome_addition(monome, monome);
monome monome_multiplication(monome, monome);
int monome_fscan(FILE*, monome*);
int monome_fprint(FILE*, monome);
int monome_sscan(const char*, monome*);
```

### Implementation of doubly chained lists
Double-linked lists allow a two-way travel from any link in the chain. All other links can then be found from a pointer to any link in the list.

For this purpose, each link must be aware, if they exist, of its predecessor and its successor. The proposed structure is as follows:

```
struct liste
{
	/** \brief Terme. */
	monome terme;
	/** \brief Élément suivant dans la liste. */
	struct liste* suivant;
	/** \brief Élément précédent dans la liste. */
	struct liste* precedent;
};

```

#### Doubly Linked List Operations

```
liste* liste_vide(void);
liste* liste_inserer(liste* l, monome t);
liste* liste_supprimer(liste* l);
void liste_free(liste* l);
monome liste_monome(const liste* l);
liste* liste_suivant(const liste* l);
liste* liste_precedent(const liste* l);
bool liste_est_vide(const liste* l);
bool liste_est_debut(const liste* l);
liste* liste_debut(const liste* l);
liste* liste_ieme(const liste* l, size_t i);
size_t liste_longueur(const liste* l);
```

### Additional Operations
The lists as described in the previous exercise may contain any number of monomers.
in an undetermined order. To facilitate the manipulation of polynomials, it is preferable to "normalize" these lists:
- the list must contain 0 or 1 monome for a given degree d.
- the monomes must be ordered in descending order of degrees.

Implement this normalization in the list_normalize() function. 
To perform this normalization, we need to move monomials within the list.
It is strongly advised to create an intermediate function list_change()
which will be in charge of exchanging the monomial contained in a link 
with the monomial contained in the next link. Don't forget to add the 
monomials of the same degree.


```
liste* liste_echanger(liste* l);
// Échange le monôme avec le suivant.
liste* liste_normaliser(liste* l); // Normalise une liste de monômes.
```
Tip: another way to see liste_normaliser() is to decompose it. This is :
- sort the monomials by descending degrees
- merge monomers of the same degree (add up the coefficients)


# Polynomial Implementation
Once "normalized", a list of monomials can be considered as a polynomial:

```
typedef liste polynome;
polynome* polynome_addition(const polynome* p1, const polynome* p2);
polynome* polynome_multiplication(const polynome* p1, const polynome* p2);
polynome* polynome_derivee(const polynome* p1);
```



# Usage

```
$ ./polynomes
P1(X) = 1.1*x^1 + 3.3*x^3 + 2.2*x^2
P2(X) = 1*x^1 + 4*x^4 + -2*x^2 + 1*x^1 + 1*x^1
P1(X) = 3.30*X^3 + 2.20*X^2 + 1.10*X^1
P2(X) = 4.00*X^4 + -2.00*X^2 + 3.00*X^1
P1 + P2 = 4.00*X^4 + 3.30*X^3 + 0.20*X^2 + 4.10*X^1
P1 * P2 = 13.20*X^7 + 8.80*X^6 + -2.20*X^5 + 5.50*X^4 + 4.40*X^3 + 3.30*X^2
P1'(X) = 9.90*X^2 + 4.40*X^1 + 1.10
P2'(X) = 16.00*X^3 + -4.00*X^1 + 3.0
```


```
$ ./polynomes <tests/X.txt
$ ./polynomes <tests/X.txt >resultat
$ diff results/X.txt resultat
```
