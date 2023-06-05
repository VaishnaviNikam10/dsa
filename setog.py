set1=[]
set2=[]

def accept():
    n=int(input("\nenter no. of elements to be accept"))
    for i in range (n):
        m=int(input("\n enter the elemennt"))
        set1.append(m)
    print("\n The Set is: ",set1)

def removeno(set1):
    n=int(input("\n Enter the element that you want to remove"))
    for i in (set1):
        if i==n:
            set1.remove(i)
        else:
            print("\n Element not fount")
    print("\n The set is: ",set1)

def containno(set1):
    n=int(input("\n Enter the element that you want to search: "))
    if n in (set1):
        print("\n Element is present")
    else:
        print("\n Element is not present")

def size(set1):
    count=0
    for i in (set1):
        count=count+1
    print("\n Size of set1 is: ",count)

def iterate(set1):
    iterator=iter(set1)
    for i in range (len(set1)):
        print(next(iterator))

def intersection(set1, set2):
    inter=[]
    for i in (set1):
        for j in (set2):
            if i==j:
                inter.append(i)
    print("\n Intersection of two set is: ",inter)

def union(set1, set2):
    uni=[]
    uni.extend(set1)
    for i in (set2):
        if i not in (set1):
            uni.append(i)
    print("\n Union of two set is: ",uni)

def difference(set1, set2):
    diff=[]
    for i in (set1):
        if i not in (set2):
            diff.append(i)
    print("\n Difference ofmset1 - set2 is: ",diff)

def subset(set1, set2):
    subset=True
    for i in (set2):
        if i not in (set1):
            subset=False
    if subset==False:
        print("\n set2 is not subset of set1")
    else:
        print("\n set2 is subset of set1")
           
def main():
    n=int(input("\n enter total no. of elements in sel 1: "))
    for i in range(n):
        set1.append(int(input("\n enter element ")))
    print("set1 is: ",set1)
    ch=0
    for i in range (7):
        print("\n Set Operation")
        print("1] Aceept element in set")
        print("2] Remove element from set")
        print("3] Contain element in set")
        print("4] Size of set")        
        print("5] Iterator set")
        print("6] Set operation")
        print("7] Exit")

        ch=int(input("\n enter choice "))
        while(True):
            if ch==1:
                accept()
                break
            elif ch==2:
                removeno(set1)
                break
            elif ch==3:
                containno(set1)
                break
            elif ch==4:
                size(set1)
                break
            elif ch==5:
                iterate(set1)
                break
            elif ch==6:
                m=int(input("\n Enter no of elements in set2: "))
                for i in range (m):
                    set2.append(int(input("\n Enter the element ")))
                print("\n Set2 is: ",set2)
                print("\n Set Operation")
                print("1] Insertion of two set")
                print("2] Union of two set")
                print("3] Difference of two set")
                print("4] subset")
                print("5] exit")
                for i in range (5):
                    choice=int(input("\n enter your choice"))
                    while(True):
                        if choice==1:
                            intersection(set1, set2)
                            break
                        elif choice==2:
                            union(set1, set2)
                            break
                        elif choice==3:
                            difference(set1, set2)
                            break
                        elif choice==4:
                            subset(set1, set2)
                            break
                        else:
                            print("\n...EXIT..")
                            break
            else:
                print("\n ---exit---")
                break
                


main()
