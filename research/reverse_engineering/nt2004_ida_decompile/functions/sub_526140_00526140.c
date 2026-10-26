int __thiscall sub_526140(_BYTE *this)
{
  _BYTE *v1; // ebx
  int v2; // esi
  _BYTE *v3; // ebp
  _BYTE *v4; // edi
  int result; // eax
  _DWORD *v6; // ecx

  v1 = this + 1664;
  if ( !this[176] )
    v1 = this + 1732;
  v2 = 0;
  v3 = this + 177;
  v4 = this + 224;
  do
  {
    *v3 = 1;
    *v4 = 0;
    result = *((_DWORD *)v1 + 16);
    v6 = *(_DWORD **)(v2 + result);
    if ( v6 )
    {
      if ( v6[5] == 1 )
        result = (*(int (__thiscall **)(_DWORD *))(*v6 + 8))(v6);
    }
    v4 += 32;
    v2 += 4;
    ++v3;
  }
  while ( v2 < 180 );
  return result;
}
