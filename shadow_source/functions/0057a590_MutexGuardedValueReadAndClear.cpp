// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A590
// Canonical corpus name: sub_57A590
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57A590_0057a590.c

void UnknownObject::MutexGuardedValueReadAndClear()
{
    // Thread-safe read-and-clear of a shared integer value guarded by a mutex with a 5 ms wait timeout. On a successful wait it reads the value at obj+0x5C4 into the result and clears it to 0, optionally shifts the string at obj+0x5C8 left by a2 bytes (when a2 is non-zero), always zeroes the string's first byte, and releases the mutex held at obj+0x618. Returns the read value, or 0 when the wait times out or fails.
    // ASSIGNMENT: Load the target object pointer from this+0x0 into a local base. [field:this:0x00000000]
    // ASSIGNMENT: Initialize the result value to 0 before the wait. [source:raw]
    // CALL: Call WaitForSingleObject on the mutex handle at obj+0x618 with a 5 ms timeout. [field:obj:0x00000618]
    // GUARD: Guard: proceed only when the wait result is neither WAIT_TIMEOUT (258) nor WAIT_FAILED (-1); otherwise skip the whole read/clear section and return 0. [source:raw]
    // ASSIGNMENT: Read the shared integer at obj+0x5C4 into the result value, then write 0 back to obj+0x5C4. [field:obj:0x000005C4]
    // GUARD: Guard: when the shift amount a2 is non-zero, shift the string buffer at obj+0x5C8 by a2 bytes. [field:obj:0x000005C8]
    // LOOP: Do-while loop copying the null-terminated string at obj+0x5C8 forward by a2 bytes, stopping when a copied null terminator is seen. [field:obj:0x000005C8]
    // ASSIGNMENT: Write 0 to the first byte of the string buffer at obj+0x5C8, truncating it unconditionally. [field:obj:0x000005C8]
    // CALL: Re-read the mutex handle at obj+0x618; if non-null, call ReleaseMutex on it. [field:obj:0x00000618]
    // RETURN: Return the value that was read from obj+0x5C4 (or 0 when the wait failed). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_57A590(int* this, int a2) {
    //     int base = *this;
    //     int result = 0;
    //     DWORD wait = WaitForSingleObject(*(HANDLE*)(base + 1560), 5);
    //     if (wait != 258 && wait != -1) {
    //       result = *(DWORD*)(base + 1476);
    //       *(DWORD*)(base + 1476) = 0;
    //       if (a2) {
    //         char* p = (char*)(base + 1480);
    //         do { char c = *p; p[a2 - (base + 1480)] = *p; ++p; } while (c);
    //       }
    //       *(BYTE*)(base + 1480) = 0;
    //       void* mutex = *(void**)(base + 1560);
    //       if (mutex) ReleaseMutex(mutex);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Purpose of shifting the string at obj+0x5C8 by a2 bytes is unknown; the offset arithmetic is deterministic but its intent (queue/name manipulation) is not proven.
    // UNRESOLVED: What writes the shared value at obj+0x5C4 and who consumes the returned value is unresolved.
    // UNRESOLVED: The string truncation at obj+0x5C8 (first byte zeroed unconditionally) vs. the optional shift interaction is not fully explained.
    // UNRESOLVED: Why the mutex is released only when the handle re-read is non-null is unresolved.
    // UNRESOLVED: Caller EnumToEnumTranslator (0x00462D30) relationship to this shared-object pattern is not established.
}
