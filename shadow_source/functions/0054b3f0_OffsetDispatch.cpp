// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054B3F0
// Canonical corpus name: OffsetDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OffsetDispatch_0054b3f0.c

void UnknownObject::OffsetDispatch()
{
    // Adds each of the three parameters a2, a3, a4 onto the corresponding fields this+0x20, this+0x24, this+0x28, then forwards the resulting sums to ThreeFieldSetterWithSubCall(this, v4, v5, v6). A pure offset-and-dispatch helper with no local side effects beyond the callee write.
    // CALCULATION: Compute v4 = a2 + *(float*)(this + 0x20) [field:this:0x00000020, source:raw]
    // CALCULATION: Compute v5 = a3 + *(float*)(this + 0x24) [field:this:0x00000024, source:raw]
    // CALCULATION: Compute v6 = a4 + *(float*)(this + 0x28) [field:this:0x00000028, source:raw]
    // CALL: Dispatch the three sums via ThreeFieldSetterWithSubCall(this, v4, v5, v6) [callee:0x0054B3B0, source:raw]
    // CALL: Called by sub_466350 (00466350) [caller:0x00466350, source:raw]
    // CALL: Called by VehicleSceneLoadAndPositionTires (004681b0) [caller:0x004681B0, source:raw]
    // CALL: Called by CameraViewportRenderSetup (004fbd70) [caller:0x004FBD70, source:raw]

    // Conservative worker pseudocode:
    //   float v6 = a4 + *(float*)(this + 0x28);
    //   float v5 = a3 + *(float*)(this + 0x24);
    //   float v4 = a2 + *(float*)(this + 0x20);
    //   ThreeFieldSetterWithSubCall(this, v4, v5, v6);
    // UNRESOLVED: The meaning of the three read fields (0x20, 0x24, 0x28) and the owning object type are unknown; the callers span vehicle scene/tyre positioning and camera viewport render setup, so the class role cannot be pinned from this packet
    // UNRESOLVED: Why the offsets are added to the incoming values before dispatch (rather than written through) is unexplained by the packet
}
