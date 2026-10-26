// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497980
// Canonical corpus name: BitmapSpriteAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmapSpriteAccessor_00497980.c

void UnknownObject::GetSpriteBitmapName()
{
    // Guarded accessor that returns the name string of a bitmap/sprite descriptor. Reads the descriptor pointer from this+0x18 (v1 = this[6]); returns 0 when that pointer or the field at this+0x60 (v1+0x48) is null. Otherwise reads the sub-descriptor pointer at this+0x68 (v1+0x50) and returns the name pointer at its offset 0x34, falling back to the global byte_5EA438 when the name pointer is null.
    // GUARD: Reads the descriptor pointer from this+0x18 (v1 = this[6]); if it is null, returns 0 [field:this:0x00000018, source:raw]
    // GUARD: If the guard field at this+0x60 (v1+0x48) is null, returns 0 without reading the name [field:this:0x00000060, source:raw]
    // CALCULATION: Reads the sub-descriptor pointer at this+0x68 (v1+0x50) and then reads the name string pointer at offset 0x34 of that sub-descriptor [field:this:0x00000068, field:*(this+0x68):0x00000034, source:raw]
    // RETURN: Returns the name pointer, or the global byte_5EA438 default when the name pointer is null [global:0x005EA438, function:0x00497980, source:raw]
    // CALL: Invoked by sub_404B60 and KeyBindingUIPressKeyOrController to retrieve the sprite bitmap name string [caller:0x00404B60, caller:0x0046B0C0, source:raw]

    // Conservative worker pseudocode:
    //   v1 = *(this + 0x18);
    //   if (!v1 || !*(v1 + 0x48)) return 0;
    //   name = *( *(v1 + 0x50) + 0x34 );
    //   return name ? name : byte_5EA438;
    // UNRESOLVED: The bitmap/sprite descriptor layout is only partially observed; whether byte_5EA438 is an empty-string placeholder or a sentinel default is not verifiable from this packet
    // UNRESOLVED: The identity of the owning object and the meaning of the guard field at this+0x60 are not established from this packet
}
