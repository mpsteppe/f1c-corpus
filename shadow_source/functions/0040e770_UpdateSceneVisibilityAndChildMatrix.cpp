// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E770
// Canonical corpus name: ShortComputation_e770
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_e770_0040e770.c

void UnknownObject::UpdateSceneVisibilityAndChildMatrix()
{
    // Per-frame camera/scene tick: toggles scene-node visibility, reads a mode selector from this+0x1C and conditionally mixes audio physics for modes 0-2, computes a dual-matrix transform into six locals, then switches on the mode (0-5): each case fetches the child object pointer at this+0x20, writes argument a2 into child+208, and invokes the child's virtual method (case 0 through the raw vtable pointer at child+0, cases 1-5 through the thiscall virtual). The six computed matrix components are stored into the child's matrix storage. Finally sub_40ED10(this) runs cleanup and the result is a3 unless a3 is zero, in which case sub_4BE010(this) is returned.
    // CALL: SceneNodeVisibilityToggle(0) toggles scene-node visibility with argument 0. [callee:0x0054FB40, source:raw]
    // CALCULATION: Read the mode selector from this[7] (byte offset 0x1C); it drives the audio-mix guard and the switch dispatch. [field:this:0x0000001C, source:raw]
    // GUARD: When the mode selector (this+0x1C) is at most 2, perform audio-physics mixing. [field:this:0x0000001C, source:raw]
    // CALL: AudioPhysicsMixWithLerp(a2, this[7]) mixes audio physics with linear interpolation for the low modes. [callee:0x0040E2B0, field:this:0x0000001C]
    // CALL: DualMatrixTransformMultiply(&v10, &v11, &v12, &v13, &v14, &v15) computes a dual-matrix transform into the six local components. [callee:0x0054B530, source:raw]
    // STATE_TRANSITION: switch(this[7]) over the jump table at jpt_40E7C4: cases 0-5 each fetch the child pointer this[8] (this+0x20), write a2 into child+208, and invoke the child's virtual method (case 0 calls the raw vtable function pointer read at child+0; cases 1-5 call the thiscall virtual through the vtable). The default case performs no dispatch. [field:this:0x00000020, field:*(this+0x20):0x00000000, global:0x0040E83C, source:raw]
    // ASSIGNMENT: After dispatch, the six computed components v10..v15 are written into the child object's matrix storage (the packet records the first three as fields this+0x24, this+0x28, this+0x2C, and the remaining three into the next dwords of the same storage). [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // CALL: sub_40ED10(this) runs the cleanup/finalize subroutine on this; the packet records it as writing field this+0xF0. [callee:0x0040ED10, field:this:0x000000F0]
    // GUARD: If a3 is zero, take the return path that calls sub_4BE010(this); otherwise return a3 directly. [callee:0x004BE010, source:raw]
    // RETURN: Return a3 when non-zero, else return the result of sub_4BE010(this). [callee:0x004BE010, source:raw]

    // Conservative worker pseudocode:
    //   SceneNodeVisibilityToggle(0);
    //   mode = this[7];
    //   if (mode <= 2) AudioPhysicsMixWithLerp(a2, mode);
    //   DualMatrixTransformMultiply(&c0, &c1, &c2, &c3, &c4, &c5);
    //   switch (mode) {
    //     case 0: child = this[8]; vtable = *child; child[208/4] = a2; (*vtable)(); break;
    //     case 1..5: child = this[8]; child[208/4] = a2; (**(vtable**)child)(child); break;
    //     default: break;
    //   }
    //   child[1] = c0; child[2] = c1; child[3] = c2; child[4] = c3; child[5] = c4; child[6] = c5;
    //   sub_40ED10(this);
    //   return a3 ? a3 : sub_4BE010(this);
    // UNRESOLVED: global dword_8AB710 is read but the decompiled text does not show where it feeds in; likely a mode/flag consulted by the switch or vtable dispatch, but its use is not evidenced.
    // UNRESOLVED: The write of a2 into child+208 is not represented in the packet field list; the target field's identity is unconfirmed.
    // UNRESOLVED: Packet fields this+0x24/0x28/0x2C are recorded on the `this` base, while the decompiled writes land on the child object via this[8]; the two bases may alias but the packet does not prove identity.
    // UNRESOLVED: sub_40ED10 and sub_4BE010 semantics are unknown beyond being cleanup/return-path helpers.
    // UNRESOLVED: The relationship between the mode selector (0-5) and the concrete camera/view modes is not established.
}
