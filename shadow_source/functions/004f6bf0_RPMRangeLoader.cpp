// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6BF0
// Canonical corpus name: RPMRangeLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RPMRangeLoader_004f6bf0.c

void UnknownObject::RPMRangeLoader()
{
    // Parses the minimum, maximum and natural RPM key-value pairs for one gear index a3 (guarded to 0..4) and stores the results in the receiver's float array at this[3*a3+1], this[3*a3+2] and this[3*a3+3]. RPM values are scaled by the rad/s conversion constant (0.1047197551196598); natural RPM stores the reciprocal of the converted value and stores 0.0 when the parsed natural RPM is not positive. Iterates the configuration through ConditionalDispatchBasedOnFlag using sub_5651B0 to read each record; a status of exactly 2 terminates parsing early. Called by sub_4F7460.
    // GUARD: If the gear index a3 is greater than 4, skip the whole parse loop and return the initial result 0. [source:raw]
    // ASSIGNMENT: Zero-initialize the 384-byte buffer v12 and the local working values before parsing. [source:raw]
    // LOOP: Iterate while ConditionalDispatchBasedOnFlag(v12, 384) returns a non-zero continuation status, re-invoking it at the end of every pass. [callee:0x00566CC0, source:raw]
    // CALL: Call sub_5651B0(v6) to read the next configuration record; a non-zero return skips the parse block, and a status of exactly 2 returns immediately (end of data). [callee:0x005651B0, source:raw]
    // CALL: Parse the minimum-RPM key aMinimumrpm via sub_565870 into v5; when it returns true, write v5 scaled by the rad/s conversion constant into this[3*a3+1]. [callee:0x00565870, global:0x005D67EC, global:0x005AD258, source:raw]
    // CALL: Parse the maximum-RPM key aMaximumrpm via sub_565870 into v5; when it returns true, write v5 scaled by the rad/s conversion constant into this[3*a3+2]. [callee:0x00565870, global:0x005D67E0, global:0x005AD258, source:raw]
    // CALL: Parse the natural-RPM key aNaturalrpm via sub_565870 into v5; when it returns true, branch on whether the parsed value is positive. [callee:0x00565870, global:0x005D67D4, source:raw]
    // GUARD: When the parsed natural RPM v5 is greater than 0.0, store the reciprocal of the converted value (the constant 1.0 divided by v5 times the rad/s conversion constant) into this[3*a3+3]. [global:0x0059E420, global:0x005AD258, source:raw]
    // ASSIGNMENT: When the parsed natural RPM is not positive (0.0 threshold), store 0.0 into this[3*a3+3] instead. [global:0x0059E440, source:raw]
    // RETURN: Return the final parser status: the last loop continuation value, or 2 when the read status terminated the loop early. [function:0x004F6BF0, source:raw]
    // CALL: Invoked by sub_4F7460 (004f7460) to load the RPM range. [caller:0x004F7460, source:raw]

    // Conservative worker pseudocode:
    //   if (a3 > 4) return 0;
    //   for (result = ConditionalDispatchBasedOnFlag(v12, 384); result;
    //        result = ConditionalDispatchBasedOnFlag(v12, 384)) {
    //       status = sub_5651B0(v6);
    //       if (status == 2) return status;
    //       if (status != 0) continue;
    //       if (sub_565870(aMinimumrpm, &v5, 0, 0, 0, 0, 0, 0, 0))
    //           this[3*a3+1] = v5 * 0.1047197551196598;
    //       if (sub_565870(aMaximumrpm, &v5, 0, 0, 0, 0, 0, 0, 0))
    //           this[3*a3+2] = v5 * 0.1047197551196598;
    //       if (sub_565870(aNaturalrpm, &v5, 0, 0, 0, 0, 0, 0, 0))
    //           this[3*a3+3] = v5 > 0.0 ? 1.0 / (v5 * 0.1047197551196598) : 0.0;
    //   }
    //   return result;
    // UNRESOLVED: The read-only globals dbl_59E420, flt_59E440 and dbl_5AD258 are flagged as reads while the raw source renders the same values as inlined literals (1.0, 0.0 and 0.1047197551196598); their exact compiled constant mapping is not independently established by this packet.
    // UNRESOLVED: Parameter a2 is passed by the caller but never referenced in the function body.
}
