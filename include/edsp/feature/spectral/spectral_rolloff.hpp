/**
 * eDSP, A cross-platform Digital Signal Processing library written in modern C++.
 * Copyright (c) 2018 All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * File: spectral_rolloff.hpp
 * Created by: Mohammed Boujemaoui Boulaghmoudi
 * Created at: 14/10/18
 */

#ifndef EDSP_SPECTRAL_ROLLOFF_HPP
#define EDSP_SPECTRAL_ROLLOFF_HPP

#include <edsp/feature/statistics/rolloff.hpp>

namespace edsp { namespace feature { inline namespace spectral {

    /**
     * @brief Computes the spectral roll-off of the of the magnitude spectrum represented by the elements in the range [first, last)
     *
     * The spectral roll-off point is the frequency so that \f$ \alpha \f$ of the signal energy is
     * contained below this frequency.
     *
     * @param first Forward iterator defining the begin of the magnitude spectrum.
     * @param last Forward iterator defining the end of the magnitude spectrum.
     * @param percentage Number between [0, 1] representing the percentage of the total energy of the roll-off frequency.
     * @return Estimated roll-off index.
     * @see statistics::rolloff
     */
    template <typename ForwardIt, typename Numeric>
    constexpr auto spectral_rolloff(ForwardIt first, ForwardIt last, Numeric percentage = 0.95) {
        return statistics::rolloff(first, last, percentage);
    }

}}} // namespace edsp::feature::spectral

#endif //EDSP_SPECTRAL_ROLLOFF_HPP
