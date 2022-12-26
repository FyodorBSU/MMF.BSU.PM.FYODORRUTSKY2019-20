from connection.db_connection import DbConnection
from io import StringIO

_SUM_OF_INT_AND_MEDIAN_OF_FLOAT = '''SELECT SUM(int_number), 
                                        PERCENTILE_CONT(0.5) WITHIN GROUP(ORDER BY float_number)
                                 FROM data;'''


def get_sum_of_int_and_median_of_float():
    with DbConnection() as conn:
        cursor = conn.cursor
        cursor.execute(_SUM_OF_INT_AND_MEDIAN_OF_FLOAT)
        result_set = cursor.fetchall()
        return result_set


def insert(path: str):
    with open(path, "r", encoding="utf-8") as file:
        with DbConnection() as conn:
            cursor = conn.cursor
            cursor.execute('SET datestyle = \'European\';')
            number_of_lines = sum(1 for line in file)
            file.seek(0)
            for i, line in enumerate(file):
                cursor.copy_from(StringIO(line.replace('||', '|')), "data", sep="|")
                if i % 10000 == 0:
                    print("Processed {}/{} lines".format(i + 1, number_of_lines))
                    conn.connection.commit()
            conn.connection.commit()
