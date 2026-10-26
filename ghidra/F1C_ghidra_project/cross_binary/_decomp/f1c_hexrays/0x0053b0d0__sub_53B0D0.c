// f1c  0x0053b0d0  size=59
int sub_53B0D0()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  int result; // eax

  v0 = (_DWORD *)sub_587C03(4);
  v1 = v0;
  if ( v0 )
  {
    result = sub_53C2A0(v0 + 1);
    *v1 = &off_5B8938;
    dword_8B8F18 = (int)v1;
    dword_8B8F24 = (int)v1;
  }
  else
  {
    result = 0;
    dword_8B8F18 = 0;
    dword_8B8F24 = 0;
  }
  return result;
}
