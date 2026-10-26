// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565080
// Canonical corpus name: RC4KeyScheduleInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RC4KeyScheduleInitialization_00565080.c

void UnknownObject::RC4KeyScheduleInitialization()
{
    // Initializes a 1024-byte (256-dword) permutation/state array from caller-supplied key material a1 of length a2, using an RC4-style key-schedule algorithm. Clears the state with memset, runs four outer passes, each doing two 256-step keyed permutation swaps over the key bytes, XORs each state dword with its index, then forwards the finished state to sub_564DD0(a3, 0, 0) whose result is returned.
    // ASSIGNMENT: Initialize the state: a3[325] is set to 0, then memset zeroes the first 0x400 bytes of a3 (dword indices 0..255). [source:raw]
    // LOOP: Outer loop i in 0..3: before each permutation pass every dword is expanded with a3[j] = j + (a3[j] << 8), seeding the state from the loop index. [source:raw]
    // LOOP: Keyed permutation pass: two passes per outer iteration, each a 256-step do/while loop over v7; v8 = a3[v7], v9 = (v6 + v8 + key byte a1[(v7++ % a2)]) masked to 8 bits, v6 = v9, then a3[v7-1] = a3[v9] and a3[v9] = v8 (swap). [source:raw]
    // CALCULATION: The key-byte index wraps at the key length a2 (v7 % a2); the permutation state and key bytes are combined through the running byte accumulator v6. [source:raw]
    // LOOP: Final scrambling loop k in 0..255: each state dword is XORed with its own index (a3[k] ^= k). [source:raw]
    // CALL: Post-process the completed state: return sub_564DD0(a3, 0, 0), passing the 256-dword state and two zero arguments; the callee's result becomes this function's return value. [callee:0x00564DD0, source:raw]

    // Conservative worker pseudocode:
    //   a3[325] = 0;
    //   memset(a3, 0, 0x400);
    //   for (i = 0; i < 4; ++i) {
    //     for (j = 0; j < 256; ++j) a3[j] = j + (a3[j] << 8);
    //     v6 = i;
    //     for (pass = 0; pass < 2; ++pass) {
    //       v7 = 0;
    //       do {
    //         v8 = a3[v7];
    //         v9 = (byte)(v6 + v8 + key[(v7++ % a2)]);
    //         v6 = v9;
    //         a3[v7-1] = a3[v9];
    //         a3[v9] = v8;
    //       } while (v7 < 256);
    //     }
    //   }
    //   for (k = 0; k < 256; ++k) a3[k] ^= k;
    //   return sub_564DD0(a3, 0, 0);
    // UNRESOLVED: The identity and purpose of sub_564DD0 (called with the state array and two zero arguments) are not evidenced by this packet.
    // UNRESOLVED: a3[325] lies outside the 256-dword region rebuilt by the permutation passes (memset covers only indices 0..255); the role of that write is not established.
    // UNRESOLVED: a1/a2 are caller-supplied key material; no packet evidence identifies the calling subsystem or key source.
}
