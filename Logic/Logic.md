# Logic

> Computational Thinking



* p &or; q

|  p   |  q   | p &or; q |
| :--: | :--: | :------: |
|  T   |  T   |    T     |
|  T   |  F   |    T     |
|  F   |  T   |    T     |
|  F   |  F   |    F     |



* p &and; q

|  p   |  q   | p &and; q |
| :--: | :--: | :-------: |
|  T   |  T   |     T     |
|  T   |  F   |     F     |
|  F   |  T   |     F     |
|  F   |  F   |     F     |



- p &oplus; q ≡ (p &or; q) &and; &not;(p &and; q) ≡ (p &and; &not;q) &or; (&not;p &and; q)
  - majority

|  p   |  q   | p &oplus; q |
| :--: | :--: | :---------: |
|  T   |  T   |      F      |
|  T   |  F   |      T      |
|  F   |  T   |      T      |
|  F   |  F   |      F      |



- p &rarr; q ≡ &not;(p &and; &not;q) ≡ &not;p &or; q
  - conditional statement: if p then q, p implies q
  - if we don't say anything wrong, then it is not false, and thus true.

|  p   |  q   | p &rarr; q |
| :--: | :--: | :--------: |
|  T   |  T   |     T      |
|  T   |  F   |     F      |
|  F   |  T   |     T      |
|  F   |  F   |     T      |

- Contrapositive: &not;q &rarr; &not;p
  - if ~q then ~p
- A conditional statement is logically equivalent to its contrapositive



* p ↔ q ≡ (p &rarr; q) &and; (q &rarr; p)  ≡ (p &rarr; q) &and; (&not;p &rarr; &not;q)
  * p and q are logically equivalent

|  p   |  q   | p ↔ q |
| :--: | :--: | :---: |
|  T   |  T   |   T   |
|  T   |  F   |   F   |
|  F   |  T   |   F   |
|  F   |  F   |   T   |



* Modus Ponens

  * Method of affirming

  If p then q

  p

  &therefore; q



* Modus Tollens

  * Method of denying

  If p then q

  ~q

  &therefore; ~p



* Equivalent

  p &rarr; q

  q &rarr; r

  &therefore; p &rarr; r



|  p   |  q   | p &rarr; q |  ~q  |  ~p  |
| :--: | :--: | :--------: | :--: | :--: |
|  T   |  T   |     T      |  F   |  F   |
|  T   |  F   |     F      |  T   |  F   |
|  F   |  T   |     T      |  F   |  T   |
|  F   |  F   |     T      |  T   |  T   |

