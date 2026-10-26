# Cross-Validation Results — Worker F/G (Functions 2035–2106)

## FUN_005423C0 — PASS
Doc: Two-Field Setter + Call. Sets param_1+4=param_2, param_1+8=param_3. Calls FUN_00542050 with +0x6c/+0x70.
Source: *(param_1+4)=param_2; *(param_1+8)=param_3; FUN_00542050(*(param_1+0x6c),*(param_1+0x70),1); ✓

## FUN_00599904 — PASS
Doc: Delegation with Fixed Args. Calls FUN_00599b86(0,1).
Source: FUN_00599b86(0,1); ✓

## FUN_004058D0 — PASS
Doc: Destructor with VTable and Free. Sets vtable *param_1=&PTR_FUN_0059e4b4. Frees param_1[1] if non-null via FUN_00587bcf. If (param_2&1)!=0 frees self.
Source: *param_1=&PTR_FUN_0059e4b4; if param_1[1]!=0: FUN_00587bcf(param_1[1]); if (param_2&1): FUN_00587bcf(param_1); ✓

## FUN_00462460 — PASS
Doc: Driver Data Copy by ID. Iterates *(param_1+0x3e14) entries stride 0x8c. Byte at +0x410 compared to ID. Copies 0x23 dwords from +0x394 on match. Aux at +0x3c74.
Source: iVar3=*param_1; loop: if *(iVar3+0x410+iVar5)==param_2: copy 0x23 dwords from iVar3+0x394+iVar5; *param_4=*(iVar3+0x3c74+iVar6); iVar5+=0x8c; ✓

## FUN_00487ED0 — PASS
Doc: Init with VTable + Flags. FUN_00485e30(). *(param_1+0x38)=param_2, *param_1=&PTR_FUN_005abac8, *(param_1+0xe1)=param_3, param_1[0x21]=0.
Source: FUN_00485e30(); *(undefined1*)(param_1+0x38)=param_2; *param_1=&PTR_FUN_005abac8; *(undefined1*)((int)param_1+0xe1)=param_3; param_1[0x21]=0; ✓

## FUN_004A0FB0 — PASS
Doc: Global Zero-Init. Zeros DAT_007ce250, DAT_007ce258, DAT_007ce260, DAT_007ce269, DAT_007ce26c.
Source: Each set to 0. ✓

## FUN_004CF010 — PASS
Doc: Array Search by ID. Iterates *(param_1+0x10) entries stride 0x6c starting at *(param_1+0x14). Compares entry+4 with param_2. On match: FUN_004cb5e0().
Source: if 0<*(param_1+0x10): iVar2=*(param_1+0x14); while *(iVar2+4)!=param_2: iVar2+=0x6c; FUN_004cb5e0(); ✓

## FUN_0050D563 — PASS
Doc: Dispatch with VTable Call. Calls FUN_0050fea7(1), then dispatches through PTR_FUN_005d7840.
Source: FUN_0050fea7(1); (*(code*)PTR_FUN_005d7840)(param_1,param_2); ✓

## FUN_005470A0 — PASS
Doc: Guarded Render State Set. If param_2<*(param_1+0xa4)<8: calls FUN_0054fc40, 0054fc80, 0054fd30, 0054fca0.
Source: if (param_2<*(param_1+0xa4) && *(param_1+0xa4)<8): FUN_0054fc40(0x8000000); FUN_0054fc80(0,0); FUN_0054fd30(...); FUN_0054fcao(4); ✓

## FUN_0059BF19 — PASS
Doc: String Copy Constructor. *param_1=&PTR_FUN_005b9dc0. _strlen(*param_2)+1 via operator_new. Copies via FUN_0058fca0. Refcount param_1[2]=1.
Source: *param_1=&PTR_FUN_005b9dc0; sVar1=_strlen(*param_2); operator_new(sVar1+1); param_1[1]=pvVar2; if(pvVar2) FUN_0058fca0(pvVar2,*param_2); param_1[2]=1; ✓

## FUN_00408250 — PASS
Doc: Short Computation. Delegates to FUN_0040bde0.
Source: FUN_0040bde0(); ✓

