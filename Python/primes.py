# find all primes of any given number 

import math

def is_prime(n):
    """
    Returns True if n is prime, False otherwise"""
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n))):
        if n % i == 0:
            return False
    return True

def find_primes(n):
    """
    Returns a list of all primes less than n"""
    primes = []
    for i in range(2, n):
        if is_prime(i):
            primes.append(i)
    return primes

def main():
    """
    The main function"""
    """get a number from the user"""
    try: 
        n = int(input("Enter a number: "))
        print(find_primes(n))    
    except ValueError:
        print("You must enter a number")
if __name__ == "__main__":
    main()