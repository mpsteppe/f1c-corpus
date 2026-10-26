// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477720
// Canonical corpus name: SeasonSceneInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonSceneInitialization_00477720.c

void UnknownObject::SeasonSceneInitialization()
{
    // Season-scene setup orchestrator. Dispatches a virtual command object (literal argument 20) through the dword_7CD8C0 interface (vtable offset +28) and, if produced, matches it via SeasonPathMatchSearch; queries a scene/search object through UtilityFunction_7810 and, if non-null, runs SeasonSceneSearchByName on it, copies the search result's match-index field (v4[93]) into this+0x184, and invokes the virtual callback at vtable offset 160. Then walks the linked list at this+0xF0 (cursor this+0xF8), comparing each node's path string at node+0x3C against dword_7CE64C (byte_5EA438 as fallback for either side when null), recording the first matching node index into this+0x174, and finally tail-calls UIViewportLayoutCalculator(this).
    // CALL: Dispatch virtual command creation through dword_7CD8C0: (*(*dword_7CD8C0 + 28))(dword_7CD8C0, 20), requesting a command object with literal argument 20 [global:0x007CD8C0, source:raw]
    // GUARD: If the command object v2 is non-null, run SeasonPathMatchSearch(v2) [callee:0x00476660, global:0x007CD8C0, source:raw]
    // CALL: Query a season scene/search object: v3 = UtilityFunction_7810(this); v4 = v3 [callee:0x00477810, source:raw]
    // GUARD: If v4 is non-null, run SeasonSceneSearchByName(v4) [callee:0x00476EC0, source:raw]
    // ASSIGNMENT: Copy the match index: read v5 = *this (vtable) and v4[93] (search object field), write this[97] at +0x184 [field:this:0x00000000, field:this:0x00000184, source:raw]
    // CALL: Invoke the virtual callback at vtable offset 160: (*(*this + 160))(this) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load the linked list head v6 = this[60] at +0xF0 and initialize the traversal cursor this[62] at +0xF8 to it [field:this:0x000000F0, field:this:0x000000F8, source:raw]
    // LOOP: Walk the list: start from the first node i = *v6 and follow node->next pointers read at cursor+4 each iteration, storing the next cursor back into this+0xF8, stopping when a null cursor or null next pointer is reached [field:this:0x000000F8, source:raw]
    // ASSIGNMENT: Per node, read the path string pointer v9 = *(node + 0x3C) (field at node+60) [field:*(this+0xF0):0x0000003C, source:raw]
    // GUARD: If v9 is non-null, build the comparison strings with byte_5EA438 as fallback for nulls, then test strcmp(v11, v10) == 0 where v11 = *v9 (first pointer/byte at v9+0) and v10 = dword_7CE64C [field:*(*(this+0xF0)+0x3C):0x00000000, global:0x007CE64C, global:0x005EA438, source:raw]
    // ASSIGNMENT: On a string match, record the node index: this[93] at +0x174 = v7 (zero-based position in the walk) [field:this:0x00000174, source:raw]
    // RETURN: Tail-call UIViewportLayoutCalculator(this) and return its result [source:raw]

    // Conservative worker pseudocode:
    //   cmd = (*(*dword_7CD8C0 + 28))(dword_7CD8C0, 20);
    //   if (cmd) SeasonPathMatchSearch(cmd);
    //   obj = UtilityFunction_7810(this);
    //   if (obj) {
    //     SeasonSceneSearchByName(obj);
    //     this[+0x184] = obj[93];
    //     (*(*this + 160))(this);
    //   }
    //   cur = this[+0xF0];
    //   this[+0xF8] = cur;
    //   for (node = *cur, idx = 0; node; ) {
    //     p = *(node + 0x3C);
    //     if (p) {
    //       target = dword_7CE64C ? dword_7CE64C : byte_5EA438;
    //       s = *p ? *p : byte_5EA438;
    //       if (!strcmp(s, target)) this[+0x174] = idx;
    //     }
    //     ++idx;
    //     nxt = cur ? *(cur + 4) : 0;
    //     cur = nxt;
    //     this[+0xF8] = cur;
    //     node = cur ? *cur : 0;
    //   }
    //   return UIViewportLayoutCalculator(this);
    // UNRESOLVED: field:obj:0x000000A0 is listed in the packet fields but no matching obj+0xA0 access appears in the raw body (the object reads present in raw are at obj+0x174, v4[93]); purpose unconfirmed
    // UNRESOLVED: field:this:0x000000FC is listed but this+0xFC is never accessed in the raw body; role unconfirmed
    // UNRESOLVED: UIViewportLayoutCalculator (tail-call target) and strcmp (CRT import) have no packet callee evidence entries, so their addresses are not recorded
    // UNRESOLVED: Semantics of the dword_7CD8C0 +28 virtual command dispatch (what command literal 20 requests) and of the vtable+160 callback are not established
    // UNRESOLVED: The exact comparison string content of byte_5EA438 and dword_7CE64C and the meaning of the recorded index at +0x174 are inherited from packet/fill labels, not from the raw body
}
