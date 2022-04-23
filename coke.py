#loop to make sure only correct coins are accepted

def main():

    due = 50
    while True:

        x = int(input("Insert coin: "))
        inserted = get_coin(x)

        due = due - inserted
        if due > 0:

            print ("Amount due:", due)

        elif due == 0:
            print ("Change owed: 0")
            break

        else:

            #print (due)
            #print (inserted)
            print ("Change owed:", inserted + due)

            break





def get_coin(y):

    if y == 5:
        #print("you inserted 5")
        return y
    elif y == 10:
        #print("you inserted 10")
        return y
    elif y == 25:
        #print("you inserted 25")
        return y
    else:
        #print("you're a moron")
        return 0

main()








