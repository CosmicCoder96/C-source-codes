while True :
    try:
        i = input()
    except:
        break


   
    a = i.split()
    
    #print(a)
    #print(len(a))
    if len(a)<=1:
                break
    number = a[0]
    basei = int(a[1])
    basef = int(a[2])
    #print(number,basei,basef)
    value=0
    nl = len(number)
    for i in range(0,nl):
        #temp = number[i]
        if number[i]=='A':
                           temp='10'
        elif number[i]=='B':
                            temp='11'
        elif number[i]=='C':
                            temp='12'
        elif number[i]=='D':
                            temp='13'
        elif number[i]=='E':
                           temp='14'
        elif number[i]=='F':
                            temp='15'
        else:
        	temp = number[i]
                            
        
        value+=(int(temp)*basei**(nl-i-1))
        #print(value)
    #print(value)
    n = value
    s = ''
    while True:
        m = n%basef
        if m==10:
                m='A'
        if m==11:
                m='B'
        if m==12:
                m='C'
        if m==13:
                m='D'
        if m==14:
                m='E'
        if m==15:
                m='F'
       
        t = int(n/basef)
        s = s+str(m)                                                               

        if t==0:
                break;
        n=int(n/basef);
    if(len(s)<=7):
                print(s[::-1].rjust(7))
    else:
        print("ERROR".rjust(7))
        
        
    