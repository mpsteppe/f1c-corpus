## NetworkSendDispatch_0057a6a0 — NetworkSendDispatch

**Summary:** Dispatches network data send. Gets sender object via vtable offset 0x58; returns 10 if null. If payload (a4) present, calls sub-object vtable method at offset 0x20 to set data; else sets flag byte. Calls sub_586800 and SingleFunctionCallWrapper_6a00 unconditionally. Final conditional dispatch via VTableDispatchWithConditionalCall or sub_585270 based on a8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionUIElementRenderer (0045f2b0), ServerOpenTrackSignal (00460e90), ServerCloseTrackSignal (00461020), TextureCreationWrapper (00462250), CollisionEventNetworkBroadcast (00462940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x58 | R | — | vtable function pointer at index 22 (0x58/4) — gets network sender object |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00585270 | sub_585270 | network send/callback path when a8 is false |
| 00585380 | VTableDispatchWithConditionalCall | conditional network dispatch path when a8 is true |
| 00586800 | sub_586800 | network data send with data payload (a5, a6, a7) |
| 00586a00 | SingleFunctionCallWrapper_6a00 | process a2/a3 parameters |

**Guard conditions:** v8 (result of vtable method at offset 0x58) must be non-null. If null → return 10 (BLOCKED). If non-null (PASSES): continues to data dispatch.

