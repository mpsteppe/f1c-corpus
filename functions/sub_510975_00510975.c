char __usercall sub_510975@<al>(_DWORD *a1@<esi>)
{
  unsigned __int8 **v1; // ebx
  unsigned __int8 *v2; // edi
  unsigned __int16 v3; // ax
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // edi
  int v6; // eax
  unsigned __int8 *v7; // edi
  int v8; // eax
  int v9; // eax
  int v11; // [esp+8h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+10h] [ebp-8h]
  unsigned __int8 *v16; // [esp+14h] [ebp-4h]
  unsigned __int8 *v17; // [esp+14h] [ebp-4h]
  unsigned __int8 *v18; // [esp+14h] [ebp-4h]
  unsigned __int8 *v19; // [esp+14h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[5];
  v2 = *v1;
  v16 = v1[1];
  if ( !v16 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
      return 0;
    v2 = *v1;
    v16 = v1[1];
  }
  v17 = v16 - 1;
  LOBYTE(v3) = 0;
  HIBYTE(v3) = *v2;
  v4 = v2 + 1;
  v13 = v3;
  if ( v17 )
    goto LABEL_7;
  if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
    return 0;
  v4 = *v1;
  v17 = v1[1];
LABEL_7:
  v18 = v17 - 1;
  v14 = *v4 + v13;
  v5 = v4 + 1;
  v15 = v14 - 2;
  while ( v15 > 0 )
  {
    if ( !v18 )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
        return 0;
      v5 = *v1;
      v18 = v1[1];
    }
    v6 = *v5;
    v19 = v18 - 1;
    v7 = v5 + 1;
    v12 = v6;
    if ( !v19 )
    {
      if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) )
        return 0;
      v7 = *v1;
      v19 = v1[1];
    }
    v8 = *v7;
    v18 = v19 - 1;
    v15 -= 2;
    *(_DWORD *)(*a1 + 20) = 78;
    *(_DWORD *)(*a1 + 24) = v12;
    v11 = v8;
    *(_DWORD *)(*a1 + 28) = v8;
    v5 = v7 + 1;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
    v9 = v12;
    if ( v12 >= 32 )
    {
      *(_DWORD *)(*a1 + 20) = 26;
      *(_DWORD *)(*a1 + 24) = v12;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      v9 = v12;
    }
    if ( v9 < 16 )
    {
      *((_BYTE *)a1 + v9 + 202) = v11 & 0xF;
      *((_BYTE *)a1 + v9 + 218) = v11 >> 4;
      if ( (unsigned __int8)(v11 & 0xF) > (unsigned __int8)(v11 >> 4) )
      {
        *(_DWORD *)(*a1 + 20) = 27;
        *(_DWORD *)(*a1 + 24) = v11;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
    }
    else
    {
      *((_BYTE *)a1 + v9 + 218) = v11;
    }
  }
  v1[1] = v18;
  *v1 = v5;
  return 1;
}
