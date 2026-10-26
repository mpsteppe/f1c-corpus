## PhysicsTireSystemConstructor_004e4500 — PhysicsTireSystemConstructor

**Summary:** Constructor for physics tire system. Calls sub-initializers for forces, arrays, 4 tire structures, and engine RPM. Sets default field at offset 0x32BC to -1 and EngineMaxRPM at offset 0x39A4 to 0. Physics vehicle setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceStructInit (00423e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | RW | 18446744073709551615 | field initialized to -1 (0xFFFFFFFF) |
| this | 0x39A4 | RW | 0 | EngineMaxRPM [CONFIRMED] |

**Written-by note (persistence):**
- this 0x32BC: set once to -1 during construction; external poke survives
- this 0x39A4: set once to 0 during construction; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a48c0 | F_5LoopInitCall | initialize 5-loop sub-structure at this+0x32C0 |
| 004dfb90 | sub_4DFB90 | initialize single tire sub-structure (called 4 times) |
| 004dfbb0 | sub_4DFBB0 | initialize dual-array sub-structure at this+0x6E4 |
| 004e4790 | sub_4E4790 | post-constructor finalization for tire system |
| 004f2430 | ConstructorZeroInitSubCalls | zero-init sub-structure at this+0x3D78 |
| 004f6f20 | sub_4F6F20 | initialize force sub-structure at this+0x8 |

**Guard conditions:** None — full constructor always executes all steps.
