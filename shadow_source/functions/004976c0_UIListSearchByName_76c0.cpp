// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004976C0
// Canonical corpus name: UIListSearchByName_76c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListSearchByName_76c0_004976c0.c

void UnknownObject::UIListSearchByName_76c0()
{
    // Searches a two-level nested linked list by name. Outer list head is this+0x4; the traversal pointer is kept in this+0xC. For each outer node FieldGetter_8e30 (00498e30) retrieves an inner list head which is walked via the next pointer at byte offset 72, comparing the name string at byte offset 52 against a2 with sub_588410 (0 meaning match). Returns the last matching inner item pointer, or 0 if a2 is null, the outer list is empty, or no name matches. Called by sub_492160 (00492160), LookupDispatch (00497940) and sub_49A5D0 (0049a5d0).
    // ASSIGNMENT: v3 = this[1] (outer list head at this+0x4); v4 = 0; the traversal pointer this[3] (this+0xC) is initialized to v3 [field:this:0x00000004, field:this:0x0000000C]
    // GUARD: If a2 is null the search aborts immediately, returning 0 [source:raw]
    // GUARD: v5 is *v3 when the outer head is present, else 0; the outer loop runs only while v5 is non-null [field:this:0x00000004, source:raw]
    // CALL: FieldGetter_8e30(v5) retrieves the inner list head for the current outer node [callee:0x00498E30]
    // LOOP: Inner loop walks the inner list via the next pointer at byte offset 72 on each item, running while the item pointer is non-null [source:raw]
    // GUARD: v8 = name pointer at byte offset 52 on the inner item; if null it defaults to byte_5EA438 [global:0x005EA438, source:raw]
    // CALL: sub_588410(v8, a2) compares the item name against the search string; a 0 return records a match by setting v4 = i [callee:0x00588410]
    // ASSIGNMENT: Advance the outer traversal: v9 = this[3] (this+0xC), v10 = *(v9 + 4), and this[3] = v10; a null v9 or v10 breaks the outer loop [field:this:0x0000000C, source:raw]
    // RETURN: Return v4: the last matching inner item pointer, or 0 when nothing matched or the search was blocked [source:raw]

    // Conservative worker pseudocode:
    //   v3 = (int *)this[1];
    //   v4 = 0;
    //   this[3] = v3;
    //   v5 = v3 ? *v3 : 0;
    //   if (!a2) return 0;
    //   for (; v5; v5 = *v10) {
    //     for (i = FieldGetter_8e30(v5); i; i = *(_DWORD *)(i + 72)) {
    //       v8 = *(char **)(i + 52);
    //       if (!v8) v8 = byte_5EA438;
    //       if (!sub_588410(v8, a2)) v4 = i;
    //     }
    //     v9 = this[3];
    //     if (!v9) break;
    //     v10 = *(int **)(v9 + 4);
    //     this[3] = v10;
    //     if (!v10) break;
    //   }
    //   return v4;
    // UNRESOLVED: field this+0x10 is flagged by packet facts but does not appear in the raw decompiled source; it may be an outer-list count or boundary used by callers, role not verifiable here
    // UNRESOLVED: The interpretation that sub_588410 returning 0 means a name match is inferred from the loop accumulating v4 rather than from an explicit contract
}
