unsigned int __userpurge sub_50B47E@<eax>(float *a1@<ebp>, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // edi
  unsigned int result; // eax
  unsigned int v9; // edx
  unsigned int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // ebx
  unsigned int v14; // edx
  _DWORD *v15; // edi
  _DWORD *v16; // esi
  unsigned int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  float *v21; // ecx
  _DWORD *v22; // edi

  sub_58A5D8();
  *((_DWORD *)a1 - 4) = v4;
  *((_DWORD *)a1 + 2) += *(_DWORD *)(v4 + 4148);
  *((_DWORD *)a1 + 3) += *(_DWORD *)(v4 + 4160);
  if ( !*(_DWORD *)(v4 + 4280) )
  {
    v5 = 16 * *(_DWORD *)(v4 + 4260);
    v6 = sub_587C03(*(_DWORD *)(v4 + 4260) << 8);
    v7 = v6;
    *((_DWORD *)a1 - 9) = v6;
    *(a1 - 1) = 0.0;
    if ( v6 )
      sub_5008C2(v6, 16, v5, (int (__thiscall *)(int))sub_5007EC);
    else
      v7 = 0;
    *(a1 - 1) = NAN;
    result = *((_DWORD *)a1 - 4);
    *(_DWORD *)(result + 4280) = v7;
    if ( !v7 )
      return result;
    v4 = *((_DWORD *)a1 - 4);
  }
  v9 = (_DWORD)a1[2] & 0xFFFFFFFC;
  if ( v9 != *(_DWORD *)(v4 + 4272) || *((_DWORD *)a1 + 3) != *(_DWORD *)(v4 + 4276) )
  {
    *(_DWORD *)(v4 + 4272) = v9;
    *(float *)(*((_DWORD *)a1 - 4) + 4276) = a1[3];
    v4 = *((_DWORD *)a1 - 4);
    v10 = *(_DWORD *)(v4 + 4236);
    v11 = *(_DWORD *)(v4 + 4280);
    v12 = *(_DWORD *)(v4 + 24)
        + *(_DWORD *)(v4 + 4180) * *(_DWORD *)(v4 + 4276)
        + *(_DWORD *)(v4 + 4224) * (v10 >> 2)
        + *(_DWORD *)(v4 + 4176) * (*(_DWORD *)(v4 + 4272) >> 2);
    while ( v10 < *(_DWORD *)(v4 + 4244) )
    {
      (*(void (__cdecl **)(int, int))(v4 + 4228))(v11, v12);
      v4 = *((_DWORD *)a1 - 4);
      v12 += *(_DWORD *)(v4 + 4224);
      v11 += 256;
      v10 += 4;
    }
  }
  result = *(_DWORD *)(v4 + 4144) - *(_DWORD *)(v4 + 4236);
  v13 = (*((_DWORD *)a1 + 2) - *(_DWORD *)(v4 + 4240)) & 3;
  v14 = result + *(_DWORD *)(v4 + 4184);
  while ( result < v14 )
  {
    v15 = (_DWORD *)*((_DWORD *)a1 + 4);
    v16 = (_DWORD *)(*(_DWORD *)(v4 + 4280) + 16 * (result & 3 | (4 * (v13 | result & 0xFFFFFFFC))));
    *v15 = *v16++;
    *++v15 = *v16++;
    *++v15 = *v16;
    v15[1] = v16[1];
    *((_DWORD *)a1 + 4) += 16;
    v4 = *((_DWORD *)a1 - 4);
    ++result;
  }
  if ( *(_DWORD *)(v4 + 16) )
  {
    sub_507473();
    while ( *((_DWORD *)a1 + 4) < v17 )
    {
      *(a1 - 5) = **((float **)a1 + 4) * 31.0 + 0.5;
      *((_DWORD *)a1 - 6) = (int)*(a1 - 5);
      *(a1 - 5) = *(a1 - 6);
      v18 = *((_DWORD *)a1 + 4);
      *(a1 - 13) = (double)*((int *)a1 - 5) * 0.032258064;
      *(a1 - 5) = *(float *)(v18 + 4) * 63.0 + 0.5;
      *((_DWORD *)a1 - 7) = (int)*(a1 - 5);
      *(a1 - 5) = *(a1 - 7);
      v19 = *((_DWORD *)a1 + 4);
      *(a1 - 12) = (double)*((int *)a1 - 5) * 0.015873017;
      *(a1 - 5) = *(float *)(v19 + 8) * 31.0 + 0.5;
      *((_DWORD *)a1 - 8) = (int)*(a1 - 5);
      *(a1 - 5) = *(a1 - 8);
      v20 = *((_DWORD *)a1 - 4);
      *(a1 - 11) = (double)*((int *)a1 - 5) * 0.032258064;
      *(a1 - 5) = *(float *)(v20 + 4204) * *(float *)(*((_DWORD *)a1 + 4) + 12) + 0.5;
      *((_DWORD *)a1 - 9) = (int)*(a1 - 5);
      v21 = (float *)*((_DWORD *)a1 - 4);
      *(a1 - 5) = *(a1 - 9);
      if ( *(a1 - 13) == v21[7]
        && *(a1 - 12) == v21[8]
        && *(a1 - 11) == v21[9]
        && (double)*((int *)a1 - 5) * v21[1052] == v21[10] )
      {
        v22 = (_DWORD *)*((_DWORD *)a1 + 4);
        *(a1 - 17) = 0.0;
        *(a1 - 16) = 0.0;
        *(a1 - 15) = 0.0;
        *(a1 - 14) = 0.0;
        *v22++ = *((_DWORD *)a1 - 17);
        *v22++ = *((_DWORD *)a1 - 16);
        *v22 = *((_DWORD *)a1 - 15);
        v22[1] = *((_DWORD *)a1 - 14);
      }
      *((_DWORD *)a1 + 4) += 16;
    }
    result = dword_8B009C;
    *((_DWORD *)a1 - 9) = dword_8B009C;
  }
  return result;
}
