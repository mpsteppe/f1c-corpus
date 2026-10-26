// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F710
// Canonical corpus name: TeamRadioNetworkMessageProcessing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TeamRadioNetworkMessageProcessing_0045f710.c

void UnknownObject::ProcessTeamRadioNetworkMessages()
{
    // Processes team-radio network messages during active session phases (1 or 2). When a shared global-state session is referenced, first performs resource-manager frame cleanup and a per-vehicle slot refresh. Then drains incoming messages: SEH-protected data copy off the session interface, message counter reset, driver-index resolution, collision contact solving with the session time, and net-comm dispatch. During an active phase, queued session data is replayed through the ring buffer, otherwise per-entity texture work is gated and a final dispatch is attempted. Raw source is truncated at the per-entity loop body.
    // GUARD: Guard on ReferencesGlobalState(this): only run global-session cleanup when the receiver references shared global state. [callee:0x00461440, source:raw]
    // CALL: ResourceManagerFrameCleanup(&dword_7CD2A8): per-frame resource-manager cleanup. [callee:0x004651C0, global:0x007CD2A8, source:raw]
    // LOOP: Iterate the vehicle array from dword_5EF9A0 (stride 4656) up to the end bound dword_7C87A0. [global:0x005EF9A0, global:0x007C87A0, source:raw]
    // GUARD: Skip slots whose state int32 equals -1 (inactive slot). [source:raw]
    // CALL: ShortComputation_52d0(&dword_7CD2A8, slotIndex): refresh each active vehicle slot in the resource manager. [callee:0x004652D0, global:0x007CD2A8, source:raw]
    // CALCULATION: Compute phase gate v5 = (this+0x3FC4 == 1 or this+0x3FC4 == 2): active racing phases gate message processing. [field:this:0x00003FC4, source:raw]
    // LOOP: Message receive loop: SEHProtectedDataCopy(this+0x3FB8 interface, v16, size 432, &v17); break out when a message is successfully copied. [callee:0x0057A760, field:this:0x00003FB8, source:raw]
    // ASSIGNMENT: Reset message counter this+0x388 to 0 on each received message. [field:this:0x00000388, source:raw]
    // CALL: If active phase: LinearSearchIn104ElementArray(this, v17) resolves the driver index and its result is merged into v16[0] (low byte). [callee:0x00460C30, source:raw]
    // CALL: CollisionContactSolver(this+0x68F0, v16, dbl_8AFEA0): solve collision contact with the session time global. [callee:0x0045C8F0, global:0x008AFEA0, source:raw]
    // CALL: NetCommSessionMessageDispatcher(this, v16): dispatch the received message into the net-comm session. [callee:0x0045D890, source:raw]
    // CALL: If active phase and global state referenced: SessionDataCopy(&dword_7D2E50) then replay via AdvanceRingBuffer(&dword_7D2E50, v16) calling sub_465300(&dword_7CD2A8, v16) per entry. [callee:0x004B3B30, callee:0x004B3AF0, callee:0x00465300, global:0x007D2E50, global:0x007CD2A8, source:raw]
    // CALL: Else path: ThunkToFUN00461480(v18) then v15 = SingleFunctionDispatch(*(void **)this) using the method pointer at this+0x0. [callee:0x00461470, callee:0x00462300, field:this:0x00000000, source:raw]
    // LOOP: Iterate this+0x3E14 active entities using the byte index array at this+0x410. [field:this:0x00003E14, field:this:0x00000410, source:raw]
    // GUARD: TwoStageCheck() gates per-entity work. [callee:0x004614C0, source:raw]
    // CALCULATION: Load v11 = *(this + 4 * entityIndex + 15896) and compare it against dispatched id v15; the per-entity body after this point is truncated in the raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void TeamRadioNetworkMessageProcessing(char *this) {
    //     if (ReferencesGlobalState(this)) {
    //       ResourceManagerFrameCleanup(&dword_7CD2A8);
    //       for (v3 = dword_5EF9A0, v2 = 0; v3 < dword_7C87A0; v3 += 4656, ++v2)
    //         if (*v3 != -1) ShortComputation_52d0(&dword_7CD2A8, v2);
    //     }
    //     int phase = *((int *)this + 4081);
    //     bool active = phase == 2 || phase == 1;
    //     for (;;) {
    //       v6 = *((void **)this + 4078);
    //       v14 = 432;
    //       if (SEHProtectedDataCopy(v6, v16, &v14, &v17)) break;
    //       *((int *)this + 226) = 0;
    //       if (active) {
    //         v7 = LinearSearchIn104ElementArray(this, v17);
    //         v16[0] = v7 | v16[0] & 0xFFFFFF00;
    //       }
    //       CollisionContactSolver((int *)this + 26864, v16, dbl_8AFEA0);
    //       NetCommSessionMessageDispatcher(this, v16);
    //     }
    //     if (active) {
    //       if (ReferencesGlobalState(this)) {
    //         SessionDataCopy(&dword_7D2E50);
    //         while (AdvanceRingBuffer(&dword_7D2E50, v16)) sub_465300(&dword_7CD2A8, v16);
    //       } else {
    //         ThunkToFUN00461480(v18);
    //         v15 = SingleFunctionDispatch(*(void **)this);
    //         /* per-entity loop body truncated in raw source * /
    //       }
    //     }
    //   }
    // UNRESOLVED: Raw source is truncated inside the per-entity loop; the texture-rendering body (TextureCreationWrapper) and final dispatch tail are not fully visible.
    // UNRESOLVED: dword_7D0E98 (threshold, compared > 8) and dword_7D0F04 (net-comm state flag gating final dispatch) are consumed in the truncated tail.
    // UNRESOLVED: CollisionContactSolver target offset 0x68F0 (decimal 26864) is not present in the packet field evidence.
}
