## SceneNodeStateUpdateWithTransform_005569f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationDispatchWithSkipFlag (00556980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | [LLM] |
| 0054d7a0 | CollisionContactStateDetection | [LLM] |
| 0054d9f0 | MeshBoundingBoxComputation | [LLM] |
| 00551760 | LinkedListTraversalWithConditionalTimerUpdate | [LLM] |
| 00556d60 | sub_556D60 | [LLM] |
| 0055d5c0 | sub_55D5C0 | [LLM] |
| 0055ed10 | sub_55ED10 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
