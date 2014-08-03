# C Generic Arrays

[![Travis](https://api.travis-ci.org/seaneshbaugh/generic_array.png)](http://travis-ci.org/seaneshbaugh/generic_array)

A library that abuses C pre-processor macros to generate code for array data structures for nearly any underlying datatype. Just redefine some macros and then include generic_array.h to create a new set of functions. Out of the box 29 basic data types are supported. Adding your own should be trivial.

"Generic" is a bit of a misnomer.

## Generating Test Files

This library's test suite uses [Unity](https://github.com/ThrowTheSwitch/Unity) for unit testing. The sheer number of data types that are supported makes writing all of the tests by hand rather impractical. A [Thor](https://github.com/erikhuda/thor) script is included that will generate the test source files using some ERB templates and a list of data types. After running `bundle install` to install Thor, use `thor tests:generate` to generate the files. To force overwrites and skip confirmation use the `--force` option.

## Unity Fixture Malloc Overrides Patch

Before building the test suite you will need to patch your local copy of the Unity test framework. Unity overrides
the default malloc and free functions. I believe this is intended for testing for memory leaks (but I definitely could be wrong). The actual result is that, at least on the systems where I have built this, all sorts of segmentation faults occur. By running `thor patch:unity_malloc` (optionally with --force) your local copy will have the overrides commented out. It's far from an ideal solution, but the Unity malloc and free functions just seem to cause too many problems with otherwise fine tests.

## Running the Tests

The test suite can can be built with `make tests` or built and run with `make all`.

If you have [valgrind](http://valgrind.org/) you can run the test suite through it using `make valgrind`.
