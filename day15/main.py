import re

def getBox(s):
    s1 = re.split('=|-', s)[0]
    current = 0
    for c in s1:
        current+=ord(c)
        current*=17
        current = current % 256
    return str(current)

def getLabel(s):
    return re.split('=|-', s)[0]


def main():
    rows = [s.strip() for s in open("input.txt").readlines()]
    sample = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7"
    instructions = rows[0].split(',')

    mymap={}
    for i in instructions:
        box = getBox(i)
        label = getLabel(i)
        if ('=' in i):
            if (box in mymap.keys()):
                flag=True
                for index, val in enumerate(mymap[box]):
                    if (getLabel(val) == label):
                        mymap[box][index] = i
                        flag=False
                if (flag):
                    mymap[box].append(i)
            else:
                mymap[box]=[i]
        elif ('-' in i):
            if (box in mymap.keys()):
                for index, val in enumerate(mymap[box]):
                    if (getLabel(val) == label):
                        mymap[box].pop(index)
                        break

        else:
            print("err")
            return -1
 
    sum=0
    for key in mymap.keys():
        current=int(key)+1
        count=1
        for ele in mymap[key]:
            toadd=current*count*int(ele[-1])
            count+=1
            sum+=toadd

    print(sum)
    return sum

if __name__ == '__main__':
    main()
