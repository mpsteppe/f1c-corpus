// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C674
// Canonical corpus name: CharacterEncodingConvertViaLookupTableFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharacterEncodingConvertViaLookupTableFallback_0058c674.c

void UnknownObject::CharacterEncodingConvertViaLookupTableFallback()
{
    // Character-code conversion helper with a direct lookup-table fast path and a multi-byte conversion fallback. For CharType values whose packed code fits the low-byte range, the 16-bit lookup entry off_5E69C8[0][CharType] is combined with a2 and returned. Otherwise the function builds a one- or two-byte source buffer from the bytes of CharType and calls sub_595DC8 to convert it; on success it returns a2 combined with the high word of CharType, and on failure it returns the conversion call's result.
    // GUARD: Dispatch on CharType: when (unsigned)(CharType + 1) <= 0x100 take the direct table path, otherwise fall through to the conversion path. [source:raw]
    // CALCULATION: Load a 16-bit table entry: v3 = (unsigned __int16)off_5E69C8[0][CharType]. [source:raw, global:0x005E69C8]
    // RETURN: Return a2 & v3 for the direct lookup path. [source:raw]
    // GUARD: Branch on the sign of the table entry off_5E69C8[0][BYTE1(CharType)] to choose a one-byte or two-byte conversion buffer. [source:raw, global:0x005E69C8]
    // ASSIGNMENT: One-byte branch: build SrcStr as LOWORD(SrcStr) = (unsigned __int8)CharType. [source:raw]
    // CALL: Call sub_595DC8 with the 1-byte source buffer SrcStr and destination pointer (&CharType + 1) as a 16-bit target. [source:raw, callee:0x00595DC8]
    // ASSIGNMENT: Two-byte branch: compose SrcStr from BYTE1(CharType) in the first byte and the low byte of CharType in the following word. [source:raw]
    // CALL: Call sub_595DC8 with the 2-byte source buffer SrcStr and the same destination pointer. [source:raw, callee:0x00595DC8]
    // GUARD: Test the result of the conversion call; a nonzero result selects the high-word return path. [source:raw]
    // RETURN: Return a2 & HIWORD(CharType) when conversion succeeded, otherwise return the conversion call's result (zero). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_58C674(int CharType, int a2) {
    //     int SrcStr;
    //     if ((unsigned int)(CharType + 1) <= 0x100)
    //       return a2 & (unsigned __int16)off_5E69C8[0][CharType];
    //     if (off_5E69C8[0][BYTE1(CharType)] >= 0) {
    //       LOWORD(SrcStr) = (unsigned __int8)CharType;
    //       if (sub_595DC8(1, &SrcStr, 1, (LPWORD)&CharType + 1, 0, 0, 1))
    //         return a2 & HIWORD(CharType);
    //     } else {
    //       LOBYTE(SrcStr) = BYTE1(CharType);
    //       *(_WORD *)((char *)&SrcStr + 1) = (unsigned __int8)CharType;
    //       if (sub_595DC8(1, &SrcStr, 2, (LPWORD)&CharType + 1, 0, 0, 1))
    //         return a2 & HIWORD(CharType);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact operation of the 7-argument callee sub_595DC8 (apparently a character or string conversion helper) is unproven.
    // UNRESOLVED: The initial store SrcStr = v2 uses uninitialized v2 and is a decompiler artifact; it is overwritten before any use.
    // UNRESOLVED: The semantics of the bitwise combines a2 & v3 and a2 & HIWORD(CharType) depend on the caller-supplied contract for a2.
    // UNRESOLVED: The >= 0 sign test on off_5E69C8[0][BYTE1(CharType)] and the meaning of the high byte of CharType as a table index are not fully resolved.
    // UNRESOLVED: A single source:raw and function:0x0058C674 grounding supports the control flow; caller relationships are listed in the packet but not otherwise probed.
}
