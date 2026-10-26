// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F4A0
// Canonical corpus name: InputCommandDispatchToEntities
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputCommandDispatchToEntities_0045f4a0.c

void UnknownObject::InputCommandDispatchToEntities()
{
    // Dispatches buffered session input commands to session entities. SessionDataCopy snapshots data into the command ring buffer at dword_83EE60, then AdvanceRingBuffer walks each buffered command. Commands carrying the 0x10000000 flag are skipped. When the object references global state, commands are forwarded to the visibility-grid manager at dword_7CD2A8 via sub_465300; otherwise each command is filtered per entity against self index, the phase flag (this+0x3FC4) and a two-stage check, optionally rewritten with an entity tag from this+0x410, and dispatched with TextureCreationWrapper. A global-state second pass recomputes the entity visibility grid, pops queued entries from dword_7CD2A8 and emits them, then calls EmptyStub_0170. Returns sub_57A730 on the session pointer at this+0x3FB8.
    // CALL: SessionDataCopy(&dword_83EE60) copies session data into the input-command ring buffer before iteration [callee:0x004B3B30, global:0x0083EE60, source:raw]
    // LOOP: while AdvanceRingBuffer(&dword_83EE60, v16) reads the next buffered input command into the 432-byte v16 buffer [callee:0x004B3AF0, global:0x0083EE60, source:raw]
    // GUARD: skips the current command when its high flag bit (*(_DWORD*)v16 & 0x10000000) is set [source:raw]
    // GUARD: ReferencesGlobalState(this) selects between the global-state dispatch path and the per-entity path [callee:0x00461440, source:raw]
    // CALL: global-state path: sub_465300(&dword_7CD2A8, v16) forwards the command to the visibility-grid manager rooted at dword_7CD2A8 [callee:0x00465300, global:0x007CD2A8, source:raw]
    // CALL: per-entity path: SingleFunctionForward((void*)*this) resolves the dispatch target index v14 from the method pointer at this+0x0 [callee:0x00462310, field:this:0x00000000, source:raw]
    // GUARD: per-entity loop guard: iterate while the active entity count this[3973] at byte 0x3E14 is greater than 0 [guard:0, field:this:0x00003E14, source:raw]
    // GUARD: per-entity filter: skip the self entity (v2 != v14) and, when the phase at byte 0x3FC4 equals 3, require FlagBitTest(flag byte, 1) to pass [guard:1, field:this:0x00003FC4, callee:0x00461530, source:raw]
    // GUARD: command filter: accept the entity when (*(_DWORD*)v16 & 0x8000000) is set or TwoStageCheck() passes [callee:0x004614C0, source:raw]
    // CALCULATION: conditional tag rewrite: if TwoStageCheck() and v16[0] < 0x68, replace the command's low byte with SLOBYTE(this[35*v14 + 260]) read from the entity tag array at this+0x410 [callee:0x004614C0, field:this:0x00000410, source:raw]
    // CALL: TextureCreationWrapper((void*)*this, v16, 1, v4, 2000) dispatches the command to the filtered entity [callee:0x00462250, source:raw]
    // CALCULATION: per-entity traversal: the flag pointer advances by 140 bytes and the entity-id array pointer v15 starts at this+3869 (byte 0x3C74) [field:this:0x00003C74, source:raw]
    // CALL: global-state second pass setup: SingleFunctionForward((void*)*this), ThunkToFUN00461480(v17) and SingleFunctionDispatch((void*)*this) prepare the visibility dispatch [callee:0x00462310, callee:0x00461470, callee:0x00462300, field:this:0x00000000, source:raw]
    // GUARD: second-pass entity loop guard: iterate while the entity count at byte 0x3E14 is greater than 0 [guard:0, field:this:0x00003E14, source:raw]
    // CALL: second pass per entity: EntityVisibilityGridManager(&dword_7CD2A8, v8, v9) computes the visibility set, then while LinkedListPopFront(&dword_7CD2A8, &v13) TextureCreationWrapper((void*)*this, v13, 1, v9, 500) emits each popped entry [callee:0x00465460, callee:0x00465C30, callee:0x00462250, global:0x007CD2A8, source:raw]
    // CALL: EmptyStub_0170() runs at the end of the global-state pass [callee:0x004B0170, source:raw]
    // RETURN: returns sub_57A730((ULONG_PTR*)this[4078], 0) using the session/COM pointer at this+0x3FB8; this function is called by CollisionResponseStatus (0x00463CD0) [callee:0x0057A730, field:this:0x00003FB8, caller:0x00463CD0, source:raw]

    // Conservative worker pseudocode:
    //   SessionDataCopy(&ring);
    //   while (AdvanceRingBuffer(&ring, cmd)) {
    //     if (*(u32*)cmd & 0x10000000) continue;
    //     if (ReferencesGlobalState(this)) sub_465300(&grid, cmd);
    //     else {
    //       selfIdx = SingleFunctionForward(*this);
    //       for (i = 0; i < this[3973]; i++) {
    //         if (i != selfIdx && (this[4081] != 3 || FlagBitTest(flags, 1))
    //             && ((*(u32*)cmd & 0x8000000) || TwoStageCheck())) {
    //           if (TwoStageCheck() && cmd[0] < 0x68)
    //             *(u32*)cmd = *(u32*)cmd & 0xFFFFFF00 | this[35*selfIdx + 260];
    //           TextureCreationWrapper(*this, cmd, 1, ids[i], 2000);
    //         }
    //       }
    //     }
    //   }
    //   if (ReferencesGlobalState(this)) {
    //     SingleFunctionForward(*this); ThunkToFUN00461480(buf); SingleFunctionDispatch(*this);
    //     for (i = 0; i < this[3973]; i++) {
    //       if (i != selfIdx && (this[4081] != 3 || FlagBitTest(p, 1))) {
    //         if (TwoStageCheck()) {
    //           EntityVisibilityGridManager(&grid, *p, this[*p + 3974]);
    //           while (LinkedListPopFront(&grid, &n)) TextureCreationWrapper(*this, n, 1, v9, 500);
    //         }
    //       }
    //     }
    //     EmptyStub_0170();
    //   }
    //   return sub_57A730((void**)this[4078], 0);
    // UNRESOLVED: The exact meanings of command flags 0x10000000 and 0x8000000 and of TwoStageCheck's two-stage gate are not stated by packet facts
    // UNRESOLVED: The phase value 3 at byte 0x3FC4 and its interaction with FlagBitTest are DERIVED from source structure
    // UNRESOLVED: The object passed as this+0x3FB8 to sub_57A730 is assumed to be a session/COM object pointer; its type is not confirmed
}
