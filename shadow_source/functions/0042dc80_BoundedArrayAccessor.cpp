// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DC80
// Canonical corpus name: BoundedArrayAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedArrayAccessor_0042dc80.c

void UnknownObject::BoundedArrayAccessor()
{
    // Bounds-checked lookup into an array owned by the object. If the requested index a2 is negative or at/above the element count stored at offset 0x0, returns 0. Otherwise reads the dword at data[this+0x4] + 8 * a2 (8-byte element stride) and returns it.
    // GUARD: Guard: if index a2 < 0 or a2 >= the element count at this+0x0, the lookup is blocked and 0 is returned. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute the element address: data pointer at this+0x4 plus 8 * a2, where 8 is the element stride. [source:raw, field:this:0x00000004]
    // RETURN: Return the dword stored at the computed element address (or 0 when the index is out of range). [source:raw]

    // Conservative worker pseudocode:
    //   int BoundedArrayAccessor(int* this, int index) {
    //     if (index < 0 || index >= this[0]) return 0;
    //     return *(int*)(this[1] + 8 * index);
    //   }
    // UNRESOLVED: Only the first dword of each 8-byte element is returned; the meaning of the remaining 4 bytes of each element is unknown.
    // UNRESOLVED: The object owner and the exact element type of the array are unknown; caller is VehicleSetupValueFormatter.
}
