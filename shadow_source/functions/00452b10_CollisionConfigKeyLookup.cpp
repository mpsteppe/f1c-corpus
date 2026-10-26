// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00452B10
// Canonical corpus name: sub_452B10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_452B10_00452b10.c

void UnknownObject::CollisionConfigKeyLookup()
{
    // Collision/system config key lookup and re-init (thiscall). Sets this[0] to 1 (matched), then compares the key argument a2 against 68 known global config addresses in a long if/else chain; on a match stores the matched global's address in this[7] (offset 0x1C), otherwise clears this[7] and this[0] and records failure. When a match was found, writes the a3 value into the matched global at offset +8. Always calls SwapAndReinit on the trailing field block (count 89), clears this[8] (offset 0x20) and returns the status (0 on match, -1 on no match). Called by ShortComputation_30a0 (004530A0).
    // ASSIGNMENT: Sets this[0] (offset 0x0) to 1 at entry as the optimistic matched flag [field:this:0x00000000, source:raw]
    // CALCULATION: If/else chain compares a2 against 68 known global config addresses (each read-only); on equality stores that global's own address into this[7] (offset 0x1C) [field:this:0x0000001C, global:0x007CA3F8, global:0x007CA420, global:0x007CA458, global:0x007CA4A0, global:0x007CA4B8, global:0x007CA4E0, global:0x007CA51C, global:0x007CA534, global:0x007CA54C, global:0x007CA564, global:0x007CC9FC, global:0x007CCA14, global:0x007CCA2C, global:0x007CCA54, global:0x007CCBC4, global:0x007CCBDC, global:0x007CCC08, global:0x007CCC20, global:0x007CCC38, global:0x007CCC50, global:0x007CCC68, global:0x007CCC80, global:0x007CCC98, global:0x007CCCC0, global:0x007CCCD8, global:0x007CCCF0, global:0x007CCD08, global:0x007CCD20, global:0x007CCD38, global:0x007CCD50, global:0x007CCD68, global:0x007CCD80, global:0x007CCD98, global:0x007CCDB0, global:0x007CCDC8, global:0x007CCDE0, global:0x007CCDF8, global:0x007CCE10, global:0x007CCE28, global:0x007CCE40, global:0x007CCE58, global:0x007CCE70, global:0x007CCE88, global:0x007CCEA0, global:0x007CCEB8, global:0x007CCED0, global:0x007CCEE8, global:0x007CCF00, global:0x007CCF18, global:0x007CCF30, global:0x007CCF48, global:0x007CCFC4, global:0x007CCFEC, global:0x007CD004, global:0x007CD01C, global:0x007CD034, global:0x007CD04C, global:0x007CD064, global:0x007CD080, global:0x007CD098, global:0x007CD0B0, global:0x007CD0C8, global:0x007CD0E0, global:0x007CD118, global:0x007CD130, global:0x007CD1A8, global:0x007CD1C0, global:0x007CD1D8, source:raw]
    // ASSIGNMENT: No-match branch: clears this[7] and this[0], and records the failure status -1 in v4 [field:this:0x00000000, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: When a match was found (this[7] non-zero), writes the a3 value into the matched global at its +8 field [source:raw]
    // CALL: SwapAndReinit(this+1, 89, 0) reinitialises the trailing field block (including offset 0x24) with element count 89 and zero fill [callee:0x00452740, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Clears this[8] (offset 0x20) before returning [field:this:0x00000020, source:raw]
    // RETURN: Returns the status: 0 when a key matched, -1 when no global matched [source:raw]
    // CALL: Invoked by ShortComputation_30a0 (004530A0) to resolve a collision config key [caller:0x004530A0, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 1;
    //   matched = 0;
    //   if (a2 == dword_7CCD50) this[7] = (int)&dword_7CCD50;
    //   else if (a2 == dword_7CCD38) this[7] = (int)&dword_7CCD38;
    //   ... // chain of 68 compares; on any equality this[7] = &that global
    //   else { this[7] = 0; this[0] = 0; matched = -1; }
    //   if (this[7] != 0) *(this[7] + 8) = a3;
    //   SwapAndReinit(this + 1, 89, 0);
    //   this[8] = 0;
    //   return matched;
    // UNRESOLVED: The 68 globals are only known by address here; their individual collision/system roles come from outside this packet
    // UNRESOLVED: The purpose of writing a3 into the matched global's +8 field (and its meaning) is not resolvable from this function alone
    // UNRESOLVED: SwapAndReinit resets a larger trailing field block; the concrete meaning of its count parameter (89) and the exact extent of the reset region are defined by that callee, not here
}
