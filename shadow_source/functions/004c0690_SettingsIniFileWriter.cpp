// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0690
// Canonical corpus name: SettingsIniFileWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SettingsIniFileWriter_004c0690.c

void UnknownObject::SettingsIniFileWriter()
{
    // Career standings ini writer (__thiscall): writes a settings/standings block into the caller-owned text buffer a2 as key-value pairs. Optionally resolves resource paths via ResourceLookupWithDualPath when a3 is nonzero. Writes the Name/VehFile/RcdFile keys, then a per-entry loop over up to 48 finish entries at this+0x18 (terminated by a negative sentinel) emitting FinishPosition/FinishPoints pairs, followed by SeasonPoints/PointsPosition/PolesTaken/OriginalGridPos/CurrentGridPos/ControlType/Active keys and a trailing word_5C30B4 separator token. Called by PlayerOpponentStateWriter (0x004C0CC0).
    // GUARD: Guard on the output buffer target a2: if *a2 is zero the whole body is skipped and 0 is returned. [source:raw]
    // GUARD: Guard on a3 (resource-path flag): when nonzero, both resource paths are resolved before the key writes. [source:raw]
    // CALL: Resolve the resource path for a3 via ResourceLookupWithDualPath when a3 is nonzero. [callee:0x00566CF0, source:raw]
    // CALL: Resolve the config/separator resource path &word_5C30B4 via ResourceLookupWithDualPath when a3 is nonzero. [callee:0x00566CF0, global:0x005C30B4, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aNameS): emit the "Name" key-value pair. [callee:0x00566C30, global:0x005D27F8, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aVehfileS): emit the "VehFile" key-value pair. [callee:0x00566C30, global:0x005D27E8, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aRcdfileS): emit the "RcdFile" key-value pair. [callee:0x00566C30, global:0x005D27D8, source:raw]
    // ASSIGNMENT: Seed the entry loop: v4 = 0 and v5 = this + 6 (this+0x18), start of the per-entry finish data array. [field:this:0x00000018, source:raw]
    // LOOP: do-while over the finish-entries array, iterating up to 48 entries; breaks early when the entry value *v5 is negative (unused-entry sentinel). [field:this:0x00000018, guard:0, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aFinishposition_0): emit the "FinishPosition" key for the current entry. [callee:0x00566C30, global:0x005D27C0, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aFinishpoints22): emit the "FinishPoints" key for the current entry. [callee:0x00566C30, global:0x005D27A8, source:raw]
    // CALCULATION: Advance through the array: ++v4 and ++v5 (v5 steps one int, i.e. 4 bytes, per iteration). [field:this:0x00000018, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aSeasonpointsD): emit the "SeasonPoints" key-value pair. [callee:0x00566C30, global:0x005D2794, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aPointsposition_0): emit the "PointsPosition" key-value pair. [callee:0x00566C30, global:0x005D2780, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aPolestakenD): emit the "PolesTaken" key-value pair. [callee:0x00566C30, global:0x005D2770, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aOriginalgridpo_0): emit the "OriginalGridPos" key-value pair. [callee:0x00566C30, global:0x005D2754, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aCurrentgridpos_0): emit the "CurrentGridPos" key-value pair. [callee:0x00566C30, global:0x005D273C, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aControltypeD): emit the "ControlType" key-value pair. [callee:0x00566C30, global:0x005D272C, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, aActiveD): emit the "Active" key-value pair. [callee:0x00566C30, global:0x005D2720, source:raw]
    // CALL: BufferWriteWithStringLengthCheck(a2, &word_5C30B4): emit the trailing config/separator token. [callee:0x00566C30, global:0x005C30B4, source:raw]
    // RETURN: Return 0 on all paths. [source:raw]
    // CALL: Invoked by PlayerOpponentStateWriter (0x004C0CC0) to write this settings/standings block. [caller:0x004C0CC0, source:raw]

    // Conservative worker pseudocode:
    //   char SettingsIniFileWriter(int* this, _DWORD* buf, int resourcePath) {
    //     if (!*buf) return 0;
    //     if (resourcePath) {
    //       ResourceLookupWithDualPath(resourcePath);
    //       ResourceLookupWithDualPath(&word_5C30B4);
    //     }
    //     BufferWriteWithStringLengthCheck(buf, aNameS);
    //     BufferWriteWithStringLengthCheck(buf, aVehfileS);
    //     BufferWriteWithStringLengthCheck(buf, aRcdfileS);
    //     int i = 0;
    //     int* entry = this + 6;
    //     do {
    //       if (*entry < 0) break;
    //       BufferWriteWithStringLengthCheck(buf, aFinishposition_0);
    //       BufferWriteWithStringLengthCheck(buf, aFinishpoints22);
    //       ++i; ++entry;
    //     } while (i < 48);
    //     BufferWriteWithStringLengthCheck(buf, aSeasonpointsD);
    //     BufferWriteWithStringLengthCheck(buf, aPointsposition_0);
    //     BufferWriteWithStringLengthCheck(buf, aPolestakenD);
    //     BufferWriteWithStringLengthCheck(buf, aOriginalgridpo_0);
    //     BufferWriteWithStringLengthCheck(buf, aCurrentgridpos_0);
    //     BufferWriteWithStringLengthCheck(buf, aControltypeD);
    //     BufferWriteWithStringLengthCheck(buf, aActiveD);
    //     BufferWriteWithStringLengthCheck(buf, &word_5C30B4);
    //     return 0;
    //   }
    // UNRESOLVED: byte_5EA438 is listed among this function's referenced globals in the packet but does not appear in the raw source; its role here is unknown.
    // UNRESOLVED: The per-entry data at this+0x18 is an int array terminated by a negative sentinel and capped at 48 entries, but the per-field meaning of each int (position vs points) is not proven by the raw source.
    // UNRESOLVED: The key-value payloads written by BufferWriteWithStringLengthCheck are read from global string constants whose full contents are not visible in the raw source.
}
