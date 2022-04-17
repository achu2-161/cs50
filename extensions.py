x = input("Filename: ").casefold().strip()

if x.endswith(".gif") == True:
    print("image/gif")
elif x.endswith(".jpg") == True:
    print("image/jpeg")
elif x.endswith(".jpeg") == True:
    print("image/jpeg")
elif x.endswith(".png") == True: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
    print("image/png")
elif x.endswith(".pdf") == True:
    print("application/pdf")
elif x.endswith(".txt") == True:
    print("text/plain")
elif x.endswith(".zip") == True:
    print("application/zip")
else:
    print("application/octet-stream")

    GHP_E9HYNYNT6VJXKXJM5XJWB1J8WKPRWO0KQBVG 