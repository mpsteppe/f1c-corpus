// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D850
// Canonical corpus name: UIScrollAreaAutoScrollManager
// Owner: UIScrollAreaAutoScrollManager [DERIVED]
// Raw source: functions/UIScrollAreaAutoScrollManager_0048d850.c

void UIScrollAreaAutoScrollManager::ScrollAutoScrollManager()
{
    // Per-frame update of a UI scroll area's auto-scroll behavior. Reads the current scroll state enum via ShortComputation_6720 and the cursor position via DualFieldRead, then dispatches a scroll command through the vtable scroll-command slot based on which region of the scroll area the cursor occupies. Up-scroll states (0/6/7) and down-scroll states (3/8/9) use opposing threshold sets. States 4 and 5 drive an auto-scroll counter (decrement / conditional increment against the scroll area size), and every path ends by invoking the vtable refresh slot.
    // CALL: Read the current scroll state enum with ShortComputation_6720(this). [source:raw, callee:0x00486720]
    // CALL: Read the cursor position with DualFieldRead into a two-field result. [source:raw, callee:0x00498880]
    // STATE_TRANSITION: Dispatch on the scroll state via the switch jump table and its index data. [source:raw, global:0x0048D9B8, global:0x0048D9C4]
    // GUARD: Up-scroll region (states 0/6/7): when the cursor is above the upper threshold this[67] the region is retested against this[66]; when inside the top band it issues the scroll-up command (6) via the vtable scroll-command slot, otherwise issues scroll-stop (0) when outside the active band, else scroll-up-fast (7). [source:raw, field:obj:0x00000040, field:this:0x00000000, field:this:0x00000108, field:this:0x0000010C, field:this:0x00000110, field:this:0x0000011C, field:this:0x00000120]
    // GUARD: Down-scroll region (states 3/8/9): when the cursor is above the upper threshold this[67] the same threshold test runs; inside the band it issues scroll-down (8), otherwise scroll-stop (3) when outside, else scroll-down-fast (9), using the inner-top this[70], inner-bottom this[71] and outer limit this[72]. [source:raw, field:obj:0x00000040, field:this:0x00000000, field:this:0x0000010C, field:this:0x00000110, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120]
    // STATE_TRANSITION: Auto-scroll counter (state 4): decrement the counter this[64] while it is still positive. [source:raw, field:this:0x00000100]
    // STATE_TRANSITION: Auto-scroll counter (state 5): compute scroll geometry via ShortComputation_adb0 on this[50] plus 108, and while the counter this[64] is below the scroll area size this[62] minus the geometry term, increment the counter and invoke the vtable refresh slot. [source:raw, callee:0x0049ADB0, field:this:0x000000C8, field:this:0x000000F8, field:this:0x00000100, field:obj:0x000000A8]
    // RETURN: Terminate every handled path by invoking the vtable refresh slot and returning 0. [source:raw, field:obj:0x000000A8]

    // Conservative worker pseudocode:
    //   int ScrollAutoScrollManager(_DWORD* this) {
    //     int state = ShortComputation_6720(this);
    //     int x, y; DualFieldRead(&x, &y);
    //     switch (state) {
    //       case 0: case 6: case 7:
    //         if (x > this[67]) {
    //           if (x < this[66] && y > this[71] && y < this[72]) { setCmd(this, 6); goto done; }
    //           if (x <= this[66] || x >= this[68] || y <= this[71] || y >= this[72]) setCmd(this, 0);
    //           else setCmd(this, 7);
    //         }
    //         goto done;
    //       case 3: case 8: case 9:
    //         if (x > this[67]) {
    //           if (x < this[68] && y > this[71] && y < this[70]) { setCmd(this, 8); goto done; }
    //           if (x <= this[67] || x >= this[68] || y <= this[70] || y >= this[72]) setCmd(this, 3);
    //           else setCmd(this, 9);
    //         }
    //         goto done;
    //       default: goto done;
    //     }
    //   done:
    //     if (state == 4 && this[64] > 0) --this[64];
    //     else if (state == 5) {
    //       int g = ShortComputation_adb0(this[50] + 108);
    //       if (this[64] < this[62] - (g - 4)) { ++this[64]; refresh(this); return 0; }
    //     }
    //     refresh(this);
    //     return 0;
    //   }
    // UNRESOLVED: The numeric scroll command values (0/3/6/7/8/9) encode scroll direction and speed but their exact visual effect is unverified.
    // UNRESOLVED: The geometry term produced by ShortComputation_adb0(this[50] + 108) and its relationship to the this[62] size is only partially understood.
    // UNRESOLVED: The refresh slot (vtable offset 168) and scroll-command slot (vtable offset 64) dispatch through the object vtable at this+0; their concrete implementations are unknown.
}
