// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D88D0
// Canonical corpus name: sub_4D88D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D88D0_004d88d0.c

void UnknownObject::sub_4D88D0()
{
    // Race render resource allocation. Builds a 25-slot pointer array at this+0x10, each slot filled by Direct3DObjectFactory(index) only when IDTypePermissionMatrix permits that index for the current championship mode (dword_7D0410). Allocates a 3-slot sub-object array (first slot this+29) via sub_4DB420, conditionally creates one object at this+0xC when RangeCheck_93e0(0, mode) passes, and stores a fixed-node allocator at this+0xD8. Returns 0. Called once during race init from RaceInitWithConstants.
    // ASSIGNMENT: Load the current championship/race mode global dword_7D0410 into a local used by the permission and range checks. Invoked from RaceInitWithConstants. [global:0x007D0410, caller:0x004D8220, function:0x004D88D0, source:raw]
    // LOOP: For index 0..24, gate each slot on IDTypePermissionMatrix(index, mode): when permitted, store Direct3DObjectFactory(index) into the 25-entry pointer array beginning at this+0x10. [callee:0x004D9290, callee:0x004DAEA0, field:this:0x00000010, source:raw]
    // LOOP: For index 0..2, store sub_4DB420(index) into the 3-slot sub-object array whose first slot is this+29. [callee:0x004DB420, source:raw]
    // GUARD: When RangeCheck_93e0(0, mode) passes, store sub_4DC220(0) at this+0xC. [callee:0x004D93E0, callee:0x004DC220, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the FixedNodeAllocator() result at this+0xD8. [callee:0x004DC290, field:this:0x000000D8]
    // RETURN: Return 0 on completion. [function:0x004D88D0, source:raw]

    // Conservative worker pseudocode:
    //   mode = dword_7D0410;                       // championship/race mode
    //   for (i = 0; i < 25; ++i)                   // array at this+0x10
    //       if (IDTypePermissionMatrix(i, mode))
    //           this->obj[i] = Direct3DObjectFactory(i);
    //   for (i = 0; i < 3; ++i)                    // sub-object array at this+29
    //       this->sub[i] = sub_4DB420(i);
    //   if (RangeCheck_93e0(0, mode))
    //       this->cond = sub_4DC220(0);            // this+0xC
    //   this->allocator = FixedNodeAllocator();    // this+0xD8
    //   return 0;
    // UNRESOLVED: The three sub-object slots at this+29..31 are written but have no packet field entries; their purpose is undetermined.
    // UNRESOLVED: The exact meaning of RangeCheck_93e0(0, mode) and why the object at this+0xC is created only conditionally is unresolved.
}
