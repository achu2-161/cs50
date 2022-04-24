def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):

    #print (s[0:2])
    l = len(s)
    j = 3
    for i in s[j:l]:
        if i.isdigit() and s[j + 1:l].isalpha():
            #print("numbers need to come at the end:")
            return False

    for i in s[j:l]:
        if i.isdigit() and s[j -1:l] == 0:
            #print("numbers need to come at the end:")
            return False

    if s.isalnum() == False:
        #print("invalid characters")
        return False
    elif l < 2 or l >6:
        #print("inappropriate length")
        return False
    elif s[0:2].isalpha() == False:
        #print ("2 first characters are not letters")
        return False
    else:
        return True



    #eliminate non-alplanumeric numbers DONE
    #eliminate inputs of length of input (2-6) DONE
    #


    #return


main()