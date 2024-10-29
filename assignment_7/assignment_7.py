# Copyright (c) 2021 Michael Neill Hartman. All rights reserved.
# mnh_license@proton.me
# https://github.com/hartmanm

"""
Classification: Naive Bayes Classifier

In the naive Bayes classifier, we make the assumption that all features are independent given the class label. This means that:

For this assignment, we will be using the Zoo Animal Classification dataset from the UCI Machine Learning dataset. https://archive.ics.uci.edu/ml/datasets/Zoo

This dataset consists of 101 animals from a zoo. There are 16 variables with various traits to describe the animals. The 7 Class Types are: Mammal, Bird, Reptile, Fish, Amphibian, Bug and Invertebrate.

For grading purposes, we will be using subsets of this public dataset, so please train your model on our provided data.

Before you start to work on the assignment, let's review what we learned from class:

Naive Bayes Classifier
Let's denote the features as  and the label as . As a generative model, the naive Bayes classifier makes predictions based an estimation of the joint probability .

For each example, the predicted label  is determined by:


In the naive Bayes classifier, we make the assumption that all features are independent given the class label. This means that:

To make our prediction, we need to keep track of  and .

Smoothing
Since some data combinations do not appear in our dataset, we smooth out the probability  and  with Laplacian correction. Specifically, since our dataset is small, we smooth the probability with a psuedo-count of 0.1.

That is,


Additional Testcases for Debugging
Here are some additional testcases for you to debug your code.

Input Format

CSV file with the following fields: animal_name, hair, feathers, eggs, milk, airborne, aquatic, predator, toothed, backbone, breathes, venomous, fins, legs, tail, domestic, catsize, classtype. Do not use the animal_name and classtype for prediction.

The examples will be split into training and test set. For the training set, the classtype field will have an integer value from 1-7. For the test set, the classtype field will have the value -1.

animal_name: Unique for each instance
hair Boolean
feathers Boolean
eggs Boolean
milk Boolean
airborne Boolean
aquatic Boolean
predator Boolean
toothed Boolean
backbone Boolean
breathes Boolean
venomous Boolean
fins Boolean
legs Numeric (set of values: {0,2,4,5,6,8})
tail Boolean
domestic Boolean
catsize Boolean
class_type Numeric (integer values in range [1,7])
Constraints

You are not allowed to use directly use machine learning libraries such as sklearn.

Output Format

For each example in the test set, print the predicted classtype. Each example should be printed in a separate line.

Sample Input 0

animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type
aardvark,1,0,0,1,0,0,1,1,1,1,0,0,4,0,0,1,1
worm,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,7
piranha,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,4
gnat,0,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0,6
oryx,1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1,1
moth,1,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0,6
skimmer,0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0,2
crab,0,0,1,0,0,1,1,0,0,0,0,0,4,0,0,0,7
vampire,1,0,0,1,1,0,0,1,1,1,0,0,2,1,0,0,1
slowworm,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,3
bass,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,0,-1
Sample Output 0

4
Explanation 0

The joint probability of the predicted class is 0.01963 if we know the total number of classes and the number of unique features for each class.

Update: A previous version of the challenge mistakenly wrote the joint probability as 0.01742. It has been fixed now.

"""

import sys
the_map={}
line_number=1
animals={}
animal_names=[]

# read in from stdin the csv creating a map of each line stripping the newline char
for line in sys.stdin:
    tokens=[]
    if line_number not in the_map:
        the_map[line_number]=[]
    tokens = line.split(',')
    for item in tokens:
        if item[-1]=='\n':
            item=item[:-1]
        the_map[line_number].append(item)
    #print(str(the_map[line_number]))
    line_number=line_number+1

# hardcoded field mapping
animal_name=the_map[1][0]
hair=the_map[1][1]
feathers=the_map[1][2]
eggs=the_map[1][3]
milk=the_map[1][4]
airborne=the_map[1][5]
aquatic=the_map[1][6]
predator=the_map[1][7]
toothed=the_map[1][8]
backbone=the_map[1][9]
breathes=the_map[1][10]
venomous=the_map[1][11]
fins=the_map[1][12]
legs=the_map[1][13]
tail=the_map[1][14]
domestic=the_map[1][15]
catsize=the_map[1][16]
class_type=the_map[1][17]

