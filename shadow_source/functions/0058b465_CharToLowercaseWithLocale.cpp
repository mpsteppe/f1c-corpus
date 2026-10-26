// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B465
// Canonical corpus name: sub_58B465
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B465_0058b465.c

void UnknownObject::CharToLowercaseWithLocale()
{
    // Converts one character to lowercase. When the locale flag dword_8D3F38 is non-zero it takes a thread-safe path: interlocked ref-counting on dword_8D5A5C, optionally entering a critical section when dword_8D5A58 is set, then delegates to the locale-aware conversion sub_58B4D4. Otherwise it applies a simple ASCII conversion, adding 32 for any char in 'A'..'Z' and returning the input unchanged for everything else.
    // ASSIGNMENT: Initialize v1 = 0 (critical section not yet entered). [source:raw]
    // GUARD: Branch on locale flag dword_8D3F38 (0x008D3F38): non-zero selects the locale-aware conversion path, zero selects the simple ASCII path. [global:0x008D3F38, source:raw]
    // CALL: Take a reference on the interlocked counter: InterlockedIncrement(&dword_8D5A5C) via the function pointer at 0x0059E238, mutating dword_8D5A5C (0x008D5A5C). [global:0x0059E238, global:0x008D5A5C, source:raw]
    // GUARD: Branch on the thread-refcount flag dword_8D5A58 (0x008D5A58); only when set is the critical section entered. [global:0x008D5A58, source:raw]
    // CALL: Release the reference taken above: InterlockedDecrement(&dword_8D5A5C) via the function pointer at 0x0059E234. [global:0x0059E234, global:0x008D5A5C, source:raw]
    // CALL: Enter the critical section with identifier 19 via CriticalSectionLazyInitEnter (0x0058DFEA). [callee:0x0058DFEA, source:raw]
    // ASSIGNMENT: Set v1 = 1 so the critical section is left at the end of the locale path. [source:raw]
    // CALL: Run the locale-aware lowercase conversion sub_58B4D4 (0x0058B4D4) on CharType and store the result as CharTypea. [callee:0x0058B4D4, source:raw]
    // GUARD: Balance the earlier critical-section decision: when v1 is set leave the section, otherwise release the interlocked reference again. [source:raw]
    // CALL: Leave the critical section via CritSectLeave (0x0058E04B) with identifier 19. [callee:0x0058E04B, source:raw]
    // CALL: Release the interlocked reference via InterlockedDecrement(&dword_8D5A5C) using the function pointer at 0x0059E234. [global:0x0059E234, global:0x008D5A5C, source:raw]
    // RETURN: Return CharTypea, the locale-aware conversion result. [source:raw]
    // GUARD: ASCII path guard: return CharType + 32 only when CharType is in the uppercase range 65..90 ('A'..'Z'). [source:raw]
    // CALCULATION: ASCII lowercase conversion: CharType + 32 for an uppercase input. [source:raw]
    // RETURN: Return the unchanged input CharType when it is outside the uppercase range on the ASCII path. [function:0x0058B465, source:raw]
    // CALL: Used as a shared character normalizer by sub_5645A0 (0x005645A0), sub_566810 (0x00566810) and sub_58BCCF (0x0058BCCF). [caller:0x005645A0, caller:0x00566810, caller:0x0058BCCF, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58B465(int CharType) {
    //     int v1 = 0;
    //     if (dword_8D3F38) {
    //       InterlockedIncrement(&dword_8D5A5C);
    //       if (dword_8D5A58) {
    //         InterlockedDecrement(&dword_8D5A5C);
    //         CriticalSectionLazyInitEnter(19);
    //         v1 = 1;
    //       }
    //       int CharTypea = sub_58B4D4(CharType);
    //       if (v1) CritSectLeave(19);
    //       else InterlockedDecrement(&dword_8D5A5C);
    //       return CharTypea;
    //     }
    //     if (CharType >= 65 && CharType <= 90) return CharType + 32;
    //     return CharType;
    //   }
    // UNRESOLVED: Semantics of the interlocked counter dword_8D5A5C and flag dword_8D5A58 are inferred (thread/critical-section bookkeeping) and unverified.
    // UNRESOLVED: Critical-section identifier 19 is a literal not mapped to a named resource.
    // UNRESOLVED: The exact locale-aware mapping performed by sub_58B4D4 is external to this function.
    // UNRESOLVED: Cluster-copy prelabel names sub_589A35 as a structural twin, but only this function's own raw source is relied on here.
}
