// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472BC0
// Canonical corpus name: SceneGraphQueryConditionalCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneGraphQueryConditionalCall_00472bc0.c

void UnknownObject::SceneGraphQueryConditionalCall()
{
    // Conditional scene-graph window-control query. First runs WindowControlTypeDetection(), then resolves a window control object from the global vtable dispatch root dword_7CD8C0 using a vtable method at offset 28 called with type argument 19. If the resolved control object is non-null, runs ObjectNameComparison() against this. Always returns 0.
    // CALL: Call WindowControlTypeDetection() before resolving the control object. [callee:0x0048C0E0, source:raw]
    // CALL: Fetch the object pointer stored in the global dword_7CD8C0 and dispatch a __thiscall vtable method at offset 28 with (dword_7CD8C0, 19) to resolve the window control object. [global:0x007CD8C0, source:raw]
    // GUARD: Guard: only proceed when the resolved control object pointer v2 is non-null. [source:raw]
    // CALL: Call ObjectNameComparison(v2, this) comparing the resolved control object name with this when the object is non-null. [callee:0x00477280, source:raw]
    // RETURN: Return constant 0 in all paths. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneGraphQueryConditionalCall(void *this) {
    //     WindowControlTypeDetection();
    //     _DWORD *v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 19);
    //     if (v2) ObjectNameComparison(v2, (int)this);
    //     return 0;
    //   }
    // UNRESOLVED: Identity of the object rooted at global dword_7CD8C0 and the exact semantic of its vtable method at offset 28 are unknown.
    // UNRESOLVED: Meaning of the type argument 19 and the target object of ObjectNameComparison depend on the window-control subsystem.
}
