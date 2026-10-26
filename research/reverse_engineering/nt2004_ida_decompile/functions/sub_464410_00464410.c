int __thiscall sub_464410(int *this)
{
  int *v1; // esi
  int v2; // edx
  int v3; // esi
  int v4; // edx
  _DWORD *v5; // ecx
  int v6; // edi
  int v7; // ebx
  int v8; // ebp
  int *v9; // eax
  int *v10; // esi
  int **v11; // eax
  bool v12; // cc
  int v13; // eax
  int i; // ecx
  int v15; // edx
  int *v16; // ecx
  int *v17; // eax
  int v18; // ecx
  int v19; // eax
  int result; // eax
  int j; // esi
  LPVOID *v22; // edi
  char v23; // al
  int v24; // [esp+Ch] [ebp-20h]
  int v25; // [esp+10h] [ebp-1Ch]
  int v26; // [esp+14h] [ebp-18h]
  int **v28; // [esp+1Ch] [ebp-10h]
  int v29; // [esp+1Ch] [ebp-10h]
  int **v30; // [esp+20h] [ebp-Ch]
  int v31; // [esp+24h] [ebp-8h]
  int v32; // [esp+28h] [ebp-4h]

  v1 = this;
  v2 = *this;
  v28 = 0;
  v30 = 0;
  v32 = 0;
  v26 = 0;
  if ( *(int *)(*this + 6512) > 0 )
  {
    v3 = 0;
    v25 = 0;
    v24 = 6320;
    while ( 1 )
    {
      if ( sub_462C60((char *)(v3 + v2 + 752), 2) && *v5 == 2 )
        v6 = *(char *)(v3 + v4 + 852);
      else
        v6 = -1;
      v7 = *(_DWORD *)(v24 + v4);
      if ( v6 < 0 )
        v8 = -1;
      else
        v8 = dword_6310F4[6326 * v6];
      v9 = (int *)operator new(0xCu);
      v10 = v9;
      if ( v9 )
      {
        *v9 = v6;
        v9[1] = v7;
        v9[2] = v8;
        v11 = (int **)operator new(0xCu);
        if ( v11 )
        {
          *v11 = v10;
          v11[1] = 0;
          *((_BYTE *)v11 + 8) = 1;
        }
        else
        {
          v11 = 0;
        }
        if ( v28 )
          v30[1] = (int *)v11;
        else
          v28 = v11;
        v30 = v11;
        ++v32;
      }
      v25 += 116;
      v2 = *this;
      v12 = ++v26 < *(_DWORD *)(*this + 6512);
      v24 += 4;
      if ( !v12 )
        break;
      v3 = v25;
    }
    v1 = this;
  }
  v13 = sub_466810(v28);
  v29 = v13;
  if ( v13 )
  {
    for ( i = *(_DWORD *)(v13 + 4); i; i = *(_DWORD *)(i + 4) )
      ;
  }
  v15 = 0;
  v16 = dword_6310F4;
  do
  {
    *v16 = ++v15;
    v16 += 6326;
  }
  while ( (int)v16 < (int)dword_759974 );
  v31 = v13;
  if ( v13 )
    v17 = *(int **)v13;
  else
    v17 = 0;
  v18 = 1;
  if ( v17 )
  {
    do
    {
      *(_DWORD *)(*v1 + 4 * v18 + 6738) = v17[1];
      v19 = *v17;
      if ( v19 >= 0 )
        dword_6310F4[6326 * v19] = v18;
      ++v18;
      if ( !v31 )
        break;
      v31 = *(_DWORD *)(v31 + 4);
      if ( !v31 )
        break;
      v17 = *(int **)v31;
    }
    while ( *(_DWORD *)v31 );
  }
  result = *v1;
  *(_BYTE *)(*v1 + 6741) = v18 - 1;
  for ( j = v29; j; result = sub_5BE8AE(v22) )
  {
    v22 = (LPVOID *)j;
    v23 = *(_BYTE *)(j + 8);
    j = *(_DWORD *)(j + 4);
    if ( v23 )
      sub_5BE8AE(*v22);
  }
  return result;
}
