// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548E20
// Canonical corpus name: sub_548E20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_548E20_00548e20.c

void UnknownObject::Initialize()
{
    // Constructor/initializer for an object whose fields are reset to zero: runs the base-class zero-initializer over the whole object, clears a byte at this+0x8, zero-fills the 0x60-byte block starting at this+0x1C, then clears ten scalar fields (this+0x4, this+0x18, this+0x7C, this+0x80, this+0x84, this+0xE8..this+0xFC) to 0. Returns this.
    // CALL: Run the base-class zero-initializer over the whole object before the field resets. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Clear the dword field at this+0x4. [field:this:0x00000004]
    // ASSIGNMENT: Clear the byte field at this+0x8. [field:this:0x00000008]
    // ASSIGNMENT: Zero-fill the 0x60-byte block starting at this+0x1C via memset. [source:raw]
    // ASSIGNMENT: Clear the dword field at this+0x7C, immediately past the memset block. [field:this:0x0000007C]
    // ASSIGNMENT: Clear the dword field at this+0x80. [field:this:0x00000080]
    // ASSIGNMENT: Clear the dword field at this+0x84. [field:this:0x00000084]
    // ASSIGNMENT: Clear the dword field at this+0x18. [field:this:0x00000018]
    // ASSIGNMENT: Clear the dword field at this+0xE8. [field:this:0x000000E8]
    // ASSIGNMENT: Clear the dword field at this+0xEC. [field:this:0x000000EC]
    // ASSIGNMENT: Clear the dword field at this+0xF0. [field:this:0x000000F0]
    // ASSIGNMENT: Clear the dword field at this+0xF4. [field:this:0x000000F4]
    // ASSIGNMENT: Clear the dword field at this+0xF8. [field:this:0x000000F8]
    // ASSIGNMENT: Clear the dword field at this+0xFC. [field:this:0x000000FC]
    // RETURN: Return this, as is typical for a constructor-style initializer. [source:raw]
    // UNRESOLVED: Object identity and the semantic meaning of each cleared field are not recoverable from this packet.
    // UNRESOLVED: The base class zero-initialized by GlobalZeroInit_c2a0 is not identifiable here.
    // UNRESOLVED: The legacy ABI name (FAIL_548e20) carries no owner signal.
}
