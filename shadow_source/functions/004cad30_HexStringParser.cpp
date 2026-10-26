// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CAD30
// Canonical corpus name: HexStringParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HexStringParser_004cad30.c

void UnknownObject::HexStringParser()
{
    // Parses a hexadecimal digit string into an int, reading characters from the end backwards. Each valid hex nibble (0-9, a-f, A-F) contributes v8 << (4 * nibble_index); any other character aborts with the partial result. Declared as __thiscall but does not reference the implicit this pointer, so it behaves as a free function.
    // ASSIGNMENT: v2 = 0: result accumulator initialized. [function:0x004CAD30, source:raw]
    // CALCULATION: v3 = strlen(this): length of the input string. [function:0x004CAD30, source:raw]
    // ASSIGNMENT: v4 = 0: nibble counter initialized. [function:0x004CAD30, source:raw]
    // GUARD: if (v3 > 0): proceed only for non-empty strings; otherwise return v2 (0). [function:0x004CAD30, source:raw]
    // CALCULATION: v6 = &this[v3 - 1]: walk pointer starting at the last character. [function:0x004CAD30, source:raw]
    // GUARD: Classify v7 = *v6: if not a-f (v7 < 97 or v7 > 102) and not A-F (v7 < 65 or v7 > 70) and not 0-9 (v7 < 48 or v7 > 57), return the partial v2 immediately. [function:0x004CAD30, source:raw]
    // ASSIGNMENT: Nibble value mapping: digit '0'-'9' -> v7 - 48; 'A'-'F' -> v7 - 55; 'a'-'f' -> v7 - 87. [function:0x004CAD30, source:raw]
    // CALCULATION: v9 = v8 << v5; v5 += 4 (shift nibble into its position); v2 += v9 (accumulate). [function:0x004CAD30, source:raw]
    // LOOP: do-while loop: ++v4 and --v6 after each nibble, continuing while v4 < v3; processes every character of the string. [function:0x004CAD30, source:raw]
    // RETURN: Return accumulated v2. [function:0x004CAD30, source:raw]

    // Conservative worker pseudocode:
    //   int parse_hex(const char *s) {
    //     int result = 0, len = strlen(s);
    //     int shift = 0, i = 0;
    //     if (len > 0) {
    //       const char *p = &s[len - 1];
    //       do {
    //         char c = *p;
    //         int nibble;
    //         if (c >= 'a' && c <= 'f') nibble = c - 87;
    //         else if (c >= 'A' && c <= 'F') nibble = c - 55;
    //         else if (c >= '0' && c <= '9') nibble = c - 48;
    //         else return result;
    //         result += nibble << shift;
    //         shift += 4;
    //         ++i; --p;
    //       } while (i < len);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Function is called by MaterialShaderReactionEffectParser (0x004CA480), but no class ownership evidence exists.
    // UNRESOLVED: Legacy ABI label 'Parses_a_hex_string' matches the observed behavior but carries no prototype.
}
