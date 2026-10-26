// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005881C0
// Canonical corpus name: __alloca_probe
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/__alloca_probe_005881c0.c

void UnknownObject::AllocaStackProbe()
{
    // MSVC CRT stack probe (_alloca_probe). Walks the stack pointer downward in 4096-byte strides while the requested allocation size a1 is at least 0x1000, touching each intervening page so the OS guard pages fire for large stack-frame growth. Returns via the bare retn that the original alloca call pushed, so it restores control directly to the caller of the prologue sequence. Called by twenty stack-heavy functions across camera, config parsing, physics init, season data, and telemetry paths.
    // ASSIGNMENT: Seed the probe pointer i from the address of the local a2 slot, i.e. the current stack high-water mark just below the caller's frame. [source:raw]
    // GUARD: Loop guard: only while a1 (remaining allocation size) is >= 0x1000 does the probe keep touching pages; any residual below one page needs no further guard-page touch. [source:raw]
    // LOOP: Per-iteration probe: decrement the pointer i by 4096 and reduce a1 by 4096, so each 4096-byte segment of the growing frame is visited exactly once. [source:raw]
    // RETURN: Bare retn: returns to the address pushed by the alloca call site rather than a C-level return; no value is returned in the usual sense. [function:0x005881C0, source:raw]

    // Conservative worker pseudocode:
    //   void _alloca_probe(unsigned int size) {
    //     char *p = (char*)&size;
    //     while (size >= 0x1000) { p -= 4096; size -= 4096; }
    //     __asm retn;
    //   }
    // UNRESOLVED: The 4096-byte step is taken from the 0x1000 literal in the raw source; the actual OS page size and guard-page interaction are not visible in this packet.
    // UNRESOLVED: The probe's effect on the exception-handler chain (_except_handler3 in this binary) is not recoverable from the raw body alone.
}
