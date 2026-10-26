## sub_4FBA10_004fba10 — Cloud / Skybox Scene Graph Initializer

**Summary:** Initializes cloud and skybox rendering state: resolves scene graph nodes for skybox and three cloud layers (normal, snowy, rainy), builds arrays of cloud node handles from the audio network graph, computes cloud opacity and noise-driven animation speeds, and calculates bounding boxes. Called during weather setup from sub_4FCAA0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | skybox scene graph node handle (from EvaluateSceneNodeProperty on "SkyboxI") |
| this | 0x20 | R | — | snowy cloud scene node handle (aCloudsny), read for initial cloud array seed |
| this | 0x30 | R | — | rainy cloud scene node handle (aCloudrny), read for initial rain array seed |
| this | 0x40 | RW | — | sentinel float (initialized to NaN) |
| this | 0x48 | RW | 1 | cloud node count (int, incremented as cloud nodes are found in audio network) |
| this | 0x4C | RW | — | pointer to allocated cloud node handle array (malloc'd, size = count*4) |
| this | 0x70 | RW | — | cloud layer opacity (float, from sub_548890 via scene node query, or 0) |
| this | 0x74 | RW | — | cloud animation speed X (noise-driven: (rand*0.5 + 0.5) * flt_7CF914) |
| this | 0x78 | RW | — | cloud animation speed Y (noise-driven) |
| this | 0x7C | RW | 1 | rainy cloud node count (int, incremented as rainy nodes found) |
| this | 0x80 | RW | — | pointer to allocated rainy cloud node handle array |
| this | 0xA4 | RW | — | rain cloud layer opacity (from sub_548890, or 0) |
| this | 0xA8 | RW | — | rain cloud animation speed X (noise-driven) |
| this | 0xAC | RW | — | rain cloud animation speed Y (noise-driven) |
| this | 0xB0 | RW | — | bounding box minimum corner (X from BoundingBoxComputation) |
| this | 0xB4 | RW | — | bounding box maximum corner (Y from BoundingBoxComputation) |
| this | 0xB8 | RW | — | sentinel value -1.0f (end-of-data marker) |

**Written-by note (persistence):**
- this 0x0: set once at init — external poke does NOT survive re-init
- this 0x40: set once at init — external poke does NOT survive re-init
- this 0x48: set once at init — external poke does NOT survive re-init
- this 0x4C: set once at init — external poke does NOT survive re-init
- this 0x70: set once at init — external poke does NOT survive re-init
- this 0x74: set once at init — external poke does NOT survive re-init
- this 0x78: set once at init — external poke does NOT survive re-init
- this 0x7C: set once at init — external poke does NOT survive re-init
- this 0x80: set once at init — external poke does NOT survive re-init
- this 0xA4: set once at init — external poke does NOT survive re-init
- this 0xA8: set once at init — external poke does NOT survive re-init
- this 0xAC: set once at init — external poke does NOT survive re-init
- this 0xB0: set once at init — external poke does NOT survive re-init
- this 0xB4: set once at init — external poke does NOT survive re-init
- this 0xB8: set once at init — external poke does NOT survive re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005d6f08 | aClouds | R | aClouds [DERIVED] |
| 005d6f10 | aCloudrny | R | aCloudRainy [DERIVED] |
| 005d6f1c | aCloudsny | R | String_CloudsNy [DERIVED] |
| 005d6f28 | aSkyboxi | R | SkyboxString [DERIVED] |
| 007cf914 | flt_7CF914 | R | Float7CF914 [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | computes axis-aligned bounding box (min, max) for skybox scene node |
| 005452f0 | AudioNetworkNodeCount | returns count of nodes in audio/collision geometry network |
| 00545340 | LinkedListNodeFinder | looks up a node from linked list by index, returns float handle value |
| 005453a0 | EvaluateSceneNodeProperty | resolves a named scene graph node property, returns node handle |
| 00545f40 | ValueGetter | queries a value from the collision geometry handle (checks if scene node exists) |
| 00548890 | sub_548890 | retrieves scene node float property value by name (cloud opacity) |
| 0054b420 | TripleFieldQuery | reads three consecutive float fields (x,y,z) from scene node |
| 0054bda0 | SelfRelativeStringCopy | copies a self-relative string from scene node data into buffer |
| 0054bdc0 | UIElementBitfieldStateSetter | sets UI element bitfield state (0,0,0 — likely reset/clear) |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation for cloud node arrays |
| 00588640 | sub_588640 | string comparison with length limit (checks if node name matches cloud type) |

**Guard conditions:** If skybox node handle == 0 after EvaluateSceneNodeProperty, skips TripleFieldQuery and UI reset. Each cloud layer node handle is checked: if 0, skips its field queries. Cloud nodes from AudioNetworkNodeCount loop are filtered by name: names matching aCloudsny are routed to rain array unless also matching aCloudrny; non-snow names go to cloud array. At end, if skybox handle is valid, calls BoundingBoxComputation to populate min/max; otherwise bounding box stays at ±FLT_MAX.