// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478390
// Canonical corpus name: ProfileIconPathSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileIconPathSetter_00478390.c

void UnknownObject::ProfileIconPathSetter()
{
    // Resolves a profile icon bitmap path from a resource list: reads the resource-list pointer at this+0xE0, resolves a node via LinkedListIndexedAccessor_f590, reads the path string pointer from node offset 48 with a fallback to byte_5EA438 when null, and writes the result to global lpExistingFileName. Any missing link silently leaves the output untouched.
    // GUARD: Read this[56] (offset 0xE0); if null the routine returns without touching lpExistingFileName. [field:this:0x000000E0, source:raw]
    // CALL: Resolve the resource node by calling LinkedListIndexedAccessor_f590 on this[56]. [callee:0x0048F590, source:raw]
    // GUARD: If the resolved node pointer is null, skip path resolution. [source:raw]
    // ASSIGNMENT: Read the path string pointer at node offset 48; if null substitute byte_5EA438 (default/fallback path). [global:0x005EA438, source:raw]
    // ASSIGNMENT: Store the resolved path into global lpExistingFileName. [global:0x005C6658, source:raw]
    // CALL: Invoked by ResourceQueryAndStoredSetup (00478320) and sub_478350 (00478350). [caller:0x00478320, caller:0x00478350, source:raw]

    // Conservative worker pseudocode:
    //   void __thiscall ProfileIconPathSetter(_DWORD *this) {
    //     v1 = (void*)this[56];
    //     if (v1) {
    //       v2 = LinkedListIndexedAccessor_f590(v1);
    //       if (v2) {
    //         v3 = *(const CHAR**)(v2 + 48);
    //         if (!v3) v3 = byte_5EA438;
    //         lpExistingFileName = v3;
    //       }
    //     }
    //   }
    // UNRESOLVED: Node layout at offset 48 (path string slot) is read directly from the raw source; it has no named packet field entry.
    // UNRESOLVED: Semantics of LinkedListIndexedAccessor_f590 (indexing vs iteration) and of byte_5EA438 (default directory vs empty string) are inferred, not proven.
}
