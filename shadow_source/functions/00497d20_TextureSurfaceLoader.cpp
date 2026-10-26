// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497D20
// Canonical corpus name: TextureSurfaceLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureSurfaceLoader_00497d20.c

void UnknownObject::TextureSurfaceLoader()
{
    // Loads a texture/surface by name a2 and registers it in a per-object linked list. Returns 0 for a null name, a null global init object, or a failed surface creation; returns 1 if the name was already loaded (no-op) or after a successful load. On a new load it resolves the base directory (dword_5EC400 with byte_5EA438 fallback), tells the init object (dword_8AC4C4) to set that base, builds a path buffer, asks the init object's surface-creation method to open it, then allocates an 88-byte node holding the name (strcpy at +0), the surface handle (+0x50) and a next pointer (+0x54), and appends the node at the tail of the list whose head is this+0x10C while incrementing the counter at this+0x110.
    // GUARD: Guard: if a2 (the requested surface name) is null, return 0 immediately. [source:raw]
    // GUARD: Guard: call sub_497E80(a2) to test whether the name is already loaded; when already loaded, skip the whole load path and return 1 (idempotent no-op). [callee:0x00497E80, source:raw]
    // GUARD: Guard: if global init object dword_8AC4C4 is null, return 0. [global:0x008AC4C4, source:raw]
    // CALCULATION: Resolve the base directory string: use dword_5EC400 if non-null, otherwise fall back to byte_5EA438. [global:0x005EC400, global:0x005EA438, source:raw]
    // CALL: Call vtable+0x44 (offset 68) on the init object dword_8AC4C4 passing the resolved base directory string (sets the load base path). [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Initialize the stack path buffer v14 to {0, -1, 0, 0} and a flag byte v15 to 0. [source:raw]
    // CALL: StringCopyWithBufferRealloc(byte_5EA438): append the default base directory to the path buffer. [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(a2): append the requested surface name to the path buffer. [callee:0x00566650, source:raw]
    // CALL: Call vtable+0x5C (offset 92) on the init object with the path buffer, argument 0 and constant 15; result v4 is a surface object (or null on failure). [global:0x008AC4C4, source:raw]
    // GUARD: Guard: if surface creation returned null, free the temp buffer v14[0] if allocated and return 0. [callee:0x00587BCF, source:raw]
    // GUARD: Guard: call vtable+0x14 (offset 20) on the new surface; if it reports failure, call the surface destructor vtable+0x00 with flag 1, free the temp buffer, and return 0. [source:raw]
    // CALL: OperatorNewNhMallocWrapper(88): allocate an 88-byte list node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new node: zero the surface-handle slot (+0x50) and the next-pointer slot (+0x54). [source:raw]
    // CALL: strcpy(node, a2): copy the surface name into the node at offset +0. [source:raw]
    // ASSIGNMENT: Store the surface object handle into node+0x50. [source:raw]
    // LOOP: Walk the loaded-surface list starting at this+0x10C following each node's next pointer at +0x54 until the last node (tail) is found. [field:this:0x0000010C, field:*(*(this+0x160)+0x54):0x00000054, source:raw]
    // ASSIGNMENT: Append the new node: set the tail's +0x54 next pointer to the node, or if the list is empty set this+0x10C to the node as the new head. [field:this:0x0000010C, field:*(*(this+0x160)+0x54):0x00000054, source:raw]
    // CALCULATION: Increment the registered-surface counter at this+0x110. [field:this:0x00000110, source:raw]
    // CALL: Free the temp path buffer v14[0] via FreeWrapper_7bcf when it was allocated. [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 on success or when the name was already loaded. [source:raw]

    // Conservative worker pseudocode:
    //   int TextureSurfaceLoader(void *self, const char *name) {
    //     if (!name) return 0;
    //     if (AlreadyLoaded(name)) return 1;
    //     if (!gInit) return 0;
    //     const char *base = gBaseDir ? (const char*)gBaseDir : gDefaultBase;
    //     gInit->SetBaseDir(base);
    //     char buf[...]; buf[0]=0; buf[1]=(void*)-1; buf[2]=0; buf[3]=0;
    //     StringCopyRealloc(&buf, gDefaultBase);
    //     StringCopyRealloc(&buf, name);
    //     void *surf = gInit->CreateSurface(&buf, 0, 15);
    //     if (!surf) { FreeIfAny(buf); return 0; }
    //     if (surf->CheckFailed()) { surf->Destroy(1); FreeIfAny(buf); return 0; }
    //     Node *node = OperatorNew(88);
    //     if (node) { node->handle = 0; node->next = 0; }
    //     strcpy(node->name, name);
    //     node->handle = surf;
    //     if (this->head) {
    //       Node *t = this->head;
    //       while (t->next) t = t->next;
    //       t->next = node;
    //     } else {
    //       this->head = node;
    //     }
    //     ++this->count;
    //     FreeIfAny(buf);
    //     return 1;
    //   }
    // UNRESOLVED: Identity of the class owning this: it manages a loaded-surface linked list (head this+0x10C, counter this+0x110) but the owner type is unknown.
    // UNRESOLVED: The exact meaning of constants passed to the surface creation call (0 and 15) is not established.
    // UNRESOLVED: field this+0x160 is recorded as read by the analysis table but no read of it appears in the raw source text; it may be a provenance alias for the list traversal.
}
