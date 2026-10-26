_DWORD *sub_5AE06E()
{
  _DWORD *v0; // esi
  int v1; // edi
  _DWORD *result; // eax

  v0 = &unk_7FBEA8;
  v1 = 512;
  do
  {
    result = sub_594070(v0);
    v0 += 6;
    --v1;
  }
  while ( v1 );
  return result;
}
