/*
 * EasyDSP, A cross-platform Digital Signal Processing library written in modern C++.
 * Copyright (C) 2018 Mohammed Boujemaoui Boulaghmoudi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along withº
 * this program.  If not, see <http://www.gnu.org/licenses/>
 *
 * Filename: pink_noise.hpp
 * Author: Mohammed Boujemaoui
 * Date: 31/7/2018
 */
#ifndef EASYDSP_PINK_NOISE_HPP
#define EASYDSP_PINK_NOISE_HPP

#include "white_noise_generator.hpp"

namespace easy { namespace dsp { namespace random {

    template <typename T, typename Engine = std::mt19937>
    struct PinkNoiseGenerator {
        using result_type = T;
        inline PinkNoiseGenerator(result_type min, result_type max) :
            generator_(WhiteNoiseGenerator<result_type>(min, max)) {

        }

        inline result_type operator()() {
            result_type white = generator_();
            b0 = 0.99886 * b0 + white * 0.0555179;
            b1 = 0.99332 * b1 + white * 0.0750759;
            b2 = 0.96900 * b2 + white * 0.1538520;
            b3 = 0.86650 * b3 + white * 0.3104856;
            b4 = 0.55000 * b4 + white * 0.5329522;
            b5 = -0.7616 * b5 - white * 0.0168980;
            result_type output = (b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362) * 0.11;
            b6 = white * 0.115926;
            return output;
        }
    private:
        result_type b0{0};
        result_type b1{0};
        result_type b2{0};
        result_type b3{0};
        result_type b4{0};
        result_type b5{0};
        result_type b6{0};
        WhiteNoiseGenerator<T, Engine> generator_;
    };

}}}

#endif // EASYDSP_PINK_NOISE_HPP
