// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DCC0
// Canonical corpus name: ArrayElementGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayElementGetter_0042dcc0.c

void UnknownObject::ArrayElementGetter()
{
    // Bounds-checked accessor over an 8-byte-strided array: struct at this holds an element count at +0x8 and an element-array base pointer at +0xC. Given index a2, returns the first dword (element offset +0) when a2 is within [0, count); otherwise returns 0. No reads beyond the two fields, no globals, no callees; sole caller is VehicleSetupValueFormatter (0x0042F470). Structural twin of ShortComputation_c910 per the cluster prelabel.
    // GUARD: Reject index a2 when negative or when it equals/exceeds the element count read from this[2] (+0x8); return 0 in that case. [source:raw, field:this:0x00000008]
    // CALCULATION: Compute the element address as the array base pointer this[3] (+0xC) advanced by 8*a2 bytes (8-byte element stride). [source:raw, field:this:0x0000000C]
    // RETURN: Return the dword at element offset +0 (first dword of the 8-byte element) when the index is in range; otherwise return 0 from the guard. [source:raw]

    // Conservative worker pseudocode:
    //   int ArrayElementGetter(_DWORD *this, int a2) {
    //     if (a2 < 0 || a2 >= this[2])
    //       return 0;
    //     return *(int *)(this[3] + 8 * a2);
    //   }
    // UNRESOLVED: Meaning of the two dwords per 8-byte element is unknown; this function reads the first dword while nearby accessors read the second, so element semantics are unproven.
    // UNRESOLVED: Owning class is UnknownObject; the count + base-pointer container layout is only evidenced by this and its cluster twin.
    // UNRESOLVED: Whether the base pointer this[3] refers to heap or embedded storage is unknown.
    // UNRESOLVED: Only caller VehicleSetupValueFormatter (0x0042F470) is known; the field's semantic role in setup formatting is unconfirmed.
}
