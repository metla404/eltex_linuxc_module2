# Задание 6.3

### Доработаннное решение задачи 2.3 (калькулятор). Функции загружаются из динамических библиотек. В одной библиотеке находится одна функция. При запуске программы считывается каталог с библиотеками и загружаются найденные функции.

#### vboxuser@Pink404:~/eltmod2/2/6/6.3$ cd library/
#### vboxuser@Pink404:~/eltmod2/2/6/6.3/library$ gcc -shared -fPIC -o libadd.so source/add.c
#### vboxuser@Pink404:~/eltmod2/2/6/6.3/library$ gcc -shared -fPIC -o libdiv.so source/div.c
#### vboxuser@Pink404:~/eltmod2/2/6/6.3/library$ gcc -shared -fPIC -o libsub.so source/sub.c
#### vboxuser@Pink404:~/eltmod2/2/6/6.3/library$ gcc -shared -fPIC -o libmul.so source/mul.c
#### vboxuser@Pink404:~/eltmod2/2/6/6.3/library$ cd ..
#### vboxuser@Pink404:~/eltmod2/2/6/6.3$ gcc -o main main.c calcmenufunc.c -ldl