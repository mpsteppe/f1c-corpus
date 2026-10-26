// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E09E0
// Canonical corpus name: VehicleResetClear
// Owner: VehicleObject [DERIVED]
// Raw source: functions/VehicleResetClear_004e09e0.c

void VehicleObject::ResetVehicleState()
{
    // Resets a vehicle state object: when a global collision-system flag is set and the secondary object pointer (this+0x4) is non-null, it re-initializes the multi-system state, destroys the 3D sound source and copies collision status from the geometry object. It then zeroes large runs of dword fields (timers/counters/flags from this+0x48 through this+0x8C, the wheel/sensor blocks this+0x88C..0x914 and this+0x934..0x98C), runs destructor/init loops over embedded arrays (4 x InitWithDualCall at this+212 step 296, 3 x F_17ElementZeroInitLoop, 8 x F_17ElementZeroInitLoop at this+1644 step 68, 11 x DualArrayDestructor at this+2988 step 748), and finally frees the object pointer at this+2805 and nulls both this+2804 and this+2805. Returns the (nulled) freed pointer.
    // GUARD: Guard: if global collision flag dword_8AFE88 is non-zero AND secondary object pointer this+0x4 is non-null, run the conditional init/sound/collision-status block. [global:0x008AFE88, field:this:0x00000004, function:0x004E09E0, source:raw]
    // CALL: Conditional: MultiSystemStructInitializer(this) re-initializes the multi-system object state. [callee:0x004E0DB0, source:raw]
    // CALL: Conditional: F_3DSoundSourceDestructor(this+0x4) destroys the 3D sound source object held at the secondary pointer. [callee:0x00545150, field:this:0x00000004, source:raw]
    // CALL: Conditional: StatusFieldCopy(dword_5EA560, geometryObj->field+0x4894, 0) copies collision status from the object pointed to by this+0x0 into the global dword_5EA560. [callee:0x00411570, global:0x005EA560, field:this:0x00000000, field:obj:0x00004894, source:raw]
    // CALL: TimerClampAndProcess(this) clamps and processes the timer state on the object. [callee:0x004E38D0, source:raw]
    // CALL: ArrayCleanup(this) releases the embedded array resources. [callee:0x004E3050, source:raw]
    // CALL: F_17ElementZeroInitLoop(this+0x4) zeroes a 17-element block beginning at this+0x4. [callee:0x004DFA50, source:raw]
    // ASSIGNMENT: Zero 18 consecutive dwords this[18..35] = offsets this+0x48 through this+0x8C. [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, field:this:0x0000008C, source:raw]
    // CALL: StringCopyWithBufferRealloc(byte_5EA438) reinitializes the string buffer at global byte_5EA438. [callee:0x00566650, global:0x005EA438, source:raw]
    // LOOP: Loop 4 times calling InitWithDualCall(v2) with v2 starting at this+212 (0xD4) and advancing 74 dwords (296 bytes) per iteration. [callee:0x004DFB60, source:raw]
    // CALL: F_17ElementZeroInitLoop(this+0x5E4) zeroes a 17-element block beginning at this+1508. [callee:0x004DFA50, source:raw]
    // CALL: F_17ElementZeroInitLoop(this+0x628) zeroes a 17-element block beginning at this+1576. [callee:0x004DFA50, source:raw]
    // LOOP: Loop 8 times calling F_17ElementZeroInitLoop(v4) with v4 starting at this+1644 (0x66C) and advancing 68 bytes per iteration. [callee:0x004DFA50, source:raw]
    // ASSIGNMENT: Zero dwords this[547..557] = offsets this+0x88C through this+0x8B4 and this[560] = this+0x8C0. [field:this:0x0000088C, field:this:0x00000890, field:this:0x00000894, field:this:0x00000898, field:this:0x0000089C, field:this:0x000008A0, field:this:0x000008A4, field:this:0x000008A8, field:this:0x000008AC, field:this:0x000008B0, field:this:0x000008B4, field:this:0x000008C0, source:raw]
    // LOOP: Loop 2 times over v8 = this+0x8B8 (dword written to 0) and v7 = this+0x8C4 (4 consecutive dwords 0x8C4..0x8D0 written to 0), advancing one dword and four dwords respectively. [field:this:0x000008B8, field:this:0x000008C4, field:this:0x000008C8, field:this:0x000008CC, field:this:0x000008D0, source:raw]
    // ASSIGNMENT: Zero dwords this[569] = this+0x8E4 and this[573..581] = this+0x8F4..0x914. [field:this:0x000008E4, field:this:0x000008F4, field:this:0x000008F8, field:this:0x000008FC, field:this:0x00000900, field:this:0x00000904, field:this:0x00000908, field:this:0x0000090C, field:this:0x00000910, field:this:0x00000914, source:raw]
    // ASSIGNMENT: Zero dwords this[589..597] = offsets this+0x934..0x954 (0x948 written as a word at this+0x948). [field:this:0x00000934, field:this:0x00000938, field:this:0x0000093C, field:this:0x00000940, field:this:0x00000944, field:this:0x00000948, field:this:0x0000094C, field:this:0x00000950, field:this:0x00000954, source:raw]
    // ASSIGNMENT: Reset block this+0x964..0x98C: zero this[601..604], zero byte fields this+0x96D/0x975/0x976/0x977/0x978/0x979, zero this[607], write 18446744073709551615 (-1) to this+0x980, 18446744073701163007 (-8388609) to this+0x984, 1065353216 (1.0f) to this+0x988, and 0 to this+0x98C. [field:this:0x00000964, field:this:0x00000968, field:this:0x0000096C, field:this:0x0000096D, field:this:0x00000970, field:this:0x00000974, field:this:0x00000975, field:this:0x00000976, field:this:0x00000977, field:this:0x00000978, field:this:0x00000979, field:this:0x0000097C, field:this:0x00000980, field:this:0x00000984, field:this:0x00000988, field:this:0x0000098C, source:raw]
    // ASSIGNMENT: memset(this+2928, 0, 0x38) zeroes a 56-byte block beginning at this+2928. [source:raw]
    // ASSIGNMENT: Zero this[731] = this+0xB6C and this[746] = this+0xBA8. [field:this:0x00000B6C, field:this:0x00000BA8, source:raw]
    // LOOP: Loop 11 times calling DualArrayDestructor(v11) with v11 starting at this+2988 (0xBAC) and advancing 187 dwords (748 bytes) per iteration. [callee:0x004DED20, source:raw]
    // CALL: sub_4DFB90 loop over v13 starting at this+2448 (0x990), advancing 28 bytes per iteration (termination via v15 != 1). [callee:0x004DFB90, source:raw]
    // STATE_TRANSITION: Save result = this+0x2BD4 pointer, zero this+0x2BD0, and if the pointer is non-null free it via FreeWrapper_7bcf and zero this+0x2BD4. [field:this:0x00002BD0, field:this:0x00002BD4, callee:0x00587BCF, source:raw]
    // RETURN: Return the saved (now nulled) pointer from this+0x2BD4. [function:0x004E09E0, source:raw]

    // Conservative worker pseudocode:
    //   void* ResetVehicleState(VehicleState* this) {
    //     if (dword_8AFE88 && this->secondary /* +0x4 * /) {
    //       MultiSystemStructInitializer(this);
    //       F_3DSoundSourceDestructor(this->secondary);
    //       StatusFieldCopy(dword_5EA560, this->geometry /* +0x0 * /->field_4894, 0);
    //     }
    //     TimerClampAndProcess(this);
    //     ArrayCleanup(this);
    //     F_17ElementZeroInitLoop(this+0x4);
    //     for (i = 18; i <= 35; ++i) this[i] = 0;                 /* +0x48..+0x8C * /
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //     for (p = this+212, n = 4; n; --n, p += 296) InitWithDualCall(p);
    //     F_17ElementZeroInitLoop(this+1508);
    //     F_17ElementZeroInitLoop(this+1576);
    //     for (p = this+1644, n = 8; n; --n, p += 68) F_17ElementZeroInitLoop(p);
    //     for (i = 547; i <= 557; ++i) this[i] = 0;               /* +0x88C..+0x8B4 * /
    //     this[560] = 0;                                          /* +0x8C0 * /
    //     for (n = 2; n; --n) { this[558] = 0; this[561]=this[562]=this[563]=this[564]=0; }
    //     this[569] = 0;                                          /* +0x8E4 * /
    //     for (i = 573; i <= 581; ++i) this[i] = 0;               /* +0x8F4..+0x914 * /
    //     for (i = 589; i <= 597; ++i) this[i] = 0;               /* +0x934..+0x954 * /
    //     for (i = 601; i <= 607; ++i) this[i] = 0;
    //     this[608] = -1; this[609] = -8388609; this[610] = 1065353216; /* 1.0f * /
    //     this[611] = 0;
    //     memset(this+2928, 0, 0x38);                          /* 56-byte block * /
    //     this[731] = 0; this[746] = 0;
    //     for (p = this+2988, n = 11; n; --n, p += 748) DualArrayDestructor(p);
    //     this[611] = 0;
    //     for (p = this+2448; ...; p += 28) sub_4DFB90(p);
    //     result = this[2805]; this[2804] = 0;
    //     if (result) { FreeWrapper_7bcf(result); this[2805] = 0; }
    //     return result;
    //   }
    // UNRESOLVED: The sub_4DFB90 loop termination (v15 != 1) is not fully resolved by the decompiler; the exact iteration count over this+2448 (step 28) is unknown.
    // UNRESOLVED: Exact semantic role of each zeroed field group (which are timers, flags, collision or audio state) is DERIVED from analysis prose, not deterministically evidenced per field.
    // UNRESOLVED: The this[559] dword (written 0 in the v8 loop, next slot after this+0x8B8) is absent from the packet field list and cannot be referenced as evidence.
    // UNRESOLVED: Field init literal 18446744073709551615 at this+0x980 is the packet's unsigned rendering of the -1 write; the raw source spells it as -1.
}
