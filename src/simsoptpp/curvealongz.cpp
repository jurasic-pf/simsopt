#include "curvealongz.h"
#include <cmath>

template<class Array>
void CurveAlongZ<Array>::gamma_impl(Array& data, Array& quadpoints) {
    int numquadpoints = quadpoints.size();
    data *= 0;
    for (int k = 0; k < numquadpoints; ++k) {
        data(k, 0) = 0;
        data(k, 1) = 0;
        data(k, 2) = tan(M_PI * (quadpoints[k] - 0.5));
    }
}

template<class Array>
void CurveAlongZ<Array>::gammadash_impl(Array& data) {
    data *= 0;
    for (int k = 0; k < numquadpoints; ++k) {
        data(k, 0) = 0;
        data(k, 1) = 0;
        data(k, 2) = M_PI / (cos(M_PI * (quadpoints[k] - 0.5)) * cos(M_PI * (quadpoints[k] - 0.5)));
    }
}

template<class Array>
void CurveAlongZ<Array>::gammadashdash_impl(Array& data) {
    data *= 0;
    for (int k = 0; k < numquadpoints; ++k) {
        data(k, 0) = 0;
        data(k, 1) = 0;
        data(k, 2) = 2 * M_PI * M_PI * tan(M_PI * (quadpoints[k] - 0.5)) / (cos(M_PI * (quadpoints[k] - 0.5)) * cos(M_PI * (quadpoints[k] - 0.5)));
    }
}

template<class Array>
void CurveAlongZ<Array>::dgamma_by_dcoeff_impl(Array& data) {
    // Empty implementation
}

template<class Array>
void CurveAlongZ<Array>::dgammadash_by_dcoeff_impl(Array& data) {
    // Empty implementation
}

template<class Array>
void CurveAlongZ<Array>::dgammadashdash_by_dcoeff_impl(Array& data) {
    // Empty implementation
}

#include "xtensor-python/pyarray.hpp"     // Numpy bindings
typedef xt::pyarray<double> Array;
template class CurveAlongZ<Array>;