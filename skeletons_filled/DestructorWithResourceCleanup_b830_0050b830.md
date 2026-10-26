## DestructorWithResourceCleanup_b830_0050b830 — Video Decoder Destructor

**Summary:** Destructor for a video decoder object. Sets vtable, calls VertexColorPackRGBto16 (color-space cleanup), frees a heap-allocated resource at offset 0x105C, then calls VtableSetFreeChild to release child objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c59e | loc_59C59E | R | Code label (used as address reference in SEH or jump table) |
| 005adbb8 | off_5ADBB8 | R | VTable_VideoDecoder [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ccc | VtableSetFreeChild | Frees child objects attached to this object's vtable chain |
| 0050a92d | VertexColorPackRGBto16 | Color-space cleanup or palette conversion during teardown |
| 00587bcf | FreeWrapper_7bcf | Heap deallocation wrapper for resource at offset 0x105C |
| 0058a5d8 | SEHHandlerInit | Structured exception handler registration for this frame |

**Guard conditions:** 
- if v2[1051] (resource pointer at offset 0x105C) is non-NULL: free it via FreeWrapper_7bcf. Otherwise skip free.
