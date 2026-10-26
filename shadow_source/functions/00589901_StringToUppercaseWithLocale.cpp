// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589901
// Canonical corpus name: sub_589901
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589901_00589901.c

void UnknownObject::StringToUppercaseWithLocale()
{
    // Locale-aware uppercase string normalization on a null-terminated ASCII string lpSrcStr, returning the original pointer. When the global locale handle dword_8D3F38 is set: guards via InterlockedIncrement/InterlockedDecrement of the dword_8D5A5C reference counter, enters critical section 19 (CriticalSectionLazyInitEnter) when dword_8D5A58 is set, queries the converted size with sub_591FA1(locale, 0x200, src, -1, 0, 0, 0, 1), allocates a buffer with MallocWrapperForNhMalloc, re-runs sub_591FA1 into that buffer and, on success, stores the result via sub_58FCA0(lpSrcStr); then leaves critical section 19 / decrements the counter and passes the buffer to sub_58AA6F, returning lpSrcStr. When the locale path is not taken, performs a plain in-place ASCII uppercase loop: every char in the range [97, 122] is reduced by 32. A heavily used string-normalization utility with many callers.
    // GUARD: lpMem = 0; if dword_8D3F38 (locale handle) is non-null, take the locale-aware path. [global:0x008D3F38]
    // CALL: Enter the guarded region: InterlockedIncrement(&dword_8D5A5C); if dword_8D5A58 is set, InterlockedDecrement(&dword_8D5A5C), CriticalSectionLazyInitEnter(19) and v10 = 1; otherwise v10 = 0. [global:0x0059E238, global:0x008D5A5C, global:0x008D5A58, global:0x0059E234, callee:0x0058DFEA]
    // CALL: If dword_8D3F38 still set: v6 = sub_591FA1(dword_8D3F38, 0x200, lpSrcStr, -1, 0, 0, 0, 1) queries the required converted size. [callee:0x00591FA1, global:0x008D3F38]
    // CALL: If v6 non-zero: v8 = MallocWrapperForNhMalloc(v6), lpMem = v8; if the buffer was allocated and the second sub_591FA1(dword_8D3F38, 0x200, lpSrcStr, -1, v8, v7, 0, 1) fill succeeds, store the conversion via sub_58FCA0(lpSrcStr). [callee:0x0058A935, callee:0x00591FA1, callee:0x0058FCA0]
    // CALL: Leave the guarded region: if v10, CritSectLeave(19); otherwise InterlockedDecrement(&dword_8D5A5C). [callee:0x0058E04B, global:0x0059E234, global:0x008D5A5C]
    // CALL: sub_58AA6F(lpMem) consumes the converted buffer, then the function returns lpSrcStr. [callee:0x0058AA6F]
    // LOOP: Fallback ASCII uppercase loop (used when the locale path is not taken): for each char, if it is >= 97 and <= 122, subtract 32 to uppercase it in place. [guard:0, source:raw]
    // RETURN: Return the original lpSrcStr pointer in all paths. [source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8D3F38) {
    //     InterlockedIncrement(&dword_8D5A5C);
    //     if (dword_8D5A58) { InterlockedDecrement(&dword_8D5A5C); CriticalSectionLazyInitEnter(19); inCrit = 1; } else inCrit = 0;
    //     if (dword_8D3F38) {
    //       n = sub_591FA1(dword_8D3F38, 0x200, lpSrcStr, -1, 0, 0, 0, 1);
    //       if (n) { lpMem = MallocWrapperForNhMalloc(n); if (lpMem && sub_591FA1(dword_8D3F38, 0x200, lpSrcStr, -1, lpMem, n, 0, 1)) sub_58FCA0(lpSrcStr); }
    //       if (inCrit) CritSectLeave(19); else InterlockedDecrement(&dword_8D5A5C);
    //       sub_58AA6F(lpMem);
    //       return lpSrcStr;
    //     }
    //   }
    //   for (p = lpSrcStr; *p; p++) if (*p >= 97 && *p <= 122) *p -= 32;
    //   return lpSrcStr;
    // UNRESOLVED: sub_591FA1 (size query + fill, code page 0x200) and sub_58FCA0/sub_58AA6F (result storage/registry consumption) semantics are not evidenced beyond their signatures here.
    // UNRESOLVED: The locale path returns the original lpSrcStr while the uppercased copy is delivered through sub_58AA6F(lpMem); the caller-visible contract of that return is ambiguous without caller context.
    // UNRESOLVED: Critical section id 19 and the dword_8D5A58 latch meaning are not evidenced by this packet.
    // UNRESOLVED: The this+0x0 field of the packet maps to the loop's per-char guard (guard:0) rather than a struct member; the extracted field reference has no object-level meaning here.
}
