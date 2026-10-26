// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2FE0
// Canonical corpus name: Delegation_2fe0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Delegation_2fe0_004c2fe0.c

void UnknownObject::ResetSceneListBuffer()
{
    // Reinitializes the 6-dword global array dword_8AC36C to the literal state { 0, -1, 0, 0, 0, 0 } (index 1 set to -1 as the only non-zero entry), then invokes SceneListCleanup() and returns a pointer to the reinitialized array.
    // ASSIGNMENT: Write the initial state into dword_8AC36C: dword_8AC36C[0] = 0, dword_8AC36C[1] = -1, dword_8AC36C[2] = 0, dword_8AC36C[3] = 0, dword_8AC36C[4] = 0, dword_8AC36C[5] = 0; index 1 is the only non-zero entry, set to -1 as a sentinel. [global:0x008AC36C, source:raw]
    // CALL: SceneListCleanup() invoked after the array is reinitialized; it has no packet callee entry or address, so its behavior and side effects are not characterized. [source:raw]
    // RETURN: Return the pointer to the reinitialized dword_8AC36C buffer. [global:0x008AC36C, source:raw]

    // Conservative worker pseudocode:
    //   dword_8AC36C[0] = 0; dword_8AC36C[1] = -1; dword_8AC36C[2] = 0;
    //   dword_8AC36C[3] = 0; dword_8AC36C[4] = 0; dword_8AC36C[5] = 0;
    //   SceneListCleanup();
    //   return dword_8AC36C;
    // UNRESOLVED: SceneListCleanup() has no packet callee entry, so it cannot be referenced as a callee evidence ref; its side effects on the scene list are not characterized.
    // UNRESOLVED: The semantic roles of the 6 array entries and of the -1 sentinel at index 1 are inferred from the SceneListCleanup call site, not independently evidenced.
}
