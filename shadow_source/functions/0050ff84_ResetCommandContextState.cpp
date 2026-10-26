// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FF84
// Canonical corpus name: sub_50FF84
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FF84_0050ff84.c

void UnknownObject::ResetCommandContextState()
{
    // Command context state initialization. Sets the state dispatcher code at obj+0x14 to 101 and dispatches (obj,1), then switches to state 60 with a no-arg dispatch when the re-entry flag at *(this+0x190)+0x50 is already set. Initializes three 16-byte field arrays near this+0xDA (values 1, 5 and 0 respectively), resets a set of context fields (DWORDs this+0x24 and this+0xFC to 0, bytes this+0x100/0x101/0x106/0x107/0x108 to 0, words this+0x102/0x104 to 1), sets the re-entry guard flag to 1, and returns 1.
    // ASSIGNMENT: Set the state code at obj+0x14 to 101 (primary entry state) before the first dispatch [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // CALL: Dispatch through the parameterized vtable entry at obj+0x4 with (this, 1) [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // GUARD: Branch on the re-entry flag byte at *(this+0x190)+0x50; when non-zero the state is reset instead of initialized [field:*(this+0x190):0x00000050, field:this:0x00000190, source:raw]
    // ASSIGNMENT: Override the state code at obj+0x14 to 60 when the re-entry flag is already set [field:obj:0x00000014, source:raw]
    // CALL: Dispatch through the no-arg vtable entry at obj+0x0 with (this) for the re-entry path [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // LOOP: 16 iterations writing constant bytes into three parallel field arrays: 1 into this+0xDA, 5 into this+0xEA, and 0 into the byte range 16 bytes before this+0xDA [field:this:0x000000DA, field:this:0x000000EA, source:raw]
    // ASSIGNMENT: Reset two DWORD context fields to 0: this+0x24 and this+0xFC [field:this:0x00000024, field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Reset byte context fields to 0 at this+0x100, this+0x101, this+0x106, this+0x107 and this+0x108 [field:this:0x00000100, field:this:0x00000101, field:this:0x00000106, field:this:0x00000107, field:this:0x00000108, source:raw]
    // ASSIGNMENT: Set word context fields to 1 at this+0x102 and this+0x104 [field:this:0x00000102, field:this:0x00000104, source:raw]
    // ASSIGNMENT: Set the re-entry guard flag at *(this+0x190)+0x50 to 1 so a later entry takes the state-60 path [field:*(this+0x190):0x00000050, source:raw]
    // RETURN: Return 1 to the caller CommandDispatchStateMachine (0051126a) as success [function:0x0050FF84, caller:0x0051126A, source:raw]

    // Conservative worker pseudocode:
    //   dispatcher = *this;
    //   dispatcher->state = 101;
    //   dispatcher->dispatch(this, 1);
    //   if (*(*(this+0x190) + 0x50)) {
    //     dispatcher->state = 60;
    //     dispatcher->dispatch0(this);
    //   }
    //   for (i = 0; i < 16; ++i) {
    //     *(this+0xDA - 16 + i) = 0;
    //     *(this+0xDA + i) = 1;
    //     *(this+0xEA + i) = 5;
    //   }
    //   *(this+0x24) = 0; *(this+0xFC) = 0;
    //   *(this+0x100) = *(this+0x101) = 0;
    //   *(this+0x102 as word) = 1; *(this+0x104 as word) = 1;
    //   *(this+0x106) = *(this+0x107) = *(this+0x108) = 0;
    //   *(*(this+0x190) + 0x50) = 1;
    //   return 1;
    // UNRESOLVED: The semantics of the three 16-byte field arrays (this+0xDA=1, this+0xEA=5, and the zeroed range sixteen bytes below this+0xDA) are unknown; the zeroed range has no packet field reference and is derived from the loop stride
    // UNRESOLVED: obj+0x14 state values 101/60 and the dispatch argument 1 are not interpreted by this function
}
