## GraphicsResourceDestructor_0040fb30 — Track Object Manager Destructor

**Summary:** Destructor for the track object manager: frees all heap-allocated arrays (vehicle, dspoly, non-DSP, cone, post, sign, wheel, wing, part) created by the constructor at 0x40FE50, calling per-element destructors (ShortComputation_fd70 or EmptyStub_aa60) on large struct arrays before freeing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DelegationThunk (0040e1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | total count (zeroed on destruct) |
| this | 0x4 | RW | 0 | capacity (zeroed on destruct) |
| this | 0x8 | RW | 0 | combined pointer array (freed, then zeroed) |
| this | 0xC | RW | 0 | vehicle count (used as count in free, then zeroed) |
| this | 0x10 | RW | 0 | vehicle data array pointer (freed with adjusted base, then zeroed) |
| this | 0x14 | RW | 0 | dspoly/dsindicator count (zeroed on destruct) |
| this | 0x18 | RW | 0 | dspoly/dsindicator small array pointer (freed, then zeroed) |
| this | 0x1C | RW | 0 | non-DSP node count (zeroed on destruct) |
| this | 0x20 | RW | 0 | non-DSP small array pointer (freed, then zeroed) |
| this | 0x24 | RW | 0 | cone/dscone count (zeroed on destruct) |
| this | 0x28 | RW | 0 | cone small array pointer (freed, then zeroed) |
| this | 0x2C | RW | 0 | cone large array pointer (792-byte, per-element Short_fd70 destructor then freed) |
| this | 0x30 | RW | 0 | post count (zeroed on destruct) |
| this | 0x34 | RW | 0 | post small array pointer (freed, then zeroed) |
| this | 0x38 | RW | 0 | post large array pointer (792-byte, per-element Short_fd70 destructor then freed) |
| this | 0x3C | RW | 0 | sign count (zeroed on destruct) |
| this | 0x40 | RW | 0 | sign small array pointer (freed via ArrayDestructorIterator with EmptyStub_aa60, then zeroed) |
| this | 0x44 | RW | 0 | sign large array pointer (792-byte, per-element Short_fd70 destructor then freed) |
| this | 0x48 | RW | 0 | wheel count (zeroed on destruct) |
| this | 0x4C | RW | 0 | wheel small array pointer (freed via ArrayDestructorIterator with EmptyStub_aa60, then zeroed) |
| this | 0x50 | RW | 0 | wheel large array pointer (808-byte, per-element Short_fd70 destructor then freed) |
| this | 0x54 | RW | 0 | wing count (zeroed on destruct) |
| this | 0x58 | RW | 0 | wing small array pointer (freed via ArrayDestructorIterator with EmptyStub_aa60, then zeroed) |
| this | 0x5C | RW | 0 | wing large array pointer (freed via ArrayOfObjectsDestructor) |
| this | 0x60 | RW | 0 | part count (zeroed on destruct) |
| this | 0x64 | RW | 0 | part small array pointer (freed via ShortComputation_fda0) |
| this | 0x68 | RW | 0 | part large array pointer (freed via ArrayOfObjectsDestructor) |

**Written-by note (persistence):**
- this 0x0: once at destruction — external poke does NOT survive (zeroed)
- this 0x4: once at destruction — external poke does NOT survive (zeroed)
- this 0x8: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0xC: once at destruction — external poke does NOT survive (zeroed)
- this 0x10: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x14: once at destruction — external poke does NOT survive (zeroed)
- this 0x18: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x1C: once at destruction — external poke does NOT survive (zeroed)
- this 0x20: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x24: once at destruction — external poke does NOT survive (zeroed)
- this 0x28: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x2C: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x30: once at destruction — external poke does NOT survive (zeroed)
- this 0x34: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x38: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x3C: once at destruction — external poke does NOT survive (zeroed)
- this 0x40: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x44: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x48: once at destruction — external poke does NOT survive (zeroed)
- this 0x4C: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x50: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x54: once at destruction — external poke does NOT survive (zeroed)
- this 0x58: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x5C: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x60: once at destruction — external poke does NOT survive (zeroed)
- this 0x64: once at destruction — external poke does NOT survive (freed and zeroed)
- this 0x68: once at destruction — external poke does NOT survive (freed and zeroed)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040fd70 | ShortComputation_fd70 | R | per-element destructor for large (792/808-byte) struct arrays |
| 0047aa60 | EmptyStub_aa60 | R | no-op destructor stub for 36-byte small struct arrays |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | iterate array calling per-element destructor, then free |
| 0040fd70 | ShortComputation_fd70 | per-element cleanup on large struct (792 or 808 byte) |
| 0040fda0 | ShortComputation_fda0 | cleanup part small array (specialized variant) |
| 0040fdd0 | ArrayOfObjectsDestructor | destruct an array of objects with internal cleanup |
| 00587bcf | FreeWrapper_7bcf | free memory (wrapper) |

**Guard conditions:** All guards check if a pointer field is non-null. When non-null (PASSES), the array is destructed (with per-element cleanup if large) then freed and zeroed. When null (BLOCKED), the free is skipped.
