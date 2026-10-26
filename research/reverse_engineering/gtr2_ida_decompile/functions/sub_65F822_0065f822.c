int __thiscall sub_65F822(_DWORD *this, int a2)
{
  int v3; // edi
  unsigned int v4; // edx
  unsigned int v5; // ecx
  int result; // eax
  int v7; // [esp-Ch] [ebp-14h]

  v3 = this[2];
  if ( !v3 )
    return 0;
  v4 = this[25];
  v5 = this[23];
  if ( v4 >= v5 )
    return 0;
  v7 = this[22] + 4 * v4;
  this[12] = a2;
  result = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, unsigned int))(*(_DWORD *)v3 + 16))(
             v3,
             *(_DWORD *)(a2 + 16),
             *(_DWORD *)(a2 + 20),
             v7,
             v5 - v4);
  if ( result < 0 )
  {
    this[19] = 1;
    this[20] = 1;
  }
  this[25] = this[23];
  return result;
}
