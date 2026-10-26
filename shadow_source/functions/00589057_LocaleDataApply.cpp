// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589057
// Canonical corpus name: sub_589057
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589057_00589057.c

void UnknownObject::LocaleDataApply()
{
    // Applies parsed locale data. Normalizes the compare-string buffer for a1, then, if the byte at a2+64 is non-zero, calls BatchFunctionCallOverVarargs(a1, 2); if the byte at a2+128 is also non-zero, calls it again and returns that result, otherwise returns a2+128.
    // CALL: sub_58FCA0(a1) normalizes the compare-string buffer identified by a1 before applying locale subtokens. [callee:0x0058FCA0, source:raw]
    // GUARD: If the byte at a2+64 is non-zero, the secondary locale subtoken is present. [source:raw]
    // CALL: BatchFunctionCallOverVarargs(a1, 2) invokes the setup function with varargs for the secondary locale subtoken. [callee:0x00588F66, source:raw]
    // GUARD: If the byte at a2+128 is non-zero, the tertiary locale subtoken is present. [source:raw]
    // CALL: BatchFunctionCallOverVarargs(a1, 2) is invoked again for the tertiary locale subtoken; its result is returned. [callee:0x00588F66, source:raw]
    // RETURN: Otherwise returns a2+128 (pointer to the tertiary subtoken byte). [source:raw]
    // CALL: Invoked by sub_588E4E as part of the locale configuration pipeline. [caller:0x00588E4E, source:raw]

    // Conservative worker pseudocode:
    //   int LocaleDataApply(int a1, int a2) {
    //     sub_58FCA0(a1);
    //     if (*(BYTE*)(a2 + 64))
    //       BatchFunctionCallOverVarargs(a1, 2);
    //     if (*(BYTE*)(a2 + 128))
    //       return BatchFunctionCallOverVarargs(a1, 2);
    //     return a2 + 128;
    //   }
    // UNRESOLVED: word_5BEB48 and word_5CC214 appear in the packet globals but are absent from the raw decompiled text; their role is unresolved.
    // UNRESOLVED: The layout of the a2 structure (bytes at +64 and +128) is unknown; the secondary/tertiary interpretation is DERIVED from the existing analysis.
    // UNRESOLVED: The meaning of the varargs count 2 passed to BatchFunctionCallOverVarargs is not established.
    // UNRESOLVED: The owning class behind a1/a2 is unknown.
}
