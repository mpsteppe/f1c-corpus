// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3CE0
// Canonical corpus name: RandomNoiseValueGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomNoiseValueGenerator_004b3ce0.c

void UnknownObject::RandomNoiseValueGenerator()
{
    // Generates a noise value approximating a normal distribution: popcount of a 32-bit hash-based PRNG result gives a binomial term, combined with a noise-table float at the auto-incremented index, centered and scaled by 0.35355338 (~1/sqrt(8)). On the per-frame random/audio/noise path.
    // CALL: v2 = DeterministicHashPseudoRandomGenerator(this); hash-based PRNG feeding popcount and table index [callee:0x004B3C60, function:0x004B3CE0, source:raw]
    // LOOP: for i in 0..31: v3 += (v2 >> i) & 1; popcount of v2 as binomial distribution term [function:0x004B3CE0, source:raw]
    // CALCULATION: v5 = *(float *)&this[(unsigned __int8)(*this)++ + 257] * 0.5; read noise-table float, advance stored index [field:this:0x00000000, function:0x004B3CE0, source:raw]
    // CALCULATION: result = (v5 + (double)(v3 - 16)) * 0.35355338; center the binomial term and apply final scale [function:0x004B3CE0, source:raw]
    // RETURN: return computed noise value [function:0x004B3CE0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = DeterministicHashPseudoRandomGenerator(this);
    //   v3 = 0;
    //   for (i = 0; i < 32; ++i) v3 += (v2 >> i) & 1;
    //   v5 = *(float *)&this[(unsigned __int8)(*this)++ + 257] * 0.5;
    //   return (v5 + (double)(v3 - 16)) * 0.35355338;
    // UNRESOLVED: globals flt_59E450 and flt_5ACCF8 are read (R) but absent from the raw source text, which spells 0.5 and 0.35355338 as literals; existing analysis proposes DegreesToRadians / FinalScaleFactor [DERIVED] - unverified in this function
    // UNRESOLVED: field this+0x0 is read and post-incremented in source but packet marks it R only
    // UNRESOLVED: 0.35355338 (approx 1/sqrt(8)) inferred as final noise scale; exact roles of the two globals unconfirmed
}
