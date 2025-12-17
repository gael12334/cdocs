/*
    Copyright © 2025 Gaël Fortier <gael.fortier.1@ens.etsmtl.ca>
*/

#include "cdocs.h"

int main(int argc, char** argv) {
    _cdocs_fn_struct functions[] = {
        _cdocs_fn(
            _cdocs_fn_f(_cdocs_fn_f, _cdocs_code(_cdocs_fn_f_struct) " initializer; function description."),
            _cdocs_fn_r(_cdocs_fn_f_struct, "Object containing the function name and description."),
            _cdocs_fn_p(_name, "The function name."),
            _cdocs_fn_p(_desc, "The description.")
        ),
        _cdocs_fn(
            _cdocs_fn_f(_cdocs_fn_r, _cdocs_code(_cdocs_fn_r_struct) " initializer; return description."),
            _cdocs_fn_r(_cdocs_fn_r_struct, "Object containing the return type and description."),
            _cdocs_fn_p(_type, "The return type of the function."),
            _cdocs_fn_p(_desc, "The description.")
        ),
        _cdocs_fn(
            _cdocs_fn_f(_cdocs_fn_p, _cdocs_code(_cdocs_fn_p_struct) " initializer; parameter description."),
            _cdocs_fn_r(_cdocs_fn_p_struct, "Object containing the parameter signature and description."),
            _cdocs_fn_p(_sig, "Parameter signature."),
            _cdocs_fn_p(_desc, "The description.")
        ),
        _cdocs_fn(
            _cdocs_fn_f(_cdocs_generate_documentation, "Generates a markdown file with provided documentation."),
            _cdocs_fn_r(void, "N/A"),
            _cdocs_fn_p(const char* subject, "The documentation subject."),
            _cdocs_fn_p(_cdocs_fn_struct* functions, "An array on the stack containing the functions documentation objects.")
        ),
        _cdocs_fn(
            _cdocs_fn_f(_cdocs_code, "Inserts monospace text in descriptions."),
            _cdocs_fn_r(const char*, "Monospace text."),
            _cdocs_fn_p(x, "Anything.")
        )
    };

    _cdocs_generate_documentation("cdocs", functions);
    return 0;
}