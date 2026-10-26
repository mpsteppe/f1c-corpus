## CollisionEventNetworkBroadcast_00462940 — Collision Event Network Broadcast

**Summary:** Broadcasts a collision event over network. Checks object state (1 or 2), encodes progress bar event for collision, prepares COM object via vtable dispatch, sends data via NetworkSendDispatch, and cleans up. Returns true if send succeeded, false if state invalid or send failed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_13e0 (004613e0), DeferredTextureObjectLoader (0046e1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM object pointer used for vtable dispatch and cleanup |
| obj | 0x3FC4 | R | — | object state/type; must be 1 or 2 to proceed |
| this | 0x0 | R | — | vtable pointer of containing object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | encodes progress bar event for collision (type 4, subtype 32, channel 4) |
| 0057a680 | COMVTableCallVia0x60 | calls COM method at vtable offset 0x60 on collision object |
| 0057a690 | VirtualMethodDispatch | dispatches virtual method on COM object after send |
| 0057a6a0 | NetworkSendDispatch | sends collision event data over network |

**Guard conditions:** Reads state at offset +0x3FC4 from this object. If value is NOT 1 or NOT 2, BLOCKED — returns false immediately. PASSES only when state is exactly 1 or 2, proceeds to encode, send, and cleanup.
