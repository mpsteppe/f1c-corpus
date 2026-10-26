// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495970
// Canonical corpus name: SimpleFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleFieldGetter_00495970.c

void UnknownObject::SimpleFieldGetter()
{
    // Field getter (__thiscall): returns the dword at this+0x18 (this[6]) unchanged. No writes, no callees, no guards. Its only known caller is ObjectSearchWithDoubleIteration (0x00495980).
    // RETURN: Read the dword at this+0x18 (this[6]) and return it unchanged; a pure read with no side effects [field:this:0x00000018, function:0x00495970, source:raw]

    // Conservative worker pseudocode:
    //   int SimpleFieldGetter(_DWORD *this)
    //   {
    //     return this[6];
    //   }
    // UNRESOLVED: Owning class of 'this' is unidentified; field +0x18 is read-only here and its semantic meaning is not evidenced
    // UNRESOLVED: How caller ObjectSearchWithDoubleIteration (0x00495980) interprets the returned dword is outside this packet
}
