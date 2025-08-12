from functools import partial


def readReports(input_path:str) -> list[list[int]]:
    """
    Read a files where each line is a report  consisting of numbers sparated by spaces

    Args:
        input_path (str): Input path to the `.txt` file.

    Returns:
        list[list[int]] : A matrix with each observation being a report.

    Raises:
        FileNotFoundError: If file doesnt exist. 
    """
    try:
        with open(input_path, "r") as f:
            report = [list(map(int, line.strip().split())) for line in f] 

    except FileNotFoundError:
        raise

    return report

def isSafeCore(report:list[int]) -> bool:
    """
    Conditions for a report to be safe (to avoid redudancy).

    A report is safe if:
    - All values are either strictly increasing or strictly decreasing.
    - Each adjacent difference is between 1 and 3 (inclusive).

    Args:
        report (list[int]): The report to evaluate.
    
    Returns:
        bool: True if the report is safe, False otherwise.
    """
    diffs = [abs(b - a) for a, b in zip(report, report[1:])]
    is_ascending = all(b > a for a, b in zip(report, report[1:]))
    is_descending = all(b < a for a, b in zip(report, report[1:]))
    return all(1<=diff<=3 for diff in diffs) and (is_ascending or is_descending)


def evaluateReport(report:list[int], allow_skip:bool) -> bool:
    """
    Determines if a single report is safe.


    Args:
        report (List[int]): The report to evaluate.
        allow_skip (bool): Allow to skip one wrong value.

    Returns:
        bool: True if the report is safe, False otherwise.
    """
    if isSafeCore(report):
        return True
    elif not allow_skip:
        return False
    else:
        for i in range(len(report)):
            temp = report[:i] + report[i+1:]
            if isSafeCore(temp):
                return True
        return False


def evaluateAllReports(reports:list[list[int]], allow_skip:bool = False) -> int:
    """
    Counts the number of safe reports in a matrix.

    Args:
        reports (List[List[int]]): List of reports to evaluate.
        allow_skip (bool): Allow to skip one wrong value. Dafault to False.

    Returns:
        int: Number of reports that are considered safe.
    """
    evaluateReportAllow = partial(evaluateReport, allow_skip=allow_skip)
    return len(list(filter(evaluateReportAllow, reports))) 




print(evaluateAllReports(readReports('./input2.txt'), allow_skip=False))
print(evaluateAllReports(readReports('./input2.txt'), allow_skip=True))
