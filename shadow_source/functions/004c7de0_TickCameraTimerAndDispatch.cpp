// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7DE0
// Canonical corpus name: sub_4C7DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C7DE0_004c7de0.c

void UnknownObject::TickCameraTimerAndDispatch()
{
    // Render-tick routine called from RenderTickUpdate (0x004C8B70). Only runs when the list head pointer at this+0xC is nonzero. Decrements a timer at this+0x4 by a double global dbl_8AFE98; when it goes negative it calls UpdateCameraFOV(0.4), adds 0.4 back to the timer, and clamps it to 0 if still negative. When dword_8AC4C4 is set, issues an indirect vtable call (slot 40) on it, then iterates a linked list: resets the cursor at (list+8) to the head node, and while the current node is nonzero repeatedly calls sub_4C8FC0 and advances the cursor to the next node via the node's +4 pointer field.
    // GUARD: Guard: proceed only when the list head pointer at this+0xC is nonzero. [guard:0, field:this:0x0000000C, field:*(this+0xC):0x00000000, source:raw]
    // CALCULATION: v2 = *(float*)(this+4) - dbl_8AFE98; write v2 back to this+0x4 (timer decrement by the double global). [field:this:0x00000004, global:0x008AFE98, source:raw]
    // GUARD: Guard: when the decremented timer v2 is below 0.0. [field:this:0x00000004, source:raw]
    // CALL: UpdateCameraFOV(0.4) resets/interpolates the camera field of view on timer expiry. [callee:0x004C7F30, source:raw]
    // CALCULATION: v3 = *(float*)(this+4) + 0.4; write v3 back to this+0x4. [field:this:0x00000004, source:raw]
    // GUARD: Guard: when v3 is still below 0.0, clamp. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clamp the timer: write 0 to this+0x4. [field:this:0x00000004, source:raw]
    // GUARD: Guard: proceed to dispatch only when the global dword_8AC4C4 is nonzero. [global:0x008AC4C4, source:raw]
    // CALL: Indirect vtable call at slot 40 on dword_8AC4C4 with arguments (0, 0, 0). [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Reset the list cursor: v4 = *(dword*)(this+0xC); *(dword*)(v4+8) = *(dword*)v4 (cursor at list+8 set to the head node). [field:*(this+0xC):0x00000000, field:*(this+0xC):0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: Guard: iterate only when the current node pointer (first field of the list) is nonzero. [field:*(*(this+0xC)+0x0):0x00000000, field:*(this+0xC):0x00000000, source:raw]
    // LOOP: Loop over list nodes: call sub_4C8FC0(), re-read the cursor at list+8, and when the current node is nonzero advance it to the node's +4 pointer (next); repeat while the cursor and the node's first field are nonzero. [callee:0x004C8FC0, field:*(this+0xC):0x00000008, field:*(*(this+0xC)+0x8):0x00000004, field:*(*(this+0xC)+0x8):0x00000000, source:raw]
    // RETURN: Return with no value after the guard chain completes. [function:0x004C7DE0, source:raw]
    // CALL: Invoked by RenderTickUpdate (0x004C8B70) as part of the render tick. [caller:0x004C8B70]

    // Conservative worker pseudocode:
    //   void TickCameraTimerAndDispatch(int this) {
    //     if (!*(dword*)(this + 12)) return;
    //     double v2 = *(float*)(this + 4) - dbl_8AFE98;
    //     *(float*)(this + 4) = v2;
    //     if (v2 < 0.0) {
    //       UpdateCameraFOV(0.4f);
    //       double v3 = *(float*)(this + 4) + 0.4f;
    //       *(float*)(this + 4) = v3;
    //       if (v3 < 0.0) *(dword*)(this + 4) = 0;
    //     }
    //     if (dword_8AC4C4) {
    //       (*(void (**)(int, dword, dword, dword))(*(dword*)dword_8AC4C4 + 40))(dword_8AC4C4, 0, 0, 0);
    //       int v4 = *(dword*)(this + 12);
    //       _DWORD* v5 = *(_DWORD**)v4;
    //       *(dword*)(v4 + 8) = *(dword*)v4;
    //       if (v5 && *v5) {
    //         do {
    //           sub_4C8FC0();
    //           int v7 = *(dword*)(this + 12);
    //           int v8 = *(dword*)(v7 + 8);
    //           if (v8) *(dword*)(v7 + 8) = *(dword*)(v8 + 4);
    //           _DWORD* v9 = *(_DWORD**)(v7 + 8);
    //         } while (v9 && *v9);
    //       }
    //     }
    //   }
    // UNRESOLVED: Globals flt_59E440 (0x0059E440) and flt_59E8C8 (0x0059E8C8) are listed in the packet but do not appear in the raw source text; their roles here are unknown.
    // UNRESOLVED: The meaning of the dbl_8AFE98 decrement, the 0.4 camera-FOV step, and the indirect vtable slot-40 call on dword_8AC4C4 are observed but not semantically established.
    // UNRESOLVED: The list node +0/+4 layout and the purpose of sub_4C8FC0 per-node work are inferred as an iteration only.
}
