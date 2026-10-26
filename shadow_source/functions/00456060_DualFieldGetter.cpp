// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456060
// Canonical corpus name: DualFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldGetter_00456060.c

void UnknownObject::DualFieldGetter()
{
    // Getter that reads two consecutive DWORD fields (offset 0x38 and 0x3C) from the this struct and writes each to a caller-supplied output pointer when that pointer is non-null. Returns the second output pointer a3. Both struct reads are unconditional; only the stores are null-guarded. Called by eleven frame-path functions (camera, car-selection, steering/camera-follow, 2D transform copy and numeric helpers).
    // GUARD: Guard on output pointer a2: only write the first field value when a2 is non-null. [source:raw, abi:lead]
    // ASSIGNMENT: Write this[14] (DWORD at offset 0x38) into *a2. [source:raw, field:this:0x00000038]
    // ASSIGNMENT: Seed the return value with output pointer a3. [source:raw]
    // GUARD: Guard on output pointer a3: only write the second field value when a3 is non-null. [source:raw, abi:lead]
    // ASSIGNMENT: Write this[15] (DWORD at offset 0x3C) into *a3. [source:raw, field:this:0x0000003C]
    // RETURN: Return a3, the second caller-supplied output pointer. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   _DWORD *DualFieldGetter(_DWORD *this, _DWORD *outFirst, _DWORD *outSecond) {
    //     if (outFirst)  *outFirst  = this[14]; /* offset 0x38 * /
    //     if (outSecond) *outSecond = this[15]; /* offset 0x3C * /
    //     return outSecond;
    //   }
    // UNRESOLVED: Semantic meaning of the two DWORD fields (0x38, 0x3C) is unknown; the eleven frame-path callers suggest a per-frame camera/viewport or transform quantity, unproven here.
    // UNRESOLVED: Whether the caller may pass the same output pointer for both fields is not constrained by this function.
}
