// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560FE0
// Canonical corpus name: sub_560FE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560FE0_00560fe0.c

void UnknownObject::WheelShadowCameraUpdate()
{
    // Recursive update of a shadow-map camera projection for a vehicle's wheel node. Selects a wheel slot via a per-wheel index (scaled by a 96 stride) into the vehicle's wheel data, pushes suspension parameters, then computes a frustum half-angle from the wheel angle and a base offset, dispatches to the projection/render pipeline, and recurses into sibling wheel nodes when enabled. Returns -2 on the early bail paths and on the cleanup branch.
    // ASSIGNMENT: Dereference the vehicle physics pointer chain from this+12 to obtain the wheel list head v4. [field:this:0x0000000C, field:*(this+0xC):0x00000000, source:raw]
    // GUARD: Branch on StructFieldGetter(dword_8B78A0): when the mode flag object is set, compute a wheel-indexed slot; otherwise use the plain base value. [callee:0x0055C9B0, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Compute this+16 (selected wheel slot): base value v4[89], plus 96 times either the per-wheel index read through the deeply nested wheel-data chain (this+24 to +312, +64, +560, then +40) when the bit at this+36 is set, or this+40 otherwise. [field:this:0x00000010, field:this:0x00000018, field:this:0x00000024, field:this:0x00000028, field:*(*(this+0xC)+0x0):0x00000164, field:*(this+0x18):0x00000138, field:*(*(this+0x18)+0x138):0x00000040, field:*(*(*(this+0x18)+0x138)+0x40):0x00000230, field:*(*(*(*(this+0x18)+0x138)+0x40)+0x230):0x00000028, source:raw]
    // CALL: Push suspension physics parameters: SuspensionPhysicsParameterSet with the vehicle physics pointer and the parameter pointer read from the selected wheel slot (*(this+16)+84). [callee:0x00542560, field:this:0x0000000C, field:this:0x00000010, field:*(this+0x10):0x00000054, source:raw]
    // GUARD: Read the suspension state pointer at *(this+12)+412; bail out with -2 when it is null or when the flag word at +24 lacks a specific suspension flag. [field:this:0x0000000C, field:*(this+0xC):0x0000019C, field:*(*(this+0xC)+0x19C):0x00000018, source:raw]
    // GUARD: Branch on render/camera state: bit 2 of the flags at ((*(this+24)+312)+60) gates the projection path, and bit 5 of the flags at (*(this+24)+20) selects between the shadow-camera sub-path and the alternate cleanup path. [field:this:0x00000018, field:*(this+0x18):0x00000138, field:*(*(this+0x18)+0x138):0x0000003C, field:*(this+0x18):0x00000014, source:raw]
    // ASSIGNMENT: Read the wheel angle float at *(this+24)+24 and the branch-enable flag at *(this+24)+316 that selects between the scene-position getter and the triple-field query. [field:*(this+0x18):0x00000018, field:*(this+0x18):0x0000013C, source:raw]
    // CALCULATION: Compute the frustum half-angle as v38 = 2 * fabs(atan2(wheelAngle * 1.2, flt_5DD848)) using the base offset global. [global:0x005DD848, field:*(this+0x18):0x00000018, source:raw]
    // CALL: Traverse the wheel list via LinkedListTraversal and fetch the node position through TripleFieldGetter_d590 into three float outputs. [callee:0x005457C0, callee:0x0055D590, source:raw]
    // CALL: Call sub_542050 on the vehicle physics pointer with the doubled half-angle for both axes and flag 1. [callee:0x00542050, source:raw]
    // CALL: TwoFieldSetterCall with the base offset minus and plus the doubled wheel angle, centered on flt_5DD848. [callee:0x005423C0, global:0x005DD848, source:raw]
    // CALL: Read the scene node position (SceneNodePositionGetter) or query it (TripleFieldQuery) from the render state at *(this+24)+312 into three float outputs. [callee:0x0054B950, callee:0x0054B420, field:*(this+0x18):0x00000138, source:raw]
    // CALL: OrientationRotationMatrixUpdate on the vehicle physics pointer with the three computed offset values. [callee:0x00541D10, source:raw]
    // CALL: CameraProjectionUpdate on the vehicle physics pointer with projection mode 14. [callee:0x00541B70, source:raw]
    // CALL: TransformWheelForcesToChassis on the vehicle physics pointer. [callee:0x00541A70, source:raw]
    // CALL: Dispatch to sub_55C070 with the global flag object and this pointer; the main path passes index 0, the alternate cleanup path passes index 16. [callee:0x0055C070, global:0x008B78A0, source:raw]
    // ASSIGNMENT: Set a flag bit on the this+36 flags word to record that the shadow update was performed. [field:this:0x00000024, source:raw]
    // CALL: Re-read the suspension pointer at *(this+12)+412; when the flag at +24 is set, call ReturnZero and clear a high flag on the same word. [callee:0x00540240, field:this:0x0000000C, field:*(this+0xC):0x0000019C, field:*(*(this+0xC)+0x19C):0x00000018, source:raw]
    // STATE_TRANSITION: Recurse into sub_560FE0 for a sibling wheel node when this+44 is non-zero, and again when this+52 is non-zero and the third argument is set. [callee:0x00560FE0, field:this:0x0000002C, field:this:0x00000034, source:raw]
    // RETURN: Return the accumulated result: -2 on the early bail and cleanup paths, 0 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = ***(this + 12);                      // wheel list head
    //   if (structFieldGetter(dword_8B78A0))
    //       *(this + 16) = v4[89] + 96 * (bitAt(this+36) ? nestedWheelIndex : *(this + 40));
    //   else
    //       *(this + 16) = v4[89];
    //   suspensionPhysicsParameterSet(*(this + 12), *(*(this + 16) + 84));
    //   v6 = *(*(this + 12) + 412);
    //   if (!v6) return -2;
    //   if (!(*(v6 + 24) & HIGH_FLAG)) return -2;
    //   if (renderPathEnabled) {
    //       if (shadowPath) {
    //           node = listTraversal(v4, 0);
    //           angle = fabs(atan2(*(*(this + 24) + 24) * 1.2, flt_5DD848)) * 2;
    //           sub_542050(*(this + 12), angle, angle, 1);
    //           twoFieldSetterCall(*(this + 12), flt_5DD848 - delta, flt_5DD848 + delta);
    //           scenePosition = getterOrQuery(*(*(this + 24) + 312));
    //           orientationRotationMatrixUpdate(*(this + 12), offsets);
    //           cameraProjectionUpdate(*(this + 12), 14);
    //           transformWheelForcesToChassis(*(this + 12));
    //           sub_55C070(dword_8B78A0, this, 0);
    //       } else if (*(this + 44)) {
    //           // alternate cleanup branch, index 16, result = -2
    //       }
    //       *(this + 36) |= 8;
    //   }
    //   if (*(this + 44)) sub_560FE0(a2, 1);
    //   if (*(this + 52) && a3) sub_560FE0(a2, 1);
    //   return result;
    // UNRESOLVED: The precise meanings of the 96 wheel stride and the 1.2 angle multiplier are inferred from the numeric literals, not independently evidenced.
    // UNRESOLVED: The semantics of arguments a2 and a3 for the recursive self-call are not established; the recursion reuses a2 as the new instance pointer.
    // UNRESOLVED: The identities of the high suspension flags and of the flag bit set on this+36 are unknown.
    // UNRESOLVED: dbl_5B8998 is listed as a read global but does not appear in the decompiled body.
    // UNRESOLVED: sub_55C070, sub_542050, TwoFieldSetterCall and the getter/query pair semantics are inferred from their call-site shapes only.
}
