// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489AB0
// Canonical corpus name: UIListSelectionHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListSelectionHandler_00489ab0.c

void UnknownObject::UIListSelectionHandler()
{
    // UI list item selection handler. Validates the 1-based requested index a2 against the item count at this+0x94, stores the 0-based selection into this+0x168 (or -1 on invalid input), optionally scrolls the list so the selection becomes visible, then walks the linked list from this+0x90 to the selected node and passes four text strings from that node to a vtable display method (this->vtable + 168). Returns 0 on success, -1 on invalid index or a premature null during the walk.
    // GUARD: Invalid selection guard: if a2 > item count this+0x94 or a2 <= 0, set this+0x168 = -1 and return -1. [field:this:0x00000094, field:this:0x00000168, source:raw]
    // ASSIGNMENT: Store 0-based selection index a2 - 1 into this+0x168. [field:this:0x00000168, source:raw]
    // GUARD: When scroll flag a3 is set, test whether selection v4 falls outside the visible window [scroll offset this+0x14C, this+0x14C + visible count this+0x164). [field:this:0x0000014C, field:this:0x00000164, source:raw]
    // ASSIGNMENT: If the selection is outside the visible window, set scroll offset this+0x14C = selection so it becomes visible. [field:this:0x0000014C, source:raw]
    // CALL: Call sub_489D00(this) after changing the scroll offset. [callee:0x00489D00, source:raw]
    // CALL: Call FloatToIntConversion(this) after changing the scroll offset. [callee:0x00489E90, source:raw]
    // GUARD: Guard: if list head this+0x90 is null, return -1. [field:this:0x00000090, source:raw]
    // LOOP: Walk the linked list from this+0x90 following node+0x8C (next pointer) until the counter reaches the selection this+0x168; return -1 if a node becomes null before the target index. [field:this:0x00000090, field:this:0x00000168, source:raw]
    // CALCULATION: Read four text strings from the selected node at offsets 0xA0, 0xA8, 0xB0 and 0xB8, substituting byte_5EA438 when any is null. [global:0x005EA438, source:raw]
    // CALL: Invoke the vtable display method at obj+0xA8 (this->vtable + 168) passing the four strings (v12, v11, v10, v9). [field:obj:0x000000A8, field:this:0x00000000, source:raw]
    // RETURN: Return 0 on success. [source:raw]
    // CALL: Called by DualCallWrapper_af00 (0x0046AF00), UIListSearchAndSelect (0x00489BA0), UIListManagementHandler (0x0048A3C0) and SessionStateDispatch (0x004A0DF0). [caller:0x0046AF00, caller:0x00489BA0, caller:0x0048A3C0, caller:0x004A0DF0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_489AB0(_DWORD* this, int index, char scroll) {
    //     if (index > *(int*)(this + 0x94) || index <= 0) { *(int*)(this + 0x168) = -1; return -1; }
    //     int sel = index - 1;
    //     *(int*)(this + 0x168) = sel;
    //     if (scroll) {
    //       int base = *(int*)(this + 0x14C);
    //       if (sel < base || sel >= base + *(int*)(this + 0x164)) {
    //         *(int*)(this + 0x14C) = sel;
    //         sub_489D00(this);
    //         FloatToIntConversion(this);
    //       }
    //     }
    //     _DWORD* node = *(_DWORD**)(this + 0x90);
    //     int n = 0;
    //     if (!node) return -1;
    //     while (n != *(int*)(this + 0x168)) {
    //       node = (_DWORD*)node[35];
    //       ++n;
    //       if (!node) return -1;
    //     }
    //     char* s1 = *(char**)(node + 0xA0); if (!s1) s1 = byte_5EA438;
    //     char* s2 = *(char**)(node + 0xA8); if (!s2) s2 = byte_5EA438;
    //     char* s3 = *(char**)(node + 0xB0); if (!s3) s3 = byte_5EA438;
    //     char* s4 = *(char**)(node + 0xB8); if (!s4) s4 = byte_5EA438;
    //     ((void(__thiscall*)(_DWORD*,char*,char*,char*,char*))*(int*)(*(int*)this + 168))(this, s3, s4, s2, s1);
    //     return 0;
    //   }
    // UNRESOLVED: The four strings read from node offsets 0xA0/0xA8/0xB0/0xB8 are passed to the display method, but the individual roles of each string are not independently confirmed.
    // UNRESOLVED: Fields this+0x1A8, this+0x1BC, this+0x1C4, this+0x1CC and this+0x1D4 are listed in the packet fields but are not referenced by the raw source text of this function.
    // UNRESOLVED: The node layout (next at node+0x8C, strings at node+0xA0..0xB8) is DERIVED from the raw source; no independent node-struct evidence exists in this packet.
}
