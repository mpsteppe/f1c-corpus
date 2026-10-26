int __userpurge sub_5F0DD0@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        const char *a4,
        int a5,
        int a6,
        int *a7,
        char a8,
        int a9)
{
  unsigned int v11; // ebx
  int v12; // eax
  _DWORD *v13; // ebp
  int v14; // ebx
  int v15; // ecx
  int v16; // ecx
  unsigned int v17; // ebp
  int v18; // ebx
  int v19; // edx
  unsigned int v20; // ebp
  int v21; // ebx
  float v22; // [esp+34h] [ebp-35Ch]
  float v24; // [esp+38h] [ebp-358h]
  int v26; // [esp+40h] [ebp-350h]
  _DWORD v28[3]; // [esp+4Ch] [ebp-344h] BYREF
  int v29; // [esp+58h] [ebp-338h]
  _DWORD v30[202]; // [esp+5Ch] [ebp-334h] BYREF

  if ( !*a4 )
    return -2;
  if ( !sub_5E7120(a7, 2) && !sub_5E7150(a7, 8) )
    return -1;
  if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
  {
    v11 = 3 * strlen(a4);
    v12 = *(_DWORD *)(a1 + 164);
    v13 = (_DWORD *)(a1 + 164);
    v14 = 2 * v11;
    *(_DWORD *)(a1 + 160) = 0;
    if ( v12 )
    {
      v15 = *(_DWORD *)(v12 + 12);
      if ( v15 <= 0 || (v16 = v15 - 1, (*(_DWORD *)(v12 + 12) = v16) == 0) )
        (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(dword_FB27A4, *v13, 0);
    }
    *v13 = 0;
    if ( (*(int (__thiscall **)(int, _DWORD, int, int, int, int, _DWORD *, _DWORD))(*(_DWORD *)dword_FB27A4 + 368))(
           dword_FB27A4,
           0,
           2048,
           v14,
           0x2000,
           a1 + 164,
           v28,
           0) )
    {
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(dword_FB27A4, *v13, 0x2000);
      return -1;
    }
    if ( *v13 )
    {
      ++*(_DWORD *)(*v13 + 12);
      *(_DWORD *)(a1 + 168) = *(_DWORD *)(*v13 + 76);
      v17 = 0;
      if ( strlen(a4) )
      {
        v18 = a5;
        do
          v18 += sub_5EFFC0(a1, a4[v17++], v18, a6, a7, a8);
        while ( v17 < strlen(a4) );
      }
      (*(void (__thiscall **)(int, _DWORD, int, int, int))(*(_DWORD *)dword_FB27A4 + 416))(
        dword_FB27A4,
        *(_DWORD *)(a1 + 164),
        0x2000,
        a3,
        a2);
      *(_DWORD *)(a1 + 168) = 0;
      if ( a9 != (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 156))(dword_FB27A4) )
      {
        sub_5E57E0(v30);
        v19 = *(_DWORD *)(a9 + 4);
        v29 = *(_DWORD *)(a9 + 8);
        v28[1] = v19;
        v24 = (float)v29;
        v22 = (float)v19;
        sub_5E53E0((int)v30, 0.0, 0.0, v22, v24, 0);
        sub_5E54E0((int)v30, 1036831949, 1065353216);
        sub_5E55E0(v30, a9);
        sub_5E5050((char *)v30, 318);
        sub_51D670(v30, a9, v26);
      }
      (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 460))(dword_FB27A4, 0, v26);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 420))(
        dword_FB27A4,
        *(_DWORD *)(a1 + 164),
        v30[5],
        *(_DWORD *)(a1 + 160),
        *(_DWORD *)(a1 + 180),
        *(_DWORD *)(a1 + 176),
        *(_DWORD *)(a1 + 136),
        *(_DWORD *)(a1 + 140),
        *(_DWORD *)(a1 + 148),
        0);
    }
  }
  else
  {
    v20 = 0;
    v28[0] = strlen(a4);
    if ( v28[0] )
    {
      v21 = a5;
      do
        v21 += sub_5EFFC0(a1, a4[v20++], v21, a6, a7, a8);
      while ( v20 < strlen(a4) );
    }
  }
  return 0;
}
