// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8CA0
// Canonical corpus name: Sound_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Sound_Post_004c8ca0.c

void UnknownObject::SoundPostCleanup()
{
    // Post-cleanup for the sound system, called from Game_Post. Optionally writes a debug-log line gated on a string-split parse, issues a guarded virtual dispatch on an init-status global, clears a scene-camera parameter, then resets entries of a sound pointer table whose value lies in (0,291): one reset via a virtual slot on a global object and up to 20 resets over a stride-8 table. Returns the last reset outcome.
    // GUARD: Call StringSplitLoop(2, aDDevF119992002_24, 760) and proceed to the debug-log write only when its byte result is non-zero. [callee:0x004D7A50, global:0x005D3398, source:raw]
    // CALL: Write the entered-sound message aEnteredSoundPo into the debug buffer dword_8AD25C via DebugLogWrite when the parse guard passes. [callee:0x004D7AA0, global:0x005D340C, global:0x008AD25C, source:raw]
    // CALL: Execute VirtualCallOnDAT008ac4c4, a virtual call on the init-status global. [callee:0x004C8180, source:raw]
    // CALL: Clear/zero the scene-camera parameter at flt_8AC4B0 via sub_4C7E80((int)&flt_8AC4B0). [callee:0x004C7E80, global:0x008AC4B0, source:raw]
    // CALL: Invoke GlobalVirtualDispatchGuarded, a guarded virtual dispatch on a global object. [callee:0x004C8A10, source:raw]
    // GUARD: If the global object dword_5EB10C is non-null and its vtable slot +8 (thiscall) returns non-zero, gate the next action on the value flt_5EA618[699] being greater than 0 and less than 291. [global:0x005EA618, source:raw]
    // CALL: When all above guards pass, call the vtable slot +12 of dword_5EB10C (thiscall) to perform the reset. [source:raw]
    // LOOP: Iterate 20 entries starting at flt_5EA618[537] with an 8-byte stride; for each entry whose first dword is greater than 0 and less than 291, call StructInitWithSentinelValues on it and store the result. [global:0x005EA618, source:raw]
    // RETURN: Return the value left by the final loop iteration (the last table entry's dword or the last StructInitWithSentinelValues result). [source:raw]

    // Conservative worker pseudocode:
    //   int SoundPostCleanup() {
    //     if (StringSplitLoop(2, aDDevF119992002_24, 760))
    //       DebugLogWrite(&dword_8AD25C, aEnteredSoundPo);
    //     VirtualCallOnDAT008ac4c4();
    //     sub_4C7E80((int)&flt_8AC4B0);
    //     GlobalVirtualDispatchGuarded();
    //     if (dword_5EB10C && vtable_slot_8(dword_5EB10C)) {
    //       if (flt_5EA618[699] > 0 && flt_5EA618[699] < 291)
    //         vtable_slot_12(dword_5EB10C);
    //     }
    //     result = 0;
    //     for (i = 0; i < 20; ++i) {
    //       p = &flt_5EA618[537 + 2*i]; /* 8-byte stride * /
    //       result = *(int*)p;
    //       if (result > 0 && result < 291)
    //         result = StructInitWithSentinelValues(p);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of dword_5EB10C and of the two virtual slots (+8 check, +12 action) invoked on it.
    // UNRESOLVED: Meaning and ownership of StructInitWithSentinelValues and the (0,291) validity window applied to table entries.
    // UNRESOLVED: Purpose of the StringSplitLoop configuration string aDDevF119992002_24 and token count 760.
    // UNRESOLVED: Semantics of the VirtualCallOnDAT008ac4c4 / GlobalVirtualDispatchGuarded pair and of the sub_4C7E80 clearing operation.
}
