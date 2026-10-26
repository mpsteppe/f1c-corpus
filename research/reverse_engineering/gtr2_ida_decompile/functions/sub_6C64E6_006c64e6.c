int __thiscall sub_6C64E6(_DWORD *this)
{
  int v2; // edi
  unsigned int v3; // edx
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int result; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v2 = this[108];
  if ( !v2 )
    return 0;
  v3 = this[71];
  v4 = this[68];
  if ( v3 >= v4 || this[53] )
    return 0;
  v5 = this[64];
  v8 = 0;
  v9 = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 60);
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 4) == 13 )
      {
        v8 = *(_DWORD *)(v6 + 64);
        v9 = *(_DWORD *)(*(_DWORD *)(v5 + 60) + 68);
      }
    }
  }
  result = (*(int (__stdcall **)(int, int, int, unsigned int, unsigned int))(*(_DWORD *)v2 + 16))(
             v2,
             v8,
             v9,
             this[67] + 4 * v3,
             v4 - v3);
  this[71] = this[68];
  return result;
}
