// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C71C0
// Canonical corpus name: SetupCarLightingAndRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupCarLightingAndRender_004c71c0.c

void UnknownObject::SetupCarLightingAndRender()
{
    // Per-vehicle telemetry packet encoder (__thiscall on the vehicle struct, output buffer a2). Writes a header marker with the current session time, then packs physics/state fields from the vehicle struct into a bitfield DWORD array via a series of encoding subroutines: position vector, speed, fixed-point and short conversions, per-wheel suspension position + offset sums, RPM, throttle, gear, clutch, per-index subsystem-ready bits, and a packed flag word (driver-model visibility, brake threshold, and other flag bytes). Final flag word also mirrors the player vehicle's state dword, then the packet is closed by a trailing encoding call.
    // ASSIGNMENT: Initialize loop index v2 to 0 and load the session-time double dbl_8AFEA0 into the float argument v21. [source:raw, global:0x008AFEA0]
    // CALL: Call ProgressBarEventEncode(a2, 1, 0, 52, *(this+18580), v21, 0) to write a header/progress marker into the packet buffer using the vehicle's state dword at +0x4894 and the session-time value. [callee:0x004B33B0, field:this:0x00004894, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Set v4 = a2 + 2, the pointer to the packet body words following the header. [source:raw]
    // CALL: Call sub_4B2310(a2 + 2, this + 1860, this + 1796) to encode a position/offset vector pair from the vehicle struct into the packet body. [callee:0x004B2310, source:raw]
    // CALL: Call UtilityFunction_2480((_WORD*)a2 + 4, this + 13560) to encode a float field into a 16-bit short field of the packet. [callee:0x004B2480, source:raw]
    // CALL: Call FloatToFixedConversionWithClamp(a2 + 2, this + 13584) to convert a float into clamped fixed-point in the packet body. [callee:0x004B25D0, source:raw]
    // CALL: Call FloatToShortClampedConversion((_WORD*)a2 + 4, this + 13632) to encode a float into a clamped 16-bit short. [callee:0x004B2750, source:raw]
    // LOOP: do-while loop over 4 wheel entries (v2 from 0 to < 1184 in steps of 296): computes v22 = *(float*)(v2 + this + 1776 + 332) + *(float*)(this + 1852), i.e. per-wheel suspension position (stride 0x128) plus the body offset field +0x73C, then calls FloatToByteShortEncoding(v4, v24, v22, *v23) where v23 advances from this + 13756 (field +0x35BC) by stride 62 each iteration; increments v24 as the wheel index. [source:raw, field:this:0x0000073C, field:this:0x000035BC, callee:0x004B2840]
    // CALL: Call FloatToBitfieldPack(v4, *(this + 14752)) to pack the engine RPM float (field +0x39A0) into a bitfield slot. [callee:0x004B2930, field:this:0x000039A0, source:raw]
    // CALL: Call BitfieldInsert(v4, *(this + 13692)) to insert the throttle factor float (field +0x357C) into a specific bitfield position. [callee:0x004B29B0, field:this:0x0000357C, source:raw]
    // CALL: Call ShortComputation_2a10(v4, *(this + 14844)) to encode the current-gear DWORD (field +0x39FC) into the packet. [callee:0x004B2A10, field:this:0x000039FC, source:raw]
    // GUARD: Conditionally set or clear bit 0x80 in packet word v4[11] based on flag byte at this + 4201 (field +0x1069). [source:raw, field:this:0x00001069]
    // CALL: Call FloatToBitfieldEncoder(v4, *(this + 13696)) to encode the clutch-engagement float (field +0x3580) into a bitfield with shift/mask. [callee:0x004B2A40, field:this:0x00003580, source:raw]
    // LOOP: for i in 0..13: v8 = SubsystemReadyQuery(i); BitfieldSetClearByIndex(v4, i, v8) - queries 14 subsystem-ready booleans and sets/clears the corresponding bit by index in the packet. [callee:0x004E18C0, callee:0x004B2AA0, source:raw]
    // GUARD: Conditionally set or clear bit 0x8000000 in packet word v4[12] based on flag byte at this + 4189 (field +0x105D, driver-model visibility). [source:raw, field:this:0x0000105D]
    // GUARD: Conditionally set or clear bit 0x4000000 in packet word v4[12] based on the brake-factor float at this + 13700 (field +0x3584) compared to 0.0099999998. [source:raw, field:this:0x00003584]
    // GUARD: Conditionally set or clear bit 0x2000000 in packet word v4[12] based on flag byte at this + 4199 (field +0x1067). [source:raw, field:this:0x00001067]
    // GUARD: Conditionally set or clear bit 0x80000000 in packet word v4[12] based on flag byte at this + 13388 (field +0x344C). [source:raw, field:this:0x0000344C]
    // GUARD: Conditionally set or clear bit 0x1000000 in packet word v4[12] based on flag byte at this + 16420 (field +0x4024). [source:raw, field:this:0x00004024]
    // CALL: Call FunctionCallWrapper_2b10(v4, *(this + 16424)) to encode the steering float (field +0x4028) into the packet. [callee:0x004B2B10, field:this:0x00004028, source:raw]
    // CALL: Call BitfieldSetter(v4, *(dword_7C54F0[dword_7C54DC] + 18580)) to set a packet bitfield from the player vehicle's state dword at +0x4894, resolved through the vehicle pointer array global and the current-player-index global. [callee:0x004B2B60, global:0x007C54F0, global:0x007C54DC, field:this:0x00004894, source:raw]
    // CALL: Call Constant5(this) to obtain the final encoding value v19. [callee:0x004C7C00, source:raw]
    // RETURN: Return sub_4B2AE0(v4, v19), the final packet closing/encoding call. [callee:0x004B2AE0, source:raw]
    // CALL: Called by PitTimingUpdate (0x004B7A90) and TireTemperatureSimStep (0x004C77D0) to emit the per-vehicle telemetry packet. [caller:0x004B7A90, caller:0x004C77D0, source:raw]

    // Conservative worker pseudocode:
    //   int SetupCarLightingAndRender(int this, _DWORD *a2) {
    //     int v2 = 0;
    //     float v21 = dbl_8AFEA0;
    //     ProgressBarEventEncode(a2, 1, 0, 52, *(_DWORD *)(this + 18580), v21, 0);
    //     _DWORD *v4 = a2 + 2;
    //     sub_4B2310(a2 + 2, (_DWORD *)(this + 1860), (float *)(this + 1796));
    //     UtilityFunction_2480((_WORD *)a2 + 4, (float *)(this + 13560));
    //     FloatToFixedConversionWithClamp((int)(a2 + 2), (float *)(this + 13584));
    //     FloatToShortClampedConversion((_WORD *)a2 + 4, (float *)(this + 13632));
    //     int v24 = 0;
    //     float *v23 = (float *)(this + 13756);
    //     do {
    //       float v22 = *(float *)(v2 + this + 1776 + 332) + *(float *)(this + 1852);
    //       FloatToByteShortEncoding(v4, v24, v22, *v23);
    //       v2 += 296; ++v24; v23 += 62;
    //     } while ( v2 < 1184 );
    //     FloatToBitfieldPack(v4, *(float *)(this + 14752));
    //     BitfieldInsert(v4, *(float *)(this + 13692));
    //     ShortComputation_2a10(v4, *(_DWORD *)(this + 14844));
    //     v4[11] = *(_BYTE *)(this + 4201) ? (v4[11] | 0x80) : (v4[11] & 0xFFFFFF7F);
    //     FloatToBitfieldEncoder(v4, *(float *)(this + 13696));
    //     for ( int i = 0; i < 14; ++i )
    //       BitfieldSetClearByIndex(v4, i, SubsystemReadyQuery(i));
    //     v4[12] = *(_BYTE *)(this + 4189) ? (v4[12] | 0x8000000) : (v4[12] & 0xF7FFFFFF);
    //     v4[12] = *(float *)(this + 13700) <= 0.0099999998 ? (v4[12] & 0xFBFFFFFF) : (v4[12] | 0x4000000);
    //     v4[12] = *(_BYTE *)(this + 4199) ? (v4[12] | 0x2000000) : (v4[12] & 0xFDFFFFFF);
    //     v4[12] = *(_BYTE *)(this + 13388) ? (v4[12] | 0x80000000) : (v4[12] & 0x7FFFFFFF);
    //     v4[12] = *(_BYTE *)(this + 16420) ? (v4[12] | 0x1000000) : (v4[12] & 0xFEFFFFFF);
    //     FunctionCallWrapper_2b10(v4, *(float *)(this + 16424));
    //     BitfieldSetter(v4, *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580));
    //     return sub_4B2AE0(v4, Constant5(this));
    //   }
    // UNRESOLVED: The exact bit assignments of packet words v4[11] and v4[12] beyond the visible masks (0x80, 0x8000000, 0x4000000, 0x2000000, 0x80000000, 0x1000000) are only partially decoded; the remaining bits are owned by other writers.
    // UNRESOLVED: SubsystemReadyQuery index semantics for i in 0..13 are not decoded here; the mapping of index to subsystem lives in 0x004E18C0.
    // UNRESOLVED: The layout of the packet header written by ProgressBarEventEncode and the trailing sub_4B2AE0 close are callee-internal.
    // UNRESOLVED: Encoding transforms applied by each packing subroutine are callee-internal.
}
