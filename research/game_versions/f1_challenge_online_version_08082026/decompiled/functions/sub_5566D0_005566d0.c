int sub_5566D0()
{
  int v0; // esi
  double *v1; // edi
  int result; // eax

  dword_8B8E48 = 3;
  v0 = 0;
  v1 = (double *)&unk_8B6C28;
  do
  {
    sub_556260(v1, 1u);
    ++v0;
    result = dword_8B8E48 + 32;
    v1 = (double *)((char *)v1 + 76);
  }
  while ( v0 < dword_8B8E48 + 32 );
  return result;
}
