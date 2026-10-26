// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477AA0
// Canonical corpus name: GameContentFilterCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameContentFilterCheck_00477aa0.c

void UnknownObject::GameContentFilterCheck()
{
    // Content filter check with settings-path lookup. Loads the object's content string at this + 384; when a game filter is active (ConditionalDispatch_81f0) the content string is compared against the filter with sub_588410 and the virtual callback at vtable slot +160 is invoked unless the strings match. When no filter is active, the virtual callback is invoked if the content string is non-empty. Afterwards a linked-list element (LinkedListIndexedAccessor_f590) whose +60 field is non-null is compared at +260 against dword_7CE5EC (or byte_5EA438 when null), and a non-matching path triggers SceneListSearchByPath. Always returns 0.
    // ASSIGNMENT: v2 = this + 384; v3 = StringPointerDereference(this + 384) loads the object's content string pointer from the this+0x180 slot [callee:0x0049A2B0, source:raw]
    // GUARD: Filter branch is entered when ConditionalDispatch_81f0(aGameFilter) is non-zero, i.e. a game filter string is configured [callee:0x005681F0, global:0x005C7130, source:raw]
    // CALL: ConditionalDispatch_81f0(aGameFilter) retrieves the active filter string [callee:0x005681F0, global:0x005C7130, source:raw]
    // CALL: sub_588410(StringPointerDereference(this + 384), filter) compares the content string with the filter (a 0 result means a match) [callee:0x00588410, callee:0x0049A2B0, source:raw]
    // GUARD: A filter match (sub_588410 == 0) skips the virtual callback; a non-match with an active filter, or a non-empty content string with no active filter, falls through to the callback [source:raw]
    // CALL: Virtual thiscall of vtable slot +160 on this (via the vtable pointer at this+0) - the content filtering callback [field:obj:0x000000A0, field:this:0x00000000, source:raw]
    // CALL: LinkedListIndexedAccessor_f590(this) fetches an indexed element from the object's linked list [callee:0x0048F590, source:raw]
    // GUARD: The settings-path comparison proceeds only while v5 (the element) and v6 = *(v5 + 60) are both non-zero [source:raw]
    // ASSIGNMENT: v7 = dword_7CE5EC, or byte_5EA438 when dword_7CE5EC is null (fallback path string) [global:0x007CE5EC, global:0x005EA438, source:raw]
    // GUARD: When strcmp(*(v6 + 260), v7) is non-zero (paths differ) the scene list search is triggered [source:raw]
    // CALL: SceneListSearchByPath(this) searches the scene list by the settings file path when the paths differ [callee:0x00477BA0, source:raw]
    // RETURN: Always returns 0 [source:raw]

    // Conservative worker pseudocode:
    //   v2 = this + 384;
    //   v3 = StringPointerDereference(v2);
    //   if (ConditionalDispatch_81f0(aGameFilter)) {
    //       v9 = ConditionalDispatch_81f0(aGameFilter);
    //       v4 = StringPointerDereference(v2);
    //       if (!sub_588410(v4, v9))
    //           goto LABEL_7;
    //   LABEL_6:
    //       (*(*(DWORD*)this + 160))(this);
    //       goto LABEL_7;
    //   }
    //   if (v3 && *v3)
    //       goto LABEL_6;
    //   LABEL_7:
    //   v5 = LinkedListIndexedAccessor_f590(this);
    //   if (v5) {
    //       v6 = *(DWORD*)(v5 + 60);
    //       if (v6) {
    //           v7 = dword_7CE5EC;
    //           if (!v7) v7 = byte_5EA438;
    //           if (strcmp((char*)(v6 + 260), v7))
    //               SceneListSearchByPath(this);
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: dword_8AD3B4 is listed as a referenced global but does not appear in the raw source shown; its role is unaccounted
    // UNRESOLVED: The virtual callback at vtable slot +160, the content-string slot at this + 384, and the linked-list element fields at +60/+260 are typed but unnamed
    // UNRESOLVED: Whether the filter comparison result zero means match or non-match is inferred from the skip/callback control flow
}
