## sub_58FFA0_0058ffa0 — update_toggle_flags

**Summary:** Reads a state value from *dword_B640C8 and sets three boolean feature toggles (ids 64, 128, 256) to specific on/off combinations via sub_5E5B30, depending on which state range (0-2, 3-4, 5-6) the value falls in.

**Called by:** sub_54B5A0 (0054b5a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00590040 | jpt_58FFAA | R | jump table for the switch on *dword_B640C8 |
| 00b640c8 | dword_B640C8 | R | points to the state/selector value driving the toggle combination |
| 00fb1ce0 | dword_FB1CE0 | R | unknown (not referenced in provided decompilation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e5b30 | sub_5E5B30 | sets feature toggle identified by first argument to the boolean value of the second argument |

**Guard conditions:** Switch on *dword_B640C8: cases 0-2 set 64=off, 128=on, 256=on; cases 3-4 set 64=on, 128=off, 256=on; cases 5-6 set 64=on, 128=on, 256=off; any other value (default) sets all three off (64=0, 128=0, 256=0).
