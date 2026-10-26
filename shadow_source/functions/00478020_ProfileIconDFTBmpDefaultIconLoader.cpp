// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478020
// Canonical corpus name: ProfileIconDFTBmpDefaultIconLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileIconDFTBmpDefaultIconLoader_00478020.c

void UnknownObject::ProfileIconDFTBmpDefaultIconLoader()
{
    // Loads the default profile icon BMP. Reads a custom icon path override at this+0x158; when null falls back to the default application directory byte_5EA438. Loads via sub_497AD0 on the loader sub-object at this+0x40, retrying with the default icon path aProfileiconDft when the first load returns null. Stores the loaded object through ObjectFieldInitWithIndirectLookup into the field at this+73 dwords, then reports success (argument 1) or failure (argument 0) through the virtual notification at vtable offset 0x3C and returns the field pointer on success, null on failure.
    // ASSIGNMENT: Read the custom icon path override from this+0x158 (86th dword). [field:this:0x00000158, source:raw]
    // GUARD: When the override path is null, fall back to the default application directory byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Attempt to load the BMP through sub_497AD0 using the loader sub-object at this+0x40 with the chosen path and flags 0. [callee:0x00497AD0, field:this:0x00000040, source:raw]
    // GUARD: When the first load attempt returns null, retry with the default profile icon path aProfileiconDft. [global:0x005C66F8, source:raw]
    // CALL: Second load attempt through sub_497AD0 on the same loader sub-object at this+0x40 with aProfileiconDft and flags 0. [callee:0x00497AD0, field:this:0x00000040, source:raw]
    // CALL: Store the loaded object through ObjectFieldInitWithIndirectLookup into the profile-icon field at this+73 dwords (byte offset this+0x124). [callee:0x00499B80, source:raw]
    // GUARD: Branch on the loaded-object handle at this+0x144 (81st dword): non-zero selects the success path, zero the failure path. [field:this:0x00000144, source:raw]
    // CALL: Success path: invoke the virtual notification at vtable offset 0x3C (60) with argument 1, reading the vtable pointer at this+0x0. [field:obj:0x0000003C, field:this:0x00000000, source:raw]
    // RETURN: Success path: return this + 292, the address of the initialized profile-icon field. [source:raw]
    // CALL: Failure path: invoke the same virtual notification at vtable offset 0x3C with argument 0, reading the vtable pointer at this+0x0. [field:obj:0x0000003C, field:this:0x00000000, source:raw]
    // RETURN: Failure path: return null. [source:raw]

    // Conservative worker pseudocode:
    //   path = this->customIconPathOverride;        // this+0x158
    //   if (path == NULL) path = byte_5EA438;       // default app directory
    //   obj = sub_497AD0(this->loader, path, 0);    // this+0x40
    //   if (obj == NULL) obj = sub_497AD0(this->loader, aProfileiconDft, 0);
    //   ObjectFieldInitWithIndirectLookup(&this->iconField, obj);  // this+0x124
    //   if (this->loadedHandle) {                   // this+0x144
    //       notify(this, 1);                        // vtable+0x3C
    //       return &this->iconField;
    //   } else {
    //       notify(this, 0);
    //       return NULL;
    //   }
    // UNRESOLVED: Identity of the virtual notification method at vtable offset 0x3C is undocumented; the success/failure signaling interpretation is DERIVED from the argument values.
    // UNRESOLVED: Semantics of the loader sub-object at this+0x40 and of byte_5EA438 as a default directory are DERIVED from the fill, not independently proven.
    // UNRESOLVED: The meaning of the returned pointer this+292 (the stored field) for callers is unknown.
}
