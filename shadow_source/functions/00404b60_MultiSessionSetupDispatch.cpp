// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404B60
// Canonical corpus name: sub_404B60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_404B60_00404b60.c

void UnknownObject::MultiSessionSetupDispatch()
{
    // Dispatches session-specific setup: a main-menu/bitmap guard resets the progress dword at obj+0x1C and returns; race mode (global dword_7C569C == 2) snapshots and compares five state dwords, accumulates a clamped progress value into the float at obj+0x1C, then calls RaceModeSetup when it reaches the threshold float at obj+0x18; server mode (== 5) plays a sound and dispatches audio rendering exactly once.
    // GUARD: Early return when the guard dword at object +0x20 is zero. [field:obj:0x00000020, source:raw]
    // ASSIGNMENT: Dereference the this pointer to reach the target object used for all obj field access. [field:this:0x00000000, source:raw]
    // GUARD: When the global dword_7CD8C0 is nonzero, run the bitmap/main-menu path. [global:0x007CD8C0, source:raw]
    // CALL: BitmapSpriteAccessor() returns the active sprite accessor object. [callee:0x00497980, source:raw]
    // GUARD: If the accessor is null or sub_588410(accessor, aMainMenu) matches the main-menu string, fall through to the reset path. [callee:0x00497980, callee:0x00588410, global:0x005BE708, source:raw]
    // ASSIGNMENT: Reset the dword at object +0x1C to 0 and return (main-menu/bitmap path). [field:obj:0x0000001C, source:raw]
    // GUARD: Branch on the session-type global dword_7C569C: only race mode (== 2) continues to the state-snapshot path. [global:0x007C569C, source:raw]
    // GUARD: Server path: when dword_7C569C == 5 and the byte at object +0x14 is set, play a sound. [global:0x007C569C, field:obj:0x00000014, source:raw]
    // CALL: SoundAudioPlayback(-1.0) plays the session-start sound. [callee:0x004C8650, source:raw]
    // GUARD: Only dispatch the audio render once: the byte at object +0x15 must still be 0. [field:obj:0x00000015, source:raw]
    // CALL: ConditionalSoundRenderDispatchOnParamCheck(this) renders the audio with the object as parameter. [callee:0x00404970, source:raw]
    // ASSIGNMENT: Mark the audio-dispatched byte at object +0x15 as 1. [field:obj:0x00000015, source:raw]
    // ASSIGNMENT: Snapshot the five global state dwords dword_7CB25C, dword_7CB260, dword_7CB2FC, dword_7CB300 and dword_7CB304 into a local buffer. [global:0x007CB25C, global:0x007CB260, global:0x007CB2FC, global:0x007CB300, global:0x007CB304, source:raw]
    // GUARD: Race path: compare the five global dwords against the object dwords at +0x0, +0x4, +0x8, +0xC and +0x10. [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, field:obj:0x0000000C, field:obj:0x00000010, source:raw]
    // CALCULATION: Accumulate progress: clamp dbl_8AFE90 into [0.0, 0.5] and add it to the float at object +0x1C (add 0.0 when it is negative). [global:0x008AFE90, field:obj:0x0000001C, source:raw]
    // ASSIGNMENT: When the snapshot does not match the object state, reset the float at object +0x1C to 0.0. [field:obj:0x0000001C, source:raw]
    // ASSIGNMENT: Copy the five-dword snapshot back into the object (0x14-byte copy covering object +0x0 through +0x10). [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, field:obj:0x0000000C, field:obj:0x00000010, source:raw]
    // GUARD: If the accumulated float at object +0x1C reaches the threshold float at object +0x18, trigger race-mode setup. [field:obj:0x0000001C, field:obj:0x00000018, source:raw]
    // CALL: RaceModeSetup(*this) starts the race session; the dword at object +0x1C is then reset to 0 and the function returns. [callee:0x00404890, field:obj:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   void MultiSessionSetupDispatch(void* obj) {
    //     if (obj[8] == 0) return;
    //     if (dword_7CD8C0) {
    //       if (!BitmapSpriteAccessor() || sub_588410(BitmapSpriteAccessor(), aMainMenu)) {
    //         obj[7] = 0;
    //         return;
    //       }
    //     }
    //     if (dword_7C569C != 2) {
    //       if (dword_7C569C == 5 && ((char*)obj)[0x14]) {
    //         SoundAudioPlayback(-1.0);
    //         if (!((char*)obj)[0x15]) {
    //           ConditionalSoundRenderDispatchOnParamCheck(obj);
    //           ((char*)obj)[0x15] = 1;
    //         }
    //       }
    //       return;
    //     }
    //     snap[0] = dword_7CB25C; snap[1] = dword_7CB260; snap[2] = dword_7CB2FC;
    //     snap[3] = dword_7CB300; snap[4] = dword_7CB304;
    //     if (snap matches obj[0..4]) {
    //       double v = dbl_8AFE90;
    //       if (v < 0.0) v = 0.0;
    //       else if (v > 0.5) v = 0.5;
    //       ((float*)obj)[7] += (float)v;
    //     } else {
    //       ((float*)obj)[7] = 0.0f;
    //     }
    //     memcpy(obj, snap, 0x14);
    //     if (((float*)obj)[7] >= ((float*)obj)[6]) {
    //       RaceModeSetup((int)obj);
    //       obj[7] = 0;
    //     }
    //   }
    // UNRESOLVED: flt_59E440 and flt_59E450 are listed as accessed globals but do not appear in the raw source; their role is unknown.
    // UNRESOLVED: byte_8AC494 is listed as an accessed global but does not appear in the raw source.
    // UNRESOLVED: The semantic meaning of the five compared state dwords (obj +0x0..+0x10) and the progress accumulator at obj +0x1C is not established by the packet alone.
}
