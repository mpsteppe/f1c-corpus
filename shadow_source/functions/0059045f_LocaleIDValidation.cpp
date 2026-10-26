// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059045F
// Canonical corpus name: sub_59045F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59045F_0059045f.c

void UnknownObject::LocaleIDValidation()
{
    // Locale identifier consistency check. Builds a masked locale id as (a1 & 0x3FF) with bit 4 set in the second byte, queries locale info through the function pointer dword_8D3FB8 into a 120-byte stack buffer, then passes when the buffer hex-parses back to a1, when the match flag a2 is zero, or when the locale language string (dword_8D3FA8) is not purely alphabetical (CountAlphabeticalChars differs from Strlen). Returns 0 on an empty guard or query failure.
    // CALCULATION: Masked locale id v2 computed as a1 & 0x3FF with 4 OR'd into the second byte [source:raw]
    // CALL: Locale info queried via function pointer dword_8D3FB8 with v2, 1, the 120-byte buffer v5 and length 120 [global:0x008D3FB8, source:raw]
    // GUARD: When the locale info query returns 0 the function falls through and returns 0 [global:0x008D3FB8, source:raw]
    // GUARD: Passes when a1 equals the hex-parsed buffer value from HexStringToIntParser(v5), i.e. self-consistent [callee:0x005905DD, source:raw]
    // GUARD: Passes immediately when the match flag a2 is zero [source:raw]
    // CALL: Alpha-character count of the locale language string via CountAlphabeticalChars(dword_8D3FA8) compared against Strlen(dword_8D3FA8) [callee:0x00590616, global:0x008D3FA8, callee:0x0058E1B0, source:raw]
    // GUARD: Passes when the alpha count differs from the string length (non-alphabetical characters present) [global:0x008D3FA8, source:raw]
    // RETURN: Returns 1 on any pass condition, otherwise 0 [function:0x0059045F, source:raw]
    // STATE_TRANSITION: Invoked as a validation helper by LocaleEnumProc and sub_590246 [caller:0x0058FFEC, caller:0x00590246, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a1 & 0x3FF;
    //   BYTE1(v2) |= 4;
    //   result = 0;
    //   if (dword_8D3FB8(v2, 1, v5, 120)) {
    //     if (a1 == HexStringToIntParser(v5)) return 1;
    //     if (!a2) return 1;
    //     v3 = (char*)CountAlphabeticalChars(dword_8D3FA8);
    //     if (v3 != Strlen((_DWORD*)dword_8D3FA8)) return 1;
    //   }
    //   return result;
    // UNRESOLVED: The meaning of the 0x3FF mask and the 4-bit flag in the second byte of the locale id is not established from this packet alone
    // UNRESOLVED: dword_8D3FB8 is a function-pointer global called as a function; its target contract is defined outside this packet
    // UNRESOLVED: Whether the pass on a2 == 0 or non-alphabetical string represents a true success or a skip is not resolvable from this packet
}
