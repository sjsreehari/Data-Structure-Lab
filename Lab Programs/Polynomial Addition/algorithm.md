# Aim

	To implement polynomial addition using arrays in C.

# Algorithm

	Step 1: Start

	Step 2: Define Data Structure
		Define a struct term containing:
			coeff → integer coefficient
			exp   → integer exponent

	Step 3: Declare Arrays
		poly1[10] → stores the first polynomial
		poly2[10] → stores the second polynomial
		result[10] → stores the resultant polynomial

		Also declare integers:
			n1 → number of terms in first polynomial
			n2 → number of terms in second polynomial
			n3 → number of terms in resultant polynomial

	Step 4: Input First Polynomial
		Read n1
		Repeat for i = 0 to n1 - 1:
			Read coeff and exp of each term
			Store into poly1[i]

	Step 5: Input Second Polynomial
		Read n2
		Repeat for j = 0 to n2 - 1:
			Read coeff and exp of each term
			Store into poly2[j]

	Step 6: Add Polynomials Term by Term
		Initialize indices: i = 0, j = 0, k = 0
		Repeat while i < n1 and j < n2:
			1. Case 1: If poly1[i].exp == poly2[j].exp
				   result[k].coeff = poly1[i].coeff + poly2[j].coeff
				   result[k].exp = poly1[i].exp
				   Increment i, j, k
			2. Case 2: If poly1[i].exp > poly2[j].exp
				   Copy poly1[i] to result[k]
				   Increment i, k
			3. Case 3: If poly1[i].exp < poly2[j].exp
				   Copy poly2[j] to result[k]
				   Increment j, k

	Step 7: Copy Remaining Terms
		While i < n1:
			Copy poly1[i] to result[k]
			Increment i, k
		While j < n2:
			Copy poly2[j] to result[k]
			Increment j, k
		Finally set n3 = k

	Step 8: Output Resultant Polynomial
		For each term t = 0 to n3 - 1:
			If result[t].exp != 0 → print result[t].coeff x^ result[t].exp
			If result[t].exp == 0 → print only result[t].coeff
			If not the last term → print +

	Step 9: Stop



