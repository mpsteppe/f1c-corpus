// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004782C0
// Canonical corpus name: StateSyncWithDirtyFlagViaGameCommandDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateSyncWithDirtyFlagViaGameCommandDispatch_004782c0.c

void UnknownObject::StateSyncWithDirtyFlagViaGameCommandDispatch()
{
    // Queries the game command dispatch interface (global dword_7CD8C0) via vtable slot 28 with argument 16. If the returned pointer is non-null, reads a dword from the returned object at offset 0x174 (372) and compares it against this[58] (this+0xE8); when they differ, stores the read value into this[58] and calls the virtual method at vtable slot 44 on this with argument 1 (a state-sync/dirty-flag notification). Returns 0 unconditionally.
    // CALL: Virtual dispatch on the interface at global dword_7CD8C0: call vtable slot 28 (interface+28) with integer argument 16; result kept in v2 [global:0x007CD8C0, source:raw]
    // GUARD: Conditional: only proceed when the returned pointer v2 is non-null [source:raw, function:0x004782C0]
    // CALCULATION: v3 = *(_DWORD *)(v2 + 372): read a dword at offset 0x174 of the object returned by the dispatch query [source:raw]
    // GUARD: Conditional: only update and notify when this[58] (this+0xE8) differs from the read value v3 [field:this:0x000000E8, source:raw]
    // CALCULATION: v4 = *this: read this's vtable pointer at offset 0 to obtain the slot table for the follow-up dispatch [field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[58] = v3: store the freshly read value at this+0xE8, recording the synchronized state [field:this:0x000000E8, source:raw]
    // CALL: Virtual dispatch on this: call the method at vtable slot 44 (function pointer read from the vtable object at offset 0x2C) with integer argument 1; per the canonical name this is the dirty-flag / state-change notification [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return integer constant 0 regardless of whether the guard branches were taken [function:0x004782C0, source:raw]

    // Conservative worker pseudocode:
    //   int StateSyncWithDirtyFlagViaGameCommandDispatch(int *this) {
    //     int v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 16);
    //     if (v2) {
    //       int v3 = *(_DWORD *)(v2 + 372);
    //       if (this[58] != v3) {
    //         int v4 = *this;
    //         this[58] = v3;
    //         (*(void (__thiscall **)(int *, int))(v4 + 44))(this, 1);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The object behind dword_7CD8C0, the semantics of query argument 16, and what vtable slot 28 returns are not identified by packet evidence
    // UNRESOLVED: The read at returned-object offset 0x174 (372) has no packet field entry, so the type of the queried object and the meaning of that dword are unknown
    // UNRESOLVED: The indirect callee at vtable slot 44 on this (called with argument 1) is unresolved; its identity as a dirty-flag/sync notification rests only on the DERIVED canonical name and prelabel
    // UNRESOLVED: The callees list is empty, so all three dispatch targets (slot 28 on dword_7CD8C0, slot 44 on this) are indirect and unresolved
}
