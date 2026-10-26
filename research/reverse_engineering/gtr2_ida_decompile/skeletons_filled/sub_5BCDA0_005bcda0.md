## sub_5BCDA0_005bcda0 — Interlocked-exchange shim then tail-call

**Summary:** Computes a value from the module global dword_16C6E90 minus an inline immediate embedded after sub_5BE8C0, performs an atomic exchange (_InterlockedExchange) of that value through a stack slot seeded with a2, then tail-calls sub_5BCDA7(a3, a4). A generated interlocked/synchronization shim around the worker routine.

**Called by:** sub_5C0E10 (005c0e10), sub_5C1050 (005c1050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no conditional branches. The saved-EFLAGS pair (__readeflags/__writeeflags) around the delta computation is a compiler idiom, not a check; the interlocked exchange and the tail-call to sub_5BCDA7(a3, a4) always execute.
