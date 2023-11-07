#ifndef CODER_H
#define CODER_H

#include <QString>
#include <QObject>

//class Coder {
class Coder : public QObject {
    Q_OBJECT
public:
    Coder(const QString& name); // Constructor with a name parameter
    virtual QString encode(const QString& input) = 0;
    virtual QString decode(const QString& input) = 0;
    virtual QString getName() const = 0;
    virtual void addCoder(Coder* coder) {}
    virtual ~Coder() {}
//    QString name; // Member variable to store the name

private:
    QString name; // Member variable to store the name
};


#endif // CODER_H
