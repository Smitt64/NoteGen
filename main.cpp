#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QDebug>
#include <QQuickView>
#include <QQmlFileSelector>
#include <QQmlContext>
#include "notation.h"
#include "trebleclef.h"
#include "note.h"
#include "noteapi.h"

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Bruce Company");
    app.setOrganizationDomain("brucecompany.com");
    app.setApplicationName("Music note generator");

    int id = QFontDatabase::addApplicationFont("://res/Metdemo.ttf");
    qDebug() << QFontDatabase::applicationFontFamilies(id).at(0);

    qRegisterMetaType<Note::MusicNote>("Note::MusicNote");
    qmlRegisterType<Notation>("NotationLib", 1, 0, "Notation");
    qmlRegisterType<TrebleClef>("NotationLib", 1, 0, "TrebleClef");
    qmlRegisterType<Note>("NotationLib", 1, 0, "Note");
    qmlRegisterType<NoteApi>("NotationLib", 1, 0, "NoteApi");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ApiNote", pNoteApi);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
