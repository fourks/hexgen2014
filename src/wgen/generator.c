/*
 
 src/wgen/generator.h - state for the generator
 
 ------------------------------------------------------------------------------
 
 Copyright (c) 2014 Ben Golightly <golightly.ben@googlemail.com>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ------------------------------------------------------------------------------
 
*/

#include "base.h"
#include "wgen/wgen.h"
#include "graph/graph.h"

int GeneratorInit(Generator *g, unsigned int seed)
{
    g->rng = RNGNew(RNG_ISAAC, seed);
    if (!g->rng) { X(RNGNew); }
    
    if (!ClockInit(&g->clock)) { X(ClockInit); }
    
    g->mask_sampler = SampleDefault;
    g->mask_sampler_rsc = NULL;
    
    g->grapher = NULL;
    
    return 1;
    
    err_ClockInit:
        RNGFree(g->rng);
    err_RNGNew:
        return 0;
}


int GeneratorUseGrapher(Generator *g, Grapher *grapher)
{
    if (!g) { X2(bad_arg, "NULL generator pointer"); }
    
    g->grapher = grapher;
    
    return 1;
    
    err_bad_arg:
        return 0;
}


int GeneratorUseMaskSampler
(
    Generator *g,
    double (*sampler)(void *p, double x, double y, double w, double h)
)
{
    g->mask_sampler = sampler;
    return 1;
}
