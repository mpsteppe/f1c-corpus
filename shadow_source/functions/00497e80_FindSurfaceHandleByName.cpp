// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497E80
// Canonical corpus name: sub_497E80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_497E80_00497e80.c

void UnknownObject::FindSurfaceHandleByName()
{
    // Searches a linked list of loaded surfaces (head at this[67], this+0x10C) for a node matching key a2. Traverses using the next pointer at node offset 0x54 (v2+84), comparing each node via sub_588410 (0 result = match). Returns the surface handle at node offset 0x50 (v2+80) when found, or 0 when a2 is null, the list is empty, or the list is exhausted. Invoked by TimedAnimationTrigger (00486730), UILargeRender (00496930) and TextureSurfaceLoader (00497d20) to resolve a surface by name.
    // GUARD: Null-guard on the search key a2: if (!a2) return 0 immediately [source:raw]
    // ASSIGNMENT: v2 = this[67] reads the head of the loaded-surface list at this+0x10C [field:this:0x0000010C, source:raw]
    // GUARD: Empty-list guard: if the head v2 is null, return 0 (no nodes to search) [field:this:0x0000010C, source:raw]
    // CALL: Call sub_588410(v2, a2) as a string/id comparison against the current node; a truthy result means 'not a match' and the walk continues [callee:0x00588410, source:raw]
    // LOOP: Walk: while sub_588410(v2, a2) is truthy (mismatch), advance v2 = *(_DWORD*)(v2+84), the next pointer at node offset 0x54; if the next pointer is null, return 0 (key not found) [field:*(this+0x160):0x00000054, source:raw]
    // RETURN: Return *(_DWORD*)(v2+80), the surface handle at node offset 0x50, once a matching node is found [field:*(this+0x160):0x00000050, source:raw]
    // CALL: Invoked by TimedAnimationTrigger (00486730), UILargeRender (00496930) and TextureSurfaceLoader (00497d20) to look up a loaded surface by name [caller:0x00486730, caller:0x00496930, caller:0x00497D20, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   v2 = this[67];
    //   if (!v2) return 0;
    //   while (sub_588410(v2, a2)) {
    //     v2 = *(v2 + 84);
    //     if (!v2) return 0;
    //   }
    //   return *(v2 + 80);
    // UNRESOLVED: The exact comparison semantics of sub_588410 (0 = match) are inferred from the loop-exit condition only, not proven independently
    // UNRESOLVED: Packet field bases for the node slots are rendered as *(this+0x160), while the raw source traverses nodes reached from the head this[67] (this+0x10C); the +0x160 base is an extractor artifact not present in the source text
    // UNRESOLVED: The 0x10C list-head slot and the 0x50/0x54 node slots are DERIVED from element indices (this[67], v2+80, v2+84) and are not individually corroborated by further evidence
}
