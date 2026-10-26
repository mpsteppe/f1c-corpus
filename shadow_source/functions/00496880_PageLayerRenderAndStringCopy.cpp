// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00496880
// Canonical corpus name: sub_496880
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_496880_00496880.c

void UnknownObject::PageLayerRenderAndStringCopy()
{
    // UI page/layer render pass. Iterates a linked list of child objects from this+0x1C calling each child's virtual render method (child->vtable + 164). Then, for the active object at this+0x18, calls its virtual position/update method (vtable + 56) with the two fields this+0x5C and this+0x60 as arguments, copies the current page and current layer name strings into string tables via StringReverseCopyLookup (using keys aCurrentPage / aCurrentLayer), and finally calls the active object's virtual finalize method (vtable + 64). Returns 0.
    // LOOP: Iterate the child linked list from this+0x1C following node+0x8C (next pointer), calling the virtual render method (child->vtable + 164) on each child. [field:this:0x0000001C, field:*(this+0xA8):0x000000A4, source:raw]
    // GUARD: Guard: process the active object at this+0x18 only when it is non-null. [field:this:0x00000018, source:raw]
    // CALL: Call the active object's virtual method at vtable + 56 with the two arguments this+0x5C and this+0x60. [field:*(this+0x18):0x00000038, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // CALL: Re-read the active object this+0x18 and call sub_498E40 on it to obtain the sub-object used for the page-name lookup. [callee:0x00498E40, field:this:0x00000018, source:raw]
    // GUARD: Guard: proceed with the page-name copy only when sub_498E40 returns non-null. [callee:0x00498E40, source:raw]
    // CALCULATION: Read the page name string from sub-object + 0x34 (or byte_5EA438 when null) and pass it to StringReverseCopyLookup with the aCurrentPage key. [global:0x005CCA20, global:0x005EA438, callee:0x0049A490, source:raw]
    // GUARD: Guard: proceed with the layer-name copy only when sub_498E40 on the active object returns non-null. [callee:0x00498E40, field:this:0x00000018, source:raw]
    // CALCULATION: Read the layer name string from active object + 0x34 (or byte_5EA438 when null) and pass it to StringReverseCopyLookup with the aCurrentLayer key. [global:0x005CCA10, global:0x005EA438, callee:0x0049A490, source:raw]
    // CALL: Call the active object's virtual finalize method at vtable + 64. [field:*(this+0x18):0x00000040, source:raw]
    // RETURN: Return 0. [source:raw]
    // CALL: Called by sub_46BF10 (0x0046BF10) and UILargeRender (0x00496930). [caller:0x0046BF10, caller:0x00496930, source:raw]

    // Conservative worker pseudocode:
    //   int sub_496880(_DWORD* this) {
    //     for (_DWORD* i = *(_DWORD**)(this + 0x1C); i; i = (_DWORD*)i[35])
    //       ((void(__thiscall*)(_DWORD*))*(int*)(*(int*)i + 164))(i);
    //     _DWORD* cur = *(_DWORD**)(this + 0x18);
    //     if (cur)
    //       ((void(__thiscall*)(int,_DWORD,_DWORD))*(int*)(*(int*)cur + 56))(cur, *(int*)(this + 0x5C), *(int*)(this + 0x60));
    //     if (cur) {
    //       if (sub_498E40(cur)) {
    //         char* page = *(char**)(sub_498E40(cur) + 0x34); if (!page) page = byte_5EA438;
    //         StringReverseCopyLookup(aCurrentPage, page);
    //       }
    //       if (sub_498E40(cur)) {
    //         char* layer = *(char**)(cur + 0x34); if (!layer) layer = byte_5EA438;
    //         StringReverseCopyLookup(aCurrentLayer, layer);
    //       }
    //       ((void(__thiscall*)(_DWORD*))*(int*)(*(int*)cur + 64))(cur);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: sub_498E40 (0x00498E40) is treated as a getter returning a sub-object; its identity and the struct layout at sub-object + 0x34 are not confirmed.
    // UNRESOLVED: The child-node offset 0x8C used as the linked-list next pointer is DERIVED from the raw source; no independent node-struct evidence exists in this packet.
    // UNRESOLVED: The three virtual methods (child vtable + 164, active vtable + 56 and + 64) are dispatched through unknown vtable layouts; the identity of the class hierarchy is unknown.
    // UNRESOLVED: Fields this+0x4C, this+0xA8 and this+0x134 are listed in the packet fields but are not referenced by the raw source text of this function.
}
