# MAS live-list ownership audit

Date: 2026-08-06. Static cross-function audit of the global list rooted at `0x008B8F14`. This establishes recovered ownership paths, not thread safety or runtime completeness.

## Producers and consumers

`0x0053CBC0` is the only recovered allocator/registrar for this list. On its 410 parser-success path it appends the 308-byte object, maintains links at `+0x12C/+0x130`, and increments `0x008B6AC0`.

The direct root-loader call sites divide into three ownership patterns:

1. Fourteen resource-loading functions retain the returned archive object only while extracting dependent resources, then call `0x0053CE40` in the same function. These cover cockpit/dashboard, pit animation and instances, special effects, car/material setup, fonts, clouds, and related resource paths (`0x0049B0A0`, `0x0049CA00`, `0x0049CD80`, `0x004A3220`, `0x004A3910`, `0x004A4900`, `0x004CF070`, `0x004D0110`, `0x004D1450`, `0x004D8AB0`, `0x004DCBA0`, `0x004DDAD0`, `0x004F8D70`, and `0x004FC550`). Several functions load multiple archives and remove each returned object.
2. `0x00494FE0` is used by bitmap loader `0x004979F0`. On success the archive pointer is transferred into a small path-registry object at its `+0x8` field. Resource-manager shutdown `0x004963D0` walks the retained registry list and calls `0x00495010`, which delegates to promoted single-node removal `0x0053CE40`, then clears the stored pointer.
3. Scene loader wrapper `0x0053CE10` marks returned archives with bit 3. After resource/vertex-buffer setup, `0x00543FA0` invokes promoted bulk prune `0x0053CED0`, which removes precisely those marked archive objects.

The global initializer `0x0053C360` sets the head and count to zero. Other recovered references to `0x008B8F14` are archive lookup/read consumers, not additional writers.

## Ownership conclusion

The list is best modeled as a registry of live archive-reader objects, not physics objects and not a permanent content database. Ownership is either function-local until explicit single removal, transferred to the bitmap/path registry until resource-manager shutdown, or marked for phase-end bulk pruning after scene resource setup.

This closes the broad final-owner question for every statically recovered root-loader call site. It does not yet prove that every error branch performs the release, that list mutation is confined to one thread, or that shutdown always runs after all producers. Those remain implementation gates.

## Replacement invariants

- Register only a fully initialized archive object.
- Transfer ownership explicitly; never infer it only from presence in the global list.
- Single removal must be idempotent at the API boundary even though the recovered implementation returns zero for not-found nodes.
- Bulk prune may remove only objects carrying the phase mark and must preserve survivor links and count.
- Resource-manager shutdown must release and clear every retained bitmap/path-registry archive pointer before destroying registry nodes.
- The replacement must either serialize live-list mutation or establish thread confinement before implementation promotion.
