//
// Created by Mohammed Boujemaoui on 16/10/2017.
//

#ifndef EDSP_IDCT_H
#define EDSP_IDCT_H

#include "frequency/dct.h"
EDSP_BEGING_NAMESPACE
    namespace frequency {
        class IDCT : BaseTransform {
        public:
            explicit IDCT(DCT_Type t = DCT_Type::Type_I) : BaseTransform(), t(t) { setType(t); }
            DCT_Type type() const { return t; }
            void setType(DCT_Type t) {
                IDCT::t = t;
            }

            template <class InputIterator, class OutputIterator>
            void compute_r2r(InputIterator __first, InputIterator __last, OutputIterator __out) {
                const auto m_size = std::distance(__first, __last);
                if (size != m_size && plan != nullptr) {
                    fftw_destroy_plan(plan);
                    size = m_size;
                    plan = fftw_plan_r2r_1d(static_cast<int>(size),
                                            PTR(__first),
                                            PTR(__out),
                                            format(),
                                            FFTW_ESTIMATE);
                }
                fftw_execute_r2r(plan, PTR(__first), PTR(__out));
            }

        private:
            DCT_Type t{DCT_Type::Type_I};
            fftw_r2r_kind format() const {
                switch(IDCT::t) {
                    case Type_I: return FFTW_REDFT00;
                    case Type_II: return FFTW_REDFT10;
                    case Type_III: return FFTW_REDFT01;
                    case Type_IV: return FFTW_REDFT11;
                    default: return FFTW_REDFT00;
                }
            }
        };
    }
EDSP_END_NAMESPACE
#endif //EDSP_IDCT_H
