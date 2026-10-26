// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005642F0
// Canonical corpus name: StructAllocInitWithSwitchBasedType
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructAllocInitWithSwitchBasedType_005642f0.c

void UnknownObject::StructAllocInitWithSwitchBasedType()
{
    // Allocates a 20-byte heap struct via MallocWrapperForNhMalloc, initializes header fields (a1 at +0, short a2 at +4, constant 9999 at +6, type a3 at +8), then selects an element count by switch on a3 (types 0-3 give 2, default gives 4) and allocates a typed int array through AllocateIntArrayViaFactory with sub_5645F0 as element factory and IntegerDifferenceComparator as comparator. Stores the array pointer at +12 and a4 at +16, then returns the struct pointer.
    // CALL: Allocate a 20-byte struct via MallocWrapperForNhMalloc(20) and keep the pointer in v6. [callee:0x0058A935, source:raw]
    // ASSIGNMENT: Store the first caller argument a1 as a DWORD at v6+0. [source:raw]
    // ASSIGNMENT: Store the second caller argument a2 as a WORD at v6+4. [source:raw]
    // ASSIGNMENT: Store the constant 9999 as a WORD at v6+6. [source:raw]
    // ASSIGNMENT: Store the type selector a3 as a DWORD at v6+8. [source:raw]
    // GUARD: Switch on the type selector a3; cases 0, 1, 2 and 3 select element count 2, the default path (a3 >= 4) selects element count 4. Dispatch is routed through the jpt_56431C jump table. [global:0x00564378, source:raw]
    // CALL: Allocate the typed array via AllocateIntArrayViaFactory(v7, sub_5645F0, IntegerDifferenceComparator, 0) and store the array pointer as a DWORD at v6+12. [callee:0x005646D0, global:0x005645F0, global:0x00564620, source:raw]
    // ASSIGNMENT: Store the fourth caller argument a4 as a DWORD at v6+16. [source:raw]
    // RETURN: Return the initialized struct pointer v6. [source:raw]

    // Conservative worker pseudocode:
    //   v6 = MallocWrapperForNhMalloc(20);
    //   *(DWORD*)v6 = a1;
    //   *(WORD*)(v6+4) = a2;
    //   *(WORD*)(v6+6) = 9999;
    //   *(DWORD*)(v6+8) = a3;
    //   switch (a3) { case 0: case 1: case 2: case 3: v7 = 2; break; default: v7 = 4; break; }
    //   *(DWORD*)(v6+12) = AllocateIntArrayViaFactory(v7, sub_5645F0, IntegerDifferenceComparator, 0);
    //   *(DWORD*)(v6+16) = a4;
    //   return v6;
    // UNRESOLVED: Semantic meaning of the type selector a3 and of the constant 9999 written at offset +6 is not documented in this function.
    // UNRESOLVED: The element factory sub_5645F0 and comparator IntegerDifferenceComparator identity and role are caller-visible contracts only; the array element type is not confirmed.
    // UNRESOLVED: The owner class of the 20-byte struct is unknown; callers ConditionalNetworkUtility (00563160), DisplayModeQueryWrapper (005633d0) and sub_564110 (00564110) provide context only.
}
