// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553E10
// Canonical corpus name: sub_553E10
// Owner: DeviceStateObject [DERIVED]
// Raw source: functions/sub_553E10_00553e10.c

void DeviceStateObject::initializeState()
{
    // Initializes a device-state object: stores the object id from a2 at this+0x0, seeds channel fields with default values 1/2, zeroes the remaining state fields this+0x24 through this+0x40, and pushes each channel's value to the global device object at 0x008B89A0 through its virtual dispatch table so external consumers observe the new state.
    // ASSIGNMENT: Store the object id argument a2 at this+0x0. [field:this:0x00000000]
    // GUARD: Only write channel field this+0x4 when it is not already 1. [guard:0, field:this:0x00000004]
    // GUARD: Only write channel field this+0x8 when it is not already 2. [guard:1, field:this:0x00000008]
    // GUARD: Only write channel field this+0xC when it is not already 1. [guard:2, field:this:0x0000000C]
    // GUARD: Only write channel field this+0x18 when it is not already 1. [guard:3, field:this:0x00000018]
    // GUARD: Only write channel field this+0x1C when it is not already 2. [guard:4, field:this:0x0000001C]
    // GUARD: Only write channel field this+0x20 when it is not already 1. [guard:5, field:this:0x00000020]
    // ASSIGNMENT: Seed channel fields with defaults: this+0x4 to 1, this+0x8 to 2, this+0xC to 1, this+0x18 to 1, this+0x1C to 2, this+0x20 to 1. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]
    // ASSIGNMENT: Zero the remaining state fields this+0x24, this+0x28, this+0x2C, this+0x30, this+0x34, this+0x38, this+0x3C and this+0x40. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040]
    // CALL: Publish channels to the global device object at 0x008B89A0 via vtable slot +252 for channel ids 4,5,6 and 1,2,3 with values 1/2 matching the seeded defaults. [global:0x008B89A0]
    // CALL: Publish the remaining channels: vtable slot +252 for ids 11, 18, 13, 14 and 19, and vtable slot +244 for id 12. [global:0x008B89A0]
    // RETURN: Return the result of the last device vtable dispatch (id 19). [source:raw]

    // Conservative worker pseudocode:
    //   this->id = a2;
    //   setChannels(this, {1, 2, 1, 1, 2, 1});  // with != guard
    //   zero(this+0x24 .. this+0x40);
    //   device->vtable[252](device, this->id, channel, value);  // per channel
    //   return device->vtable[252](device, this->id, 19, 0);
    // UNRESOLVED: Decompiler null-sentinel guards comparing this against pointer constants (-24, -28, -32) indicate a possible re-entry guard based on whether this object is a sub-block of the device; exact intent unclear.
    // UNRESOLVED: Whether the channel fields this+0x4..0x20 are input state, output state, or capability bits is not determinable from this function alone.
}
