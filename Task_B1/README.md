# Тестовое задание

## Example of application run

### File generation:


![](images/image_1.png)
![](images/image_2.png)


### File merging:
![](images/image_3.png)


### Loading to the db:


![](images/image_4.png)


### SQL query
```postgresql
SELECT SUM(int_number),
       PERCENTILE_CONT(0.5) WITHIN GROUP(ORDER BY float_number)
FROM data;
```

### Result:


![](images/image_5.png)