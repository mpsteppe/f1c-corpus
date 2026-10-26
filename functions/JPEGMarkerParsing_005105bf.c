char __cdecl sub_5105BF(_DWORD *a1)
{
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // ebx
  unsigned __int16 v4; // ax
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // ebx
  unsigned __int8 v7; // al
  int v8; // ecx
  bool v9; // cc
  __int16 v11; // cx
  __int16 v12; // dx
  __int16 v13; // ax
  unsigned __int16 v14; // cx
  __int16 v15; // ax
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // ecx
  _BYTE v19[5]; // [esp+Ch] [ebp-18h]
  unsigned __int8 v20; // [esp+11h] [ebp-13h]
  unsigned __int8 v21; // [esp+12h] [ebp-12h]
  char v22; // [esp+13h] [ebp-11h]
  unsigned __int8 v23; // [esp+14h] [ebp-10h]
  unsigned __int8 v24; // [esp+15h] [ebp-Fh]
  unsigned __int8 v25; // [esp+16h] [ebp-Eh]
  unsigned __int8 v26; // [esp+17h] [ebp-Dh]
  __int16 v27; // [esp+18h] [ebp-Ch]
  int v28; // [esp+1Ch] [ebp-8h]
  int v29; // [esp+20h] [ebp-4h]
  unsigned __int8 *v30; // [esp+2Ch] [ebp+8h]
  unsigned __int8 *v31; // [esp+2Ch] [ebp+8h]
  unsigned __int8 *v32; // [esp+2Ch] [ebp+8h]

  v2 = (unsigned __int8 **)a1[5];
  v3 = *v2;
  v30 = v2[1];
  if ( !v30 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v3 = *v2;
    v30 = v2[1];
  }
  v31 = v30 - 1;
  LOBYTE(v4) = 0;
  HIBYTE(v4) = *v3;
  v5 = v3 + 1;
  v29 = v4;
  if ( v31 )
    goto LABEL_7;
  if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
    return 0;
  v5 = *v2;
  v31 = v2[1];
LABEL_7:
  v32 = v31 - 1;
  v29 = *v5 + v29 - 2;
  v6 = v5 + 1;
  if ( v29 < 14 )
  {
    v18 = v29;
    *(_DWORD *)(*a1 + 20) = 76;
    *(_DWORD *)(*a1 + 24) = v18;
  }
  else
  {
    v28 = 0;
    do
    {
      if ( !v32 )
      {
        if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
          return 0;
        v6 = *v2;
        v32 = v2[1];
      }
      --v32;
      v7 = *v6;
      v8 = v28;
      ++v6;
      v9 = ++v28 < 14;
      v19[v8] = v7;
    }
    while ( v9 );
    v29 -= 14;
    if ( v19[0] == 74 && v19[1] == 70 && v19[2] == 73 && v19[3] == 70 && !v19[4] )
    {
      if ( v20 == 1 )
      {
        if ( v21 > 2u )
        {
          *(_DWORD *)(*a1 + 20) = 88;
          *(_DWORD *)(*a1 + 24) = 1;
          *(_DWORD *)(*a1 + 28) = v21;
          (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
        }
      }
      else
      {
        *(_DWORD *)(*a1 + 20) = 115;
        *(_DWORD *)(*a1 + 24) = v20;
        *(_DWORD *)(*a1 + 28) = v21;
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
      }
      v11 = v24;
      v12 = v26;
      *((_BYTE *)a1 + 257) = v22;
      v13 = v23;
      *((_BYTE *)a1 + 256) = 1;
      v14 = (v13 << 8) + v11;
      v15 = v25;
      *((_WORD *)a1 + 129) = v14;
      *((_WORD *)a1 + 130) = v12 + (v15 << 8);
      v16 = (_DWORD *)(*a1 + 24);
      *v16 = v14;
      v16[1] = *((unsigned __int16 *)a1 + 130);
      v16[2] = *((unsigned __int8 *)a1 + 257);
      *(_DWORD *)(*a1 + 20) = 86;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      if ( v27 )
      {
        *(_DWORD *)(*a1 + 20) = 89;
        *(_DWORD *)(*a1 + 24) = (unsigned __int8)v27;
        *(_DWORD *)(*a1 + 28) = HIBYTE(v27);
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
      }
      v17 = v29;
      if ( v29 == 3 * (unsigned __int8)v27 * HIBYTE(v27) )
        goto LABEL_31;
      *(_DWORD *)(*a1 + 20) = 87;
    }
    else
    {
      *(_DWORD *)(*a1 + 20) = 76;
      v17 = v29 + 14;
    }
    *(_DWORD *)(*a1 + 24) = v17;
  }
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
LABEL_31:
  v9 = v29 <= 0;
  *v2 = v6;
  v2[1] = v32;
  if ( !v9 )
    (*(void (__cdecl **)(_DWORD *, int))(a1[5] + 16))(a1, v29);
  return 1;
}
