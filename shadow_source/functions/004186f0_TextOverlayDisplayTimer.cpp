// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004186F0
// Canonical corpus name: TextOverlayDisplayTimer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextOverlayDisplayTimer_004186f0.c

void UnknownObject::TextOverlayDisplayTimer()
{
    // Per-tick update for a timed text-overlay display (commentary/subtitles). Bails out unless the session is active (dword_7D0308), the track condition is positive (flt_7CF3C8) and the init flag at this+0xAF0 is set. It steps the audio/text overlay object, manages a pending-display flag with last-display timestamp, decrements a cooldown counter, renders active overlay text through the font subsystem when a slot's elapsed time passes its threshold, then resets and compacts the slots.
    // GUARD: Guard: return 0 unless dword_7D0308 (session active), flt_7CF3C8 > 0.0 (track condition), and init flag *(this+0xAF0) are all satisfied. [global:0x007D0308, global:0x007CF3C8, field:this:0x00000AF0, source:raw]
    // CALL: If overlay object *(this+0xAF4) is non-null, invoke vfunc+0x18 (update/process) on it via its vtable (read at *(this+0xAF4)). [field:this:0x00000AF4, field:*(this+0xAF4):0x00000000, field:*(*(this+0xAF4)+0x0):0x00000018, source:raw]
    // GUARD: Guard: when object *(this+0xAF4) is non-null, vfunc+8 returns 0 (not busy) and pending flag *(this+0xAE4) is set, begin a new display cycle. [field:this:0x00000AF4, field:*(this+0xAF4):0x00000000, field:*(*(this+0xAF4)+0x0):0x00000008, field:this:0x00000AE4, source:raw]
    // ASSIGNMENT: Start display cycle: clear pending flag *(this+0xAE4)=0, set last-display timestamp *(this+0xAE8)=dbl_8AFEA8, reset active overlay id *(this+0xAEC)=-1. [field:this:0x00000AE4, field:this:0x00000AE8, field:this:0x00000AEC, global:0x008AFEA8, source:raw]
    // CALL: ArraySlotCompactionWithGapFilling(this) compacts or fills the overlay slot array before the active-slot checks. [callee:0x00418AC0, source:raw]
    // GUARD: Guard (guard:0): current slot index *(this+0x864) == -1 means no active slot; if the object is ready (vfunc+8 == 0) reset active id *(this+0xAEC)=-1 and return 0. [field:this:0x00000864, guard:0, field:this:0x00000AEC, field:this:0x00000AF4, field:*(*(this+0xAF4)+0x0):0x00000008, source:raw]
    // GUARD: Guard: return 0 when overlay object *(this+0xAF4) is null or its vfunc+8 returns non-zero (busy). [field:this:0x00000AF4, field:*(this+0xAF4):0x00000000, field:*(*(this+0xAF4)+0x0):0x00000008, source:raw]
    // CALCULATION: Cooldown handling on counter *(this+0x135C): when (dbl_8AFEA8 - last-display timestamp at *(this+0xAE8)) exceeds dword_7CF278 and the counter is positive, decrement it; otherwise no display is due. [field:this:0x0000135C, global:0x007CF278, global:0x008AFEA8, field:this:0x00000AE8, source:raw]
    // GUARD: Guard: if dbl_8AFEA8 < threshold *(this+0x86C), set active id *(this+0xAEC)=-1 and return 0 (too early to display). [global:0x008AFEA8, field:this:0x0000086C, field:this:0x00000AEC, source:raw]
    // GUARD: Guard: when elapsed time (dbl_8AFEA8 - per-slot timestamp at 4*slot+2808) is at least the per-slot threshold flt_5BF9AC[5*slot], render the overlay text for the active slot. [global:0x008AFEA8, global:0x005BF9AC, field:this:0x00000864, source:raw]
    // LOOP: Loop: initialize three temporary text-render structs in the v15 stack buffer, zeroing fields, setting sentinel -1 values and filling each string with StringCopyWithBufferRealloc(&byte_5EA438). [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: FontRenderingPrep(this+0x864, v15) prepares the rendered text for the active slot and returns the number of rendered items v8. [callee:0x00411840, field:this:0x00000864, source:raw]
    // GUARD: Guard: when v8 > 0 and the overlay object *(this+0xAF4) is non-null, render by invoking vfunc+4 with (v15, v8, 0). [field:this:0x00000AF4, field:*(this+0xAF4):0x00000000, field:*(*(this+0xAF4)+0x0):0x00000004, source:raw]
    // ASSIGNMENT: On successful render: set pending flag *(this+0xAE4)=1, active overlay id *(this+0xAEC)=slot, and slot timestamp (4*slot+2808)=dbl_8AFEA8. [field:this:0x00000AE4, field:this:0x00000AEC, global:0x008AFEA8, source:raw]
    // LOOP: Loop: free the three temporary render strings via FreeWrapper_7bcf after rendering. [callee:0x00587BCF, source:raw]
    // CALL: StructInitWithSentinelValues(this+0x864) resets the active overlay slot structure to sentinel defaults. [callee:0x004144D0, field:this:0x00000864, source:raw]
    // CALL: ArraySlotCompactionWithGapFilling(this) compacts the slot array again after the reset. [callee:0x00418AC0, source:raw]
    // RETURN: Return 0 on the various early-out paths and after the completed display/reset sequence. [source:raw]

    // Conservative worker pseudocode:
    //   int TextOverlayDisplayTimer(TextOverlaySystem* this) {
    //     if (!dword_7D0308 || flt_7CF3C8 <= 0.0 || !*(byte*)(this + 0xAF0)) return 0;
    //     if (*(this + 0xAF4)) vfunc(*(this + 0xAF4), 0x18)(*(this + 0xAF4));
    //     if (*(this + 0xAF4) && !vfunc(*(this + 0xAF4), 0x8)(*(this + 0xAF4)) && *(byte*)(this + 0xAE4)) {
    //       *(byte*)(this + 0xAE4) = 0;
    //       *(float*)(this + 0xAE8) = (float)dbl_8AFEA8;
    //       *(int*)(this + 0xAEC) = -1;
    //     }
    //     ArraySlotCompactionWithGapFilling(this);
    //     int slot = *(int*)(this + 0x864);
    //     if (slot == -1) {
    //       if (*(this + 0xAF4) && !vfunc(*(this + 0xAF4), 0x8)(*(this + 0xAF4))) *(int*)(this + 0xAEC) = -1;
    //       return 0;
    //     }
    //     if (!*(this + 0xAF4) || vfunc(*(this + 0xAF4), 0x8)(*(this + 0xAF4))) return 0;
    //     int cool = *(int*)(this + 0x135C);
    //     if (dbl_8AFEA8 - *(float*)(this + 0xAE8) > dword_7CF278) {
    //       if (cool <= 0) goto render;
    //     } else if (cool <= 0) return 0;
    //     *(int*)(this + 0x135C) = cool - 1;
    //   render:
    //     if (dbl_8AFEA8 < *(float*)(this + 0x86C)) { *(int*)(this + 0xAEC) = -1; return 0; }
    //     if (dbl_8AFEA8 - *(float*)(this + 4*slot + 2808) >= flt_5BF9AC[5*slot]) {
    //       init_three_strings(v15);
    //       int n = FontRenderingPrep((DWORD*)(this + 0x864), v15);
    //       if (n > 0 && *(this + 0xAF4)) {
    //         vfunc(*(this + 0xAF4), 0x4)(*(this + 0xAF4), v15, n, 0);
    //         *(byte*)(this + 0xAE4) = 1;
    //         *(int*)(this + 0xAEC) = slot;
    //         *(float*)(this + 4*slot + 2808) = (float)dbl_8AFEA8;
    //       }
    //       free_three_strings(v15);
    //     }
    //     StructInitWithSentinelValues((DWORD*)(this + 0x864));
    //     ArraySlotCompactionWithGapFilling(this);
    //     return 0;
    //   }
    // UNRESOLVED: The object behind this (text/overlay/commentary system) is unknown; owner left UNKNOWN.
    // UNRESOLVED: vfunc+8 semantics (0 = ready) and vfunc+4 render signature are inferred from call shape only.
    // UNRESOLVED: flt_59E440 is listed as a read global in the packet but has no direct reference in the raw source; its role is unplaced.
}
