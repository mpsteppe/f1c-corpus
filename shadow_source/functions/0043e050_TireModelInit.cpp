// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043E050
// Canonical corpus name: TireModelInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireModelInit_0043e050.c

void UnknownObject::TireModelInit()
{
    // Initializes the per-vehicle tire physics model. Stores the context handle a2 at this+0x1F00, saves and restores the FPU control word (512 mask), clears this+0x60/0x64, derives step and traction constants from 400 >> dword_7CE958 into this+0x68 and the globals dbl_5E5238/dbl_5E5240, parses the vehicle HDV file twice via TheSvmHdvVehicleFileParser, then runs the body-name mapping, vehicle-physics initialization, sub_43C250, brake-bias setup and a final sub_438F00 call with the vehicle entry's string and float fields. Ends by restoring the FPU control word if it changed, freeing all temporary allocations and returning the leftover pointer.
    // ASSIGNMENT: Store the context handle argument a2 at this+0x1F00 (offset 7936). [field:this:0x00001F00, source:raw]
    // CALL: Call FPUControlWordMaskExtract(512) to capture the original FPU control word into v3. [callee:0x00567740, source:raw]
    // ASSIGNMENT: Clear this+0x60 and this+0x64 to 0. [field:this:0x00000060, field:this:0x00000064, source:raw]
    // CALCULATION: Compute this+0x68 (double) = 1.0 / (double)(400 >> dword_7CE958), where dword_7CE958 is the tire-model mode shift. [field:this:0x00000068, global:0x007CE958, source:raw]
    // CALCULATION: Compute the traction scale v4 = (double)(400 >> dword_7CE958) * 0.8 and store the global traction constants dbl_5E5238 = v4 * v4 and dbl_5E5240 = v4 + v4. [global:0x007CE958, global:0x005E5238, global:0x005E5240, source:raw]
    // CALL: Initialize the session struct buffer v18 via SessionStructInit and the tire model data buffer v12 via TireModelDataInit. [callee:0x0042E320, callee:0x004F34E0, source:raw]
    // CALCULATION: Resolve the vehicle HDV file entry: v5 = 1060 * *(_DWORD *)(a2 + 18584); file path pointer v6 = *(char **)(v5 + dword_8AC394 + 8), falling back to byte_5EA438 when null; entry base v7 = dword_8AC394 + v5. [global:0x008AC394, global:0x005EA438, source:raw]
    // CALL: Parse the vehicle file twice: TheSvmHdvVehicleFileParser(v6, v18, 0) with the resolved path, then TheSvmHdvVehicleFileParser(a2 + 18324, v18, 1) with the inline setup offset. [callee:0x004F4270, source:raw]
    // CALL: Call VehiclePhysicsBodyNameMapping(this, v8) where v8 is v17 or byte_5EA438 when the local allocation pointer is null. [callee:0x00438DA0, global:0x005EA438, source:raw]
    // CALL: Call VehiclePhysicsInitializer(this, (int)v18, (int)v12) with the session and tire-data buffers. [callee:0x00439210, source:raw]
    // CALL: Call sub_43C250(this, v11) where the 64-bit v11 packs the two buffer pointers (LOWORD v18, HIWORD v12). [callee:0x0043C250, source:raw]
    // CALL: Call BrakeBiasSetup(this). [callee:0x00438CC0, source:raw]
    // CALL: Call sub_438F00(this, v9, (float *)(v7 + 56)) where v9 is the string pointer at *(char **)(v7 + 16) or byte_5EA438 when null, passing the entry's float block at v7 + 56. [callee:0x00438F00, global:0x005EA438, source:raw]
    // GUARD: Restore the FPU control word when it changed: if v3 != 512 call EmptyStub_7780(v3). [callee:0x00567780, source:raw]
    // LOOP: Free the temporary heap allocations returned by the initializers: FreeWrapper_7bcf each of v17, v16, v15, v14, v13 and v12[0] when non-null. [callee:0x00587BCF, source:raw]
    // CALL: Call ScoreSlotDeallocator(v20) on the 235-dword stack score-slot buffer. [callee:0x0042DDD0, source:raw]
    // CALL: Compiler-inserted __alloca_probe for the large stack frame of locals. [callee:0x005881C0, source:raw]
    // RETURN: Return the leftover allocation pointer v19; when non-null, free it via FreeWrapper_7bcf and return its result. [callee:0x00587BCF, function:0x0043E050, source:raw]

    // Conservative worker pseudocode:
    //   void* TireModelInit(this, int a2) {
    //     this.field_1F00 = a2;
    //     int fpu = FPUControlWordMaskExtract(512);
    //     this.field_60 = 0; this.field_64 = 0;
    //     this.field_68 = 1.0 / (400 >> dword_7CE958);
    //     double v4 = (400 >> dword_7CE958) * 0.8;
    //     dbl_5E5238 = v4 * v4; dbl_5E5240 = v4 + v4;
    //     SessionStructInit(session); TireModelDataInit(tireData);
    //     int v5 = 1060 * *(int*)(a2 + 18584);
    //     char* hdv = *(char**)(v5 + dword_8AC394 + 8);
    //     if (!hdv) hdv = byte_5EA438;
    //     int v7 = dword_8AC394 + v5;
    //     TheSvmHdvVehicleFileParser(hdv, session, 0);
    //     TheSvmHdvVehicleFileParser(a2 + 18324, session, 1);
    //     VehiclePhysicsBodyNameMapping(this, v17 ? v17 : byte_5EA438);
    //     VehiclePhysicsInitializer(this, session, tireData);
    //     sub_43C250(this, pack64(session, tireData));
    //     BrakeBiasSetup(this);
    //     char* v9 = *(char**)(v7 + 16);
    //     if (!v9) v9 = byte_5EA438;
    //     sub_438F00(this, v9, (float*)(v7 + 56));
    //     if (fpu != 512) EmptyStub_7780(fpu);
    //     FreeEach(v17, v16, v15, v14, v13, v12[0]);
    //     ScoreSlotDeallocator(scoreBuf);
    //     if (v19) return FreeWrapper_7bcf(v19);
    //     return v19;
    //   }
    // UNRESOLVED: The purpose of the global traction constants dbl_5E5238/dbl_5E5240 (written from v4 = (400 >> mode) * 0.8) is inferred; their consumers are outside this packet.
    // UNRESOLVED: The '400 >> dword_7CE958' expression implies dword_7CE958 is a small mode index; the mapping of mode to a value is not established.
    // UNRESOLVED: sub_43C250 and sub_438F00 are referenced by address only; the packed v11 argument to sub_43C250 and the (v7 + 56) float block to sub_438F00 are structurally inferred.
    // UNRESOLVED: global:0x0059E420 and global:0x0059EC70 appear in the packet global table but not in the raw source text.
}
