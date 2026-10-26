// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B450
// Canonical corpus name: sub_54B450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54B450_0054b450.c

void UnknownObject::SetThreeFloatsAndClearBitmask()
{
    // Stores three float parameters a2, a3, a4 into the object at offsets 44 (0x2C), 48 (0x30) and 52 (0x34), calling InterruptDispatch on each value before storing it, then clears a bitmask at offset 64 on the same object via BitmaskClear.
    // CALL: Process the first float a2 through InterruptDispatch before storing it. [callee:0x0058957A]
    // ASSIGNMENT: Store a2 into the float field at this+44 (0x2C). [field:this:0x0000002C]
    // CALL: Process the second float a3 through InterruptDispatch before storing it. [callee:0x0058957A]
    // ASSIGNMENT: Store a3 into the float field at this+48 (0x30). [field:this:0x00000030]
    // CALL: Process the third float a4 through InterruptDispatch before storing it. [callee:0x0058957A]
    // ASSIGNMENT: Store a4 into the float field at this+52 (0x34). [field:this:0x00000034]
    // CALL: Clear the bitmask at offset 64 of the object with BitmaskClear(this, 64, 0, 0). [callee:0x0054B330]

    // Conservative worker pseudocode:
    //   void SetThreeFloatsAndClearBitmask(int this, float a2, float a3, float a4) {
    //     InterruptDispatch(a2); *(float*)(this + 44) = a2;
    //     InterruptDispatch(a3); *(float*)(this + 48) = a3;
    //     InterruptDispatch(a4); *(float*)(this + 52) = a4;
    //     BitmaskClear((DWORD*)this, 64, 0, 0);
    //   }
    // UNRESOLVED: Global dbl_5B8960 appears in the packet global list but is absent from the raw function body; its role here is unknown (possibly an inlined or neighboring expression).
    // UNRESOLVED: Meaning of the three stored floats and of the cleared bitmask depends on the owning vehicle/state object, which is not identified by this packet.
}
