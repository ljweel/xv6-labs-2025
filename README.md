# xv6-labs-2025 학습 저장소

이 저장소는 [MIT 6.S081 운영체제 과제](https://pdos.csail.mit.edu/6.1810/2025/index.html)를 수행하는 공간입니다.
각 과제별 소스 코드는 아래 브랜치에 각각 보관되어 있습니다.

## 브랜치 목록
- **util**: Lab 1 실습 코드
- **syscall**: Lab 2 실습 코드
- ...

## 실행 방법
1. `git checkout [브랜치명]`
2. `make qemu`

## 채점 방법
- 해당 브랜치의 전체 채점: `make grade`
- 해당 브랜치의 하나만 채점(예시 : sleep):
    - `./grade-lab-util sleep`
    - `make GRADEFLAGS=sleep grade`

## 블로그

https://ljweel.github.io//posts/xv6/ 에서 환경 설정 및 과제 풀이를 작성합니다.
