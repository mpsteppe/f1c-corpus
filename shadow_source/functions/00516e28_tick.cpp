// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516E28
// Canonical corpus name: UIControlStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIControlStateMachine_00516e28.c

void UnknownObject::tick()
{
    // Per-tick update of a UI control state machine. Loads a state-machine context from this+0x17C. If the transition-trigger flag at context+0x8 is set, consumes it (write 0) and dispatches three vtable calls in order: main-logic (this+0x1A4) with 0, state-transition (this+0x188) with 2, action (this+0x180) with 2, skipping the input logic. Otherwise, if the activation gate (this+0x4A) is set and the counter at this+0x74 is zero, selects the main-logic vtable pointer (this+0x1A4): from context+0x18 when button (this+0x50) and hold (this+0x5A) conditions are both set (also setting the transition flag to 1), from context+0x14 when the single-button condition (this+0x58) is set, or falls back to writing 45 into the base object at obj+0x14 and calling base vtable[0]. Then dispatches pre-update (this+0x198), update/render (this+0x184 vtable slot 2), and, unless bypassed (this+0x41), the conditional (this+0x1A0 when context+0x10 is clear), post-input (this+0x19C), main-logic (this+0x1A4 with context+0x8), state-transition (this+0x188 with 3 or 0) and action (this+0x180 with 0) dispatches. Finally updates a child control (this+0x8): copies context+0xC into child+0xC and writes context+0xC plus a flag-derived increment into child+0x10, then, when this+0x40 is set and the byte at sub-object (this+0x18C)+0x11 is clear, increments child+0x10 again by (this+0x5A != 0) + 1.
    // CALCULATION: Load state-machine context pointer v1 from this+0x17C. [field:this:0x0000017C]
    // GUARD: Transition branch: if the transition-trigger flag byte at context+0x8 is non-zero, take the consume-transition path. [guard:0, field:*(this+0x17C):0x00000008]
    // ASSIGNMENT: Consume the transition: clear the flag byte at context+0x8 to 0. [field:*(this+0x17C):0x00000008]
    // CALL: Dispatch main-logic vtable at this+0x1A4, slot index 0, with (a1, 0). [field:this:0x000001A4, field:*(this+0x1A4):0x00000000]
    // CALL: Dispatch state-transition vtable at this+0x188, slot index 0, with (a1, 2). [field:this:0x00000188, field:*(this+0x188):0x00000000]
    // CALL: Dispatch action vtable at this+0x180, slot index 0, with (a1, 2). [field:this:0x00000180, field:*(this+0x180):0x00000000]
    // GUARD: Normal path activation gate: activation flag this+0x4A non-zero AND counter at this+0x74 zero. [field:this:0x0000004A, field:this:0x00000074]
    // GUARD: Button-and-hold path: button condition this+0x50 non-zero AND hold condition this+0x5A non-zero. [guard:1, field:this:0x00000050, field:this:0x0000005A]
    // ASSIGNMENT: Select main-logic vtable pointer: this+0x1A4 = value at context+0x18. [field:this:0x000001A4, field:*(this+0x17C):0x00000018]
    // ASSIGNMENT: Set transition-trigger flag byte at context+0x8 to 1. [field:*(this+0x17C):0x00000008]
    // GUARD: Single-button path: condition this+0x58 non-zero (only reached when the button-and-hold guard failed). [field:this:0x00000058]
    // ASSIGNMENT: Select main-logic vtable pointer: this+0x1A4 = value at context+0x14. [field:this:0x000001A4, field:*(this+0x17C):0x00000014]
    // ASSIGNMENT: Fallback path: write action code 45 into the base object at obj+0x14, where obj is the vtable pointer read from this+0x0. [field:obj:0x00000014, field:this:0x00000000]
    // CALL: Fallback path: call base-object vtable[0] (obj+0x0) with (a1). [field:obj:0x00000000, field:this:0x00000000]
    // CALL: Dispatch pre-update vtable at this+0x198, slot index 0, with (a1). [field:this:0x00000198, field:*(this+0x198):0x00000000]
    // CALL: Dispatch update/render vtable at this+0x184, slot index 2 (function pointer at +8 within the vtable), with (a1). [field:this:0x00000184, field:*(this+0x184):0x00000008]
    // GUARD: Bypass gate: only run the following dispatches when the byte this+0x41 is zero. [field:this:0x00000041]
    // GUARD: Conditional dispatch gate: only when the byte at context+0x10 is zero. [field:*(this+0x17C):0x00000010]
    // CALL: Dispatch conditional vtable at this+0x1A0, slot index 0, with (a1). [field:this:0x000001A0, field:*(this+0x1A0):0x00000000]
    // CALL: Dispatch post-input vtable at this+0x19C, slot index 0, with (a1). [field:this:0x0000019C, field:*(this+0x19C):0x00000000]
    // GUARD: Main-logic dispatch gate: only when activation flag this+0x4A is non-zero. [field:this:0x0000004A]
    // CALL: Dispatch main-logic vtable at this+0x1A4, slot index 0, with (a1, byte at context+0x8). [field:this:0x000001A4, field:*(this+0x1A4):0x00000000, field:*(this+0x17C):0x00000008]
    // CALL: Dispatch state-transition vtable at this+0x188 with (a1, 3 if context+0x8 non-zero else 0). [field:this:0x00000188, field:*(this+0x17C):0x00000008]
    // CALL: Dispatch action vtable at this+0x180 with (a1, 0). [field:this:0x00000180]
    // CALCULATION: Load child-control pointer from this+0x8. [field:this:0x00000008]
    // GUARD: Child-control update path: only when the pointer at this+0x8 is non-null. [field:this:0x00000008]
    // ASSIGNMENT: Copy state-machine data into child width field: child+0xC = value at context+0xC. [field:*(this+0x8):0x0000000C, field:*(this+0x17C):0x0000000C]
    // CALCULATION: Compute child offset value = value at context+0xC + (context+0x8 byte non-zero ? 1 : 0) + 1. [field:*(this+0x17C):0x0000000C, field:*(this+0x17C):0x00000008]
    // ASSIGNMENT: Write computed value into child offset field child+0x10. [field:*(this+0x8):0x00000010]
    // GUARD: Secondary offset adjustment gate: only when byte this+0x40 is non-zero. [field:this:0x00000040]
    // CALCULATION: Load sub-object pointer from this+0x18C. [field:this:0x0000018C]
    // GUARD: Secondary adjustment gate on the dereferenced sub-object: only when the byte at offset 0x11 is zero. Packet labels the read base as *(this+0x8) (see unresolved). [field:*(this+0x8):0x00000011]
    // CALCULATION: Increment child offset: child+0x10 += (this+0x5A byte non-zero ? 1 : 0) + 1. [field:*(this+0x8):0x00000010, field:this:0x0000005A]
    // RETURN: Return result (the final scratch value; the child pointer when the child path ran, otherwise the child pointer read at this+0x8 or the computed offset value). [function:0x00516E28]

    // Conservative worker pseudocode:
    //   stateContext = *(void**)&a1[0x17C];
    //   if (stateContext->byte0x8 != 0)
    //   {
    //       stateContext->byte0x8 = 0;
    //       mainLogicDispatch(a1, 0);    // *(this+0x1A4) vtable[0]
    //       stateTransitionDispatch(a1, 2); // *(this+0x188) vtable[0]
    //       actionDispatch(a1, 2);       // *(this+0x180) vtable[0]
    //   }
    //   else
    //   {
    //       if (this->byte0x4A != 0 && this->dword0x74 == 0)
    //       {
    //           if (this->byte0x50 != 0 && this->byte0x5A != 0)
    //           {
    //               *(void**)&a1[0x1A4] = *(void**)(stateContext + 0x18);
    //               stateContext->byte0x8 = 1;
    //           }
    //           else if (this->byte0x58 != 0)
    //           {
    //               *(void**)&a1[0x1A4] = *(void**)(stateContext + 0x14);
    //           }
    //           else
    //           {
    //               *(int*)(*(void**)a1 + 0x14) = 45;
    //               baseObjectVtable0(a1); // **(void***)a1
    //           }
    //       }
    //       preUpdateDispatch(a1);       // *(this+0x198) vtable[0]
    //       updateRenderDispatch(a1);    // *(this+0x184) vtable[2]
    //       if (this->byte0x41 == 0)
    //       {
    //           if (stateContext->byte0x10 == 0)
    //               conditionalDispatch(a1); // *(this+0x1A0) vtable[0]
    //           postInputDispatch(a1);   // *(this+0x19C) vtable[0]
    //           if (this->byte0x4A != 0)
    //               mainLogicDispatch(a1, stateContext->byte0x8);
    //           stateTransitionDispatch(a1, stateContext->byte0x8 != 0 ? 3 : 0);
    //           actionDispatch(a1, 0);
    //       }
    //   }
    //   child = *(void**)&a1[0x8];
    //   if (child != 0)
    //   {
    //       child->dword0xC = *(int*)(stateContext + 0xC);
    //       child->dword0x10 = *(int*)(stateContext + 0xC) + (stateContext->byte0x8 != 0) + 1;
    //       if (this->byte0x40 != 0)
    //       {
    //           sub = *(void**)&a1[0x18C];
    //           if (*(unsigned char*)(sub + 0x11) == 0)
    //               child->dword0x10 += (this->byte0x5A != 0) + 1;
    //       }
    //   }
    //   return child;
    // UNRESOLVED: Identity and semantics of the seven vtable-dispatched functions (pointers at this+0x180, this+0x184 slot 2, this+0x188, this+0x198, this+0x19C, this+0x1A0, this+0x1A4) are not statically resolvable from this packet; they are dispatched through control-owned vtables.
    // UNRESOLVED: Semantic meaning of the state-machine context fields at *(this+0x17C)+0x8/0xC/0x10/0x14/0x18 (transition flag, data, condition, two state/vtable indices).
    // UNRESOLVED: Byte-gate read at offset 0x11: the raw source dereferences it through the sub-object loaded from this+0x18C, but the packet labels the field base as *(this+0x8). Referenced as field:*(this+0x8):0x00000011 per packet naming.
    // UNRESOLVED: Semantic meaning of control flags this+0x40, this+0x41, this+0x4A, this+0x50, this+0x58, this+0x5A, this+0x74.
    // UNRESOLVED: No static callers recorded; call frequency and frame path unknown.
    // UNRESOLVED: Meaning of the return value to any caller is unknown.
}
