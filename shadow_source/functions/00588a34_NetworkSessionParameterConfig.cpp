// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588A34
// Canonical corpus name: sub_588A34
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588A34_00588a34.c

void UnknownObject::NetworkSessionParameterConfig()
{
    // Configures network session parameters, either by indexed accessor (a1 in 1..5) or by parsing a configuration string. The a1 != 0 path sets a single parameter value (or reads the stored session pointer) under critical section 19. The a1 == 0 path parses 'LC_'-prefixed key=value pairs against a parameter table, or a generic tokenized config against the existing session table, then (re)initializes and post-processes the session. All paths are serialized by critical section 19, a reentrancy counter, and a spin-wait on the heap-lock counter.
    // GUARD: Reject invalid session index: if a1 > 5 return 0 immediately [function:0x00588A34, source:raw]
    // CALL: Enter critical section 19 via CriticalSectionLazyInitEnter(19) [callee:0x0058DFEA, source:raw]
    // ASSIGNMENT: Increment the thread/reentrancy counter dword_8D5A58 [global:0x008D5A58, source:raw]
    // LOOP: Spin-wait: while dword_8D5A5C is nonzero, Sleep(1) via the imported Sleep function (0x0059E0DC) [global:0x008D5A5C, global:0x0059E0DC, source:raw]
    // STATE_TRANSITION: Indexed accessor path (a1 != 0): with a value string call sub_588C7A(a1, a2); without one read the stored session pointer at dword_5E64F4 indexed by 3 * a1 [callee:0x00588C7A, global:0x005E64F4, source:raw]
    // CALL: Leave critical section 19, decrement dword_8D5A58, and return the retrieved value [callee:0x0058E04B, global:0x008D5A58, source:raw]
    // GUARD: Config-string path (a1 == 0): only when a2 begins with the 'LC_' prefix (bytes 76 'L', 67 'C', 95 '_') parse key=value pairs; otherwise fall to the generic parse path [source:raw]
    // LOOP: For each key=value pair located by sub_58FC60(a2, "=;"), scan the parameter table at off_5E64FC (3-entry stride) comparing each entry name with sub_588640 and its length with Strlen until a full match is found or the table end off_5E652C is passed [callee:0x0058FC60, callee:0x00588640, callee:0x0058E1B0, global:0x005E64FC, global:0x005E652C, source:raw]
    // CALL: Extract the value: locate the ';' terminator with sub_58FC20, copy the value into the local buffer with sub_587DD0, NUL-terminate it, then apply it with sub_588C7A(table index, value); each success increments the applied counter v19 [callee:0x0058FC20, callee:0x00587DD0, callee:0x00588C7A, source:raw]
    // GUARD: Pair-list early exit: stop when the ';' terminator search fails, when a key is empty or ';'-terminated immediately, or when a value is empty; if no parameter was applied (v19 == 0) return 0 after leaving the critical section [source:raw]
    // CALL: Generic parse path (non-LC_ string): tokenize with sub_588E4E(a2, v17, 0, 0); on failure leave the critical section and return 0 [callee:0x00588E4E, source:raw]
    // LOOP: Match the parsed block against each existing session pointer in the dword_5E64F4 array (stride 3, up to off_5E6530): compare with sub_58FB90, apply changed values with sub_588C7A, and clear the all-matched flag on any mismatch [callee:0x0058FB90, callee:0x00588C7A, global:0x005E64F4, global:0x005E6530, source:raw]
    // STATE_TRANSITION: When every existing session matched, finalize: initialize the session with sub_588D95(), post-process it with sub_58AA6F(dword_5E64F4), and clear the session pointer dword_5E64F4 [callee:0x00588D95, callee:0x0058AA6F, global:0x005E64F4, source:raw]
    // RETURN: Fall-through and return paths leave the critical section, decrement dword_8D5A58, and return the session/index value (0 on failure) [callee:0x0058E04B, global:0x008D5A58, source:raw]
    // CALL: Invoked by sub_423890 (00423890) during session/network configuration [caller:0x00423890, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 > 5) return 0;
    //   CriticalSectionLazyInitEnter(19);
    //   ++dword_8D5A58;
    //   while (dword_8D5A5C) Sleep(1);
    //   if (a1) {
    //     v4 = a2 ? sub_588C7A(a1, a2) : *(&dword_5E64F4 + 3 * a1);
    //   } else if (a2) {
    //     if (a2 starts with "LC_") {
    //       for each pair delimited by sub_58FC60(a2, "=;") {
    //         match key against off_5E64FC table (sub_588640 + Strlen);
    //         copy value with sub_587DD0; apply with sub_588C7A(idx, value);
    //       }
    //     } else {
    //       v4 = sub_588E4E(a2, v17, 0, 0);
    //       if (!v4) goto leave;
    //       match v17 against dword_5E64F4 session table;
    //       if (all matched) { sub_588D95(); sub_58AA6F(dword_5E64F4); dword_5E64F4 = 0; }
    //     }
    //   }
    //   if (!v19) v4 = 0;
    //   v4 = sub_588D95();
    //   leave:
    //   CritSectLeave(19);
    //   --dword_8D5A58;
    //   return v4;
    // UNRESOLVED: Two string literals (asc_5B8C74, asc_5B8C78) are flagged as packet globals but never appear explicitly in the raw source; they likely back the "=;" / ";" delimiters or a format string, but the binding is not visible here
    // UNRESOLVED: The LABEL_31/LABEL_46 shared exit flow is goto-woven between the LC_ pair parser and the generic parse path; the exact condition under which the final sub_588D95() initialization is reached is inferred, not proven
}
