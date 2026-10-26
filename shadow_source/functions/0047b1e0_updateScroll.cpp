// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047B1E0
// Canonical corpus name: UIComponentScrollUpdate
// Owner: UIComponentScroll [DERIVED]
// Raw source: functions/UIComponentScrollUpdate_0047b1e0.c

void UIComponentScroll::updateScroll()
{
    // Per-frame update of a scrollable UI component. Invokes a vtable update first, reads current selection/scroll references from the dual-field object at this+0x40, advances a float accumulator (this+0x108), then dispatches scroll behavior on the scroll state (this+0x104): recompute item layout and move a bounded counter (state 1), step the counter (states 2/3), clamp and apply a scroll delta (state 4), or step-scroll via sub_47BB40 (state 5). Always ends by invoking a vtable refresh and returning its result.
    // CALL: Invokes vtable slot +44 (initial update) on the object with argument 1 [field:obj:0x0000002C, field:this:0x00000000]
    // CALL: DualFieldRead reads two values from the object pointed at by this+0x40 into locals v11 and v10 (selection index and layout reference) [callee:0x00498880, field:this:0x00000040]
    // ASSIGNMENT: Float accumulator this+0x108 becomes FloatFieldAccessor(this+0x40 object) + this+0x108 (accumulates per-frame advance) [callee:0x00498730, field:this:0x00000040, field:this:0x00000108]
    // STATE_TRANSITION: Switch on scroll state this+0x104 over cases 1..5 plus default, dispatched through jump table at 0x0047B3C0 [field:this:0x00000104, global:0x0047B3C0]
    // CALL: State 1: MenuItemLayoutCalculator(this, v11, v10) recomputes item layout; result stored to this+0xE4 [callee:0x0047B850, field:this:0x000000E4]
    // CALCULATION: State 1: while accumulator this+0x108 > 0.125, decrement it by 0.125; decrement the bounded counter via BoundedCounterUpdate(this, -1) when v10 <= this+0xFC + this+0x4, and increment it via BoundedCounterUpdate(this, 1) when v10 >= this+0x8 - this+0xFC [field:this:0x00000108, field:this:0x000000FC, field:this:0x00000004, field:this:0x00000008, callee:0x0047BAE0]
    // CALCULATION: State 2: if accumulator > 0.125, decrement this+0x108 by 0.125 and BoundedCounterUpdate(this, -1) [field:this:0x00000108, callee:0x0047BAE0]
    // CALCULATION: State 3: if accumulator > 0.125, decrement this+0x108 by 0.125 and BoundedCounterUpdate(this, 1) [field:this:0x00000108, callee:0x0047BAE0]
    // ASSIGNMENT: State 4: scroll delta this+0x110 = v10 - this+0x11C, clamped to the range [0, this+0x114] [field:this:0x00000110, field:this:0x00000114, field:this:0x0000011C]
    // CALL: State 4: sub_47BE00(this) applies the bounded scroll delta to the component [callee:0x0047BE00]
    // CALCULATION: State 5: if accumulator > 0.25, decrement this+0x108 by 0.25 and sub_47BB40(this, v10) performs a step scroll [field:this:0x00000108, callee:0x0047BB40]
    // CALL: All paths converge on vtable slot +84 (final update/refresh) invoked on the object [field:obj:0x00000054, field:this:0x00000000]
    // RETURN: Returns the result of the final vtable refresh call [function:0x0047B1E0]

    // Conservative worker pseudocode:
    //   vtable[+44](this, 1);
    //   DualFieldRead(*(this + 0x40), &v11, &v10);
    //   acc = FloatFieldAccessor(*(this + 0x40)) + this->f108;
    //   this->f108 = acc;
    //   switch (this->i104) {
    //     case 1:
    //       this->iE4 = MenuItemLayoutCalculator(this, v11, v10);
    //       if (this->f108 > 0.125) {
    //         this->f108 -= 0.125;
    //         if (v10 <= this->iFC + this->i4) BoundedCounterUpdate(this, -1);
    //         if (v10 >= this->i8 - this->iFC) BoundedCounterUpdate(this, 1);
    //       }
    //       break;
    //     case 2: if (acc > 0.125) { this->f108 = acc - 0.125; BoundedCounterUpdate(this, -1); } break;
    //     case 3: if (acc > 0.125) { this->f108 = acc - 0.125; BoundedCounterUpdate(this, 1); } break;
    //     case 4:
    //       this->i110 = v10 - this->i11C;
    //       this->i110 = this->i110 < 0 ? 0 : (this->i110 > this->i114 ? this->i114 : this->i110);
    //       sub_47BE00(this);
    //       break;
    //     case 5: if (acc > 0.25) { this->f108 = acc - 0.25; sub_47BB40(this, v10); } break;
    //   }
    //   return vtable[+84](this);
    // UNRESOLVED: Read-only globals flt_59E4E0 and flt_59E7F8 are listed but do not appear in the raw source; they may back the 0.125/0.25 accumulator decrement constants but that association is not verifiable from this packet
    // UNRESOLVED: Scroll state enumeration at this+0x104 (values 1..5) is mapped from switch cases only; the meaning of each state is not independently confirmed
    // UNRESOLVED: Exact base class owning the vtable +44/+84 slots is not identified
}
