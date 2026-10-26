// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564F10
// Canonical corpus name: sub_564F10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564F10_00564f10.c

void UnknownObject::GenerateKeystreamWords()
{
    // PRNG-style keystream generator. Maintains four persistent state words in a1 (dword indices 307, 304, 306, 305) plus byte-indexed tables around dword indices 256, 272 and 288. Refills a 16-entry table while an internal counter is below 0x10000, then emits count words of mixed keystream into the output buffer a2 as result ^ mix1. Persists the updated state back into a1[306], a1[307], a1[304] and a1[305] and returns the final mix2 value. The caller 0x00565140 consumes it as a rolling XOR key stream over a 16-dword block at a1+309.
    // ASSIGNMENT: Load persistent state into locals: counter from a1[307], cursor v5 from a1[304], mix1 from a1[306] and mix2 from a1[305]. [source:raw]
    // ASSIGNMENT: Initialize the output cursor to a2 and compute the end pointer as a2 + a3. [source:raw]
    // GUARD: Enter the outer loop only when the output range is non-empty (a2 < a2 + a3). [source:raw]
    // LOOP: Outer do-while over output words, advancing the output cursor until it reaches the end pointer. [source:raw]
    // GUARD: Inner refill runs only while the counter is below 0x10000. [source:raw]
    // LOOP: Inner do-while that regenerates the 16-entry table starting at a1[v5 + 272], doubling the counter each step until it reaches 0x10000. [source:raw]
    // ASSIGNMENT: Write three table entries during refill: a1[v5+272+16] gets the current counter, a1[v5+272] gets a summed value, and a1[v5+272-16] gets another summed value. [source:raw]
    // CALCULATION: Mix state through byte-indexed table lookups and 8/24-bit rotate combinations (on v10, v11, v12 and v13), updating mix1 and mix2. [source:raw]
    // ASSIGNMENT: Emit one output word: *v17 = result ^ v6. [source:raw]
    // CALCULATION: Decrement the cursor v5, clamping it to zero when negative, then rebuild the next seed as v3 = 2 * a1[v5 + 288] + 1. [source:raw]
    // CALCULATION: Further byte-indexed mix using tables at a1[v5 + 272] and a1[v5 + 256] together with complement/rotate operations to update mix2 and mix1. [source:raw]
    // ASSIGNMENT: Persist updated state back into the object: a1[306] = mix1, a1[307] = counter, a1[304] = cursor, a1[305] = mix2. [source:raw]
    // RETURN: Return the final mix2 value. [source:raw, function:0x00564F10]
    // UNKNOWN: Field evidence marks offset 0x0 of this as read/written, but the raw source only accesses higher dword indices (256..307); the access at 0x0 is not visible in the raw text. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_564F10(_DWORD* a1, unsigned int* out, int count) {
    //     unsigned int counter = a1[307];
    //     int cursor = a1[304];
    //     unsigned int mix1 = a1[306];
    //     unsigned int mix2 = a1[305];
    //     unsigned int* dst = out;
    //     unsigned int* end = &out[count];
    //     if ((unsigned int)out < (unsigned int)end) {
    //       do {
    //         if (counter < 0x10000) {
    //           unsigned int* tbl = &a1[cursor + 272];
    //           do {
    //             unsigned int s = counter + mix2;
    //             tbl[16] = counter;
    //             unsigned int t = s + mix1;
    //             counter *= 2;
    //             unsigned int u = t + s;
    //             *tbl = t;
    //             tbl[-16] = u;
    //             ++cursor;
    //             ++tbl;
    //             // byte-indexed table lookups + 8/24-bit rotates update mix1/mix2
    //           } while (counter < 0x10000);
    //         }
    //         *dst = mix2 ^ mix1;
    //         --cursor;
    //         ++dst;
    //         if (cursor < 0) cursor = 0;
    //         // further table mixes from a1[cursor+272] / a1[cursor+256] /
    //         //   a1[cursor+288] rebuild mix2, mix1 and counter (= 2*a1[cursor+288] + 1)
    //       } while ((unsigned int)dst < (unsigned int)end);
    //     }
    //     a1[306] = mix1;
    //     a1[307] = counter;
    //     a1[304] = cursor;
    //     a1[305] = mix2;
    //     return mix2;
    //   }
    // UNRESOLVED: The exact byte-mixing arithmetic (8/24-bit rotates, complement and byte-indexed lookups) is reproduced from the decompiler but not further reduced to a named cipher.
    // UNRESOLVED: The object is accessed at dword indices 256..307, yet the only evidenced field is offset 0x0; the object layout beyond that offset is unknown.
    // UNRESOLVED: The cluster prelabel names a FloatClamp structural twin, but the raw source is clearly a PRNG-style keystream generator; the proposed name follows the raw source and the calling context rather than the prelabel.
}
