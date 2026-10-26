// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496030
// Canonical corpus name: CarCrashDamageProcessing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CarCrashDamageProcessing_00496030.c

void UnknownObject::CarCrashDamageProcessing()
{
    // Advances the car crash damage animation. Early-returns unless the damage timer float at this+0xDC is positive and the damage data pointer at this+0x157C is non-null. On the first frame (timer equal to 0.01) it randomly picks an impact type and an impact origin (one of several screen-edge offsets written to this+0x1580/0x1584) using RandLCGRandomNumberGenerator, then zeroes cleanup fields this+0x18EC/0x18F0. Each call decrements the timer by FloatFieldAccessor (frame delta); when the timer expires the damage pointer and timer are cleared, otherwise the damage rects are rendered via sub_495DC0 with viewport data from InitViewportDimensions, SceneEntityCleanup runs on the argument, and ShortComputation_7250(1) is invoked. Returns 1 on a normal update.
    // GUARD: Return 0 when the damage timer float at this+0xDC is not positive (<= 0.0); this is the lifetime gate of the animation. [field:this:0x000000DC, source:raw]
    // GUARD: Read the damage data pointer v3 from this+0x157C; return 0 when it is null. [field:this:0x0000157C, source:raw]
    // ASSIGNMENT: v4 = *(v3 + 4) and v5 = *(v3 + 12); these two ints from the damage data struct act as screen-edge origin references for the direction pick. [field:*(this+0x157C):0x00000004, field:*(this+0x157C):0x0000000C, source:raw]
    // GUARD: First-frame path: when the DWORD at this+0xDC equals 1008981770 (float 0.01) the impact type and origin are randomized once. [guard:0, field:this:0x000000DC, source:raw]
    // STATE_TRANSITION: If the impact type at this+0x1578 is zero, seed it with RandLCGRandomNumberGenerator % 2 so each damage instance picks one of two impact families. [field:this:0x00001578, callee:0x005884ED, source:raw]
    // STATE_TRANSITION: Impact type 0: switch on RandLCGRandomNumberGenerator % 8 (dispatch via jump table global jpt_4960A2) writing eight distinct origin pairs to this+0x1580 (X) and this+0x1584 (Y), combining the 800/-800 X values and -600/600/v4/v5 Y values. [global:0x00496250, callee:0x005884ED, field:this:0x00001580, field:this:0x00001584, source:raw]
    // STATE_TRANSITION: Impact type 1: switch on RandLCGRandomNumberGenerator % 3 (dispatch via jump table global jpt_4960C3) selecting three sub-directions; v6==1 writes 600 to this+0x1584, v6==2 writes 800 to this+0x1580, otherwise v5 is kept as X, and the fall-through sets this+0x1584 to -600 before jumping to the shared cleanup label. [global:0x00496264, callee:0x005884ED, field:this:0x00001580, field:this:0x00001584, source:raw]
    // ASSIGNMENT: Shared cleanup label reached by impact types 1/2/3/4: zero the DWORD at this+0x18F0 and the byte at this+0x18EC. [field:this:0x000018F0, field:this:0x000018EC, source:raw]
    // CALCULATION: v8 = (float)this+0xDC - FloatFieldAccessor(this); write v8 back to this+0xDC, i.e. decrement the damage timer by the frame delta each call. [callee:0x00498730, field:this:0x000000DC, source:raw]
    // GUARD: If the subtraction raised the overflow flags (v10 | v11), the timer expired: clear the damage data pointer this+0x157C and the timer this+0xDC to 0; otherwise run the render path. [field:this:0x0000157C, field:this:0x000000DC, source:raw]
    // CALL: Render path: compute v14 = v8 * 100.0 using the float constants read from flt_59E440/flt_59E6F8, obtain the viewport via InitViewportDimensions(this), then call sub_495DC0(this, viewport, v14) to draw the impact damage rectangles. [global:0x0059E440, global:0x0059E6F8, callee:0x00498740, callee:0x00495DC0, source:raw]
    // CALL: SceneEntityCleanup(a2) runs on the function's second argument as part of the per-frame update. [callee:0x00497100, source:raw]
    // CALL: ShortComputation_7250(1) is invoked with constant 1 after the frame update. [callee:0x00497250, source:raw]
    // RETURN: Return 1 on the normal update path. Called by sub_496E90; the crash-damage display system drives this per-frame. [caller:0x00496E90, function:0x00496030, source:raw]

    // Conservative worker pseudocode:
    //   char sub_496030(CarCrashDamage* this, int a2) {
    //     if (this->timer <= 0.0) return 0;
    //     DamageData* d = this->damageData;
    //     if (!d) return 0;
    //     int edgeY = d->field4;
    //     int edgeX = d->field12;
    //     if (this->timer == 0.01f) {
    //       if (this->impactType == 0) this->impactType = RandLCGRandomNumberGenerator() % 2;
    //       switch (this->impactType) {
    //         case 0:
    //           switch (RandLCGRandomNumberGenerator() % 8) {
    //             case 0: this->originX = edgeX; this->originY = -600; break;
    //             case 1: this->originX = edgeX; this->originY = 600; break;
    //             case 2: this->originX = 800; this->originY = -600; break;
    //             case 3: this->originX = 800; this->originY = edgeY; break;
    //             case 4: this->originX = 800; this->originY = 600; break;
    //             case 5: this->originX = -800; this->originY = -600; break;
    //             case 6: this->originX = -800; this->originY = edgeY; break;
    //             default: this->originX = -800; this->originY = 600; break;
    //           } break;
    //         case 1:
    //           int r = RandLCGRandomNumberGenerator() % 3;
    //           if (r) { if (r == 2) this->originX = 800; this->originY = -600; }
    //           else { this->originX = edgeX; this->originY = -600; }
    //         case 2: case 3: case 4:
    //           this->cleanup2 = 0;
    //           this->cleanup1 = 0;
    //       }
    //     }
    //     float t = this->timer - FloatFieldAccessor(this);
    //     this->timer = t;
    //     if (overflow) { this->damageData = 0; this->timer = 0; }
    //     else { sub_495DC0(this, InitViewportDimensions(this), t * 100.0); SceneEntityCleanup(a2); }
    //     ShortComputation_7250(1);
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the two ints at v3+4 and v3+12 (screen-edge references) are inferred; their meaning inside the damage data struct is not proven.
    // UNRESOLVED: Exact literal values stored at float globals flt_59E440 and flt_59E6F8 (presumed 100.0 and related scale constants) are not read from this packet.
    // UNRESOLVED: Meaning of the cleanup fields this+0x18EC (byte) and this+0x18F0 (dword) is unknown.
    // UNRESOLVED: Purpose of the impact type 0 vs type 1 families and why type 1 skips the shared direction table is not established.
    // UNRESOLVED: Identity/role of SceneEntityCleanup's argument a2 is unresolved.
}
