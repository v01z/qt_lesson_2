#include "parsetext.h"

ParseText::ParseText(): text{ "" } {}

bool ParseText::findAndReplace(QString istr)
{
    bool ret_val { false };

    for (size_t i{}; i < 4; ++i) // 4 - size of specSymbols[]
        {
        int j {};

        while ((j = istr.indexOf(specSymbols[i].first)) != -1)
            {
                ret_val = true;
                istr.replace(j, specSymbols[i].first.length(),
                    specSymbols[i].second);
            }
        }

    text = std::move(istr); //We dont need extra copy

    return ret_val;
}

const QString &ParseText::getText() const
   {
      return  text;
   }
