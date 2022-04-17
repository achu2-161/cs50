

def main():
    hours, minutes = input("Enter time: ").split(":")

    print(hours)
    print(minutes)

    time = float(hours) + float(minutes)/60

    if 7 <= time <= 8:
        print("breakfast yime")
    elif 12 <= time <= 13:
        print ("lunch time")
    elif 18 <= time <= 19:
        print ("dinner time")






#if __name__ == "__main__":
main()