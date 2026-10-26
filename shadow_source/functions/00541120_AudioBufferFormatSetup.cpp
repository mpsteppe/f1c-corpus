// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541120
// Canonical corpus name: AudioBufferFormatSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioBufferFormatSetup_00541120.c

void UnknownObject::AudioBufferFormatSetup()
{
    // Configures an audio buffer format on the audio sub-object. Guards on a configuration object (a3 non-zero with a non-zero dword at a3+32). Optionally tears down a pending buffer via vtable slot 148 on the sub-object at this[1088] (this+0x1100), then enters a state 7 via vtable slot 200. Decodes format flags from a7/a8 into the channel-config field this[1116] (this+0x1170) with 256/1280/2304 base values and 1/0x800 flag bits, dispatches through sub_554790, the multi-field setter, the chained state init and the property setter, then invokes vtable slot 280 (format set) with either a buffered or a divided sample rate, restoring the saved state field this[1262] (this+0x13B8) through a final vtable slot 200 call. Called by sub_553070 (00553070) and sub_553700 (00553700).
    // CALL: StructInitWithDefaultValues initializes the local 32-byte structure v18 to defaults [callee:0x00553DB0, source:raw]
    // GUARD: The whole configuration block runs only when a3 is non-zero and the dword at a3+32 is non-zero; otherwise the function returns the incoming a3 value [source:raw]
    // GUARD: When the pending-init flag this[1267] (this+0x13CC) is set, the flag is cleared and vtable slot 148 on the sub-object at this[1088] is invoked with (256, this+1283) to tear down the prior buffer, storing the result at this+0x0 [field:this:0x000013CC, field:this:0x00001100, field:*(this+0x1100):0x00000094, field:this:0x00000000, source:raw]
    // CALL: vtable slot 200 on the sub-object at this[1088] (this+0x1100) is invoked with (7, 0) to enter state 7, storing the result at this+0x0 [field:this:0x00001100, field:*(this+0x1100):0x000000C8, field:this:0x00000000, source:raw]
    // GUARD: a6-present branch: sub_554F80(a2, a6) validates the format and early-returns its result when it is 0 [callee:0x00554F80, source:raw]
    // CALCULATION: Decodes a8 & 0x1400: v22 is set to 1 when the masked value equals 1024, or 2 when it equals 4096 [source:raw]
    // CALCULATION: Decodes a8 & 0x2800: v23 is set to 1 when the masked value equals 2048, or 2 when it equals 0x2000 [source:raw]
    // ASSIGNMENT: Channel/config field this[1116] (this+0x1170) is set to 256 as the base value; a7 & 0x40 overrides it to 1280; a8 & 0x80 ORs in 1 and sets v20 to 3; a7 & 0x20 ORs in 0x800, sets v20 to 2 and v12 to 393221 [field:this:0x00001170, source:raw]
    // ASSIGNMENT: a6-absent branch: this[1116] (this+0x1170) is set to 256 with v19 cleared, or to 2304 with v20 2 and v12 327686 when a7 & 0x20 is set [field:this:0x00001170, source:raw]
    // CALL: sub_554790(this[1116], v12, a9) dispatches the chosen channel configuration with its mode tag [callee:0x00554790, field:this:0x00001170, source:raw]
    // CALL: MultiFieldSetterDispatchingTo7SubSetters(v18, 0) pushes the initialized local structure through seven sub-setters [callee:0x005546A0, source:raw]
    // CALL: StateFieldSetWithChainedInit(1) sets a state field with chained initialization [callee:0x00553FA0, source:raw]
    // CALL: PropertyValueSetterWithRefreshOnChange(a3) applies the configuration object through a refresh-on-change property setter [callee:0x00554700, source:raw]
    // CALL: vtable slot 280 on the sub-object at this[1088] (this+0x1100) sets the format: with a10 set it is called as (6, a4, a10); otherwise as (4, a4, a5 / 3) [field:this:0x00001100, field:*(this+0x1100):0x00000118, source:raw]
    // ASSIGNMENT: The saved state field this[1262] (this+0x13B8) is read into v17, the format-set result is stored at this+0x0, then vtable slot 200 is re-invoked with (7, v17) to restore the state and its result is stored at this+0x0 [field:this:0x000013B8, field:this:0x00000000, field:this:0x00001100, field:*(this+0x1100):0x000000C8, source:raw]
    // RETURN: Returns the result of the last operation, which is a3 when the config guard failed [source:raw]
    // CALL: Invoked by sub_553070 (00553070) and sub_553700 (00553700) to configure the audio buffer format [caller:0x00553070, caller:0x00553700, source:raw]

    // Conservative worker pseudocode:
    //   StructInitWithDefaultValues(local);
    //   result = a3;
    //   v12 = 65538;
    //   if (a3 && *(a3+32)) {
    //     if (this[1267]) {
    //       this[1267] = 0;
    //       *this = vtable(*(this[1088]), 148)(this[1088], 256, this+1283);
    //     }
    //     *this = vtable(*(this[1088]), 200)(this[1088], 7, 0);
    //     if (a6) {
    //       result = sub_554F80(a2, a6);
    //       if (!result) return result;
    //       this[1116] = 256;
    //       sel = a8 & 0x1400;
    //       if (sel == 1024) v22 = 1; else if (sel == 4096) v22 = 2;
    //       sel = a8 & 0x2800;
    //       if (sel == 2048) v23 = 1; else if (sel == 0x2000) v23 = 2;
    //       if (a7 & 0x40) this[1116] = 1280;
    //       if (a8 & 0x80) { this[1116] |= 1; v20 = 3; }
    //       if (a7 & 0x20) { this[1116] |= 0x800; v20 = 2; v12 = 393221; }
    //     } else {
    //       this[1116] = 256; v19 = 0;
    //       if (a7 & 0x20) { this[1116] = 2304; v20 = 2; v12 = 327686; }
    //     }
    //     sub_554790(this[1116], v12, a9);
    //     MultiFieldSetterDispatchingTo7SubSetters(local, 0);
    //     StateFieldSetWithChainedInit(1);
    //     PropertyValueSetterWithRefreshOnChange(a3);
    //     if (a10) v16 = vtable(*(this[1088]), 280)(this[1088], 6, a4, a10);
    //     else v16 = vtable(*(this[1088]), 280)(this[1088], 4, a4, a5 / 3);
    //     v17 = this[1262];
    //     *this = v16;
    //     *this = vtable(*(this[1088]), 200)(this[1088], 7, v17);
    //   }
    //   return result;
    // UNRESOLVED: The vtable slots 148/200/280 on the sub-object at this[1088] are reached through indirect dispatch; their concrete behavior (buffer teardown, state entry, format set) is inferred from the existing analysis only
    // UNRESOLVED: The saved state field this[1262] (this+0x13B8) and the pending-init flag this[1267] (this+0x13CC) are offset-indexed only; their meaning is inferred from call ordering
    // UNRESOLVED: The role of the two zero literals passed to sub_554F80 and of the a6 validation failure path is not documented in this function
}
