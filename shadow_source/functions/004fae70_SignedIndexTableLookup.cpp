// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAE70
// Canonical corpus name: SignedIndexTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SignedIndexTableLookup_004fae70.c

void UnknownObject::SignedIndexTableLookup()
{
    // Converts a float argument to an integer via CRTFtol, then selects a double from one of two clamped 8-entry regions of a caller-provided float table: indices 59..66 for non-negative input, indices 51..58 (magnitude) for negative input.
    // CALL: Convert float a2 to integer v3 via CRTFtol. [callee:0x00587BDC, source:raw]
    // GUARD: Branch on sign of v3: if v3 >= 0 use the positive table side, otherwise negate to v4 and use the negative side. [source:raw]
    // CALCULATION: Clamp positive-side index: if v3 >= 8, force v3 = 7. [source:raw]
    // RETURN: Return double this[v3 + 59] from the positive-side table region. [source:raw]
    // CALCULATION: Compute v4 = -v3 as the magnitude for the negative branch. [source:raw]
    // CALCULATION: Clamp negative-side index: if v4 >= 8, force v4 = 7. [source:raw]
    // RETURN: Return double this[v4 + 51] from the negative-side table region. [source:raw]

    // Conservative worker pseudocode:
    //   int idx = CRTFtol(a2);
    //   if (idx >= 0) { if (idx >= 8) idx = 7; return this[idx + 59]; }
    //   idx = -idx; if (idx >= 8) idx = 7; return this[idx + 51];
    // UNRESOLVED: Global double dbl_59E430 (0x0059E430) is read per packet facts but does not appear in the decompiled body; likely a constant consumed by CRTFtol or adjacent compiler-emitted code, not this table lookup itself.
}
