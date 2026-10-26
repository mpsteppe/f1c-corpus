// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005645A0
// Canonical corpus name: sub_5645A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5645A0_005645a0.c

void UnknownObject::StringHashModulo()
{
    // Computes a rolling 32-bit hash over a null-terminated string and returns the hash reduced modulo a caller-supplied divisor. Walks the string character by character, folding each character through helper sub_58B465 into an accumulator using the fixed multiplier 1664117991, and terminates at the null terminator.
    // ASSIGNMENT: Initialize the accumulator v3 to 0, load the string base pointer v2 from *a1 and read the first character v5 from **a1. [source:raw]
    // GUARD: When the first character v5 is non-zero, enter the character-walking hash loop. [source:raw]
    // LOOP: do { ++v2; ...; v5 = *v2; } while (*v2); — advance one character per iteration and stop at the null terminator. [source:raw]
    // CALL: Fold the current character through sub_58B465 into the rolling hash: v3 = sub_58B465(v5) - 1664117991 * v3, using the fixed multiplier 1664117991. [callee:0x0058B465, source:raw]
    // RETURN: Return v3 % a2, the final hash reduced modulo the caller-supplied divisor a2. [function:0x005645A0, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int StringHashModulo(char **a1, unsigned int a2) {
    //     char *v2 = *a1;
    //     unsigned int v3 = 0;
    //     char v5 = **a1;
    //     if (v5) {
    //       do {
    //         ++v2;
    //         v3 = sub_58B465(v5) - 1664117991 * v3;
    //         v5 = *v2;
    //       } while (*v2);
    //     }
    //     return v3 % a2;
    //   }
    // UNRESOLVED: Semantics of sub_58B465 (the per-character transform applied before the rolling multiply) are unknown; it may be a character class / case normalization helper.
    // UNRESOLVED: The role of the fixed multiplier 1664117991 (a hash constant) is not otherwise evidenced.
    // UNRESOLVED: The string is passed by pointer-to-pointer; the caller-supplied buffer indirection is not fully explained.
}
