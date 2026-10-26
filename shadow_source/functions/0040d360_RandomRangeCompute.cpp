// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D360
// Canonical corpus name: ShortComputation_d360
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_d360_0040d360.c

void UnknownObject::RandomRangeCompute()
{
    // Computes and stores a randomized value within a clamped [min, max) range: sets an updated flag byte at 0x2E, clamps and stores min (a2) at 0x30 and max (a3, fallback a2+5) at 0x34, draws a random integer from the LCG, computes v4 + (rand % (max - min)), stores it as a float at 0x3C, and returns the LCG integer quotient rand / (max - min).
    // ASSIGNMENT: Set flag byte at this + 0x2E to 1 (marks the range as updated on each call). [field:this:0x0000002E]
    // GUARD: If a2 <= 0 store 0 as min (this + 0x30), else store a2. [field:this:0x00000030]
    // GUARD: If a3 <= 0 or a3 <= a2 store a2 + 5 as max (this + 0x34), else store a3. [field:this:0x00000034]
    // CALL: Draw random integer v5 via RandLCGRandomNumberGenerator(). [callee:0x005884ED]
    // CALCULATION: Compute v6 = max - min, v8 = v5 % v6, and store v4 + v8 (random value in [min, max)) as a float at this + 0x3C. [field:this:0x00000030, field:this:0x00000034, field:this:0x0000003C]
    // RETURN: Return the LCG integer quotient v5 / v6 (side channel of the random draw). [function:0x0040D360]

    // Conservative worker pseudocode:
    //   this->updated = 1;
    //   this->min = (a2 <= 0) ? 0 : a2;
    //   this->max = (a3 <= 0 || a3 <= a2) ? (a2 + 5) : a3;
    //   v5 = RandLCGRandomNumberGenerator();
    //   v6 = this->max - this->min;
    //   this->random_float = (float)(this->min + (v5 % v6));
    //   return v5 / v6;
    // UNRESOLVED: Float at 0x3C stores min + (rand % (max-min)); the packet's random value range is open on the upper side relative to max.
    // UNRESOLVED: The struct owning offsets 0x2E/0x30/0x34/0x3C is not evidenced by the packet.
}
