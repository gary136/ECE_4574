#ifndef COMPOSITECODER_H
#define COMPOSITECODER_H

#include "coder.h"
#include <vector>

class CompositeCoder : public Coder {
private:
    std::vector<Coder*> coders;

public:
    CompositeCoder(const QString& name);
//    void addCoder(Coder* coder);
    void addCoder(Coder* coder) override;
    QString encode(const QString& input) override;
    QString decode(const QString& input) override;
    QString getName() const;
    ~CompositeCoder();
};

#endif // COMPOSITECODER_H
