// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C1C0
// Canonical corpus name: sub_53C1C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53C1C0_0053c1c0.c

void UnknownObject::RegisterStubArrayOnce()
{
    // One-time guarded initialization that sets bit 2 of flag byte_8B8EE4, then walks a fixed table backwards from dword_8B78A0 in 19-dword (76-byte) steps across exactly 42 entries, calling EmptyStub_7470 on each entry pointer. The guard makes the whole pass run at most once per process. The table base and the meaning of the per-entry stub call are not evidenced by the packet.
    // GUARD: Bit-flag guard on byte_8B8EE4: the whole pass runs only while bit 2 is clear, so the registration is performed at most once. [global:0x008B8EE4, source:raw]
    // ASSIGNMENT: Latch the flag by setting bit 2 in byte_8B8EE4 before the pass runs. [global:0x008B8EE4, source:raw]
    // ASSIGNMENT: Seed the table cursor v0 from dword_8B78A0 and the iteration counter v1 to 42. [global:0x008B78A0, source:raw]
    // LOOP: do-while loop counting v1 down from 42, so the body runs exactly 42 times. [source:raw]
    // CALCULATION: Step the cursor backwards by 19 dwords (76 bytes) per iteration, walking the table from its top entry downward. [global:0x008B78A0, source:raw]
    // CALL: Call EmptyStub_7470 with each table entry pointer as its single argument. [callee:0x00557470, source:raw]

    // Conservative worker pseudocode:
    //   if ((byte_8B8EE4 & 2) == 0) {
    //     byte_8B8EE4 |= 2;
    //     cursor = dword_8B78A0;
    //     n = 42;
    //     do { cursor -= 19; EmptyStub_7470(cursor); --n; } while (n);
    //   }
    // UNRESOLVED: EmptyStub_7470 is a decompiler-named stub; whether the per-entry call registers, constructs, or tears down each table entry is not evidenced.
    // UNRESOLVED: The layout of the 42-entry table behind dword_8B78A0 (element type, 19-dword stride) is not described by the packet; the backwards walk is structural only.
    // UNRESOLVED: Bit 2 of byte_8B8EE4 behaves as a one-time initialization latch; other writers of this flag are not evidenced.
}
