// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4DB0
// Canonical corpus name: UIComponentCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentCleanup_004a4db0.c

void UnknownObject::UIComponentCleanup()
{
    // Teardown/cleanup of a UI component object: resets five byte flags at this+0x35/0x75/0xB5/0xF5/0x135 to 1, clears ~25 numeric/state fields across this+0x158..0x1CC (including -1 sentinels at this+0x15C and this+0x160), then conditionally releases three child resources: an array at this+0xC and an array at this+0x10 via ArrayResourceCleanup plus FreeWrapper_7bcf, and a buffer at this+0x14 via sub_4A3B30, sub_4A2220 and FreeWrapper_7bcf. Each freed pointer is nulled. Returns the last free result.
    // ASSIGNMENT: Set the five byte flags at this+0x35, this+0x75, this+0xB5, this+0xF5 and this+0x135 to 1. [field:this:0x00000035, field:this:0x00000075, field:this:0x000000B5, field:this:0x000000F5, field:this:0x00000135, source:raw]
    // ASSIGNMENT: Clear the numeric fields this+0x158, this+0x184, this+0x188 and this+0x18C to 0. [field:this:0x00000158, field:this:0x00000184, field:this:0x00000188, field:this:0x0000018C, source:raw]
    // ASSIGNMENT: Set the byte field this+0x190 to 0 and the sentinel dwords this+0x15C and this+0x160 to -1. [field:this:0x00000190, field:this:0x0000015C, field:this:0x00000160, source:raw]
    // ASSIGNMENT: Reset the remaining numeric/state fields this+0x194, this+0x198, this+0x19C, this+0x1A0, this+0x1A4, this+0x1A8, this+0x1AC, this+0x1B0, this+0x1B8, this+0x1BC, this+0x1C0, this+0x1C4, this+0x1C8 and this+0x1CC to 0. [field:this:0x00000194, field:this:0x00000198, field:this:0x0000019C, field:this:0x000001A0, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B8, field:this:0x000001BC, field:this:0x000001C0, field:this:0x000001C4, field:this:0x000001C8, field:this:0x000001CC, source:raw]
    // ASSIGNMENT: Clear the object pointer field this+0x8 to 0 while reading the first child resource pointer from this+0xC. [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: If the array resource at this+0xC is non-null, run ArrayResourceCleanup on it, free it via FreeWrapper_7bcf and null this+0xC. [field:this:0x0000000C, callee:0x004A29A0, callee:0x00587BCF, source:raw]
    // GUARD: If the array resource at this+0x10 is non-null, run ArrayResourceCleanup on it, free it via FreeWrapper_7bcf and null this+0x10. [field:this:0x00000010, callee:0x004A29A0, callee:0x00587BCF, source:raw]
    // GUARD: If the buffer at this+0x14 is non-null, tear it down with sub_4A3B30 and sub_4A2220, free it via FreeWrapper_7bcf and null this+0x14. [field:this:0x00000014, callee:0x004A3B30, callee:0x004A2220, callee:0x00587BCF, source:raw]
    // RETURN: Return the result of the last free operation (0 when no child resource was released). [source:raw]

    // Conservative worker pseudocode:
    //   int UIComponentCleanup(int this) {
    //     *(BYTE*)(this + 0x35) = 1; *(BYTE*)(this + 0x75) = 1;
    //     *(BYTE*)(this + 0xB5) = 1; *(BYTE*)(this + 0xF5) = 1; *(BYTE*)(this + 0x135) = 1;
    //     *(DWORD*)(this + 0x158) = 0; *(DWORD*)(this + 0x184) = 0; *(DWORD*)(this + 0x188) = 0; *(DWORD*)(this + 0x18C) = 0;
    //     *(BYTE*)(this + 0x190) = 0;
    //     *(DWORD*)(this + 0x15C) = -1; *(DWORD*)(this + 0x160) = -1;
    //     *(DWORD*)(this + 0x194..0x1CC) = 0; *(BYTE*)(this + 0x1AC) = 0;
    //     *(DWORD*)(this + 0x8) = 0;
    //     if (*(void**)(this + 0xC))  { ArrayResourceCleanup(*(this + 0xC));  FreeWrapper_7bcf(*(this + 0xC));  *(this + 0xC) = 0; }
    //     if (*(void**)(this + 0x10)) { ArrayResourceCleanup(*(this + 0x10)); FreeWrapper_7bcf(*(this + 0x10)); *(this + 0x10) = 0; }
    //     if (*(void**)(this + 0x14)) { sub_4A3B30(*(this + 0x14)); sub_4A2220(*(this + 0x14)); FreeWrapper_7bcf(*(this + 0x14)); *(this + 0x14) = 0; }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the five byte flags set to 1 (this+0x35/0x75/0xB5/0xF5/0x135) and of the -1 sentinels at this+0x15C/0x160 is unknown; the prelabel template classified this as ctor_init, but the resource-releasing tail indicates cleanup.
    // UNRESOLVED: The roles of the three child resources at this+0xC, this+0x10 and this+0x14, and the exact distinction between sub_4A2220 and sub_4A3B30 during teardown, are unknown.
    // UNRESOLVED: The owner class of this object is unknown; no class evidence is available in the packet.
}
