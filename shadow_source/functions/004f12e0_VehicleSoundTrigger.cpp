// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F12E0
// Canonical corpus name: VehicleSoundTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSoundTrigger_004f12e0.c

void UnknownObject::VehicleSoundTrigger()
{
    // Per-frame vehicle sound/HUD trigger on the wheel-contact path (frame-path: yes, called by sub_4F0430). Gated on a2 enable flag: walks the four-wheel array at this+0x3668 (stride 248), collects the unique surface-type identifiers from each wheel's contact struct (force id at surface+0x30, contact id at surface+0x34), then calls WheelContactForceAggregation (004F0F40) and WheelForceAggregation (004F1120) per unique surface, the latter scaled by the speed magnitude sqrt(this+0x34EC^2 + this+0x34F0^2 + this+0x34F4^2). Computes a position/velocity delta (this+0x3A58/0x3A5C/0x3A60 minus this+0x34EC/0x34F0/0x34F4), maps its magnitude into 0..1 (squared) and drives HUD element 5 (vibration) via HUDElementConfig. Always ends by driving HUD element 42 (timer: HUDElementConfig when this+0x7A4 > 0, otherwise clears flag byte this+0x5FC) and, per rigid-body status this+0x32BC (0 with dbl_7C9138 <= dbl_7C9150, or 1 with this+0x39B8 > this+0x39C4), HUD element 38 (warning) via HUDElementConfig.
    // GUARD: The whole wheel-aggregation and velocity-sound block runs only when the low byte of a2 is nonzero [source:raw]
    // LOOP: Walks the four wheel-pointer slots starting at this+0x3668, byte stride 248, exactly four iterations; null pointers are skipped [field:this:0x00003668, source:raw]
    // CALCULATION: For each valid wheel, reads the contact surface-struct pointer at wheel+84 (0x54) and collects the unique identifiers at surface+52 (0x34, contact) and surface+48 (0x30, force) into the two local dedup lists [field:*(this+0x3668):0x00000054, field:*(*(this+0x3668)+0x54):0x00000034, field:*(*(this+0x3668)+0x54):0x00000030, source:raw]
    // CALCULATION: Computes speed magnitude k as the square root of the summed squares of this+0x34EC, this+0x34F0 and this+0x34F4 [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, source:raw]
    // CALL: WheelContactForceAggregation (004F0F40) invoked once per unique contact surface-type identifier, with the vehicle pointer and the surface id [callee:0x004F0F40, source:raw]
    // CALL: WheelForceAggregation (004F1120) invoked once per unique force surface-type identifier, with the vehicle pointer, the surface id and the speed magnitude k [callee:0x004F1120, source:raw]
    // CALCULATION: Forms a velocity-delta vector as this+0x3A58/0x3A5C/0x3A60 minus this+0x34EC/0x34F0/0x34F4, takes its magnitude, scales by (mag - 2.0) * 0.010204081, clamps the positive result to 1.0 and squares it; also forms the HUD 5 intensity v16 = k * 0.00390625 + 0.89999998 [field:this:0x00003A58, field:this:0x00003A5C, field:this:0x00003A60, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, source:raw]
    // CALL: HUDElementConfig (004F87C0) drives HUD element 5 (vibration) with the squared delta magnitude and the speed-based intensity, only when the delta magnitude exceeds 0 [callee:0x004F87C0, source:raw]
    // STATE_TRANSITION: Timer branch (ungated): if this+0x7A4 (timer value) is <= 0 the flag byte this+0x5FC is cleared to 0; otherwise HUDElementConfig (004F87C0) drives HUD element 42 with the timer value [field:this:0x000007A4, field:this:0x000005FC, callee:0x004F87C0, source:raw]
    // GUARD: Rigid-body warning branch: with status this+0x32BC == 0 the function returns unless dbl_7C9138 > dbl_7C9150; with status 1 the warning fires when this+0x39B8 > this+0x39C4; either path drives HUD element 38 (warning) via HUDElementConfig (004F87C0) [field:this:0x000032BC, field:this:0x000039B8, field:this:0x000039C4, global:0x007C9138, global:0x007C9150, callee:0x004F87C0, source:raw]
    // CALL: Invoked by sub_4F0430 (004F0430) on the per-frame path [caller:0x004F0430, source:raw]

    // Conservative worker pseudocode:
    //   if (low byte of a2) {
    //     ids[2][4] = {}; counts = {0,0};
    //     for (w = 0; w < 4; ++w) {
    //       wheel = *(this + 0x3668/4 + w*248/4);
    //       if (wheel) {
    //         surf = *(wheel + 84);
    //         if (surf+52 not in ids[contact]) ids[contact][count_contact++] = *(surf+52);
    //         if (surf+48 not in ids[force])  ids[force][count_force++] = *(surf+48);
    //       }
    //     }
    //     k = sqrt(this+0x34EC^2 + this+0x34F0^2 + this+0x34F4^2);
    //     for each unique contact id: WheelContactForceAggregation(this, id);
    //     for each unique force id:  WheelForceAggregation(this, id, k);
    //     dx = this+0x3A58 - this+0x34EC; dy = this+0x3A5C - this+0x34F0; dz = this+0x3A60 - this+0x34F4;
    //     m = (sqrt(dx^2+dy^2+dz^2) - 2.0) * 0.010204081;
    //     if (m > 0.0) HUDElementConfig(5, 1, min(m,1)^2, k * 0.00390625 + 0.89999998);
    //   }
    //   if (*(this+0x7A4) <= 0.0) *(byte)(this+0x5FC) = 0;
    //   else HUDElementConfig(42, 2, *(this+0x7A4), 1.0);
    //   st = *(this+0x32BC);
    //   if (!st) { if (dbl_7C9138 > dbl_7C9150) HUDElementConfig(38, 2, 1.0, 1.0); }
    //   else if (st == 1 && *(this+0x39B8) > *(this+0x39C4)) HUDElementConfig(38, 2, 1.0, 1.0);
    // UNRESOLVED: Seven read-only globals (flt_59E430, flt_59E43C, flt_59E440, flt_59E800, flt_59E824, flt_5AC988, flt_5AD238) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them as physics/audio constants, which this packet cannot verify
    // UNRESOLVED: The wheel contact surface-struct layout (surface+48, +52 ids) and the wheel slot stride (248) are reached by relative offsets only; the enclosing class definition is not established
    // UNRESOLVED: The identities of the values written/compared (this+0x7A4 timer, this+0x39B8/0x39C4 threshold pair, this+0x32BC status enum) are plausible per the skeleton fill but are DERIVED at best from this packet
    // UNRESOLVED: HUDElementConfig element indices 5, 42 and 38 are literal call arguments; their HUD semantic labels (vibration/timer/warning) come from the skeleton fill and are not evidenced numerically in this packet
}
