// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040F550
// Canonical corpus name: UICameraModeDispatchWithVehicleDataRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UICameraModeDispatchWithVehicleDataRead_0040f550.c

void UnknownObject::UICameraModeDispatchWithVehicleDataRead()
{
    // Mode-based dispatch on the mode selector at this+0x1C. For modes 0-5, integrates physics state into the position fields (this+0xC) and sets the activity flag byte at this+0xA to 1. For mode 6, accumulates vehicle telemetry, then copies a 3-dword position triplet from the sub-object at this+0x20 (offset 0x34D4) into the position fields this+0xC/0x10/0x14. Any other mode returns immediately. Returns the last computed result.
    // ASSIGNMENT: Load the mode selector from this+0x1C into result before dispatch. [field:this:0x0000001C, source:raw]
    // STATE_TRANSITION: switch(result) dispatch on the mode value via the jump table at 0x0040F5DC. [global:0x0040F5DC, field:this:0x0000001C, source:raw]
    // CALL: For modes 0-5: call PhysicsStateIntegration(a2, this+0xC) to integrate physics state into the position fields. [callee:0x00459A40, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: For modes 0-5: set the activity flag byte at this+0xA to 1 after physics integration. [field:this:0x0000000A, source:raw]
    // CALL: For mode 6: call VehicleTelemetryPositionAccumulator(a2) to accumulate vehicle telemetry position. [callee:0x004EC080, source:raw]
    // CALCULATION: For mode 6: compute the source pointer v4 as the sub-object at this+0x20 advanced by constant offset 13524 (0x34D4). [field:this:0x00000020, field:*(this+0x20):0x000034D4, source:raw]
    // ASSIGNMENT: For mode 6: copy the 3-dword position triplet from sub-object offsets 0x34D4/0x34D8/0x34DC into the destination position fields at this+0xC/0x10/0x14. [field:*(this+0x20):0x000034D4, field:*(this+0x20):0x000034D8, field:*(this+0x20):0x000034DC, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // RETURN: Return the computed result; the default branch returns the raw mode value. [source:raw]
    // CALL: Invoked by ParticleEffectUpdateDispatch (0x004EB430) on the frame path. [caller:0x004EB430, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40F550(int this, int a2) {
    //     int result = *(_DWORD *)(this + 28);
    //     switch (result) {
    //       case 0: case 1: case 2: case 3: case 4: case 5:
    //         result = PhysicsStateIntegration(a2, this + 12);
    //         *(_BYTE *)(this + 10) = 1;
    //         break;
    //       case 6:
    //         VehicleTelemetryPositionAccumulator(a2);
    //         { _DWORD *src = (_DWORD *)(*(_DWORD *)(this + 32) + 13524);
    //           _DWORD *dst = (_DWORD *)(this + 12);
    //           dst[0] = src[0]; result = src[1]; dst[1] = result; dst[2] = src[2]; }
    //         break;
    //       default:
    //         return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object type holding the mode selector at this+0x1C is unknown.
    // UNRESOLVED: Semantics of the 3-dword value copied from sub-object +0x34D4 are labeled position per prior analysis but not independently confirmed.
}
