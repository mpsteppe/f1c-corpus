int __thiscall sub_68DD50(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  _DWORD *v10; // esi
  bool v11; // zf
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  int v19; // esi
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // eax
  unsigned int v23; // eax
  int result; // eax
  unsigned int v25; // edx
  unsigned int v26; // edi
  _DWORD *v27; // ecx
  unsigned int v28; // eax
  _DWORD *v29; // ecx
  int v30; // eax
  int v31; // ecx
  _DWORD *v32; // eax
  int v33; // ecx
  int v34; // esi
  int v35[4]; // [esp+0h] [ebp-3Ch] BYREF
  int v36[4]; // [esp+10h] [ebp-2Ch] BYREF
  int v37; // [esp+20h] [ebp-1Ch]
  unsigned int v38; // [esp+24h] [ebp-18h]
  _DWORD *v39; // [esp+28h] [ebp-14h]
  int v40; // [esp+2Ch] [ebp-10h]
  int v41; // [esp+30h] [ebp-Ch]
  unsigned int v42; // [esp+34h] [ebp-8h]
  int v43; // [esp+38h] [ebp-4h]
  unsigned int v44; // [esp+44h] [ebp+8h]
  unsigned int v45; // [esp+44h] [ebp+8h]
  unsigned int i; // [esp+48h] [ebp+Ch]
  int v47; // [esp+4Ch] [ebp+10h]
  unsigned int v48; // [esp+54h] [ebp+18h]

  v6 = this[5];
  v7 = a3;
  v43 = (int)this;
  v8 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
  if ( v8 != -1 )
  {
    a3 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
    v7 = v8;
  }
  v10 = *(_DWORD **)(v6 + 4 * v7);
  v11 = *(_DWORD *)a2 == v10[1];
  v39 = v10;
  if ( !v11 )
    goto LABEL_47;
  v12 = 4 * v10[3];
  if ( *(_DWORD *)(v12 + *(_DWORD *)(a2 + 16)) != -1 )
    goto LABEL_47;
  v13 = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(v12 + *(_DWORD *)(a2 + 8)) < v13 && *(_DWORD *)(v12 + *(_DWORD *)(a2 + 12)) < v13 )
    goto LABEL_47;
  v41 = -1;
  v42 = -1;
  if ( a6 != -1 )
  {
    v41 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * a6);
    v42 = sub_685948(v43, a2, v7, v41, a4, v36, 0xFFFFFFFF);
    goto LABEL_27;
  }
  v48 = 0;
  if ( !*(_DWORD *)(a2 + 44) )
  {
LABEL_28:
    if ( (*(_BYTE *)(a2 + 96) & 2) != 0 )
      sub_686791(
        v43,
        *(_DWORD *)(*(_DWORD *)(a2 + 92) + 60),
        4004,
        "program too complex; there are more active values than registers");
    return -2147467259;
  }
  while ( 1 )
  {
    v14 = *(_DWORD *)(a2 + 60);
    v15 = *(_DWORD *)(a2 + 64);
    v44 = 0;
    v40 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v48);
    v16 = 4 * v10[3];
    v17 = *(_DWORD *)(v14 + v16);
    v18 = *(_DWORD *)(a2 + 68) + 4 * *(_DWORD *)(v15 + v16);
    v38 = v17;
    v37 = v18;
    if ( v17 )
    {
      while ( 1 )
      {
        v19 = v40;
        if ( v40 == *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * *(_DWORD *)(v37 + 4 * v44)) )
          break;
        if ( ++v44 >= v38 )
        {
          v19 = v40;
          break;
        }
      }
      if ( v44 < v38 )
        goto LABEL_23;
    }
    else
    {
      v19 = v40;
    }
    if ( a5 == -1 )
      goto LABEL_52;
    v45 = 0;
    v20 = 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 4 * a5) + 12);
    v21 = *(_DWORD *)(v20 + v14);
    v22 = *(_DWORD *)(a2 + 68) + 4 * *(_DWORD *)(v20 + v15);
    if ( !v21 )
      goto LABEL_52;
    do
    {
      if ( v19 == *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * *(_DWORD *)(v22 + 4 * v45)) )
        break;
      ++v45;
    }
    while ( v45 < v21 );
    if ( v45 >= v21 )
    {
LABEL_52:
      v23 = sub_685948(v43, a2, a3, v19, a4, v35, v42);
      if ( v23 < v42 )
      {
        v41 = v19;
        v36[0] = v35[0];
        v36[1] = v35[1];
        v36[2] = v35[2];
        v42 = v23;
        v36[3] = v35[3];
        if ( !v23 )
          break;
      }
    }
LABEL_23:
    ++v48;
    v10 = v39;
    if ( v48 >= *(_DWORD *)(a2 + 44) )
      goto LABEL_27;
  }
  v10 = v39;
LABEL_27:
  if ( v42 == -1 )
    goto LABEL_28;
  v25 = v41;
  *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * v10[3]) = v41;
  if ( (*(_BYTE *)(v43 + 204) & 4) != 0 )
  {
    v26 = *(_DWORD *)(a2 + 36);
    if ( v25 < v26 )
    {
      v27 = *(_DWORD **)(a2 + 32);
      v28 = 0;
      while ( 1 )
      {
        ++v28;
        if ( *v27 == v25 )
          break;
        ++v27;
      }
      if ( v28 < v26 )
      {
        do
        {
          v29 = (_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v28++);
          *(v29 - 1) = *v29;
        }
        while ( v28 < *(_DWORD *)(a2 + 36) );
      }
      *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * *(_DWORD *)(a2 + 36) - 4) = v25;
    }
  }
  for ( i = 0; i < 4; ++i )
  {
    v30 = 4 * (i + 4 * v10[3]);
    v47 = *(_DWORD *)(v30 + *(_DWORD *)(a2 + 24));
    if ( v47 != -1 )
    {
      v31 = v36[i];
      *(_DWORD *)(v30 + *(_DWORD *)(a2 + 20)) = v31;
      v32 = (_DWORD *)(*(_DWORD *)(a2 + 28) + 4 * (v31 + 4 * v25));
      if ( *v32 != -1 )
      {
        do
        {
          v33 = 4 * *v32;
          if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + v33) + 88) <= *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 4 * v47)
                                                                                       + 88) )
            break;
          v32 = (_DWORD *)(*(_DWORD *)(v33 + *(_DWORD *)(v43 + 20)) + 48);
        }
        while ( *v32 != -1 );
        v25 = v41;
      }
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 20) + 4 * v47) + 48) = *v32;
      *v32 = v47;
    }
  }
LABEL_47:
  v34 = v10[2];
  if ( v34 == -1 )
    return 0;
  result = sub_68DD50(a2, v34, 0, -1, -1);
  if ( result >= 0 )
    return 0;
  return result;
}
