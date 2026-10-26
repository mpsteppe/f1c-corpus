// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DCA0
// Canonical corpus name: BoundsCheckedArrayLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundsCheckedArrayLookup_0042dca0.c

void UnknownObject::BoundsCheckedArrayLookup()
{
    // Bounds-checked accessor over an 8-byte-strided array: struct at this holds an element count at +0x0 and an element-array base pointer at +0x4. Given index a2, returns the second dword (element offset +4) when a2 is within [0, count); otherwise returns 0. No reads beyond the two fields, no globals, no callees; sole caller is VehicleSetupValueFormatter (0x0042F470). Structural twin of BoundedArrayAccessor per the cluster prelabel.
    // GUARD: Reject index a2 when negative or when it equals/exceeds the element count read from this[0] (+0x0); return 0 in that case. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute the element address as the array base pointer this[1] (+0x4) advanced by 8*a2 bytes (8-byte element stride). [source:raw, field:this:0x00000004]
    // RETURN: Return the dword at element offset +4 (second dword of the 8-byte element) when the index is in range; otherwise return 0 from the guard. [source:raw]

    // Conservative worker pseudocode:
    //   int BoundsCheckedArrayLookup(int *this, int a2) {
    //     if (a2 < 0 || a2 >= this[0])
    //       return 0;
    //     return *(int *)(this[1] + 8 * a2 + 4);
    //   }
    // UNRESOLVED: Meaning of the two dwords per 8-byte element is unknown (count/value or id/pointer pairs are plausible but unproven).
    // UNRESOLVED: Owning class is UnknownObject; the count + base-pointer container layout is only evidenced by this and its cluster twin.
    // UNRESOLVED: Whether the base pointer this[1] refers to heap or embedded storage is unknown.
    // UNRESOLVED: Only caller VehicleSetupValueFormatter (0x0042F470) is known; the field's semantic role in setup formatting is unconfirmed.
}
