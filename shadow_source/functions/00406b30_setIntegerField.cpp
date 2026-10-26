// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406B30
// Canonical corpus name: IntegerSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IntegerSetter_00406b30.c

void UnknownObject::setIntegerField()
{
    // Simple setter that writes the input integer parameter a2 to this+0x4 (this[1]) and returns a2.
    // ASSIGNMENT: Write input parameter a2 to this[1], i.e. the DWORD field at offset 0x4. [field:this:0x00000004]
    // RETURN: Return the input value a2. [function:0x00406B30, source:raw]

    // Conservative worker pseudocode:
    //   int setIntegerField(_DWORD *this, int a2) {
    //       this[1] = a2;
    //       return a2;
    //   }
    // UNRESOLVED: Owning class of the struct containing offset 0x4 is unknown.
}
