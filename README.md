# ZPR - Warcaby wariant rosyjski

## Technologie
Technologie wykorzystywane w projekcie:
- Python -> Flask, Flask-SocketIO, eventlet, PyTest
- C++ -> boost_unit_test_framework, Boost.Python
- JavaScript

## Budowanie i uruchamianie aplikacji

### Wymagania wstępne
- **Windows**
  1. msvc (min. 14.0)
  2. Python 3.7 (zlokalizowany w C:\Python37 , jeśli scons ma zadziałać bez modyfikacji)
  3. boost 1_70_0 (biblioteki linkowane dynamicznie; zlokalizowany w C:\boost_1_70_0 , jeśli scons ma zadziałać bez modyfikacji)
  4. pip3 (powinien być domyślnie zainstalowany wraz z Pythonem)
  5. scons (powinien być domyślnie zainstalowany wraz z Pythonem)
  6. Flask, flask-socketio, eventlet, pyd, pytest 
- **Linux (Ubuntu 18.04 Bionic)**
  1. g++
  2. Python 3.5 
  3. libboost-all-dev (boost), scons, python3-pip, Flask, flask-socketio, eventlet, pytest 

### Kompilacja
Należy wywołać z poziomu głównego katalogu projektu:
**sconst**

### Czyszczenie plików utworzonych przez SConst
Należy wywołać z poziomu głównego katalogu projektu:
**sconst --clean**

