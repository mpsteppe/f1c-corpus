// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004900A0
// Canonical corpus name: sub_4900A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4900A0_004900a0.c

void UnknownObject::sub_4900A0()
{
    // Reads a cursor/input position (two fields) via DualFieldRead into locals v8/v9. Computes bounding-region boundaries with sub_487060 (mode 0 and 1) and sub_4870E0 (mode 0 and 1). If the input position lies strictly inside the region (v8 between both v2/v3 and v9 between both v4/v10), toggles the state flag at this[0xE0] (0->1, 1->0, 2 unchanged, other values reset to 1); when outside the region the flag is set to 1. Then dispatches the state via the vtable+0x40 method and runs the vtable+0x98 method, returning 0.
    // ASSIGNMENT: Initialize the two input locals v8 and v9 to zero before DualFieldRead writes them. [source:raw]
    // CALL: Call sub_487060(this, 0) and sub_487060(this, 1) to obtain the two horizontal bounding boundaries v2 and v3. [callee:0x00487060, source:raw]
    // CALL: Call sub_4870E0(this, 0) and sub_4870E0(this, 1) to obtain the two vertical bounding boundaries v4 and v10. [callee:0x004870E0, source:raw]
    // CALL: Call DualFieldRead(&v8, &v9) to read the two cursor/input position fields into the locals. [callee:0x00498880, source:raw]
    // GUARD: Enter the toggle branch only when v8 is strictly between v2 and v3 and v9 is strictly between v4 and v10 (input inside the bounding region). [callee:0x00487060, callee:0x004870E0, callee:0x00498880, source:raw]
    // STATE_TRANSITION: Toggle the state flag this[56] (0xE0) on a hit: 0 -> 1, 1 -> 0, 2 stays 2, any other value resets to 1. When the input is outside the region the flag is set to 1. [field:this:0x000000E0, source:raw]
    // CALL: Read the vtable pointer from this and dispatch the updated state this[56] through the vtable+0x40 method (this, this[56]). [field:this:0x00000000, field:obj:0x00000040, field:this:0x000000E0, source:raw]
    // CALL: Read the vtable pointer from this and invoke the vtable+0x98 method on this as a post-dispatch step. [field:this:0x00000000, field:obj:0x00000098, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   x = 0; y = 0;
    //   left = sub_487060(this, 0);
    //   right = sub_487060(this, 1);
    //   top = sub_4870E0(this, 0);
    //   bottom = sub_4870E0(this, 1);
    //   DualFieldRead(&x, &y);
    //   if (x > left && x < right && y > top && y < bottom) {
    //       switch (state) {
    //           case 0: state = 1; break;
    //           case 1: state = 0; break;
    //           case 2: state = 2; break;
    //           default: state = 1; break;
    //       }
    //   } else {
    //       state = 1;
    //   }
    //   vtbl[16](this, state);
    //   vtbl[38](this);
    //   return 0;
    // UNRESOLVED: The meaning of the sub_487060 / sub_4870E0 boundaries and the DualFieldRead input coordinate space are not established by the packet.
    // UNRESOLVED: The vtable+0x40 and vtable+0x98 dispatch targets and their purposes are unknown.
}