## FUN_00466270 — PASS
Doc: Short Computation (Flag Set). FUN_004988a0(3), sets param_1+0xf5=1, returns 0.
Source: FUN_004988a0(3); *(param_1+0xf5)=1; return 0; ✓

## FUN_0048D360 — PASS
Doc: Guarded Accessor. If +0x328<1 return -1. Return +0x338.
Source: if (*(param_1+0x328)<1) return 0xffffffff; return *(param_1+0x338); ✓

## FUN_004B1A70 — PASS
Doc: Short Constructor. param_1[1]=0, [2]=-1, [3]=0, [4]=-1. *param_1=&PTR_LAB_005acc68.
Source: param_1[1]=0; param_1[2]=0xffffffff; param_1[3]=0; param_1[4]=0xffffffff; *param_1=&PTR_LAB_005acc68; ✓

## FUN_004D91E0 — PASS
Doc: ID-to-Value Mapper. Switch 0-0x18: 0→100, 1/3-6/9-0x18→50, 2/0xd→49, 7/8/0x13→51, 0x11→52.
Source: case 0→100; case 1,3,4,5,6,9,10,0xb,0xc,0xe,0xf,0x10,0x12,0x14,0x15,0x16,0x17,0x18→0x32; case 2,0xd→0x31; case 7,8,0x13→0x33; case 0x11→0x34; ✓

## FUN_005158E3 — PASS
Doc: Init+Process Wrapper. FUN_00513e2d() init. If ok: FUN_00515417(param_1,buf). Return 0/-1.
Source: iVar1=FUN_00513e2d(); if (-1<iVar1) { iVar1=FUN_00515417(param_1,local_104); if (-1<iVar1) iVar1=0; } return iVar1; ✓

## FUN_005528B0 — PASS
Doc: Conditional Free by Flag. If +0x24 & 0x20000: FUN_00540eb0(+0xc), free +0xc via FUN_00587bcf, zero +0xc.
Source: if (*(param_1+0x24)&0x20000): FUN_00540eb0(*(param_1+0xc)); if (*(param_1+0xc)) FUN_00587bcf(*(param_1+0xc)); *(param_1+0xc)=0; ✓

## FUN_00583210 — PASS
Doc: Linked List Node Alloc & Prepend. 12-byte node [data,next,flag]. If head empty: set head=tail=cursor=new. Else prepend. Count at +0x0c.
Source: operator_new(0xc); *piVar3=param_2; piVar3[1]=0/head; *(piVar3+2)=param_3; if *param_1==0: param_1[1]=param_1[2]=*param_1=piVar3; else piVar3[1]=*param_1; *param_1=piVar3; param_1[3]++; ✓

## FUN_004560A0 — PASS
Doc: Dual Field Getter. Reads +0x4c/+0x50 to output pointers.
Source: if param_2: *param_2=*(param_1+0x4c); if param_3: *param_3=*(param_1+0x50); ✓

## FUN_0048B950 — PASS
Doc: String Cursor Reset. +0x2f0 StringBase, +0x2f4 Cursor, +0x1e7 FormatBuf. Calls vtable+0x2c, FUN_0048b810.
Source: param_1[0xbc](+0x2f0)=StringBase; param_1[0xbd](+0x2f4)=Cursor; if param_2==0: strlen -> cursor at end, vtable+0x2c; else: cursor=base, zero-terminate, FUN_0048b810; ✓

## FUN_004A40C0 — PASS
Doc: Callback Registration. FUN_00587b3e(&DAT_004a40d0).
Source: FUN_00587b3e(&DAT_004a40d0); ✓

## FUN_004D7F20 — PASS
Doc: Centered Position. Compute centered=param_2-width/2. Calls FUN_004d7fa0, FUN_005531f0.
Source: iVar1=FUN_004d7fa0(param_4); if(iVar1) FUN_005531f0(...); *param_3=param_2-param_4/2; ✓

## FUN_00513A56 — PASS
Doc: Flag Setter + Float Store. If params non-null: set bit 0 at param_2+8, store (float)param_3 at param_2+0x28.
Source: if (param_1&&param_2): *(param_2+8)|=1; *(param_2+0x28)=(float)param_3; ✓

