// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005631A0
// Canonical corpus name: TwoStepDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoStepDispatch_005631a0.c

void UnknownObject::TwoStepDispatch()
{
    // Two-step dispatch wrapper: computes an intermediate value by calling sub_563E70 on the object field at this+0x4, then passes it together with a2 to AudioNoteParamIndexSearchLoop and returns that search's result. Structurally paired with DebugLogWrite (004d7aa0) per the cluster prelabel.
    // CALL: v2 = sub_563E70(this[1]) derives the lookup index/limit from the object field at byte offset 0x4 (dword index 1) [callee:0x00563E70, field:this:0x00000004, source:raw]
    // CALL: AudioNoteParamIndexSearchLoop(a2, v2) searches the note parameter space for a2 using the derived v2 [callee:0x005631D0, source:raw]
    // RETURN: Return the AudioNoteParamIndexSearchLoop result as the function result [function:0x005631A0, source:raw]
    // CALL: Invoked by NetworkConnection (00563260) and sub_563410 (00563410) as a two-step audio-note parameter dispatch [caller:0x00563260, caller:0x00563410]

    // Conservative worker pseudocode:
    //   v2 = sub_563E70(this[1]);
    //   return AudioNoteParamIndexSearchLoop(a2, v2);
    // UNRESOLVED: What sub_563E70 computes from this[1] and what a2 represents (note value, index, or key) is not documented in this function
    // UNRESOLVED: The object type behind this (field at 0x4) is unknown; the cluster-copy label against DebugLogWrite (004d7aa0) is DERIVED only
}
