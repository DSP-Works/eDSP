//
// Created by Mohammed Boujemaoui on 26/10/2017.
//

#ifndef EDSP_CEPSTRUM_H
#define EDSP_CEPSTRUM_H


#include "config.h"
#include "fft.h"
#include "ifft.h"
#include "math/complex.h"
EDSP_BEGING_NAMESPACE
    namespace frequency {
        template<typename T, std::size_t N = 1024>
        class EDSP_EXPORT Cepstrum  {
        public:
            explicit Cepstrum() = default;
            virtual ~Cepstrum() = default;
            template<typename Container>
            typename std::enable_if<std::is_same<typename Container::value_type,
                    T>::value, Container>::type
            compute(const Container& input) {
                const auto& fft_data = fft.compute(math::complex::real_to_complex(input));
                std::transform(fft_data.begin(), fft_data.end(), fft_data.begin(), [](std::complex<T>& value) {
                    return std::complex<T>( 2 * std::log(std::abs(value)), 0);
                });

                const auto& out = ifft.compute(fft_data);
                Container data(N);
                std::transform(out.begin(), out.end(), data.begin(), [](const std::complex<T>& value) {
                    return value.real();
                });
                return data;
            }
        private:
            frequency::FFT<T,N> fft;
            frequency::IFFT<T,N> ifft;
        };
    }
EDSP_END_NAMESPACE

#endif //EDSP_CEPSTRUM_H