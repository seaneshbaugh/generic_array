# C Generic Arrays

[![Travis](https://api.travis-ci.org/seaneshbaugh/generic_array.png)](http://travis-ci.org/seaneshbaugh/generic_array)

A library that abuses C pre-processor macros to generate code for array data structures for nearly any underlying datatype. Just redefine some macros and then include generic_array.h to create a new set of functions. Out of the box 29 basic data types are supported. Adding your own should be trivial.

"Generic" is a bit of a misnomer.

## Generating Test Files

This library's test suite uses [Unity](https://github.com/ThrowTheSwitch/Unity) for unit testing. The sheer number of data types that are supported makes writing all of the tests by hand rather impractical. A [Thor](https://github.com/erikhuda/thor) script is included that will generate the test source files using some ERB templates and a list of data types. After running `bundle install` to install Thor, use `thor tests:generate` to generate the files. To force overwrites and skip confirmation use the `--force` option.

## Running the Tests

The test suite can can be built with `make tests` or built and run with `make all`.
