import psycopg2


class DbConnection:
    _instance = None

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(DbConnection, cls).__new__(cls, *args, **kwargs)
        return cls._instance

    def __init__(self, host='localhost', dbname='postgres', user='postgres', password='admin'):
        self.connection = psycopg2.connect(host=host, dbname=dbname, user=user, password=password)
        self.cursor = self.connection.cursor()

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        self.connection.close()
