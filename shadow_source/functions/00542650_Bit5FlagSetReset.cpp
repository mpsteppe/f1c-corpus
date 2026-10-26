// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542650
// Canonical corpus name: Bit5FlagSetReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Bit5FlagSetReset_00542650.c

void UnknownObject::Bit5FlagSetReset()
{
    // Sets or clears bit 5 (value 0x20) of the dword at this + 0x80 depending on the boolean parameter a2, stores the updated dword back, and returns it. Called from ConditionalRenderPipelineDispatch to toggle a state flag on a render-related object.
    // ASSIGNMENT: Read the current dword value v2 from this + 0x80. [source:raw, field:this:0x00000080]
    // GUARD: Branch on parameter a2: non-zero sets the flag, zero clears it. [source:raw]
    // CALCULATION: When a2 is non-zero, set bit 5 by OR-ing the value with 0x20. [source:raw]
    // CALCULATION: When a2 is zero, clear bit 5 by AND-ing the value with 0xFFFFFFDF. [source:raw]
    // ASSIGNMENT: Write the updated dword back to this + 0x80. [source:raw, field:this:0x00000080]
    // RETURN: Return the updated dword value as the unsigned result. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_542650(int* this, int a2) {
    //     int v2 = this[32];
    //     this[32] = a2 ? (v2 | 0x20) : (v2 & 0xFFFFFFDF);
    //     return this[32];
    //   }
    // UNRESOLVED: The meaning of the bit-5 flag at this + 0x80 (e.g. enabled, dirty, visible) is not evidenced by the packet.
    // UNRESOLVED: The object type and why ConditionalRenderPipelineDispatch (0x00409970) toggles this flag are unevidenced here.
}
