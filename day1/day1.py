from collections import Counter

def readLists(input_path:str) -> tuple[list[int], list[int]]:
    """
    Read a text file where each line contain a pair of integers and return the two corresponding lists.

    Args:
        input_path (str): Path to the input file.
    
    Returns:
        tuple[list[int], list[int]]: Two list of integers extracted from each column.

    Raises:
        ValueError: If file is empty or not well formated.
        FileNotFoundError: If file doesnt exist.
        
    """

    try:
        with open(input_path, "r") as f:
            left_right = [tuple(map(int, line.strip().split())) for line in f]
            left_lst, right_lst = zip(*left_right) 
            return list(left_lst), list(right_lst)

    except ValueError:
        raise ValueError("File is not well formated")

    except FileNotFoundError:
        raise



def day1Part1(left_lst:list[int], right_lst:list[int]) -> int:
    """
    Return the sum of the absolute difference between two sorted lists of integers;

    Args:
        left_lst (list[int]): list of integers 
        right_lst (list[int]): list of integers 

    Return:
        int : sum of the absolute difference between the two sorted lists. 

    Raises:
        ValueError: If the input lists are not of the same length.
    """
    if len(left_lst) != len(right_lst):
        raise ValueError("Lists must be the same length")

    left_lst = sorted(left_lst)
    right_lst = sorted(right_lst)
    res = sum([abs(l - r) for l, r in zip(left_lst, right_lst)])
    return res


def day1Part2(left_lst:list[int], right_lst:list[int]) -> int:
    """
    Computes the 'similarity score' between two lists of integers.

    Args:
        left_lst (list[int]): list of integers 
        right_lst (list[int]): list of integers 

    Return:
        int : sum of the number of occurence of the each term of the left list inside the right list. 
        
    Raises:
        ValueError: If the input lists are not of the same length.
    """
    if len(left_lst) != len(right_lst):
        raise ValueError("Lists must be the same length")

    counter_right = Counter(right_lst)
    res = sum([i * counter_right[i] for i in left_lst])
    return res

print(day1Part1(*readLists('./input.txt')))
print(day1Part2(*readLists('./input.txt')))
