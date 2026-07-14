import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({
        'SecondHighestSalary': [
            employee['salary'].drop_duplicates().nlargest(2).iloc[-1]
            if employee['salary'].nunique() >= 2 else None
        ]
    })