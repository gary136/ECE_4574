#ifndef COMPOSITECODER_H
#define COMPOSITECODER_H

#include "coder.h"
#include <vector>

class CompositeCoder : public Coder {
private:
    std::vector<Coder*> coders;

public:
    void addCoder(Coder* coder);
    QString encode(const QString& input) override;
    QString decode(const QString& input) override;
    ~CompositeCoder();
};

#endif // COMPOSITECODER_H
