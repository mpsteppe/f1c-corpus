_DWORD *ArithmeticComparison_c2d0()
{
  _DWORD *v0; // esi
  int v1; // edi
  _DWORD *result; // eax

  v0 = &unk_8BF740;
  v1 = 256;
  do
  {
    result = F_10FloatStructInitializer(v0);
    v0 += 26;
    --v1;
  }
  while ( v1 );
  return result;
}

