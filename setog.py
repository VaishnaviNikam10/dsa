'''Problem statement : To create ADT that implements the "set" concept.
    a. Add (new Element) -Place a value into the set 
	b. Remove (element) Remove the value 
	c. Contains (element) Return true if element in collection
	d. Size () Return number of values in collection  Iterator() Return an iterator used to loop over collection
    e. Intersection of two sets 
	f. Union of two sets
	g. Difference between two sets
	h. Subset
'''

def accept():
    s1=set()
    n=int(input("\nHow many numbers do you want in set : "))
    for i in range(n):
        s1.add(int(input(f"\nEnter number {i+1} : ")))
    return s1

def removeNo(n,s1):
    i=search(n,s1)
    if(n in s1):
        s1.remove(n)
    else:
       print(f"\n {n} does not found in set") 
    return s1

def display(s1):
    itr=iter(s1)
    print("\nSet elements are : \n")
    for i in s1:
        print(next(itr))

def search(n,s1):
    for i in s1:
        if(n in s1):
            return i
        else:
            return -1 

def findSize(s1):
    cnt=0
    for i in s1:
        cnt+=1
    return cnt

def unionSet(s1,s2):
    result=set()
    for i in s1:
        result.add(i)
    for j in s2:
        if j not in s1:
            result.add(j)
    return result

def intersectionSet(s1,s2):
    result=set()
    for i in s1:
        if i in s2:
            result.add(i)
    return result

def differnceSet(s1,s2):
    result=set()
    for i in s1:
        if i not in s2:
            result.add(i)
    return result

def Subset(s1):
    if(len(s1)==0):
        return [[]]
    x=Subset(s1[:-1])
    return x+[[s1[-1]]+y for y in x]
              
def setOperation():
    s1=accept()
    s2=accept()
    uni=set()
    inter=set()
    diff=set()
    subset=set()
    while True:
        print("\n---------------------------SET MENU------------------------------")
        print("\n\n \t [1] Union \n\t [2] Intersection \n\t [3] Difference \n\t [4] Subset")
        ch=int(input("\nEnter your choice : "))
        if ch==1:
            uni=unionSet(s1,s2)
            print("\nSet 1 : ",s1)
            print("\nSet 2 : ",s2)
            print("\nUnion : ",uni)
        elif ch==2:
            inter=intersectionSet(s1,s2)
            print("\nSet 1 : ",s1)
            print("\nSet 2 : ",s2)
            print("\nIntersection : ",inter)
        elif ch==3:
            diff=differnceSet(s1,s2)
            print("\nSet 1 : ",s1)
            print("\nSet 2 : ",s2)
            print("\nDifference (S1-S2): ",diff)
            diff=differnceSet(s2,s1)
            print("\nDifference (S2-S1): ",diff)

        elif ch==4:
            s1=[1,2,3]
            result=Subset(s1)
            print("\nSet is : ",s1)
            print("\nSubsets of set are : ",result)
#main
s1=set()
s2=set()
ch=0
while True:
    print("\n---------------------------MENU------------------------------")
    print("\n\n \t [1] Accept elements \n\t [2] Display elements \n\t [3] Remove element \n\t [4] Search element \n\t [5] Find Size\n\t [6] Perform Set Operations")
    ch=int(input("\nEnter your choice : "))
    if ch==1:
        s1=accept()
        print("\nSet is : ",s1)
    elif ch==2:
        display(s1)
    elif ch==3:
        n=int(input("\nEnter the number to remove : "))
        s1=removeNo(n,s1)
        print("\nSet is : ",s1)
    elif ch==4:
        n=int(input("\nEnter the number to search : "))
        i=search(n,s1)
        if(i!=-1):
            print(f"\n {n} is present in set ")
        else:
            print(f"\n {n} does not found in set ")
        print("\nSet is : ",s1)
    elif ch==5:
        size=findSize(s1)
        print(f"\nSize of the set is : {size}")
    elif ch==6:
        setOperation()
