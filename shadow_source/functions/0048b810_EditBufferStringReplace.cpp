// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B810
// Canonical corpus name: EditBufferStringUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EditBufferStringUpdate_0048b810.c

void UnknownObject::EditBufferStringReplace()
{
    // Replaces the text buffer content of an edit control with a new string. Returns -1 when a2 is null or identical to the current buffer. Otherwise truncates and copies a2 into the buffer (at most this[190]-1 bytes), filters out characters rejected by the field-type validator sub_48B560, repositions the cursor pointer this[189] to the end of the resulting string, and triggers a vtable render-update call, returning 0.
    // GUARD: Early-return -1 when the input string a2 is null. [source:raw]
    // GUARD: Early-return -1 when a2 equals the current buffer at this[188] (no change). [source:raw]
    // CALCULATION: Compute the maximum copy length as this[190] - 1 (buffer end limit 0x2F8-derived slot, one byte reserved for the terminator). [source:raw]
    // CALL: Copy a2 into the buffer v4 with truncation to the length limit via sub_587DD0. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Force the NUL terminator at v4[this[190] - 1]. [source:raw]
    // LOOP: Walk the copied string from this[188]; truncate the string at the first character rejected by the validator sub_48B560 (sets *v6 = 0). [callee:0x0048B560, source:raw]
    // ASSIGNMENT: Reset the cursor pointer this[189] to the buffer start this[188]. [field:this:0x000002F4, source:raw]
    // LOOP: Advance the cursor pointer this[189] to the end of the string (past the terminating NUL). [field:this:0x000002F4, source:raw]
    // CALL: Indirect call through the vtable (this[0] + 44) with argument 1 to request a render update of the edit control. [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int EditBufferStringReplace(DWORD *this, const char *a2) {
    //     if (!a2) return -1;
    //     const char *cur = (const char *)this[188];
    //     if (strcmp(cur, a2) == 0) return -1;
    //     int len = this[190] - 1;
    //     sub_587DD0(cur, a2, len);
    //     ((char *)cur)[len] = 0;
    //     unsigned char *p = (unsigned char *)this[188];
    //     while (*p && sub_48B560((int)this, *p)) ++p;
    //     *p = 0;
    //     this[189] = this[188];
    //     while (*(char *)this[189]) this[189] = (DWORD *)((char *)this[189] + 1);
    //     ((void (__thiscall *)(DWORD *, int))(this[0] + 44))(this, 1);
    //     return 0;
    //   }
    // UNRESOLVED: Field obj+0x2C is read but has no visible use in the decompiled body; role unknown.
    // UNRESOLVED: Field this+0x2F5 is read but has no visible use in the decompiled body; role unknown.
    // UNRESOLVED: The offset this[190] (buffer end limit) is used for truncation but its exact storage layout is unconfirmed.
    // UNRESOLVED: Field this[188] and this[189] (0x2F0/0x2F4 slots) semantics are DERIVED from the skeleton analysis, not independently confirmed.
}
