#pragma once

#include "curve.h"

template<class Array>
class CurveAlongZ : public Curve<Array> {
    public:
        using Curve<Array>::quadpoints;
        using Curve<Array>::numquadpoints;
        using Curve<Array>::check_the_persistent_cache;

        CurveAlongZ(int _numquadpoints) : Curve<Array>(_numquadpoints) {}

        CurveAlongZ(vector<double> _quadpoints) : Curve<Array>(_quadpoints) {}

        CurveAlongZ(Array _quadpoints) : Curve<Array>(_quadpoints) {}

        inline int num_dofs() override {
            return 0;
        }

        void set_dofs_impl(const vector<double>& _dofs) override {
            // No dofs to set
        }

        vector<double> get_dofs() override {
            return vector<double>();
        }

        /**
         * @brief Returns an empty array as the derivative of gamma with respect to coefficients.
         * 
         * This function overrides the base class implementation to return an empty array.
         * 
         * @return Array& An empty array.
         */
        Array& dgamma_by_dcoeff() override {
            static Array empty_array;
            return empty_array;
        }

        /**
         * @brief Returns an empty array as the derivative of gammadash with respect to coefficients.
         * 
         * This function overrides the base class implementation to return an empty array.
         * 
         * @return Array& An empty array.
         */
        Array& dgammadash_by_dcoeff() override {
            static Array empty_array;
            return empty_array;
        }

        /**
         * @brief Returns an empty array as the derivative of gammadashdash with respect to coefficients.
         * 
         * This function overrides the base class implementation to return an empty array.
         * 
         * @return Array& An empty array.
         */
        Array& dgammadashdash_by_dcoeff() override {
            static Array empty_array;
            return empty_array;
        }

        /**
         * @brief Returns an empty array as the derivative of gammadashdashdash with respect to coefficients.
         * 
         * This function overrides the base class implementation to return an empty array.
         * 
         * @return Array& An empty array.
         */
        Array& dgammadashdashdash_by_dcoeff() override {
            static Array empty_array;
            return empty_array;
        }

        void gamma_impl(Array& data, Array& quadpoints) override;
        void gammadash_impl(Array& data) override;
        void gammadashdash_impl(Array& data) override;
        void dgamma_by_dcoeff_impl(Array& data) override;
        void dgammadash_by_dcoeff_impl(Array& data) override;
        void dgammadashdash_by_dcoeff_impl(Array& data) override;
};