20171664 소프트웨어학부 이범석



# Pointer-Quiz

안녕하십니까 교수님!

저는 군생활을 마치고 2020년 1학기에 복학하게 된 소프트웨어학부 이범석입니다. 

코로나-19 바이러스 때문에 모두가 힘든 상황이지만 한 학기 동안 열심히 수업에 임해서 많은 지식을 얻어가겠습니다.

한 학기 동안 잘 부탁드립니다!

---



### 코드 구현

아래는 Pointer-Quiz 코드에 대한 구현 명세이다.

- double 형의 변수 d 와 char/int/float/double 포인터 변수 cp, ip, fp, dp 를 선언한다.

```c++
double d;
char *cp;
int *ip;
float *fp;
double *dp;
```

- cp, ip, fp, dp 가 모두 변수 d 의 주소를 갖는 치환문을 실행한다.

  이 때, 포인터 변수와 d의 변수의 type이 다르므로 type casting을 해서 치환해 준다.

```c++
cp = (char *)&d;
ip = (int *)&d;
fp = (float *)&d;
dp = &d;
```

- d의 주소 xxxxx 를 출력한다

```c++
cout << d << endl;
```
결과: ![image-20200412185756659](/home/leebumseok/.config/Typora/typora-user-images/image-20200412185756659.png)

- 에 3.14159 의 값을 저장한 후 cp, ip, fp, dp 를 이용하여 xxxxx 에 저장된 값을

  char/int/float/double 로 해석하여 출력하는 프로그램을 작성하여 컴파일하고 실행한다.


```c++
cout << *cp << ' ' << *ip << ' ' << *fp << ' ' << ' ' << *dp << endl;
```
결과:![image-20200412190032121](/home/leebumseok/.config/Typora/typora-user-images/image-20200412190032121.png)
- gdb 를 이용하여 3.14159 가 저장된 (변수 d 의 위치의) 메모리의 값을 16진수로 출력한다.

결과: ![image-20200412185442332](/home/leebumseok/.config/Typora/typora-user-images/image-20200412185442332.png)

------



### Quiz 문제

------

1. char로 읽으면: n

2. int로 읽으면: -266631570

3. float로 읽으면: -1.92531e+29

4. 16진수로 debugger로 읽으면: 0xf01b866e

-----

   

긴 글 읽어 주셔서 감사합니다.



------

이범석

국민대학교 소프트웨어학부, 20171664

Mobile 010-6401-6042

qpwoeiru6486@gmail.com

ijkoo16@kookmin.ac.kr