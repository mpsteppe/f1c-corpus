char __stdcall sub_4DA590(_BYTE *a1)
{
  _BYTE *v1; // eax
  int v2; // esi

  v1 = a1;
  v2 = 256;
  do
  {
    *v1 = v1[byte_7D4490 - a1];
    ++v1;
    --v2;
  }
  while ( v2 );
  return 1;
}
