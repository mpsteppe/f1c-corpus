// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004893C0
// Canonical corpus name: sub_4893C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4893C0_004893c0.c

void UnknownObject::NetCommObjectInit()
{
    // Object constructor/initializer for a network-communication object. Runs the base initialization ShortComputation_5e30, zeroes a block of state fields (bytes +0x144..0x146, dwords +0x134..0x13C, +0x148, +0x158, +0x160..0x16C), installs the vtable off_5ABD78 at +0, then sets configuration fields: +0x131=1 and +0xE0=1 (enabled flags), +0x140=5 (config value), +0x168=-1 and +0x170=-1 (unused/invalid sentinels). Returns this.
    // CALL: Call ShortComputation_5e30(this) as the base/prior initialization step before field setup. [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Zero the byte fields at +324 (+0x144), +325 (+0x145) and +326 (+0x146). [field:this:0x00000144, field:this:0x00000145, field:this:0x00000146, source:raw]
    // ASSIGNMENT: Zero the dword fields at +328 (+0x148), +308 (+0x134), +312 (+0x138) and +316 (+0x13C). [field:this:0x00000148, field:this:0x00000134, field:this:0x00000138, field:this:0x0000013C, source:raw]
    // ASSIGNMENT: Zero the dword fields at +352 (+0x160), +356 (+0x164), +344 (+0x158) and +364 (+0x16C). [field:this:0x00000160, field:this:0x00000164, field:this:0x00000158, field:this:0x0000016C, source:raw]
    // ASSIGNMENT: Install the vtable: write the address of global off_5ABD78 into the object header at +0. [field:this:0x00000000, global:0x005ABD78, source:raw]
    // ASSIGNMENT: Set the byte flags +305 (+0x131) and +224 (+0xE0) to 1. [field:this:0x00000131, field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Set the dword field +320 (+0x140) to 5. [field:this:0x00000140, source:raw]
    // ASSIGNMENT: Set the dword fields +360 (+0x168) and +368 (+0x170) to -1 (invalid/unused sentinel). [field:this:0x00000168, field:this:0x00000170, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_5e30(this);
    //   byte[this+0x144]=0; byte[this+0x145]=0; byte[this+0x146]=0;
    //   dword[this+0x148]=0; dword[this+0x134]=0; dword[this+0x138]=0; dword[this+0x13C]=0;
    //   dword[this+0x160]=0; dword[this+0x164]=0; dword[this+0x158]=0; dword[this+0x16C]=0;
    //   *(this) = &off_5ABD78;
    //   byte[this+0x131]=1; dword[this+0x140]=5; dword[this+0x168]=-1; dword[this+0x170]=-1; byte[this+0xE0]=1;
    //   return this;
    // UNRESOLVED: Semantic roles of the zeroed fields (+0x134..0x16C) are DERIVED; they are likely counters/state but their purpose is not proven.
    // UNRESOLVED: The identity of vtable off_5ABD78 as a network-communication vtable comes from the skeleton analysis and is DERIVED.
}
