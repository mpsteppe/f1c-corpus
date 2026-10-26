// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059ABCD
// Canonical corpus name: ObjectConstructorWithVTableAndStringInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTableAndStringInit_0059abcd.c

void UnknownObject::ObjectConstructorWithVTableAndStringInit()
{
    // Object constructor. Registers the SEH frame, sets the reference count at +0x4 to 1, installs the std::locale::facet vtable, copies two flag bytes from caller parameters to +0x14 and +0x18, zeroes the range +0x8..+0x10, re-initializes the embedded reference-counted string buffer at +0x18 from global word_5C406C (via Strlen + BufferWriteWithNullTerminate), then overrides the vtable with off_5B9D4C and returns the object.
    // CALL: SEHHandlerInit registers the SEH handler for this frame; the landing pad is loc_59D510. [callee:0x0058A5D8, global:0x0059D510]
    // ASSIGNMENT: Store the object pointer v2 into the frame slot at a1-16. [source:raw]
    // ASSIGNMENT: Set the reference count at object+0x4 to 1. [source:raw]
    // ASSIGNMENT: Install the initial vtable: std::locale::facet (??_7facet@locale@std@@6B@). [global:0x005B9D54]
    // ASSIGNMENT: Copy the flag byte at caller slot a1+8 (this+0x8) into object+0x14. [field:this:0x00000008]
    // ASSIGNMENT: Copy the low byte of caller slot a1+11 (this+0xB) into object+0x18 (v3[6] via the byte store at v3+24). [field:this:0x0000000B]
    // ASSIGNMENT: Zero the object dwords at +0x8, +0xC and +0x10 (v3[2], v3[3], v3[4]). [source:raw]
    // ASSIGNMENT: Clear the frame slot at a1-4 to 0. [source:raw]
    // CALL: ReferenceCountDecrementWithConditionalFree(object+0x18, 0) releases the previous reference-counted string buffer at +0x18 before re-init. [callee:0x005993AF]
    // CALL: Strlen(&word_5C406C) computes the length of the init string constant. [callee:0x0058E1B0, global:0x005C406C]
    // CALL: BufferWriteWithNullTerminate(object+0x18, &word_5C406C, len) copies the init string into the buffer with a null terminator. [callee:0x00599615, global:0x005C406C]
    // ASSIGNMENT: Override the vtable with off_5B9D4C after initialization. [global:0x005B9D4C]
    // RETURN: Return the constructed object v3. [source:raw]

    // Conservative worker pseudocode:
    //   void* ObjectConstructorWithVTableAndStringInit(void* frame, void* obj, int* args) {
    //     SEHHandlerInit();
    //     void* result = obj;
    //     *(void**)(frame - 16) = obj;
    //     *(int*)((char*)obj + 4) = 1;
    //     *(void**)obj = &std::locale::facet::vftable;
    //     *(byte*)((char*)obj + 20) = *(byte*)(frame + 8);
    //     byte flag = *(byte*)(frame + 11);
    //     *(int*)((char*)obj + 8) = 0;
    //     *(int*)((char*)obj + 12) = 0;
    //     *(int*)((char*)obj + 16) = 0;
    //     *(byte*)((char*)obj + 24) = flag;
    //     *(int*)(frame - 4) = 0;
    //     ReferenceCountDecrementWithConditionalFree((char*)obj + 24, 0);
    //     unsigned int len = Strlen(&word_5C406C);
    //     BufferWriteWithNullTerminate((char*)obj + 24, &word_5C406C, len);
    //     *(void**)obj = &off_5B9D4C;
    //     return result;
    //   }
    // UNRESOLVED: Why the vtable is installed twice (std::locale::facet then overridden with off_5B9D4C) is not resolvable from this function alone.
    // UNRESOLVED: Semantics of the two flag bytes read from a1+8 and a1+11 depend on the caller's parameter layout.
    // UNRESOLVED: The role of the low-byte value stored at +0x18 before BufferWriteWithNullTerminate overwrites the buffer is unclear.
}
