// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424CD0
// Canonical corpus name: AICommandMessageQueueDispatcher
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AICommandMessageQueueDispatcher_00424cd0.c

void F1CVehicle::AICommandMessageQueueDispatcher()
{
    // Dispatches an AI command via a switch on the command id, handling state transitions (cases 4, 5), a delayed timer (case 1), and race-phase-dependent cleanup (case 15), then manages a deduplicated command queue: append {command, value} when idle, or scan existing entries and re-send the queued response when the command is already pending.
    // STATE_TRANSITION: Switch on the command id a2. Case 4: enable state via sub_4A46F0(this, 1, 1). [callee:0x004A46F0, source:raw]
    // ASSIGNMENT: Case 5: clear the active byte at this + 0x4548 (PitLaneRouteFlag) to 0, then disable state via sub_4A46F0(this, 0, 0). [field:this:0x00004548, callee:0x004A46F0, source:raw]
    // ASSIGNMENT: Case 1: set this + 0x413C (PitDecisionTimer) to dbl_8AFEA0 (session time) + 2.0. [field:this:0x0000413C, global:0x008AFEA0, source:raw]
    // GUARD: Case 15 session-condition: if dword_7C56A4 == 7, condition is FinishState of the object referenced by this[0] (this + 0x4064 via postProcessInput) == 0; otherwise condition is dword_7C56A8 != 8. [global:0x007C56A4, global:0x007C56A8, field:this:0x00000000, field:obj:0x00004064, guard:0, source:raw]
    // GUARD: If the session-condition holds and the RetiredFlag byte at this + 0x4410 is zero, call SessionCleanupFlagClear(this). [field:this:0x00004410, callee:0x0042ADB0, source:raw]
    // CALL: Otherwise (session condition fails): call SceneRenderUpdate(0) and StateChangeNotify(0). [callee:0x004C6D90, callee:0x004A5C80, source:raw]
    // ASSIGNMENT: Case 15 continuation: set this + 0x4544 to 0, call ParameterValueSetter(18), set this + 0x4550 (WaypointSetSelector) to 1, and set the active byte at this + 0x4548 to 1. [field:this:0x00004544, callee:0x0042ACD0, field:this:0x00004550, field:this:0x00004548, source:raw]
    // GUARD: Queue stage: proceed only if the queue buffer pointer at this + 0x44A8 is non-zero. [field:this:0x000044A8, source:raw]
    // GUARD: If the current queue index at this + 0x44B0 is negative (queue idle), take the append path. [field:this:0x000044B0, source:raw]
    // GUARD: Append path capacity check: new index (index + 1) must be less than the queue capacity at this + 0x44AC. [field:this:0x000044AC, field:this:0x000044B0, source:raw]
    // ASSIGNMENT: Append path: enqueue the {command, value} pair (a2, a3) into the 8-byte slot at this + 0x44A8 at the new index, and store the new index at this + 0x44B0. [field:this:0x000044A8, field:this:0x000044B0, source:raw]
    // CALL: Call CommandQueueResponseHandler(this), then reset the queue index at this + 0x44B0 to -1. [callee:0x00429EE0, field:this:0x000044B0, source:raw]
    // GUARD: If command a2 is zero and FinishState at this + 0x4064 == 2, clear the AIControlFlag byte at this + 0x45F4 to 0. [field:this:0x00004064, field:this:0x000045F4, guard:1, source:raw]
    // LOOP: When the queue index is non-negative, scan the 8-byte entries of the buffer at this + 0x44A8 for an entry whose command id equals a2 (deduplication); if none found by the end of the queue, fall back to the append path. [field:this:0x000044A8, field:this:0x000044B0, source:raw]
    // ASSIGNMENT: When the queue is full (new index not below capacity), restore the queue index at this + 0x44B0 to its previous value (no append). [field:this:0x000044B0, source:raw]

    // Conservative worker pseudocode:
    //   void AICommandMessageQueueDispatcher(F1CVehicle* this, int32_t a2, int32_t a3) {
    //     switch (a2) {
    //       case 4: sub_4A46F0(this, 1, 1); break;
    //       case 5: *(uint8_t*)(this + 0x4548) = 0; sub_4A46F0(this, 0, 0); break;
    //       case 1: *(float*)(this + 0x413C) = (float)dbl_8AFEA0 + 2.0f; break;
    //       case 15: {
    //         bool cont = (dword_7C56A4 == 7) ? (*(uint32_t*)(*this + 0x4064) == 0) : (dword_7C56A8 != 8);
    //         if (cont) { if (*(uint8_t*)(this + 0x4410) == 0) SessionCleanupFlagClear(this); }
    //         else { SceneRenderUpdate(0); StateChangeNotify(0); }
    //         *(uint32_t*)(this + 0x4544) = 0;
    //         ParameterValueSetter(18);
    //         *(uint32_t*)(this + 0x4550) = 1;
    //         *(uint8_t*)(this + 0x4548) = 1;
    //         break;
    //       }
    //     }
    //     uint32_t* q = *(uint32_t**)(this + 0x44A8);
    //     if (q) {
    //       int32_t idx = *(int32_t*)(this + 0x44B0);
    //       if (idx < 0) {
    //         int32_t ni = idx + 1;
    //         if (ni < *(int32_t*)(this + 0x44AC)) {
    //           *(uint32_t*)(q + 2*ni) = a2;
    //           *(uint32_t*)((uint8_t*)q + 8*ni + 4) = a3;
    //           CommandQueueResponseHandler(this);
    //           *(int32_t*)(this + 0x44B0) = -1;
    //           if (!a2 && *(uint32_t*)(this + 0x4064) == 2) *(uint8_t*)(this + 0x45F4) = 0;
    //         } else { *(int32_t*)(this + 0x44B0) = idx; }
    //       } else {
    //         uint32_t* p = q; int32_t i = 0;
    //         while (*p != a2) { i++; p += 2; if (i > idx) goto append; }
    //       }
    //     }
    //   }
    // UNRESOLVED: Packet lists globals flt_59E800 (0x0059E800) and unk_7CE2F0 (0x007CE2F0) as read, but the raw source contains no use of either; likely compiler-folded or extracted from neighboring code.
    // UNRESOLVED: sub_4A46F0 callee semantics (state enable/disable) are not described in the packet; its two calls pass (this, 1, 1) and (this, 0, 0) respectively.
}
