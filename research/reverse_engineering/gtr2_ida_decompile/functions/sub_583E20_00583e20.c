// positive sp value has been detected, the output may be wrong!
void __usercall sub_583E20(void *a1@<ebx>, int a2@<ebp>, int a3@<edi>, void *a4@<esi>)
{
  int v4; // ecx
  int v5; // esi
  _DWORD *v6; // edi
  const CHAR *v7; // eax
  int v8; // edx
  _DWORD *v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // ebx
  int v12; // ecx
  int v13; // eax
  double v14; // st7
  int v15; // [esp-3C5Ch] [ebp-3C8Ch]
  int v16; // [esp-3C58h] [ebp-3C88h]
  void *v17[2]; // [esp-3C54h] [ebp-3C84h] BYREF
  _DWORD v19[59]; // [esp-3C48h] [ebp-3C78h] BYREF
  double v20; // [esp-3B5Ch] [ebp-3B8Ch]
  int v21; // [esp-1E84h] [ebp-1EB4h] BYREF
  _BYTE v22[92]; // [esp-1E78h] [ebp-1EA8h] BYREF
  void *v23; // [esp-1E1Ch] [ebp-1E4Ch]
  _DWORD v24[241]; // [esp-394h] [ebp-3C4h] BYREF

  sub_631BD0();
  v17[1] = a1;
  v17[0] = a4;
  v5 = v4;
  sub_574690();
  if ( *(_DWORD *)(v5 + 14804) <= 4u )
  {
    v15 = a3;
    if ( *(_DWORD *)v5 == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
      sub_457850(dword_91E084, v5, *(_DWORD *)v5, a3);
    sub_435800(v15, a2);
    sub_5875F0(v19);
    v6 = (_DWORD *)(dword_BE1BD8 + 2824 * *(_DWORD *)(*(_DWORD *)v5 + 22472));
    v7 = (const CHAR *)v6[2];
    if ( !v7 )
      v7 = WindowName;
    sub_5886A0(v7, v22, 0);
    v8 = *(_DWORD *)v5;
    if ( *(_DWORD *)v5 + 22212 + strlen((const char *)(*(_DWORD *)v5 + 22212)) + 1 - (*(_DWORD *)v5 + 22213) )
      sub_5886A0(v8 + 22212, v22, 1);
    sub_56E020();
    sub_56ACD0();
    if ( v6[70] > 4u )
      v6[70] = 0;
    *(_DWORD *)(v5 + 2924) = v6[70];
    v16 = 0;
    if ( (int)v6[70] > 0 )
    {
      v9 = (_DWORD *)(v5 + 2988);
      v10 = v6 + 83;
      do
      {
        v11 = v9 - 12;
        *v11 = *(v10 - 12);
        v11[1] = *(v10 - 11);
        v11[2] = *(v10 - 10);
        *v9 = *v10;
        v9[1] = v10[1];
        v9[2] = v10[2];
        v10 += 3;
        v9 += 3;
        ++v16;
      }
      while ( v16 < v6[70] );
    }
    v12 = v19[57];
    *(_DWORD *)(v5 + 2920) = v6[95];
    *(_DWORD *)(v5 + 3036) = -1082130432;
    *(_DWORD *)(v5 + 15912) = v12;
    if ( v12 >= 1 )
    {
      if ( v12 > 64 )
        *(_DWORD *)(v5 + 15912) = 64;
    }
    else
    {
      *(_DWORD *)(v5 + 15912) = 1;
    }
    v13 = 5 * *(_DWORD *)(v5 + 15912);
    *(float *)(v5 + 15916) = v20 * v20;
    v14 = 1.0 / (double)(8 * v13);
    *(float *)(v5 + 15920) = v14;
    *(float *)(v5 + 15924) = 1.0 / (double)(8 * v13 + 40);
    *(float *)(v5 + 15928) = v14;
    *(float *)(v5 + 15932) = dbl_FB1D18;
    sub_57FC70(v5, COERCE_FLOAT(&v21), (int)v17);
    sub_579710(v5, 0);
    sub_43A460(v17);
    v24[240] = 2;
    sub_431A70(v24);
    if ( v23 )
      j_j__free(v23);
  }
}
