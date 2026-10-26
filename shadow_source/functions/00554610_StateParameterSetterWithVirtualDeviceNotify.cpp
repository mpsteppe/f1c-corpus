// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554610
// Canonical corpus name: StateParameterSetterWithVirtualDeviceNotify
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateParameterSetterWithVirtualDeviceNotify_00554610.c

void UnknownObject::StateParameterSetterWithVirtualDeviceNotify()
{
    // Sets a device-backed parameter: when the new value pointer a2 differs from the stored one at this+0x30, dispatches a stdcall virtual method at vtable slot +244 on the global GameDeviceObject (dword_8B89A0), passing the object identifier *this (this+0x0) and a parameter value read from *(*(a2 + 84) + 20) when a2 is non-null or 0 when a2 is null, then stores a2 (or 0) into this+0x30. When a2 equals the stored pointer, the dispatch is skipped. Used by state field setters and cleanup iterators.
    // GUARD: Early-out guard: when a2 equals this[12] (the stored pointer at this+0x30), the dispatch is skipped and the stored value is returned unchanged. [source:raw, field:this:0x00000030]
    // CALCULATION: Read the device object's vtable pointer v4 from the global dword_8B89A0 and select the slot at v4 + 244. [source:raw, global:0x008B89A0]
    // CALCULATION: Build the parameter value: when a2 is non-null, dereference the object pointer at a2 + 84 and read the dword at offset +20 of that inner object; when a2 is null, use 0. [source:raw]
    // CALL: Dispatch the __stdcall virtual method at vtable slot +244 on dword_8B89A0 with (dword_8B89A0, *this, parameter value), using the object identifier from this+0x0 as the second argument. [source:raw, field:this:0x00000000, global:0x008B89A0]
    // ASSIGNMENT: After a successful non-null dispatch store a2 into this[12] (this+0x30); in the null branch store 0 into this+0x30. [field:this:0x00000030]
    // RETURN: Return the virtual dispatch result, or the unchanged stored pointer this+0x30 when the guard skipped the dispatch. [source:raw, field:this:0x00000030]
    // CALL: Called by StateFieldSetWithChainedInit (0x00553FA0), MultiFieldSetterDispatchingTo7SubSetters (0x005546A0), UICleanupIterator (0x00554D70) and D3DResourceListCleanup (0x00554E10) to set or clear this device-backed parameter. [caller:0x00553FA0, caller:0x005546A0, caller:0x00554D70, caller:0x00554E10, source:raw]

    // Conservative worker pseudocode:
    //   int StateParameterSetterWithVirtualDeviceNotify(void *this, void *a2) {
    //     if (a2 == this[12]) return this[12];
    //     int *vtable = *(int **)dword_8B89A0;
    //     int value = a2 ? *(int *)(*(int *)((char *)a2 + 84) + 20) : 0;
    //     int result = ((int (__stdcall *)(int, int, int))(vtable[61]))(dword_8B89A0, *(int *)this, value);
    //     this[12] = a2;
    //     return result;
    //   }
    // UNRESOLVED: The concrete callee behind the indirect dispatch at vtable slot +244 (0xF4) of the global device object is not established by this packet.
    // UNRESOLVED: The layout of the parameter-source object a2 (offsets +84 and +84+20) and the meaning of the parameter value are not in the packet field set.
    // UNRESOLVED: The object that owns this (type, identity of the stored pointer at this+0x30) is unknown.
}
