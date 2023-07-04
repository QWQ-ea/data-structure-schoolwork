import  random as R
f=open("moreradixdigit30.txt", 'w', encoding='utf-8')
a=[str(R.randint(1000000,9999999))+'\n' for i in range(30)]
f.writelines(a)
f.close()