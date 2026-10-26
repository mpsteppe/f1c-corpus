// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A8FA
// Canonical corpus name: sub_59A8FA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A8FA_0059a8fa.c

void UnknownObject::GlobalObjectTableRegister()
{
    // Registers the this object in a global 8-slot object table. Calls sub_59A54D (CRT/SEH init prologue) with a local stack buffer. When the slot index at this[9] (offset 0x24) is below 8 it linearly searches the table dword_8D4618 for either an empty slot or a slot already holding this, advancing this[9] until index 8. It then writes this into dword_8D4618[this[9]] and increments the ref-count byte byte_8D463C[this[9]], finishing with sub_59A5E9 (cleanup epilogue). Called by several object constructor/init routines.
    // CALL: sub_59A54D(v5) runs the prologue/SEH setup on a local stack buffer (CRT init prologue per existing analysis) [callee:0x0059A54D, source:raw]
    // GUARD: Only search the table while the slot index this[9] (offset 0x24) is less than 8 [field:this:0x00000024, guard:0, source:raw]
    // LOOP: do-while scan of dword_8D4618 from index this[9] until a free or self slot is found, or index reaches 8 [global:0x008D4618, source:raw]
    // GUARD: Break when dword_8D4618[this[9]] is null (empty slot found) [global:0x008D4618, source:raw]
    // GUARD: Break when dword_8D4618[this[9]] already equals this (already registered) [global:0x008D4618, source:raw]
    // ASSIGNMENT: Advance this[9] = v2 + 1 and loop while v4 < 8 [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Store this in the selected slot: dword_8D4618[this[9]] = (int)this [global:0x008D4618, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Increment the ref-count byte byte_8D463C[this[9]] [global:0x008D463C, field:this:0x00000024, source:raw]
    // CALL: sub_59A5E9() runs the cleanup epilogue (CRT/SEH unwind teardown per existing analysis) [callee:0x0059A5E9, source:raw]

    // Conservative worker pseudocode:
    //   void sub_59A8FA(int this) {
    //     BYTE v5[4];
    //     sub_59A54D(v5);
    //     unsigned int i = this[9];
    //     if (i < 8) {
    //       do {
    //         int* slot = &dword_8D4618[i];
    //         if (!*slot) break;
    //         if ((_DWORD*)*slot == this) break;
    //         i = i + 1;
    //         this[9] = i;
    //       } while (i < 8);
    //     }
    //     dword_8D4618[this[9]] = (int)this;
    //     ++byte_8D463C[this[9]];
    //     sub_59A5E9();
    //   }
    // UNRESOLVED: Owner object identity is unknown; the global table dword_8D4618 and ref-count array byte_8D463C have no confirmed type or consumer
    // UNRESOLVED: The role of sub_59A54D/sub_59A5E9 as SEH/CRT wrappers is taken from the existing analysis (DERIVED), not proven by the packet
    // UNRESOLVED: All six callers are constructor/init routines but the table's consumer elsewhere is not established
}
