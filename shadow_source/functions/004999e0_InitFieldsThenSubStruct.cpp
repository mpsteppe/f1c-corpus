// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004999E0
// Canonical corpus name: sub_4999E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4999E0_004999e0.c

void UnknownObject::InitFieldsThenSubStruct()
{
    // Object/sub-struct initializer. Zeroes the first field at this+0x0, sets the second field at this+0x4 to the -1 sentinel, then delegates further initialization to SmallStructInit_9a00 on the same object. Returns the this pointer, consistent with a chained constructor convention.
    // ASSIGNMENT: *this = 0; zero the first field at this+0x0. [field:this:0x00000000, function:0x004999E0, source:raw]
    // ASSIGNMENT: this[1] = -1; initialize the second field at this+0x4 to the -1 sentinel value. [field:this:0x00000004, function:0x004999E0, source:raw]
    // CALL: SmallStructInit_9a00(this); run the sub-initializer over the same object after the two leading fields are set. [callee:0x00499A00, function:0x004999E0, source:raw]
    // RETURN: Return the this pointer, matching a constructor-style return convention. [function:0x004999E0, source:raw]

    // Conservative worker pseudocode:
    //   void* InitFieldsThenSubStruct(void* this) {
    //     this[0] = 0;
    //     this[1] = -1;
    //     SmallStructInit_9a00(this);
    //     return this;
    //   }
    // UNRESOLVED: The role of the -1 sentinel at this+0x4 is unknown; it may mark an empty/unset slot.
    // UNRESOLVED: What SmallStructInit_9a00 initializes beyond this+0x4 is not visible in this packet.
    // UNRESOLVED: Called from LargeStructZeroInit (00495190) as part of a larger construction sequence; the owning type is unknown.
}
