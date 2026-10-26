unsigned int __usercall sub_62B620@<eax>(unsigned int a1@<eax>, int a2@<esi>)
{
  unsigned int v2; // edx
  unsigned int v3; // ebp
  int v4; // edi
  _BYTE *v5; // ecx
  _BYTE *v6; // edi
  _BYTE *v7; // edx
  char v8; // bl
  _BYTE *v9; // edx
  _BYTE *v10; // ecx
  _BYTE *v11; // edx
  char v12; // bl
  _BYTE *v13; // edx
  char v14; // bl
  _BYTE *v15; // edx
  char v16; // bl
  _BYTE *v17; // edx
  char v18; // bl
  _BYTE *v19; // edx
  char v20; // bl
  _BYTE *v21; // edx
  char v22; // bl
  _BYTE *v23; // edx
  char v24; // bl
  _BYTE *v25; // edx
  char v26; // bl
  int v27; // edx
  unsigned int result; // eax
  char v29; // [esp+Eh] [ebp-12h]
  char v30; // [esp+Fh] [ebp-11h]
  unsigned int v31; // [esp+10h] [ebp-10h]
  int v32; // [esp+14h] [ebp-Ch]
  unsigned int v33; // [esp+18h] [ebp-8h]
  unsigned int v34; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 98);
  v3 = *(_DWORD *)(a2 + 110);
  v31 = *(_DWORD *)(a2 + 114);
  v32 = *(_DWORD *)(a2 + 134);
  v4 = *(_DWORD *)(a2 + 34);
  v5 = (_BYTE *)(v2 + *(_DWORD *)(a2 + 46));
  if ( v2 <= v4 - 262 )
    v33 = 0;
  else
    v33 = v2 - v4 + 262;
  v29 = v5[v3 - 1];
  v30 = v5[v3];
  v6 = v5 + 258;
  if ( v3 >= *(_DWORD *)(a2 + 130) )
    v31 >>= 2;
  v34 = *(_DWORD *)(a2 + 106);
  if ( v32 > v34 )
    v32 = *(_DWORD *)(a2 + 106);
  do
  {
    v7 = (_BYTE *)(a1 + *(_DWORD *)(a2 + 46));
    if ( v7[v3] == v30 && v7[v3 - 1] == v29 && *v7 == *v5 )
    {
      v8 = v7[1];
      v9 = v7 + 1;
      if ( v8 == v5[1] )
      {
        v10 = v5 + 2;
        v11 = v9 + 1;
        do
        {
          v12 = *++v10;
          v13 = v11 + 1;
          if ( v12 != *v13 )
            break;
          v14 = *++v10;
          v15 = v13 + 1;
          if ( v14 != *v15 )
            break;
          v16 = *++v10;
          v17 = v15 + 1;
          if ( v16 != *v17 )
            break;
          v18 = *++v10;
          v19 = v17 + 1;
          if ( v18 != *v19 )
            break;
          v20 = *++v10;
          v21 = v19 + 1;
          if ( v20 != *v21 )
            break;
          v22 = *++v10;
          v23 = v21 + 1;
          if ( v22 != *v23 )
            break;
          v24 = *++v10;
          v25 = v23 + 1;
          if ( v24 != *v25 )
            break;
          v26 = *++v10;
          v11 = v25 + 1;
          if ( v26 != *v11 )
            break;
        }
        while ( v10 < v6 );
        v27 = v10 - v6 + 258;
        v5 = v6 - 258;
        if ( v27 > (int)v3 )
        {
          *(_DWORD *)(a2 + 102) = a1;
          v3 = v27;
          if ( v27 >= v32 )
            break;
          v29 = v5[v27 - 1];
          v30 = v5[v27];
        }
      }
    }
    a1 = *(unsigned __int16 *)(*(_DWORD *)(a2 + 54) + 2 * (a1 & *(_DWORD *)(a2 + 42)));
    if ( a1 <= v33 )
      break;
    --v31;
  }
  while ( v31 );
  result = v34;
  if ( v3 <= v34 )
    return v3;
  return result;
}
