// Geometric Tools, LLC
// Copyright (c) 1998-2014
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.3.0 (2010/09/07)

#ifndef CPULOCALSOLVER1_H
#define CPULOCALSOLVER1_H

#include "CpuPdeSolver1.h"

class CpuLocalSolver1 : public CpuPdeSolver1<float>
{
public:
    CpuLocalSolver1 (int dimension, const Image1<float>* initial,
        const Image1<unsigned char>* domain, float dt, float dx,
        const std::string& folder, bool& success);

    virtual ~CpuLocalSolver1 ();

private:
    void GetIntegral (float& umax, float& integral);

    virtual float Equation (int i0, const Image1<float>& u0,
        const Image1<float>& u1);

    virtual bool OnPreIteration (uint64_t iteration);
    virtual bool OnPostIteration (uint64_t iteration);

    float* mReadBack;
    std::string mFolder;
};

#endif
