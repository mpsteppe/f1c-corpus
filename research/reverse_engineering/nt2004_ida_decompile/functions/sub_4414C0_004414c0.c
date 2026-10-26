_DWORD *__thiscall sub_4414C0(int this)
{
  int v1; // edi
  double *v2; // ebp
  int v3; // esi
  double *v4; // ebx
  _DWORD *result; // eax
  int i; // edx
  _DWORD *v7; // ecx
  float v8; // [esp+0h] [ebp-24h]
  float v9; // [esp+0h] [ebp-24h]
  float v10; // [esp+0h] [ebp-24h]
  float *v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]

  flt_75E880 = *(double *)(this + 8240);
  flt_75E884 = *(double *)(this + 8176);
  v1 = 0;
  v11 = (float *)&unk_75E8D8;
  v2 = (double *)(this + 1868);
  v12 = 4;
  do
  {
    v8 = *(v2 - 5);
    sub_434710((float *)&byte_75CBC8, v1, v8);
    v9 = *v2;
    sub_4347A0((float *)&byte_75CBC8, v1, v9);
    v3 = 0;
    v4 = v2 - 31;
    do
    {
      v10 = *v4;
      sub_4347C0((float *)&byte_75CBC8, v1, v3++, v10);
      ++v4;
    }
    while ( v3 < 3 );
    *v11++ = *(v2 - 26);
    ++v1;
    v2 += 157;
    --v12;
  }
  while ( v12 );
  sub_4FE670(&dword_7D78FC);
  sub_438010((_DWORD *)(this + 508));
  *(_DWORD *)(this + 8620) = 0;
  sub_581700(this + 6096);
  if ( *(_DWORD *)(this + 8096) )
    sub_5BE8AE(*(LPVOID *)(this + 8096));
  if ( *(_DWORD *)(this + 6224) )
    sub_5BE8AE(*(LPVOID *)(this + 6224));
  memset((void *)this, 0, 0x2214u);
  *(_DWORD *)(this + 8240) = 1546188227;
  *(_DWORD *)(this + 8176) = 1546188227;
  *(_DWORD *)(this + 8244) = 1081234063;
  *(_DWORD *)(this + 8180) = 1081234063;
  result = (_DWORD *)(this + 1828);
  for ( i = 0; i < 4; ++i )
  {
    *(result - 260) = i;
    *result = 1546188227;
    result[1] = 1081234063;
    result[10] = 824633721;
    result[11] = 1067232264;
    *(result - 52) = 1546188227;
    *(result - 51) = 1081234063;
    v7 = result - 50;
    *v7 = *(result - 52);
    v7[1] = *(result - 51);
    v7[2] = *v7;
    v7[3] = *(result - 49);
    *(result - 42) = 0;
    *(result - 41) = 1080254464;
    result += 314;
  }
  return result;
}
