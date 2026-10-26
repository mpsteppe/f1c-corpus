## sub_5FBCC0_005fbcc0 — Recursive object update: orientation fixup + child-list flag propagation

**Summary:** Thiscall scene-object method. When the object's flag bit 0x2 is clear and its gate checks pass, it computes view-relative angles (sub_5E4DA0) and applies orientation deltas (sub_5DB1E0) for objects flagged 0x100/0x2000, runs per-object processing (sub_5FBB60), then walks the linked list rooted at this+0x274 storing the cursor at this+0x27C and recursively processes each child, OR-ing flag 0x40 into each child when sub_5DAE90's result (v4) is nonzero.

**Called by:** sub_5FBCC0 (005fbcc0), sub_5FBFF0 (005fbff0), sub_608270 (00608270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x274)+0x0) | 0x0 | RW | — | First element/object pointer of the current list node; read as v6 and conditionally OR-ed with flag 0x40 (`*v6 \|= 0x40`) |
| *(*(this+0x27C)+0x4) | 0x0 | R | — | Next-node pointer of the current cursor node (v8 = *(v7+4)); terminates loop when null |
| *(this+0x274) | 0x0 | R | — | Head pointer of the child/update list (v5); copied into the cursor before traversal |
| *(this+0x27C) | 0x4 | R | — | Cursor node's next pointer, re-read via v7 = *(this+0x27C) after the recursive call |
| this | 0x0 | R | — | Object flag word; tested for 0x2 (skip), 0x100 and 0x2000 (orientation paths) |
| this | 0x274 | R | — | List head field, source of the traversal root |
| this | 0x27C | RW | — | Traversal cursor: set to head (v5) before the loop, advanced to v8 each iteration; re-read after recursion |

**Written-by note (persistence):**
- *(*(this+0x274)+0x0) 0x0: conditional read-modify-write (OR 0x40) on each traversal pass, only when v4 = sub_5DAE90(this,1,1) is nonzero. The bit is never cleared here, so an external poke clearing it survives only until the next pass with v4 nonzero re-sets it.
- this 0x27C: transient traversal cursor — recalculated (reset to the head, then advanced) on every call, so an external poke is overwritten each time the function runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072d3ac | flt_72D3AC | R | Float constant used as π (3.1415927) in the orientation fixup (`3.1415927 - angle`) for the 0x100 and 0x2000 flag paths |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005da650 | sub_5DA650 | Gate check on (this, a2); nonzero required to run the body |
| 005dae90 | sub_5DAE90 | Called as (this, 1, 1); return captured in v4 and decides whether children get flag 0x40 |
| 005daf80 | sub_5DAF80 | Processing gate on ((float*)this, v3, 0); nonzero enables sub_5FBB60 and the child traversal |
| 005db1e0 | sub_5DB1E0 | Applies orientation/rotation values computed from sub_5E4DA0 outputs (full 3-arg path or yaw-only path) |
| 005e4da0 | sub_5E4DA0 | Computes view-relative values into v13, a2 and v12 used for the rotation math |
| 005fbb60 | sub_5FBB60 | Per-object processing invoked with (this, v3) before iterating children |
| 005fbcc0 | sub_5FBCC0 | Recursive self-call per list element (context v3), so every child runs the same update |

**Guard conditions:** Entry is blocked when the object flag word `*this` has bit 0x2 set (`(*this & 2) == 0` fails → whole body skipped). Inside, sub_5DA650(this,a2) must return nonzero, else nothing runs. The orientation block runs only when `(*this & 0x2100) != 0`; within it bit 0x100 selects the full path (v11=-v12, angle = π - a2) and, failing that, bit 0x2000 selects the yaw-only path (angle = π - a2, other args 0). sub_5DAF80((float*)this, v3, 0) must be nonzero to pass; then sub_5FBB60 runs and the child list is walked — the loop breaks as soon as the cursor (this+0x27C) or its next pointer (*(v7+4)) becomes null, and iterates only while `*v8` is nonzero.
