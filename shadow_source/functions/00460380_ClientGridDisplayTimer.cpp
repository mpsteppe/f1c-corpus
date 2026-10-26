// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460380
// Canonical corpus name: ClientGridDisplayTimer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClientGridDisplayTimer_00460380.c

void UnknownObject::ClientGridDisplayTimer()
{
    // Timer-driven client grid overlay controller. While the session phase (this+0x3FC4) equals 3, decrements a 7.5-second countdown timer (this+0x1C) by the frame delta dbl_8AFE98; on expiry it refreshes scene state and toggles a grid display flag (this+0x20), then resets the timer. Runs only while a unique session ID is present.
    // GUARD: If the session phase at this+0x3FC4 does not equal 3, return immediately; the timer logic only runs during phase 3. [guard:0, field:this:0x00003FC4, source:raw]
    // CALCULATION: Decrement the countdown timer: this+0x1C -= dbl_8AFE98 (frame delta), storing the new value back. [field:this:0x0000001C, global:0x008AFE98, source:raw]
    // GUARD: If the timer is still non-negative (>= 0.0), return; expiry handling only runs when it goes below zero. [field:this:0x0000001C, source:raw]
    // CALL: Initialize the scratch description buffer via FAILWRONGDESCRIPTION(v4). [callee:0x00461550, source:raw]
    // CALL: Query the unique session ID via UniqueID(v4); if it is zero the expiry body is skipped. [callee:0x004630D0, source:raw]
    // ASSIGNMENT: Cache the current scene/module index dword_8AC48C into v3 for change detection. [global:0x008AC48C, source:raw]
    // CALL: Parse the current scene state into the scratch buffer via SceneDataParser(v5). [callee:0x004C5690, source:raw]
    // GUARD: If the grid display flag this+0x20 is set, run the hide sequence: SessionConfigWriteback(v4), AIW(0), SystemOSAPICall_0dc0(&unk_7CE24D), and (unless byte_7CE254 is set) sub_4A0030(&unk_7CE24C); then LookupDispatch(aMpclientgrid, -1) and clear this+0x20. [field:this:0x00000020, callee:0x00461900, callee:0x004C54F0, callee:0x004A0DC0, callee:0x004A0030, callee:0x00497940, global:0x007CE24D, global:0x007CE254, global:0x007CE24C, global:0x005C5F5C, source:raw]
    // STATE_TRANSITION: Otherwise, if the cached scene index v3 differs from the current dword_8AC48C, set the grid display flag this+0x20 to 1 (show). [field:this:0x00000020, global:0x008AC48C, source:raw]
    // ASSIGNMENT: Reset the countdown timer this+0x1C to 1089470464 (7.5f) after the expiry evaluation. [field:this:0x0000001C, source:raw]
    // CALL: Release/finalize the scratch buffer via EmptyStub_0170(v4). [callee:0x004B0170, source:raw]

    // Conservative worker pseudocode:
    //   if (this->sessionPhase != 3) return;
    //   this->timer -= dbl_8AFE98;
    //   if (this->timer < 0.0) {
    //     FAILWRONGDESCRIPTION(buf);
    //     if (UniqueID(buf)) {
    //       cached = dword_8AC48C;
    //       SceneDataParser(sceneBuf);
    //       if (this->gridFlag) {
    //         SessionConfigWriteback(buf); AIW(0);
    //         SystemOSAPICall_0dc0(&unk_7CE24D);
    //         if (!byte_7CE254) sub_4A0030(&unk_7CE24C);
    //         LookupDispatch(aMpclientgrid, -1);
    //         this->gridFlag = 0;
    //       } else if (cached != dword_8AC48C) {
    //         this->gridFlag = 1;
    //       }
    //       this->timer = 7.5f;
    //     }
    //     EmptyStub_0170(buf);
    //   }
    // UNRESOLVED: Globals flt_59E440, dword_59F0AC, dword_7CD25C, dword_7CD8C0 and unk_8AC368 are listed in the packet globals but do not appear in the raw source; their role in this function is unclear.
    // UNRESOLVED: this+0x3FC4 is a 4-byte phase check (== 3) at a large offset; the object layout is otherwise unknown (owner UNKNOWN).
    // UNRESOLVED: The exact meaning of LookupDispatch(aMpclientgrid, -1) (grid overlay lookup/dispatch) is DERIVED from the string and caller context.
}
