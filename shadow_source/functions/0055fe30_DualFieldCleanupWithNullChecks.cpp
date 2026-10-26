// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055FE30
// Canonical corpus name: DualFieldCleanupWithNullChecks
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldCleanupWithNullChecks_0055fe30.c

void UnknownObject::DualFieldCleanupWithNullChecks()
{
    // Two-field resource cleanup method. If the file-handle field at offset 0x10 is non-null it is closed via FileCloseWithLock and zeroed; if the buffer-pointer field at offset 0x128 is non-null it is released via FreeWrapper_7bcf and zeroed. Both releases are null-guarded; always returns 0.
    // GUARD: If the field at this+0x10 (file handle) is non-null, enter the close-and-clear block. [field:this:0x00000010, source:raw]
    // CALL: Call FileCloseWithLock(*(this+0x10)) to close the open handle. [callee:0x00587D02, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Clear the handle field: *(this+0x10) = 0. [field:this:0x00000010, source:raw]
    // GUARD: If the field at this+0x128 (allocated buffer pointer) is non-null, enter the free-and-clear block. [field:this:0x00000128, source:raw]
    // CALL: Call FreeWrapper_7bcf(*(this+0x128)) to release the allocated buffer. [callee:0x00587BCF, field:this:0x00000128, source:raw]
    // ASSIGNMENT: Clear the buffer pointer: *(this+0x128) = 0. [field:this:0x00000128, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (this->handle) {
    //     FileCloseWithLock(this->handle);
    //     this->handle = 0;
    //   }
    //   if (this->buffer) {
    //     FreeWrapper_7bcf(this->buffer);
    //     this->buffer = 0;
    //   }
    //   return 0;
    // UNRESOLVED: The struct owning offsets 0x10 and 0x128 is not proven; field roles (file handle and data buffer) follow callee names only.
    // UNRESOLVED: The relationship between the two released resources and any ordering requirement is unknown.
}
