// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406B60
// Canonical corpus name: MenuSelectSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuSelectSetter_00406b60.c

void UnknownObject::setSelectionField()
{
    // Simple setter that writes the input integer parameter a2 to this+0x54 (this[21]) and returns a2.
    // ASSIGNMENT: Write input parameter a2 to this[21], i.e. the DWORD field at offset 0x54. [field:this:0x00000054]
    // RETURN: Return the input value a2. [function:0x00406B60, source:raw]

    // Conservative worker pseudocode:
    //   int setSelectionField(_DWORD *this, int a2) {
    //       this[21] = a2;
    //       return a2;
    //   }
    // UNRESOLVED: Owning class of the struct containing offset 0x54 is unknown; selection semantics (menu/track index) are not established by this setter alone.
}
