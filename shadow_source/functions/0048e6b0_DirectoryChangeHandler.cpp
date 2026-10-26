// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E6B0
// Canonical corpus name: DirectoryChangeHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectoryChangeHandler_0048e6b0.c

void UnknownObject::DirectoryChangeHandler()
{
    // Directory-path change handler. Appends this object to a doubly linked list, then compares the current directory path at this+0xB8 against the stored path at this+0xE0 (both defaulting to byte_5EA438 when null). If they differ, copies the new path through StringCopyWithBufferRealloc and fires the change-notification virtual method at vtable+0xAC. Always invokes the refresh virtual method at vtable+0x2C with argument 1 and returns 0.
    // CALL: Append this handler object to a doubly linked list via DoublyLinkedListAppend_6750(this, 0). [callee:0x00496750, source:raw]
    // ASSIGNMENT: v2 = this[56] (this+0xE0) stored path; when null, substitute the default path byte_5EA438. [field:this:0x000000E0, global:0x005EA438, source:raw]
    // ASSIGNMENT: v3 = this[46] (this+0xB8) current path; when null, substitute the default path byte_5EA438. [field:this:0x000000B8, global:0x005EA438, source:raw]
    // GUARD: Guard on strcmp(v3, v2) != 0: paths differ -> update path buffer and fire the change callback; paths equal -> skip that block. Falls through to the refresh call either way. [field:this:0x000000B8, field:this:0x000000E0, source:raw]
    // CALL: When paths differ, copy the new path into the buffer: StringCopyWithBufferRealloc(this[46] or byte_5EA438). [callee:0x00566650, field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: When paths differ, invoke the directory-change notification virtual method at vtable+172 (field obj+0xAC) with this as sole argument. [field:obj:0x000000AC, field:this:0x00000000, source:raw]
    // CALL: Always invoke the refresh virtual method at vtable+44 (field obj+0x2C) with (this, 1) after the change block. [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int DirectoryChangeHandler(this) {
    //     DoublyLinkedListAppend_6750(this, 0);
    //     const char* stored = this[0xE0] ? this[0xE0] : byte_5EA438;
    //     const char* current = this[0xB8] ? this[0xB8] : byte_5EA438;
    //     if (strcmp(current, stored) != 0) {
    //       StringCopyWithBufferRealloc(this[0xB8] ? this[0xB8] : byte_5EA438);
    //       (*(void(**)(this*))(this->vtbl + 172))(this);
    //     }
    //     (*(void(**)(this*, int))(this->vtbl + 44))(this, 1);
    //     return 0;
    //   }
    // UNRESOLVED: Class of the this object is unnamed; 'directory change handler' semantics are derived from the path comparison.
    // UNRESOLVED: Which linked list the object is appended to (DoublyLinkedListAppend_6750 target list) is unknown.
    // UNRESOLVED: Purpose of the argument 1 passed to the vtable+0x2C refresh method is unknown.
    // UNRESOLVED: byte_5EA438 is the default path substituted for null fields; its exact contents are DERIVED (default application directory), not proven here.
}
