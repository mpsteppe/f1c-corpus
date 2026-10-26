int __thiscall sub_4EE360(int this, _DWORD *a2, int a3)
{
  int *v4; // edi
  int v5; // ebp
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int result; // eax
  float v22; // [esp+0h] [ebp-18h]
  float *v23; // [esp+20h] [ebp+8h]

  if ( *(float *)&a3 == -3.4028235e38 )
    *(float *)&a3 = dbl_7DA9D0;
  else
    sub_51CCB0(*(float *)&a3);
  sub_4D0D00(a2, 1, 0, 52, *(_DWORD *)(this + 25248), a3, 0);
  v4 = a2 + 2;
  a2[9] = *(_DWORD *)(this + 1976);
  a2[10] = *(_DWORD *)(this + 1980);
  a2[11] = *(_DWORD *)(this + 1984);
  a2[12] = *(_DWORD *)(this + 1912);
  a2[13] = *(_DWORD *)(this + 1916);
  a2[14] = *(_DWORD *)(this + 1920);
  sub_4CFA90(a2 + 6, (float *)(this + 17628));
  sub_4CFC00((int)(a2 + 6), (float *)(this + 17652));
  sub_4CFE90((int)(a2 + 2), (float *)(this + 17700));
  v5 = 0;
  v6 = 0;
  v23 = (float *)(this + 17824);
  do
  {
    v22 = *(float *)(v6 + this + 2240) + *(float *)(this + 1968);
    sub_4CFF90(v4, v5, v22, *v23);
    v6 += 304;
    ++v5;
    v23 += 62;
  }
  while ( v6 < 1216 );
  sub_4D02B0(v4, *(float *)(this + 18820));
  v7 = *v4;
  if ( *(_BYTE *)(this + 20812) )
    v8 = v7 | 0x10000;
  else
    v8 = v7 & 0xFFFEFFFF;
  *v4 = v8;
  sub_4D0340(v4, *(float *)(this + 17760));
  sub_4D0390(v4, *(_DWORD *)(this + 18912));
  v9 = *v4;
  if ( *(_BYTE *)(this + 21121) )
    v10 = v9 | 0x80;
  else
    v10 = v9 & 0xFFFFFF7F;
  *v4 = v10;
  sub_4D03C0((unsigned int *)v4, *(float *)(this + 17764));
  sub_4D0410(v4, this + 1892);
  v11 = a2[3];
  if ( *(_BYTE *)(this + 4769) )
    v12 = v11 | 0x8000000;
  else
    v12 = v11 & 0xF7FFFFFF;
  a2[3] = v12;
  v13 = a2[3];
  if ( *(float *)(this + 17768) <= 0.0099999998 )
    v14 = v13 & 0xFBFFFFFF;
  else
    v14 = v13 | 0x4000000;
  a2[3] = v14;
  v15 = a2[3];
  if ( *(_BYTE *)(this + 17412) )
    v16 = v15 | 0x2000000;
  else
    v16 = v15 & 0xFDFFFFFF;
  a2[3] = v16;
  if ( (*(_DWORD *)(this + 25296) & 2) != 0 )
    v17 = v16 | 0x1000000;
  else
    v17 = v16 & 0xFEFFFFFF;
  a2[3] = v17;
  v18 = sub_4EED90(this);
  sub_4D0500(v4, v18);
  sub_4D0530(v4, *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248));
  v19 = !sub_4DEB10((_DWORD *)(this + 20836));
  v20 = a2[3];
  if ( v19 )
    result = v20 & 0x7FFFFFFF;
  else
    result = v20 | 0x80000000;
  a2[3] = result;
  return result;
}
