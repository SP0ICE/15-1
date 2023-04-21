#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSettings settings("config.ini", QSettings::IniFormat); 
    settings.beginGroup("AppConfig"); 

    
    QString appName = settings.value("appname", "My App").toString();
    int appVersion = settings.value("appversion", 1).toInt();
    QString appAuthor = settings.value("appauthor", "Unknown").toString();
    QString appDescription = settings.value("appdescription", "").toString();

    qDebug() << "Application Name:" << appName;
    qDebug() << "Application Version:" << appVersion;
    qDebug() << "Application Author:" << appAuthor;
    qDebug() << "Application Description:" << appDescription;

    settings.endGroup(); 

    return a.exec();
}
