### 1067

Создадим струтуру, которая в себе будет хранить название директории и map с дочерними директориями с доступом по ключу — названием директории. Для начала зададим корневую директорию без имени. При парсе очередной строки будем начинать от корня и до последней директории в пути, если на очередном шаге при обращении к map по имени, таковой не существует — добавляем в map новую директорию и т. д.

Сложность nlog(n)

![](/images/10.png)

### 1494

Рассмотрим, какой порядок должен быть, если Чичиков забил все шары в правильном порядке (при любом несоответствии — cheater).
Допустим ревизор каждый раз забирает шар, тут всё понятно, сначала 1, потом 2 и т. д.

![](/images/11.png)

Допустим ревизор взял первый, а потом последний шар. Тогда дальше он должен взять все шары от последний-1 до первого.

![](/images/12.png)

Аналогично для всех случаев: если мы берем шар, который больше текущего максимума — значит ревизор пропустил какие-то шары, чтобы их сохранить — воспользуемся стеком, куда будем складывать все шары, которые пропустили в правильном порядке, если мы берем шар, который меньше текущего максимума, то это значит, что мы начали брать пропущенные шары: смотрим верх стек, если равны элементы, то всё в порядке, снимаем его оттуда. Во всех остальных случаях — Чичиков жульничает.

Рассмотрим более сложный пример:
Сначала ревизор берёт 4 шар, максимальный у нас 0, сохраним на стек 1-3, далее ревизор берёт 6 шар, максимальный у нас 4, сохраним на стек 5, равизор берёт 10 шар, сохраним на стек 7-9. Последующие шары должны быть взяты в порядке, представленным на рисунке: самый правый столбец, это и есть стек.

![](/images/13.png)

Сложность O(n)

### 1521

Для решения будем использовать дерево отрезков. В листах будут лежать наши солдатики, а в узлах — сумма. Таким образом мы за логарифм сможем находить сумму на определенном отрезке, а также изменять элементы (убирать выбывших). Построив дерево уберём k-ого солдата (искомый уровень у нас есть). Перестроим нашего дерево (суммы), после чего нам нужно найти позицию следующего солдата. Если выстроить оставшихся солдат в ряд, то номер следующего выбывшего = (кол-во солдат, стоящих до последнего выбывшего + k) mod сумма оставшихся солдат. Теперь нам нужно найти индекс в нашем кругу: для этого нам надо как-бы «отсчитать» этих солдат. Суммы у нас уже есть, отсчёт ведём слева, значит, наш солдат будет справа от узла = позиции в ряду.
Пример из условия:
Уже выбыл 3 и 1 солдат.
В ряду следущий солдат — 3, а среди всех солдат — 5.
Мы приходим в узел с количеством 3 = кол-во оставшихся солдат. Мы ещё не отсчитали никого (количество солдат <= номеру в ряду). Начинаем наш отсчёт — движимся вправо. Видим, что здесь количество солдат — уже необходимое, движимся влево, пока не придём к листу. И т. д.

![](/images/14.png)

Сложность nlog(n)

### 1628

Будем находить белые полосы, как разницу между двумя черными днями. Для этого добавим рамку из черных дней. Отсортируем по столбцам, найдём разность между днями, если больше 1, то это однозначно полоса, если равно 1, то отложим для последующей проверки. Аналогично для строк. После этого проверим являются ли отложенные точки полосами размером 1х1 (так как это могут быть просто концы других полос). Отсортируем (не важно в каком порядке, нам просто надо проверить нет ли соседей), если такая полоса встречается 2 раза, то она была добвлена и при проходе по столбцам, и при проходе по строкам — является полосой 1х1.

Сложность O(k)

### 1650

Будем хранить в 2 map города и миллиардеров. Ключами будут их имена. Для города будем хранить сумму денег, которая там сейчас находится и количество дней, которые он был в топе. Для миллиардеров же будем хранить текущее местоположение. Заведём также set, в который будем добавлять города с суммами денег. Тогда у нас всегда будет актуальное первое и второе место среди городов. Осталось лишь считывать очередное перемещение миллиардера, менять количество денег в городе, местоположение миллиардера, количество дней, которые город был в  топе.

Сложность klog(k)