// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F150
// Canonical corpus name: sub_44F150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44F150_0044f150.c

void UnknownObject::Force_Feedback_Joystick_Input_Processing()
{
    // Polls the raw input device (keyboard when the device type at this+0x0 equals 2, otherwise a joystick) each frame and refreshes per-proxy input state: it resets the active-proxy count, reads device state either as a 256-byte keyboard state or as a polled event buffer, accumulates a per-frame delta into axis positions at this+0x480, advances per-proxy activation states against thresholds, and registers active proxies into the word list at this+0xC88. A final pass toggles the sign bit of registered proxy ids matching a keyboard shift-key pattern.
    // GUARD: If the device object pointer this+0x4 is null, return immediately without polling. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Reset the active-proxy count at this+0xC84 to 0 for the current frame. [field:this:0x00000C84, source:raw]
    // GUARD: If the global input-enabled byte byte_5CD08D is clear, return immediately. [global:0x005CD08D, source:raw]
    // GUARD: When the device type at this+0x0 differs from 2 (joystick path, packet guard 0): initialize 256 per-proxy flag bytes from the state byte at this+892 (shifted left by 7), then call the device vtable slot 0x28 (call 40) to poll 20-byte events into a 1280-byte buffer; if either poll call fails, return early. [field:this:0x00000000, field:*(this+0x4):0x00000028, guard:0, source:raw]
    // LOOP: Merge polled events: for each 20-byte entry, index the per-proxy flag array by the entry's first dword (slot id) and store the entry byte 4 bit 0x80 as the pressed flag. [source:raw]
    // GUARD: When the device type at this+0x0 equals 2 (keyboard path): read the 256-byte device state via the device vtable slot 0x24 (call 36); if the read returns error -2147024884 or -2147024866, call the device vtable slot 0x1C (call 28) to acquire the device and retry the read on the object at this+0x4; if the read still fails, return early. [field:this:0x00000000, field:*(this+0x4):0x00000024, field:*(this+0x4):0x0000001C, source:raw]
    // CALCULATION: Build a 16-bit modifier word v16 from keyboard/proxy bits: bit 29 or bit 157 set contributes 4096, bit 56 contributes 0x2000, bit 42 or bit 54 contributes 0x8000, bit 69 contributes 0x4000. [source:raw]
    // LOOP: For each proxy slot 1 through 255: when the global dbl_8AFEA8 threshold is at least the per-slot limit at this+0x880 (the array anchored at this+0x480 indexed by 256), update that slot's activation byte at this+892, accumulate the frame delta a2 into the axis position at this+0x480, transition the activation state (0, 1, or 3) and clamp the position to the thresholds at this+0xC7C and this+0xC80. [global:0x008AFEA8, field:this:0x00000480, field:this:0x00000880, field:this:0x00000C7C, field:this:0x00000C80, source:raw]
    // CALCULATION: Register active proxies: when the activation state has bit 1 set and ConditionalFlagReturn(dword_5EA43C) does not suppress registration (suppressed only when dword_7C569C equals 5 and the slot is not slot 1), append the proxy id or'ed with the modifier word v16 to the word list at this+0xC88 and increment the count at this+0xC84; otherwise clear the slot's activation byte to 0. [callee:0x00404F10, global:0x005EA43C, global:0x007C569C, field:this:0x00000C88, field:this:0x00000C84, source:raw]
    // LOOP: When keyboard bit v19[58] is set and the active-proxy count at this+0xC84 is greater than 0 (packet guard 1), walk the registered word list at this+0xC88 and toggle the sign bit (0x8000) of proxy ids matching the switch-table case range 0x10..0x19, 0x1E..0x26 and 0x2C..0x32, as dispatched by the jump table at jpt_44F3EE. [guard:1, field:this:0x00000C88, field:this:0x00000C84, global:0x0044F42C, source:raw]

    // Conservative worker pseudocode:
    //   if (!this.device) return;
    //   this[C84] = 0;
    //   if (!byte_5CD08D) return;
    //   if (this[0] == 2) {
    //       v19 = GetState(this.device, 256);
    //       if (v19 fails with -2147024884 / -2147024866) { Acquire(this.device); v19 = GetState(this.device, 256); }
    //   } else {
    //       for i in 0..255: v19[i] = stateByte(this+892+i) << 7;
    //       if (Poll(device, events) || Poll(this.device, events)) return;
    //       for each 20-byte event: v19[event.slotId] = event.byte4 & 0x80;
    //   }
    //   v16 = build modifier word from v19[29/157/56/42/54/69];
    //   for slot in 1..255:
    //       if (dbl_8AFEA8 >= limit[this+0x880+slot]):
    //           if pressed: accumulate a2 into axis[this+0x480+slot]; advance activation (0/1/3);
    //                   clamp to thresholds this+C7C / this+C80;
    //                   if activation bit1 && !ConditionalFlagReturn(dword_5EA43C) || dword_7C569C != 5 || slot == 1:
    //                       list[this+C88 + count++] = (slot | v16);
    //           else activation = 0;
    //   if (v19[58] && this[C84] > 0):
    //       for each registered id: if low byte in jpt case range: id ^= 0x8000;
    // UNRESOLVED: byte_44F434 (0x0044F434) and flt_59E440 (0x0059E440) appear in the packet global list but are not referenced by the raw decompilation; their role is unknown.
    // UNRESOLVED: The per-proxy activation byte at this+892 and the auxiliary state byte at this+636 are side tables present in the raw source but not exposed as packet fields.
    // UNRESOLVED: The purpose of the final sign-bit toggle pass (keyboard bit v19[58], 0x8000 toggling over the jump-table case range) is DERIVED from the switch structure; its gameplay meaning is unknown.
}
