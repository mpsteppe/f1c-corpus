// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8B20
// Canonical corpus name: Sound_Restart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Sound_Restart_004c8b20.c

void UnknownObject::Sound_Restart()
{
    // Sound subsystem restart routine invoked on game restart. First calls StringSplitLoop(2, aDDevF119992002_24, 694); if that returns non-zero it writes the 'entered sound restart' debug message to the buffer global dword_8AD25C via DebugLogWrite. It then resets the virtual dispatch state on the this context, zeros the scene-camera parameter global flt_8AC4B0 via FieldZero4, and finally reinitializes the audio buffer from flt_5EA618, returning that call's result.
    // GUARD: Condition on StringSplitLoop(2, aDDevF119992002_24, 694) returning non-zero. [callee:0x004D7A50, global:0x005D3398, source:raw]
    // CALL: Log the 'entered sound restart' message aEnteredSoundRe through DebugLogWrite into the buffer global dword_8AD25C. [callee:0x004D7AA0, global:0x008AD25C, global:0x005D33F0, source:raw]
    // CALL: Reset the virtual dispatch state on the sound this context. [callee:0x004C8630, source:raw]
    // CALL: Zero the 4-byte global flt_8AC4B0 (scene camera parameter). [callee:0x004C7DD0, global:0x008AC4B0, source:raw]
    // CALL: Final call reinitializes the audio buffer from the global flt_5EA618 (the callee address is not present in the packet callee facts). [global:0x005EA618, source:raw]
    // RETURN: Return the result of the buffer reinitialization call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C8B20(void *this) {
    //     if (StringSplitLoop(2, aDDevF119992002_24, 694))
    //       DebugLogWrite(&dword_8AD25C, aEnteredSoundRe);
    //     VirtualDispatchStateReset(this);
    //     FieldZero4(&flt_8AC4B0);
    //     return <buffer-init-callee>(flt_5EA618);
    //   }
    // UNRESOLVED: The final buffer-reinitialization callee is named only in the raw source text and has no address in the packet callee facts; its identity and signature are unconfirmed.
    // UNRESOLVED: Meaning of the StringSplitLoop arguments (2, aDDevF119992002_24, 694) and why its result gates only the debug log is unresolved.
    // UNRESOLVED: Identity of the this sound object is unknown (no fields were recovered).
}