## FUN_0054FC10 — PASS
Doc: Self-Relative Copy + Normalize. Copy string to self-relative offset. FUN_00589901.
Source: Copies via self-relative offset (param_1-param_2). FUN_00589901(param_1); ✓

## FUN_0058C38E — PASS
Doc: Handle Close with Error Reporting. FUN_00595a1f lookup, CloseHandle, GetLastError, FUN_005959a0 release slot. DAT_008d4920 table.
Source: iVar1=FUN_00595a1f(param_1); if iVar1!=-1: CloseHandle(hObject); GetLastError; FUN_005959a0; *(DAT_008d4920+...)=0; FUN_0058af5c(DVar4); ✓

## FUN_0047F3D0 — FAIL
**Error tags: [WRONG_BEHAVIOR] [WRONG_STRUCT_OFFSETS]**
Doc claims: "Simple Getter — Returns a value from struct at offset +0x10. Returns *(int*)(param_1+0x10)."
Source shows: Destructor pattern. FUN_0047f3f0() cleanup called. If (param_2&1)!=0: frees param_1 via FUN_00587bcf. Returns param_1 pointer. Completely different function — no offset +0x10 access at all.

**Corrected entry:**
## FUN_0047F3D0 — Destructor with Conditional Free

Source: unknown | Confidence: high
Destructor that calls sub-cleanup and optionally frees self.

**Key logic:**
- Calls FUN_0047f3f0() — sub-cleanup/destructor
- If (param_2 & 1) != 0: frees self via FUN_00587bcf
- Returns param_1

**Calls:** FUN_0047f3f0, FUN_00587bcf (conditional)

**Used by system:** docs/20-math-utilities.md — object destructor

**Moddability:** hardcoded

## FUN_004D7F60 — PASS
Doc: Size Computation with Subtraction. FUN_004d7fa0, FUN_005531f0, sets *param_3=param_2-param_4.
Source: iVar1=FUN_004d7fa0(param_4); if iVar1: FUN_005531f0(...); *param_3=param_2-param_4; ✓

## FUN_005597C0 — PASS
Doc: Binary Tree Search (2-byte key). Starts at param_1+4. 2-byte key compare. Walk via +0x1c.
Source: pbVar2=*(byte**)(param_1+4); do { compare bytes in pairs; return if match; pbVar2=*(byte**)(pbVar2+0x1c); } ✓

## FUN_0059BFC3 — PASS
Doc: __CxxThrowException_8. Copies SEH params from DAT_005b9de0, calls RaiseException.
Source: Copies 8 DWORDs from DAT_005b9de0 to local; RaiseException(local_24[0],...); ✓

## FUN_0051C6BE — PASS
Doc: 2D Copy Delegation. Calls FUN_0051593f() with parameters from param_1+0x5c.
Source: FUN_0051593f(*param_2, param_3, param_4, 0, param_5, *(param_1+0x5c)); ✓

## FUN_00404F00 — PASS
Doc: Byte Field Extractor with Shift. Reads *param_1 as base pointer, extracts byte at +0x14, merges via CONCAT31.
Source: CONCAT31((int3)((uint)*param_1>>8), *(undefined1*)(*param_1+0x14)); ✓

## FUN_0046A220 — PASS
Doc: Object Constructor with VTable. FUN_0048c9f0(); param_1[0xd2]=0; [0xd3]=-1; [0xd1]=0; *param_1=&PTR_LAB_0059f878.
Source: FUN_0048c9f0(); param_1[0xd2]=0; param_1[0xd3]=0xffffffff; param_1[0xd1]=0; *param_1=&PTR_LAB_0059f878; ✓

## FUN_0048EA20 — PASS
Doc: Two-Field Setter. Sets *(param_1+0x14)=param_2; *(param_1+0x18)=param_3.
Source: *(param_1+0x14)=param_2; *(param_1+0x18)=param_3; ✓

## FUN_004B28F0 — PASS
Doc: Scaled Byte/Short Read. *p3=(float)*(char)(p2+0x12+p1)*_DAT_005ac988; *p4=(float)*(short)(p1+0x16+p2*2)*_DAT_0059e444.
Source: *param_3=(float)(int)*(char*)(param_2+0x12+param_1)*_DAT_005ac988; *param_4=(float)(int)*(short*)(param_1+0x16+param_2*2)*_DAT_0059e444; ✓

