// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057DFF0
// Canonical corpus name: MutexProtectedLinkedListLookupByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedLinkedListLookupByID_0057dff0.c

void UnknownObject::MutexProtectedLinkedListLookupByID()
{
    // Mutex-guarded lookup over a connection linked list anchored at this+0xAAC. Waits on the mutex handle at this+0xABC with the timeout at this+0xAC0, then walks the list comparing each node's two key pairs (+2/+4 and +18/+20) against HIWORD(a2) and a3. On a match, releases the mutex and dispatches the matched node to sub_57DE30 with a6; otherwise releases and returns 0. Called from sub_57CB50 and sub_57D6C0.
    // CALL: This lookup is invoked from two connection-manager call sites, sub_57CB50 and sub_57D6C0 [caller:0x0057CB50, caller:0x0057D6C0, source:raw]
    // GUARD: Mutex gate: reads the handle at this+0xABC; when non-null, WaitForSingleObject(handle, *(this+0xAC0)) must return 0 or 128 to select the active list base this+0xAAC, otherwise the base is null [field:this:0x00000ABC, field:this:0x00000AC0, global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Initializes the traversal: anchors at this+0xAAC and copies the head entry pointer into the cursor slot at this+0xAB4 [field:this:0x00000AAC, field:this:0x00000AB4, source:raw]
    // LOOP: Walks the node chain reading the head data at *(this+0xAAC); a node matches when either key pair (dword at +4 with word at +2, or dword at +20 with word at +18) equals a3 and HIWORD(a2); the matched node's sockaddr-like data supplies the compared fields at +2/+4 and +0x12/+0x14 [field:*(this+0xAAC):0x00000000, field:*(*(this+0xAB4)+0x4):0x00000000, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000002, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000004, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000012, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000014, source:raw]
    // LOOP: Cursor advance on a failed node: reads the current entry at cursor slot +8, takes the next pointer at entry+4, writes it back to the cursor slot, and dereferences it for the next comparison [field:*(this+0xAB4):0x00000004, field:this:0x00000AB4, source:raw]
    // ASSIGNMENT: Records the matched node pointer as the result when either key pair comparison succeeds [source:raw]
    // GUARD: Release path: when the release slot at base+16 is non-null, ReleaseMutex is called on the handle read from this+0xABC (the same object region as base+16) [global:0x0059E1A4, field:this:0x00000ABC, source:raw]
    // RETURN: Returns 1 via sub_57DE30(this, matched node, a6) when a node was found, else 0 [callee:0x0057DE30, source:raw]

    // Conservative worker pseudocode:
    //   mutex = *(this + 0xABC);
    //   base = this + 0xAAC;
    //   if (mutex) {
    //     st = WaitForSingleObject(mutex, *(this + 0xAC0));
    //     v11 = (st == 0 || st == 128) ? base : 0;
    //   } else v11 = 0;
    //   *(v11 + 8) = *(v11);
    //   node = *(v11);
    //   found = 0;
    //   while (node) {
    //     if ((*(node + 4) == a3 && *(word*)(node + 2) == HIWORD(a2)) ||
    //         (*(node + 20) == a3 && *(word*)(node + 18) == HIWORD(a2))) { found = node; break; }
    //     cur = *(v11 + 8);
    //     if (!cur) break;
    //     next = *(cur + 4);
    //     *(v11 + 8) = next;
    //     node = next ? *(next) : 0;
    //   }
    //   if (*(base + 16)) ReleaseMutex(*(base + 16));
    //   return found ? sub_57DE30(this, found, a6) : 0;
    // UNRESOLVED: a3 is compared as a full dword while the second key HIWORD(a2) is compared as a 16-bit word; the exact sockaddr encoding of the node's two key pairs is not resolved
    // UNRESOLVED: The release slot read at base+16 and the wait handle at this+0xABC alias the same object region in the packet field model; only this+0xABC carries a named field
    // UNRESOLVED: a6 is forwarded unchanged to sub_57DE30 but its meaning is unresolved
}
