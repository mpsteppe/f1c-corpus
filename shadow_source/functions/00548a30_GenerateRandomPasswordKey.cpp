// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548A30
// Canonical corpus name: RandomPasswordKeyGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomPasswordKeyGenerator_00548a30.c

void UnknownObject::GenerateRandomPasswordKey()
{
    // Generates a 4-character null-terminated key string into the a2 buffer. Seeds the TLS random generator with a1 modulo 42330, folds a pseudo-random value with (value << 17) | value, then maps four successive low bytes into a 78-character printable range (48..126) and writes the four bytes followed by a terminating NUL. Returns the last computed quotient.
    // CALL: Call TLSFieldSetter(a1 % 42330) to seed the TLS random context from a1 modulo 42330. [callee:0x005884E0, source:raw]
    // CALL: Call RandLCGRandomNumberGenerator(v2) to obtain a pseudo-random value into v3. [callee:0x005884ED, source:raw]
    // CALCULATION: Fold the random value: v4 = (v3 << 17) | v3, mixing the high bits into the low bits. [source:raw]
    // LOOP: Loop over i = 0..3, generating one output character per iteration. [source:raw]
    // CALCULATION: Take the low byte of v4; result = (unsigned __int8)v4 / 78 and v7 = (unsigned __int8)v4 % 78 + 48, mapping the byte into a 78-character printable range starting at 48. [source:raw]
    // GUARD: Clamp v7 to the printable range: on overflow set v7 to 48, otherwise if v7 >= 126 set v7 to 126. [source:raw]
    // CALCULATION: Shift the working value right by 8 (v4 >>= 8) so the next iteration consumes the next byte. [source:raw]
    // ASSIGNMENT: Write the generated character byte v7 to the output buffer at a2 + i. [source:raw]
    // ASSIGNMENT: Write a terminating NUL at a2 + 4 so the four generated characters form a string. [source:raw]
    // RETURN: Return result, the quotient computed in the final loop iteration. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_548A30(int a1, char *out) {
    //     TLSFieldSetter(a1 % 42330);
    //     unsigned v4 = (RandLCGRandomNumberGenerator() << 17) | RandLCGRandomNumberGenerator();
    //     int result;
    //     for (int i = 0; i < 4; ++i) {
    //       result = (unsigned char)v4 / 78;
    //       int c = (unsigned char)v4 % 78 + 48;
    //       if (OF) c = 48; else if (c >= 126) c = 126;
    //       v4 >>= 8;
    //       out[i] = (char)c;
    //     }
    //     out[4] = '\0';
    //     return out;
    //   }
    // UNRESOLVED: Semantic role of a1 (seed or key index) and the meaning of the 42330 modulus.
    // UNRESOLVED: RandLCGRandomNumberGenerator is invoked with the raw register v2 (ecx); its prototype and whether that argument is meaningful is unknown.
    // UNRESOLVED: The exact alphabet semantics (modulo 78 plus offset 48 with clamps at 48 and 126) are observed from raw source only.
}
