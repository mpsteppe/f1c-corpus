// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED810
// Canonical corpus name: WheelTireForceUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelTireForceUpdate_004ed810.c

void UnknownObject::WheelTireForceUpdate()
{
    // Per-frame tire temperature update with a thermal model. Computes two tire-temperature updates from absolute slip inputs, friction-heating and convection coefficients, blending toward an ambient reference derived from flt_8AFEF0 + 273.16; then runs a four-iteration normalization loop that clamps each corner temperature into [0, 1] and stores it through a wheel base pointer at this+0x8CC. Called per frame by MainGameTickUpdate (0042C690).
    // ASSIGNMENT: Compute the ambient reference v17 = flt_8AFEF0 + 273.16 used as the convective target temperature. [global:0x008AFEF0, source:raw]
    // CALCULATION: Read the shared absolute slip-magnitude term v16 = fabs(this+0x3500) used by both temperature updates. [field:this:0x00003500, source:raw]
    // CALCULATION: First temperature update: new_temp = ((fabs(slip_a)*coef_a + fabs(slip_b)*coef_b) * convection * 0.5 + (v16 * friction + convection_off) * (v17 - temp)) * a2 + temp, using slip/coefficient inputs at this+0x35B0/+0x35D8 and this+0x36A8/+0x36D0 with model parameters this+0x3A38/+0x3A3C/+0x3A40; written to this+0x35DC and copied to this+0x36D4. [field:this:0x000035B0, field:this:0x000035D8, field:this:0x000036A8, field:this:0x000036D0, field:this:0x00003A38, field:this:0x00003A3C, field:this:0x00003A40, field:this:0x000035DC, field:this:0x000036D4, source:raw]
    // CALCULATION: Second temperature update: same form against temperature slot this+0x37CC using slip/coefficient inputs at this+0x37A0/+0x37C8 and this+0x3898/+0x38C0 with model parameters this+0x3A4C/+0x3A50/+0x3A54; written to this+0x37CC and copied to this+0x38C4. [field:this:0x000037A0, field:this:0x000037C8, field:this:0x00003898, field:this:0x000038C0, field:this:0x00003A4C, field:this:0x00003A50, field:this:0x00003A54, field:this:0x000037CC, field:this:0x000038C4, source:raw]
    // LOOP: Four-iteration normalization loop: for each of the four corner temperatures (read at this+0x35DC, this+0x36D4, this+0x37CC, this+0x38C4, stepping 62 floats), normalize value = ((temp - 1023.16) * 0.004) clamped into [0, 1] and write it to the per-corner slot reached through the wheel base pointer at this+0x8CC (stepping 74 floats per corner). [field:this:0x000008CC, field:this:0x000035DC, field:this:0x000036D4, field:this:0x000037CC, field:this:0x000038C4, source:raw]
    // CALL: Invoked per frame by MainGameTickUpdate (0042C690) as the tire-temperature stage of the game tick. [caller:0x0042C690, source:raw]

    // Conservative worker pseudocode:
    //   // this: wheel object, a2: frame-delta time scale
    //   ambient = flt_8AFEF0 + 273.16;
    //   slip_mag = fabs(this[0x3500]);
    //   temp_a = this[0x35DC];
    //   this[0x35DC] = ((fabs(this[0x35B0])*this[0x35D8] + fabs(this[0x36A8])*this[0x36D0]) * this[0x3A38] * 0.5
    //                + (slip_mag*this[0x3A40] + this[0x3A3C]) * (ambient - temp_a)) * a2 + temp_a;
    //   this[0x36D4] = this[0x35DC];
    //   temp_b = this[0x37CC];
    //   this[0x37CC] = ((fabs(this[0x37A0])*this[0x37C8] + fabs(this[0x3898])*this[0x38C0]) * this[0x3A4C] * 0.5
    //                + (slip_mag*this[0x3A54] + this[0x3A50]) * (ambient - temp_b)) * a2 + temp_b;
    //   this[0x38C4] = this[0x37CC];
    //   src = &this[0x35DC]; dst = (float*)(this + 0x8CC);  // per-corner base
    //   for (corner = 0; corner < 4; ++corner) {
    //     value = (*src - 1023.16) * 0.004;
    //     value = value < 0.0 ? 0.0 : (value > 1.0 ? 1.0 : value);
    //     *dst = value;
    //     src += 62; dst += 74;
    //   }
    // UNRESOLVED: The per-corner normalization write slots reached through the wheel base pointer at this+0x8CC are relative to that pointer; their absolute offsets from the wheel object are not in the packet field set.
    // UNRESOLVED: Six read-only globals (flt_59E43C, flt_59E440, flt_59E450, dbl_59EEC0, dbl_59EEC8, flt_5ACAFC) are flagged by packet facts but appear nowhere in the raw decompiled source; their roles are unverifiable from this packet.
    // UNRESOLVED: Which physical corners the two temperature-update groups and the four normalization slots map to is not determinable from this packet alone.
}
