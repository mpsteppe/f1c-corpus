char __thiscall sub_5C8E60(_BYTE *this, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ebx
  _BYTE *v13; // eax
  int v14; // eax
  int v15; // ebx
  int v16; // edx
  int v17; // esi
  _DWORD *v18; // esi
  int v19; // ebx
  int v20; // ecx
  char *v21; // edi
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // edi
  int v26; // ecx
  int v27; // edi
  void (__thiscall ***v28)(_DWORD); // esi
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  char *v36; // edi
  int v37; // eax
  _DWORD *v38; // eax
  int v39; // eax
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  void (__thiscall ***v43)(_DWORD); // esi
  int v44; // ecx
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // [esp-12h] [ebp-68h]
  int v49; // [esp-12h] [ebp-68h]
  char v50; // [esp+0h] [ebp-56h]
  char v51; // [esp+1h] [ebp-55h]
  void **v52; // [esp+2h] [ebp-54h]
  int v53; // [esp+6h] [ebp-50h]
  _DWORD *v54; // [esp+6h] [ebp-50h]
  char *v55; // [esp+Ah] [ebp-4Ch] BYREF
  int v56; // [esp+Eh] [ebp-48h]
  void **v57; // [esp+16h] [ebp-40h]
  int v58; // [esp+1Ah] [ebp-3Ch]
  char v59; // [esp+20h] [ebp-36h] BYREF
  unsigned __int16 v60; // [esp+22h] [ebp-34h]
  char v61; // [esp+25h] [ebp-31h]
  int v62; // [esp+26h] [ebp-30h]
  _BYTE *v63; // [esp+2Ah] [ebp-2Ch] BYREF
  void *v64[10]; // [esp+2Eh] [ebp-28h] BYREF

  v5 = a3;
  v7 = this[12];
  v64[2] = this;
  if ( a3 )
  {
    if ( v7 )
      sub_643E40("- Skinning Information");
    v9 = *(_DWORD *)a2;
    v58 = 4;
    v57 = v64;
    (*(void (__thiscall **)(int))(v9 + 4))(a2);
    if ( this[12] )
    {
      sub_643E40("   + Node number = %d", v62);
      if ( this[12] )
        sub_643E40("   + Node name   = %s", *(const char **)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v62) + 376));
    }
    v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v62) + 320) + 4);
    v61 = 0;
    if ( v10 && (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 12))(v10) )
    {
      v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v62) + 320);
      v61 = 1;
    }
    else
    {
      v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v62) + 296);
    }
    if ( *(_DWORD *)(v11 + 4) )
      v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v11 + 4) + 12))(*(_DWORD *)(v11 + 4));
    else
      v12 = 0;
    v13 = operator new(0x1Cu);
    v63 = v13;
    v64[7] = 0;
    if ( v13 )
      v62 = sub_5D38B0(v13, *(_DWORD *)(v12 + 36));
    else
      v63 = 0;
    v64[6] = (void *)-1;
    sub_5C3C50(v12, a2, v62);
    if ( v63[12] )
      sub_643E40("   + Num org vertices = %d", *(_DWORD *)(v12 + 36));
    v14 = *(_DWORD *)(v12 + 36);
    v15 = 0;
    v63 = (_BYTE *)v14;
    if ( v14 > 0 )
    {
      do
      {
        v16 = *(_DWORD *)a2;
        v56 = 1;
        v55 = &v59;
        (*(void (__thiscall **)(int))(v16 + 4))(a2);
        v17 = 0;
        if ( SBYTE2(v57) > 0 )
        {
          do
          {
            v53 = 8;
            v52 = (void **)&v63;
            (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 4))(a2);
            sub_5D3970(v57, v15, *(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * v60), v62, 0);
            ++v17;
          }
          while ( v17 < v50 );
        }
        ++v15;
      }
      while ( v15 < (int)v55 );
      v5 = a3;
    }
    sub_5D3710(v53);
    v18 = *(_DWORD **)(*(_DWORD *)(v5 + 452) + 4 * (_DWORD)v52);
    v54 = v18;
    if ( v51 )
    {
      v19 = v18[83];
      v20 = *(_DWORD *)(v19 + 4);
      if ( !v20 || !(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 12))(v20) )
      {
        v21 = (char *)operator new(0x14u);
        v55 = v21;
        v62 = 1;
        if ( v21 )
        {
          v22 = v18[80];
          if ( *(_DWORD *)(v22 + 4) )
          {
            v24 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v22 + 4) + 12))(*(_DWORD *)(v22 + 4));
            v23 = sub_5C3D90(v21, v24);
          }
          else
          {
            v23 = sub_5C3D90(v21, 0);
          }
        }
        else
        {
          v23 = 0;
        }
        v62 = -1;
        v55 = (char *)&off_7296C8;
        v56 = 0;
        sub_5BD270(&v55, (int)v23);
        v25 = v56;
        v62 = 2;
        if ( v56 )
          (**(void (__thiscall ***)(int))v56)(v56);
        v26 = *(_DWORD *)(v19 + 4);
        *(_DWORD *)(v19 + 4) = v25;
        if ( v26 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 4))(v26);
        v62 = -1;
        if ( v25 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v25 + 4))(v25);
        v27 = v18[83];
        v28 = *(void (__thiscall ****)(_DWORD))(v19 + 4);
        if ( v28 )
          (**v28)(*(_DWORD *)(v19 + 4));
        v29 = *(_DWORD *)(v27 + 4);
        *(_DWORD *)(v27 + 4) = v28;
        if ( v29 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v29 + 4))(v29);
        v18 = v54;
      }
      v30 = v18[80];
      if ( *(_DWORD *)(v30 + 4) )
        v31 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v30 + 4) + 12))(*(_DWORD *)(v30 + 4));
      else
        v31 = 0;
      v48 = v31;
      v32 = sub_5C63C0();
      sub_5D33C0(v32, v48);
      v33 = *(_DWORD *)(v19 + 4);
      if ( !v33 )
        goto LABEL_75;
    }
    else
    {
      v34 = v18[77];
      v35 = *(_DWORD *)(v34 + 4);
      if ( !v35 || !(*(int (__thiscall **)(int))(*(_DWORD *)v35 + 12))(v35) )
      {
        v36 = (char *)operator new(0x14u);
        v55 = v36;
        v62 = 3;
        if ( v36 )
        {
          v37 = v18[74];
          if ( *(_DWORD *)(v37 + 4) )
          {
            v39 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v37 + 4) + 12))(*(_DWORD *)(v37 + 4));
            v38 = sub_5C3D90(v36, v39);
          }
          else
          {
            v38 = sub_5C3D90(v36, 0);
          }
        }
        else
        {
          v38 = 0;
        }
        v62 = -1;
        v55 = (char *)&off_7296C8;
        v56 = 0;
        sub_5BD270(&v55, (int)v38);
        v40 = v56;
        v62 = 4;
        if ( v56 )
          (**(void (__thiscall ***)(int))v56)(v56);
        v41 = *(_DWORD *)(v34 + 4);
        *(_DWORD *)(v34 + 4) = v40;
        if ( v41 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v41 + 4))(v41);
        v62 = -1;
        if ( v40 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v40 + 4))(v40);
        v42 = v18[77];
        v43 = *(void (__thiscall ****)(_DWORD))(v34 + 4);
        if ( v43 )
          (**v43)(*(_DWORD *)(v34 + 4));
        v44 = *(_DWORD *)(v42 + 4);
        *(_DWORD *)(v42 + 4) = v43;
        if ( v44 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v44 + 4))(v44);
        v18 = v54;
      }
      v45 = v18[74];
      if ( *(_DWORD *)(v45 + 4) )
        v46 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v45 + 4) + 12))(*(_DWORD *)(v45 + 4));
      else
        v46 = 0;
      v49 = v46;
      v47 = sub_5C63C0();
      sub_5D33C0(v47, v49);
      v33 = *(_DWORD *)(v34 + 4);
      if ( !v33 )
        goto LABEL_75;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v33 + 12))(v33);
LABEL_75:
    sub_5C3F50();
    return 1;
  }
  if ( v7 )
    sub_643E40("Passed actor seems to be not valid!");
  return 0;
}
