// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2C10
// Canonical corpus name: IncrementFieldAt0x34
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IncrementFieldAt0x34_004c2c10.c

void UnknownObject::IncrementFieldAt0x34()
{
    // Minimal __thiscall incrementer: bumps the 32-bit field at this+0x34 (this[13]) by one and returns void. No guards, calls or other side effects. Note: the packet's prelabel template labels this a no-side-effect getter, which contradicts the raw source; the raw source outranks that proposal.
    // ASSIGNMENT: Increment the 32-bit field at this+0x34 (this[13]) by one, in place (read-modify-write); the function returns void. [source:raw, field:this:0x00000034]
    // CALL: Invoked by sub_4A0760 (0x004A0760) to bump this counter field. [caller:0x004A0760, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C2C10(_DWORD *this) {
    //     ++this[13];  // field at +0x34
    //   }
    // UNRESOLVED: Packet classifies field 0x34 as read-only (rw=R) although the raw source performs an in-place increment (read-modify-write).
    // UNRESOLVED: Prelabel template ('Getter: returns field 0x34 of this. No side effects') contradicts the raw source, which increments and returns void; raw source takes precedence.
    // UNRESOLVED: Meaning of the counter at this+0x34 (uses, bounds, owner object type) requires caller context not present in the packet.
}
