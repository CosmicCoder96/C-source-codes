while True:
            n=int(input())
            m=1000000000
            s=0
            if(n==0):
                break;
            w=[]
            h=[]
            d=[]
            v=[]
            
            for i in range(n):
                inp=input()

                a=  list((map(int,inp.split())))
                w.append(a[0])
                h.append(a[1])
                d.append(a[2])
                v.append(w[i]*h[i]*d[i])
                
                tm=min(w[i],h[i],d[i])
                if(tm<m):
                    m=tm
                    
            
            for i in range(n):
                s+= v[i]/(m**3)
            print(int(s))
        
    
