## WheelDynamicsInit_0043e230 — Wheel dynamics initialization

**Summary:** Initializes wheel dynamics state: sets contact constraints, parameters, and grid values for 4 wheels. Initializes wheel struct entries with default bit patterns and cleans up resources. Part of wheel physics initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DynMan_Post (0042c9f0), DynamicsObjectInitialization (00438c10), PhysicsInitSequence (00438ca0), sub_4E4790 (004e4790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5D8 | RW | 18446744071819766006 | Default wheel struct entry (first dword pair) |
| this | 0x5DC | RW | 1081507266 → 3.8514f | Default wheel struct entry (second dword pair) |
| this | 0x5E0 | RW | — | Copied from 0x5D8 (same initial pattern) |
| this | 0x5E4 | RW | — | Copied from 0x5DC (same initial pattern) |
| this | 0x5E8 | RW | — | Copied from 0x5D8 (same initial pattern) |
| this | 0x5EC | RW | — | Copied via v8[3] = result[3] (carries forward) |
| this | 0x6B8 | R | — | Input value for SetContactConstraint call |
| this | 0x162C | R | — | Pointer checked for non-null before FreeWrapper_7bcf |
| this | 0x1CFC | R | — | Pointer checked for non-null before FreeWrapper_7bcf |
| this | 0x1D4C | R | — | Float value for SimpleSetterWithFlag call |
| this | 0x1F00 | RW | 0 | Cleared to zero after initialization |

**Written-by note (persistence):**
- this 0x5D8: recalc every frame — external poke does NOT persist
- this 0x5DC: recalc every frame — external poke does NOT persist
- this 0x5E0: recalc every frame — external poke does NOT persist
- this 0x5E4: recalc every frame — external poke does NOT persist
- this 0x5E8: recalc every frame — external poke does NOT persist
- this 0x5EC: recalc every frame — external poke does NOT persist
- this 0x1F00: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00431930 | SetContactConstraint | Sets wheel contact constraint parameters |
| 004319c0 | ParameterArraySetterWithDirtyFlag | Sets wheel parameter with dirty flag |
| 00431a50 | SimpleSetterWithFlag | Sets simple parameter with update flag |
| 00431a70 | PhysicsGridValueSet | Sets physics grid value for wheel |
| 004358f0 | PhysicsBufferClear | Clears physics buffer |
| 004d5840 | ResourceDestroy | Destroys resource handle |
| 0056e970 | sub_56E970 | Additional wheel dynamics setup |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory if pointer non-null |

**Guard conditions:** If pointer at this+0x162C or this+0x1CFC is non-null, free the pointed memory via FreeWrapper_7bcf.
