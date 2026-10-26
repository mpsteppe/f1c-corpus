int __thiscall sub_4FBE60(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  int result; // eax

  if ( a2 )
  {
    v3 = (_DWORD *)this[2];
    if ( a2 != v3 )
    {
      if ( v3 )
      {
        return off_16C9294(a2);
      }
      else
      {
        this[2] = a2;
        return sub_4F7EC0(a2, 0, 0);
      }
    }
  }
  return result;
}
