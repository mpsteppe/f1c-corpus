## NetworkSessionStart_0057f2b0 — start network session via vtable dispatch

**Summary:** Initiates a network session: queries sub-object (at this+0x940) via vtable, sets up session config buffer, allocates connection object via vtable+88, configures socket parameters, dispatches conditional call based on a2. Returns result of VTableDispatchWithConditionalCall.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x940) | 0x10 | R | — | Sub-object vtable entry at +16 (dispatched indirectly) |
| obj | 0x58 | R | — | Main vtable entry at +88 (get connection object) |
| this | 0x0 | R | — | Main vtable pointer (dispatched for connection alloc) |
| this | 0x940 | R | — | Sub-object pointer (config/session state) |
| this | 0x94C | R | — | Sub-object field at offset +12 (part of session config) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ca3b | SEH_57F2B0 | R | SEH handler registration for exception safety |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00585380 | VTableDispatchWithConditionalCall | Final dispatch: conditional vtable call based on session state |
| 00586800 | sub_586800 | Configure connection object socket parameters |
| 00586a00 | SingleFunctionCallWrapper_6a00 | Execute single function from session config |

**Guard conditions:**
- If a2 == -1 → set byte flag at v6[18]+4 to 1 (default/free mode)
- Else → call vtable method at v6[18]+12 with a2 (configure specific session)
