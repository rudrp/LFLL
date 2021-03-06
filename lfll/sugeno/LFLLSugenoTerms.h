/*
The MIT License (MIT)

Copyright (c) 2013 Nicolas Pauss

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef LFLLSUGENOTERMS_H
#define LFLLSUGENOTERMS_H

#include <lfll/engine/LFLLDefinitions.h>
#include <lfll/engine/LFLLArray.h>


LFLL_BEGIN_NAMESPACE

/**
 * \brief Sugeno zero order term
 */
struct LFLLSugenoZeroOrderTerm
{
    scalar value;

	/** 
	 * \brief Compute term value
	 */
	template <size_t N>
    scalar computeTermValue(const LFLLArray<N>&) const
    {
        return value;
    }
};

/**
 * \brief Sugeno first order term
 * \tparam NI Number of inputs
 */
template <size_t NI>
struct LFLLSugenoFirstOrderTerm
{
    scalar values[NI+1];

	/** 
	 * \brief Compute term value
	 * \param inputs Inputs
	 */
    scalar computeTermValue(const LFLLArray<NI>& inputs) const
    {
        scalar result = values[NI];
        for (size_t i = NI ; i > 0 ; )
        {
            --i;
            result += values[i] * inputs[i];
        }
        return result;
    }
};

LFLL_END_NAMESPACE


#endif //LFLLSUGENOTERMS_H
