## UITextDialogRendering_00495bd0 — TextDialogRender

**Summary:** Renders a multi-option text dialog from 4 active-entry slots (each 12 bytes, starting at offset 0x15FC). Iterates slots, measures text dimensions via TextRenderToSurface, computes layout clamped to 800x600, draws background/shadow for the first entry, renders each entry's text, dispatches UI messages, and fills the final render surface. Part of the UI text dialog system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown render region — accessed indirectly via GlobalAccessor_5150 and DelegationWrapper |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Retrieve render device/surface accessor for final fill operation |
| 004918d0 | RenderSurfaceFillCopy | Fill the composed dialog area to the render surface |
| 00494bf0 | DelegationWrapper | Draw background rect and shadow for the dialog (first entry only) |
| 00494f10 | UIMessageDispatch | Dispatch UI message for each dialog entry (click target forwarding) |
| 00495150 | GlobalAccessor_5150 | Get global UI context handle (used by DelegationWrapper for drawing) |
| 004983b0 | TextRenderToSurface | Render entry text to an offscreen surface, returning width/height |
| 00498550 | ShortComputation_8550 | Prepare dialog state before layout computation |
| 00499a50 | FloatThresholdCheck | Check if a 12-byte entry slot is active (passes threshold) |
| 0049a2b0 | StringPointerDereference | Retrieve string pointer from a 12-byte entry slot |

**Guard conditions:** First loop: only entries that pass FloatThresholdCheck (active) are measured. If zero active entries (v15 == 0) → BLOCKED (return 0, skip all rendering). Second loop: renders only the v15 active entries in order.
