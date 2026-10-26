// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2F20
// Canonical corpus name: LinkedListDestructorWithData
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructorWithData_004c2f20.c

void UnknownObject::LinkedListDestructorWithData()
{
    // Destroys a singly linked list and releases the data each node owns. The head pointer is at this+0; each node is 12 bytes with a value pointer at +0, next at +4 and an ownership flag byte at +8. Walking from the head, every node whose flag is set has its value pointer dereferenced to a data object: if that object is non-null it is freed, then the value wrapper itself is freed. Every node is freed via FreeWrapper_7bcf as the walk advances. After the list is empty the four head DWORDs this+0/+4/+8/+0xC are zeroed and the last FreeWrapper result is returned.
    // GUARD: The destruction loop runs only while the head node pointer at this+0 is non-null; the head field this+0 is read at entry and the object pointer is preserved in v6 across the loop [field:this:0x00000000, field:*(obj+0x0):0x00000000, source:raw]
    // LOOP: Walks the list from the head node (obj+0) by following each node's next pointer at node+4 until it is null [field:*(obj+0x0):0x00000000, field:*(obj+0x4):0x00000004, source:raw]
    // GUARD: Per node, the ownership flag byte at node+8 decides whether the node's value is released before the node is freed [field:obj:0x00000008, source:raw]
    // CALL: When the flag is set and the value pointer at node+0 is non-null, dereferences it to the data object; if the data object is non-null FreeWrapper_7bcf frees it, then FreeWrapper_7bcf frees the value wrapper itself [field:obj:0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Frees every node with FreeWrapper_7bcf as the walk advances; the final call's result is the function return value [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the loop, zeroes the four head DWORDs of the list object at this+0/+4/+8/+0xC [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Invoked by AIPathPerformanceFunction (004BFA00) [caller:0x004BFA00, source:raw]

    // Conservative worker pseudocode:
    //   node = this->head;
    //   if (node) {
    //     do {
    //       next = node->next;
    //       if (node->ownsValue) {
    //         wrapper = node->value;
    //         if (wrapper) {
    //           if (*wrapper) FreeWrapper_7bcf(*wrapper);
    //           FreeWrapper_7bcf(wrapper);
    //         }
    //       }
    //       result = FreeWrapper_7bcf(node);
    //       node = next;
    //     } while (node);
    //   }
    //   this->head = 0;
    //   this->field4 = 0;
    //   this->field8 = 0;
    //   this->fieldC = 0;
    //   return result;
    // UNRESOLVED: The value layout is two-level (node+0 points to a wrapper whose first DWORD is a heap object) yet no packet evidence defines the wrapper or data structures
    // UNRESOLVED: The object type of the list owner and the meaning of its four cleared DWORDs are not determinable from this packet
    // UNRESOLVED: The prelabel calls this a structural twin of ListFullDestruction (004bb650), a DERIVED cluster attribution not corroborated here
    // UNRESOLVED: The return value is the last FreeWrapper_7bcf result, likely meaningless to the caller
}
