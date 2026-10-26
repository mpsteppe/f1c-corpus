// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0DF0
// Canonical corpus name: SessionStateDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStateDispatch_004a0df0.c

void UnknownObject::SessionStateDispatch()
{
    // Dispatches UI handling according to the current session state. Queries SessionStateCheck(dword_7CD25C); for state 3 it invokes the dispatch interface (vtable of dword_7CD8C0, method offset 28) with parameter 36, and for state 2 the same interface with parameter 35; any other state returns the raw state value immediately. When the queried result is non-null it runs UITextInputHandler(result, a1, 0), UIListSelectionHandler(result, result[37], 1) and returns SoundEffectLoadPlay(4, 1065353216). Otherwise the result pointer is returned unchanged. Called by MouseInputHandler (0045F030), SessionScoringUpdate (004643C0) and SessionMessageUICommandHandler (00470490).
    // CALL: Evaluate SessionStateCheck(dword_7CD25C) to obtain the current session state. [source:raw, callee:0x00461CD0, global:0x007CD25C]
    // GUARD: Branch on the session state: state 3 takes the parameter-36 dispatch path; state 2 takes the parameter-35 path; any other state returns the state value immediately. [source:raw]
    // CALL: State-3 path: indirect __thiscall through the dispatch vtable at *(dword_7CD8C0) with method offset 28, argument 36; store the result. [source:raw, global:0x007CD8C0]
    // CALL: State-2 path: indirect __thiscall through the dispatch vtable at *(dword_7CD8C0) with method offset 28, argument 35; store the result. [source:raw, global:0x007CD8C0]
    // GUARD: When the dispatch result is null, return it without any UI handling. [source:raw]
    // CALL: UITextInputHandler(result, a1, 0) processes text input against the dispatched UI object. [source:raw, callee:0x004896C0]
    // CALL: UIListSelectionHandler(v2, v2[37], 1) processes list selection on the dispatched UI object using its 37th dword. [source:raw, callee:0x00489AB0]
    // CALL: SoundEffectLoadPlay(4, 1065353216) loads and plays the UI sound effect; its return value becomes the function result. [source:raw, callee:0x004C8DE0]
    // RETURN: Return the dispatch result (or the state value on early-out paths). [source:raw, function:0x004A0DF0]

    // Conservative worker pseudocode:
    //   _DWORD* sub_4A0DF0(int a1) {
    //     _DWORD* result;
    //     int state = SessionStateCheck(dword_7CD25C);
    //     if (state == 3) {
    //       result = (*(int (__thiscall **)(int, int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 36);
    //     } else {
    //       if (state != 2) return (_DWORD*)state;
    //       result = (*(int (__thiscall **)(int, int))(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 35);
    //     }
    //     if (result) {
    //       UITextInputHandler(result, a1, 0);
    //       UIListSelectionHandler(result, result[37], 1);
    //       return (_DWORD*)SoundEffectLoadPlay(4, 1065353216);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The dispatch vtable method at offset 28 and what parameters 36/35 select are not identifiable from this packet.
    // UNRESOLVED: Field v2[37] of the dispatched UI object is read but its meaning is unnamed.
    // UNRESOLVED: The literal 1065353216 passed to SoundEffectLoadPlay is preserved verbatim from the raw source; no float interpretation is synthesized.
    // UNRESOLVED: byte_8AC494 (SceneArrayFirstSceneName per existing analysis, DERIVED) is flagged as read but never appears in the raw decompiled body.
}
