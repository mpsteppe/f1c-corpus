// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C220
// Canonical corpus name: sub_53C220
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53C220_0053c220.c

void UnknownObject::RegisterTableBelowOnce()
{
    // One-time guarded initialization: while bit 1 (value 0x1) of flag byte_8B8EE5 is clear, latches that bit, seeds a cursor to unk_8B8C38 and a counter to 8, then walks the cursor backwards in 68-byte steps calling the stub EmptyStub_0170 before each decrement, running exactly 8 iterations. The guard makes the whole pass run at most once per process. The cursor is stepped before the call, so the stub sees the address one stride below the previous cursor position; the stub's arguments are not visible in the raw source.
    // GUARD: Bit-flag guard on byte_8B8EE5: the pass runs only while bit 1 (value 1) is clear, so the registration is performed at most once per process. [global:0x008B8EE5, source:raw]
    // ASSIGNMENT: Latch the flag by setting bit 1 in byte_8B8EE5 before the pass runs. [global:0x008B8EE5, source:raw]
    // ASSIGNMENT: Seed the walking cursor v0 to the address of unk_8B8C38 and the iteration counter v1 to 8. [source:raw]
    // LOOP: do-while loop counting v1 down from 8, so the body runs exactly 8 times. [source:raw]
    // CALCULATION: Step the cursor backwards by 68 bytes per iteration (v0 -= 68) before the stub call. [source:raw]
    // CALL: Call EmptyStub_0170 each iteration; the raw source shows no arguments and no callee address for this stub. [source:raw]

    // Conservative worker pseudocode:
    //   void RegisterTableBelowOnce() {
    //     if ((byte_8B8EE5 & 1) == 0) {
    //       byte_8B8EE5 |= 1;
    //       char *v0 = (char *)&unk_8B8C38;
    //       int v1 = 8;
    //       do { v0 -= 68; EmptyStub_0170(); --v1; } while (v1);
    //     }
    //   }
    // UNRESOLVED: EmptyStub_0170 has no callee address evidence in this packet and the raw source shows the call with no arguments; whether it is passed the current cursor v0 is unproven.
    // UNRESOLVED: dword_8B78A0 (0x008B78A0) is recorded in the packet facts as read but does not appear in the raw decompiled body; likely a decompiler artifact or a fact-table over-report.
    // UNRESOLVED: The object type and element layout of the region below unk_8B8C38 (68-byte stride) are not evidenced.
}
