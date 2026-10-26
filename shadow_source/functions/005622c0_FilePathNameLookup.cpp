// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005622C0
// Canonical corpus name: FilePathNameLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePathNameLookup_005622c0.c

void UnknownObject::FilePathNameLookup()
{
    // Dispatches a path/request string a2 against a file-system context. When the first byte of a2 is ';' (ASCII 59, packet guard) the request is delegated to a virtual handler: the context object (a1, defaulting to off_5E4DFC when null) is dereferenced at dword index 63 and, if non-null, called with (a2, a3, a4). Otherwise the context counters are bumped (dword index 55 incremented, dword index 56 reset, flag byte at 232 cleared), and the function walks the entry table off_5E4CD4 calling sub_562530 on each of the 9 entries; a hit selects one of several buffer-init/acumulate routines on the 1397-byte buf stack buffer, then sub_5629B0 composes the final result from buf and the v15 byte buffer. Called by NetworkPacketReceive.
    // GUARD: Dispatch guard: when the first byte of a2 equals 59 (';') the request takes the virtual-handler path instead of the table scan (packet guard on the context field) [guard:0, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch: the handler pointer is read from the context at dword index 63 (the context is off_5E4DFC when a1 is null) and, when non-null, called with (a2, a3, a4), its result returned directly [global:0x005E4DFC, source:raw]
    // STATE_TRANSITION: Context counter update on the table-scan path: increment the counter at context dword index 55, reset dword index 56 to 0, and clear the flag byte at context offset 232 when it was set [global:0x005E4DFC, source:raw]
    // ASSIGNMENT: Stack buffer initialization: both buf and v15 are seeded with the first character of the default path byte_5EA438, then zero-filled (buf after byte 1, 1397-byte region; v15 after byte 1, 255 bytes) [global:0x005EA438, source:raw]
    // LOOP: Entry-table scan: walk the off_5E4CD4 table for 9 entries (index 0..8), calling sub_562530(a2, *v10) per entry to test for a match [callee:0x00562530, global:0x005E4CD4, source:raw]
    // CALCULATION: Hit dispatch switch on the entry index: cases 0-5 run combinations of the zero-init/virtual-call buffer routines (StackBufferZeroInitWithCallback, StackBufferZeroInitWithVTableCall, BufferZeroInitWithVirtualMethodCall, LargeStackStructZeroInitWithVtableCall) with sub_562610 interleaved for case 5, accumulating content into buf [callee:0x00562610, callee:0x005626B0, callee:0x00562830, callee:0x00562890, callee:0x005628F0, source:raw]
    // CALCULATION: Remaining hit cases: case 6 passes the match to sub_562950(buf, v11); case 7 copies the matched string bytes from v11 into the v15 buffer [callee:0x00562950, source:raw]
    // CALL: Compose result: return sub_5629B0(buf, v15) which finalizes the accumulated buffers into the output; on the ';' path with a null handler the function returns 0 [callee:0x005629B0, source:raw]
    // RETURN: Fall-through return of 0 when the ';' path has no handler installed [source:raw]
    // CALL: Invoked by NetworkPacketReceive (00561E30), consistent with the dispatch role of this function [caller:0x00561E30, source:raw]

    // Conservative worker pseudocode:
    //   v4 = a1 ? a1 : off_5E4DFC;
    //   buf[0] = v15[0] = byte_5EA438[0];
    //   memset(&buf[1], 0, 0x574); memset(&v15[1], 0, 255);
    //   if (*a2 == 59) {
    //     v7 = *((DWORD*)v4 + 63);
    //     if (v7) return v7(a2, a3, a4);
    //   } else {
    //     *((DWORD*)v4 + 56) = 0;
    //     *((DWORD*)v4 + 55) = *((DWORD*)v4 + 55) + 1;
    //     if (*((BYTE*)v4 + 232) > 0) *((BYTE*)v4 + 232) = 0;
    //     for (idx = 0; idx <= 8; ++idx) {
    //       match = sub_562530(a2, *(off_5E4CD4 + idx));
    //       if (match) { switch (idx) {
    //         case 0: StackBufferZeroInitWithCallback(buf); break;
    //         case 1: StackBufferZeroInitWithVTableCall(buf); break;
    //         case 2: BufferZeroInitWithVirtualMethodCall(buf); break;
    //         case 3: LargeStackStructZeroInitWithVtableCall(buf); break;
    //         case 4: all four routines; break;
    //         case 5: callback; sub_562610; vtable; sub_562610; virtual; sub_562610; large; break;
    //         case 6: sub_562950(buf, match); break;
    //         case 7: copy string bytes from match into v15; break;
    //       } }
    //     }
    //     return sub_5629B0(buf, v15);
    //   }
    //   return 0;
    // UNRESOLVED: Global jpt_562391 (0x0056250C) is flagged by packet facts as the jump table for the dispatch switch but never appears in the raw decompiled source; its role is unverifiable here
    // UNRESOLVED: The context counter fields at dword index 55 / 56 and flag byte at offset 232 are accessed through v4 (a1 or off_5E4DFC) with no field-level evidence; their semantics (call counters, state flags) are inferred only
    // UNRESOLVED: The exact meaning of each case-0..7 buffer routine and how sub_5629B0 combines buf and v15 is not documented in this packet
}
