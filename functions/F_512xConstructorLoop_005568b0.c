_DWORD *F_512xConstructorLoop()
{
  _DWORD *v0; // esi
  int v1; // edi
  _DWORD *result; // eax

  v0 = &unk_8CBF70;
  v1 = 512;
  do
  {
    result = ShortComputation_8e00(v0);
    v0 += 6;
    --v1;
  }
  while ( v1 );
  return result;
}
