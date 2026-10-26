## VirtualMethodDispatch_0057a690 — VTableCallMethodAtOffset0x64

**Summary:** Calls virtual method at vtable offset 0x64 on a COM-like object. Passes `*this` as the `this` pointer to the callee.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionUIElementRenderer (0045f2b0), ServerOpenTrackSignal (00460e90), ServerCloseTrackSignal (00461020), TextureCreationWrapper (00462250), CollisionEventNetworkBroadcast (00462940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x64 | R | — | vtable function pointer at index 25 (0x64/4) |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, no branch logic

