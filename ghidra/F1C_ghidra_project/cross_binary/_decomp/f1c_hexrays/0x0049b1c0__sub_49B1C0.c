// f1c  0x0049b1c0  size=60
int sub_49B1C0()
{
  int *v0; // esi
  int result; // eax
  void *v2; // edi

  v0 = dword_7CE23C;
  do
  {
    if ( *v0 )
    {
      result = sub_4DCD10(*v0);
      v2 = (void *)*v0;
      if ( *v0 )
      {
        sub_4DCD10(*v0);
        result = sub_587BCF(v2);
      }
      *v0 = 0;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&unk_7CE24C );
  return result;
}
