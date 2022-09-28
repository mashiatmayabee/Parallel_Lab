a =100
b =50
c = 0
t = .1
k1 = .008
k2 = .002
for i in range (60):
    a = a + (k2*c - k1*a*b)*t
    b = b + (k2*c - k1*a*b)*t
    c = c  + ( 2*k1*a*b - 2*k2*6)*t






    