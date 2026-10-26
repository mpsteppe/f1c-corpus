// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491FB0
// Canonical corpus name: sub_491FB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_491FB0_00491fb0.c

void UnknownObject::ReadLineAndCountTokens()
{
    // Reads a line of input through LineInputReader(256) and returns 0 when no more input is available. Then loops: increments the line counter at this[99] (offset 0x18C), classifies the token in the global buffer at unk_7CD9D8 via sub_5651B0, and when the token type is 1, 3 or 4 increments the special-token counter at this[100] (offset 0x190) before reading the next line. The loop continues while the classified type is 1, 3 or 4 and stops on type 2 or on types >= 5. Returns 1 on successful completion. The same read-and-count pattern is called by TokenMatchingLoop (00492030) and eight sibling text-parsing routines, consistent with the UI/text parser subsystem.
    // GUARD: If LineInputReader(256) returns zero (no more input available) return 0 immediately [callee:0x005351D0, source:raw]
    // LOOP: Infinite parsing loop: increment the line counter, classify the token, and read the next line until a non-matching token type is seen [source:raw]
    // ASSIGNMENT: Increment this[99] (offset 0x18C), the line counter [field:this:0x0000018C, source:raw]
    // CALL: sub_5651B0(&unk_7CD9D8) classifies the current token from the global input buffer; the result (v2) selects the continuation branch [callee:0x005651B0, global:0x007CD9D8, source:raw]
    // GUARD: Break the loop when v2 is not 1 and (v2 <= 2 or v2 > 4), i.e. continue only for token types 1, 3 or 4 [source:raw]
    // ASSIGNMENT: Increment this[100] (offset 0x190), the special-token counter, for matching token types [field:this:0x00000190, source:raw]
    // GUARD: If LineInputReader(256) returns zero inside the loop return 0 immediately [callee:0x005351D0, source:raw]
    // RETURN: Return 1 on successful completion of the line/token scan [source:raw]

    // Conservative worker pseudocode:
    //   if (!LineInputReader(256)) return 0;
    //   for (;;) {
    //     ++this[99];
    //     int type = sub_5651B0(&unk_7CD9D8);
    //     if (type != 1 && (type <= 2 || type > 4)) break;
    //     ++this[100];
    //     if (!LineInputReader(256)) return 0;
    //   }
    //   return 1;
    // UNRESOLVED: Global unk_7CDB70 is listed by the packet as a referenced global but does not appear in the decompiled body; its role is unknown
    // UNRESOLVED: The meaning of token types 1/3/4 (continue) versus 2/5+ (stop) is not established
    // UNRESOLVED: Owner object identity is unknown; the counters this[99]/this[100] are per-object state with no confirmed class
    // UNRESOLVED: All nine callers are recorded but the calling discipline is not established
}
