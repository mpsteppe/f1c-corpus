// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004053E0
// Canonical corpus name: ShortComputation_53e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_53e0_004053e0.c

void UnknownObject::MultiStageStructInitializer()
{
    // Initializes a structure in stages: zeroes the dword at byte offset 0x4, sets the dword at byte offset 0x8 to -1, zero-initializes the integer range starting at byte offset 0x30 (this + 12), initializes the sub-object at byte offset 0x34 (this + 13) via ObjectInit_4840, then calls CameraViewStructInitializer on the base pointer; returns this.
    // ASSIGNMENT: Set dword at byte offset 0x4 (this[1]) to 0. [field:this:0x00000004]
    // ASSIGNMENT: Set dword at byte offset 0x8 (this[2]) to -1 (packet literal 18446744073709551615). [field:this:0x00000008]
    // CALL: ZeroInitInt(this + 12): zero-initialize integer field(s) starting at byte offset 0x30. [callee:0x0049A180]
    // CALL: ObjectInit_4840(this + 13): initialize the sub-object at byte offset 0x34. [callee:0x004D4840]
    // CALL: CameraViewStructInitializer(this): initialize camera-view-related fields on the struct. [callee:0x00405440]
    // RETURN: Return this pointer. [function:0x004053E0]

    // Conservative worker pseudocode:
    //   this->field_0x4 = 0;
    //   this->field_0x8 = -1;
    //   ZeroInitInt((int*)this + 12);  // byte offset 0x30
    //   ObjectInit_4840(this + 13);    // byte offset 0x34
    //   CameraViewStructInitializer(this);
    //   return this;
    // UNRESOLVED: Field names and the struct owning these offsets are not evidenced by the packet.
}
