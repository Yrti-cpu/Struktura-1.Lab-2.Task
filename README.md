# 1.Lab-2.Task(Status: ✅)
## Средний уровень сложности
Написать на языке С++ программу, решающую поставленную в вариативной части задачу, используя указанную там же структуру данных. Выполнение задания осуществляется в два этапа. На первом этапе требуется реализовать необходимую структуру данных с помощью одной структуры хранения (векторной или связной), реализацию оформить в виде класса. Методы класса должны выполнять только основные и 2 дополнительные операции, допустимые над элементами описываемой СД (перечислены ниже). Никаких других операций в классе быть не должно. На втором этапе требуется использовать объекты созданного класса при решении поставленной задачи.
### Операции над стеком
Обязательные: добавление элемента в стек, извлечение элемента из стека. Дополнительные: проверка заполнения стека, проверка пустоты стека, неразрушающее чтение элемента с вершины стека.
### Вариант 9
Структура данных – стек. Написать программу для вычисления значения арифметического выражения, записанного в префиксной форме. Операнды и операции отделяются друг от друга пробелами. На среднем уровне сложности операндами 
являются положительные целые числа.
#### `Пример`
* exp = "+ 2 3";//Result = 5
* exp = "- - 2 3";//неверно введенная строка
