// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D070
// Canonical corpus name: SteeringWheelAnimation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringWheelAnimation_0049d070.c

void UnknownObject::SteeringWheelAnimation()
{
    // Steering-wheel HUD element update/render. Selects an engine input mode from dword_7C54E0+13000 and the +14752 time threshold, then conditionally runs a drawing pass (RenderDrawOperationWithClipping) followed by either an audio-effect or a sub-function animation chain. After the unconditional sub_49D5D0(v15) call, five animation parameter sources (this+0x4C/+0x50/+0x54/+0x58/+0x5C) are each gated on a non-null +84 target object and advanced toward it via ParamRangeClampedLerp into animation target storage.
    // GUARD: Engine-mode select: reads the mode integer at dword_7C54E0+13000 and the float threshold at dword_7C54E0+14752. Null mode, out-of-range mode (<=0 or >2) or a <=0.0f threshold picks one flag set; a valid in-range mode with positive threshold picks the other. [global:0x007C54E0, source:raw]
    // ASSIGNMENT: Sets the chain-select flag v12 and the branch flag v15 from the engine-mode test; the null-mode fallback derives both from the byte_7C9081 engine-mode flag (v15 = byte_7C9081 == 0). [global:0x007C9081, source:raw]
    // GUARD: Render gate: the render-context pointer this[4] (byte offset 0x10) and its sub-object at +84 must both be non-null, and the this[1] (byte offset 0x4) flag must be set, before any drawing occurs. [field:this:0x00000010, field:this:0x00000004, source:raw]
    // CALL: When the render gate passes, RenderDrawOperationWithClipping draws the element using the width/height fields at v14+28 and v14+32 of the geometry sub-object. [callee:0x00543440, source:raw]
    // CALL: When the chain flag v12 is set, either AudioEffectTrigger (branch flag v15 set) or sub_49D4C0 runs, followed by the animation chain TrackPositionNameFormatter, WheelRotationAnimation, GlobalStateBranchFormat, FormatRegisterDispatch and LocalBufferSubsystemCall; when v12 is clear, AudioEffectTrigger alone runs. [callee:0x0049E4E0, callee:0x0049D4C0, callee:0x0049D320, callee:0x0049D280, callee:0x0049D3F0, callee:0x0049D440, callee:0x0049D480, source:raw]
    // CALL: sub_49D5D0 is invoked unconditionally with the branch flag v15 after the mode-dependent section. [callee:0x0049D5D0, source:raw]
    // LOOP: Five animation parameter sources (this+0x4C, this+0x50, this+0x54, this+0x58, this+0x5C) are each gated on a non-null pointer and a non-null target object at +84, then ParamRangeClampedLerp(0..4, dest, target) advances the parameter toward its target, writing animation target storage at this+0x64 and this+0xA0/+0xA4/+0xA8/+0xAC. [field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000064, field:this:0x000000A0, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, source:raw]
    // CALL: Invoked from ShortComputation_f070 (0049F070) on the steering/HUD update path. [caller:0x0049F070]

    // Conservative worker pseudocode:
    //   mode = *(dword_7C54E0 + 13000);
    //   if (mode == 0) { chain = byte_7C9081; branch = (byte_7C9081 == 0); }
    //   else if (mode <= 0 || mode > 2 || *(dword_7C54E0 + 14752) <= 0.0f) { chain = 0; branch = 1; }
    //   else { chain = 1; branch = 1; }
    //   if (this[4] && *(this[4] + 84) && this[1]) {
    //     RenderDrawOperationWithClipping(0, 0, *(v14 + 28), *(v14 + 32), 0);
    //     if (chain) { branch ? AudioEffectTrigger(0, 0) : sub_49D4C0(this);
    //       TrackPositionNameFormatter(this); WheelRotationAnimation(this);
    //       GlobalStateBranchFormat(this); FormatRegisterDispatch(this); LocalBufferSubsystemCall(this); }
    //     else AudioEffectTrigger(0, 0);
    //   }
    //   sub_49D5D0(branch);
    //   for (i = 0; i < 5; ++i) {
    //     src = this[4 + i];
    //     if (src && *(src + 84)) ParamRangeClampedLerp(i, dest[i], *(src + 84));
    //   }
    // UNRESOLVED: The mapping between the five ParamRangeClampedLerp destination dword-indices (this+24/+43/+62/+81/+100) and the animation target storage offsets this+0x64 and this+0xA0..0xAC is assigned from existing analysis; it is not independently derivable from this packet.
    // UNRESOLVED: Sub-struct reads *(this+0x64)+0x1C, *(this+0x64)+0x20 and *(this+0xB0)+0x54 are flagged by packet facts as steering-input fields but never appear in the raw decompiled source.
    // UNRESOLVED: Global flt_59E440 is flagged by packet facts but absent from the raw source; the skeleton fill labels it a zero threshold, which is unverifiable from this packet.
}
