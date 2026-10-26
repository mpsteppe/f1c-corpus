int __thiscall sub_543E7F(int this, int a2, int a3, int a4)
{
  unsigned int v5; // esi
  int result; // eax
  _DWORD *v7; // edi
  void *v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edx
  int v17; // ecx
  _DWORD *v18; // edi
  _DWORD *v19; // esi
  unsigned int v20; // eax
  int v21; // esi
  unsigned int v22; // eax
  _DWORD *v23; // edx
  int v24; // ecx
  int v25; // esi
  _DWORD *v26; // esi
  int v27; // [esp+Ch] [ebp-18h]
  unsigned int v28; // [esp+Ch] [ebp-18h]
  unsigned int v29; // [esp+Ch] [ebp-18h]
  unsigned int j; // [esp+Ch] [ebp-18h]
  int v31; // [esp+10h] [ebp-14h]
  int v32; // [esp+10h] [ebp-14h]
  int v33; // [esp+10h] [ebp-14h]
  _DWORD *v34; // [esp+14h] [ebp-10h]
  unsigned int v35; // [esp+2Ch] [ebp+8h]
  _DWORD *v36; // [esp+2Ch] [ebp+8h]
  int v37; // [esp+30h] [ebp+Ch]
  _DWORD *v38; // [esp+30h] [ebp+Ch]
  unsigned int i; // [esp+34h] [ebp+10h]
  unsigned int v40; // [esp+34h] [ebp+10h]

  v5 = *(_DWORD *)(this + 4148) + a2;
  v37 = *(_DWORD *)(this + 4160) + a3;
  v35 = v5;
  if ( !*(_DWORD *)(this + 4288) )
  {
    result = (int)operator new(8 * *(_DWORD *)(this + 4268) * *(_DWORD *)(this + 4264));
    *(_DWORD *)(this + 4288) = result;
    if ( !result )
      return result;
    memset((void *)result, 0, 8 * *(_DWORD *)(this + 4268) * *(_DWORD *)(this + 4264));
  }
  v7 = (_DWORD *)(*(_DWORD *)(this + 4288)
                + 8
                * (((v5 - *(_DWORD *)(this + 4240)) >> 2) + *(_DWORD *)(this + 4264) * (v37 - *(_DWORD *)(this + 4252))));
  v34 = v7;
  if ( !v7[1] )
  {
    v27 = 16 * *(_DWORD *)(this + 4260);
    v8 = operator new(*(_DWORD *)(this + 4260) << 8);
    v31 = (int)v8;
    if ( v8 )
    {
      sub_53D688((int)v8, 16, v27, (int (__thiscall *)(int))sub_53D5B2);
      result = v31;
    }
    else
    {
      result = 0;
    }
    v7[1] = result;
    if ( !result )
      return result;
    *v7 = 0;
    ++*(_DWORD *)(this + 4284);
  }
  if ( !*v7 )
  {
    v9 = 4;
    if ( *(_DWORD *)(this + 4156) >= 4u )
      v9 = *(_DWORD *)(this + 4156);
    v10 = v5 & 3;
    if ( v10 < *(_DWORD *)(this + 4148) || v10 + 4 > v9 )
    {
      v13 = *(_DWORD *)(this + 4236);
      v14 = *(_DWORD *)(this + 24)
          + v37 * *(_DWORD *)(this + 4180)
          + *(_DWORD *)(this + 4224) * (v13 >> 2)
          + *(_DWORD *)(this + 4176) * (v5 >> 2);
      v32 = v34[1];
      v29 = v13;
      while ( v13 < *(_DWORD *)(this + 4244) )
      {
        (*(void (__cdecl **)(int, int))(this + 4228))(v32, v14);
        v14 += *(_DWORD *)(this + 4224);
        v32 += 256;
        v29 += 4;
        v13 = v29;
      }
      v7 = v34;
    }
    else
    {
      v28 = 4;
      if ( *(_DWORD *)(this + 4152) >= 4u )
        v28 = *(_DWORD *)(this + 4152);
      v11 = *(_DWORD *)(this + 4236);
      if ( v11 < *(_DWORD *)(this + 4144) )
        (*(void (__cdecl **)(_DWORD, unsigned int))(this + 4228))(
          v7[1],
          *(_DWORD *)(this + 24)
        + v37 * *(_DWORD *)(this + 4180)
        + *(_DWORD *)(this + 4176) * (v5 >> 2)
        + *(_DWORD *)(this + 4224) * (v11 >> 2));
      v12 = *(_DWORD *)(this + 4244);
      if ( v12 > v28 )
        (*(void (__cdecl **)(_DWORD, unsigned int))(this + 4228))(
          v7[1],
          *(_DWORD *)(this + 24)
        + v37 * *(_DWORD *)(this + 4180)
        + *(_DWORD *)(this + 4176) * (v5 >> 2)
        + *(_DWORD *)(this + 4224) * ((v12 - 4) >> 2));
    }
  }
  if ( *(_DWORD *)(this + 4168) )
    a4 = sub_543AE8((_DWORD *)this, a4);
  v15 = *(_DWORD *)(this + 4144) - *(_DWORD *)(this + 4236);
  v16 = v15 + *(_DWORD *)(this + 4184);
  v17 = (v5 - *(_DWORD *)(this + 4240)) & 3;
  if ( v15 < v16 )
  {
    do
    {
      v18 = (_DWORD *)(v34[1] + 16 * (v15 & 3 | (4 * (v17 | v15 & 0xFFFFFFFC))));
      v19 = (_DWORD *)a4;
      a4 += 16;
      *v18 = *v19++;
      *++v18 = *v19++;
      *++v18 = *v19;
      ++v15;
      v18[1] = v19[1];
    }
    while ( v15 < v16 );
    v5 = v35;
    v7 = v34;
  }
  result = (v5 - *(_DWORD *)(this + 4240)) & 3;
  if ( *(_DWORD *)(this + 4212) )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( (i & *(_DWORD *)(this + 4220)) == result )
        *v7 |= 1 << i;
    }
  }
  else
  {
    *v7 |= 1 << result;
  }
  if ( *v7 == 15 )
  {
    v20 = *(_DWORD *)(this + 4236);
    v21 = *(_DWORD *)(this + 24)
        + v37 * *(_DWORD *)(this + 4180)
        + *(_DWORD *)(this + 4224) * (v20 >> 2)
        + *(_DWORD *)(this + 4176) * (v5 >> 2);
    v38 = (_DWORD *)v7[1];
    for ( j = v20; ; v20 = j )
    {
      v33 = v21;
      if ( v20 >= *(_DWORD *)(this + 4244) )
        break;
      v22 = 0;
      if ( *(_DWORD *)(this + 4212) )
      {
        v23 = v38;
        do
        {
          v40 = 0;
          v24 = 4 * v22;
          v36 = v23;
          do
          {
            v25 = (*(_DWORD *)(this + 4216) & v40) + 4 * (v22 & *(_DWORD *)(this + 4220));
            if ( v24 != v25 )
            {
              v26 = &v38[4 * v25];
              *v36 = *v26++;
              v36[1] = *v26++;
              v36[2] = *v26;
              v36[3] = v26[1];
              v7 = v34;
            }
            ++v40;
            v36 += 4;
            ++v24;
          }
          while ( v40 < 4 );
          v23 = v36;
          ++v22;
        }
        while ( v22 < 4 );
      }
      (*(void (__cdecl **)(int, _DWORD *))(this + 4232))(v33, v38);
      v21 = *(_DWORD *)(this + 4224) + v33;
      v38 += 64;
      j += 4;
    }
    if ( (unsigned int)(v7 + 2) >= *(_DWORD *)(this + 4288) + 8 * *(_DWORD *)(this + 4264) * *(_DWORD *)(this + 4268)
      || v7[2]
      || v7[3] )
    {
      result = sub_5BE8AE();
      --*(_DWORD *)(this + 4284);
    }
    else
    {
      result = v7[1];
      v7[3] = result;
      v7[1] = 0;
    }
    v7[1] = 0;
  }
  return result;
}
