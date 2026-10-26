int __thiscall sub_42F7D0(_DWORD *this, int a2)
{
  _DWORD *v3; // ecx
  int result; // eax

  v3 = (_DWORD *)this[4];
  result = v3[27];
  if ( this[5] != result )
  {
    if ( dword_6F3A68[result] == -1 )
    {
      return sub_54B280(v3 + 15);
    }
    else
    {
      this[5] = result;
      return sub_4092C0(v3, dword_6F3A68[result]);
    }
  }
  return result;
}
