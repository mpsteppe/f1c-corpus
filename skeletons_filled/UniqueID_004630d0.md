## UniqueID_004630d0 — Unique Identifier Validation via VTable Query

**Summary:** Validates a unique identifier: queries sub-object via vtable, checks COM result, copies 128-byte ID into output buffer, verifies copy consumed expected size. Returns true if copy size matches 128, false otherwise. Releases sub-object via vtable on exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClientGridDisplayTimer (00460380), WeatherSurfaceUpdate (004628a0), AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | sub-object pointer for vtable dispatch |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a230 | ByteAlignedMemoryCopyFromStruct | copies 128-byte ID from queried object to output buffer |
| 0057a880 | VTableQueryWithStackBufferResult | queries sub-object via vtable with stack buffer for result |
| 0057a8b0 | VTableCallViaOffset0x7c | releases/cleanup on sub-object after query |
| 0057a8e0 | COMVTableCallVia0xc4 | COM interface check on queried object; non-zero = invalid |

**Guard conditions:** COMVTableCallVia0xc4 returns non-zero (COM interface invalid): BLOCKED, returns false without copying ID. PASSES when COM check returns 0 — copies 128-byte ID, returns true if copied size matches 128.
