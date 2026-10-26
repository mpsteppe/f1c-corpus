_WORD *sub_4B2620()
{
  int *v0; // esi
  _WORD *result; // eax
  int v2; // [esp+4h] [ebp-4h] BYREF

  v2 = (__int64)((double)dword_6152EC * 0.3334);
  v0 = (int *)&unk_765D30;
  do
  {
    result = sub_4B1C70(v0, &v2);
    v0 += 12;
  }
  while ( (int)v0 < (int)&dword_765E50 );
  return result;
}
