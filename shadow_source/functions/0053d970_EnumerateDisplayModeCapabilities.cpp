// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D970
// Canonical corpus name: sub_53D970
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53D970_0053d970.c

void UnknownObject::EnumerateDisplayModeCapabilities()
{
    // Enumerates display modes of a graphics sub-object at this+0x10FC. First zero-fills the per-mode entry array (this[2] entries of 0x43C bytes each, resetting the count to 0), then queries the mode count through sub-object vtable slot 4 (offset 16). For each mode it probes pixel-format capabilities through vtable slot 9 (offset 36) and builds a capability bitmask; when any capability bit is set it fetches mode info (vtable slot 13, offset 52) and framebuffer data (vtable slot 5, offset 20), packs a mode record, and hands it to sub_53D8B0. Returns the number of enumerated modes.
    // GUARD: Guard on this[2] > 0: zero-fill the entry array only when a previous count is stored. [field:this:0x00000008, guard:0, source:raw]
    // LOOP: Zero-fill this[2] entries of 0x43C (1084) bytes each starting at this+3 (dword index), stepping 1084 bytes per entry. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Reset the entry count this[2] to 0 after the zero-fill. [field:this:0x00000008, source:raw]
    // CALL: Query the display mode count through vtable slot 4 (offset 16) on the sub-object at this+0x10FC. [field:this:0x000010FC, field:*(this+0x10FC):0x00000010, source:raw]
    // LOOP: Iterate over the returned mode count, processing one display mode per iteration. [source:raw]
    // CALL: Probe pixel-format capability through vtable slot 9 (offset 36) on the sub-object for format codes 23, 24, 25, 20 and 22; each call result is stored to this[0]. [field:this:0x00000000, field:*(this+0x10FC):0x00000024, source:raw]
    // ASSIGNMENT: Accumulate a capability bitmask: 0x1000000 (23), 0x2000000 (24/25), 0x4000000 (24/24), 0x8000000 (20/20), 0x20000000 (22/22), 0x10000000 (22/21) when the respective capability probe fails. [source:raw]
    // GUARD: Only proceed to detailed mode querying when any capability bit is set (mask & 0x3F000000) != 0. [source:raw]
    // CALL: Fetch detailed mode info through vtable slot 13 (offset 52) and framebuffer data through vtable slot 5 (offset 20) on the sub-object. [field:*(this+0x10FC):0x00000034, field:*(this+0x10FC):0x00000014, source:raw]
    // GUARD: Accept the mode when the mode-info call succeeds or both stored dimensions exceed 512. [source:raw]
    // ASSIGNMENT: Pack the mode record v25: capability bitmask, mode index, width/height values and a name string copied from the framebuffer buffer; clear trailing fields. [source:raw]
    // CALL: Hand the completed mode record to sub_53D8B0 (0x0053D8B0) for each accepted mode. [callee:0x0053D8B0, source:raw]
    // RETURN: Return the number of modes enumerated (the mode count from the first vtable query). [source:raw]
    // CALL: Invoked by sub_53E070 (0x0053E070) and sub_55BE80 (0x0055BE80). [caller:0x0053E070, caller:0x0055BE80]

    // Conservative worker pseudocode:
    //   int sub_53D970(int *self) {
    //     for (int i = 0; i < self[2]; ++i) memset((char *)(self + 3) + i * 1084, 0, 0x43C);
    //     self[2] = 0;
    //     int count = (*(int (__stdcall **)(int))(*(int *)*sub + 16))(sub); /* vtable[4], sub = this[1087] * /
    //     for (int i = 0; i < count; ++i) {
    //       int mask = 0;
    //       /* probe format codes 20..25 via vtable[9]; OR 0x1000000..0x20000000 on failure * /
    //       if (mask & 0x3F000000) {
    //         /* vtable[13] mode info + vtable[5] framebuffer * /
    //         if (ok || (width > 512 && height > 512)) {
    //           build_record(rec); /* rec[0]=mask, rec[1]=i, width/height, name * /
    //           sub_53D8B0(this, rec);
    //         }
    //       }
    //     }
    //     return count;
    //   }
    // UNRESOLVED: The sub-object at this+0x10FC is an untyped graphics/display object; its vtable layout is inferred only from the four slots referenced (offsets 16, 20, 36, 52).
    // UNRESOLVED: The exact display-format codes passed to vtable[9] (20-25) and their mapping to the capability bitmask are not documented in this corpus.
    // UNRESOLVED: Argument a2 is unused in the shown raw source; its role in the caller's contract is unknown.
    // UNRESOLVED: The entry-array record layout (size 0x43C) and what sub_53D8B0 does with each record are only DERIVED from this call site.
}
