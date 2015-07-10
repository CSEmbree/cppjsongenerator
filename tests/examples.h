/*
 * Title:    json_generator
 * Author:   C. Embree
 * Contact:  cse@cameronembree.com
 * Created:  25-OCT-2014
 * Edited:   25-OCT-2014
 * Notes:    Handles dumb boarderline-hardcoded creation of a json formatted file
 */

#ifndef JSON_GENERATOR_EXAMPLES_H
#define JSON_GENERATOR_EXAMPLES_H


#include "../src/json_generator.h"

using namespace std;

void example1();
void example2();
void example3();
void example4();

void make_example_output(json_generator *jg);
void write_output(json_generator *jg);
void display_output(json_generator *jg);

#endif
