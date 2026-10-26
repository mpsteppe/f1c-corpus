// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E110
// Canonical corpus name: UIScreenSoundResourceLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIScreenSoundResourceLoader_0048e110.c

void UnknownObject::UIScreenSoundResourceLoader()
{
    // Loads sound resources for a UI screen. Frees any existing Bink sound resource at this+0xE0 (field [56]) via ConditionalFreeWithBinkClose and clears the field. Creates a first sound object at field [57] (this+0xE4) via ObjectCreationWithRollbackOnFailure using the screen path from this+0xB0 (field [44]) or the default byte_5EA438, then normalizes the screen path with StringCopyWithBufferRealloc. When creation succeeded, builds a combined path by concatenating the extra directory dword_5EC3F0 (or default) with the screen path, creates a second sound object at field [57] with it, and, if the creation did not roll back (field 0xE0 still holds the handle), calls sub_551EB0 with the DSP transform parameter flt_7CF2CC. Always returns 0.
    // GUARD: If field [56] (offset 0xE0) is non-null (guard condition 0), close and free the existing Bink sound resource via ConditionalFreeWithBinkClose and clear field 0xE0 to 0. [guard:0, field:this:0x000000E0, callee:0x00551F80, source:raw]
    // CALL: Create the first sound object at field [57] (offset 0xE4) via ObjectCreationWithRollbackOnFailure using the screen path from field [44] (offset 0xB0) or the default byte_5EA438. [field:this:0x000000E4, field:this:0x000000B0, global:0x005EA438, callee:0x00551F10, source:raw]
    // CALL: Normalize the screen path (field [44] or default byte_5EA438) with StringCopyWithBufferRealloc. [global:0x005EA438, callee:0x00566650, source:raw]
    // GUARD: If the created object at field [57] (offset 0xE4) is non-null: build a combined path by copying the extra directory dword_5EC3F0 (or default byte_5EA438) into a stack buffer and appending the screen path from field [44] with strcat. [field:this:0x000000E4, field:this:0x000000B0, global:0x005EC3F0, global:0x005EA438, source:raw]
    // CALL: Create the second sound object at field [57] (offset 0xE4) via ObjectCreationWithRollbackOnFailure using the combined path, and store its handle. [field:this:0x000000E4, callee:0x00551F10, source:raw]
    // CALL: If the object creation did not roll back (field 0xE0 still non-zero), call sub_551EB0 with the DSP transform parameter flt_7CF2CC. [field:this:0x000000E0, global:0x007CF2CC, callee:0x00551EB0, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int LoadScreenSound(void* this) {
    //     if (this[56]) { ConditionalFreeWithBinkClose(this[56]); this[56] = 0; }
    //     const char* path = this[44] ? (const char*)this[44] : byte_5EA438;
    //     this[57] = CreateResourceObject(&this[56], path, 0, 0);
    //     path = this[44] ? (const char*)this[44] : byte_5EA438;
    //     NormalizeString(path);
    //     if (this[57]) {
    //       path = this[44] ? (const char*)this[44] : byte_5EA438;
    //       NormalizeString(path);
    //       const char* dir = dword_5EC3F0 ? (const char*)dword_5EC3F0 : byte_5EA438;
    //       char combined[128]; strcpy(combined, dir); strcat(combined, path);
    //       int ok = CreateResourceObject(&this[56], combined, 0, 0);
    //       this[57] = ok;
    //       if (this[56]) ApplyDSPTransform(flt_7CF2CC);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact lifecycle contract of ObjectCreationWithRollbackOnFailure's rollback semantics on field 0xE0 is not visible here.
    // UNRESOLVED: Global dword_8AFE64 is read by this function per static analysis but does not appear literally in the raw body; its role is unconfirmed.
}
