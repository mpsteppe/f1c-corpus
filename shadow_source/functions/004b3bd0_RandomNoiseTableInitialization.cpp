// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3BD0
// Canonical corpus name: RandomNoiseTableInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomNoiseTableInitialization_004b3bd0.c

void UnknownObject::RandomNoiseTableInitialization()
{
    // Initializes a 514-entry float noise table: entry 0 is set to 0.0, entries 1-256 are filled with (float)LCG() * 0.000030518509 giving uniform [0,1), entries 257-512 are filled with (float)LCG() * 0.000061037019 - 1.0 giving uniform [-1,1), and entry 513 receives the CPU timestamp counter via RDTSCTimestampRead. The PRNG is seeded from GetTickCount through TLSFieldSetter before the fill. Called once during startup by GameFileLoader.
    // ASSIGNMENT: Set the first table entry to 0.0: *this = 0.0. [field:this:0x00000000, source:raw]
    // CALL: Call GetTickCount through the imported function pointer __imp_GetTickCount to obtain a time-based seed value. [global:0x0059E0D4, source:raw]
    // CALL: Call TLSFieldSetter with the tick count to seed the TLS-backed PRNG state. [callee:0x005884E0, source:raw]
    // LOOP: Fixed 256-iteration loop filling entries 1-256: each entry = (float)RandLCGRandomNumberGenerator() * 0.000030518509, using the RandomScalingFactor constant read from flt_59E6E0. [callee:0x005884ED, global:0x0059E6E0, source:raw]
    // LOOP: Fixed 256-iteration loop filling entries 257-512: each entry = (float)RandLCGRandomNumberGenerator() * 0.000061037019 - 1.0, using the RandomRangeScale constant read from flt_5ACCF0. [callee:0x005884ED, global:0x005ACCF0, source:raw]
    // CALL: Call RDTSCTimestampRead with a scratch buffer and the address of table entry 513, writing the CPU timestamp counter into that entry. [callee:0x0055687B, source:raw]
    // RETURN: Return the value produced by RDTSCTimestampRead. [function:0x004B3BD0, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0.0;
    //   seed = GetTickCount();
    //   TLSFieldSetter(seed);
    //   for (i = 1; i <= 256; ++i) this[i] = (float)RandLCG() * 0.000030518509;
    //   for (i = 257; i <= 512; ++i) this[i] = (float)RandLCG() * 0.000061037019 - 1.0;
    //   return RDTSCTimestampRead(scratch, &this[513]);
    // UNRESOLVED: The exact pairing of the two scale literals (0.000030518509 and 0.000061037019) with globals flt_59E6E0 and flt_5ACCF0 is DERIVED from the existing analysis, not proven.
    // UNRESOLVED: Global flt_59E43C is listed by the existing analysis as read by this function, but the raw source text exposes only two scale constants; its specific role here is unclear.
    // UNRESOLVED: Owner object is unknown; this is a __thiscall initializer over an opaque float buffer.
    // UNRESOLVED: Entry 513 (RDTSC) and entry 0 (0.0) semantics: the table layout itself is not independently corroborated.
}
