// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4050
// Canonical corpus name: AccumulatorWithStateSwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulatorWithStateSwitch_004a4050.c

void UnknownObject::AccumulatorWithStateSwitch()
{
    // Per-frame accumulator update gated on a mode word at offset 0x78: mode 0 disables the update, mode 1 resets the accumulator dword at offset 0x84 to 0, and any other non-zero mode adds argument a2 to the accumulator float at offset 0x84. After the update the accumulator value at offset 0x84 is forwarded to sub_4A2840. Invoked from ConditionalDispatch_55a0.
    // GUARD: Reads the mode word at offset 0x78; when it is 0 the function returns without touching the accumulator or calling sub_4A2840 [field:this:0x00000078, source:raw]
    // GUARD: When the mode word at offset 0x78 is exactly 1 the accumulator at offset 0x84 is reset instead of being incremented [field:this:0x00000078, field:this:0x00000084, source:raw]
    // ASSIGNMENT: In mode 1 the accumulator dword at offset 0x84 is set to 0 [field:this:0x00000084, source:raw]
    // CALCULATION: For any other non-zero mode the accumulator float at offset 0x84 is set to argument a2 plus its previous value [field:this:0x00000084, source:raw]
    // CALL: After the accumulator update, sub_4A2840 is invoked with this object and the accumulator value at offset 0x84 for further processing [field:this:0x00000084, function:0x004A4050, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(int*)(this + 0x78);
    //   if (v2 == 0) return;
    //   if (v2 == 1)
    //       *(int*)(this + 0x84) = 0;
    //   else
    //       *(float*)(this + 0x84) += a2;
    //   sub_4A2840(this, *(float*)(this + 0x84));
    // UNRESOLVED: The identity of the object owning offsets 0x78 and 0x84 is unknown
    // UNRESOLVED: The meaning of the mode values at offset 0x78 (beyond 0=disabled and 1=reset) is not documented
    // UNRESOLVED: sub_4A2840's behavior and the significance of the forwarded accumulator value are outside this packet
}
