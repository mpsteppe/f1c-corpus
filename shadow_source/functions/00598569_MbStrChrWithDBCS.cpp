// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598569
// Canonical corpus name: sub_598569
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_598569_00598569.c

void UnknownObject::MbStrChrWithDBCS()
{
    // Multibyte-aware character search. When the code-page tables are not initialized (dword_8D46CC == 0) it delegates to the simple fallback sub_589DB0. Otherwise, under critical section 25, it iterates the input string: bytes flagged as DBCS lead bytes (bit 4 of byte_8D47E1) are combined with their trail byte into a 16-bit value compared against a2, while ordinary bytes are compared directly. Returns a pointer into the string at the match, or 0 when not found.
    // GUARD: If dword_8D46CC is zero the code-page tables are uninitialized and the function takes the fallback path. [global:0x008D46CC, source:raw]
    // CALL: Delegate to the simple fallback search sub_589DB0(a1, a2) when dword_8D46CC is zero. [callee:0x00589DB0, source:raw]
    // CALL: Enter critical section 25 via CriticalSectionLazyInitEnter before scanning. [callee:0x0058DFEA, source:raw]
    // LOOP: Iterate the input string byte by byte, reading the current byte from offset 0 of the scanned buffer. [field:this:0x00000000, source:raw]
    // GUARD: For a DBCS lead byte (bit 4 set in byte_8D47E1), read the following trail byte; if the trail byte is zero the string ends, so leave the critical section and return 0. [global:0x008D47E1, source:raw]
    // CALCULATION: Combine lead and trail bytes into a 16-bit value (trail | (lead << 8)) and compare it against a2; on match return i - 1 after leaving the critical section. [global:0x008D47E1, source:raw]
    // GUARD: For a non-lead byte, compare the single byte against a2 and break out of the loop on a match. [global:0x008D47E1, source:raw]
    // CALL: Leave critical section 25 via CritSectLeave before every return path. [callee:0x0058E04B, source:raw]
    // RETURN: Return the last examined byte i when it equals a2, otherwise return 0 (not found). [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_598569(char *a1, int a2) {
    //     if (!dword_8D46CC) return sub_589DB0(a1, a2);
    //     CriticalSectionLazyInitEnter(25);
    //     for (char *i = a1; *i; ++i) {
    //       unsigned __int8 lead = *i;
    //       if (byte_8D47E1[lead] & 4) {
    //         unsigned __int8 trail = *++i;
    //         if (!trail) { CritSectLeave(25); return 0; }
    //         if (a2 == (trail | (lead << 8))) { CritSectLeave(25); return i - 1; }
    //       } else if (a2 == *i) {
    //         break;
    //       }
    //     }
    //     CritSectLeave(25);
    //     return (lead == a2) ? i : 0;
    //   }
    // UNRESOLVED: The concrete values and layout of the byte_8D47E1 classification table (bit 4 as the DBCS lead-byte flag) are DERIVED from static analysis, not proven.
    // UNRESOLVED: The meaning of the critical-section index 25 and the init gate behind CriticalSectionLazyInitEnter are not grounded by this function alone.
    // UNRESOLVED: The single caller sub_598323 is known statically but its use of the returned pointer is outside this function.
}
