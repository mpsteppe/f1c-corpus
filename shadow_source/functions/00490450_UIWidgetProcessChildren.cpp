// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490450
// Canonical corpus name: UIWidgetProcessChildren
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetProcessChildren_00490450.c

void UnknownObject::UIWidgetProcessChildren()
{
    // Processes child widgets of a UI widget: reads the input/cursor position pair via DualFieldRead, dispatches on the state returned by ShortComputation_6720 through the jump table at 0x00490538. For states 0-2 it dispatches vtable+64 with argument 0 and runs VTableDispatchListIteration. For states 3-5 it also dispatches vtable+64 with argument 0, then, if the child count at this+0xEC is positive, walks the child linked list from the head at this+0xE0 following next pointers at node+4, and for the child whose rectangle contains the input position dispatches vtable+64 with argument 4 (hit notification). The default path and the end of iteration dispatch VTableDispatchListIteration and return 0.
    // ASSIGNMENT: Initialize the two stack locals v8 and v7 to 0 before reading the input position. [source:raw]
    // CALL: Call DualFieldRead(&v8, &v7) to read the input/cursor position pair used for the bounds test. [callee:0x00498880, source:raw]
    // CALL: Call ShortComputation_6720(this) to obtain the state value that selects the switch case. [callee:0x00486720, source:raw]
    // CALCULATION: Switch dispatch over the computed state via the jump table jpt_490489 at global 0x00490538, with cases 0-5 handled explicitly and everything else falling to the default path. [global:0x00490538, source:raw]
    // CALL: For cases 0-2: dispatch vtable entry at obj+0x40 (vtable+64) with argument 0. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: For cases 0-2: call VTableDispatchListIteration(this) and return 0. [callee:0x00490660, source:raw]
    // CALL: For cases 3-5: dispatch vtable entry at obj+0x40 (vtable+64) with argument 0 before iterating children. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // GUARD: Guard: when the child count at this+0xEC is less than or equal to 0 the child iteration is skipped and control jumps to the default path. [guard:0, field:this:0x000000EC, source:raw]
    // LOOP: Iterate child index v3 from 0 up to the child count at this+0xEC, continuing while v3 stays within [0, count). [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Load v5 = this[56], the head of the child widget linked list at offset this+0xE0. [field:this:0x000000E0, source:raw]
    // LOOP: Walk the child linked list by following the next pointer at node+4 (base *(this+0xE4), offset 0x4) until the indexed child is reached. [field:*(this+0xE4):0x00000004, source:raw]
    // GUARD: Guard: the selected child node pointer v6 must be non-null before the rectangle test runs. [field:this:0x000000E0, source:raw]
    // CALL: Call RectangleBoundsCheck(v6, v8, v7) to test whether the input position falls within the child's bounding rectangle. [callee:0x0048EA60, source:raw]
    // CALL: On a rectangle hit: dispatch vtable entry at obj+0x40 (vtable+64) with argument 4 as the child hit notification, then jump to the default path. [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // RETURN: Return 0 from the case 0-2 path, the default path, and the end of child iteration. [source:raw]

    // Conservative worker pseudocode:
    //   int UIWidgetProcessChildren(int *this) {
    //     int v8 = 0, v7 = 0;
    //     DualFieldRead(&v8, &v7);
    //     switch (ShortComputation_6720(this)) {
    //       case 0: case 1: case 2:
    //         vtable(this)[16](this, 0);
    //         VTableDispatchListIteration(this);
    //         return 0;
    //       case 3: case 4: case 5:
    //         vtable(this)[16](this, 0);
    //         for (int i = 0; i < this[59]; ++i) {
    //           int node = this[56];
    //           for (int k = i; node && k > 0; --k) node = *(int*)(node + 4);
    //           if (node && *(void**)node && RectangleBoundsCheck(*(void**)node, v8, v7)) {
    //             vtable(this)[16](this, 4);
    //             break;
    //           }
    //         }
    //         break;
    //       default:
    //         VTableDispatchListIteration(this);
    //         return 0;
    //     }
    //     VTableDispatchListIteration(this);
    //     return 0;
    //   }
    // UNRESOLVED: Vtable entry 16 (offset obj+0x40) is dispatched with argument 0 for the non-hit paths and argument 4 for the hit notification; the concrete target and its semantics live outside this function.
    // UNRESOLVED: RectangleBoundsCheck consumes the DualFieldRead output; the exact meaning of the two position fields is established by that callee.
}
