// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E4500
// Canonical corpus name: PhysicsTireSystemConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsTireSystemConstructor_004e4500.c

void UnknownObject::PhysicsTireSystemConstructor()
{
    // Constructor for the physics tire system. Runs sub-initializers on several embedded sub-structures (forces at this+2, dual-array at this+441, 5-loop structure at this+3248, four tire sub-structures spaced 28 DWORDs apart from this+3806, zero-init sub-structure at this+3934), sets defaults (this+0x32BC = -1, this+0x39A4 = 0), then a post-constructor finalization call. Called once from RaceStructInit. No guards — every step always runs.
    // CALL: sub_4F6F20(this + 2) initializes the force sub-structure at the object base. [callee:0x004F6F20, source:raw]
    // CALL: sub_4DFBB0((int)(this + 441)) initializes the dual-array sub-structure. [callee:0x004DFBB0, source:raw]
    // CALL: F_5LoopInitCall(this + 3248) initializes the 5-loop sub-structure. [callee:0x004A48C0, source:raw]
    // LOOP: Loop of 4 iterations: sub_4DFB90(v2) initializes a single tire sub-structure, advancing v2 by 28 DWORDs each iteration (4 tires from this+3806). [callee:0x004DFB90, source:raw]
    // CALL: ConstructorZeroInitSubCalls(this + 3934) zero-initializes the sub-structure at the tail of the object. [callee:0x004F2430, source:raw]
    // ASSIGNMENT: this[3247] = -1 writes -1 (0xFFFFFFFF) to the field at this+0x32BC. [field:this:0x000032BC, source:raw]
    // ASSIGNMENT: this[3689] = 0 writes 0 to the field at this+0x39A4 (EngineMaxRPM). [field:this:0x000039A4, source:raw]
    // CALL: sub_4E4790((int)this) runs post-constructor finalization for the tire system. [callee:0x004E4790, source:raw]
    // RETURN: Returns this. [source:raw]

    // Conservative worker pseudocode:
    //   sub_4F6F20(this + 2);
    //   sub_4DFBB0((int)(this + 441));
    //   F_5LoopInitCall(this + 3248);
    //   for (v2 = this + 3806, v3 = 4; v3; --v3, v2 += 28)
    //       sub_4DFB90(v2);
    //   ConstructorZeroInitSubCalls(this + 3934);
    //   this[3247] = -1;   // +0x32BC
    //   this[3689] = 0;    // +0x39A4
    //   sub_4E4790((int)this);
    //   return this;
    // UNRESOLVED: The sub-structure roles (force, dual-array, 5-loop, tire, tail zero-init) are descriptive only; the callees are unnamed helpers whose internal layouts are not pinned here.
}
