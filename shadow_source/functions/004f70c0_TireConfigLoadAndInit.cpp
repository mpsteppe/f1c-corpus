// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F70C0
// Canonical corpus name: sub_4F70C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F70C0_004f70c0.c

void UnknownObject::TireConfigLoadAndInit()
{
    // Loads and initializes per-tire configuration. When the two 180-byte buffers this+0x694 and this+0x6D8 are not already allocated, allocates and zero-fills them via OperatorNewNhMallocWrapper(180). Initializes two 45-slot tire-slot stacks on the stack (v50/v51), pre-resolves the season sounds directory path (dword_5EC3D8 / dword_5EC428 with byte_5EA438 fallbacks plus the 'sfx' suffix) once (byte_8AFC74 guard), copies per-slot names and parameters from the global config tables referenced below into the slot stacks, dispatches a conditional config entry through this+18196 and calls sub_4F7460, invokes a season-entry handler through the config object vtable when dword_8AC4C4 is set, then resolves each of the 45 tire slots by SwitchBasedParamSetting, ColorPaletteLookupByIndex and StringMatchWithWildcard into this+0x694 / this+0x6D8, writing reciprocal-based palette blend factors (slot[7] scale, slot[8] = 1 - scale*offset, slot[9] = color). Finally frees the temporary per-slot string allocations in v50/v51 and returns v34 (1 when the buffers were already allocated, else 0).
    // LOOP: Initialize the two 45-slot tire-slot stacks v50 and v51: for each slot (5-dword stride) set slot[0] = 0 and slot[1] = -1, then call TireSlotStructInit(slot). [callee:0x004F7440, source:raw]
    // GUARD: If this[421] (this+0x694) or this[438] (this+0x6D8) is already allocated, skip the allocation/load path and set v34 = 1. [field:this:0x00000694, field:this:0x000006D8, source:raw]
    // ASSIGNMENT: On the allocation path, allocate this[421] and this[438] with OperatorNewNhMallocWrapper(180) and zero both 180-byte buffers (45 dwords each). [callee:0x00587C03, field:this:0x00000694, field:this:0x000006D8, source:raw]
    // GUARD: When byte_8AFC74 is zero the sounds directory has not been resolved yet, so build and pre-load the season sound path. [global:0x008AFC74, source:raw]
    // ASSIGNMENT: Build the sounds path into v52 with StringFormatWithBufferOverflowCheck(v52, "%s%s%s", seasonDir, seasonName, aF1soundsSfx): seasonDir = dword_5EC3D8 or byte_5EA438 fallback, seasonName = dword_5EC428 or byte_5EA438 fallback; the format-string global 0x005C6784 (aSSS_0) anchors the literal "%s%s%s". [callee:0x0058815F, global:0x005EC3D8, global:0x005EC428, global:0x005EA438, global:0x005C6784, global:0x005D6788, source:raw]
    // CALL: Pre-load the sound config with sub_4F7460(v52, dword_8AF8F0, dword_8AF568); when it returns zero set byte_8AFC74 = 1 to mark the directory resolved. [callee:0x004F7460, global:0x008AF8F0, global:0x008AF568, global:0x008AFC74, source:raw]
    // LOOP: Fill the two slot stacks from the global config tables for j = 0..220 step 5 (45 slots): copy the name dword_8AF8F0[j] (byte_5EA438 fallback) via StringCopyWithBufferRealloc, then set v50[j*4+8] = dword_8AF8F8[j], v50[j*4+12] = dword_8AF8FC[j], v50[j*4+16] = byte_8AF900[j*4]; for stack B copy dword_8AF568[j] (byte_5EA438 fallback) via StringCopyWithBufferRealloc and set v51[j*4+8] = dword_8AF570[j], v51[j*4+12] = dword_8AF574[j], v51[j*4+16] = byte_8AF578[j*4]. [global:0x008AF8F0, global:0x008AF8F8, global:0x008AF8FC, global:0x008AF900, global:0x008AF568, global:0x008AF570, global:0x008AF574, global:0x008AF578, global:0x005EA438, callee:0x00566650, source:raw]
    // CALL: Dispatch the conditional config entry: v16 = ConditionalDispatch_40b0(*this + 18196); when non-null take its string at offset +24 (byte_5EA438 fallback) and call sub_4F7460(v17, v50, v51). [callee:0x004C40B0, field:this:0x00000000, global:0x005EA438, callee:0x004F7460, source:raw]
    // GUARD: When dword_8AC4C4 (config object) is non-null, invoke the virtual method at vtable offset 68 with the season current-entry string (dword_5EC3E8 or byte_5EA438 fallback). [global:0x008AC4C4, global:0x005EC3E8, global:0x005EA438, source:raw]
    // LOOP: Per-tire-slot resolution loop A (45 iterations, k step 20 over 900 bytes): call SwitchBasedParamSetting(v19, &v43, &v45) and ColorPaletteLookupByIndex(v19, &v42, &v46, &v44), then StringMatchWithWildcard(4*v19 + this[421], &v50[k], v43, v45); when a matching entry v22 = *(float**)(4*v19 + this[421]) exists compute v25 = ((v26|v27)==0 ? 1.0/v42 : 1.0) and write v22[7] = v25, v22[8] = 1.0 - v25*v47, v22[9] = v46. [callee:0x004F8030, callee:0x004F8280, callee:0x004F81D0, field:this:0x00000694, global:0x0059E43C, global:0x0059E440, source:raw]
    // LOOP: Per-tire-slot resolution loop B: the same StringMatchWithWildcard and blend-factor computation applied to the second buffer this[438] (this+0x6D8) against the v51 slot stack. [callee:0x004F81D0, field:this:0x000006D8, source:raw]
    // LOOP: Cleanup: two 45-iteration loops free the per-slot string allocations of the v50/v51 stacks, reading each slot base via *((_DWORD*)cursor - 5) with a backward 20-byte stride and calling FreeWrapper_7bcf on non-null pointers. [callee:0x00587BCF, source:raw]
    // RETURN: Return v34: 1 when the buffers were already allocated, otherwise the value v48 (0). [function:0x004F70C0, source:raw]

    // Conservative worker pseudocode:
    //   init 45-slot stacks v50 and v51 (slot[0]=0, slot[1]=-1, TireSlotStructInit);
    //   if (this[421] || this[438]) v34 = 1;
    //   else {
    //     this[421] = OperatorNewNhMallocWrapper(180);
    //     this[438] = OperatorNewNhMallocWrapper(180);
    //     zero both 180-byte buffers;
    //     if (!byte_8AFC74) {
    //       build v52 = StringFormatWithBufferOverflowCheck(seasonDir, seasonName, aF1soundsSfx);
    //       if (!sub_4F7460(v52, dword_8AF8F0, dword_8AF568)) byte_8AFC74 = 1;
    //     }
    //     for j in 0..220 step 5: copy per-slot names/params from the config tables into v50/v51;
    //     v16 = ConditionalDispatch_40b0(*this + 18196);
    //     if (v16) sub_4F7460(*(char**)(v16+24) or byte_5EA438, v50, v51);
    //     if (dword_8AC4C4) (*(void(**)(char*))(*(dword_8AC4C4)+68))(dword_5EC3E8 or byte_5EA438);
    //     for each of 45 tire slots:
    //       SwitchBasedParamSetting + ColorPaletteLookupByIndex + StringMatchWithWildcard;
    //       if entry: scale = (ok) ? 1.0/v42 : 1.0; entry[7]=scale; entry[8]=1.0-scale*v47; entry[9]=v46;
    //     v34 = v48;
    //   }
    //   free v50/v51 slot string allocations;
    //   return v34;
    // UNRESOLVED: Global 0x008AC388 (unk_8AC388) appears in the packet as a read global but has no visible use site in the raw source; the existing-analysis label VehicleFilePathBuffer (DERIVED) is not adopted here.
    // UNRESOLVED: The float globals 0x0059E43C (flt_59E43C) and 0x0059E440 (flt_59E440) are packet-listed read globals that the raw source renders as inline literals (the 1.0 / 1.0/v42 reciprocal arithmetic); their exact load sites are not visible, so their placement with the blend computation is positional.
    // UNRESOLVED: The format-string global 0x005C6784 (aSSS_0) is the literal "%s%s%s"; the correspondence is inferred from the StringFormatWithBufferOverflowCheck call.
    // UNRESOLVED: The exact layout of the per-tire slot record (what slot[7]/slot[8]/slot[9] represent beyond scale/offset/color) is not evidenced by the packet.
    // UNRESOLVED: The cleanup loops assume the slot base is 20 bytes back from the copy cursor (slot[0] holds the freed allocation pointer); this follows the backward stride pattern but the slot record layout is not independently evidenced.
}
