// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408DE0
// Canonical corpus name: ConditionalSubsystemCallWithParameter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalSubsystemCallWithParameter_00408de0.c

void UnknownObject::ConditionalSubsystemCallWithParameter()
{
    // Conditionally invokes a subsystem operation on a2 and optionally a render draw with clipping. Guarded by the enable flag at this[2] (field this+0x8). When enabled, calls sub_541CA0(a2). If after that call a2 evaluates to zero and the sub-object pointer at this[3] (field this+0xC) is non-null, calls RenderDrawOperationWithClipping with the sub-object's dimension fields at +28 and +32 and the global unk_686B75 as the last argument. Otherwise returns the sub_541CA0 result. Part of the camera/view render dispatch path from ViewCameraModeDispatch.
    // GUARD: Enable guard: this[2] (field this+0x8) must be non-zero before any subsystem call is made [field:this:0x00000008, source:raw]
    // CALL: result = sub_541CA0(a2) performs the subsystem operation on the forwarded parameter [callee:0x00541CA0, source:raw]
    // GUARD: Draw guard: proceed only when a2 is zero after the call AND this[3] (field this+0xC) is non-null [field:this:0x0000000C, source:raw]
    // CALL: RenderDrawOperationWithClipping(0, 0, *(v4+28), *(v4+32), &unk_686B75) renders with the sub-object's dimension fields and the static parameter global [callee:0x00543440, field:this:0x00000028, field:this:0x0000002C, global:0x00686B75, source:raw]
    // RETURN: Return the render call result on the draw path; otherwise return the sub_541CA0 result (or leave the default result value when the enable guard fails) [source:raw]
    // CALL: Called from ViewCameraModeDispatch as part of the per-frame camera/view render dispatch [caller:0x00409440]

    // Conservative worker pseudocode:
    //   int ConditionalSubsystemCallWithParameter(_DWORD *this, int a2) {
    //     int result;
    //     if (this[2]) {
    //       result = sub_541CA0(a2);
    //       if (!a2) {
    //         int v4 = this[3];
    //         if (v4)
    //           return RenderDrawOperationWithClipping(0, 0, *(_DWORD*)(v4+28), *(_DWORD*)(v4+32), &unk_686B75);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The packet normalizes the sub-object offsets +28 / +32 to field base 'this' (0x28 / 0x2C), but the raw source dereferences them through the pointer v4 = this[3]; the two readings agree only if this[3] equals the struct base
    // UNRESOLVED: Semantics of the enable flag, of the sub_541CA0 operation and of unk_686B75 are not documented by the packet
}
