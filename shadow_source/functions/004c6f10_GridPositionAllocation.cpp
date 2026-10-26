// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6F10
// Canonical corpus name: sub_4C6F10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C6F10_004c6f10.c

void UnknownObject::GridPositionAllocation()
{
    // Allocates this vehicle to a free slot on the starting grid. Seeds the slot index at this+0x48A4 from this+0x4894 modulo 52, then scans up to 52 slots via IndexedArrayAccessor + sub_588410 for an unoccupied one. Computes a team-column order from this+0x4710 (forward/reverse permutation of the column triple). Copies the slot position from the setup scene (dword_5EA2C0) with ArrayOfStructIndexedFieldCopy and, when the slot is empty, walks candidate columns writing this+0x48A8 and checks dword_5C329C vehicles in dword_7C54F0 for an occupant already holding the same slot and column. A fallback loop rescans all 52 slots with per-column occupancy reads (IndexedStructDataRead); on exhaustion sets this+0x48A4 and this+0x48A8 to -1.
    // STATE_TRANSITION: Invoked from MultiplayerVehiclePlacement, ConditionalDelegateDispatch, and RenderCallWithGuard on the frame path. [caller:0x0042CF10, caller:0x004D1100, caller:0x004D1140, function:0x004C6F10]
    // ASSIGNMENT: Seed allocated slot index this+0x48A4 from this+0x4894 modulo 52. [field:this:0x00004894, field:this:0x000048A4, source:raw]
    // LOOP: Scan up to 52 grid slots via IndexedArrayAccessor; sub_588410(this + 0x46B8, entry) marks a slot as occupied; first passing slot index is stored to this+0x48A4. [callee:0x004D1410, callee:0x00588410, field:this:0x000048A4]
    // CALCULATION: Derive the column-order permutation from this+0x4710: default column triple (0,2,1), swapped to (2,0,1) when the parity test ((v4 & 1) != v4 < 13) holds. [field:this:0x00004710]
    // ASSIGNMENT: Read dword_7D0B40 as the candidate column count; cap the fallback iteration bound at 3. [global:0x007D0B40]
    // CALL: ArrayOfStructIndexedFieldCopy(dword_5EA2C0, slot this+0x48A4, dst, src) copies the grid slot position data from the setup scene. [callee:0x00403F70, global:0x005EA2C0, field:this:0x000048A4]
    // CALL: ZeroVectorCheck on the copied vector; a near-zero position marks the slot as unoccupied. [callee:0x00404030]
    // LOOP: Walk the candidate columns writing this+0x48A8 = column index; for each, scan the dword_5C329C vehicles in dword_7C54F0 for an occupant v9 != this whose +0x48A4 equals this+0x48A4 and +0x48A8 equals the candidate column; a slot/column pair with no occupant is taken. [field:this:0x000048A8, global:0x005C329C, global:0x007C54F0, field:this:0x000048A4]
    // LOOP: Fallback: rescan slots 0..51 (up to 2 passes), re-reading occupancy with ArrayOfStructIndexedFieldCopy + ZeroVectorCheck and per-column data with IndexedStructDataRead; on a free (slot, column) pair write this+0x48A8 and return. [callee:0x00403F70, callee:0x00404030, callee:0x00403FC0, global:0x005EA2C0, global:0x005C329C, global:0x007C54F0, field:this:0x000048A4, field:this:0x000048A8]
    // ASSIGNMENT: On allocation failure set this+0x48A4 and this+0x48A8 to -1. [field:this:0x000048A4, field:this:0x000048A8]

    // Conservative worker pseudocode:
    //   this->dword[0x48A4] = this->dword[0x4894] % 52
    //   for (v2 = 0; v2 < 52; ++v2) {
    //       v3 = IndexedArrayAccessor(v2)
    //       if (!v3) break
    //       if (!sub_588410(this + 0x46B8, v3)) { this->dword[0x48A4] = v2; break }
    //   }
    //   cols = (this->dword[0x4710] & 1) != this->dword[0x4710] < 13 ? (2,0,1) : (0,2,1)
    //   count = dword_7D0B40 (capped at 3 for fallback)
    //   ArrayOfStructIndexedFieldCopy(dword_5EA2C0, slot, dst, src)
    //   if (ZeroVectorCheck(dst, src) && count > 0) {
    //       for each column c in cols:
    //           this->dword[0x48A8] = c
    //           for (i = 0; i < dword_5C329C; ++i) if (dword_7C54F0[i] != this && same_slot && same_column) break
    //           if (i == dword_5C329C) return
    //   }
    //   fallback: rescan slots 0..51 (max 2 passes), IndexedStructDataRead per column, return on first free (slot,column)
    //   this->dword[0x48A4] = -1
    //   this->dword[0x48A8] = -1
    // UNRESOLVED: flt_59E440 and dword_8ACEE0 appear in the IDB global list but are not referenced by the raw source; their role here is unresolved.
    // UNRESOLVED: The parity test ((v4 & 1) != v4 < 13) on this+0x4710 is a grid-layout heuristic whose exact semantics (DERIVED forward/reverse column order) are unproven.
    // UNRESOLVED: abi:lead LEGACY name AssignDriverGridPosition conflicts with the GridPositionAllocation interpretation; owner remains UnknownObject.
    // UNRESOLVED: Vehicle slot/column fields on peer vehicles at +18596 and +18600 are read as raw offsets, not packet field references.
}
