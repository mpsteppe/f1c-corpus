// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560340
// Canonical corpus name: sub_560340
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_560340_00560340.c

void UnknownObject::loadRenderingResources()
{
    // Guarded by the feature flag at this+0x13D4: when set, loads three rendering resources (likely vertex-buffer related) through the loader object's vtable at this+0x1100, using the vtable method at offset 0x12C (byte +300) with identifier pairs (unk_5DC7A4/5DC7B8, unk_5DD1E0/5DD1F8, unk_5DC628/5DC640) writing results into dword_8CEF7C, dword_8CEF74 and dword_8CEF78 with a 16-byte buffer; every call result is stored to *this, and any non-zero result aborts with -1. On the final success path a vtable method at offset 0xC8 (byte +200) is called with (153, 1) and 0 is returned. When the flag is clear, the three globals default to 0, 0 and 324 and 0 is returned. Called from sub_53EB70.
    // GUARD: Feature-flag guard on this[1269] (offset 0x13D4): non-zero selects the resource-loading path, zero selects the global-default path. Reached from caller sub_53EB70. [field:this:0x000013D4, caller:0x0053EB70, source:raw]
    // CALL: First resource load: invokes the loader object at this+0x1100 through its vtable method at byte offset +300 (field +0xC8) with (this+0x1100, &unk_5DC7A4, &unk_5DC7B8, &dword_8CEF7C, 16) and stores the result to *this. The ABI lead names this D3D resource file loader. [field:this:0x00001100, field:*(this+0x1100):0x000000C8, field:this:0x00000000, global:0x005DC7A4, global:0x005DC7B8, global:0x008CEF7C, abi:lead, source:raw]
    // GUARD: If the first load's returned status is non-zero, return -1 immediately. [function:0x00560340, source:raw]
    // CALL: Second resource load: invokes the same vtable method at +300 on this+0x1100 with (this+0x1100, &unk_5DD1E0, &unk_5DD1F8, &dword_8CEF74, 16) and stores the result to *this. [field:this:0x00001100, field:*(this+0x1100):0x000000C8, field:this:0x00000000, global:0x005DD1E0, global:0x005DD1F8, global:0x008CEF74, source:raw]
    // GUARD: If the second load's returned status is non-zero, return -1 immediately. [function:0x00560340, source:raw]
    // CALL: Third resource load: invokes the same vtable method at +300 on this+0x1100 with (this+0x1100, &unk_5DC628, &unk_5DC640, &dword_8CEF78, 16) and stores the result to *this. [field:this:0x00001100, field:*(this+0x1100):0x000000C8, field:this:0x00000000, global:0x005DC628, global:0x005DC640, global:0x008CEF78, source:raw]
    // GUARD: If the third load's returned status is non-zero, return -1 immediately. [function:0x00560340, source:raw]
    // CALL: Final success-path call: invokes the loader vtable method at byte offset +200 (field +0x12C) on this+0x1100 with (this+0x1100, 153, 1) and stores the result to *this. [field:this:0x00001100, field:*(this+0x1100):0x0000012C, field:this:0x00000000, source:raw]
    // RETURN: Success path returns 0 after the final vtable call. [function:0x00560340, source:raw]
    // ASSIGNMENT: Flag-clear default path initializes the three globals: dword_8CEF7C = 0, dword_8CEF74 = 0, dword_8CEF78 = 324. [global:0x008CEF7C, global:0x008CEF74, global:0x008CEF78, source:raw]
    // RETURN: Flag-clear default path returns 0. [function:0x00560340, source:raw]

    // Conservative worker pseudocode:
    //   int loadRenderingResources(void *this) {
    //     if (*(int*)((char*)this + 0x13D4) != 0) {
    //       loader = *(void**)((char*)this + 0x1100);
    //       *(int*)this = vtable(loader, 0x12C)(loader, &unk_5DC7A4, &unk_5DC7B8, &dword_8CEF7C, 16);
    //       if (*(int*)this != 0) return -1;
    //       *(int*)this = vtable(loader, 0x12C)(loader, &unk_5DD1E0, &unk_5DD1F8, &dword_8CEF74, 16);
    //       if (*(int*)this != 0) return -1;
    //       *(int*)this = vtable(loader, 0x12C)(loader, &unk_5DC628, &unk_5DC640, &dword_8CEF78, 16);
    //       if (*(int*)this != 0) return -1;
    //       *(int*)this = vtable(loader, 0xC8)(loader, 153, 1);
    //       return 0;
    //     }
    //     dword_8CEF7C = 0;
    //     dword_8CEF74 = 0;
    //     dword_8CEF78 = 324;
    //     return 0;
    //   }
    // UNRESOLVED: The three identifier pairs (unk_5DC7A4/5DC7B8, unk_5DD1E0/5DD1F8, unk_5DC628/5DC640) and the two output globals dword_8CEF7C/dword_8CEF74 have no semantic identity in the packet beyond being resource identifiers and loaded-resource handles.
    // UNRESOLVED: The vtable method at +300 and +200 map to specific loader operations whose D3D resource meanings are not present in the packet.
    // UNRESOLVED: The object class owning this loader is unknown; the owner stays UnknownObject.
}
