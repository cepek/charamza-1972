A = [
1.34839974e-01  7.62770063e-01 -4.78091438e-01  3.14285711e-01 -3.14285670e-01  4.57142861e-01
 2.69679946e-01  4.76731277e-01  1.19522874e-01 -6.28571419e-01  6.28571505e-01	-9.14285711e-01
 4.04519916e-01  1.90692500e-01  7.17137186e-01  1.42857145e+00 -4.28571335e-01	-2.85714283e-01
 5.39359892e-01 -9.53462853e-02  1.19522888e-01 -2.22857143e+00  2.28571553e-01	 1.48571429e+00
 6.74199863e-01 -3.81385070e-01 -4.78091408e-01  1.11428573e+00 -1.14285551e-01	-7.42857142e-01
 1.34839974e-01 -4.48127416e+00  3.70520868e+00  3.31428573e+00  1.96857143e+01	 1.45714290e+00
 2.69679946e-01 -1.62088642e+00  1.07570577e+00 -2.85714284e+00  5.85714294e+00	 5.71428577e-01
 2.56195948e+00 -2.28831033e+00  9.56183000e-01  1.57142862e+00  1.42857197e+00	-7.14285693e-01
 1.21355976e+00 -4.76731402e-01  2.03188875e+00 -6.68571426e+00  3.68571483e+00	-2.54285711e+00
 1.34839974e-01 -1.33484763e+00  1.07570576e+00  4.42857153e-01  5.55714289e+00	 3.71428571e-01
 0.00000000e+00  1.04880885e+00 -1.07570575e+00 -7.42857149e-01 -5.25714284e+00	-1.71428576e-01
 0.00000000e+00  0.00000000e+00  5.97614306e-01  3.57142863e-01  1.64285716e+00	-5.71428569e-01
]

B= [
     1.348399725e-01   7.627700714e-01  -4.780914437e-01   3.142857143e-01     -3.142857143e-01   4.571428571e-01
     2.696799450e-01   4.767312946e-01   1.195228609e-01  -6.285714286e-01      6.285714286e-01  -9.142857143e-01
     4.045199175e-01   1.906925178e-01   7.171371656e-01   1.428571429e+00     -4.285714286e-01  -2.857142857e-01
     5.393598900e-01  -9.534625892e-02   1.195228609e-01  -2.228571429e+00      2.285714286e-01   1.485714286e+00
     6.741998625e-01  -3.813850357e-01  -4.780914437e-01   1.114285714e+00     -1.142857143e-01  -7.428571429e-01
     1.348399725e-01  -4.481274169e+00   3.705208689e+00   3.314285714e+00      1.968571429e+01   1.457142857e+00
     2.696799450e-01  -1.620886402e+00   1.075705748e+00  -2.857142857e+00      5.857142857e+00   5.714285714e-01
     2.561959477e+00  -2.288310214e+00   9.561828875e-01   1.571428571e+00      1.428571429e+00  -7.142857143e-01
     1.213559752e+00  -4.767312946e-01   2.031888636e+00  -6.685714286e+00      3.685714286e+00  -2.542857143e+00
     1.348399725e-01  -1.334847625e+00   1.075705748e+00   4.428571429e-01      5.557142857e+00   3.714285714e-01
     0.000000000e+00   1.048808848e+00  -1.075705748e+00  -7.428571429e-01     -5.257142857e+00  -1.714285714e-01
     0.000000000e+00   0.000000000e+00   5.976143047e-01   3.571428571e-01      1.642857143e+00  -5.714285714e-01
]

C = A - B

max(abs(C))
