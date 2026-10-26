// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E7E0
// Canonical corpus name: MutexProtectedLinkedListDestruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedLinkedListDestruction_0057e7e0.c

void UnknownObject::MutexProtectedLinkedListDestruction()
{
    // Flushes a mutex-protected singly-linked list on the owning object: waits on the mutex handle (this+0xB2C) with the wait timeout (this+0xB30), then walks every node from the head (this+0xB1C) via each node's next pointer (node+4), freeing the node's data pointer when the byte flag at node+8 is set and freeing every node itself, zeroes the four list-head dwords (this+0xB1C through this+0xB28), and releases the mutex. Called by NetworkCleanup_fbe0 (0057FBE0).
    // GUARD: Mutex acquisition gate: when the mutex handle at this+0xB2C is non-null, WaitForSingleObject is called with the timeout at this+0xB30 and the walk base is accepted when the return is 0 or 128, otherwise the walk base is null [global:0x0059E1A0, field:this:0x00000B2C, field:this:0x00000B30, source:raw]
    // LOOP: Walks the singly-linked list starting at the head pointer this+0xB1C, advancing through each node's next pointer (node+4) until a null node is reached [field:this:0x00000B1C, field:*(*(this+0xB1C)+0x4):0x00000004, source:raw]
    // CALL: For each node, when the byte flag at node+8 is non-zero, FreeWrapper_7bcf is called on the node's data pointer (node+0) [field:*(this+0xB1C):0x00000008, field:*(this+0xB1C):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Every node address itself is released through FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clears the four list-head dwords at this+0xB1C, this+0xB20, this+0xB24 and this+0xB28 to zero [field:this:0x00000B1C, field:this:0x00000B20, field:this:0x00000B24, field:this:0x00000B28, source:raw]
    // CALL: When the mutex handle at this+0xB2C is non-zero, ReleaseMutex is called on it [global:0x0059E1A4, field:this:0x00000B2C, source:raw]
    // RETURN: Returns the ReleaseMutex result when the mutex was released, otherwise 0 [global:0x0059E1A4, field:this:0x00000B2C, source:raw]
    // CALL: Invoked by NetworkCleanup_fbe0 (0057FBE0) as part of network session cleanup [caller:0x0057FBE0, source:raw]

    // Conservative worker pseudocode:
    //   handle = this[0xB2C/4];
    //   base = (handle && WaitForSingleObject(handle, this[0xB30/4]) in {0, 128}) ? this[0xB1C/4] : null;
    //   node = *base;
    //   while (node) {
    //     next = *(node + 4);
    //     if (*(node + 8)) FreeWrapper_7bcf(*(node + 0));
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   this[0xB1C/4] = 0; this[0xB20/4] = 0; this[0xB24/4] = 0; this[0xB28/4] = 0;
    //   return this[0xB2C/4] ? ReleaseMutex(this[0xB2C/4]) : 0;
    // UNRESOLVED: The 128 (0x80) accept-value of WaitForSingleObject is kept verbatim; its Windows wait-constant identity is not asserted here
    // UNRESOLVED: The node layout (next at +4, flag at +8, data at +0) is evidenced only through the list walk; no node allocation site is visible from this packet
    // UNRESOLVED: The wait result is treated as boolean success; the distinct semantics of the 0 vs 128 paths are not further separated
}
