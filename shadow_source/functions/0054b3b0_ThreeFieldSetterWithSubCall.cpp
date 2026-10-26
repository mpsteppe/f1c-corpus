// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B3B0
// Canonical corpus name: ThreeFieldSetterWithSubCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeFieldSetterWithSubCall_0054b3b0.c

void UnknownObject::ThreeFieldSetterWithSubCall()
{
    // Writes parameters a2, a3, a4 into fields at this+0x20, this+0x24, this+0x28, then calls BitmaskClear(this, 64, 0, 0).
    // ASSIGNMENT: Write a2 into field at this+0x20. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write a3 into field at this+0x24. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Write a4 into field at this+0x28. [field:this:0x00000028, source:raw]
    // CALL: Call BitmaskClear(this, 64, 0, 0) after the three field writes. [source:raw]

    // Conservative worker pseudocode:
    //   this[8] = a2;
    //   this[9] = a3;
    //   this[10] = a4;
    //   BitmaskClear(this, 64, 0, 0);
    // UNRESOLVED: Semantics of the BitmaskClear arguments (64, 0, 0) and the location of the bitmask it clears are unknown; BitmaskClear is not listed among the packet's callees.
    // UNRESOLVED: Meaning of the three written fields (0x20, 0x24, 0x28) and the owning object type are unknown.
}
