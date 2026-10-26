// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410980
// Canonical corpus name: LoopWithConditionalSkipFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoopWithConditionalSkipFunction_00410980.c

void UnknownObject::UpdateSceneObjects()
{
    // Per-frame scene-object tick. Clears the UI widget matrix (dword_8AB710), then iterates this[0] scene objects from the array at this[2] (offset +0x8), running SceneObjectLoaderStateMachine on each with the frame argument. When the state machine returns false, the element is pulled from the array, ConditionalCleanupChain runs on it, and the index is decremented so the same slot is revisited. Returns the element count.
    // CALL: MatrixClear zeroes the matrix at global dword_8AB710 before the element loop. [callee:0x004BDFE0, global:0x008AB710, source:raw]
    // LOOP: Iterate i from 0 while i < this[0]; the bound is re-read each iteration from this[0] and the array base comes from this[2] (offset +0x8). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALL: SceneObjectLoaderStateMachine advances the load state of element *(this[2] + 4*i), passing the frame argument a2. [callee:0x0040F1C0, field:this:0x00000008, source:raw]
    // GUARD: If SceneObjectLoaderStateMachine returns 0 (false), the element is treated as failed/unloaded. [callee:0x0040F1C0, source:raw]
    // CALL: ConditionalCleanupChain runs the cleanup chain on the failed element; the loop index is decremented so the replacement element at the same slot is processed on the next iteration. [callee:0x0040F100, field:this:0x00000008, source:raw]
    // RETURN: Returns the element count read from this[0]. [field:this:0x00000000, function:0x00410980, source:raw]

    // Conservative worker pseudocode:
    //   MatrixClear(&dword_8AB710);
    //   for (i = 0; i < this[0]; ++i) {
    //       if (!SceneObjectLoaderStateMachine(*(this[2] + 4*i), a2)) {
    //           elem = *(this[2] + 4*i--);
    //           ConditionalCleanupChain(elem);
    //       }
    //   }
    //   return this[0];
    // UNRESOLVED: The identity of the scene-object type and the semantics of the state machine's false return (failure vs unload) are not established by this packet alone.
}
