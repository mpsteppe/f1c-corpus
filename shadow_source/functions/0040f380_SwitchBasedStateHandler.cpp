// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040F380
// Canonical corpus name: SwitchBasedStateHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchBasedStateHandler_0040f380.c

void UnknownObject::SwitchBasedStateHandler()
{
    // Eight-mode __thiscall state handler. Reads the mode selector at this[7] and dispatches on its value: modes 0/1/3/4/5 run AABB collision detection with contact response against the sub-object at this[8]; mode 2 reads a sub-object vector plus a value and runs wheel-contact distance computation, visibility toggles and a UI focus change; mode 6 gates the same contact path on a bit-0 flag in the sub-object vtable at +18620; mode 7 runs the contact path with a null vector. Any unlisted mode returns immediately.
    // ASSIGNMENT: Load the mode selector value from this[7] (byte offset 0x1C) as the switch expression. [field:this:0x0000001C, source:raw]
    // STATE_TRANSITION: Switch on the mode value with eight cases (0-7 plus default), compiled to the jump table at jpt_40F393. [global:0x0040F484, source:raw]
    // CALL: Modes 0, 1, 3, 4 and 5: call F_3DCollisionDetectionWithAABBTestAndContactResp with this, the dword at sub-object offset 208 and the address of sub-object offset 212. [callee:0x004EA040, field:this:0x00000020, source:raw]
    // CALCULATION: Mode 2: read the sub-object pointer this[8], load the dword at sub-object offset 208 as the UI focus target, and load a three-component double vector from sub-object offsets 312, 320 and 328 into v8. [field:this:0x00000020, field:this:0x00000158, field:this:0x00000160, field:this:0x00000168, source:raw]
    // CALL: Mode 2 and mode 6 entry: toggle scene node visibility on via SceneNodeVisibilityToggle(1). [callee:0x0054FB40, source:raw]
    // CALL: Shared label: run VehicleBodyToWheelContactDistanceComputation on the selected vector or sub-object wheel-contact pointer. [callee:0x004E9A40, source:raw]
    // CALL: Shared label: change UI focus to the selected target via UIFocusChange(target, 1). [callee:0x0054F7A0, source:raw]
    // CALL: Shared label: toggle scene node visibility back off via SceneNodeVisibilityToggle(0). [callee:0x0054FB40, source:raw]
    // GUARD: Mode 6 gate: read the sub-object vtable byte at offset 18620 (0x48BC) and proceed only when bit 0 is set. [field:*(this+0x20):0x000048BC, field:this:0x00000020, source:raw]
    // CALCULATION: Mode 6: load the UI focus target as the dword at sub-object index 442 and the wheel-contact pointer as sub-object offset 13548. [field:this:0x000000F0, field:this:0x00000708, source:raw]
    // CALL: Mode 7: toggle visibility on, run wheel-contact distance computation with a null vector, change UI focus to the sub-object pointer this[8], then toggle visibility off. [callee:0x0054FB40, callee:0x004E9A40, callee:0x0054F7A0, field:this:0x00000020, source:raw]
    // RETURN: Return the mode value (default path) or the last stored result value; the default case returns without any side effect. [source:raw]

    // Conservative worker pseudocode:
    //   void *SwitchBasedStateHandler(int *this, int a2) {
    //     int mode = this[7];
    //     switch ((unsigned)mode) {
    //     case 0: case 1: case 3: case 4: case 5:
    //       return F_3DCollisionDetectionWithAABBTestAndContactResp(this,
    //               *(int *)(this[8] + 208), this[8] + 212);
    //     case 2:
    //       {
    //         int focus = *(int *)(this[8] + 208);
    //         double v[3];
    //         v[0] = *(double *)(this[8] + 312);
    //         v[1] = *(double *)(this[8] + 320);
    //         v[2] = *(double *)(this[8] + 328);
    //         SceneNodeVisibilityToggle(1);
    //         contact_and_focus((float *)v, focus);
    //         return 0;
    //       }
    //     case 6:
    //       if ((*(unsigned char *)(*((int *)this[8]) + 18620) & 1) != 0) {
    //         int focus = ((int *)this[8])[442];
    //         SceneNodeVisibilityToggle(1);
    //         contact_and_focus((float *)(this[8] + 13548), focus);
    //       }
    //       return 0;
    //     case 7:
    //       SceneNodeVisibilityToggle(1);
    //       VehicleBodyToWheelContactDistanceComputation(0);
    //       UIFocusChange(this[8], 1);
    //       return SceneNodeVisibilityToggle(0);
    //     default:
    //       return mode;
    //     }
    //   }
    // UNRESOLVED: Meaning of the eight mode enum values (0-7) and the identity of the owning object are unknown.
    // UNRESOLVED: Sub-object byte offsets 208, 212, 312, 320, 328, 13548 and index 442 have no semantic names here.
    // UNRESOLVED: The vtable flag at sub-object offset 18620 (0x48BC) bit 0 gates mode 6 but its meaning is unknown.
    // UNRESOLVED: The deterministic field base/offset labels (e.g. field:this:0x000000F0 for the UI focus target) do not match the raw source displacements literally; they are treated as extraction labels, not additional offsets.
}
