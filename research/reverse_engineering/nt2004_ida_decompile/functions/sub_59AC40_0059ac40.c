_DWORD *sub_59AC40()
{
  _DWORD *v0; // esi
  int v1; // edi
  _DWORD *result; // eax

  v0 = &unk_7EF668;
  v1 = 256;
  do
  {
    result = sub_5904C0(v0);
    v0 += 26;
    --v1;
  }
  while ( v1 );
  return result;
}
