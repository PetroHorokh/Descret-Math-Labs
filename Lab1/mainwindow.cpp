#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include<list>
#include <bits/stdc++.h>

std::list<std::string> split(std::string);
bool repeats(std::list<std::string>);
std::string type_checker(std::list<std::string>);
bool intersection(std::list<std::string>, std::list<std::string>);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked()
{
    ui->statusbar->showMessage("");

    QString arr = ui->InputLine1->text();
    std::string l1 = arr.toUtf8().constData();

    if(l1 == ""){ui->statusbar->showMessage("Статус: Перша множина була пуста!"); return;}

    arr = ui->InputLine2->text();
    std::string l2 = arr.toUtf8().constData();

    if(l2 == ""){ui->statusbar->showMessage("Статус: Друга множина була пуста!"); return;}

    std::list<std::string> m1 = split(l1);
    std::list<std::string> m2 = split(l2);

    if(repeats(m1)){ui->statusbar->showMessage("Статус: Перша множина має повтори"); return;}
    if(repeats(m2)){ui->statusbar->showMessage("Статус: Друга множина має повтори"); return;}

    std::string type_of_m1 = type_checker(m1);
    std::string type_of_m2 = type_checker(m2);

    if(type_of_m1 == "0" && type_of_m2 == "0") {ui->statusbar->showMessage("Статус: Обидві множини були неправильно задані!"); return;}
    else if(type_of_m1 == "0") {ui->statusbar->showMessage("Статус: Перша множина була неправильно задана!"); return;}
    else if(type_of_m2 == "0") {ui->statusbar->showMessage("Статус: Друга множина була неправильно задана!"); return;}

    if(type_of_m1 != type_of_m2) {ui->statusbar->showMessage("Статус: Множини різного роду!"); return;}

    if(intersection(m1, m2)) {ui->statusbar->showMessage("Статус: Множини не перетинаються!"); return;}
    else {ui->statusbar->showMessage("Статус: Множини перетинаються!"); return;}
}

std::list<std::string> split(std::string line)
{
    std::list<std::string> elems;

    line.erase(remove(line.begin(), line.end(), ' '), line.end());
    line += ",";

    std::string elem = "";
    for (auto s : line){
        if(s==',' && elem != ""){
            elems.push_back(elem);
            elem = "";
        }
        else if(s != ','){
            elem += s;
        }
    }
    return elems;
}

bool repeats(std::list<std::string>m){
    for(auto const& elem:m ){
        int count = 0;
        for(auto const& elem_d:m ){
            if (elem == elem_d) count++;
            if(count == 2) return true;
        }
    }

    return false;
}

std::string type_checker(std::list<std::string>m){
    int max_length_of_word = 0;
    char type_to_check = m.front()[0];

    for(auto elem : m){
       for(auto charin : elem){
           if((isdigit(charin) && isalpha(type_to_check))||(isdigit(type_to_check) && isalpha(charin))) return "0";
       }
        if(elem.length() > max_length_of_word) max_length_of_word = elem.length();
    }

    if (isalpha(type_to_check) && max_length_of_word > 1) return "words";
    if (isalpha(type_to_check) && max_length_of_word == 1) return "letters";
    if (isdigit(type_to_check)) return "numbers";

   return "";
}

bool intersection(std::list<std::string>m1, std::list<std::string>m2){
    for(auto const& elem1 : m1){
        for(auto const& elem2 : m2){
            if(elem1 == elem2) return false;
        }
    }
    return true;
}
