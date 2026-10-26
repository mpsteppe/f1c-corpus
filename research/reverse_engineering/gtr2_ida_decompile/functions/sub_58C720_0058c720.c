int __thiscall sub_58C720(_BYTE *this)
{
  _BYTE *v1; // ebx
  int result; // eax
  int v3; // esi
  _BYTE *v4; // edi
  _BYTE *v5; // ebp
  _DWORD *v6; // ecx

  v1 = this + 2200;
  if ( !this[252] )
    v1 = this + 2440;
  result = *((_DWORD *)v1 + 59);
  if ( result )
  {
    v3 = 0;
    v4 = this + 253;
    v5 = this + 312;
    do
    {
      *v4 = 1;
      *v5 = 0;
      result = *((_DWORD *)v1 + 59);
      v6 = *(_DWORD **)(v3 + result);
      if ( v6 )
      {
        if ( v6[5] == 1 )
          result = (*(int (__thiscall **)(_DWORD *))(*v6 + 8))(v6);
      }
      v3 += 4;
      ++v4;
      v5 += 32;
    }
    while ( v3 < 236 );
  }
  return result;
}
