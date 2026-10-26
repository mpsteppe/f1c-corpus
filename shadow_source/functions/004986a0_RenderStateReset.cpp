// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004986A0
// Canonical corpus name: RenderStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderStateReset_004986a0.c

void UnknownObject::RenderStateReset()
{
    // Resets render state on a __thiscall object: copies the default string into the global byte_5EA438 buffer via StringCopyWithBufferRealloc, clears three integer state fields at this+0x1560, this+0x1564 and this+0x1568 to 0, and returns 0. Called by UILargeRender (0x00496930).
    // CALL: Reset the global string buffer: StringCopyWithBufferRealloc(byte_5EA438), copying a default/empty value into it. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Clear the first render state integer field: this[1368] (offset 0x1560) = 0. [field:this:0x00001560, source:raw]
    // ASSIGNMENT: Clear the second render state integer field: this[1369] (offset 0x1564) = 0. [field:this:0x00001564, source:raw]
    // ASSIGNMENT: Clear the third render state integer field: this[1370] (offset 0x1568) = 0. [field:this:0x00001568, source:raw]
    // RETURN: Return literal 0 after clearing the state fields. [source:raw]
    // CALL: Invoked by UILargeRender (0x00496930) as part of large UI render preparation. [caller:0x00496930]

    // Conservative worker pseudocode:
    //   int __thiscall RenderStateReset(int *this) {
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     this[1368] = 0;
    //     this[1369] = 0;
    //     this[1370] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The default/empty value written into byte_5EA438 by StringCopyWithBufferRealloc is not evident from the raw source.
    // UNRESOLVED: The exact roles of the cleared fields at 0x1560, 0x1564 and 0x1568 in the render state object are DERIVED prose, not packet evidence.
    // UNRESOLVED: Owner object is unknown; the function is a __thiscall on an unidentified render state object.
}
