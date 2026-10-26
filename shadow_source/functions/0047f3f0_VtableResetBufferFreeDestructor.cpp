// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F3F0
// Canonical corpus name: Destructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Destructor_0047f3f0.c

void UnknownObject::VtableResetBufferFreeDestructor()
{
    // Object destructor: resets the vtable pointer at this+0x0 to off_5A6E70, then frees each of three buffer pointers (at this+0x219C, this+0x2194, this+0x218C) via FreeWrapper_7bcf when non-null, then chains to base destructor sub_495300(this) and returns its result.
    // ASSIGNMENT: Reset the vtable pointer at this+0x0 to off_5A6E70 at entry. [field:this:0x00000000, global:0x005A6E70, source:raw]
    // GUARD: Guard: free the pointer at this+0x219C (this[2151]) only when non-null. [field:this:0x0000219C, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer at this+0x219C (this[2151]). [callee:0x00587BCF, field:this:0x0000219C, source:raw]
    // GUARD: Guard: free the pointer at this+0x2194 (this[2149]) only when non-null. [field:this:0x00002194, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer at this+0x2194 (this[2149]). [callee:0x00587BCF, field:this:0x00002194, source:raw]
    // GUARD: Guard: free the pointer at this+0x218C (this[2147]) only when non-null. [field:this:0x0000218C, source:raw]
    // CALL: Call FreeWrapper_7bcf on the pointer at this+0x218C (this[2147]). [callee:0x00587BCF, field:this:0x0000218C, source:raw]
    // CALL: Chain to base destructor sub_495300(this); its return value is returned to the caller. [source:raw]
    // RETURN: Return the result of the chained base destructor sub_495300(this). [function:0x0047F3F0, source:raw]
    // CALL: Invoked by SimpleGetter (0x0047F3D0) as the object teardown path. [caller:0x0047F3D0, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall VtableResetBufferFreeDestructor(LPVOID* this) {
    //     *this = off_5A6E70;
    //     if (this[2151]) FreeWrapper_7bcf(this[2151]);
    //     if (this[2149]) FreeWrapper_7bcf(this[2149]);
    //     if (this[2147]) FreeWrapper_7bcf(this[2147]);
    //     return sub_495300(this);
    //   }
    // UNRESOLVED: The three freed pointers at 0x218C/0x2194/0x219C are buffer allocations freed when non-null; their allocation sites and buffer purpose are outside this packet.
    // UNRESOLVED: Base destructor sub_495300 is identified only by the raw-source name; it is not present in the packet callee list and its contract is unknown here.
    // UNRESOLVED: Class identity (ScreenData texture manager per the DERIVED skeleton fill) is unverified; off_5A6E70 vtable object type is UNKNOWN.
}
