// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A2010
// Canonical corpus name: PitCrewMeshLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitCrewMeshLoader_004a2010.c

void UnknownObject::PitCrewMeshLoader()
{
    // Loads pit crew member meshes into the scene graph. Guards on the global detail level against a __int16 threshold at this+0x0, allocates mesh resources through MeshResourceAllocator at the list-head field this+0x64, walks the sub-mesh node list, appends the nodes to the actor node list, builds a child index table at this+0x6C from the child count at this+0x68, optionally re-links nodes with a 0x2000000 flag, and records the name at this+4. On allocation failure falls back to an error-logging path returning -1.
    // GUARD: Guard: if the resource argument a3 is null (a3 == 0) return -1 immediately. [source:raw]
    // GUARD: Guard: if the global detail level dword_7CF884 is below the __int16 threshold stored at this+0x0, return 0 and skip loading the pit crew meshes. [global:0x007CF884, field:this:0x00000000, source:raw]
    // CALL: Invoke MeshResourceAllocator on the list-head field at this+0x64 with the mesh name a2 and resource a3, fixed size 16. A zero return enters the load body; a non-zero return falls to the error path. [callee:0x005450E0, field:this:0x00000064, source:raw]
    // LOOP: Walk the sub-mesh node list starting at a3, following the next pointer at node+68; for each node call sub_54A870 and set the local flag i when the node byte at +64 is zero (incomplete mesh marker). [callee:0x0054A870, source:raw]
    // CALL: Attach the loaded mesh node list to the scene graph: when a4 is true call DoublyLinkedListNodeMover(*node, 0), otherwise call ActorNodeLinkedListAppend(*node), where *node is the list head at this+0x64. [callee:0x0054BA00, callee:0x00545250, field:this:0x00000064, source:raw]
    // ASSIGNMENT: Query the scene graph child count via SceneGraphChildCount(*node) and store it at this+0x68, then allocate the child index table of 4*count bytes via OperatorNewNhMallocWrapper and store the pointer at this+0x6C. [callee:0x0054C210, callee:0x00587C03, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // LOOP: Fill the child index table: for each index j below the count at this+0x68, store LinkedListIndexedAccessor_c230(j) into the table at this+0x6C at element offset 4*j. [callee:0x0054C230, field:this:0x00000068, field:this:0x0000006C, source:raw]
    // GUARD: Optional re-link guard: when a5 is set or the global detail level dword_7CF884 is at least 2, walk the scene node list again starting from LinkedListIndexedAccessor_c230(0), chaining nodes via the next pointer at +16. [global:0x007CF884, callee:0x0054C230, source:raw]
    // CALL: For each scene node that is linked to a sub-mesh node whose byte at +64 is set, insert it with LinkedListNodeInsert_5930(node, a4) and set the 0x2000000 flag at node+20 when the earlier incomplete-mesh flag i is set. [callee:0x00545930, source:raw]
    // ASSIGNMENT: Copy the mesh name a2 into this+4 via strcpy so the loader object records the loaded mesh name. [source:raw]
    // RETURN: Return 0 on the successful load path. [source:raw]
    // CALL: Error path: StringRelocationCopy(0, v14) into a stack buffer, then if StringSplitLoop(1, aDDevF119992002_2, 180) returns non-zero call DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi) to log the mesh load failure. [callee:0x0053C5B0, callee:0x004D7A50, callee:0x004D7AA0, global:0x005CD174, global:0x008AD25C, global:0x005CD14C, source:raw]
    // RETURN: Return -1 on a null resource argument or on mesh allocation failure. [source:raw]
    // CALL: Called by StringCopyWithReverse (0x004A21D0) and ModeDependentSubsystemCall (0x004A2770) on pit-area mesh loading paths. [caller:0x004A21D0, caller:0x004A2770, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A2010(__int16 *this, const char *name, int resource, int a4, char a5) {
    //     if (!resource) return -1;
    //     if (dword_7CF884 < *this) return 0;
    //     if (MeshResourceAllocator(this + 0x64, name, resource, 16)) {
    //       StringRelocationCopy(0, v14);
    //       if (StringSplitLoop(1, aDDevF119992002_2, 180)) DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi);
    //       return -1;
    //     }
    //     for (node = *(int*)(resource + 68); node; node = *(int*)(node + 68)) {
    //       sub_54A870(node); if (!*(char*)(node + 64)) i = 1;
    //     }
    //     if (a4) DoublyLinkedListNodeMover(*(int*)(this + 0x64), 0);
    //     else   ActorNodeLinkedListAppend(*(int*)(this + 0x64));
    //     *(int*)(this + 0x68) = SceneGraphChildCount(*(int*)(this + 0x64));
    //     *(int*)(this + 0x6C) = OperatorNewNhMallocWrapper(4 * *(int*)(this + 0x68));
    //     for (j = 0; j < *(int*)(this + 0x68); ++j)
    //       *(int*)(*(int*)(this + 0x6C) + 4 * j) = LinkedListIndexedAccessor_c230(j);
    //     if (a5 || dword_7CF884 >= 2)
    //       for (sn = LinkedListIndexedAccessor_c230(0); sn; sn = *(int*)(sn + 16))
    //         if (*(char*)(sn + 64)) { LinkedListNodeInsert_5930(sn, a4); if (i) *(int*)(sn + 20) |= 0x2000000; }
    //     strcpy((char*)this + 4, name);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the __int16 threshold at this+0x0 relative to global dword_7CF884 (detail level) are inferred from the comparison only (DERIVED).
    // UNRESOLVED: The 0x2000000 flag at scene node +20 and the incomplete-mesh byte at +64 are interpreted from the flag arithmetic but their exact meanings are unproven.
}
