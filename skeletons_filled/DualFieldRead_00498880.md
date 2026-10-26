## DualFieldRead_00498880 — Dual Dimension Field Read Accessor

**Summary:** Reads two adjacent integer fields at offsets 0x5C and 0x60 (the computed width and height dimensions initialized by InitViewportDimensions_00498740) and returns them via output parameters. Also returns the second value as the function result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_466350 (00466350), sub_466650 (00466650), UIClickHandlerWithBoundsCheck (0046b070), UIMouseClickHandler (0046c8b0), BoundsCheckWithPositionQuery (004773a0), HitTest (00479320), UIComponentScrollUpdate (0047b1e0), MultiStageVTableDispatch (00487e70), DeltaBasedUpdate (00488900), UIScrollWidgetUpdate (00488a30), UIScrollbarThumbDragHandler (0048a650), UIScrollListUpdate (0048a8d0), sub_48D0D0 (0048d0d0), UIScrollAreaAutoScrollManager (0048d850), MediaBufferPlaybackManager (0048d9d0), UIWidgetDragHandler (0048df40), sub_48F1A0 (0048f1a0), UITileGrid (0048f870), sub_4900A0 (004900a0), UIWidgetProcessChildren (00490450), PanelMouseInteractionHandler (00490550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Computed width dimension (from InitViewportDimensions) |
| this | 0x60 | R | — | Computed height dimension (from InitViewportDimensions) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** (none — always reads unconditionally)
