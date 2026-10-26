// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409A00
// Canonical corpus name: CameraModeViewportUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraModeViewportUpdate_00409a00.c

void UnknownObject::CameraModeViewportUpdate()
{
    // Per-frame camera/viewport update. Reads the primary context pointer at this+4 (early return if null), sets camera-update flag bit 4096 via FlagBitSetter_a160, dispatches on the camera mode at this+0x34 (cases 0-8 plus default) to select a per-mode camera sub-object pointer, runs the 3D transform that produces the viewport position/orientation (matrix+translation, or local-to-world for the cockpit mode), clamps and commits the mode-3 camera angle, applies optional mirror negation and per-axis Euler rotation adjustments, invokes the camera sub-object's virtual update, feeds position/orientation into utility calls, applies a negated chassis transform when the flag at context+0x1B0 is set, and returns a conditional float setter result. Modes 7/8 drive a two-step offset state machine through dword_5BE900 that applies +/- flt_5BE8FC to a sub-object Y offset. Rendered viewport data is copied from dword_7C54E0+88/92/96.
    // GUARD: Early-exit guard: read the primary context pointer at this+4 and return 0 immediately when it is null, otherwise proceed with the camera update. [field:this:0x00000004, source:raw]
    // CALL: Call FlagBitSetter_a160(4096) to mark the camera update path (sets flag bit 4096). [callee:0x0054A160, source:raw]
    // CALL: Invoke the virtual method at vtable slot offset 20 of this (this+0 vtable pointer) to prepare the camera for update. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Dispatch on the camera mode selector at this+0x34 via the jump table jpt_409A3C (cases 0-8 plus a default that zeroes all position/orientation outputs). [field:this:0x00000034, global:0x00409F1C, source:raw]
    // CALL: Mode 0: transform viewport point with F_3DTransformPointByMatrixAndTranslation, select camera sub-object this+0x10, then call ConditionalBranchByFlag(1). [callee:0x004E1FD0, callee:0x004D8860, field:this:0x00000010, source:raw]
    // CALL: Mode 1: convert coordinates with LocalToWorldCoordinateTransform (cockpit path), select camera sub-object this+0x14, and when byte_7CFE70 is non-zero call ConditionalBranchByFlag(1). [callee:0x004E2070, callee:0x004D8860, field:this:0x00000014, global:0x007CFE70, source:raw]
    // CALL: Mode 2: transform viewport point, select camera sub-object this+0x18, call ConditionalBranchByFlag(1). [callee:0x004E1FD0, callee:0x004D8860, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Mode 3: transform viewport point, select camera sub-object this+0x1C (reading its vtable pointer); clamp its angle field at +0xA0 into [-2.95, -0.050000001], write the clamped value back along with copied components at +0xA4 and +0xA8, then commit via the sub-object vtable slot at offset 28. [callee:0x004E1FD0, callee:0x004D8860, field:this:0x0000001C, field:*(this+0x1C):0x00000000, field:*(this+0x1C):0x000000A0, field:*(this+0x1C):0x000000A4, field:*(this+0x1C):0x000000A8, field:*(*(this+0x1C)+0x0):0x0000001C, source:raw]
    // ASSIGNMENT: Copy the viewport position triple: read three dwords at dword_7C54E0 + 88, + 92, + 96 into the position buffer passed to the camera update. [global:0x007C54E0, source:raw]
    // CALCULATION: Mirror handling: when the flag at this+0x40 is non-zero, negate the view X component, add 3.1415927 to the Y rotation, and negate the Z component. [field:this:0x00000040, source:raw]
    // CALL: When any of the Euler adjustment fields this+0x44, this+0x48, this+0x4C is non-zero, convert Euler angles to a rotation matrix with EulerToRotationMatrix, then apply RotationMatrixY for +0x48, RotationMatrixYAxisRotationEulerExtraction for +0x44, and RotateMatrixAndExtractAngles for +0x4C. [callee:0x00566E40, callee:0x00567400, callee:0x00567340, callee:0x005674C0, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: Main camera update: compute parameters via ScoringGateConditionCheck(this) and ShortComputation_84a0(), then call the camera sub-object's virtual method at vtable slot offset 24 with the viewport position, orientation buffer, the copied post-process triple, and the two computed floats. [callee:0x0040C780, callee:0x004084A0, field:*(*(this+0x1C)+0x0):0x00000018, source:raw]
    // ASSIGNMENT: Read the updated position and orientation back from the camera sub-object: position at +0xC, +0x10, +0x14 and orientation at +0x18, +0x1C, +0x20, then feed all six components into UtilityFunction_1cd0. [callee:0x00541CD0, field:*(this+0x1C):0x0000000C, field:*(this+0x1C):0x00000010, field:*(this+0x1C):0x00000014, field:*(this+0x1C):0x00000018, field:*(this+0x1C):0x0000001C, field:*(this+0x1C):0x00000020, source:raw]
    // CALL: When the flag at (this+4)+0x1B0 is non-zero, fetch the vehicle chassis world transform with ChassisWorldTransform, negate all six resulting components, and pass them through UtilityFunction_1cd0 again. [field:*(this+0x4):0x000001B0, callee:0x004E2130, callee:0x00541CD0, source:raw]
    // CALL: Retrieve two parameter fields with DualFieldGetter and two more with ShortComputation_6080 (an object field at offset 0x14 is fed through this path), scale the float pair by 0.01745433, pass the pair into sub_542050, and apply the computed pair with TwoFieldSetterCall. [callee:0x00456060, callee:0x00456080, callee:0x00542050, callee:0x005423C0, field:obj:0x00000014, source:raw]
    // RETURN: Return the result of ConditionalFloatSetter, which consumes the float at the camera sub-object offset +0x48. [callee:0x00542680, field:*(this+0x1C):0x00000048, source:raw]
    // STATE_TRANSITION: Modes 4-8 sub-object selection and offset state machine: mode 4 selects this+0x20 + 200 * this+0x3C; modes 5/6 select this+0x24 / this+0x28; modes 7/8 select this+0x2C / this+0x30 and use dword_5BE900 sequencing (0 -> 1 -> 2) to add or subtract flt_5BE8FC to the Y component at sub-object +0xC0, copying through +0xBC and +0xC4; the default case zeroes all position/orientation outputs. [callee:0x004E1FD0, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x0000003C, field:*(this+0x2C):0x000000BC, field:*(this+0x2C):0x000000C0, field:*(this+0x30):0x000000BC, field:*(this+0x30):0x000000C0, field:*(this+0x30):0x000000C4, global:0x005BE8FC, global:0x005BE900, source:raw]

    // Conservative worker pseudocode:
    //   int CameraModeViewportUpdate(void* this) {
    //     void* ctx = *(dword*)(this + 4);
    //     if (!ctx) return 0;
    //     FlagBitSetter_a160(4096);
    //     call_vtable_slot(this, 20);
    //     int target = 0;
    //     switch (*(dword*)(this + 0x34)) {
    //       case 0: transform(&pos, &ori); target = *(dword*)(this + 0x10); ConditionalBranchByFlag(1); break;
    //       case 1: local_to_world(&pos, &ori); target = *(dword*)(this + 0x14); if (byte_7CFE70) ConditionalBranchByFlag(1); break;
    //       case 2: transform(&pos, &ori); target = *(dword*)(this + 0x18); ConditionalBranchByFlag(1); break;
    //       case 3: transform(&pos, &ori); target = *(dword*)(this + 0x1C); ConditionalBranchByFlag(1);
    //               clamp_and_commit(target); break;
    //       case 4: transform(&pos, &ori); target = *(dword*)(this + 0x20) + 200 * *(dword*)(this + 0x3C); break;
    //       case 5: transform(&pos, &ori); target = *(dword*)(this + 0x24); break;
    //       case 6: transform(&pos, &ori); target = *(dword*)(this + 0x28); break;
    //       case 7: transform(&pos, &ori); target = *(dword*)(this + 0x2C); step_offset(target, +flt_5BE8FC); break;
    //       case 8: transform(&pos, &ori); target = *(dword*)(this + 0x30); step_offset(target, -flt_5BE8FC); break;
    //       default: zero_position_and_orientation(); break;
    //     }
    //     copy_viewport_triple(dword_7C54E0 + 88);
    //     if (target) {
    //       if (*(dword*)(this + 0x40)) mirror_flip(&ori);
    //       if (*(float*)(this + 0x44) != 0.0 || *(float*)(this + 0x48) != 0.0 || *(float*)(this + 0x4C) != 0.0) {
    //         EulerToRotationMatrix(&ori, m);
    //         if (*(float*)(this + 0x48) != 0.0) RotationMatrixY(*(float*)(this + 0x48), &ori);
    //         if (*(float*)(this + 0x44) != 0.0) RotationMatrixYAxisRotationEulerExtraction(*(float*)(this + 0x44), &ori);
    //         if (*(float*)(this + 0x4C) != 0.0) RotateMatrixAndExtractAngles(*(float*)(this + 0x4C), &ori);
    //       }
    //       float s = ScoringGateConditionCheck(this);
    //       float c = ShortComputation_84a0();
    //       call_vtable_slot(target, 24, &pos, &ori, viewport, c, s);
    //       read_back_position_orientation(target, &pos, &ori);
    //       UtilityFunction_1cd0(pos, ori);
    //       if (*(dword*)(ctx + 0x1B0)) {
    //         ChassisWorldTransform(&t, &o);
    //         negate_and_UtilityFunction_1cd0(t, o);
    //       }
    //       DualFieldGetter(&a, &b);
    //       ShortComputation_6080(&c, &d);
    //       sub_542050(a * 0.01745433, b * 0.01745433, 0);
    //       TwoFieldSetterCall(c, d);
    //       return ConditionalFloatSetter(*(float*)(target + 72));
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_59E440, flt_59E65C, flt_59E660, flt_59E664, flt_59E668, dword_8AD298 and dword_8AFE88 are recorded as read by this function but do not appear by name in the decompiled text; they are likely constant operands folded by Hex-Rays or reached through an inlined helper, so their exact role here is not traceable from this packet.
    // UNRESOLVED: The concrete class of the camera/viewport object (this) and of the camera sub-object selected per mode is unknown; field semantics are derived only from the access pattern.
    // UNRESOLVED: dword_5BE900 0 -> 1 -> 2 sequencing spans two calls (modes 7 and 8); where the reset back to 0 happens is outside this function.
    // UNRESOLVED: field:obj:0x00000014 participates in the DualFieldGetter/ShortComputation_6080 path but the owning object it resolves against is not identifiable from this packet.
}
