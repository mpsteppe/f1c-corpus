// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559390
// Canonical corpus name: StructFieldInit_9390
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldInit_9390_00559390.c

void UnknownObject::StructFieldInit()
{
    // Trivial struct field initializer: writes argument a2 to this+0x14, argument a3 to this+0x18 and literal 0 to this+0x1C, then returns a2. No guards and no further computation. Called by LinkedListNodeSearchAllocation (00559630); its prelabel notes it as a structural twin of StringCopyFieldInit (00559350).
    // ASSIGNMENT: Writes a2 into this+0x14 (this[5] in dwords) [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Writes a3 into this+0x18 (this[6] in dwords) [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Writes literal 0 into this+0x1C (this[7] in dwords) [field:this:0x0000001C, source:raw]
    // RETURN: Returns a2 (the first stored value) as the function result [source:raw]
    // CALL: Invoked by LinkedListNodeSearchAllocation (00559630) as a per-node field initialization step [caller:0x00559630]

    // Conservative worker pseudocode:
    //   result = a2;
    //   this[0x14/4] = a2;
    //   this[0x18/4] = a3;
    //   this[0x1C/4] = 0;
    //   return result;
    // UNRESOLVED: The struct owning offsets 0x14/0x18/0x1C is unknown; the three fields are written but never read in this function
    // UNRESOLVED: The semantic role of a2 and a3 (e.g. array index, size or linkage pointers) is not determinable from this packet alone
}
