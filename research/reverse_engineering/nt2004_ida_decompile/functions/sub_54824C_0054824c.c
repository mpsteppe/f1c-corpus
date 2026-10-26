unsigned int __thiscall sub_54824C(unsigned int this, int a2, int a3, float *a4)
{
  int v4; // esi
  void *v5; // eax
  void *v6; // edi
  unsigned int result; // eax
  unsigned int v8; // edi
  int v9; // ebx
  int v10; // esi
  int v11; // ebx
  unsigned int v12; // edx
  float *v13; // esi
  unsigned int v14; // edx
  float v15; // [esp+18h] [ebp-34h]
  float v16; // [esp+1Ch] [ebp-30h]
  float v17; // [esp+20h] [ebp-2Ch]
  float v18; // [esp+38h] [ebp-14h]
  float v19; // [esp+38h] [ebp-14h]
  float v20; // [esp+38h] [ebp-14h]
  float v21; // [esp+38h] [ebp-14h]
  unsigned int v22; // [esp+3Ch] [ebp-10h]
  int v23; // [esp+54h] [ebp+8h]
  int v24; // [esp+58h] [ebp+Ch]

  v22 = this;
  v23 = *(_DWORD *)(this + 4148) + a2;
  v24 = *(_DWORD *)(this + 4160) + a3;
  if ( !*(_DWORD *)(this + 4280) )
  {
    v4 = 16 * *(_DWORD *)(this + 4260);
    v5 = operator new(*(_DWORD *)(this + 4260) << 8);
    v6 = v5;
    if ( v5 )
      sub_53D688((int)v5, 16, v4, (int (__thiscall *)(int))sub_53D5B2);
    else
      v6 = 0;
    result = v22;
    *(_DWORD *)(v22 + 4280) = v6;
    if ( !v6 )
      return result;
    this = v22;
  }
  if ( (v23 & 0xFFFFFFFC) != *(_DWORD *)(this + 4272) || v24 != *(_DWORD *)(this + 4276) )
  {
    *(_DWORD *)(this + 4272) = v23 & 0xFFFFFFFC;
    *(_DWORD *)(v22 + 4276) = v24;
    this = v22;
    v8 = *(_DWORD *)(v22 + 4236);
    v9 = *(_DWORD *)(v22 + 4280);
    v10 = *(_DWORD *)(v22 + 24)
        + *(_DWORD *)(v22 + 4180) * *(_DWORD *)(v22 + 4276)
        + *(_DWORD *)(v22 + 4224) * (v8 >> 2)
        + *(_DWORD *)(v22 + 4176) * (*(_DWORD *)(v22 + 4272) >> 2);
    while ( v8 < *(_DWORD *)(this + 4244) )
    {
      (*(void (__cdecl **)(int, int))(this + 4228))(v9, v10);
      this = v22;
      v10 += *(_DWORD *)(v22 + 4224);
      v9 += 256;
      v8 += 4;
    }
  }
  result = *(_DWORD *)(this + 4144) - *(_DWORD *)(this + 4236);
  v11 = (v23 - *(_DWORD *)(this + 4240)) & 3;
  v12 = result + *(_DWORD *)(this + 4184);
  while ( result < v12 )
  {
    v13 = (float *)(*(_DWORD *)(this + 4280) + 16 * (result & 3 | (4 * (v11 | result & 0xFFFFFFFC))));
    *a4 = *v13++;
    a4[1] = *v13++;
    a4[2] = *v13;
    a4[3] = v13[1];
    a4 += 4;
    this = v22;
    ++result;
  }
  if ( *(_DWORD *)(this + 16) )
  {
    sub_544279();
    while ( (unsigned int)a4 < v14 )
    {
      v18 = *a4 * 31.0 + 0.5;
      v15 = (double)(int)v18 * 0.032258064;
      if ( v15 == *(float *)(v22 + 28) )
      {
        v19 = a4[1] * 63.0 + 0.5;
        v16 = (double)(int)v19 * 0.015873017;
        if ( v16 == *(float *)(v22 + 32) )
        {
          v20 = a4[2] * 31.0 + 0.5;
          v17 = (double)(int)v20 * 0.032258064;
          if ( v17 == *(float *)(v22 + 36) )
          {
            v21 = *(float *)(v22 + 4204) * a4[3] + 0.5;
            if ( (double)(int)v21 * *(float *)(v22 + 4208) == *(float *)(v22 + 40) )
            {
              *a4 = 0.0;
              a4[1] = 0.0;
              a4[2] = 0.0;
              a4[3] = 0.0;
            }
          }
        }
      }
      a4 += 4;
    }
    return dword_7E0598;
  }
  return result;
}
