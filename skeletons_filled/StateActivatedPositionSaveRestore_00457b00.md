## StateActivatedPositionSaveRestore_00457b00 — SaveOrRestorePositionByActivationState

**Summary:** Saves or restores a 3-DWORD position vector based on activation flag at offset 0x9C. When a2=1 and flag is clear, copies current position (0x18/0x1C/0x20) to saved slot (0x90/0x94/0x98) and sets flag to 1. When a2=0 and flag is set, restores saved position back to base offsets (0x00/0x04/0x08) via VectorCopy and clears flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraShake (0040adb0), CollisionResponseWithRandomPerturbation (00457a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | source position X |
| this | 0x1C | R | — | source position Y |
| this | 0x20 | R | — | source position Z |
| this | 0x90 | RW | — | saved position X |
| this | 0x94 | RW | — | saved position Y |
| this | 0x98 | RW | — | saved position Z |
| this | 0x9C | RW | 1 | activation flag: 0=inactive/unsaved, 1=active/saved |

**Written-by note (persistence):**
- this 0x90: written when a2==1 and flag==0. Overwritten only on next save.
- this 0x94: written when a2==1 and flag==0. Overwritten only on next save.
- this 0x98: written when a2==1 and flag==0. Overwritten only on next save.
- this 0x9C: set to 1 on save, cleared to 0 on restore. External poke survives until next save/restore cycle.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456130 | VectorCopy | restore: copy 3 DWORDs from saved slot (0x90) to base position (0x00) |

**Guard conditions:** Reads byte at offset 0x9C (flag). If flag != 0 OR a2 != 1 → enters first branch. Within that, if flag == 1 AND a2 == 0 → performs restore. If flag == 0 AND a2 == 1 → performs save. All other combinations (flag==1 with a2==1, flag==0 with a2!=1) are no-op.
