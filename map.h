#ifndef MAP_H
#define MAP_H

#include <QWidget>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

public slots:
    void handleKeyPress(int key);
    void setNomJoueur(const QString &nom);

private:
    Ui::Map *ui;

    void showExtFaculte();
    void showIntFaculte();
    void showCombat();
    void showGenidex();
    void showHistoRencontre();
    void quitGame();

    QString nomJoueur = "default";
    bool isPaused = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // MAP_H
