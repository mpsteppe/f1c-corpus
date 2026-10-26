// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495890
// Canonical corpus name: HashTableIDResolution
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableIDResolution_00495890.c

void UnknownObject::StringHashIDResolve()
{
    // Asset/hash-table name resolution. Formats input string a1 into the global buffer unk_7CDE38 via StringFormatWithBufferOverflowCheck using the "%s" format literal at 0x005C2C18, then passes a1 and the buffer to ShortComputation_4fb0 (00494FB0) with a constant 1. Returns the original a1 when the lookup returns 0, otherwise returns NULL. Called by sub_497AD0 (00497AD0) and sub_497BA0 (00497BA0).
    // CALL: StringFormatWithBufferOverflowCheck(&unk_7CDE38, "%s", a1): safe-copy the input string into the global format buffer using the "%s" literal at 0x005C2C18 [callee:0x0058815F, global:0x005C2C18, global:0x007CDE38, source:raw]
    // CALL: ShortComputation_4fb0((int)&a1, (int)&unk_7CDE38, 1): hash/ID table lookup validating the formatted string, returning 0 on success [callee:0x00494FB0, global:0x007CDE38, source:raw]
    // GUARD: v1 == 0 decides the outcome: pass returns a1, any non-zero lookup result blocks and yields NULL [source:raw]
    // RETURN: Return a1 when the lookup succeeded (v1 == 0), otherwise return NULL [function:0x00495890, source:raw]
    // CALL: Consumed by sub_497AD0 (00497AD0) and sub_497BA0 (00497BA0) as the shared string-to-ID resolution step [caller:0x00497AD0, caller:0x00497BA0, source:raw]

    // Conservative worker pseudocode:
    //   StringFormatWithBufferOverflowCheck(&unk_7CDE38, "%s", a1);
    //   v1 = ShortComputation_4fb0((int)&a1, (int)&unk_7CDE38, 1);
    //   return v1 == 0 ? a1 : 0;
    // UNRESOLVED: Global 0x007CDE00 is listed in packet facts but does not appear in the raw decompiled body; its role in the hash/ID resolution is unverifiable here
    // UNRESOLVED: The constant 1 argument to ShortComputation_4fb0 is passed verbatim; its meaning (table index, mode, or size) is not documented in this function
}
