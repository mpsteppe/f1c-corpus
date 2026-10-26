unsigned int __fastcall sub_536900(int a1, int a2)
{
  int v2; // ebx
  unsigned int v4; // edi
  _BYTE *v5; // esi
  unsigned int result; // eax
  _BYTE *v7; // edx
  _BYTE *v8; // edi
  char v9; // bl
  _BYTE *v10; // edi
  _BYTE *v11; // esi
  _BYTE *v12; // edi
  char v13; // bl
  _BYTE *v14; // edi
  char v15; // bl
  _BYTE *v16; // edi
  char v17; // bl
  _BYTE *v18; // edi
  char v19; // bl
  _BYTE *v20; // edi
  char v21; // bl
  _BYTE *v22; // edi
  char v23; // bl
  _BYTE *v24; // edi
  char v25; // bl
  _BYTE *v26; // edi
  char v27; // bl
  _BYTE *v28; // edi
  int v29; // edi
  char v30; // [esp+12h] [ebp-12h]
  char v31; // [esp+13h] [ebp-11h]
  unsigned int v32; // [esp+14h] [ebp-10h]
  int v33; // [esp+18h] [ebp-Ch]
  unsigned int v34; // [esp+1Ch] [ebp-8h]
  unsigned int v35; // [esp+20h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 34);
  v4 = *(_DWORD *)(a1 + 98);
  v33 = *(_DWORD *)(a1 + 134);
  v5 = (_BYTE *)(v4 + *(_DWORD *)(a1 + 46));
  v32 = *(_DWORD *)(a1 + 114);
  result = *(_DWORD *)(a1 + 110);
  if ( v4 <= v2 - 262 )
    v34 = 0;
  else
    v34 = v4 - v2 + 262;
  v30 = v5[result - 1];
  v7 = v5 + 258;
  v31 = v5[result];
  if ( result >= *(_DWORD *)(a1 + 130) )
    v32 >>= 2;
  v35 = *(_DWORD *)(a1 + 106);
  if ( v33 > v35 )
    v33 = *(_DWORD *)(a1 + 106);
  do
  {
    v8 = (_BYTE *)(a2 + *(_DWORD *)(a1 + 46));
    if ( v8[result] == v31 && v8[result - 1] == v30 && *v8 == *v5 )
    {
      v9 = v8[1];
      v10 = v8 + 1;
      if ( v9 == v5[1] )
      {
        v11 = v5 + 2;
        v12 = v10 + 1;
        do
        {
          v13 = *++v11;
          v14 = v12 + 1;
          if ( v13 != *v14 )
            break;
          v15 = *++v11;
          v16 = v14 + 1;
          if ( v15 != *v16 )
            break;
          v17 = *++v11;
          v18 = v16 + 1;
          if ( v17 != *v18 )
            break;
          v19 = *++v11;
          v20 = v18 + 1;
          if ( v19 != *v20 )
            break;
          v21 = *++v11;
          v22 = v20 + 1;
          if ( v21 != *v22 )
            break;
          v23 = *++v11;
          v24 = v22 + 1;
          if ( v23 != *v24 )
            break;
          v25 = *++v11;
          v26 = v24 + 1;
          if ( v25 != *v26 )
            break;
          v27 = *++v11;
          v12 = v26 + 1;
          if ( v27 != *v12 )
            break;
        }
        while ( v11 < v7 );
        v28 = v11;
        v5 = v7 - 258;
        v29 = v28 - v7 + 258;
        if ( v29 > (int)result )
        {
          *(_DWORD *)(a1 + 102) = a2;
          result = v29;
          if ( v29 >= v33 )
            break;
          v30 = v5[v29 - 1];
          v31 = v5[v29];
        }
      }
    }
    a2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 54) + 2 * (a2 & *(_DWORD *)(a1 + 42)));
    if ( (unsigned __int16)a2 <= v34 )
      break;
    --v32;
  }
  while ( v32 );
  if ( result > v35 )
    return v35;
  return result;
}

