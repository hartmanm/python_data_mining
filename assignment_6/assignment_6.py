# for University_of_Illinois 2021
# Michael Neill Hartman

# assignment_6

"""
Classification: Decision Tree Classifier

In this assignment, we will build a decision tree classifier for multi-class classification with continuous feature/attribute values. For the decision tree you are to implement, please always use binary split and a threshold to split data. That is, each decision node has the form:

If attribute   threshold ; then left node; else right node.
where the best  and  are for you to determine. Please use information gain to construct the decision tree.

Model Specifications
For the decision tree, let  be the only stopping criterion. In other words, you should grow the tree as long as  is not violated and not all training instances in the current node have the same label.

Tie Breaking
We ensure each attribute is named by a non-negative integer, and each class label is named by a positive integer. Since we are to use HackerRank for grading, we have to eliminate additional randomness and generate deterministic results. We, therefore, enforce the following rule in this assignment: In the event of ties, always choose the attribute or label with the smallest value. Namely,

When training a DT, if splitting on either attribute  or  gives us the best information gain, choose the smaller of  and .
In prediction, if both labels  and  have the same number of training instances at a DT leaf node , predict the smaller of  and .
For all test cases in this assignment, we guarantee results are deterministic as long as the requirements above are satisfied.

Additional Testcases for Debugging
Here are some additional testcases for you to debug your code.

Input Format

Each input dataset contains training instances followed by test instances. Each line has the following space-separated format:

[label] [attribute 1]:[value 1] [attribute 2]:[value 2]...
The name of each attribute, e.g., [attribute 2], is a non-negative integer. The value of an attribute, e.g., [value 2], is a float number. A line stands for a test instance if [label] is -1 and a training instance otherwise. The label of a training instance can be any positive integer.

Please do not assume the attribute names to start from  or to be consecutive integers, and please do not assume the class labels to start from  or to be consecutive integers.

Constraints

Only standard libraries are allowed for this assignment. Advanced libraries (e.g., sklearn, pandas, numpy) are not allowed and would generate an error by HackerRank.

Output Format

The output is the prediction on the test instances made by your DT. In each line of the output, print the prediction for each test instance. Please follow the ordering of the test instances in the input file.

Sample Input 0

1 0:1.0 2:1.0
1 0:1.0 2:2.0
1 0:2.0 2:1.0
3 0:2.0 2:2.0
1 0:3.0 2:1.0
3 0:3.0 2:2.0
3 0:3.0 2:3.0
3 0:4.5 2:3.0
-1 0:1.0 2:2.2
-1 0:4.5 2:1.0
Sample Output 0

1
1
"""


import sys

#labels=[]
#attributes=[]
#values=[]
the_map={}
line_number=1




#line_items=[]
for line in sys.stdin:
    #dic = {item.split(' ')[0]:float(item.split('\t')[1]) for item in line}
    #print(str(line))
    #for item in line:
    #    print(item)
    tokens=[]
    if line_number not in the_map:
        the_map[line_number]=[]
    tokens = line.split(' ')
    for item in tokens:
        if item[-1]=='\n':
            item=item[:-1]
        #this_item = item.split('\n')
        the_map[line_number].append(item)
    print(str(the_map[line_number]))
    line_number=line_number+1
    """

    line_items=[]
    for item in line:

        line_items[line_number]=
        print(str(item))
    #for item in line_items:
    #    print(str(iitem))
        #if item[0] not in the_map:
        #    the_map[line_number]=[]
        #the_map[line_number].append(item[0]
    """     
    
    """    
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
    """

print(str(the_map))

#print(str(labels))

#print(str(attributes))

#print(str(values))

#If attribute X <= threshold T ; then left node; else right node.
