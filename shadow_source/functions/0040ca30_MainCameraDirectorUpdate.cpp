// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040CA30
// Canonical corpus name: MainCameraDirectorUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MainCameraDirectorUpdate_0040ca30.c

void UnknownObject::MainCameraDirectorUpdate()
{
    // Per-frame update of the main camera director. Tracks player-vehicle changes, runs a one-time camera setup guard, negates a triple-field offset vector, then either short-circuits (clear skip flag) or picks the camera action from the AI random state machine versus keyboard input, requests the mode change, and applies camera mode-change callbacks and vehicle-position/velocity tracking on the camera controller object.
    // CALL: Retarget the camera to the current player vehicle when the player changes. [callee:0x0040C7A0, source:raw]
    // CALL: Run a short setup computation over the director object. [callee:0x0040C910, source:raw]
    // GUARD: First-time initialization guard: when the one-time flag is unset the camera is configured once. [field:this:0x0000002D, source:raw]
    // ASSIGNMENT: Set the one-time initialization flag. [field:this:0x0000002D, source:raw]
    // CALL: Configure the prior camera entity (stored in the previous-camera field) on first setup. [callee:0x00409890, field:this:0x00000018, source:raw]
    // CALL: Read a triple of float fields out into local scratch values. [callee:0x00542460, source:raw]
    // CALCULATION: Negate each component of the triple-field vector in place. [source:raw]
    // CALL: Conditional branch helper invoked with a zero flag value. [callee:0x004D8860, source:raw]
    // GUARD: Skip flag check: if the per-frame skip flag is set the update short-circuits after clearing it. [field:this:0x00000025, source:raw]
    // ASSIGNMENT: Clear the per-frame skip flag on the short-circuit path. [field:this:0x00000025, source:raw]
    // ASSIGNMENT: Reset the camera action state counter for the frame. [field:this:0x00000028, source:raw]
    // GUARD: Select the camera input source from the AI-mode flag: random state machine when set, keyboard otherwise. [field:this:0x0000002E, source:raw]
    // CALL: AI branch: drive camera selection through the random state machine with timer and trigger. [callee:0x0040C070, source:raw]
    // CALL: Input branch: map the keyboard action to a camera command. [callee:0x0040BE70, source:raw]
    // CALL: Request a camera mode change on the director. [callee:0x0040C5B0, source:raw]
    // GUARD: When the resulting camera action requests a mode transition, run the per-vehicle and camera callbacks. [source:raw]
    // LOOP: On mode transition, iterate the global vehicle array calling a per-vehicle sub-routine on each slot base. [callee:0x004F0D20, global:0x005C329C, global:0x007C54F0, source:raw]
    // CALL: Invoke the camera controller's mode-change virtual (vtable slot +16) on the current camera entity. [field:*(*(this+0x8)+0x0):0x00000010, field:*(this+0x8):0x00000000, field:this:0x00000008, source:raw]
    // CALL: Read the resulting camera state through the controller's state virtual (vtable slot +12). [field:*(*(this+0x8)+0x0):0x0000000C, field:*(this+0x8):0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Proceed with position/velocity tracking only while the global camera-tracking object is present. [global:0x008AC4C4, source:raw]
    // CALL: Fetch six values (two triples) through a delegation helper for the tracking math. [callee:0x00542420, source:raw]
    // CALCULATION: Negate the offset vector again after the delegation. [source:raw]
    // GUARD: Branch on the mode-transition result to decide between the particle path and the velocity-tracking path. [source:raw]
    // CALL: Mode-transition path: dispatch a position/velocity update virtual (vtable slot +28) on the tracking object. [global:0x008AC4C4, source:raw]
    // RETURN: When the global particle-add flag is set, return the result of adding a particle at the tracked position. [callee:0x004CCDC0, global:0x008ACEBC, source:raw]
    // GUARD: Velocity-tracking path: compare the current camera entity against the stored previous camera entity. [field:this:0x00000008, field:this:0x00000018, source:raw]
    // CALCULATION: Unchanged camera: source the vehicle position from the global vehicle-track slot offset. [global:0x007C54E0, source:raw]
    // CALL: Changed camera: fetch the entity position through the controller's position virtual (vtable slot +24) and use its float vector. [field:*(*(this+0x8)+0x0):0x00000018, field:*(this+0x8):0x00000000, source:raw]
    // CALCULATION: Clamp the velocity magnitude against the speed/velocity limit globals, scaled by a unit-conversion constant unless the conversion-disable flag is set. [global:0x007C56AC, global:0x007CFE28, global:0x007CFE4C, global:0x007CFE54, source:raw]
    // CALL: Obtain the current speed through the virtual dispatch helper on the director. [callee:0x0040C870, source:raw]
    // CALL: Feed the combined speed value into a short computation helper. [callee:0x0053D450, source:raw]
    // CALL: Dispatch the final position/velocity update virtual (vtable slot +32) on the tracking object with the offset vector and speed. [global:0x008AC4C4, source:raw]

    // Conservative worker pseudocode:
    //   char sub_40CA30(CameraDirector* this) {
    //     CameraTargetUpdateOnPlayerChange(this);
    //     ShortComputation_c910(this);
    //     if (!this->initFlag) { this->initFlag = 1; sub_409890(this->prevCamera, 0); }
    //     TripleFieldGetter_2460(&v23, &v24, &v25);
    //     v20 = -(v23 = -v23); v21 = -(v24 = -v24); v22 = -(v25 = -v25);
    //     ConditionalBranchByFlag(0);
    //     if (this->skipFlag) { this->skipFlag = 0; }
    //     else {
    //       this->stateCounter = 0;
    //       action = this->aiModeFlag ? RandomStateMachineWithTimerAndTrigger(this) : KeyboardInputActionMapper(this);
    //       CameraModeChangeRequest(this);
    //       if (action == 1) {
    //         for (v2 = 0; v2 < vehicleCount; ) sub_4F0D20(vehicleArray[v2++] + 12);
    //         this->camera->vtbl[4](this->camera);
    //       }
    //       result = this->camera->vtbl[3](this->camera);
    //     }
    //     if (trackObject) {
    //       TwoCallDelegation_2420(&v20, &v21, &v22, v26, v27, v28);
    //       v17 = -(v20 = -v20); v18 = -(v21 = -v21); v19 = -(v22 = -v22);
    //       if (action) {
    //         result = trackObject->vtbl[7](trackObject, &v20, v26);
    //         if (particleAddFlag) return ParticlePositionAdd(&v23, &v20);
    //       } else {
    //         if (this->camera == this->prevCamera) { v17 = vehiclePos.x; v18 = vehiclePos.y; v19 = vehiclePos.z; }
    //         else { p = this->camera->vtbl[6](this->camera); if (p) { v17 = p->x; v18 = p->y; v19 = p->z; trackObject->vtbl[8](trackObject, &v20, v26, &v17); } }
    //         speed = 0.0;
    //         if (!conversionDisabled) {
    //           speed = sqrt(v17*v17 + v18*v18 + v19*v19) / (flt_7CFE28 * 0.44704) * dword_7CFE4C;
    //           speed = clamp(speed, dword_7CFE54, dword_7CFE4C);
    //         }
    //         speed += VirtualDispatchHelper(this) ? *(float*)(ptr + 92) : 0.0;
    //         ShortComputation_d450(speed);
    //         return trackObject->vtbl[8](trackObject, &v20, v26, &v17);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Read-only globals 0x0059E440, 0x0059E6D8, 0x008AD298 and 0x008AFE64 appear in the packet but not in the raw source; their roles are unresolved.
    // UNRESOLVED: Identity of the tracking object behind global 0x008AC4C4 and the meaning of its vtable slots +28/+32 is unresolved.
    // UNRESOLVED: Meaning of the six values produced by TwoCallDelegation_2420 and the byte arrays v26/v27/v28 is unresolved.
    // UNRESOLVED: The per-vehicle sub-call sub_4F0D20 role on mode transitions is caller-context dependent and unresolved here.
}
