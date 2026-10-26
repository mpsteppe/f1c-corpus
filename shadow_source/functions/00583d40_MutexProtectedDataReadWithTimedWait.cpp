// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583D40
// Canonical corpus name: MutexProtectedDataReadWithTimedWait
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedDataReadWithTimedWait_00583d40.c

void UnknownObject::MutexProtectedDataReadWithTimedWait()
{
    // Reads a mutex-protected byte from a slot record at a1 + 40*a2 (byte value at +12, mutex handle at +16, wait timeout in ms at +20). Acquires the mutex via WaitForSingleObject with the per-slot timeout; when the wait returns 0 (signaled) or 128 (WAIT_TIMEOUT) the protected byte is read, then the mutex is re-loaded from +16 and released via ReleaseMutex. Returns the byte read. Called by StartAddress (0x00583D90).
    // CALCULATION: Record addressing: v2 = a1 + 40*a2 + 12 locates the protected byte member; the mutex handle sits at +16 and the wait timeout (ms) at +20 of the same record [source:raw]
    // GUARD: Data access is gated: when the mutex handle at +16 is null, or WaitForSingleObject returns neither 0 (WAIT_OBJECT_0) nor 128 (WAIT_TIMEOUT), the read pointer v5 is set to null instead of the record address [source:raw]
    // CALL: WaitForSingleObject(v3, *(DWORD*)(a1 + 40*a2 + 20)) acquires the per-slot mutex with the record's own timeout; import resolved via IAT slot 0x0059E1A0 [global:0x0059E1A0, source:raw]
    // ASSIGNMENT: The mutex handle is reloaded from +16 (v2+4) immediately before release so the same handle is unlocked [source:raw]
    // CALL: ReleaseMutex(v6) unlocks the mutex when the reloaded handle is non-null; import resolved via IAT slot 0x0059E1A4 [global:0x0059E1A4, source:raw]
    // RETURN: Returns the byte v7 read through v5, i.e. the mutex-protected byte at record offset +12 [function:0x00583D40, source:raw]
    // CALL: Invoked by StartAddress (0x00583D90) as the guarded data read inside that worker-style routine [caller:0x00583D90]

    // Conservative worker pseudocode:
    //   v2 = a1 + 40*a2 + 12;
    //   v3 = *(void **)(a1 + 40*a2 + 16);
    //   if (v3 && ((v4 = WaitForSingleObject(v3, *(DWORD *)(a1 + 40*a2 + 20))) == 0 || v4 == 128))
    //       v5 = (char *)v2;
    //   else
    //       v5 = 0;
    //   v6 = *(void **)(v2 + 4);
    //   v7 = *v5;
    //   if (v6)
    //       ReleaseMutex(v6);
    //   return v7;
    // UNRESOLVED: When the mutex is null or the wait fails, v5 is null yet the decompiled body reads through it; the original guard that avoids that read path is not visible in the raw source
    // UNRESOLVED: The meaning of the protected byte at +12 and the enclosing 40-byte record layout (what array a1/a2 selects) is unknown
    // UNRESOLVED: Why WAIT_TIMEOUT (128) also authorizes the read is unexplained; the consumer's contract for a timed-out read is unknown
}
