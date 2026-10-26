// f1c  0x0054eaa0  size=32
_DWORD *sub_54EAA0()
{
  _DWORD *v0; // esi
  int v1; // edi
  _DWORD *result; // eax

  v0 = &unk_8C5F48;
  v1 = 1024;
  do
  {
    result = sub_548E00(v0);
    v0 += 6;
    --v1;
  }
  while ( v1 );
  return result;
}
