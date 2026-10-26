int __thiscall sub_56A1F0(_DWORD *this)
{
  int v2; // ecx
  int result; // eax

  v2 = *this;
  if ( v2 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 76))(v2);
    if ( *this )
      result = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*this + 68))(*this, 1);
    *this = 0;
  }
  return result;
}
