// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004109D0
// Canonical corpus name: PerVehicleCameraUpdateIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerVehicleCameraUpdateIterator_004109d0.c

void UnknownObject::PerVehicleCameraUpdateIterator()
{
    // Per-frame per-vehicle camera/physics update tick on the main game frame path. When the scoring gate is set to direct mode it walks the global vehicle array applying wheel contact transforms; otherwise it iterates the receiver's own camera-element array dispatching mode-render physics calls and, on a coarse camera-shake timer, writes shake data for eligible camera structs to a ring buffer.
    // GUARD: Branch on the global scoring gate being set to the direct-contact mode. [global:0x008AB6E4, source:raw]
    // LOOP: Direct mode: iterate over the global vehicle count, one pass per vehicle slot. [global:0x005C329C, source:raw]
    // CALL: Call a float-parameter sub-routine per vehicle slot during the direct-mode pass. [callee:0x004F0430, source:raw]
    // CALL: Compute the wheel contact transform for each vehicle slot base (slot pointer plus an object offset) in direct mode. [callee:0x004EF180, global:0x007C54F0, source:raw]
    // LOOP: Otherwise: iterate the receiver's element array up to the count stored in the first field. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALL: Dispatch the mode-ordered render physics call for each array element with the time argument. [callee:0x0040F300, field:this:0x00000008, source:raw]
    // GUARD: When the scoring gate is in the shake-enabled mode and the stored shake timestamp plus one is older than the current time argument, refresh the camera shake timer and scan for eligible camera structs. [global:0x008AB6E4, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Store the current time argument as the updated camera shake timestamp. [field:this:0x0000006C, source:raw]
    // GUARD: Skip the shake sweep when the element count in the first field is not positive. [field:this:0x00000000, guard:0, source:raw]
    // LOOP: Walk the camera element array and write shake data for elements whose per-element state field is not in the excluded state. [callee:0x0040F600, field:this:0x00000008, field:this:0x00000000, source:raw]
    // LOOP: Alternate shake path: walk the camera element array and write shake data only for elements neither in the excluded state nor flagged inactive by their flag byte. [callee:0x0040F600, field:this:0x00000008, source:raw]
    // RETURN: Return the element count stored in the first field as the result. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4109D0(CameraDirector* this, float time) {
    //     if (scoringGate == 2) {
    //       for (i = 0; i < vehicleCount; ++i) { sub_4F0430(time); WheelContactTransform(vehicleArray[i] + 12); }
    //     } else {
    //       for (j = 0; j < this->count; ++j) ModeDispatchedRenderPhysicsCall(this->elements[j], time);
    //       if (scoringGate == 1 && this->shakeTime + 1.0f < time) {
    //         this->shakeTime = time;
    //         for (k = 0; k < this->count; ++k) if (this->elements[k]->state != 6) CameraShakeRingBufferWrite(this->elements[k]);
    //       } else {
    //         for (k = 0; k < this->count; ++k) if (this->elements[k]->state != 6 && this->elements[k]->flags) CameraShakeRingBufferWrite(this->elements[k]);
    //       }
    //     }
    //     return this->count;
    //   }
    // UNRESOLVED: Role of the read-only global float at 0x0059E43C is not visible in this function's body.
    // UNRESOLVED: Per-element camera struct fields at byte offsets +28 (state tag, value 6 excluded) and +10 (flag byte) are not listed in the packet field set.
    // UNRESOLVED: Purpose of the float-parameter sub-call sub_4F0430 is caller-context dependent and unresolved here.
}
