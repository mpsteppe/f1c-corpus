## __purecall_006316b0 — _purecall (pure virtual call handler)

**Summary:** CRT handler invoked when a pure virtual function is called: if a user-installed handler exists (dword_FB8180) it is run first, then the process is terminated via _amsg_exit(0x19) — the R6025 "pure virtual function call" fatal runtime error.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb8180 | dword_FB8180 | R | User-installed pure-virtual-call handler pointer (set via _set_purecall_handler); called before termination when nonzero |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006346fb | __amsg_exit | CRT fatal error reporter — emits runtime error 0x19 and terminates the process |

**Guard conditions:** Checks dword_FB8180: nonzero → the user handler dword_FB8180() is invoked first (callback path taken); zero → it is skipped. Either way control falls into _amsg_exit(0x19), which does not return (function is __noreturn).
