// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B360
// Canonical corpus name: ShortComputation_b360
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b360_0045b360.c

void UnknownObject::RenderUIObjectInit()
{
    // Constructor-style initializer for a render/UI object. Installs the RenderUIObject vtable (off_59F080), initializes a sub-object at byte offset 4 via two calls (ShortComputation_cb70, sub_4DCF80) and two field writes (0x2C := 0, 0x30 := -1), fills eight 92-byte viewport blocks starting at 0x3C with default values (0, -1, -1.0f, 3), clears the buffer cursor at 0x31C, resets all eight entries via PerIndexStructFieldResetter, and clears tail state fields (0x320, 0x324, 0x328).
    // CALL: ShortComputation_cb70(v2) — initialize the sub-object at byte offset 4 (this + 1 dword) [callee:0x004DCB70, source:raw]
    // ASSIGNMENT: sub-object field at this + 0x2C := 0 [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: sub-object field at this + 0x30 := -1 [field:this:0x00000030, source:raw]
    // CALL: sub_4DCF80(v2) — second-stage initialization of the sub-object at byte offset 4 [callee:0x004DCF80, source:raw]
    // LOOP: do-while loop over 8 viewport blocks with a 92-byte stride, starting at this + 0x3C [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: each viewport block first byte := 0 [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: each viewport block field at block + 0x8C := -1 [field:this:0x0000008C, source:raw]
    // ASSIGNMENT: each viewport block field at block + 0x90 := -1082130432 (float -1.0f) [field:this:0x00000090, source:raw]
    // ASSIGNMENT: each viewport block field at block + 0x94 := 3 [field:this:0x00000094, source:raw]
    // ASSIGNMENT: this vtable pointer (field 0x0) := &off_59F080 [field:this:0x00000000, global:0x0059F080, source:raw]
    // ASSIGNMENT: this[199] (this + 0x31C) := 0 — clear the indexed-entry cursor [field:this:0x0000031C, source:raw]
    // LOOP: for i in 0..7: call PerIndexStructFieldResetter(i) to reset each of the eight indexed entries [callee:0x0045B430, source:raw]
    // ASSIGNMENT: byte at this + 800 (0x320) := 0 [field:this:0x00000320, source:raw]
    // ASSIGNMENT: this[201] (this + 0x324) := 0 [field:this:0x00000324, source:raw]
    // ASSIGNMENT: this[202] (this + 0x328) := 0 [field:this:0x00000328, source:raw]
    // RETURN: return this [function:0x0045B360, source:raw]

    // Conservative worker pseudocode:
    //   v2 = (char*)this + 4;
    //   ShortComputation_cb70(v2);
    //   *(_DWORD*)(v2 + 0x2C) = 0;
    //   *(_DWORD*)(v2 + 0x30) = -1;
    //   sub_4DCF80(v2);
    //   for (v3 = (char*)this + 0x3C, v4 = 8; v4; --v4, v3 += 92) {
    //       *v3 = 0; *(_DWORD*)(v3 + 0x8C) = -1; *(_DWORD*)(v3 + 0x90) = -1082130432; *(_DWORD*)(v3 + 0x94) = 3;
    //   }
    //   *this = &off_59F080;
    //   this[199] = 0;
    //   for (i = 0; i < 8; ++i) PerIndexStructFieldResetter(i);
    //   *(char*)this + 800 = 0;
    //   this[201] = 0;
    //   this[202] = 0;
    //   return this;
    // UNRESOLVED: Identity of the owning class and the exact render/UI role of the object are unknown.
    // UNRESOLVED: Semantics of the eight 92-byte viewport blocks and their default values (0, -1, -1.0f, 3) are unknown.
    // UNRESOLVED: Purpose of the sub-object at byte offset 4 initialized by ShortComputation_cb70 and sub_4DCF80 is unknown.
    // UNRESOLVED: The single static caller is ShortComputation_bb40; no frame-path or call-frequency evidence exists.
}
