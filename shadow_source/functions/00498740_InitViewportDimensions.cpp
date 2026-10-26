// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498740
// Canonical corpus name: InitViewportDimensions
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitViewportDimensions_00498740.c

void UnknownObject::InitViewportDimensions()
{
    // Writes six viewport/render dimension fields on this. Copies screen-width (dword_7CB2FC), scroll-acceleration (dword_7CB300) and a constant (dword_7CB304) into offsets 0x64/0x68/0x6C, stores a contact flag value read-and-cleared via ContactFlagReadClear(dword_7CB24C) into offset 0x70, and computes integer width (offset 0x5C) and height (offset 0x60) as CRTFtol of the font scale factors flt_7CB274 and flt_7CB278 times 400.0/300.0, returning the computed height. Called from CarCrashDamageProcessing (0x00496030) and UILargeRender (0x00496930).
    // ASSIGNMENT: Store dword_7CB2FC (screen width) into this[25] (offset 0x64). [global:0x007CB2FC, field:this:0x00000064]
    // ASSIGNMENT: Store dword_7CB300 (scroll acceleration) into this[26] (offset 0x68). [global:0x007CB300, field:this:0x00000068]
    // ASSIGNMENT: Store dword_7CB304 (constant value) into this[27] (offset 0x6C). [global:0x007CB304, field:this:0x0000006C]
    // CALL: Store the result of ContactFlagReadClear(dword_7CB24C) into this[28] (offset 0x70); the call reads and clears a contact/collision flag. [callee:0x0044F7D0, global:0x007CB24C, field:this:0x00000070]
    // CALCULATION: Compute CRTFtol(flt_7CB274 * 400.0) and store the integer into this[23] (offset 0x5C). [global:0x007CB274, callee:0x00587BDC, field:this:0x0000005C]
    // CALCULATION: Compute result = CRTFtol(flt_7CB278 * 300.0) and store it into this[24] (offset 0x60). [global:0x007CB278, callee:0x00587BDC, field:this:0x00000060]
    // RETURN: Return the computed height value (result) written to this[24] (offset 0x60). [field:this:0x00000060, source:raw]

    // Conservative worker pseudocode:
    //   this[25] = dword_7CB2FC;
    //   this[26] = dword_7CB300;
    //   this[27] = dword_7CB304;
    //   this[28] = ContactFlagReadClear(dword_7CB24C);
    //   this[23] = CRTFtol(flt_7CB274 * 400.0);
    //   result = CRTFtol(flt_7CB278 * 300.0);
    //   this[24] = result;
    //   return result;
    // UNRESOLVED: Globals dbl_59E9B0 (0x0059E9B0) and dbl_5AC9D8 (0x005AC9D8) appear in the packet globals table but are not referenced by the raw source; their role in this function is unresolved.
    // UNRESOLVED: The owning class is unknown; callers span both crash-damage processing (0x00496030) and large UI rendering (0x00496930), so the object behind this is not identified by the packet.
    // UNRESOLVED: The semantics of the written fields (viewport dimensions, scroll acceleration, contact flag) are proposed from the legacy abi name and existing analysis, not confirmed by the packet.
}
