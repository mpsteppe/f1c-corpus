int __usercall sub_486AC0@<eax>(int *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  int v5; // eax
  int v6; // ecx
  float *v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // edx
  float v12; // ecx
  int v13; // edi
  float v14; // ebx
  int v15; // eax
  float v16; // edx
  float v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // ebp
  float v23; // edi
  int v24; // ecx
  int v25; // eax
  int v26; // ebx
  int v27; // edi
  int v28; // [esp+2Eh] [ebp-7Ch]
  int v29; // [esp+2Eh] [ebp-7Ch]
  int v30; // [esp+36h] [ebp-74h]
  int v31; // [esp+3Eh] [ebp-6Ch]
  int v32; // [esp+42h] [ebp-68h]
  int v33; // [esp+46h] [ebp-64h]
  char v34; // [esp+50h] [ebp-5Ah]
  char v35; // [esp+51h] [ebp-59h]
  int v36; // [esp+52h] [ebp-58h]
  int v37; // [esp+56h] [ebp-54h]
  int v38; // [esp+5Ah] [ebp-50h]
  int v39; // [esp+5Eh] [ebp-4Ch] BYREF
  int v40; // [esp+62h] [ebp-48h] BYREF
  int v41; // [esp+66h] [ebp-44h] BYREF
  int v42; // [esp+6Ah] [ebp-40h] BYREF
  int v43; // [esp+6Eh] [ebp-3Ch]
  int v44; // [esp+72h] [ebp-38h]
  float v45; // [esp+76h] [ebp-34h]
  int v46; // [esp+7Ah] [ebp-30h] BYREF
  float v47; // [esp+7Eh] [ebp-2Ch] BYREF
  float v48; // [esp+82h] [ebp-28h] BYREF
  int v49[4]; // [esp+86h] [ebp-24h] BYREF
  int v50; // [esp+96h] [ebp-14h] BYREF
  int v51; // [esp+9Ah] [ebp-10h] BYREF
  int v52; // [esp+9Eh] [ebp-Ch] BYREF
  int v53; // [esp+A2h] [ebp-8h] BYREF
  int v54; // [esp+A6h] [ebp-4h] BYREF
  int retaddr; // [esp+AAh] [ebp+0h] BYREF
  float v57; // [esp+AEh] [ebp+4h]

  if ( *((_BYTE *)a1 + 108) )
  {
    (*(void (__thiscall **)(int *))(*a1 + 160))(a1);
    *((_BYTE *)a1 + 108) = 0;
  }
  v5 = GlobalAccessor_5150(&unk_7CDE00);
  v6 = a1[16];
  v40 = v5;
  v34 = 0;
  if ( *(_DWORD *)(v6 + 56) == 2 )
  {
    v40 = GlobalGetter(&unk_7CDE00);
    v34 = 1;
  }
  v54 = sub_486830(a1);
  if ( !sub_486830(a1) && !v34 )
    return -1;
  if ( *((_BYTE *)a1 + 101) )
  {
    v35 = (*(int (__thiscall **)(int *))(*a1 + 20))(a1);
    if ( v35 )
      (*(void (__thiscall **)(int *, int *, float *, float *, int *))(*a1 + 8))(a1, &v46, &v47, &v48, v49);
    (*(void (__thiscall **)(int *, int, int, int))(*a1 + 12))(a1, a4, a3, a2);
    v8 = (float *)ConditionalDelegation_6460(a1, a1[33]);
    v9 = a1[34];
    if ( v9 > 0 )
    {
      do
      {
        if ( v8 )
          v8 = (float *)*((_DWORD *)v8 + 10);
        --v9;
      }
      while ( v9 );
    }
    if ( v8 )
    {
      v10 = a1[1];
      v39 = a1[3];
      v40 = v10;
      v11 = *((_DWORD *)v8 + 8);
      v12 = *v8;
      v13 = *((_DWORD *)v8 + 1);
      LODWORD(v14) = *((_DWORD *)v8 + 3) - *((_DWORD *)v8 + 2);
      v48 = v8[2];
      v15 = *(_DWORD *)(v11 + 12);
      v16 = *(float *)(v15 + 28);
      LODWORD(v17) = v13 - LODWORD(v12);
      v57 = v12;
      v46 = LODWORD(v17);
      v44 = LODWORD(v14);
      if ( SLODWORD(v17) > SLODWORD(v16) )
      {
        v17 = v16;
        v46 = LODWORD(v16);
      }
      if ( SLODWORD(v14) > *(_DWORD *)(v15 + 32) )
      {
        v14 = *(float *)(v15 + 32);
        v44 = LODWORD(v14);
      }
      if ( BYTE2(v38) )
      {
        GlobalFieldReader(&v50, &v51);
        v47 = (double)v50 * 0.00125;
        v45 = (double)v51 * 0.0016666667;
        v40 = CRTFtol((double)v40 * v45);
        v18 = CRTFtol((double)v39 * v47);
        v19 = *a1;
        v39 = v18;
        (*(void (__thiscall **)(int *, int *, int *, int *, int *))(v19 + 136))(a1, &retaddr, &v54, &v53, &v52);
        v33 = v52;
        v32 = v53;
        v31 = v54;
        v30 = CRTFtol((double)v44 * v45);
        v20 = CRTFtol((double)v46 * v47);
        F_2DScreenQuadRender(
          *(_DWORD *)(*((_DWORD *)v8 + 8) + 12),
          v57,
          v48,
          v17,
          v14,
          v43,
          v39,
          *(float *)&v40,
          v20,
          v30,
          retaddr,
          v31,
          v32,
          v33);
      }
      else
      {
        F_10ParamForwarder(v15, LODWORD(v12), LODWORD(v48), v43, v39, v40, LODWORD(v17), LODWORD(v14), 0, 0);
        (*(void (__thiscall **)(int *, int, int, int, int))(*a1 + 16))(
          a1,
          v40,
          v40 + LODWORD(v14),
          v39,
          v39 + LODWORD(v17));
      }
    }
    v41 = 0;
    v42 = 0;
    v21 = *a1;
    v40 = 600;
    v39 = 800;
    (*(void (__thiscall **)(int *, int *, int *, int *, int *))(v21 + 52))(a1, &v40, &v41, &v39, &v42);
    if ( v41 - v40 > 0 && v42 - v39 > 0 )
      (*(void (__thiscall **)(int *, int, int, int, int))(*a1 + 16))(a1, v40, v41, v39, v42);
    (*(void (__thiscall **)(int *, int *))(*a1 + 8))(a1, &v40);
    if ( v35 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int *))(*a1 + 20))(a1) )
      {
        v22 = v37;
        if ( v37 >= v46 )
          v22 = v46;
        v23 = *(float *)&v38;
        if ( v38 <= SLODWORD(v47) )
          v23 = v47;
        v24 = v36;
        if ( v36 >= SLODWORD(v48) )
          v24 = LODWORD(v48);
        v25 = v39;
        if ( v39 <= v49[0] )
        {
          v25 = v49[0];
          v39 = v49[0];
        }
      }
      else
      {
        v22 = v46;
        v23 = v47;
        v24 = LODWORD(v48);
        v25 = v49[0];
        v39 = v49[0];
      }
    }
    else
    {
      v24 = v36;
      v22 = v37;
      v23 = *(float *)&v38;
      v25 = v39;
    }
    if ( !v34 )
    {
      v26 = v25 - v24;
      v27 = LODWORD(v23) - v22;
      v53 = v24;
      if ( v54 == 1 )
      {
        v28 = v24;
        Accessor();
        RenderSurfaceFillCopy(v28, v22, v26, v27);
        v24 = v53;
      }
      else if ( v54 <= 1 || v54 > 3 )
      {
        goto LABEL_45;
      }
      v29 = v24;
      Accessor();
      DualDispatchWithGuard(v29, v22, v26, v27);
LABEL_45:
      (*(void (__thiscall **)(int *, _DWORD))(*a1 + 44))(a1, 0);
    }
  }
  return 0;
}
