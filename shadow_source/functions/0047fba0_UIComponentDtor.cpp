// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047FBA0
// Canonical corpus name: UIComponentDtor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentDtor_0047fba0.c

void UnknownObject::UIComponentDtor()
{
    // Deleting destructor for a generic UI component. Installs the off_5A6E98 vtable at this+0x0, calls FunctionCallWrapper_9440(this) to run the sub-object/base cleanup path, then, when the low bit of the a2 flag is set, calls FreeWrapper_7bcf(this) to release the object's own memory. Returns this unchanged.
    // ASSIGNMENT: *this = &off_5A6E98; install the vtable pointer for this component type at this+0x0 before any cleanup runs [field:this:0x00000000, global:0x005A6E98]
    // CALL: FunctionCallWrapper_9440(this); run the wrapped sub-object/base cleanup routine on the instance [callee:0x00489440, function:0x0047FBA0]
    // GUARD: if ( (a2 & 1) != 0 ) { ... }; the low bit of a2 decides whether the object's own storage is freed [source:raw, function:0x0047FBA0]
    // CALL: FreeWrapper_7bcf(this); conditionally release the instance memory inside the guarded branch [callee:0x00587BCF, source:raw]
    // RETURN: return this; the thiscall convention returns the instance pointer, which is unchanged by destruction [field:this:0x00000000, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   *this = &off_5A6E98;
    //   FunctionCallWrapper_9440(this);
    //   if ( (a2 & 1) != 0 )
    //     FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: the exact cleanup performed by FunctionCallWrapper_9440 (base-class destructor vs member cleanup dispatcher) is not evidenced in the packet
    // UNRESOLVED: the object type owned by vtable off_5A6E98 is not identified; owner stays UnknownObject/UNKNOWN
    // UNRESOLVED: the allocator paired with FreeWrapper_7bcf and whether it matches the allocation used at construction is unverified
    // UNRESOLVED: the high bits of a2 are unused in this function; only the low bit is tested
}
