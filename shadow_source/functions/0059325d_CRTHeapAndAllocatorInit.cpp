// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059325D
// Canonical corpus name: sub_59325D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59325D_0059325d.c

void UnknownObject::CRTHeapAndAllocatorInit()
{
    // Creates the CRT private heap with HeapCreate, stores the selected heap type code in a global, then initializes the matching sub-allocator (msvcrt heap for type 3, slab/buddy allocator for type 2). Returns 1 on success, 0 if the heap or the sub-allocator initialization fails.
    // CALL: Call HeapCreate with flag a1 == 0, initial size 0x1000, and 0 for the maximum size, storing the returned handle in the hHeap global. [global:0x0059E0A8, global:0x008D4904, source:raw]
    // GUARD: If hHeap is null, the heap could not be created; return 0 immediately. [global:0x008D4904, source:raw]
    // CALL: Call sub_593115 to determine the heap type code and store its return value in v1. [callee:0x00593115, source:raw]
    // ASSIGNMENT: Write the heap type code v1 into the dword_8D4908 global for downstream use. [global:0x008D4908, source:raw]
    // GUARD: Branch on the heap type code: v1 == 3 selects the msvcrt heap initializer, v1 == 2 selects the slab/buddy allocator initializer, and any other value returns 1 without further initialization. [callee:0x00593DD3, callee:0x0059491A, source:raw]
    // CALL: On the type 3 path, call sub_593DD3 with the size parameter 1016 to initialize the msvcrt heap; capture the success result in v2. [callee:0x00593DD3, source:raw]
    // CALL: On the type 2 path, call SlabBuddyAllocatorInitialization to set up the slab/buddy allocator; capture the success result in v2. [callee:0x0059491A, source:raw]
    // GUARD: If the chosen sub-allocator initializer returned 0 (failure), destroy the private heap with HeapDestroy and return 0. [global:0x0059E0FC, global:0x008D4904, source:raw]
    // RETURN: Return 1 to report successful heap and sub-allocator initialization. [function:0x0059325D, source:raw]

    // Conservative worker pseudocode:
    //   hHeap = HeapCreate(a1 == 0, 0x1000, 0);
    //   if (!hHeap) return 0;
    //   v1 = sub_593115();
    //   dword_8D4908 = v1;
    //   if (v1 == 3) { v2 = sub_593DD3(1016); }
    //   else { if (v1 != 2) return 1; v2 = SlabBuddyAllocatorInitialization(); }
    //   if (!v2) { HeapDestroy(hHeap); return 0; }
    //   return 1;
    // UNRESOLVED: The exact meaning of the heap type codes 1, 2 and 3 is not established beyond this packet's control flow.
    // UNRESOLVED: The identity of the object owning this initialization routine is not established by the packet.
    // UNRESOLVED: The caller sub_58A19E is known but the call context is not present in the packet.
}
