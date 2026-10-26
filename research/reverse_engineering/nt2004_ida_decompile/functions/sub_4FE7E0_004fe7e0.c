int sub_4FE7E0()
{
  int v0; // esi
  int v1; // edx
  char v2; // cl
  int v3; // eax
  int v4; // eax
  int v5; // edx
  char v6; // cl
  int v7; // esi
  char v8; // cl
  char Buffer; // [esp+Fh] [ebp-9h] BYREF
  float v11; // [esp+10h] [ebp-8h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF

  Buffer = 4;
  sub_4FEA10(&Buffer, 1u);
  v0 = 0;
  v1 = 0;
  v2 = 0;
  do
  {
    v3 = (unsigned __int8)byte_75E9C2[v1];
    if ( v1 == 5 && !*(_DWORD *)dword_766B6C )
      v3 = 1;
    v4 = v3 << v2;
    v2 += 2;
    v0 += v4;
    ++v1;
  }
  while ( v1 < 12 );
  v5 = *(_DWORD *)dword_7667D4 << v2;
  v6 = v2 + 2;
  v7 = (*(_DWORD *)dword_766AA4 << v6) + v5 + v0;
  v12 = v7;
  v8 = v6 + 1;
  if ( *(_DWORD *)(dword_75AACC + 4760) == 1 )
    v7 += 1 << v8;
  v12 = ((unsigned __int8)byte_7669B4 << (v8 + 2)) + ((unsigned __int8)byte_76699C << (v8 + 1)) + v7;
  sub_4FEA10(&v12, 4u);
  v11 = flt_7DAB00;
  sub_4FEA10(&v11, 4u);
  v11 = flt_7DAB04;
  sub_4FEA10(&v11, 4u);
  v11 = flt_7DAB08;
  sub_4FEA10(&v11, 4u);
  v11 = flt_7DAB0C + 273.16;
  sub_4FEA10(&v11, 4u);
  v11 = flt_7DAB10 + 273.16;
  return sub_4FEA10(&v11, 4u);
}
