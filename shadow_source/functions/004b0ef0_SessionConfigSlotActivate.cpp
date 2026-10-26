// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0EF0
// Canonical corpus name: sub_4B0EF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B0EF0_004b0ef0.c

void UnknownObject::SessionConfigSlotActivate()
{
    // Activates one of six configuration slots (a2 in 1..6) on a session-configuration object. Copies each per-slot parameter value into the active/current field and clamps it against stored per-group min/max bounds; groups use ClampByRange except a byte group using ByteClamp and a float group using FloatClamp. Two groups clamp inline. Slots 1 and 2 additionally preset a control field (this+0x1C54) to 1 or 7 before clamping. Ends by calling sub_4B1190(-1.0) and returning 1; returns 0 when a2 is out of range.
    // GUARD: Range guard on parameter a2: if a2 < 1 or a2 >= 7 return 0 [source:raw]
    // ASSIGNMENT: Slot index: write a2 into this+0x1F78 then ClampByRange(this+0x1F78, this+0x1F80, this+0x1F84) [callee:0x0047F1F0, field:this:0x00001F78, field:this:0x00001F80, field:this:0x00001F84, source:raw]
    // ASSIGNMENT: Active param group 1: copy this[4*(9*a2+369)] into this+0x5C4, then ClampByRange(this+0x5C4, this+0x5CC, this+0x5D0) [callee:0x0047F1F0, field:this:0x000005C4, field:this:0x000005CC, field:this:0x000005D0, source:raw]
    // ASSIGNMENT: Active param group 2: with v6 = this + 36*a2, copy *(v6+0x7F8) into this+0x7F8, then ClampByRange(this+0x7F8, this+0x800, this+0x804) [callee:0x0047F1F0, field:this:0x000007F8, field:this:0x00000800, field:this:0x00000804, source:raw]
    // ASSIGNMENT: Active param group 3: copy *(v6+0x8F4) into this+0x8F4, then ClampByRange(this+0x8F4, this+0x8FC, this+0x900) [callee:0x0047F1F0, field:this:0x000008F4, field:this:0x000008FC, field:this:0x00000900, source:raw]
    // ASSIGNMENT: Active param group 4: copy *(v6+0x9F0) into this+0x9F0, then ClampByRange(this+0x9F0, this+0x9F8, this+0x9FC) [callee:0x0047F1F0, field:this:0x000009F0, field:this:0x000009F8, field:this:0x000009FC, source:raw]
    // ASSIGNMENT: Active param group 5: copy *(v6+0xAEC) into this+0xAEC, then ClampByRange(this+0xAEC, this+0xAF4, this+0xAF8) [callee:0x0047F1F0, field:this:0x00000AEC, field:this:0x00000AF4, field:this:0x00000AF8, source:raw]
    // ASSIGNMENT: Active param group 6: copy *(v6+0xBE8) into this+0xBE8, then ClampByRange(this+0xBE8, this+0xBF0, this+0xBF4) [callee:0x0047F1F0, field:this:0x00000BE8, field:this:0x00000BF0, field:this:0x00000BF4, source:raw]
    // ASSIGNMENT: Byte group: copy *(BYTE*)(this + 24*a2 + 0xCE4) into this+0xCE4, then ByteClamp(this+0xCE4, this+0xCE6, this+0xCE7) [callee:0x00464720, field:this:0x00000CE4, field:this:0x00000CE6, field:this:0x00000CE7, source:raw]
    // ASSIGNMENT: Active param group 7: copy *(v6+0x200C) into this+0x200C, then ClampByRange(this+0x200C, this+0x2014, this+0x2018) [callee:0x0047F1F0, field:this:0x0000200C, field:this:0x00002014, field:this:0x00002018, source:raw]
    // ASSIGNMENT: Active param group 8: copy *(v6+0x2108) into this+0x2108, then ClampByRange(this+0x2108, this+0x2110, this+0x2114) [callee:0x0047F1F0, field:this:0x00002108, field:this:0x00002110, field:this:0x00002114, source:raw]
    // ASSIGNMENT: Active param group 9: copy *(v6+0x2204) into this+0x2204, then ClampByRange(this+0x2204, this+0x220C, this+0x2210) [callee:0x0047F1F0, field:this:0x00002204, field:this:0x0000220C, field:this:0x00002210, source:raw]
    // ASSIGNMENT: Float group: copy *(float*)(v6+0x2300) into this+0x2300, then FloatClamp(this+0x2300, this+0x2308, this+0x230C) [callee:0x004646C0, field:this:0x00002300, field:this:0x00002308, field:this:0x0000230C, source:raw]
    // ASSIGNMENT: Active param group 10: copy *(v6+0x24F8) into this+0x24F8, then ClampByRange(this+0x24F8, this+0x2500, this+0x2504) [callee:0x0047F1F0, field:this:0x000024F8, field:this:0x00002500, field:this:0x00002504, source:raw]
    // ASSIGNMENT: Active param group 11: copy *(v6+0x26CC) into this+0x26CC, then ClampByRange(this+0x26CC, this+0x26D4, this+0x26D8) [callee:0x0047F1F0, field:this:0x000026CC, field:this:0x000026D4, field:this:0x000026D8, source:raw]
    // ASSIGNMENT: Inline-clamped group 12: copy *(v6+0x27C8) into this+0x27C8, then clamp it inline to the [this+0x27D0, this+0x27D4] range without a helper call [field:this:0x000027C8, field:this:0x000027D0, field:this:0x000027D4, source:raw]
    // ASSIGNMENT: Inline-clamped group 13: copy *(v6+0x23FC) into this+0x23FC, then clamp it inline to the [this+0x2404, this+0x2408] range without a helper call [field:this:0x000023FC, field:this:0x00002404, field:this:0x00002408, source:raw]
    // STATE_TRANSITION: Special case: if a2 == 1 write 1 into this+0x1C54, else if a2 == 2 write 7 into this+0x1C54; both then ClampByRange(this+0x1C54, this+0x1C5C, this+0x1C60) [callee:0x0047F1F0, field:this:0x00001C54, field:this:0x00001C5C, field:this:0x00001C60, source:raw]
    // CALL: Apply the configuration globally: sub_4B1190(-1.0) [callee:0x004B1190, source:raw]
    // RETURN: Return 1 on success [function:0x004B0EF0, source:raw]
    // CALL: Invoked by SessionConfigWriteback (00461900), SessionInit (004A06E0) and PlayerFileInit (004B0540) to select a stored configuration slot [caller:0x00461900, caller:0x004A06E0, caller:0x004B0540, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 < 1 || a2 >= 7) return 0;
    //   this+0x1F78 = a2; ClampByRange(&this+0x1F78, this+0x1F80, this+0x1F84);
    //   this+0x5C4 = this[4*(9*a2 + 369)]; ClampByRange(&this+0x5C4, this+0x5CC, this+0x5D0);
    //   slot = this + 36*a2;
    //   this+0x7F8 = slot+0x7F8; ClampByRange(&this+0x7F8, this+0x800, this+0x804);
    //   this+0x8F4 = slot+0x8F4; ClampByRange(&this+0x8F4, this+0x8FC, this+0x900);
    //   this+0x9F0 = slot+0x9F0; ClampByRange(&this+0x9F0, this+0x9F8, this+0x9FC);
    //   this+0xAEC = slot+0xAEC; ClampByRange(&this+0xAEC, this+0xAF4, this+0xAF8);
    //   this+0xBE8 = slot+0xBE8; ClampByRange(&this+0xBE8, this+0xBF0, this+0xBF4);
    //   this+0xCE4 = (BYTE)(this + 24*a2)[0xCE4]; ByteClamp(&this+0xCE4, this+0xCE6, this+0xCE7);
    //   this+0x200C = slot+0x200C; ClampByRange(&this+0x200C, this+0x2014, this+0x2018);
    //   this+0x2108 = slot+0x2108; ClampByRange(&this+0x2108, this+0x2110, this+0x2114);
    //   this+0x2204 = slot+0x2204; ClampByRange(&this+0x2204, this+0x220C, this+0x2210);
    //   this+0x2300 = slot+0x2300; FloatClamp(&this+0x2300, this+0x2308, this+0x230C);
    //   this+0x24F8 = slot+0x24F8; ClampByRange(&this+0x24F8, this+0x2500, this+0x2504);
    //   this+0x26CC = slot+0x26CC; ClampByRange(&this+0x26CC, this+0x26D4, this+0x26D8);
    //   this+0x27C8 = slot+0x27C8; if (this+0x27C8 < this+0x27D0) this+0x27C8 = this+0x27D0; if (this+0x27C8 > this+0x27D4) this+0x27C8 = this+0x27D4;
    //   this+0x23FC = slot+0x23FC; if (this+0x23FC < this+0x2404) this+0x23FC = this+0x2404; if (this+0x23FC > this+0x2408) this+0x23FC = this+0x2408;
    //   if (a2 == 1) this+0x1C54 = 1;
    //   else if (a2 == 2) this+0x1C54 = 7;
    //   if (a2 == 1 || a2 == 2) ClampByRange(&this+0x1C54, this+0x1C5C, this+0x1C60);
    //   sub_4B1190(-1.0);
    //   return 1;
    // UNRESOLVED: The exact meaning of each copied group (engine, gear, tyre, aero, etc.) is not determinable from this function alone; group roles come from the external fill analysis
    // UNRESOLVED: The inline clamps at this+0x27C8 and this+0x23FC use the same min/max semantics as ClampByRange but were compiled inline, so no helper call appears
    // UNRESOLVED: Slot storage layout is dual-stride: the group at this+0x5C4 uses 4*(9*a2+369) (36-slot-relative), most groups use this+36*a2, and the byte group uses this+24*a2; the divergent strides are evidence-only, not explained here
}