## FUN_004DC220 — PASS
Doc: Conditional Object Constructor. If param_1==0: alloc 0x10 bytes, vtable, [1]=3, byte+2=0, [3]=0. Calls operator_new.
Source: if (param_1==0): operator_new(0x10); puVar1[1]=3; *(puVar1+2)=0; puVar1[3]=0; *puVar1=&PTR_LAB_005ad0f8; ✓

## FUN_00515986 — PASS
Doc: Bitfield-Controlled Memory Copy. (param_3 & 0x1ffffff) << 5 dwords copied.
Source: for (iVar1=(param_3&0x1ffffff)<<5; iVar1!=0; iVar1--) *param_2=*param_1; param_1++; param_2++; ✓

## FUN_00553D00 — PASS
Doc: 2D Range Swap + Grid Fill Call. If param_3<param_2: swap. FUN_00561a15().
Source: if (param_3<param_2) swap; FUN_00561a15(param_2*param_5+param_1,(iVar1-param_2)+1,param_4,param_5,param_6); ✓

## FUN_00551790 — PASS
Doc: Linked List String Key Removal. Walks list at param_1+0x13c via +0x24. Compares wide string at +0x1c. If match: clears bit 0x00020000 at node+4, calls FUN_00551480.
Source: iVar2=*(param_1+0x13c); walks via *(iVar2+0x24); compares bytes at *(iVar2+0x1c)+0x1c; if match: *(iVar2+4)&=0xfffdffff; FUN_00551480(); ✓

## FUN_0041F100 — PASS
Doc: Triple-Value Equality Check. Calls FUN_004c2850, FUN_004c11d0. Checks +0xd0/+0xd4/+0xd8+iVar1*4 == 10.
Source: FUN_004c2850(); iVar1=FUN_004c11d0(); if (param_1 && 2<iVar1 && *(param_1+0xd8+iVar1*4)==10 && *(param_1+0xd4+iVar1*4)==10 && *(param_1+0xd0+iVar1*4)==10) return 1; ✓

## FUN_004761A0 — PASS
Doc: String Copy with Guard. If param_1!=0: calls FUN_00566650().
Source: if (param_1!=0) FUN_00566650(); ✓

## FUN_00496E40 — PASS
Doc: Linked List Traversal with Virtual Call. Reads list from param_1+0x18dc, iterator at +0x18e4. Calls vtable[0x6c] on content. Advances via +0x04.
Source: piVar2=*(int**)(param_1+0x18dc); *(int**)(param_1+0x18e4)=piVar2; while non-null: (**(code**)(*piVar2+0x6c))(); puVar1=*(int*)(*(param_1+0x18e4)+4); ... ✓

## FUN_004BA9F0 — PASS
Doc: Linked List Destruction. Walks list at *param_1. If flagged: FUN_004b0170 + frees content. Frees each node. Clears list metadata (param_1[0..3]=0).
Source: piVar3=*param_1; while: piVar1=piVar3[1]; if flagged && *piVar3: FUN_004b0170(); FUN_00587bcf(*piVar3); FUN_00587bcf(piVar3); then *param_1=0; param_1[1..3]=0; ✓

