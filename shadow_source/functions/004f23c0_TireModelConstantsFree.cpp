// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F23C0
// Canonical corpus name: sub_4F23C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F23C0_004f23c0.c

void UnknownObject::TireModelConstantsFree()
{
    // Cleanup routine that frees six heap allocations (global pointers 0x008ADB00, 0x008ADB0C, 0x008ADB14, 0x008ADB1C, 0x008ADB24, 0x008ADB2C) via FreeWrapper_7bcf. Each pointer is individually null-guarded; the last allocation's FreeWrapper return value is returned (or 0 when it was already null). Prior analysis labels the block as tire model constants, a DERIVED interpretation.
    // GUARD: If global 0x008ADB2C is non-null, FreeWrapper_7bcf is called on it. [global:0x008ADB2C, callee:0x00587BCF, source:raw]
    // GUARD: If global 0x008ADB24 is non-null, FreeWrapper_7bcf is called on it. [global:0x008ADB24, callee:0x00587BCF, source:raw]
    // GUARD: If global 0x008ADB1C is non-null, FreeWrapper_7bcf is called on it. [global:0x008ADB1C, callee:0x00587BCF, source:raw]
    // GUARD: If global 0x008ADB14 is non-null, FreeWrapper_7bcf is called on it. [global:0x008ADB14, callee:0x00587BCF, source:raw]
    // GUARD: If global 0x008ADB0C is non-null, FreeWrapper_7bcf is called on it. [global:0x008ADB0C, callee:0x00587BCF, source:raw]
    // CALL: If global 0x008ADB00 is non-null, FreeWrapper_7bcf is called on it and its return value becomes the function result. [global:0x008ADB00, callee:0x00587BCF, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result of the last freed allocation, or 0 when 0x008ADB00 was already null. [global:0x008ADB00, source:raw]

    // Conservative worker pseudocode:
    //   int TireModelConstantsFree() {
    //     int result = 0;
    //     if (g_8ADB2C) result = FreeWrapper_7bcf(g_8ADB2C);
    //     if (g_8ADB24) result = FreeWrapper_7bcf(g_8ADB24);
    //     if (g_8ADB1C) result = FreeWrapper_7bcf(g_8ADB1C);
    //     if (g_8ADB14) result = FreeWrapper_7bcf(g_8ADB14);
    //     if (g_8ADB0C) result = FreeWrapper_7bcf(g_8ADB0C);
    //     if (g_8ADB00) result = FreeWrapper_7bcf(g_8ADB00);
    //     return result;
    //   }
    // UNRESOLVED: The allocation sites and element layouts behind the six freed pointers are not visible here; the 'tire model constants' role comes from prior prose analysis (DERIVED), not this packet's deterministic facts.
    // UNRESOLVED: The sparse global layout (pointer slots not spaced uniformly at 4 bytes) suggests neighbouring slots exist that this routine does not free; no addresses beyond the packet's six are asserted.
    // UNRESOLVED: No static callers: this is invoked top-level or indirectly, so the shutdown context is unknown.
}
