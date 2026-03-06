# Philosophers 👴

<div align="center">

<img src="https://i.imgur.com/GFMvD0W.gif" height="500" > </img>

*A dining philosophers problem simulation*  

[![42 School](https://img.shields.io/badge/School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

</div>

## 📖 About
Philosophers is a 42 project about threading and concurency. The objective is to simulate the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) in a program which lets you define how many philosophers are at the table as well as how long they sleep, eat and have to eat before dying.

## ✨ Features

- Multi-hreaded simulation - In the philo binary, each philosopher is a thread
- Multi-process simulation - In the philo_bonus binary, each philosopher is a process

## 🚀 Getting Started

### Download from [latest](https://github.com/ghostyghast/philosophers/releases/latest)

### or

### Compile from source

#### Prerequisites

- **GCC** compiler
- **Make**

1. **Clone the repository**
```bash
git clone https://github.com/ghostyghast/philosophers
cd philosophers/
```

2. **Compile the project**
```bash
make -C ./philo
make -C ./philo_bonus
```
## 🔮 Usage

You must define : 
- how many philosophers are dining
- how long they can live before having a meal in ms
- how long they take to eat in ms
- how long they take to sleep in ms.
- (optionally) how many meals they have to eat before leaving the table
```
philo <number of philos> <life duration> <eat duration> <sleep duration> [meals to eat]
```
For a clearer understanding of a timeline of events, you can paste your output into [this visualiser](https://rom98759.github.io/Philosophers-visualizer/)


## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines.