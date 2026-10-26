int __thiscall sub_6C7980(_DWORD *this)
{
  int v2; // eax
  int v3; // edx
  _DWORD *v4; // ecx
  int result; // eax
  unsigned int v6; // [esp+Ch] [ebp-4h]

  v2 = this[64];
  v6 = 0;
  if ( *(_DWORD *)(v2 + 4) )
  {
    v3 = this[5];
    v4 = *(_DWORD **)(v2 + 8);
    while ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(v3 + 4 * *v4) + 4)) + 5) & 2) == 0 )
    {
      ++v6;
      ++v4;
      if ( v6 >= *(_DWORD *)(this[64] + 4) )
        goto LABEL_5;
    }
    return 1;
  }
  else
  {
LABEL_5:
    this[87] = 0;
    result = sub_6C73E9((int)this, 0x100000, 0, *(char **)(v2 + 8), 0x100000, 0, 0);
    if ( result >= 0 )
      return sub_6BFA68(this);
  }
  return result;
}
