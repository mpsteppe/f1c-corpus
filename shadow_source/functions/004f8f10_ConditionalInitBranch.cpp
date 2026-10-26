// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8F10
// Canonical corpus name: ConditionalInitBranch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalInitBranch_004f8f10.c

void UnknownObject::ConditionalInitBranch()
{
    // Gated timer/counter reinitializer. When the struct guard at this+0x0 is non-null, stores the counter parameter a2 into this+0x4, resets the high-resolution timer handle read from this+0x18, and zeroes this+0xC. When a2 is zero it additionally looks up the FTFrameRate entry in the wide string list and dispatches cleanup on it. Called by VidMan_Restart and sub_4FA7E0 during video manager restarts.
    // GUARD: Proceed only when the initialization guard at this+0x0 is non-null. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the counter parameter a2 into this+0x4. [field:this:0x00000004, source:raw]
    // CALL: Reset the high-resolution timer using the timer handle read from this+0x18. [callee:0x00556440, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero the counter field at this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: When a2 is zero, take the frame-rate list cleanup branch. [source:raw]
    // CALL: Search the wide string list for the aFtframerate entry and, when found, dispatch conditional UI cleanup on it. [global:0x005D6D78, source:raw]
    // CALL: Invoked by VidMan_Restart and sub_4FA7E0. [caller:0x004FA640, caller:0x004FA7E0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4F8F10(DWORD *this, int a2) {
    //     if (*this) {
    //       int timer = this[6];
    //       this[1] = a2;
    //       HighResolutionTimerReset(timer);
    //       this[3] = 0;
    //       if (!a2) {
    //         void *entry = WideStringLinkedListSearch(aFtframerate);
    //         if (entry) ConditionalUICleanupDispatch(entry);
    //       }
    //     }
    //   }
    // UNRESOLVED: WideStringLinkedListSearch and ConditionalUICleanupDispatch appear in the raw decompiled source but have no address evidence in this packet.
    // UNRESOLVED: dword_8AFE64 (RaceTimeDelta) is flagged by packet facts but never appears in the raw decompiled source.
}
