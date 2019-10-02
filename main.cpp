#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QProcess>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  Widget w;
   // w.show();

   QFile myFile(":/MyFiles/file.xlsm");

   if(!QDir("/home/ashmantak/temp").exists()){
    QDir().mkdir("/home/ashmantak/temp");
   }

   QFile::copy(":/MyFiles/file.xlsm" , "/home/ashmantak/temp/file.xlsm");

   QFile("/home/ashmantak/temp/file.xlsm").setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);

 //  QProcess process;
 //  process.start("gnome-open",QStringList() << "/tmp/file.xlsm");

    QProcess::execute("xdg-open /home/ashmantak/temp/file.xlsm");
    return a.exec();
}
