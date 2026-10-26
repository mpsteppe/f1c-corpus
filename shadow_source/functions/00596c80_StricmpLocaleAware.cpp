// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596C80
// Canonical corpus name: sub_596C80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596C80_00596c80.c

void UnknownObject::StricmpLocaleAware()
{
    // Case-insensitive string comparison with a maximum compare length a3. When a3 is zero the function returns 0 immediately. When the global locale flag is set it takes a locale-aware path that folds each character pair through sub_58B4D4 (locale character conversion) under a reference-counted critical section (entered via CriticalSectionLazyInitEnter(19) only when another thread is inside, otherwise a plain interlocked counter is kept); otherwise it uses an ASCII fast path that manually lowercases 'A'..'Z' by adding 32. Both paths stop at a null terminator in either string and return -1/0/1 according to the first differing character pair, comparing against the remaining length countdown.
    // GUARD: Guard on a3: when the maximum compare length is zero, skip all work and return a3 (0). [source:raw]
    // GUARD: Branch on the global locale-thread-safe flag: non-zero selects the locale-aware path, zero selects the ASCII fast path. [global:0x008D3F30, source:raw]
    // ASSIGNMENT: Locale-aware path: increment the global reference counter dword_8D5A5C with an interlocked add, then test whether the thread-count global dword_8D5A58 is positive. [global:0x008D5A5C, global:0x008D5A58, source:raw]
    // GUARD: When dword_8D5A58 > 0 another thread is inside: release the interlocked counter, enter critical section 19 and remember that the section must later be left (v16 = 1). Otherwise keep the interlocked counter and do not touch the critical section (v16 = 0). [global:0x008D5A5C, global:0x008D5A58, source:raw]
    // CALL: CriticalSectionLazyInitEnter(19) acquires the shared critical section used to serialize the locale-aware comparison. [callee:0x0058DFEA, source:raw]
    // LOOP: Iterate the two input buffers in parallel, reading one byte from each (field 0 of the first input, i.e. *a1); stop when either byte is a null terminator. [field:this:0x00000000, source:raw]
    // CALL: Fold both characters through sub_58B4D4 (locale-aware character conversion) before comparing. [callee:0x0058B4D4, source:raw]
    // CALCULATION: Compare the folded characters; on mismatch return -1 when the first is less than the second and 1 when greater. On match decrement the remaining-length counter and continue until the length runs out (v15 becomes 1) or a null terminator appears. [source:raw]
    // RETURN: When the loop exhausts the compare length with all characters equal, return 0. [source:raw]
    // CALL: If the critical section was entered (v16), leave critical section 19 with CritSectLeave(19) and return the saved result. [callee:0x0058E04B, source:raw]
    // ASSIGNMENT: If the critical section was not entered, release the interlocked reference counter dword_8D5A5C with a decrement instead. [global:0x008D5A5C, source:raw]
    // LOOP: ASCII fast path: read one byte from each input, stop at a null terminator, and advance both pointers. [field:this:0x00000000, source:raw]
    // CALCULATION: Manually lowercase each byte in the range 0x41..0x5A ('A'..'Z') by adding 32, then compare the pair; on mismatch return -1 or 1, on match decrement the length counter and continue. [source:raw]
    // RETURN: When the fast-path length counter runs out with all characters equal, return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int StricmpLocaleAware(const char *a1, const char *a2, int maxLen) {
    //     if (!maxLen) return 0;
    //     if (dword_8D3F30) {
    //       InterlockedIncrement(&dword_8D5A5C);
    //       int v16 = 0;
    //       if (dword_8D5A58 > 0) { InterlockedDecrement(&dword_8D5A5C); CriticalSectionLazyInitEnter(19); v16 = 1; }
    //       int len = maxLen;
    //       do {
    //         int c1 = *a1, c2 = *a2;
    //         if (!c1 || !c2) break;
    //         ++a1; ++a2;
    //         c2 = sub_58B4D4(c2); c1 = sub_58B4D4(c1);
    //         if (c1 != c2) { int r = (c1 < c2) ? -1 : 1; goto out; }
    //         len = len - 1;
    //       } while (len != 1);
    //       { int r = 0; goto out; }
    //     out:
    //       if (v16) { int r2 = r; CritSectLeave(19); return r2; }
    //       InterlockedDecrement(&dword_8D5A5C);
    //       return r;
    //     } else {
    //       int len = maxLen;
    //       do {
    //         int c1 = *a1, c2 = *a2;
    //         if (!c1 || !c2) break;
    //         ++a1; ++a2;
    //         if (c1 >= 0x41 && c1 <= 0x5A) c1 += 32;
    //         if (c2 >= 0x41 && c2 <= 0x5A) c2 += 32;
    //         if (c1 != c2) return (c1 < c2) ? -1 : 1;
    //         --len;
    //       } while (len);
    //       return 0;
    //     }
    //   }
    // UNRESOLVED: Identity and exact contract of the two caller-side string buffers (a1, a2) is not stated in this packet; caller 0047f300 (SceneFilenameMatchAgainstBasePath) suggests filename/base-path usage.
    // UNRESOLVED: dword_8D5A58 is read as a thread/reference count gate but its writer is external to this function.
    // UNRESOLVED: Whether the ASCII fast path uses the same 19-id critical section semantics is moot because it never calls CritSectLeave; both paths are mutually exclusive via the dword_8D3F30 flag.
}
