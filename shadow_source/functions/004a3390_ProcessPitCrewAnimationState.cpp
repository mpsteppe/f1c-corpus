// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3390
// Canonical corpus name: sub_4A3390
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A3390_004a3390.c

void UnknownObject::ProcessPitCrewAnimationState()
{
    // Pit crew animation state processor. Runs once (guarded by bit 0 of this+0x0): iterates the child animation-entry array (count at this+0xC, array pointer at this+0x10, stride 120 bytes), resets each live entry's keyframe animation to time 0.0 via sub_4A2840, clears or sets a visibility/flag bit on the entry's associated widget based on the entry's active-state byte, and frees animation state resources when the entry is flagged inactive. After the loop, if global detail level dword_7CF884 >= 2 and the widget-update guard this+0x14 is non-zero, recursively updates the UI widget tree. Finally marks the executed bit.
    // GUARD: Guard on bit 0 of this+0x0: if already set (previously executed) the entire function body is skipped and only this+0xC is returned. [field:this:0x00000000]
    // GUARD: Loop guard: read entry count from this+0xC and iterate only while it is greater than zero. [field:this:0x0000000C]
    // LOOP: do-while loop over the count of entries, walking the child animation-entry array at this+0x10 with a fixed stride of 120 bytes per entry. [field:this:0x00000010]
    // ASSIGNMENT: Compute the current child entry pointer as this+0x10 base plus the loop index; read the entry's widget/flag pointer at entry+100 to test liveness. [source:raw]
    // CALL: Call sub_4A2840 on the current child entry with 0.0 to reset its keyframe animation to the start. [callee:0x004A2840]
    // GUARD: Guard on the caller flag a2 OR the child entry's active-state byte at entry+3: only entries considered active proceed to the flag update. [source:raw]
    // CALL: On the entry's associated widget pointer (entry+100), clear the visibility bit via BitClear when the entry's byte at +2 is set, otherwise set the bit via Bit12FlagSet. [callee:0x0054C190, callee:0x0054C1A0]
    // CALL: When the child entry's field at +72 is not -1 and its widget pointer at +100 is non-zero, call sub_5506A0(0, 0, 0) to clear/reset the entry's animation state resources. [callee:0x005506A0]
    // GUARD: Guard: only when global detail level dword_7CF884 is >= 2 and the widget-update guard field this+0x14 is non-zero does the recursive UI widget update run. [global:0x007CF884, field:this:0x00000014]
    // CALL: Call UIWidgetRecursiveStateUpdate(1, 0, 0) to recursively refresh UI widget tree visibility state. [callee:0x0054C1B0]
    // ASSIGNMENT: Set bit 0 of this+0x0 so the function executes only once. [field:this:0x00000000]
    // RETURN: Return the entry count this+0xC (or the result of the UI update call when it ran). [field:this:0x0000000C]

    // Conservative worker pseudocode:
    //   int sub_4A3390(CrewAnimState* s, bool force) {
    //     if (s->flags & 1) return s->entryCount;
    //     int count = s->entryCount;
    //     if (count > 0) {
    //       for (int n = 0; n < count; ++n) {
    //         Entry* e = (Entry*)((char*)s->entries + n * 120);
    //         if (e->widgetOrFlag) {
    //           sub_4A2840(e, 0.0);
    //           if (!force || e->activeByte) {
    //             if (e->byte2) BitClear(e->widgetOrFlag);
    //             else Bit12FlagSet(e->widgetOrFlag);
    //           }
    //           if (e->field72 != -1 && e->widgetOrFlag)
    //             sub_5506A0(0, 0, 0);
    //         }
    //       }
    //     }
    //     if (dword_7CF884 >= 2 && s->uiUpdateGuard)
    //       result = UIWidgetRecursiveStateUpdate(1, 0, 0);
    //     s->flags |= 1;
    //     return result;
    //   }
    // UNRESOLVED: Child-entry layout (offsets +2, +3, +72, +100 and the 120-byte stride) is present only in the raw source, not in packet field evidence; exact struct is unknown.
    // UNRESOLVED: Caller flag a2 semantics (which entries are treated as active) are inferred, not packet-confirmed.
    // UNRESOLVED: Meaning of arguments passed to sub_5506A0 and UIWidgetRecursiveStateUpdate is not established.
}
