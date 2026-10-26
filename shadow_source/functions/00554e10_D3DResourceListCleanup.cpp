// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554E10
// Canonical corpus name: D3DResourceListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DResourceListCleanup_00554e10.c

void UnknownObject::D3DResourceListCleanup()
{
    // Two-phase cleanup. First phase resets device parameters for every slot: gated on the slot count this+0x13B0 being greater than zero, it walks the parameter table starting at this+4472 in 17-DWORD steps and calls StateParameterSetterWithVirtualDeviceNotify on each entry with a null second argument. Second phase, only when a2 is non-null, walks a linked list of resource groups (head via a2+272 then the node pointer at +40, next pointer at DWORD index 23) and for every group whose item count at DWORD index 19 exceeds zero, walks the items in 96-byte steps calling UICleanupIterator on each item whose flag at (DWORD index 21)+24 has bit 0x80000 clear.
    // GUARD: First phase only runs when the slot count this+0x13B0 is greater than zero [guard:0, field:this:0x000013B0, source:raw]
    // LOOP: First loop walks the parameter table starting at this+4472 in 17-DWORD steps, once per entry counted by this+0x13B0 [field:this:0x000013B0, source:raw]
    // CALL: StateParameterSetterWithVirtualDeviceNotify invoked on each parameter-table entry with a null second argument to reset device state [callee:0x00554610, source:raw]
    // GUARD: Second phase requires a2 to be non-null before the resource-group list is traversed [source:raw]
    // ASSIGNMENT: Loads the head of the resource-group chain: reads the node pointer at a2+272 and dereferences +40 to obtain the first group node [source:raw]
    // LOOP: Outer loop walks the group linked list, advancing through the next pointer at DWORD index 23 until it becomes null [source:raw]
    // GUARD: Each group is processed only when its item count at DWORD index 19 is greater than zero [source:raw]
    // LOOP: Inner loop walks group items in 96-byte steps; only items whose flag at (DWORD index 21)+24 has bit 0x80000 clear are selected for cleanup [source:raw]
    // CALL: UICleanupIterator called on each non-protected item together with the owning object [callee:0x00554D70, source:raw]
    // RETURN: Returns a2 when it is null, otherwise the last traversed result value [source:raw]
    // CALL: Invoked by sub_4A0250, RenderTargetCleanup and sub_554F80 as a shared cleanup path [caller:0x004A0250, caller:0x0053F270, caller:0x00554F80, source:raw]

    // Conservative worker pseudocode:
    //   // Phase 1: reset each parameter slot
    //   // count = this[0x13B0/4];
    //   // if (count > 0) {
    //   //   entry = this + 4472;
    //   //   do { StateParameterSetterWithVirtualDeviceNotify(entry, 0); entry += 17; } while (++done < count);
    //   // }
    //   // Phase 2: walk resource groups when a2 is present, cleaning non-protected items
    // UNRESOLVED: The parameter-table entry layout (stride of 17 DWORDs) is not named by this packet; only the slot count field this+0x13B0 is flagged
    // UNRESOLVED: The resource-group chain offsets (a2+272, +40, DWORD indices 23/19/21, +24 and the 96-byte item stride) come from raw source only and are not packet-flagged fields
    // UNRESOLVED: The meaning of the 0x80000 flag (interpreted as protected/persistent resource marker) is not established by this packet
}
