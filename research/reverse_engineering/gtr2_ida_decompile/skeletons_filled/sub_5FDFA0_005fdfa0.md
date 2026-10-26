## sub_5FDFA0_005fdfa0 — Notification dispatch trampoline

**Summary:** Thin wrapper that unconditionally forwards its argument to sub_5FDE00, the notification/handler dispatch routine; exists as an alternate entry point to that dispatcher.

**Called by:** sub_5ECBC0 (005ecbc0), sub_5ED040 (005ed040)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the argument is passed straight through to sub_5FDE00 with no checks or branches.
