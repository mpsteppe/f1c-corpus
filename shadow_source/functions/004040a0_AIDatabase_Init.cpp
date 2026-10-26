// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004040A0
// Canonical corpus name: AIDatabase_Init
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDatabase_Init_004040a0.c

void UnknownObject::AIDatabase_Init()
{
    // Initializes the AI difficulty database object from built-in constants and an on-disk AI database file. Seeds track-position speed-curve slots (3.0/1.0/2.0), zeroes three slots, sets low/mid/high aggression baselines (0.5/1.0/1.3) and configuration integers (1/104/52/3), opens the AI database file path (with a dword_7CE608/byte_5EA438 fallback source), then interpolates a difficulty-scaled output into this[70] from dword_7D01A0. Called once from Game_Init (0x0042D6B0).
    // GUARD: Guard on StringSplitLoop(2, aDDevF119992002_14, 2022); when it returns nonzero the init proceeds to the log-entry step. [callee:0x004D7A50, global:0x005BE41C, source:raw]
    // CALL: When the split guard passes, write an entry trace via DebugLogWrite(&dword_8AD25C, aEnteredAidatab). [callee:0x004D7AA0, global:0x008AD25C, global:0x005BE6A8, source:raw]
    // LOOP: Loop v2 from 0 while v2 < 3, writing this[v2 + 79] with 3.0 on the first iteration and the prior index value (1.0, 2.0) afterwards, seeding the three track-position speed-curve slots starting at offset 0x13C. [source:raw]
    // ASSIGNMENT: Zero the three slots this[76], this[77], this[78] (offsets 0x130, 0x134, 0x138). [field:this:0x00000130, field:this:0x00000134, field:this:0x00000138, source:raw]
    // ASSIGNMENT: Set the difficulty aggression baselines this[71] = 0.5 (0x11C), this[72] = 1.0 (0x120), this[73] = 1.3 (0x124). [field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, source:raw]
    // ASSIGNMENT: Write configuration integers as dword indices: this[87] = 1 (0x15C), this[88] = 104 (0x160), this[89] = 52 (0x164), this[90] = 3 (0x168). [field:this:0x0000015C, field:this:0x00000160, field:this:0x00000164, field:this:0x00000168, source:raw]
    // ASSIGNMENT: Set base aggressiveness multiplier *this = 4.75 (0x0) and secondary multiplier this[1] = 4.3125 (0x4). [field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the sentinel this[82] = -1.0 (offset 0x148). [field:this:0x00000148, source:raw]
    // CALL: Guard StringCopyWithValidation(this + 6, 256, aAiDatabaseFile, 0); on success copy the configured AI database file name into the file buffer. [callee:0x004C58A0, global:0x005BE694, source:raw]
    // CALL: Copy the AI database file path: source is dword_7CE608 when set, otherwise the fallback byte_5EA438, written via sub_587DD0(this + 6, source, 200). [callee:0x00587DD0, global:0x007CE608, global:0x005EA438, source:raw]
    // CALL: Open the database file with sub_587DB0(this + 6, aRt); when it returns nonzero, process it via sub_402690(this, v5) and close with FileCloseWithLock(v6). [callee:0x00587DB0, global:0x005BE690, callee:0x00402690, callee:0x00587D02, source:raw]
    // CALCULATION: Interpolate the difficulty-scaled output into this[70] (0x118): when dword_7D01A0 > 100 blend between this[72] and this[73] with result = dword_7D01A0 - 100 scaled by 0.05, otherwise blend between this[71] and this[72] with result = dword_7D01A0 - 70 scaled by 0.0333. [global:0x007D01A0, field:this:0x00000118, field:this:0x0000011C, field:this:0x00000120, field:this:0x00000124, source:raw]
    // CALL: Invoked from Game_Init (0x0042D6B0) during game initialization. [caller:0x0042D6B0]
    // RETURN: Return the difficulty difference value (dword_7D01A0 minus 100 or 70). [function:0x004040A0, source:raw]

    // Conservative worker pseudocode:
    //   int AIDatabase_Init(float *this) {
    //     if (StringSplitLoop(2, aDDevF119992002_14, 2022))
    //       DebugLogWrite(&dword_8AD25C, aEnteredAidatab);
    //     this[79] = 3.0; this[80] = 1.0; this[81] = 2.0;
    //     this[76] = 0.0; this[77] = 0.0; this[78] = 0.0;
    //     this[71] = 0.5; this[72] = 1.0; this[73] = 1.3;
    //     *((_DWORD *)this + 87) = 1;
    //     *((_DWORD *)this + 88) = 104;
    //     *((_DWORD *)this + 89) = 52;
    //     *((_DWORD *)this + 90) = 3;
    //     *this = 4.75; this[1] = 4.3125; this[82] = -1.0;
    //     if (StringCopyWithValidation(this + 6, 256, aAiDatabaseFile, 0)) {
    //       src = dword_7CE608 ? dword_7CE608 : byte_5EA438;
    //       sub_587DD0(this + 6, src, 200);
    //     }
    //     v5 = sub_587DB0(this + 6, aRt);
    //     if (v5) { sub_402690(this, v5); FileCloseWithLock(v5); }
    //     result = (dword_7D01A0 > 100) ? (dword_7D01A0 - 100) : (dword_7D01A0 - 70);
    //     this[70] = blend(this[71], this[72], this[73], result);
    //     return result;
    //   }
    // UNRESOLVED: flt_59E43C, flt_59E448, flt_59E474 and flt_59E478 are read per the deterministic fact table but do not appear in the decompiled body; likely constant-pool values feeding the difficulty interpolation path.
    // UNRESOLVED: unk_8AC368 is read per the deterministic fact table but is absent from the decompiled body.
    // UNRESOLVED: The loop writes this[79..81] (offset 0x13C onward), which fall outside the packet's deterministic field list; the packet fields 0x130/0x134/0x138 correspond to the zeroed this[76..78], not the curve seeds.
}
