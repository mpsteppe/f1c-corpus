// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585680
// Canonical corpus name: ThreadResumeWithMutexWait
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadResumeWithMutexWait_00585680.c

void UnknownObject::ThreadResumeWithMutexWait()
{
    // Thread-management routine that, while holding a mutex at this+0xD4, computes and applies a float to a sub-object at offset 132 via FloatAdditionReturnsFUN00568d90Param1 and FloatSetWithTimingCall, then releases the mutex. If a thread handle is stored at this+0x4, it takes a second mutex at this+0x20 and, when the suspend flag at this+0x1C is set, repeatedly resumes the thread (up to 50 attempts, sleeping an increasing delay) until its suspend count drops below 2; the flag is cleared on success and the function returns 0 on failure. Returns 1 when no thread handle is present or on success.
    // ASSIGNMENT: Initialize the success flag to 1. [source:raw]
    // ASSIGNMENT: Load the first mutex handle from this+0xD4 and compute the sub-object pointer this+132. [source:raw, field:this:0x000000D4]
    // GUARD: If the first mutex is present and WaitForSingleObject on it with timeout this+0xD8 returns 0 (signalled) or 128 (timeout), keep the sub-object pointer; otherwise use null. [source:raw, field:this:0x000000D4, field:this:0x000000D8, global:0x0059E1A0]
    // CALL: Call FloatAdditionReturnsFUN00568d90Param1 with the (possibly null) sub-object pointer to compute the float value. [source:raw, callee:0x00583680]
    // CALL: Call FloatSetWithTimingCall(sub-object, value) to apply the computed float. [source:raw, callee:0x00583660]
    // CALL: Release the first mutex via ReleaseMutex when the handle at this+132+80 (this+0xD4) is non-null. [source:raw, field:this:0x000000D4, global:0x0059E1A4]
    // GUARD: If there is no thread handle at this+0x4, return success (1) immediately. [source:raw, field:this:0x00000004]
    // GUARD: If the second mutex at this+0x20 is present, wait on it with timeout this+0x24, accepting return 0 or 128, and set the suspend-flag pointer to this+0x1C or null accordingly. [source:raw, field:this:0x00000020, field:this:0x00000024, global:0x0059E1A0]
    // GUARD: If the suspend flag at this+0x1C is set, enter the resume loop. [source:raw, field:this:0x0000001C]
    // LOOP: Loop: increment the attempt counter, then ResumeThread on the handle at this+0x4; break when the suspend count is below 2. Otherwise Sleep(attempt); if 50 attempts are reached set the success flag to 0 and abort. [source:raw, field:this:0x00000004, global:0x0059E1F8, global:0x0059E0DC]
    // ASSIGNMENT: Clear the suspend flag at this+0x1C to 0 after the resume loop breaks successfully. [source:raw, field:this:0x0000001C]
    // CALL: Release the second mutex at this+0x20 via ReleaseMutex when present. [source:raw, field:this:0x00000020, global:0x0059E1A4]
    // RETURN: Return the success flag (0 on resume failure, 1 otherwise). [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_585680(int this_) {
    //     char ok = 1;
    //     void* m1 = *(void**)(this_ + 212);
    //     char* p = 0;
    //     if (m1) {
    //       DWORD w = WaitForSingleObject(m1, *(DWORD*)(this_ + 216));
    //       if (w == 0 || w == 128) p = (char*)(this_ + 132);
    //     }
    //     float v = FloatAdditionReturnsFUN00568d90Param1(p);
    //     FloatSetWithTimingCall(p, v);
    //     void* m = *(void**)(this_ + 212);
    //     if (m) ReleaseMutex(m);
    //     if (!*(DWORD*)(this_ + 4)) return 1;
    //     void* m2 = *(void**)(this_ + 32);
    //     _BYTE* flag = 0;
    //     if (m2) {
    //       DWORD w2 = WaitForSingleObject(m2, *(DWORD*)(this_ + 36));
    //       if (w2 == 0 || w2 == 128) flag = (_BYTE*)(this_ + 28);
    //     }
    //     if (flag && *flag) {
    //       int n = 0;
    //       while (1) {
    //         ++n;
    //         if (ResumeThread(*(HANDLE*)(this_ + 4)) < 2) break;
    //         Sleep(n);
    //         if (n >= 50) { ok = 0; goto out; }
    //       }
    //       *flag = 0;
    //     }
    //   out:
    //     if (*(DWORD*)(this_ + 32)) ReleaseMutex(*(HANDLE*)(this_ + 32));
    //     return ok;
    //   }
    // UNRESOLVED: Purpose of the float computation (FloatAdditionReturnsFUN00568d90Param1 / FloatSetWithTimingCall) on the sub-object at offset 132 and why its pointer may be null; not tied to any named field of this.
    // UNRESOLVED: Semantic roles of the two mutex-protected regions (value update vs. thread resume) and why a wait timeout (128) is accepted as success on both waits.
    // UNRESOLVED: Why the first mutex handle is read through the sub-object (this+132+80) rather than directly from this.
}
