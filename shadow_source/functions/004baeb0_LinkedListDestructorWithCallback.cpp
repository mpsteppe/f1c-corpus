// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAEB0
// Canonical corpus name: LinkedListDestructorWithCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructorWithCallback_004baeb0.c

void UnknownObject::LinkedListDestructorWithCallback()
{
    // Walks a singly linked list owned by the receiver. For each node, reads the flag byte at obj+0x8 and the next-pointer at obj+0x4; when the flag is nonzero and the embedded data pointer at obj+0x0 is non-null, calls EmptyStub_0170 and frees the embedded data. Every node is then freed with FreeWrapper_7bcf. Finally the list head and the three following dwords (0x0/0x4/0x8/0xC) are zeroed and 0 is returned.
    // ASSIGNMENT: Load the list head *this into the walk cursor v2. [field:this:0x00000000]
    // LOOP: while (v2 != 0): iterate over every node until the next-pointer chain terminates. [source:raw]
    // ASSIGNMENT: Capture the current node v3, read its flag byte at obj+0x8, and advance the cursor to the next node via the pointer at obj+0x4. [field:obj:0x00000008, field:*(obj+0x4):0x00000004]
    // GUARD: If the node's flag byte at obj+0x8 is nonzero, release the embedded data. [field:obj:0x00000008]
    // GUARD: If the embedded data pointer at obj+0x0 is non-null, run the stub and free it. [field:obj:0x00000000]
    // CALL: EmptyStub_0170 invoked before freeing the embedded data. [callee:0x004B0170]
    // CALL: FreeWrapper_7bcf on the embedded data pointer read from obj+0x0. [callee:0x00587BCF, field:obj:0x00000000]
    // CALL: FreeWrapper_7bcf on the node itself v3. [callee:0x00587BCF]
    // ASSIGNMENT: Reset the list head this+0x0 to 0. [field:this:0x00000000]
    // ASSIGNMENT: Reset this+0x4 to 0. [field:this:0x00000004]
    // ASSIGNMENT: Reset this+0x8 to 0. [field:this:0x00000008]
    // ASSIGNMENT: Reset this+0xC to 0. [field:this:0x0000000C]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4BAEB0(int* this) {
    //     int node = *this;
    //     while (node) {
    //       int next = *(int*)(node + 4);
    //       int flag = *(char*)(node + 8);
    //       if (flag) {
    //         void* data = *(void**)node;
    //         if (data) { EmptyStub_0170(); FreeWrapper_7bcf(data); }
    //       }
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: EmptyStub_0170 is a stub; the behavior it is supposed to perform is unknown.
    // UNRESOLVED: The flag byte at obj+0x8 decides whether embedded data is freed, but its exact semantics (owns-data bit vs state flag) are not determined.
    // UNRESOLVED: The concrete node and list-owner types are unknown; caller DestroyUIWidgetHierarchy suggests a UI-widget child list.
}
