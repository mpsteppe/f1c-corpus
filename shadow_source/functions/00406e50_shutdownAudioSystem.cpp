// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406E50
// Canonical corpus name: AudioSystemShutdown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSystemShutdown_00406e50.c

void UnknownObject::shutdownAudioSystem()
{
    // Tear-down of an audio manager object guarded by the active flag at this+0x88: walks four internal linked lists of audio resources, invoking virtual release/cleanup methods on their nodes (vtable+0x18 per component, vtable+0x34 call with argument 1, and MultiStageCleanupWithFree for the third list), freeing every node through FreeWrapper_7bcf, and zeroing each list head. Then performs a virtual call through the object vtable at +0x34, closes the wave output handle at this+0x90 via AIL_waveOutClose, calls AIL_shutdown to terminate the audio library, and clears the active flag. Does nothing if already shut down.
    // GUARD: Read the active flag at this+0x88 (this[34]); if it is zero the system is already shut down and the function returns immediately. [field:this:0x00000088, source:raw]
    // ASSIGNMENT: Seed the list iterator this+0x10 (this[4]) from the component list head this+0x8 (this[2]). [field:this:0x00000008, field:this:0x00000010, source:raw]
    // LOOP: Walk the primary component list: for each entry pointer (first element field at this+0x8) call the virtual method at object vtable offset 0x18 on each component (field vtable+0x18), re-reading the head into the iterator each step and stopping when the list head becomes null. [field:*(this+0x8):0x00000000, field:*(*(this+0x8)+0x0):0x00000018, field:this:0x00000010, field:this:0x00000008, source:raw]
    // LOOP: Walk the linked list headed at this+0x18: for each node read the active byte at node+8 and the next pointer at node+4 (field this+0x1C); if active and the node's object pointer (field this+0x18, whose vtable is the field at *(*(this+0x18)+0x0)) is non-null, invoke the virtual method on that object with argument 1, then free the node via FreeWrapper_7bcf. [field:this:0x00000018, field:*(this+0x18):0x00000000, field:*(*(this+0x18)+0x0):0x00000000, field:*(this+0x1C):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list-1 head and its three sibling words: this+0x18, this+0x1C, this+0x20, this+0x24. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // LOOP: Walk the list headed at this+0x28: for each node read the active byte at node+8 and next pointer at node+4 (field this+0x2C); if active, free the node's object pointer (field this+0x28) and its inner allocation *v12 when present via FreeWrapper_7bcf, then free the node itself. [field:this:0x00000028, field:*(this+0x28):0x00000000, field:*(this+0x2C):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list-2 head and its sibling words: this+0x28, this+0x2C, this+0x30, this+0x34. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // LOOP: Walk the list headed at this+0x38: for each node read the active byte at node+8 and the next pointer at node+4 (field this+0x3C); if active, run MultiStageCleanupWithFree on the node's object pointer, free that pointer via FreeWrapper_7bcf, then free the node itself. [field:this:0x00000038, field:*(this+0x3C):0x00000004, callee:0x00405410, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list-3 head and its sibling words: this+0x38, this+0x3C, this+0x40, this+0x44. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, source:raw]
    // CALL: Invoke the virtual method at object vtable + 52 (offset 0x34, through the vtable pointer at this+0x0) with arguments (this, 0). [field:this:0x00000000, source:raw]
    // GUARD: If the wave-output handle at this+0x90 (this[36]) is non-null, close it via AIL_waveOutClose(this[36]) and set the field back to 0. [field:this:0x00000090, global:0x0059E3A4, source:raw]
    // CALL: Call AIL_shutdown() to terminate the audio library, then clear the active flag at this+0x88 (this[34]) to mark the system shut down. [global:0x0059E394, field:this:0x00000088, source:raw]
    // RETURN: Return the result of AIL_shutdown() when the system was active, or the initial zero flag value when it was already shut down. [global:0x0059E394, field:this:0x00000088, source:raw]

    // Conservative worker pseudocode:
    //   result = this[34];
    //   if (!result) return result;
    //   this[4] = this[2];
    //   while (this[2] && *this[2]) {
    //     call vtable+0x18 on *this[2]; this[4] = this[2];
    //   }
    //   for (node = this[6]; node; node = node->next) {
    //     if (node->active && node->obj) call obj->vtable(this, 1);
    //     FreeWrapper_7bcf(node);
    //   }
    //   this[6] = this[7] = this[8] = this[9] = 0;
    //   for (node = this[10]; node; node = node->next) {
    //     if (node->active) { if (*node->obj) FreeWrapper_7bcf(*node->obj); FreeWrapper_7bcf(node->obj); }
    //     FreeWrapper_7bcf(node);
    //   }
    //   this[10] = this[11] = this[12] = this[13] = 0;
    //   for (node = this[14]; node; node = node->next) {
    //     if (node->active) { MultiStageCleanupWithFree(node->obj); FreeWrapper_7bcf(node->obj); }
    //     FreeWrapper_7bcf(node);
    //   }
    //   this[14] = this[15] = this[16] = this[17] = 0;
    //   call vtable+0x34(this, 0);
    //   if (this[36]) { AIL_waveOutClose(this[36]); this[36] = 0; }
    //   result = AIL_shutdown();
    //   this[34] = 0;
    //   return result;
    // UNRESOLVED: field:obj:0x00000034 is a packet-listed read (an object/import handle around this+0xD0) that has no visible use in the decompiled body.
    // UNRESOLVED: The exact identity of the three list node structures (object pointer + active byte + next pointer) and the vtable+0x34 call target are inferred, not evidenced.
    // UNRESOLVED: AIL_shutdown and AIL_waveOutClose are known Miles Sound System imports per their global symbols, but the library version is not evidenced.
}
