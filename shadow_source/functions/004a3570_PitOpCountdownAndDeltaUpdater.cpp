// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3570
// Canonical corpus name: sub_4A3570
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A3570_004a3570.c

void UnknownObject::PitOpCountdownAndDeltaUpdater()
{
    // Dual-mode per-frame updater over an element array (base this+0x10, stride 120 bytes, count this+0xC). When flags bit 0 (this+0x0) is set and the countdown counter this+0x8 is above 0, the counter is decremented and every element gets its +68 dword reset to -1082130432 (a -1.0f float) followed by sub_4A2840(element, 0.0). When flags bit 1 (this+0x0) is set, a delta a2 - this[1] is computed and sub_4A2840(element, delta) runs on every element. The two modes are independent and can both run in one tick.
    // GUARD: Mode-1 enable: flags byte at this+0x0 has bit 0 set. [field:this:0x00000000, source:raw]
    // GUARD: Countdown gate: the counter at this+0x8 must be greater than 0 for mode 1 to act. [guard:0, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Decrement the countdown counter at this+0x8. [field:this:0x00000008, source:raw]
    // GUARD: Element-count gate: the count at this+0xC must be greater than 0 before either loop runs. [field:this:0x0000000C, source:raw]
    // LOOP: Walk the element array at base this+0x10, 120 bytes per element, once per element in this+0xC. [field:this:0x00000010, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write the dword -1082130432 (a -1.0f bit pattern) to each element's +68 slot. [source:raw]
    // CALL: Reset each element with sub_4A2840(element, 0.0). [callee:0x004A2840, source:raw]
    // GUARD: Mode-2 enable: flags byte at this+0x0 has bit 1 set. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the per-element delta v8 = a2 - this[1] (reference value at this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: Element-count gate for mode 2: the count at this+0xC must be greater than 0. [field:this:0x0000000C, source:raw]
    // LOOP: Walk the element array at base this+0x10, 120 bytes per element, once per element in this+0xC. [field:this:0x00000010, field:this:0x0000000C, source:raw]
    // CALL: Update each element with sub_4A2840(element, delta). [callee:0x004A2840, source:raw]
    // CALL: Invoked by ConditionalDispatch_55a0 (004A55A0). [caller:0x004A55A0, source:raw]

    // Conservative worker pseudocode:
    //   void PitOpCountdownAndDeltaUpdater(float *this, float a2) {
    //     char flags = *(char *)this;
    //     if ((flags & 1) != 0) {
    //       if (this[2] > 0) {
    //         this[2]--;
    //         int count = this[3];
    //         int i = 0;
    //         while (i < count) {
    //           *(DWORD*)((char*)this[4] + i*120 + 68) = -1082130432;   // -1.0f
    //           sub_4A2840((char*)this[4] + i*120, 0.0);
    //           ++i;
    //         }
    //       }
    //     }
    //     if ((flags & 2) != 0) {
    //       float delta = a2 - this[1];
    //       int count = this[3];
    //       int i = 0;
    //       while (i < count) {
    //         sub_4A2840((char*)this[4] + i*120, delta);
    //         ++i;
    //       }
    //     }
    //   }
    // UNRESOLVED: The element type and the meaning of each element's +68 slot are not established by this packet; sub_4A2840 defines the write semantics.
    // UNRESOLVED: The object owning this+0x10's array is unknown; the packet owner is UnknownObject.
    // UNRESOLVED: The purpose of the two independent modes (countdown reset versus delta update) and their interaction with the pit flow is only described by the skeleton fill, which is a labeled lower-trust layer.
}
