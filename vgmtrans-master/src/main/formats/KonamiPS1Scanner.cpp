#include "pch.h"
#include "KonamiPS1Scanner.h"
#include "KonamiPS1Seq.h"

void KonamiPS1Scanner::Scan(RawFile *file, void *info) {
    uint32_t offset = 0;
    int numSeqFiles = 0;
    while (offset < file->size()) {
        if (KonamiPS1Seq::IsKDT1Seq(file, offset)) {
            std::wstring name = file->tag.HasTitle() ? file->tag.title : RawFile::removeExtFromPath(file->GetFileName());
            if (numSeqFiles >= 1) {
                std::wstringstream postfix;
                postfix << L" (" << (numSeqFiles + 1) << L")";
                name += postfix.str();
            }

            KonamiPS1Seq *newSeq = new KonamiPS1Seq(file, offset, name);
            if (newSeq->LoadVGMFile()) {
                offset += newSeq->unLength;
                numSeqFiles++;
                continue;
            }
            else {
                delete newSeq;
            }
        }
        offset++;
    }
}
