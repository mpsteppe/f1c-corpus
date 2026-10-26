int __thiscall sub_4B8290(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi
  int result; // eax

  v2 = this + 1;
  v3 = 5;
  do
  {
    if ( *v2 )
    {
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 12))(*v2);
      if ( *v2 )
        result = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*v2 + 4))(*v2, 1);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  this[6] = -1;
  return result;
}
