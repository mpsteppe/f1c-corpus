void *sub_4D2560()
{
  void *result; // eax
  char *v1; // edx
  int v2; // esi
  _DWORD *v3; // edx
  int v4; // esi

  result = &unk_7D4490;
  v1 = (char *)&unk_7D4590;
  v2 = 256;
  do
  {
    *(_DWORD *)v1 = -1082130432;
    v1[4] = 0;
    v1 += 8;
    --v2;
  }
  while ( v2 );
  v3 = &unk_7D4D90;
  v4 = 256;
  do
  {
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  dword_7D5D90 = 0;
  unk_7D5D98 = 0;
  unk_7D5D9C = -1;
  return result;
}
