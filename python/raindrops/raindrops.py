def convert(number):

    rtnString = f"{'Pling' if number % 3 == 0 else ''}
        {'Plang' if number % 5 == 0 else ''}
        {'Plong' if number % 7 == 0 else ''}"

    if rtnString and rtnString.strip():
        return rtnString

    return str(number)

###########################################
#Third attempt using string               #
###########################################
#def convert(number):
#
#    rtnString = ""
#
#    if not number % 3:
#        rtnString += "Pling"
#    if not number % 5:
#        rtnString += "Plang"
#    if not number % 7:
#        rtnString += "Plong"
#
#    if rtnString and rtnString.strip():
#        return rtnString
#
#    return str(number)

###########################################
# Second attempt with list                #
###########################################
#def convert(number):
#
#    rtnStringList = []
#
#    if not number % 3:
#        rtnStringList.append("Pling")
#    if not number % 5:
#        rtnStringList.append("Plang")
#    if not number % 7:
#        rtnStringList.append("Plong")
#
#    if not rtnStringList:
#        return str(number)
#
#    return ("".join(rtnStringList))

###########################################
# First Attempt uses LCD; if,elif form    #
###########################################
#def convert(number):
#
#    if number % 105 == 0:
#        return "PlingPlangPlong"
#    elif number % 35 == 0:
#       return "PlangPlong"
#    elif number % 21 == 0:
#        return "PlingPlong"
#    elif number % 15 == 0:
#        return "PlingPlang"
#    elif number % 7 == 0:
#        return "Plong"
#    elif number % 5 == 0:
#        return "Plang"
#    elif number % 3 == 0:
#        return "Pling"
#    else:
#        return str(number)
##########################################
