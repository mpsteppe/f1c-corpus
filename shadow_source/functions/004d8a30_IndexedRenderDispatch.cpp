// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8A30
// Canonical corpus name: sub_4D8A30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D8A30_004d8a30.c

void UnknownObject::IndexedRenderDispatch()
{
    // Indexed render dispatch over a small 5-entry handle table. Switches on a1 in 0..5 (via jump table jpt_4D8A40); indices 1..5 each load a handle from the global table dword_8AD398/dword_8AD39C/dword_8AD3A0/dword_8AD3A4/flt_8AD3A8, and index 5 additionally renders a colored quad via QuadRenderWithColor(flt_8AD3A8). When the loaded handle and the render device global dword_8B8DC8 are both non-null, calls sub_553700 on the device. Returns 0 on the success/fall-through path, 1 for an out-of-range index.
    // CALCULATION: Switch on a1 (0..5), dispatched through the jump table jpt_4D8A40. [global:0x004D8A94, source:raw]
    // RETURN: Default case: an index outside 0..5 returns 1 immediately. [source:raw]
    // STATE_TRANSITION: Case 0: no handle is loaded; falls through to the shared completion path which checks only the render device. [source:raw]
    // ASSIGNMENT: Case 1: load the handle from global dword_8AD398. [global:0x008AD398]
    // ASSIGNMENT: Case 2: load the handle from global dword_8AD39C. [global:0x008AD39C]
    // ASSIGNMENT: Case 3: load the handle from global dword_8AD3A0. [global:0x008AD3A0]
    // ASSIGNMENT: Case 4: load the handle from global dword_8AD3A4. [global:0x008AD3A4]
    // ASSIGNMENT: Case 5: load the low dword of global flt_8AD3A8 as the handle. [global:0x008AD3A8]
    // CALL: Case 5 only: render a colored quad by calling QuadRenderWithColor(flt_8AD3A8). [global:0x008AD3A8, callee:0x004D90D0]
    // GUARD: Guard on the shared completion path: when the loaded handle v2 and the render device global dword_8B8DC8 are both non-null, call sub_553700 with the device. [global:0x008B8DC8, callee:0x00553700]
    // STATE_TRANSITION: Set the result to 0 on the completion path (success or no-op when a guard fails). [source:raw]
    // RETURN: Return 0 on the completion path (indices 0..5), 1 on the default out-of-range path. [source:raw]

    // Conservative worker pseudocode:
    //   int IndexedRenderDispatch(int index) {
    //     int result = 1;
    //     switch (index) {
    //       case 0: result = 0; break;
    //       case 1: v2 = dword_8AD398; goto render;
    //       case 2: v2 = dword_8AD39C; goto render;
    //       case 3: v2 = dword_8AD3A0; goto render;
    //       case 4: v2 = dword_8AD3A4; goto render;
    //       case 5: v2 = LODWORD(flt_8AD3A8); QuadRenderWithColor(flt_8AD3A8); goto render;
    //       render:
    //         if (v2 && dword_8B8DC8) { sub_553700(dword_8B8DC8); result = 0; }
    //         break;
    //       default: return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner and caller context: the function is called by sub_4D7FE0; the relationship between a1 and the render operation is not evidenced in this packet.
    // UNRESOLVED: The five global handles (dword_8AD398..flt_8AD3A8) are presumed to be one contiguous table, but only the individual reads are evidenced here.
    // UNRESOLVED: flt_8AD3A8 doubles as both a handle (low dword) and the color argument to QuadRenderWithColor; its float interpretation is unresolved.
    // UNRESOLVED: sub_553700's contract (what render operation it performs with the handle) is not established by this packet.
}
