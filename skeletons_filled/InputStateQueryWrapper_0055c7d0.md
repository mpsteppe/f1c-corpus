## InputStateQueryWrapper_0055c7d0 — Wraps input-state query via sub_55C450

**Summary:** Calls sub_55C450 with a field at offset 0x13EC (an input-state handle), constant 0, and the this pointer; returns this. Acts as thin wrapper around an input-state query.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyEventDispatchToSubHandlers (0055c7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13EC | R | — | Input-state handle passed to query function sub_55C450 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055c450 | sub_55C450 | Input state query — reads state from handle, writes result into this pointer |

**Guard conditions:** None — always executes unconditionally.
