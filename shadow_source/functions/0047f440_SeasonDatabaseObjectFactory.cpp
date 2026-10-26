// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F440
// Canonical corpus name: SeasonDatabaseObjectFactory
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonDatabaseObjectFactory_0047f440.c

void UnknownObject::SeasonDatabaseObjectFactory()
{
    // Season/career database object factory. Validates a type id against the cache bounds, returns a cached object pointer when already built or for out-of-range ids, and for ids 1-45 allocates a per-type buffer, runs the matching constructor, installs the per-type vtable, caches the result in this[(id-1)+1607] and returns it. On allocation failure the cache slot is set to 0 and 0 is returned. Id 436 is handled specially with a 772-byte bulk-init object.
    // GUARD: Validate the id against the cache: a2-1 must be in [0, 507] and the cache slot this[(a2-1)+1607] must be empty; otherwise return 0 or the already-cached pointer. [source:raw]
    // GUARD: Ids above 436 return the cached pointer without building a new object (only 436 has special handling). [source:raw]
    // ASSIGNMENT: Id 436: allocate 772 bytes and, on success, run the bulk-init-and-vtable constructor, cache the result and return it; on allocation failure store 0 in the cache slot and return that 0. [callee:0x00587C03, callee:0x00470230]
    // CALL: Id 1 (track database): allocate 236 bytes, run the byte-parameter constructor, set the string-buffer state (field 57 empty, field 58 length -1), install vtable off_5A7638, copy the track-db filename literal into the string buffer, then cache and return. [callee:0x00587C03, callee:0x00487220, callee:0x00566650, global:0x005A7638, global:0x005BF970]
    // CALL: Id 2: allocate 380 bytes and run the FunctionCallWrapper_85b0 constructor, then cache and return. [callee:0x00587C03, callee:0x004685B0]
    // CALL: Id 3: allocate 1108 bytes, run the zeroed-fields constructor, zero the four trailing fields (indices 273-276), install vtable off_5A6F48, cache and return. [callee:0x00587C03, callee:0x0048C9F0, global:0x005A6F48]
    // CALL: Ids 5 and 6: allocate 848 bytes and run the ObjectConstructorWithVTable constructor, cache and return. [callee:0x00587C03, callee:0x0046A220]
    // CALL: Ids 7 to 10 (UI components): allocate 232 bytes, run the UI-component init, install the per-type vtable (off_5A7588, off_5A74D8, off_5A7428, off_5A7378), cache and return. [callee:0x00587C03, callee:0x0048FE60, global:0x005A7588, global:0x005A74D8, global:0x005A7428, global:0x005A7378]
    // CALL: Ids 11-15, 19, 25 and 26: allocate 384 bytes, run the large constructor, install vtable off_5A7218, cache and return. [callee:0x00587C03, callee:0x0048EAA0, global:0x005A7218]
    // CALL: Ids 16 and 22: allocate 412 bytes, run the large constructor, run a post-construction computation on the field at index 96, install vtable off_5A7168, cache and return. [callee:0x00587C03, callee:0x0048EAA0, callee:0x004C5DB0, global:0x005A7168]
    // CALL: Ids 17 and 24: allocate 396 bytes and run the specialized constructor that receives the type id, then cache and return. [callee:0x00587C03, callee:0x00477410]
    // CALL: Id 18: allocate 384 bytes, run the large constructor, install vtable off_5A70B8, cache and return. [callee:0x00587C03, callee:0x0048EAA0, global:0x005A70B8]
    // CALL: Id 20: allocate 388 bytes, run the large constructor, zero the field at index 96, install vtable off_5A72C8, cache and return. [callee:0x00587C03, callee:0x0048EAA0, global:0x005A72C8]
    // CALL: Ids 21 and 23: allocate 400 bytes and run the ShortComputation_66f0 constructor with the type id, cache and return. [callee:0x00587C03, callee:0x004766F0]
    // CALL: Id 27: allocate 380 bytes and run the vtable-and-sub-init constructor, cache and return. [callee:0x00587C03, callee:0x0046A4E0]
    // CALL: Id 28: allocate 524 bytes and run the fields-plus-vtable constructor, cache and return. [callee:0x00587C03, callee:0x0046A900]
    // CALL: Ids 30, 32 and 33: allocate 384 bytes and run the ShortComputation_b580 constructor with flag 0; id 31 runs the same constructor with flag 1; cache and return. [callee:0x00587C03, callee:0x0046B580]
    // CALL: Id 34: allocate 384 bytes and run the specialized 0x004750F0 constructor, cache and return. [callee:0x00587C03, callee:0x004750F0]
    // CALL: Ids 35 and 36: allocate 372 bytes, run the base init, install vtable off_5A7008, cache and return. [callee:0x00587C03, callee:0x004893C0, global:0x005A7008]
    // CALL: Id 37: allocate 288 bytes and run the specialized 0x0047A9E0 constructor, cache and return. [callee:0x00587C03, callee:0x0047A9E0]
    // CALL: Id 38: allocate 376 bytes and run the init-plus-vtable constructor, cache and return. [callee:0x00587C03, callee:0x0047BE70]
    // CALL: Ids 39 to 42: allocate 376 bytes, run the base init, install vtable off_5A6E98, set the flag field at index 93 to 1, cache and return; on allocation failure store 0 in the cache and return 0. [callee:0x00587C03, callee:0x004893C0, global:0x005A6E98]
    // CALL: Id 43: allocate 376 bytes and run the ShortComputation_e7d0 constructor, then cache the result. [callee:0x00587C03, callee:0x0046E7D0]
    // CALL: Id 44: allocate 376 bytes and run the vtable-state init constructor, then cache the result. [callee:0x00587C03, callee:0x0046EEC0]
    // CALL: Id 45: allocate 228 bytes and run the byte-parameter constructor with both parameters zero, then cache the result. [callee:0x00587C03, callee:0x00487220]
    // RETURN: Default (unhandled ids) and post-switch cases return the cached slot value; the dispatch is driven by the switch jump table pointer. [global:0x0047FA1C, source:raw]

    // Conservative worker pseudocode:
    //   int id = a2;
    //   if (id < 1 || id - 1 >= 508 || cache[id - 1]) return 0;
    //   if (id > 436) return cache[id - 1];
    //   if (id == 436) { p = alloc(772); cache[id-1] = p ? ConstructorWithBulkInitAndVTable(p) : 0; return cache[id-1]; }
    //   switch (id) {
    //     // each case: p = alloc(size); init(p); install vtable; cache[id-1] = p; return p;
    //     // on allocation failure cache[id-1] = 0 and return 0
    //   }
    // UNRESOLVED: No static callers; the owning class and the semantic meaning of each type id are not established.
    // UNRESOLVED: Id 4 jumps out of line to a block whose logic is not present in this function.
    // UNRESOLVED: The cache slot base index 1607 is a dword index; the backing allocation and slot count are not independently confirmed.
}
