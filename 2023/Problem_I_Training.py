count = 0
maximum = 0
skill = 0


with open("Problem_I_input.txt", "r") as file:
    for line in file:
        inputs = line.split(" ")
        if count == 0:
            skill = int(inputs[1])
        else:
            if int(inputs[0]) <= skill <= int(inputs[1]):
                skill = skill + 1
        count += 1
    
with open("Problem_I_output.txt", "w") as o:
    o.write(str(skill))
    