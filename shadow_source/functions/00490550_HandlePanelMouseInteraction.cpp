// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490550
// Canonical corpus name: PanelMouseInteractionHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PanelMouseInteractionHandler_00490550.c

void UnknownObject::HandlePanelMouseInteraction()
{
    // Panel mouse/input interaction handler (thiscall). Computes a state selector, and for state groups 3-5 reads the input position, runs a vtable hit-test at this+48, then on a miss dispatches this+64 with argument 0, walks the child widget linked list (head this+0xE0, next node+4), and on the first bounding-rect hit dispatches this+64 with argument 4 and stops. Always runs the child dispatch-list iteration at the end and returns 0.
    // CALL: Compute v2 = ShortComputation_6720(this), the state/computation selector that decides whether mouse interaction is processed. [callee:0x00486720, field:this:0x00000000, source:raw]
    // GUARD: Process the interaction block only when v2 is in the range 3 to 5; for other states the whole block is skipped. [source:raw]
    // ASSIGNMENT: Zero the local position pair before reading input: v9 = 0 and v8 = 0. [source:raw]
    // CALL: DualFieldRead(&v9, &v8) reads the input/cursor position into the two locals. [callee:0x00498880, source:raw]
    // GUARD: Call the vtable hit-test at this+48 with (v9, v8); when it returns non-zero (interaction already handled) skip the child dispatch loop. [field:obj:0x00000030, source:raw]
    // CALL: Dispatch the vtable method at this+64 with argument 0 to open the child traversal. [field:obj:0x00000040, source:raw]
    // LOOP: Iterate i from 0 up to this[59] (child count at this+0xEC), walking the child widget linked list whose head is this+0xE0. [field:this:0x000000EC, field:this:0x000000E0, source:raw]
    // CALCULATION: Advance through the child linked list: current node from head this+0xE0, move to the next node via the pointer at node+4 (dereferenced as *(this+0xE4):0x4), and read each node's content pointer v6 from the node. [field:this:0x000000E0, field:*(this+0xE4):0x00000004, source:raw]
    // CALL: Test the child node content against the input position with RectangleBoundsCheck(v6, v9, v8). [callee:0x0048EA60, source:raw]
    // CALL: On the first bounding-rect hit, dispatch the vtable method at this+64 with argument 4 and break out of the loop. [field:obj:0x00000040, source:raw]
    // CALL: After the interaction block, always run VTableDispatchListIteration(this) over the child dispatch list. [callee:0x00490660, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int HandlePanelMouseInteraction(void *this) {
    //     int v2 = ShortComputation_6720(this);
    //     if (v2 >= 3 && v2 <= 5) {
    //       int v9 = 0, v8 = 0;
    //       DualFieldRead(&v9, &v8);
    //       if (!hitTest_vtbl48(this, v9, v8)) {
    //         dispatch_vtbl64(this, 0);
    //         for (i = 0; i < childCount_0xEC; ++i) {
    //           walk child list from head_0xE0 via next at node+4;
    //           if (child && RectangleBoundsCheck(child, v9, v8)) { dispatch_vtbl64(this, 4); break; }
    //         }
    //       }
    //     }
    //     VTableDispatchListIteration(this);
    //     return 0;
    //   }
    // UNRESOLVED: Owner object type is not established; the panel/UI container that owns this handler is UnknownObject.
    // UNRESOLVED: The vtable methods at this+48 (hit-test) and this+64 (dispatch) have no resolved callee addresses.
    // UNRESOLVED: The state values 3-5 and the dispatch arguments 0 and 4 are not interpreted by this function.
}
