## sub_57BCE0_0057bce0 — NetworkPhysicsDestructorChain

**Summary:** Destructor for a network/physics/IO composite object: closes Win32 handles guarded by byte flags, destroys linked lists with vtable-based destructors, frees allocated resources, and chains into sub_583AE0 for final cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithFlagCleanup (0057bcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtablePtr (set to IOOpsVTable off_5B8A68 at entry, then PhysicsVtable off_5B8A00 before sub_583AE0) |
| this | 0x940 | RW | — | cleanupChainReturn (result from sub_583AE0, final return value of destructor) |
| this | 0xAF4 | RW | 0 | handle701 (HANDLE at *(this+0xAF4), closed and zeroed if this[2812] is set) |
| this | 0xAFC | R | — | guardByte_2812 (if set, invokes CloseHandle on handle701 then LinkedListCleanup) |
| this | 0xB10 | RW | 0 | handle708 (HANDLE at *(this+0xB10), closed and zeroed if this[2840] is set) |
| this | 0xB18 | R | — | guardByte_2840 (if set, closes handle708 then LinkedListCleanup) |
| this | 0xB2C | RW | 0 | handle715 (HANDLE at *(this+0xB2C), closed and zeroed if this[2868] is set) |
| this | 0xB34 | R | — | guardByte_2868 (if set, closes handle715) |
| this | 0xB3C | RW | 0 | handle719 (HANDLE at *(this+0xB3C), closed and zeroed if this[2884] is set; preceded by sub_582650) |
| this | 0xB44 | R | — | guardByte_2884 (if set, closes handle719 after sub_582650) |
| this | 0xB68 | RW | 0 | handle730 (HANDLE at *(this+0xB68), closed and zeroed if this[2928] is set; preceded by sub_582A10) |
| this | 0xB70 | R | — | guardByte_2928 (if set, closes handle730 after sub_582A10) |
| this | 0xB94 | RW | 0 | handle741 (HANDLE at *(this+0xB94), closed and zeroed if this[2972] is set; preceded by sub_582CE0) |
| this | 0xB9C | R | — | guardByte_2972 (if set, closes handle741 after sub_582CE0) |
| this | 0xBC0 | RW | 0 | handle752 (HANDLE at *(this+0xBC0), closed and zeroed if this[3016] is set; preceded by LinkedBufferCleanup) |
| this | 0xBC8 | R | — | guardByte_3016 (if set, closes handle752 after LinkedBufferCleanup) |
| this | 0xBEC | RW | 0 | handle763 (HANDLE at *(this+0xBEC), closed and zeroed if this[3060] is set; preceded by NetworkCleanup_fbe0) |
| this | 0xBF4 | R | — | guardByte_3060 (if set, closes handle763 after NetworkCleanup_fbe0) |

**Written-by note (persistence):**
- this 0x0: written during destruction (vtable reassignment) — object being destroyed, persistence irrelevant
- this 0x940: written during destruction — persistence irrelevant
- this 0xAF4: written during destruction (zeroed handle) — persistence irrelevant
- this 0xB10: written during destruction — persistence irrelevant
- this 0xB2C: written during destruction — persistence irrelevant
- this 0xB3C: written during destruction — persistence irrelevant
- this 0xB68: written during destruction — persistence irrelevant
- this 0xB94: written during destruction — persistence irrelevant
- this 0xBC0: written during destruction — persistence irrelevant
- this 0xBEC: written during destruction — persistence irrelevant

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c990 | SEH_57BCE0 | R | SEH registration record for this destructor |
| 0059e1a8 | CloseHandle | R | Win32 CloseHandle import (closes kernel handles) |
| 005b8a00 | off_5B8A00 | R | PhysicsVtable [DERIVED] |
| 005b8a68 | off_5B8A68 | R | IOOpsVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499ae0 | FreeIfNonNull | Frees heap memory at this+0x29E if non-null |
| 0057e530 | sub_57E530 | Pre-cleanup step before network cleanup |
| 0057fbe0 | NetworkCleanup_fbe0 | Network resource cleanup for this object |
| 00581880 | LinkedListDestructionWithVTableReleaseCall | Destroys linked list at this+0xAC8, calling vtable release on each node |
| 005819c0 | LinkedListDestroyWithVtableDestructorCall | Destroys linked list at this+0xAE4, calling vtable destructor on each node |
| 00581a80 | LinkedListCleanup | Cleans up linked list at this+0xB00 and this+0xB1C |
| 005822b0 | LinkedListFreeStandard | Frees linked list at this+0xAAC |
| 00582310 | CloseHandleWrapper | Wraps CloseHandle for handles at this+0xAC8 and this+0xAAC |
| 00582650 | sub_582650 | Sub-cleanup for handle719 region (this+0xB48) |
| 00582a10 | sub_582A10 | Sub-cleanup for handle730 region (this+0xB74) |
| 00582ce0 | sub_582CE0 | Sub-cleanup for handle741 region (this+0xBA0) |
| 00582dc0 | LinkedBufferCleanup | Cleans up linked buffer at this+0xBCC |
| 00583ae0 | sub_583AE0 | Final destructor chain call, returns result |

**Guard conditions:** No field-vs-literal guards — linear destructor sequence. Each handle close is guarded by a byte flag at the corresponding guard offset (e.g., this[3060] guards handle763, this[3016] guards handle752, etc.). If guard byte is zero, CloseHandle and the subordinate cleanup call are skipped. Final vtable reassignment to PhysicsVtable always occurs before sub_583AE0.
