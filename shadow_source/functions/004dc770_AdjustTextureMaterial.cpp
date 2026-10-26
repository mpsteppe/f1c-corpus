// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC770
// Canonical corpus name: TextureAdjuster
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureAdjuster_004dc770.c

void UnknownObject::AdjustTextureMaterial()
{
    // Adjusts a texture material assignment. Validates the material name a1, a global condition via ConditionalDispatchWithGlobalCheck, and a successful texture-ID resolution via sub_548890; any failure returns -1. Then compares the resolved ID against up to three alternative texture paths a3, a4 and a5 using StringCompareCopy, returning 0, 1 or 2 for whichever matches first. When none match, copies each alternative into 253-byte local buffers seeded from byte_5EA438, formats a debug buffer through StringSplitLoop with the DDev string aDDevF119992002_5, logs an 'Unable to adjust texture' message via DebugLogWrite, and returns -1.
    // GUARD: If material name a1 is null, return -1. [source:raw]
    // GUARD: If ConditionalDispatchWithGlobalCheck(a7) returns zero, return -1. [callee:0x004DC430, source:raw]
    // CALL: Resolve a1 to a texture id via sub_548890 and keep it as v10. [callee:0x00548890, source:raw]
    // GUARD: If the resolution returned null, return -1. [source:raw]
    // GUARD: Match alternative a3: if a3 is null or StringCompareCopy(v9, a2, a3, a6) is non-zero, the match failed and evaluation continues; otherwise return the stored match result (0). [callee:0x004DC450, source:raw]
    // GUARD: Match alternative a4: if a4 is null or StringCompareCopy(v10, a2, a4, a6) is non-zero, continue; otherwise return 1. [callee:0x004DC450, source:raw]
    // GUARD: Match alternative a5: if a5 is null or StringCompareCopy(v10, a2, a5, a6) is non-zero, continue; otherwise return 2. [callee:0x004DC450, source:raw]
    // ASSIGNMENT: Seed three 253-byte local buffers (v19, v16, v13) with byte_5EA438[0] and zero the remainder plus the trailing words. [global:0x005EA438, source:raw]
    // CALL: For each non-null alternative (a3 into v19, a4 into v16, a5 into v13), copy it into its buffer with length limit 255 via sub_587DD0 and re-zero the trailing byte. [callee:0x00587DD0, source:raw]
    // CALL: Format the debug message buffer with StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_5, 265); a non-zero result means the format string is ready. [callee:0x004D7A50, global:0x008AD25C, global:0x005D4BE0, source:raw]
    // CALL: Log the 'Unable to adjust texture for material' message via DebugLogWrite(dword_8AD25C, format aUnableToAdjust, a1, v19, v16, v13). [callee:0x004D7AA0, global:0x008AD25C, global:0x005D4B98, source:raw]
    // RETURN: Return -1 when no alternative matched, otherwise 0, 1 or 2 for the matching alternative. [source:raw]

    // Conservative worker pseudocode:
    //   int AdjustTextureMaterial(const char* a1, char a2, const char* a3, const char* a4, const char* a5, char a6, int a7) {
    //     if (!a1) return -1;
    //     if (!ConditionalDispatchWithGlobalCheck(a7)) return -1;
    //     int id = sub_548890(a1);
    //     if (!id) return -1;
    //     int result;
    //     if (a3 && (result = StringCompareCopy(id, a2, a3, a6)) == 0) return result;
    //     if (a4 && StringCompareCopy(id, a2, a4, a6) == 0) return 1;
    //     if (a5 && StringCompareCopy(id, a2, a5, a6) == 0) return 2;
    //     char buf0[253] = { byte_5EA438[0] }, buf1[253] = { byte_5EA438[0] }, buf2[253] = { byte_5EA438[0] };
    //     if (a3) { sub_587DD0(buf0, a3, 255); }
    //     if (a4) { sub_587DD0(buf1, a4, 255); }
    //     if (a5) { sub_587DD0(buf2, a5, 255); }
    //     if (StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_5, 265))
    //       DebugLogWrite((int)dword_8AD25C, (int)"Unable to adjust texture for material: %s, tex0=%s, tex1=%s, tex2=%s", a1, buf0, buf1, buf2);
    //     return -1;
    //   }
    // UNRESOLVED: Semantics of the char parameters a2 and a6 (flags passed into StringCompareCopy) are unknown.
    // UNRESOLVED: The format literal used by DebugLogWrite is inlined in the raw source; global aUnableToAdjust is its storage evidence ref.
    // UNRESOLVED: The meaning of the 265 size argument to StringSplitLoop is unknown (likely a buffer capacity).
}
