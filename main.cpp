#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QDebug>
#include "notation.h"
#include "trebleclef.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    int id = QFontDatabase::addApplicationFont("://res/Metdemo.ttf");
    qDebug() << QFontDatabase::applicationFontFamilies(id).at(0);

    qmlRegisterType<Notation>("NotationLib", 1, 0, "Notation");
    qmlRegisterType<TrebleClef>("NotationLib", 1, 0, "TrebleClef");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
