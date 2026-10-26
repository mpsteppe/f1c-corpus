// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1410
// Canonical corpus name: IndexedArrayAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedArrayAccessor_004d1410.c

void UnknownObject::PitStopOrderIndexedAccessor()
{
    // Lazy-initializing indexed accessor into a pit-stop-order array. If the array pointer at this[107] (this+0x1AC) is null, it loads the data via PitStopOrderLoader(this) (0x004D12C0). The index a2 is bounds-checked against the element count at this[106] (this+0x1A8); out-of-range indexes return a null pointer. Valid indexes fetch the entry pointer at an 8-byte stride from this[107]; a null entry falls back to the default string byte_5EA438 (0x005EA438).
    // GUARD: If the pit-stop-order array pointer at this[107] (this+0x1AC) is null, lazily trigger initialization of the array before accessing it. [field:this:0x000001AC, source:raw]
    // CALL: Call PitStopOrderLoader(this) (0x004D12C0) to load/initialize the pit-stop-order data array into this[107]. [callee:0x004D12C0, field:this:0x000001AC, source:raw]
    // GUARD: Bounds check: if a2 < 0 or a2 >= the element count at this[106] (this+0x1A8), return a null pointer. [field:this:0x000001A8, source:raw]
    // RETURN: Return the null pointer for an out-of-range index (no accessor value). [field:this:0x000001A8, source:raw]
    // CALCULATION: Fetch the entry pointer as *(char **)(this[107] + 8 * a2), indexing the array at an 8-byte stride. [field:this:0x000001AC, source:raw]
    // GUARD: If the fetched entry pointer is null, fall back to the default string byte_5EA438 (0x005EA438). [global:0x005EA438, source:raw]
    // RETURN: Return the resolved entry pointer, or the byte_5EA438 fallback when the entry is null. [function:0x004D1410, global:0x005EA438, source:raw]
    // UNKNOWN: Context: this indexed accessor is consumed by sub_4C6F10 (0x004C6F10) and sub_4D1450 (0x004D1450); the ABI lead names it Indexed_Array_Accessor. [abi:lead, caller:0x004C6F10, caller:0x004D1450]

    // Conservative worker pseudocode:
    //   char *PitStopOrderIndexedAccessor(int *this, int a2) {
    //     if (!this[107]) PitStopOrderLoader(this);
    //     if (a2 < 0 || a2 >= this[106]) return 0;
    //     result = *(char **)(this[107] + 8 * a2);
    //     if (!result) return byte_5EA438;
    //     return result;
    //   }
    // UNRESOLVED: The element type beyond an 8-byte-strided pointer array (the first dword of each entry is the returned string pointer) is not evidenced in this packet.
    // UNRESOLVED: byte_5EA438 is only evidenced as a read fallback here; its true role (directory/path string) is not established by this function alone.
    // UNRESOLVED: PitStopOrderLoader's population of this[107] and this[106] is not evidenced in this packet.
}
