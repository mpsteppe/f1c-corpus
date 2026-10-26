// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F030
// Canonical corpus name: MouseInputHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MouseInputHandler_0045f030.c

void UnknownObject::MouseInputHandler()
{
    // Processes mouse-button inputs into HUD text labels when the hover timer at this+0x384 has reached the 0.667 threshold and the HUD flag byte_7CE254 is clear. Walks dword_7CB218 input-action entries from word_7CB21C, maps action codes 4098-4107 to button indices via the jpt_45F095 jump table, bounds-checks the index against the button count at this+0x1B78C, and traverses the button-state linked list headed at this+0x1B780. For the selected node it formats and clamps the label string (falling back to byte_5EA438 when empty), encodes a progress-bar event with ProgressBarEventEncode using dbl_8AFEA0, builds the text through sub_587DD0/sub_4B0B20/StringCopyWithFormatQuery/SessionStateDispatch, allocates a texture via TextureCreationWrapper, renders the wrapped line with TextLineWrappingAndRendering into dword_7CD204, then resets the hover timer.
    // GUARD: outer gate: the hover timer this[225] at byte 0x384 must be >= 0.667 and the HUD-disable flag byte_7CE254 (0x007CE254) must be clear before any mouse-label handling [field:this:0x00000384, global:0x007CE254, source:raw]
    // LOOP: iterate dword_7CB218 (0x007CB218) input-action entries, walking the action-code array at word_7CB21C (0x007CB21C) [global:0x007CB218, global:0x007CB21C, source:raw]
    // CALCULATION: the switch on the action code maps codes 4098..4107 to button indices 1..10 via the jump table jpt_45F095 (0x0045F278); unknown codes are skipped [global:0x0045F278, source:raw]
    // GUARD: bounds-check the mapped button index against the button count *((_DWORD*)this + 28131) at byte 0x1B78C, skipping out-of-range indices [field:this:0x0001B78C, source:raw]
    // LOOP: traverse the button-state linked list headed at byte 0x1B780: follow the next pointer stored at node+4 and read the node data pointer stored at node+0 [field:this:0x0001B780, field:*(*(this+0x1B780)+0x4):0x00000004, field:*(*(this+0x1B780)+0x4):0x00000000, source:raw]
    // GUARD: only handle a list node whose dereferenced data pointer (node->data, field at *(*(*(this+0x1B780)+0x4)+0x0)) is non-null [field:*(*(*(this+0x1B780)+0x4)+0x0):0x00000000, source:raw]
    // ASSIGNMENT: label fallback: when the node's label string pointer is null, use byte_5EA438 (0x005EA438) [global:0x005EA438, source:raw]
    // CALCULATION: clamp the label length v8 (from strlen of the label plus one) to the range 0..159 before formatting [source:raw]
    // CALL: ProgressBarEventEncode(4, 6, v8, 0, LODWORD(v11), 1) encodes a progress-bar label event whose duration comes from the double constant dbl_8AFEA0 (0x008AFEA0) [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // CALL: build and render the label: sub_587DD0(v21, v9, v8) copies the clamped text, sub_4B0B20(v14, 64) and StringCopyWithFormatQuery(v14, v21, v17, 128) format it, SessionStateDispatch(v17) forwards it, and TextLineWrappingAndRendering(&dword_7CD204, v17, 3, 16909060) draws the wrapped line [callee:0x00587DD0, callee:0x004B0B20, callee:0x0045BC50, callee:0x004A0DF0, callee:0x0045BD10, global:0x007CD204, source:raw]
    // CALL: TextureCreationWrapper(v20, 0, -1, -1) creates the texture object used by the label rendering [callee:0x00462250, source:raw]
    // ASSIGNMENT: resets the hover timer after a successful render: this[225] = 0.0 (byte 0x384) [field:this:0x00000384, source:raw]

    // Conservative worker pseudocode:
    //   if (this[225] < 0.667 || byte_7CE254) return;
    //   for (idx = 0; idx < dword_7CB218; idx++) {
    //     code = word_7CB21C[idx];
    //     if (code < 4098 || code > 4107) continue;
    //     btn = code - 4097;
    //     if (btn > this[28131]) continue;
    //     node = this[28128];
    //     while (node) {
    //       if (--btn <= 0) break;
    //       node = *(u32*)(node + 4);
    //     }
    //     if (!node || !*(u32*)node) continue;
    //     label = **(char***)node; if (!label) label = byte_5EA438;
    //     len = strlen(label) + 1 - 1; len = clamp(len, 0, 159);
    //     ProgressBarEventEncode(4, 6, len, 0, (u32)dbl_8AFEA0, 1);
    //     sub_587DD0(v21, label, len); v21[len] = 0;
    //     TextureCreationWrapper(v20, 0, -1, -1);
    //     memset(v17, 0, sizeof(v17)); memset(v14, 0, sizeof(v14));
    //     sub_4B0B20(v14, 64); StringCopyWithFormatQuery(v14, v21, v17, 128);
    //     SessionStateDispatch(v17); TextLineWrappingAndRendering(&dword_7CD204, v17, 3, 16909060);
    //     this[225] = 0.0;
    //   }
    // UNRESOLVED: flt_59F114 (0x0059F114), unk_7CE24D (0x007CE24D) and byte_7CE498 (0x007CE498) are reported as referenced globals by extraction but do not appear in the raw source text, so their roles in this function are not grounded
    // UNRESOLVED: The list-node layout (data pointer at node+0, next pointer at node+4) is DERIVED from the pointer-deref field evidence, not stated by packet facts
    // UNRESOLVED: The progress-bar event parameters (4, 6, 0, 1) and the 16909060 color literal are passed verbatim; their meaning is not stated
}
