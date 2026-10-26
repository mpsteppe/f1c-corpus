// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466A30
// Canonical corpus name: ConstructorWithVTableAndFloatInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndFloatInit_00466a30.c

void UnknownObject::ConstructorWithVTableAndFloatInit()
{
    // Object constructor: first delegates to InitVTableSet(this, a3, a4) for base/companion setup, then writes the vtable pointer off_59F380 to this+0x0, stores float 1056964608 (0.5f) at this+0x104, clears the byte at this+0x100 to 0, stores parameter a2 at this+0x108, and returns this.
    // CALL: Invoke InitVTableSet(this, a3, a4) to perform base initialization with the forwarded parameters. [callee:0x004668E0, source:raw]
    // ASSIGNMENT: Write the vtable pointer off_59F380 to this+0x0. [field:this:0x00000000, global:0x0059F380, source:raw]
    // ASSIGNMENT: Store float 1056964608 (0.5f) at this+0x104. [field:this:0x00000104, source:raw]
    // ASSIGNMENT: Clear the byte at this+0x100 to 0. [field:this:0x00000100, source:raw]
    // ASSIGNMENT: Store parameter a2 at this+0x108. [field:this:0x00000108, source:raw]
    // RETURN: Return this, the constructed object pointer. [function:0x00466A30, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall ConstructorWithVTableAndFloatInit(this, a2, a3, a4) {
    //     InitVTableSet(this, a3, a4);
    //     *(DWORD*)this = off_59F380;
    //     *(DWORD*)(this + 0x104) = 1056964608; // 0.5f
    //     *(BYTE*)(this + 0x100) = 0;
    //     *(DWORD*)(this + 0x108) = a2;
    //     return this;
    //   }
    // UNRESOLVED: Meaning of parameter a2 (index/ID per the DERIVED skeleton fill) is unverified.
    // UNRESOLVED: off_59F380 vtable and the constructed class identity are UNKNOWN from this packet.
    // UNRESOLVED: InitVTableSet (0x004668E0) performs base initialization but its full contract is outside this packet.
}
