int __thiscall sub_4D0EC0(_DWORD *this, int a2)
{
  int v3; // ecx
  int result; // eax

  v3 = this[1];
  *this = a2;
  if ( v3 )
    result = sub_5506A0(a2, 0, 0);
  if ( this[2] )
    return sub_5506A0(a2, 0, 0);
  return result;
}

