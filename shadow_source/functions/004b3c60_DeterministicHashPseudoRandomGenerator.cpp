// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3C60
// Canonical corpus name: DeterministicHashPseudoRandomGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DeterministicHashPseudoRandomGenerator_004b3c60.c

void UnknownObject::DeterministicHashPseudoRandomGenerator()
{
    // Entropy-mixing pseudo-random DWORD generator. Reads the x86 RDTSC timestamp into v11 via RDTSCTimestampRead, updates a multiplicative accumulator at this+0x804 using the LCG-style step 219837*(this[513]+2), mixes in the timestamp, then indexes a float table inside this by an auto-incrementing byte counter (this+0x0) to obtain a noise sample. Combines that sample with GetTickCount (via a scaled CRTFtol term v12*-3499.01), an LCG call (RandLCGRandomNumberGenerator), and the accumulated timestamp, and returns (2*v9+1)*v7+v11. Called by RandomNoiseValueGenerator, AIDriverCountSetup, sub_4CB120, and TelemetryDataDump.
    // CALL: Call RDTSCTimestampRead(v13, &v11) to capture the RDTSC timestamp; v11 receives the low 32 bits. [callee:0x0055687B, source:raw]
    // CALCULATION: Compute v2 = 219837 * (this[513] + 2), an LCG-style multiplicative step over the accumulator at this+0x804. [field:this:0x00000804, source:raw]
    // ASSIGNMENT: Store the new accumulator: this[513] = v2. [field:this:0x00000804, source:raw]
    // CALCULATION: Mix the timestamp into the state: v11 = v2 + v11. [source:raw]
    // ASSIGNMENT: Read the byte counter from this+0x0 as v4 and post-increment it (*this = v4 + 1). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Read a float noise sample from inside this at the counter-derived element (float at index (byte)v4+1) into v5/v12. [source:raw]
    // CALL: Call GetTickCount via the __imp_GetTickCount import to obtain a system-timer seed. [global:0x0059E0D4, source:raw]
    // CALL: Call CRTFtol(v12 * -3499.01) to truncate the scaled noise sample to an integer. [callee:0x00587BDC, source:raw]
    // CALCULATION: Compute v7 = TickCount - CRTFtol(v12 * -3499.01). [source:raw]
    // CALL: Call RandLCGRandomNumberGenerator to obtain an additional LCG random value v9. [callee:0x005884ED, source:raw]
    // CALCULATION: Combine the terms and return (2*v9 + 1) * v7 + v11. [source:raw]

    // Conservative worker pseudocode:
    //   RDTSCTimestampRead(v13, &v11);
    //   this[513] = 219837 * (this[513] + 2);
    //   v11 += this[513];
    //   v4 = this[0]++;
    //   v12 = *(float*)(this + v4 + 1);
    //   TickCount = GetTickCount();
    //   v7 = TickCount - CRTFtol(v12 * -3499.01);
    //   v9 = RandLCGRandomNumberGenerator();
    //   return (2*v9 + 1) * v7 + v11;
    // UNRESOLVED: flt_5ACCF4 is listed as a read global but does not appear in the raw source text; its role here is unclear.
    // UNRESOLVED: RandLCGRandomNumberGenerator is called with v8, which the decompiler leaves uninitialized; the actual seed argument is unclear.
    // UNRESOLVED: Semantic meaning of the constants 219837 and -3499.01 is not established from this packet.
    // UNRESOLVED: The float noise table read lands at an offset inside this computed from the counter, not a field listed in the packet.
}
