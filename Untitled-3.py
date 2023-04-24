def access_array(s1, s2, s3, n):
    # Concatenate s1, s2 repeated n times, and s3 to get the binary representation of S
    s = s1 + (s2 * n) + s3
    length = len(s)
    count = 0
    i = 0
    while i < length:
        if s[i] == '1':
            count += 1
            # If the current bit is 1, access the array n+1 times
            i += n+1
        else:
            # If the current bit is 0, access the array once
            count += 1
            i += 1
    return count

# Taking input and calling the function for each test case
t = int(input())
for i in range(t):
    s1, s2, s3, n = input().split()
    n = int(n)
    result = access_array(s1, s2, s3, n)
    print(result)
