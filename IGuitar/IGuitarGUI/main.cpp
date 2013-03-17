#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include "Controler.hpp"

int main(int argc, char *argv[]){
  QApplication app(argc, argv);

  QTranslator translator;
  translator.load(":/translations/IGuitarGUI_fr");
  app.installTranslator(&translator);

  QRect screenGeo = QApplication::desktop()->screenGeometry();

  Configuration::setWindowSize(screenGeo); // Ne fonctionne pas sur les multi ecran
  new Controler();

  return app.exec();
}
