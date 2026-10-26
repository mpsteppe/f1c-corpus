int sub_590460()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  int result; // eax

  v0 = operator new(4u);
  v1 = v0;
  if ( v0 )
  {
    result = sub_5918B0(v0 + 1);
    *v1 = &off_5F64F0;
    dword_7E8E4C = (int)v1;
    dword_7E8E58 = (int)v1;
  }
  else
  {
    result = 0;
    dword_7E8E4C = 0;
    dword_7E8E58 = 0;
  }
  return result;
}
