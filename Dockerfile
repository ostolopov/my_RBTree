FROM ubuntu:latest
LABEL authors="egorbaranov"

RUN apt-get update && \
    apt-get install -y \
    g++ \
    build-essential \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Копирование исходного кода
COPY . .

# Создание скрипта запуска
RUN echo '#!/bin/bash\n\
echo "Проверка файлов..."\n\
ls -la\n\
echo ""\n\
if [ -f "CMakeLists.txt" ]; then\n\
    echo "Сборка с помощью CMake..."\n\
    mkdir -p build\n\
    cd build\n\
    cmake ..\n\
    make\n\
    if [ -f "lab3" ]; then\n\
        echo "Запуск программы..."\n\
        ./lab3\n\
    else\n\
        echo "Программа не найдена после сборки"\n\
    fi\n\
else\n\
    echo "Прямая компиляция с g++..."\n\
    g++ -o lab3 main.cpp ind_funcs.cpp trees_structs.cpp utils.cpp\n\
    if [ $? -eq 0 ]; then\n\
        echo "Запуск программы..."\n\
        ./lab3\n\
    else\n\
        echo "Ошибка компиляции"\n\
    fi\n\
fi' > /entrypoint.sh && \
    chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]