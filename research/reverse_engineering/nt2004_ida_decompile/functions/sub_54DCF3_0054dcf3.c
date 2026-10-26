char __usercall sub_54DCF3@<al>(_DWORD *a1@<ebx>)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // esi
  unsigned __int16 v3; // ax
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // eax
  __int16 v11; // ax
  int *v12; // eax
  unsigned __int16 *v13; // ecx
  _DWORD *v14; // eax
  int v16; // [esp+8h] [ebp-18h]
  int v17; // [esp+Ch] [ebp-14h]
  int v18; // [esp+10h] [ebp-10h]
  _DWORD *v19; // [esp+10h] [ebp-10h]
  int *v20; // [esp+10h] [ebp-10h]
  unsigned __int16 *v21; // [esp+10h] [ebp-10h]
  __int16 v22; // [esp+14h] [ebp-Ch]
  __int16 v23; // [esp+14h] [ebp-Ch]
  int v24; // [esp+14h] [ebp-Ch]
  int v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+18h] [ebp-8h]
  int v27; // [esp+18h] [ebp-8h]
  unsigned __int8 *v28; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *v29; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *v30; // [esp+1Ch] [ebp-4h]

  v1 = (unsigned __int8 **)a1[5];
  v2 = *v1;
  v28 = v1[1];
  if ( !v28 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v2 = *v1;
    v28 = v1[1];
  }
  v29 = v28 - 1;
  LOBYTE(v3) = 0;
  HIBYTE(v3) = *v2;
  v4 = v2 + 1;
  v25 = v3;
  if ( v29 )
    goto LABEL_7;
  if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
    return 0;
  v4 = *v1;
  v29 = v1[1];
LABEL_7:
  v30 = v29 - 1;
  v26 = *v4 + v25;
  v5 = v4 + 1;
  v27 = v26 - 2;
  while ( v27 > 0 )
  {
    if ( !v30 )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
        return 0;
      v5 = *v1;
      v30 = v1[1];
    }
    v6 = *v5;
    --v30;
    *(_DWORD *)(*a1 + 20) = 80;
    v7 = v6;
    v8 = v6 & 0xF;
    *(_DWORD *)(*a1 + 24) = v8;
    v18 = v8;
    v17 = v7 >> 4;
    *(_DWORD *)(*a1 + 28) = v7 >> 4;
    ++v5;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
    v9 = v18;
    if ( v18 >= 4 )
    {
      *(_DWORD *)(*a1 + 20) = 30;
      *(_DWORD *)(*a1 + 24) = v18;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      v9 = v18;
    }
    v10 = &a1[v9 + 36];
    v19 = v10;
    if ( !*v10 )
    {
      *v10 = sub_553907(a1);
      v10 = v19;
    }
    v16 = *v10;
    v20 = &dword_5F4D18;
    do
    {
      if ( v17 )
      {
        if ( !v30 )
        {
          if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
            return 0;
          v5 = *v1;
          v30 = v1[1];
        }
        --v30;
        LOBYTE(v11) = 0;
        HIBYTE(v11) = *v5++;
        v22 = v11;
        if ( !v30 )
        {
          if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
            return 0;
          v5 = *v1;
          v30 = v1[1];
        }
        v23 = *v5 + v22;
      }
      else
      {
        if ( !v30 )
        {
          if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
            return 0;
          v5 = *v1;
          v30 = v1[1];
        }
        v23 = *v5;
      }
      v12 = v20;
      --v30;
      ++v20;
      ++v5;
      *(_WORD *)(v16 + 2 * *v12) = v23;
    }
    while ( (int)v20 < (int)dword_5F4E18 );
    if ( *(int *)(*a1 + 104) >= 2 )
    {
      v13 = (unsigned __int16 *)(v16 + 4);
      v21 = (unsigned __int16 *)(v16 + 4);
      v24 = 8;
      while ( 1 )
      {
        v14 = (_DWORD *)(*a1 + 24);
        *v14 = *(v13 - 2);
        v14[1] = *(v13 - 1);
        v14[2] = *v13;
        v14[3] = v13[1];
        v14[4] = v13[2];
        v14[5] = v13[3];
        v14[6] = v13[4];
        v14[7] = v13[5];
        *(_DWORD *)(*a1 + 20) = 92;
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 2);
        v21 += 8;
        if ( !--v24 )
          break;
        v13 = v21;
      }
    }
    v27 -= 65;
    if ( v17 )
      v27 -= 64;
  }
  v1[1] = v30;
  *v1 = v5;
  return 1;
}
