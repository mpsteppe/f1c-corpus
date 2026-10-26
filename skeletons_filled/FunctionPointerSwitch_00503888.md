## FunctionPointerSwitch_00503888 — Render path function pointer selector

**Summary:** Selects between compositing function pointers based on sub_50FC7D() condition: on true, sets both slots to sub_503772; on false, sets to ImageBlendingCompositing and F_2DImageBoxFilter. Then calls the selected function via off_5D76C0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00503533 | ImageBlendingCompositing | R | fallback image compositing function when condition false |
| 0050368a | F_2DImageBoxFilter | R | fallback 2D image box filter function when condition false |
| 00503772 | sub_503772 | R | alternative function pointer used when condition true |
| 005d76c0 | off_5D76C0 | RW | PTR_FUN_SteerTable [DERIVED] — primary function pointer to execute |
| 005d76c4 | off_5D76C4 | W | CollisionDispatchFn [DERIVED] — secondary function pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fc7d | sub_50FC7D | condition check that determines which function pointers to install |

**Guard conditions:** If sub_50FC7D() returns nonzero → both function pointers set to sub_503772. If zero → ImageBlendingCompositing and F_2DImageBoxFilter.
