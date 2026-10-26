## sub_58FBA0_0058fba0 — show_named_image

**Summary:** Loads a named image resource (returning 0 on failure) and, if the direct name fails, retries with a WindowName prefix built via sprintf("%s%s"); on success draws the image and holds it for a2 seconds, returning 1 if displayed and 0 otherwise.

**Called by:** sub_4DD750 (004dd750)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ea08b | SEH_58FBA0 | R | SEH scope/unwind record for this function |
| 006f16bc | WindowName | R | fallback prefix string, used when *dword_91CAB0 is null |
| 006f1f34 | aSS | R | sprintf format literal "%s%s" |
| 0091cab0 | dword_91CAB0 | R | holds pointer to the configured name-prefix string; null deref falls back to WindowName |
| 00b69668 | dword_B69668 | R | unknown (not referenced in provided decompilation) |
| 00b698e8 | dword_B698E8 | R | flag whose bit 0 is tested in the hold loop to break early (meaning unknown) |
| 00b6a2f4 | dword_B6A2F4 | R | integer compared > 0 in the hold-loop break condition (meaning unknown) |
| 00b6a328 | dword_B6A328 | R | unknown (not referenced in provided decompilation) |
| 00b6e2a0 | unk_B6E2A0 | R | address passed to a nullsub_7 call after the hold loop (cleanup marker; exact purpose unknown) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045dde0 | sub_45DDE0 | called after the hold loop, before returning success; counterpart of sub_45DE00 (likely ends frame/video state) |
| 0045de00 | sub_45DE00 | called before the blit calls (likely begins frame/video state) |
| 004617b0 | sub_4617B0 | delay/wait invoked with 0.050000001 inside the hold loop |
| 004dd9b0 | sub_4DD9B0 | loads a named resource into an out pointer; branch logic shows 0 = success (nonzero = failure) |
| 004dd9c0 | sub_4DD9C0 | called after the hold loop; likely releases/unloads the loaded resource |
| 004dda20 | sub_4DDA20 | called after each blit (sub_4DDC20); exact purpose unknown |
| 004ddc20 | sub_4DDC20 | 14-argument blit/draw of a loaded object, using its +4/+8 dimensions and the screen descriptor |
| 004ddfe0 | sub_4DDFE0 | returns a screen/viewport descriptor whose +4/+8 fields are read as target dimensions |
| 004eda30 | nullsub_7 | empty no-op function; called for stack-object cleanup slots |
| 00617db0 | sub_617DB0 | initializes timing/frame state (v22 buffer, v18) once at function entry |
| 00617df0 | sub_617DF0 | starts/resets the timing source (argument 1) before the hold loop |
| 00617f80 | sub_617F80 | queries elapsed time (return value compared against a2) |
| 00631761 | _sprintf | builds Buffer from the "%s%s" format with prefix and a1 |

**Guard conditions:** Load path: sub_4DD9B0(&v21, a1, 0, 1) returning 0 (success) jumps directly to LABEL_6 (draw); nonzero (failure) goes to the prefix-retry path. Prefix selection: if *dword_91CAB0 == 0, WindowName is used as prefix, else *dword_91CAB0. After building the prefixed name, a second sub_4DD9B0 call returning nonzero (still failing) sets v24=-1 and returns 0; returning 0 (success) falls into LABEL_6. At LABEL_6, LODWORD(v21) == 0 skips all drawing and returns 0. Hold loop: while sub_617F80(&v20) < a2, each iteration waits 0.05 and, when a3 is set, breaks if (dword_B698E8 & 1) != 0 && dword_B6A2F4 > 0; when a3 is clear the loop runs until elapsed >= a2.

**String literals referenced (deterministic):**

- `%s%s`
