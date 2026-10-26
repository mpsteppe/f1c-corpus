// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543A30
// Canonical corpus name: GetOrientationAngleValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GetOrientationAngleValues_00543a30.c

void UnknownObject::GetOrientationAngleValues()
{
    // __thiscall getter that copies two orientation/angle values from the object into caller-provided output pointers: this+0x194 (this[101]) into *a2 and this+0x198 (this[102]) into *a3. Each output pointer is individually null-checked and skipped when null. Returns the a3 pointer (which may be null). Called by sub_4FCAA0.
    // GUARD: When a2 is non-null, write this+0x194 (this[101]) into *a2; a null a2 is skipped. [field:this:0x00000194, source:raw]
    // ASSIGNMENT: Copy the angle value at this+0x194 into the caller's a2 output pointer. [field:this:0x00000194, source:raw]
    // GUARD: When a3 is non-null, write this+0x198 (this[102]) into *a3; a null a3 is skipped. [field:this:0x00000198, source:raw]
    // ASSIGNMENT: Copy the angle value at this+0x198 into the caller's a3 output pointer. [field:this:0x00000198, source:raw]
    // RETURN: Returns the a3 pointer, which may be null. [function:0x00543A30, source:raw]
    // CALL: Called by sub_4FCAA0 to read the two orientation angle values from its owning object. [caller:0x004FCAA0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_543A30(_DWORD *this, _DWORD *a2, _DWORD *a3) {
    //     if (a2) *a2 = this[101];
    //     if (a3) *a3 = this[102];
    //     return a3;
    //   }
    // UNRESOLVED: Whether the two values represent left/right orientation angles or another pair of angles is not verifiable from this packet
    // UNRESOLVED: Object type is unknown; the fields are known only by offset and behavior
}
