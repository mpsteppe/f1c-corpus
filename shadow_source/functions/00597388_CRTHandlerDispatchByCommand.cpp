// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597388
// Canonical corpus name: sub_597388
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_597388_00597388.c

void UnknownObject::CRTHandlerDispatchByCommand()
{
    // CRT handler dispatcher by command id (cdecl, arg a1 = command id). Maps ids 2, 15, 21, 22 to static global handler slots (dword_8D41E8, dword_8D41F4, dword_8D41EC, dword_8D41F0) and ids 4, 8, 11 to a TLS-resident handler resolved by linear array search; rejects any other id with -1. Enters the lazy-init critical section, temporarily saves/clears saved-state fields this[0x54] and this[0x58] (the latter set to 140 for id 8), zeroes exception-table entries in 12-byte steps between dword_5E7888 and dword_5E7888 + dword_5E788C for id 8, invokes the selected handler (id 8 with two arguments, others with the command id), restores the saved fields, and always leaves the critical section before returning 0.
    // GUARD: Validate the command id a1: ids 2, 15, 21 and 22 select the static global handler slots dword_8D41E8, dword_8D41F4, dword_8D41EC and dword_8D41F0 respectively; any other id returns -1. [source:raw, global:0x008D41E8, global:0x008D41F4, global:0x008D41EC, global:0x008D41F0]
    // CALL: For ids 4/8/11, retrieve the TLS array via TLSValueRetrievalWithInit() and resolve the handler slot by linear search ArrayOfStructLinearSearchByID_750a(a1, v4[20]) + 8, reading the handler function pointer from that slot (this[20] is the TLS table base at offset 0x50). [callee:0x0058E0C7, callee:0x0059750A, field:this:0x00000050]
    // STATE_TRANSITION: Set the in-critical-section flag v11 = 1 and enter the lazy-init critical section via CriticalSectionLazyInitEnter(1). [callee:0x0058DFEA]
    // GUARD: If the selected handler pointer equals the sentinel value 1, skip dispatch entirely; if it is null, leave the critical section (CritSectLeave(1)) and call sub_589CB5(3u) before continuing. [callee:0x0058E04B, callee:0x00589CB5]
    // ASSIGNMENT: For ids 4/8/11, save this[21] (offset 0x54) into v10 and clear it; for id 8 additionally save this[22] (offset 0x58) into v9 and set it to 140. [field:this:0x00000054, field:this:0x00000058]
    // LOOP: For id 8, walk the exception-table entries from dword_5E7888 up to dword_5E7888 + dword_5E788C in 12-byte steps, writing 0 at this[20] + step - 4 for each entry. [global:0x005E7888, global:0x005E788C, field:this:0x00000050]
    // ASSIGNMENT: For the static handler ids (2/15/21/22), clear the selected global slot (*v3 = 0) before dispatch. [source:raw, global:0x008D41E8, global:0x008D41F4, global:0x008D41EC, global:0x008D41F0]
    // CALL: Leave the critical section if the flag is set (CritSectLeave(1)), then invoke the handler: id 8 calls v2(8, this[22]) with two arguments, all other ids call v2(a1); afterwards restore this[21] = v10, and for id 8 restore this[22] = v9. [callee:0x0058E04B, field:this:0x00000054, field:this:0x00000058]
    // RETURN: Return -1 for invalid command ids and -1 via sub_589CB5(3u) on the null-handler path; return 0 on every success path. [source:raw]
    // CALL: Called by SEHWrapperDispatchingToHandlerFunction (0x00593C9C) and SEHGuardedFunctionPointerCall (0x00593CFD) as the shared CRT command dispatcher. [caller:0x00593C9C, caller:0x00593CFD]

    // Conservative worker pseudocode:
    //   v11 = 0;
    //   switch (a1) {
    //       case 2:  v3 = &dword_8D41E8; v2 = *v3; break;
    //       case 15: v3 = &dword_8D41F4; v2 = *v3; break;
    //       case 21: v3 = &dword_8D41EC; v2 = *v3; break;
    //       case 22: v3 = &dword_8D41F0; v2 = *v3; break;
    //       case 4: case 8: case 11:
    //           v4 = TLSValueRetrievalWithInit();
    //           v3 = (int *)(ArrayOfStructLinearSearchByID_750a(a1, v4[20]) + 8);
    //           v2 = (void (__cdecl *)(_DWORD))*v3;
    //           goto dispatch;
    //       default: return -1;
    //   }
    //   v11 = 1;
    //   CriticalSectionLazyInitEnter(1);
    //   v4 = a1;
    //   dispatch:
    //   if (v2 == 1) { if (v11) CritSectLeave(1); return 0; }
    //   if (!v2) { if (v11) CritSectLeave(1); sub_589CB5(3u); }
    //   if (a1 == 4 || a1 == 8 || a1 == 11) {
    //       v10 = v4[21]; v4[21] = 0;
    //       if (a1 == 8) { v9 = v4[22]; v4[22] = 140; }
    //   }
    //   if (a1 == 8) {
    //       for (v7 = dword_5E7888, v8 = 12 * dword_5E7888; v7 < dword_5E7888 + dword_5E788C; ++v7) {
    //           v8 += 12;
    //           *(_DWORD *)(v4[20] + v8 - 4) = 0;
    //       }
    //   } else {
    //       *v3 = 0;
    //   }
    //   if (v11) CritSectLeave(1);
    //   if (a1 == 8) { v2(8, v4[22]); }
    //   else {
    //       v2(a1);
    //       if (a1 != 11 && a1 != 4) return 0;
    //   }
    //   v4[21] = v10;
    //   if (a1 == 8) v4[22] = v9;
    //   return 0;
    // UNRESOLVED: The semantic meaning of the command ids (2 = onexit, 15 = atexit, 21 = signal, 22 = exception, 4/8/11 = per-thread cleanup, per the corpus fill) is DERIVED, not established by the packet.
    // UNRESOLVED: The role of critical-section index 1 and the sentinel handler value 1 (skip dispatch) are not explained by the packet.
    // UNRESOLVED: The exact layout of the TLS table at this[20] and of the exception table bounded by dword_5E7888 / dword_5E788C (whether dword_5E788C is a count or a limit) is not confirmed by the packet.
    // UNRESOLVED: sub_589CB5(3u) is treated as an error/abort helper per the corpus fill; the packet only shows the call with argument 3.
    // UNRESOLVED: The 12-byte record size walked for id 8 is read directly from the raw source; the record type it describes is unknown.
}