# iterate over the map appending each animal to its own nested map named after its animal_name with its fields:values
iterator=1
while iterator < line_number-1:
    #aprint(str(the_map[iterator][0]))
    iterator=iterator+1
    this_animal=the_map[iterator][0]
    animal_names.append(str(this_animal))
    animals[this_animal]={}
    animals[this_animal][animal_name]=this_animal
    animals[this_animal][hair]=the_map[iterator][1]
    animals[this_animal][feathers]=the_map[iterator][2]
    animals[this_animal][eggs]=the_map[iterator][3]
    animals[this_animal][milk]=the_map[iterator][4]
    animals[this_animal][airborne]=the_map[iterator][5]
    animals[this_animal][aquatic]=the_map[iterator][6]
    animals[this_animal][predator]=the_map[iterator][7]
    animals[this_animal][toothed]=the_map[iterator][8]
    animals[this_animal][backbone]=the_map[iterator][9]
    animals[this_animal][breathes]=the_map[iterator][10]
    animals[this_animal][venomous]=the_map[iterator][11]
    animals[this_animal][fins]=the_map[iterator][12]
    animals[this_animal][legs]=the_map[iterator][13]
    animals[this_animal][tail]=the_map[iterator][14]
    animals[this_animal][domestic]=the_map[iterator][15]
    animals[this_animal][catsize]=the_map[iterator][16]
    animals[this_animal][class_type]=the_map[iterator][17]

    #milk,airborne,aquatic,predator,toothed,backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type 
    
    #animals[this_animal][]


#print(str(animals))

#print(str(animal_names[0]))
#animal_iterator=0
#while animal_iterator < len(animal_names)-1:

# iterate over each nested animal map
print(str(line_number)+" line_number")
iterator=0
while iterator < line_number-2:

    #if animal_names[iterator] == animal_names[animal_iterator]:
    print(str(animals[animal_names[iterator]]))
    print(str(iterator)+" "+item)
    iterator=iterator+1
    #animal_iterator=animal_iterator+1
#print(str(animals['gnat']))

'''
#line_items=[]
for line in sys.stdin:
    #dic = {item.split(' ')[0]:float(item.split('\t')[1]) for item in line}
    #print(str(line))
    #for item in line:
    if line_number==1:
        tokens=[]
        tokens = line.split(',')
        token_number=1
        if token_number==1:
            token_number=token_number+1
        if token_number!=1:
            the_map[line_number]=[]

    if line_number!=1:

        #    print(item)
        tokens=[]

        tokens = line.split(',')
        token_number=1
        for item in tokens:
            if token_number==1:
                token_number=token_number+1
                if item not in the_map:
                    the_map[item]={}
            if token_number!=1:
                the_map[line_number]=[]
            if item[-1]=='\n':
                item=item[:-1]
            #this_item = item.split('\n')
            the_map[line_number].append(item)
        print(str(the_map[line_number]))
        line_number=line_number+1
        #"""

        line_items=[]
        for item in line:

            line_items[line_number]=
            print(str(item))
        #for item in line_items:
        #    print(str(iitem))
            #if item[0] not in the_map:
            #    the_map[line_number]=[]
            #the_map[line_number].append(item[0]
        #"""     
        
        #"""    
        the_map[line_number].append(label) 
        label,attribute_value_1,attribute_value_2 = line.split(' ')
        print(str(label))
        print(str(attribute_value_1))
        print(str(attribute_value_2))
        attribute_1,value_1 = attribute_value_1.split(':')
        print(str(attribute_1))
        print(str(value_1))
        attribute_2,value_2 = attribute_value_2.split(':')
        print(str(attribute_2))
        print(str(value_2))
        if line_number not in the_map:
            the_map[line_number]=[]
        the_map[line_number].append(label)
        #the_map[line_number][]
        labels.append(label)
        attributes.append(attribute_1)
        values.append(value_1)
        attributes.append(attribute_2)
        values.append(value_2)
        line_number=line_number+1
        #"""

print(str(the_map))

#print(str(labels))

#print(str(attributes))

#print(str(values))

#If attribute X <= threshold T ; then left node; else right node.
'''