## FUN_004F8030 — PASS
Doc: Switch-Based Param Setting. Maps 0..0x2b to *param_2/*param_3. Most cases (1,0) or (0,0).
Source: switch(param_1): default+case groups→*param_2=1,*param_3=0; other groups→*param_2=0,*param_3=0; ✓

## FUN_00529AF8 — PASS
Doc: Field Setter with VTable Alloc. Alloc 0x1c via vtable+0x20. Sets [0]=0, byte[4]=param_1, byte[0x11]=param_2, [5]=param_3, [6]=param_4.
Source: puVar1 = (**(code**)(param_5+0x20))(*(param_5+0x28),1,0x1c); *puVar1=0; *(puVar1+4)=param_1; *(puVar1+0x11)=param_2; puVar1[5]=param_3; puVar1[6]=param_4; ✓

## FUN_0057A680 — PASS
Doc: COM VTable Call via +0x60. Indirect jump through vtable slot 0x60.
Source: (**(code**)(*(int*)*param_1+0x60))(); ✓

## FUN_00421470 — PASS
Doc: Function Call Wrapper. Forwards call.
Source: FUN_004214a0(); ✓

## FUN_00487160 — PASS
Doc: Utility Function. (No specific claims beyond high-level description.)
Source: FUN_0049adb0(); conditional: FUN_0049aec0; computes *param_3/*param_4; returns 1/0. No contradictions. ✓

## FUN_004A4000 — PASS
Doc: Utility Function. (No specific claims beyond high-level description.)
Source: Sets +0x78=1, +0x84=0, if *(param_1+100): FUN_0054c030(1,1,1,0). No contradictions. ✓

## FUN_0059CA50 — PASS
Doc: SEH Unwind freeing object at EBP-0x114 via FUN_00587bcf.
Source: FUN_00587bcf(*(unaff_EBP+-0x114)); ✓

## FUN_0059C7FC — PASS
Doc: SEH Unwind calling FUN_005822b0 (linked-list free).
Source: FUN_005822b0(); ✓

## FUN_0059C948 — PASS
Doc: SEH Unwind calling FUN_00581b30 (cleanup callback dispatch).
Source: FUN_00581b30(); ✓

## FUN_0059C6C0 — PASS
Doc: SEH Unwind freeing object at stack offset +8 via FUN_00587bcf.
Source: FUN_00587bcf(*(unaff_EBP+8)); ✓

## FUN_0050E174 — PASS
Doc: Indirect Dispatch via Global Function Pointer. Calls FUN_0050fea7(1), dispatches through PTR_FUN_005d7854 with 4 params.
Source: FUN_0050fea7(1); (*(code*)PTR_FUN_005d7854)(param_1,param_2,param_3,param_4); ✓

## FUN_0050D85D — PASS
Doc: Quaternion to Rotation Matrix. Multiplies by _DAT_0059e800 (2.0). Standard 3x4 formula. Bottom row [0,0,0,1].
Source: fVar10-12 = q.xyz * _DAT_0059e800; standard matrix entries; row 3 = [0,0,0,1]; ✓

## FUN_00521079 — PASS
Doc: 3DNow! Barycentric Interpolation with Normalization. Packed float compare, 4 branches + default. 1/sqrt via 3DNow! reciprocal sqrt. 0.5 scale. Two result outputs. _m_femms().
Source: _m_pfcmpge for classification; 3DNow! rsqr sequence; 0x3F0000003F000000 scale; two packed output values; _m_femms(); ✓

## FUN_0050DB5C — PASS
Doc: Rotation Matrix to Quaternion. Computes trace m00+m11+m22. Two paths (trace>0 or ≤0). Standard algorithm.
Source: v3 = a2[5]+*a2+a2[10] trace. If trace<=0: pivot selection. If trace>0: sqrt(trace+1)*0.5 for w. Standard method. ✓

## FUN_0051ECA0 — PASS
Doc: SSE Weighted Vector Sum. Weight0/1 from a2[0]/a2[1], splat via _mm_shuffle_ps, multiply a3[0]/a3[1], add, store as double.
Source: _mm_shuffle_ps for splat, _mm_mul_ps + _mm_add_ps, _mm_storel_ps to store. ✓

## FUN_005272B5 — PASS
Doc: 3DNow! Cubic Bezier Interpolation. 4 control points, parameter t. Bernstein basis. 0.5 normalization. Two __m64 results. _m_femms().
Source: _m_punpckldq for broadcast; _m_pfmul/_m_pfsub/_m_pfadd for basis; 0x3F0000003F000000 scale; a1[0]/a1[1] output; _m_femms(); ✓

## FUN_00522B5B — PASS
Doc: 3x3 Matrix Inverse (3DNow!). Adj/det via packed float. a1[0-2]/a1[3-5] rows, a1[6]=zero, a1[7]=identity. _m_femms().
Source: _m_pfadd/_m_pfmul/_m_pfsub/_m_pfacc/_m_pfsubr. a1[6]=0. a1[7]=0x3F800000 (1.0f). _m_femms(). ✓

## FUN_00567340 — PASS
Doc: Y-Axis Rotation + Euler Extraction. Computes sin/cos. Rotates 3 rows. FUN_00588570. Gimbal check on param_1[5] vs _DAT_0059e420 (1.0). fpatan extraction.
Source: fsin/fcos; row 0/1/2 rotation; FUN_00588570(); ABS(param_1[5])!=_DAT_0059e420 gimbal check; fpatan calls; ✓

## FUN_004C8650 — PASS
Doc: Sound/Audio Playback. Checks param_2, clamped to _DAT_008afe90. Validates DAT_008ac4c8. DAT_005d3254 filename. FUN_00566650.
Source: if param_2<=DAT_0059e440: param_2=_DAT_008afe90; if DAT_008ac4c8: ... DAT_005d3254; FUN_00566650; ✓

## FUN_0057BA10 — PASS
Doc: Constructor copies 0x30 bytes from param_2 to param_1+0x242. Initializes channels via FUN_00582360. Sets vtable.
Source: FUN_005837f0(param_2,param_3); copy 0xc*4=0x30 bytes; FUN_00582360(); param_1[0x250]=&PTR_FUN_005b8b3c; ... ✓

## FUN_00532AA0 — PASS
Doc: Audio Resampler (SIMD FIR). Ring buffer at param_1+0x24bc (16-entry, masked 0xf). Entry count at [0x24cc]. Stereo/mono paths. pmaddwd accumulations. DAT_008b3xxx coefficients.
Source: param_1+0x24bc; *(param_1+0x24cc)==2; pmaddwd; DAT_008b3724; packssdw; ✓

## FUN_00515417 — PASS
Doc: Sub-Band Audio Encoder. 16-sample analysis frame. Calls FUN_00513e5d (reset). Quantization.
Source: 16-float zero init. FUN_00513e5d(). Matches high-level description. ✓

## FUN_00531B50 — PASS
Doc: 32-Point MDCT. Phase 1: 16 difference pairs (param_3[i]-param_3[31-i]) scaled by _DAT_005b772c series.
Source: fVar1=(*param_3-param_3[0x1f])*_DAT_005b772c; fVar2=(param_3[1]-param_3[0x1e])*_DAT_005b7730; ... ✓

## FUN_00564490 — PASS
Doc: IP Address to String. Calls inet_ntoa.
Source: inet_ntoa((in_addr)param_1->S_un_b); ✓

## FUN_0059869C — PASS
Doc: WSAStartup (Winsock Wrapper). Thunk to WSAStartup().
Source: WSAStartup(wVersionRequired,lpWSAData); ✓

## FUN_0057B840 — PASS
Doc: Network Message Comparison. Reads list from param_1+0x1c. Compares param_2[1] against +0x04/+0x14. Short-masked ID (param_2[0]>>16) against +0x02/+0x12.
Source: iVar1=*(param_1+0x1c); if null→0; compare *(iVar1+4) vs param_2[1] AND *(iVar1+2) vs (short)(*param_2>>16); else same at +0x14/+0x12; ✓

## FUN_00551480 — PASS
Doc: Audio Flag Set. Clears 0x6000, sets 0x1000 at param_1+4. Calls FUN_00556330 (timer).
Source: *(param_1+4) = (*(param_1+4)&0xffff9fff)|0x1000; FUN_00556330(); ✓

## FUN_00585EA0 — PASS
Doc: Mutex Pair Initializer. Two CreateMutexA calls, active flags, infinite timeout (0xffffffff). Zeros fields.
Source: param_1[3]=CreateMutexA; set active flag; param_1[4]=0xffffffff; second mutex at param_1[7]; *param_1=0; param_1[1]=0; ✓

## FUN_00406659 — PASS
Doc: Miles Stream Volume Set. Calls sub_405013 init. If a2==0: vtable+12 (stop). Else: AIL_set_stream_volume_levels.
Source: sub_405013(); if a2==0.0: (*(vtable+12))(v3); else: AIL_set_stream_volume_levels(v6,v3[1],v3[1]); ✓

## FUN_00456170 — PASS
Doc: 3D Sound Emitter/Camera Struct Init. param_1[1]=0, [2]=-1, vtable, FUN_00566650, zeroes fields, 9 float defaults matching hex values, zeroes [0x22]-[0x31]. Calls FUN_00456280.
Source: All 60 fields verified matching doc description exactly. ✓
