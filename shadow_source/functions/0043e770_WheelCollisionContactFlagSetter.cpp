// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E770
// Canonical corpus name: WheelCollisionContactFlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelCollisionContactFlagSetter_0043e770.c

void UnknownObject::WheelCollisionContactFlagSetter()
{
    // Sets collision contact flags for one wheel indexed by a2 (per-wheel stride 281 DWORDs). Always marks the wheel contact flag byte at this[281*a2+276] as 1. When the wheel contact state this[281*a2+251] is non-zero, marks the per-wheel second flag this[281*a2+291] and ORs flag bit 1 into every body-pair contact entry (this+0x15C4/0x15C8, 72-byte stride) whose body A id (entry+4) or body B id (entry+12) equals the contact state. When the wheel is not in contact, scans two wheel-body contact lists (counts/pointers this+0x15B4/0x15B8 and this+0x15BC/0x15C0, 48-byte stride) and ORs flag bit 1 into entry+44 for entries whose (body A, body B) pair matches the wheel contact body id this[281*a2+250] with the reference body id this[1287] at this+0x141C in either order.
    // ASSIGNMENT: Set the wheel-contact flag byte at this[281*a2+276] to 1, marking the indexed wheel as having contact [source:raw]
    // GUARD: Branch on the wheel contact state: when this[281*a2+251] (v2) is non-zero the body-pair contact path runs; when zero the no-contact wheel-body path runs [source:raw]
    // ASSIGNMENT: In the contact path, set the second per-wheel flag byte at this[281*a2+291] to 1 [source:raw]
    // LOOP: Body-pair scan: read the body-pair contact list count this[1393] (this+0x15C4) and pointer this[1394] (this+0x15C8); iterate its 72-byte entries while the count is positive [field:this:0x000015C4, field:this:0x000015C8, source:raw]
    // ASSIGNMENT: For each body-pair entry whose body A id (entry+4) or body B id (entry+12) equals the wheel contact state v2, OR flag bit 1 into the contact-flags field at entry+68 [source:raw]
    // GUARD: If the wheel-body contact list 1 count this[1389] (this+0x15B4) is greater than 0, iterate its entries [field:this:0x000015B4, guard:0, source:raw]
    // LOOP: Wheel-body list 1 scan: count this[1389] (this+0x15B4), data pointer this[1390] (this+0x15B8), 48-byte stride [field:this:0x000015B8, source:raw]
    // ASSIGNMENT: For each wheel-body entry where (body A id (entry+4) == v9 && body B id (entry+12) == the reference body id this[1287] at this+0x141C) OR (body B id == v9 && body A id == this[1287]), OR flag bit 1 into the wheel-contact flag field at entry+44 [field:this:0x0000141C, source:raw]
    // GUARD: If the wheel-body contact list 2 count this[1391] (this+0x15BC) is greater than 0, iterate its entries [field:this:0x000015BC, source:raw]
    // LOOP: Wheel-body list 2 scan: count this[1391] (this+0x15BC), data pointer this[1392] (this+0x15C0), 48-byte stride; same body-id matching test and the same flag OR into entry+44 as list 1 [field:this:0x000015C0, source:raw]
    // RETURN: Return result (the last loop-count value) [function:0x0043E770, source:raw]
    // CALL: Invoked by RepairServiceStateDispatcher (004ED250) [caller:0x004ED250]

    // Conservative worker pseudocode:
    //   wheel_contact = this[281*a2 + 251];
    //   this[281*a2 + 276] = 1;
    //   if (wheel_contact) {
    //     this[281*a2 + 291] = 1;
    //     for (i = 0; i < this[1393]; i++) {
    //       e = this[1394] + i*72;
    //       if (*(e+4) == wheel_contact || *(e+12) == wheel_contact) *(e+68) |= 1;
    //     }
    //   } else {
    //     wheel_body = this[281*a2 + 250];
    //     for (i = 0; i < this[1389]; i++) {
    //       e = this[1390] + i*48;
    //       if ((*(e+4) == wheel_body && *(e+12) == this[1287]) || (*(e+12) == wheel_body && *(e+4) == this[1287])) *(e+44) |= 1;
    //     }
    //     for (i = 0; i < this[1391]; i++) {
    //       e = this[1392] + i*48;
    //       if ((*(e+4) == wheel_body && *(e+12) == this[1287]) || (*(e+12) == wheel_body && *(e+4) == this[1287])) *(e+44) |= 1;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Entry-level offsets (+4 body A id, +12 body B id, +44 wheel-contact flag, +68 body-pair contact flag) are offsets inside heap-allocated contact records and have no field evidence refs
    // UNRESOLVED: The per-wheel computed offsets (281*a2+251, +250, +276, +291) have no field evidence refs; the 281-DWORD per-wheel stride comes from the raw source
    // UNRESOLVED: The deterministic guard this+0x15B4 > 0 is recorded as the wheel-body list 1 count check; the fill table instead labels this+0x15B4 as the wheel contact state, which conflicts with the raw source that reads the contact state from the computed per-wheel offset this[281*a2+251]
}
