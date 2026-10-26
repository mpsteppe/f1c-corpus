// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562B50
// Canonical corpus name: MemoryObjectAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryObjectAllocator_00562b50.c

void UnknownObject::CreateNetworkSessionObject()
{
    // Allocates and initializes a 1464-byte network session object: zeroes offset 0, builds a 0x18-byte sub-struct with an inner buffer (via Malloc0x18ByteStructWithInnerBuffer(sub_5640F0)) at offset 4, a typed dynamic array (via AllocateIntArrayViaFactory with the sub_5645A0 factory and IndirectDwordCompare/sub_564630 callbacks) at offset 148, and a zeroed 28-byte-stride element array sized by a4 at offset 8. Copies three configuration strings into offsets 12/44/76, stores a4/a5/a7 at offsets 108/120/124, stores the global byte_5EA438 at offset 128, zeroes offset 152, then calls NetworkStartup.
    // CALL: MallocWrapperForNhMalloc(1464) allocates the session object v8; offset 0 is then zeroed [callee:0x0058A935, source:raw]
    // CALL: Malloc0x18ByteStructWithInnerBuffer(sub_5640F0) builds the sub-struct at offset 4, passing the callback global sub_5640F0 [callee:0x00564810, global:0x005640F0, source:raw]
    // CALL: AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630) creates the typed dynamic array stored at offset 148, wiring the factory and comparison callbacks [callee:0x005646D0, global:0x005645A0, global:0x00564600, global:0x00564630, source:raw]
    // ASSIGNMENT: Store a4 at offset 108 [source:raw]
    // CALL: MallocWrapperForNhMalloc(28 * a4) allocates the element array v9, stored at offset 8; the array is zeroed with memset of 4 * (28 * a4 >> 2) bytes [callee:0x0058A935, source:raw]
    // ASSIGNMENT: Copy the three configuration strings with strcpy: a1 to offset 12, a3 to offset 44, a2 to offset 76 (a2 and a3 stored in swapped order) [source:raw]
    // ASSIGNMENT: Store the remaining scalars: a5 at offset 120, a7 at offset 124, the global byte_5EA438 at offset 128, and 0 at offset 152 [global:0x005EA438, source:raw]
    // CALL: NetworkStartup() initializes the networking subsystem [callee:0x00564660, source:raw]
    // RETURN: Return the fully initialized session object v8 [function:0x00562B50, source:raw]
    // CALL: Invoked by NetworkReplayBufferInit (0045D260) to create the network session/connection object [caller:0x0045D260, source:raw]

    // Conservative worker pseudocode:
    //   v8 = MallocWrapperForNhMalloc(1464);
    //   *(v8 + 0) = 0;
    //   *(v8 + 4) = Malloc0x18ByteStructWithInnerBuffer(sub_5640F0);
    //   *(v8 + 148) = AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630);
    //   *(v8 + 108) = a4;
    //   v9 = MallocWrapperForNhMalloc(28 * a4);
    //   *(v8 + 8) = v9;
    //   memset(v9, 0, 4 * ((28 * a4) >> 2));
    //   strcpy(v8 + 12, a1);
    //   strcpy(v8 + 44, a3);
    //   strcpy(v8 + 76, a2);
    //   *(v8 + 120) = a5;
    //   *(v8 + 124) = a7;
    //   *(v8 + 128) = byte_5EA438;
    //   *(v8 + 152) = 0;
    //   NetworkStartup();
    //   return v8;
    // UNRESOLVED: The packet declares parameter a6 but the function body never references it
    // UNRESOLVED: byte_5EA438 is stored as a dword at offset 128; the skeleton fill suggests a default application directory path, unverifiable from this packet
    // UNRESOLVED: The layouts of the 0x18-byte sub-struct at offset 4 and of the typed array at offset 148 are not documented in this function
    // UNRESOLVED: a2 and a3 are stored in swapped order (a2 at offset 76, a3 at offset 44), suggesting a naming/directory split whose intent is not documented here
}
