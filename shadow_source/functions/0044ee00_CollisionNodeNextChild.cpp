// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EE00
// Canonical corpus name: CollisionNodeNextChildAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNodeNextChildAccessor_0044ee00.c

void UnknownObject::CollisionNodeNextChild()
{
    // Getter with no side effects: reads field 0x0 of this; when nonzero returns pointer this + 76 (decimal), otherwise returns null.
    // GUARD: Read field 0x0 of this; the return path branches on whether it is nonzero. [field:this:0x00000000, source:raw]
    // RETURN: When field 0x0 is nonzero, return this + 76 (pointer arithmetic, byte offset 76). [source:raw]
    // RETURN: When field 0x0 is zero, return null. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* CollisionNodeNextChild(DWORD* this) {
    //       if (*this)
    //           return this + 76;
    //       else
    //           return 0;
    //   }
    // UNRESOLVED: The object type behind this is unknown (owner UnknownObject).
    // UNRESOLVED: The meaning of field 0x0 (a presence/link flag) and the layout at byte offset 76 are unproven.
}
