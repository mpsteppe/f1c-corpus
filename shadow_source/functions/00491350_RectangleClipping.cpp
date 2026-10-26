// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491350
// Canonical corpus name: RectangleClipping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RectangleClipping_00491350.c

void UnknownObject::RectangleClipping()
{
    // Subtractive rectangle clipping. Computes the area of a subject rectangle (this[0]..this[3], a 16-bit x1/y1 plus extents) that lies outside a boundary rectangle (a2..a5). Splits the space into a 3 by 3 grid, allocates a resource-pool node per surviving cell, links the nodes into a singly linked list via the next-pointer at node offset 12, and returns the list head (0 when the subject is entirely inside the boundary).
    // CALCULATION: Read subject rectangle x1 (this+0) and y1 (this+2) and compute right = x1 + extent (this+4) and bottom = y1 + extent (this+6). [field:this:0x00000000, field:this:0x00000002, field:this:0x00000004, field:this:0x00000006]
    // ASSIGNMENT: Build boundary coordinate arrays from a2..a5: columns v45 = (a2, right-derived, a2+a4) and rows v47 = (a3, bottom-derived, a3+a5). [source:raw]
    // LOOP: Bubble-sort the 3 column coordinates (v45) and 3 row coordinates (v47) by running 3 passes of a 3-element compare-swap loop. [source:raw]
    // LOOP: Build the 3 by 3 cell-mask grid v43: for each cell, record whether it lies within the subject rectangle or outside the boundary rectangle (inside-subject OR not-inside-boundary test). [source:raw]
    // GUARD: For each not-yet-marked cell, test whether the cell spans positive width and height (column delta and row delta greater than 0); zero-size cells are marked as handled. [source:raw]
    // LOOP: For each surviving cell, mark it and the cells it covers as handled, then allocate a clipped-rectangle output node via ResourcePoolNodeAllocDealloc(x, y, width, height). [callee:0x00490940, source:raw]
    // ASSIGNMENT: Copy the subject metadata word from this+8 into the allocated node at node offset 8. [field:this:0x00000008]
    // ASSIGNMENT: Append the new node to the singly linked list using the next-pointer at node offset 12, or start the list with it when the list head is empty. [source:raw]
    // RETURN: Return the linked-list head of allocated clipped rectangles (0 when no cell passed the tests). [source:raw]

    // Conservative worker pseudocode:
    //   RectangleClipping(this, a2, a3, a4, a5) {
    //     x1 = this[0]; y1 = this[1];
    //     right = x1 + this[2]; bottom = y1 + this[3];
    //     cols = sort(a2, right, a2 + a4); rows = sort(a3, bottom, a3 + a5);
    //     grid = mark_cells(subject, boundary, cols, rows);
    //     head = 0;
    //     for each live cell c:
    //       if cell size > 0:
    //         node = ResourcePoolNodeAllocDealloc(c.x, c.y, c.w, c.h);
    //         node[8] = this[4]; append(node, &head);
    //     return head;
    //   }
    // UNRESOLVED: Whether this+4/this+6 are extents or absolute right/bottom coordinates is ambiguous from source:raw.
    // UNRESOLVED: Meaning of the metadata word copied from this+8 into each output node is unknown.
    // UNRESOLVED: Exact node layout beyond the next-pointer at offset 12 and metadata at offset 8 is unknown.
    // UNRESOLVED: Callers are sub_490D00, CollisionBroadphaseBuilder, CollisionBroadphaseTraversal; on_frame_path=false.
}
