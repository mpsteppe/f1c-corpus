// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559FB0
// Canonical corpus name: PRNG4UniformFloatsFromSeed
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PRNG4UniformFloatsFromSeed_00559fb0.c

void UnknownObject::PRNG4UniformFloatsFromSeed()
{
    // Generates up to four uniform floats into caller-supplied output pointers a3..a6. A seeding/validation call sub_559D80 gates the body; on success it reads a seed value from this[0x30C], increments it, and for each non-null output pointer invokes sub_58B077 with an advancing seed state to produce a float. Returns 1 when generation ran, 0 when the guard failed.
    // CALL: Call sub_559D80(this, a2): PRNG seeding or state validation that gates the generation path; a non-zero result opens the body. [callee:0x00559D80]
    // GUARD: Guard on sub_559D80 returning non-zero; otherwise skip generation and return 0. [source:raw]
    // CALCULATION: Read the seed at this[0x30C] and increment it by one; seed the advancing PRNG state a2 = seed + 1. [field:this:0x0000030C, source:raw]
    // ASSIGNMENT: Set the success flag v7 = 1 once generation begins. [source:raw]
    // GUARD: If output pointer a3 is non-null, fill it with the next uniform float. [source:raw]
    // CALL: *a3 = sub_58B077(seed, &a2): generate the first uniform float and advance the seed state a2. [callee:0x0058B077]
    // CALCULATION: Advance the seed state for the next draw: v10 = a2 + 1. [source:raw]
    // GUARD: If output pointer a4 is non-null, fill it with the next uniform float. [source:raw]
    // CALL: *a4 = sub_58B077(seed, &a2): generate the second uniform float and advance the seed state. [callee:0x0058B077]
    // CALCULATION: Advance the seed state for the next draw: v10 = a2 + 1. [source:raw]
    // GUARD: If output pointer a5 is non-null, fill it with the next uniform float. [source:raw]
    // CALL: *a5 = sub_58B077(seed, &a2): generate the third uniform float and advance the seed state. [callee:0x0058B077]
    // CALCULATION: Advance the seed state for the next draw: v10 = a2 + 1. [source:raw]
    // GUARD: If output pointer a6 is non-null, fill it with the final uniform float. [source:raw]
    // CALL: *a6 = sub_58B077(seed, &a2): generate the fourth uniform float (no further seed advance). [callee:0x0058B077]
    // RETURN: Return v7: 1 when generation ran, 0 when the seeding guard failed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_559FB0(State* this, int seed, float* o0, float* o1, float* o2, float* o3) {
    //     int ok = 0;
    //     if (sub_559D80(this, seed)) {
    //       int s = this[0x30C] + 1;
    //       ok = 1;
    //       if (o0) { *o0 = sub_58B077(s, &s); s = s + 1; }
    //       if (o1) { *o1 = sub_58B077(s, &s); s = s + 1; }
    //       if (o2) { *o2 = sub_58B077(s, &s); s = s + 1; }
    //       if (o3) { *o3 = sub_58B077(s, &s); }
    //     }
    //     return ok;
    //   }
    // UNRESOLVED: Exact role of sub_559D80 (seeding vs validation) is not proven; it only gates generation here.
    // UNRESOLVED: Transform from the advancing seed to a uniform float inside sub_58B077 is external and unknown.
    // UNRESOLVED: Interaction between caller-supplied a2 and the this[0x30C] seed is only partly visible.
    // UNRESOLVED: Meaning of the up-to-four output floats depends on the caller (SceneNode, SceneFileTopLevelParser) and is unknown here.
}
