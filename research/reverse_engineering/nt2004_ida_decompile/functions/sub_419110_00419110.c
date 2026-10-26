int __thiscall sub_419110(_DWORD *this)
{
  int result; // eax
  int v3; // ecx

  *(_BYTE *)this = 0;
  this[1] = 0;
  result = sub_58DAB0();
  v3 = this[3];
  if ( v3 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 12))(v3);
  return result;
}
