// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1D40
// Canonical corpus name: IndexedFloatArrayLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedFloatArrayLookup_004d1d40.c

void UnknownObject::ClampedScaledIndexLookup()
{
    // Indexed array lookup: converts an input scaled by a factor at this+0x108 to an integer index via CRTFtol, clamps that index to the valid range [0, count-1] where count is read from this+0x10C, and returns the DWORD stored at (array base at this+0x110) + 8*index. Out-of-range indices return the first or last element of the 8-byte-stride record array instead of faulting.
    // CALL: v3 := CRTFtol(a2 * *(float*)(this+0x108)) — convert the input scaled by the factor at this+0x108 to an integer index [callee:0x00587BDC, field:this:0x00000108, source:raw]
    // CALCULATION: v4 := (int)count at this+0x10C - 1 — last valid array index [field:this:0x0000010C, source:raw]
    // GUARD: if v3 < 0: v3 := 0 — clamp the index to the lower bound [source:raw]
    // RETURN: if v3 <= v4: return the DWORD at (array base at this+0x110) + 8*v3 — read the record selected by the in-range index (8-byte element stride) [field:this:0x00000110, source:raw]
    // RETURN: else: return the DWORD at (array base at this+0x110) + 8*v4 — clamp to the last element when the index exceeds count-1 [field:this:0x00000110, source:raw]

    // Conservative worker pseudocode:
    //   v3 = CRTFtol(a2 * *(float*)(this + 264));
    //   v4 = *(int*)(this + 268) - 1;
    //   if (v3 < 0) v3 = 0;
    //   if (v3 <= v4) return *(int*)(*(int*)(this + 272) + 8 * v3);
    //   return *(int*)(*(int*)(this + 272) + 8 * v4);
    // UNRESOLVED: The element type at this+0x110 is a single DWORD read per 8-byte record; whether the DWORD is a float bit pattern or a pointer is unestablished.
    // UNRESOLVED: this+0x110 is dereferenced as a pointer to an array of 8-byte records; the record layout beyond the returned DWORD is unknown.
    // UNRESOLVED: CRTFtol's exact rounding/truncation behavior is not analyzed in this packet.
    // UNRESOLVED: The owner (UnknownObject) is unknown; the structural-twin relationship to RingBufferAccessWithWrap (004d1cf0) is DERIVED from the cluster prelabel and not independently confirmed.
}
