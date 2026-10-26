// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499A30
// Canonical corpus name: StringFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFieldSetter_00499a30.c

void UnknownObject::StringFieldSetter()
{
    // String-and-id thiscall setter: copies the string at a2 via StringCopyWithBufferRealloc (0x00566650), assigns the copied result to the DWORD slot this[2] (this+0x8), then returns the copy result. Used by SpriteTextureEnumeration during string/resource field assignment.
    // CALL: Call StringCopyWithBufferRealloc(a2) and store the copied string as result. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Store a3 into the DWORD slot this[2], i.e. the field at this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return the copied string result; invoked by SpriteTextureEnumeration. [caller:0x00498950, function:0x00499A30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_499A30(int *this, int a2, int a3) {
    //     int copy = StringCopyWithBufferRealloc(a2);
    //     this[2] = a3;
    //     return copy;
    //   }
    // UNRESOLVED: The returned copy pointer is not written back to any field inside this function; its disposition is decided by the caller (SpriteTextureEnumeration).
    // UNRESOLVED: The field at this+0x8 stores a3 (not the copied string); whether the copied string is consumed by StringCopyWithBufferRealloc internally or returned for caller use is unresolved here.
}
