// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405D70
// Canonical corpus name: MilesSoundSystemFilterOpenByIndex
// Owner: MilesSoundSystem [DERIVED]
// Raw source: functions/MilesSoundSystemFilterOpenByIndex_00405d70.c

void MilesSoundSystem::OpenFilterByIndex()
{
    // Opens a Miles audio filter by index (0-3): resolves the filter name string for the index via sub_404FA0, enumerates available Miles filters with AIL_enumerate_filters until the name matches, and, when the config pointer this+0x54 is set, opens the matched filter with AIL_open_filter (provider handle at config+0xE4) and stores the index, filter handle, and provider parameter into this+0x60/0x64/0x68.
    // GUARD: Require a2 < 4 (valid filter index 0-3); otherwise return 0 without acting. [source:raw, function:0x00405D70]
    // CALL: Look up the filter name string for index a2 via sub_404FA0 (callee 0x00404FA0); abort when the name is null. [callee:0x00404FA0, source:raw]
    // CALL: Enumerate Miles filters with AIL_enumerate_filters (global 0x0059E3B0), strcmp-looping until a name match or enumeration end. [global:0x0059E3B0, source:raw]
    // GUARD: Require the enumeration to have produced a valid filter handle (a2 != -1) before opening. [source:raw]
    // CALL: When this[0x54] (config pointer) is set, open the matched filter via AIL_open_filter (global 0x0059E3B4) using the provider handle stored at config+0xE4. [field:this:0x00000054, field:this:0x000000E4, global:0x0059E3B4, source:raw]
    // ASSIGNMENT: Store the original index a2 in this[0x60], the matched Miles filter handle in this[0x64], and the provider parameter a3 in this[0x68]. [field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, source:raw]
    // RETURN: Return 0 on all completion paths. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 >= 4) return 0;
    //   name = sub_404FA0(a2);
    //   if (name && AIL_enumerate_filters(&state, &handle, &fname)) {
    //     while (strcmp(fname, name)) if (!AIL_enumerate_filters(&state, &handle, &fname)) return 0;
    //     if (handle != -1 && this[0x54]) {
    //       AIL_open_filter(handle, *(this[0x54] + 0xE4));
    //       this[0x60] = v3; this[0x64] = handle; this[0x68] = a3;
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: Offset 0xE4 is read from the config object referenced by this[0x54], not from this itself; the config object's class is unknown.
    // UNRESOLVED: sub_404FA0's exact behavior (index-to-name lookup) is inferred from usage, not independently evidenced.
    // UNRESOLVED: The AIL filter handle in this[0x64] is written but never consumed within this packet, so its downstream use is unresolved.
    // UNRESOLVED: No callers exist in the packet, so the invocation context is unknown.
}
