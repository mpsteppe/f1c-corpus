int __thiscall sub_58ED90(int this)
{
  int v1; // ebp
  bool v3; // zf
  int i; // eax
  const char *v5; // ecx
  const char *v6; // eax
  int j; // esi
  const CHAR *v8; // eax
  int v9; // ecx
  int v10; // edx
  const CHAR *v11; // eax
  int v12; // edx
  char v13; // al
  int v14; // eax
  const CHAR *v15; // eax
  const CHAR *v16; // eax
  int k; // ebx
  int v18; // esi
  int v19; // ecx
  double v21; // st7
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c3
  int v24; // edx
  double v25; // st7
  int v26; // esi
  double v28; // st7
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  int v31; // edx
  double v32; // st7
  float v34; // [esp+Ch] [ebp-B5Ch] BYREF
  int v35; // [esp+10h] [ebp-B58h] BYREF
  int v36; // [esp+14h] [ebp-B54h]
  int v37; // [esp+18h] [ebp-B50h] BYREF
  float v38; // [esp+1Ch] [ebp-B4Ch] BYREF
  int v39; // [esp+20h] [ebp-B48h] BYREF
  _BYTE v40[1180]; // [esp+24h] [ebp-B44h] BYREF
  char v41[1180]; // [esp+4C0h] [ebp-6A8h] BYREF
  char Buffer[512]; // [esp+95Ch] [ebp-20Ch] BYREF
  int v43; // [esp+B64h] [ebp-4h]

  v1 = 0;
  v36 = 0;
  sub_630A11(v40, 20, 59, sub_40B430, sub_498720);
  v43 = 0;
  sub_630A11(v41, 20, 59, sub_40B430, sub_498720);
  v3 = *(_DWORD *)(this + 2436) == 0;
  LOBYTE(v43) = 1;
  if ( !v3 || *(_DWORD *)(this + 2676) )
  {
    v36 = 1;
  }
  else
  {
    *(_DWORD *)(this + 2436) = operator new(0xECu);
    *(_DWORD *)(this + 2676) = operator new(0xECu);
    for ( i = 0; i < 236; i += 4 )
    {
      *(_DWORD *)(i + *(_DWORD *)(this + 2436)) = 0;
      *(_DWORD *)(i + *(_DWORD *)(this + 2676)) = 0;
    }
    if ( !sub_473630(&dword_B6CBA8) )
    {
      if ( !byte_FB1398 )
      {
        v5 = (const char *)dword_91CAE8;
        if ( !dword_91CAE8 )
          v5 = WindowName;
        v6 = *(const char **)dword_91CA70;
        if ( !*(_DWORD *)dword_91CA70 )
          v6 = WindowName;
        sprintf(Buffer, "%s%s%s", v6, v5, aDefaultAud);
        if ( !sub_58CD60((float *)this, (int)Buffer, (int)dword_FB13A0, (int)dword_FB1840) )
          byte_FB1398 = 1;
      }
      for ( j = 0; j < 295; j += 5 )
      {
        v8 = (const CHAR *)dword_FB13A0[j];
        if ( !v8 )
          v8 = WindowName;
        sub_615860(v8);
        v9 = dword_FB13A8[j];
        v10 = dword_FB13AC[j];
        v40[j * 4 + 16] = byte_FB13B0[j * 4];
        v11 = (const CHAR *)dword_FB1840[j];
        *(_DWORD *)&v40[j * 4 + 8] = v9;
        *(_DWORD *)&v40[j * 4 + 12] = v10;
        if ( !v11 )
          v11 = WindowName;
        sub_615860(v11);
        v12 = dword_FB184C[j];
        v13 = byte_FB1850[j * 4];
        *(_DWORD *)&v41[j * 4 + 8] = dword_FB1848[j];
        *(_DWORD *)&v41[j * 4 + 12] = v12;
        v41[j * 4 + 16] = v13;
      }
      v14 = sub_539670((char *)(*(_DWORD *)this + 22084));
      if ( v14 )
      {
        v15 = *(const CHAR **)(v14 + 24);
        if ( !v15 )
          v15 = WindowName;
        sub_58CD60((float *)this, (int)v15, (int)v40, (int)v41);
      }
      if ( dword_BE1D0C )
      {
        v16 = (const CHAR *)dword_91CA90;
        if ( !dword_91CA90 )
          v16 = WindowName;
        (*(void (__stdcall **)(const CHAR *))(*(_DWORD *)dword_BE1D0C + 68))(v16);
      }
      for ( k = 0; k < 1180; k += 20 )
      {
        sub_58BED0((_DWORD *)v1, &v37, &v39);
        sub_58C090(v1, &v34, (float *)&v35, &v38);
        v18 = 4 * v1;
        sub_58C470((int *)(4 * v1 + *(_DWORD *)(this + 2436)), (const char **)&v40[k], v37, v39);
        v19 = *(_DWORD *)(4 * v1 + *(_DWORD *)(this + 2436));
        if ( v19 )
        {
          v21 = 1.0;
          if ( !(v22 | v23) )
            v21 = 1.0 / v34;
          v24 = v35;
          *(float *)(v19 + 28) = v21;
          v25 = v21 * v38;
          *(_DWORD *)(v19 + 36) = v24;
          *(float *)(v19 + 32) = 1.0 - v25;
        }
        sub_58C470((int *)(v18 + *(_DWORD *)(this + 2676)), (const char **)&v41[k], v37, v39);
        v26 = *(_DWORD *)(v18 + *(_DWORD *)(this + 2676));
        if ( v26 )
        {
          v28 = 1.0;
          if ( !(v29 | v30) )
            v28 = 1.0 / v34;
          v31 = v35;
          *(float *)(v26 + 28) = v28;
          v32 = v28 * v38;
          *(_DWORD *)(v26 + 36) = v31;
          *(float *)(v26 + 32) = 1.0 - v32;
        }
        ++v1;
      }
    }
  }
  LOBYTE(v43) = 0;
  `eh vector destructor iterator'(v41, 0x14u, 59, (void (__thiscall *)(void *))sub_498720);
  v43 = -1;
  `eh vector destructor iterator'(v40, 0x14u, 59, (void (__thiscall *)(void *))sub_498720);
  return v36;
}
