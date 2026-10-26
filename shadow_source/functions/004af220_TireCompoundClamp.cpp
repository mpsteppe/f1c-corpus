// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004AF220
// Canonical corpus name: TireCompoundClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireCompoundClamp_004af220.c

void UnknownObject::TireCompoundClamp()
{
    // Selects and clamps a tire compound setting. Reads the compound mode selector at this+0x1B34 (dword index 1741) and switches 1-4: each case writes a compound value (12/14/16/16) into this+0xD98 (index 870) and a compound index (0/1/2/3) into this+0x1170 (index 1116), clamping both against per-object min/max bounds (0xD98 to [0xDA0, 0xDA4], 0x1170 to [0x1178, 0x117C]). Returns mode-1; any mode outside 1-4 returns immediately with no state change.
    // CALCULATION: Compute result = this[1741] - 1 from the compound mode selector at this+0x1B34. [field:this:0x00001B34, source:raw]
    // GUARD: Switch on the compound mode selector at this+0x1B34 with cases 1-4; any other value hits the default and returns immediately with no field writes. [field:this:0x00001B34, source:raw]
    // ASSIGNMENT: Case 1: write 12 to compound value this+0xD98, clamp it to [0xDA0, 0xDA4], and set compound index this+0x1170 to 0. [field:this:0x00000D98, field:this:0x00000DA0, field:this:0x00000DA4, field:this:0x00001170, source:raw]
    // ASSIGNMENT: Case 2: write 14 to compound value this+0xD98, clamp it to [0xDA0, 0xDA4], and set compound index this+0x1170 to 1. [field:this:0x00000D98, field:this:0x00000DA0, field:this:0x00000DA4, field:this:0x00001170, source:raw]
    // ASSIGNMENT: Case 3: write 16 to compound value this+0xD98, clamp it to [0xDA0, 0xDA4], and set compound index this+0x1170 to 2. [field:this:0x00000D98, field:this:0x00000DA0, field:this:0x00000DA4, field:this:0x00001170, source:raw]
    // ASSIGNMENT: Case 4: write 16 to compound value this+0xD98, clamp it to [0xDA0, 0xDA4], and set compound index this+0x1170 to 3. [field:this:0x00000D98, field:this:0x00000DA0, field:this:0x00000DA4, field:this:0x00001170, source:raw]
    // ASSIGNMENT: Shared tail (LABEL_22) for cases 1-4: clamp compound index this+0x1170 to the [0x1178, 0x117C] min/max bounds. [field:this:0x00001170, field:this:0x00001178, field:this:0x0000117C, source:raw]
    // CALL: The switch dispatches through the jump table at 0x004AF384 (jpt_4AF231). [global:0x004AF384, source:raw]
    // RETURN: Invoked from sub_472510 and TrackEnvironmentSelect; returns the unmodified result on unhandled modes and after successful clamping. [caller:0x00472510, caller:0x004ADE20, function:0x004AF220, source:raw]

    // Conservative worker pseudocode:
    //   int TireCompoundClamp(int this) {
    //     int mode = *(int*)(this + 0x1B34);
    //     int result = mode - 1;
    //     int min_v = *(int*)(this + 0xDA0), max_v = *(int*)(this + 0xDA4);
    //     int min_i = *(int*)(this + 0x1178), max_i = *(int*)(this + 0x117C);
    //     switch (mode) {
    //       case 1: *(int*)(this + 0xD98) = 12; *(int*)(this + 0x1170) = 0; break;
    //       case 2: *(int*)(this + 0xD98) = 14; *(int*)(this + 0x1170) = 1; break;
    //       case 3: *(int*)(this + 0xD98) = 16; *(int*)(this + 0x1170) = 2; break;
    //       case 4: *(int*)(this + 0xD98) = 16; *(int*)(this + 0x1170) = 3; break;
    //       default: return result;
    //     }
    //     *(int*)(this + 0xD98) = clamp(*(int*)(this + 0xD98), min_v, max_v);
    //     *(int*)(this + 0x1170) = clamp(*(int*)(this + 0x1170), min_i, max_i);
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the compound constants 12/14/16 and indexes 0-3 (tire compound presets) is structural; the caller at TrackEnvironmentSelect consumes them, but their semantic mapping is not confirmed here.
    // UNRESOLVED: The min/max bounds at 0xDA0/0xDA4 and 0x1178/0x117C are per-object values written elsewhere; their source is not recoverable from this function alone.
}
