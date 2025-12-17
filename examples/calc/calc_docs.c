/*
    Copyright © 2025 Gaël Fortier <gael.fortier.1@ens.etsmtl.ca>
*/

#include "cdocs/cdocs.h"

void calc_generate_docs(void) {
    _cdocs_fn_struct functions[] = {
        _cdocs_fn(_cdocs_fn_f(calc_even, "Tells if a value is even or not."),
              _cdocs_fn_r(int, "1 if even, 0 if odd."),
              _cdocs_fn_p(int value, "An integer value.")),

        _cdocs_fn(_cdocs_fn_f(calc_mean, "Calculates the average."),
              _cdocs_fn_r(float, "The average. "),
              _cdocs_fn_p(const float* set, "Values used to get the average."),
              _cdocs_fn_p(unsigned size, "Number of values in set."))
    };

    _cdocs_generate_documentation("calc", functions);
}
