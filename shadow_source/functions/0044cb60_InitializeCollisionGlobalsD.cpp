// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CB60
// Canonical corpus name: InitializeCollisionGlobalsD
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitializeCollisionGlobalsD_0044cb60.c

void UnknownObject::InitializeCollisionGlobalsD()
{
    // Argument-less, branch-free initialization routine. Writes 104 to vehicle/collision global dword_7CD108, writes 0.0 to the adjacent global flt_7CD10C, then calls InputHandlerGlobalReset (present in the raw source text only; the packet carries no callee entry or address for it). No return value.
    // ASSIGNMENT: Write 104 to global dword_7CD108. [global:0x007CD108, source:raw]
    // ASSIGNMENT: Write 0.0 to global flt_7CD10C. [global:0x007CD10C, source:raw]
    // CALL: Call InputHandlerGlobalReset. [source:raw]

    // Conservative worker pseudocode:
    //   void InitializeCollisionGlobalsD() {
    //       dword_7CD108 = 104;
    //       flt_7CD10C = 0.0;
    //       InputHandlerGlobalReset();
    //   }
    // UNRESOLVED: The callee InputHandlerGlobalReset appears only by name in the raw source text; the packet has no callee evidence entry or address for it, so its identity and definition are unknown.
    // UNRESOLVED: The semantic role of dword_7CD108 (initialized to 104) and flt_7CD10C (initialized to 0.0) within the collision globals is not evidenced by this packet; only the writes are certain.
}
