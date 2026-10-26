## NetworkSocketCreate_0057bee0 — InitAndCreateSocket

**Summary:** Calls vtable initializer method (at offset 0x74) on the object, then creates a TCP socket via socket(AF_INET=2, SOCK_STREAM=1, 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x74 | R | — | vtable method pointer (initializer callback at vtable+0x74) |
| this | 0x0 | R | — | vtable pointer (dispatched through for virtual call) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2dc | __imp_socket | R | Winsock socket() — create TCP socket |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
