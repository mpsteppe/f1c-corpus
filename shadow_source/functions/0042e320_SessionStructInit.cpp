// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E320
// Canonical corpus name: SessionStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStructInit_0042e320.c

void UnknownObject::SessionStructInit()
{
    // Initializes a large session-style structure: zeroes the leading DWORD and header fields (0x68, 0x6C set to -1, 0x70), runs two StructInitializer passes over 64-byte blocks (44 entries from this+176, then 55 entries from this+2992), initializes a small data structure at DWORD index 1628, sets byte counters at 0x19A4/0x19A5 to 1, zeroes fields 0x1988/0x1989 and a six-DWORD block 0x198C-0x19A0, calls sub_42ED70, clears two bytes per 128-byte step around this+6950 (field 0x1B26), sets four float fields 0x1CA8-0x1CB4 to the literal 1056964608 (0.5f), and finishes with PenaltyStructInit. Returns this.
    // ASSIGNMENT: zeroes the leading DWORD of the structure: *this = 0 (byte 0x0) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: initializes header fields: *((_DWORD*)this + 26) = 0 (byte 0x68), *((_DWORD*)this + 27) = -1 (byte 0x6C), this[112] = 0 (byte 0x70) [field:this:0x00000068, field:this:0x0000006C, field:this:0x00000070, source:raw]
    // LOOP: first StructInitializer pass: 44 iterations calling StructInitializer on 64-byte blocks starting at this+176 [callee:0x0042E1C0, source:raw]
    // LOOP: second StructInitializer pass: 55 iterations calling StructInitializer on 64-byte blocks starting at this+2992 [callee:0x0042E1C0, source:raw]
    // CALL: SmallDataStructInit((_DWORD*)this + 1628) initializes a small data structure at DWORD index 1628 [callee:0x0042DC60, source:raw]
    // ASSIGNMENT: sets byte fields this[6564] = 1 (byte 0x19A4) and this[6565] = 1 (byte 0x19A5) [field:this:0x000019A4, field:this:0x000019A5, source:raw]
    // ASSIGNMENT: zeroes byte fields this[6536] = 0 (byte 0x1988) and this[6537] = 0 (byte 0x1989) [field:this:0x00001988, field:this:0x00001989, source:raw]
    // ASSIGNMENT: zeroes a six-DWORD block from *((_DWORD*)this + 1635) through +1640 (bytes 0x198C, 0x1990, 0x1994, 0x1998, 0x199C, 0x19A0) [field:this:0x0000198C, field:this:0x00001990, field:this:0x00001994, field:this:0x00001998, field:this:0x0000199C, field:this:0x000019A0, source:raw]
    // CALL: sub_42ED70(this) performs an additional initialization pass over the structure [callee:0x0042ED70, source:raw]
    // LOOP: three iterations clearing two bytes per step: *(this + 6950 - 384) = 0 and *(this + 6950) = 0, advancing by 128 bytes each iteration; the this+6950 write is field 0x1B26 [field:this:0x00001B26, source:raw]
    // ASSIGNMENT: sets four DWORD float fields at bytes 0x1CA8, 0x1CAC, 0x1CB0 and 0x1CB4 to the literal 1056964608 (0.5f) [field:this:0x00001CA8, field:this:0x00001CAC, field:this:0x00001CB0, field:this:0x00001CB4, source:raw]
    // CALL: PenaltyStructInit(this) initializes the penalty subsystem state [callee:0x0042E400, source:raw]
    // RETURN: returns this; called by TireModelInit (0x0043E050), sub_45C400 (0x0045C400), SeasonDataFileSetupChain (0x0046D060), TelemetryDataDump (0x004D4A80), sub_4E3360 (0x004E3360) and LargeConfigFunctionWithPhysicsConstants (0x004E45B0) [function:0x0042E320, caller:0x0043E050, caller:0x0045C400, caller:0x0046D060, caller:0x004D4A80, caller:0x004E3360, caller:0x004E45B0, source:raw]

    // Conservative worker pseudocode:
    //   *(u32*)this = 0;
    //   *(u32*)(this + 0x68) = 0; *(u32*)(this + 0x6C) = -1; this[0x70] = 0;
    //   for (p = this + 176, n = 44; n; n--, p += 64) StructInitializer(p);
    //   for (p = this + 2992, n = 55; n; n--, p += 64) StructInitializer(p);
    //   SmallDataStructInit((u32*)this + 1628);
    //   this[0x19A4] = 1; this[0x19A5] = 1;
    //   this[0x1988] = 0; this[0x1989] = 0;
    //   for (i = 1635; i <= 1640; i++) *((u32*)this + i) = 0;
    //   sub_42ED70(this);
    //   for (p = this + 6950, n = 3; n; n--, p += 128) { *(p - 384) = 0; *p = 0; }
    //   *(u32*)(this + 0x1CA8) = 1056964608; *(u32*)(this + 0x1CAC) = 1056964608;
    //   *(u32*)(this + 0x1CB0) = 1056964608; *(u32*)(this + 0x1CB4) = 1056964608;
    //   PenaltyStructInit(this);
    //   return this;
    // UNRESOLVED: The identities of the two StructInitializer arrays (44 then 55 entries of 64 bytes) are not stated by packet facts
    // UNRESOLVED: The byte fields 0x19A4/0x19A5 set to 1 and the six zeroed DWORDs 0x198C-0x19A0 are unnamed; their purpose is DERIVED from init patterns
    // UNRESOLVED: The structure cleared in 128-byte steps at this+6950 and the float group 0.5f at 0x1CA8-0x1CB4 remain semantically unnamed
}
