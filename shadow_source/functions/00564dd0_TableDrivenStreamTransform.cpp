// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564DD0
// Canonical corpus name: sub_564DD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564DD0_00564dd0.c

void UnknownObject::TableDrivenStreamTransform()
{
    // Performs 16 rounds of a substitution-table-driven stream transform. It mixes two running state words (v3, v5) through byte-granular lookups into the 256-entry table a1[0..255] with rotate/OR permutations, branching on each bit of a3 from mask 0x8000 downward. On the clear-bit path it records v9, v8 and v6 into a1 at indices 256, 272 and 288 (indexed by the counter at a1[304]). Writes final state into a1 at indices 305..308 and returns v5 XOR v3. Called by RC4KeyScheduleInitialization.
    // ASSIGNMENT: Resets the output index at a1[304] to 0 [source:raw]
    // LOOP: Runs 16 iterations, shifting the bitmask down from 0x8000 [source:raw]
    // GUARD: Branches on the current bit of a3 via the test (bitmask & a3) [source:raw]
    // CALCULATION: Bit-set path: grows v6 as 2*v6+1 and mixes state_a and state_b through byte-indexed table lookups with byte-rotation and OR permutations [source:raw]
    // ASSIGNMENT: Bit-clear path: records v9, v8 and v6 into a1[256 + index], a1[272 + index] and a1[288 + index] then increments the index stored at a1[304] [source:raw]
    // CALCULATION: Bit-clear path: mixes state_a and state_b through byte-indexed table lookups with byte-rotation and OR permutations, then doubles v6 [source:raw]
    // ASSIGNMENT: Writes final state into a1: index 306 gets state_a, 305 gets state_b, 307 gets v6 and 308 gets the seed a2 [source:raw]
    // RETURN: Returns state_b XOR state_a [source:raw, function:0x00564DD0]

    // Conservative worker pseudocode:
    //   a1[304] = 0;
    //   state_a = 0; state_b = a2; v6 = 1;
    //   for (bitmask = 0x8000; bitmask; bitmask >>= 1) {
    //       if (bitmask & a3) {
    //           v6 = 2*v6 + 1;
    //           /* mix state_a/state_b through a1 byte-table with rotations * /
    //       } else {
    //           a1[256 + a1[304]] = v9;
    //           a1[272 + a1[304]] = v8;
    //           a1[288 + a1[304]++] = v6;
    //           /* mix state_a/state_b through a1 byte-table with rotations * /
    //           v6 *= 2;
    //       }
    //   }
    //   a1[306] = state_a; a1[305] = state_b; a1[307] = v6; a1[308] = a2;
    //   return state_b ^ state_a;
    // UNRESOLVED: The exact cipher/algorithm identity behind the substitution-table transform is not established from packet evidence.
    // UNRESOLVED: The layout and purpose of the a1 sub-regions at indices 256..308 beyond the byte table at 0..255 is unverified.
    // UNRESOLVED: The relationship of the a2/a3 inputs to the RC4KeyScheduleInitialization caller is unverified.
}
