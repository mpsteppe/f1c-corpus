BOOL __thiscall sub_67F7F0(_DWORD *this, int a2)
{
  BOOL result; // eax
  int v3; // edx
  int v4; // eax

  result = sub_67EC87(this, a2);
  if ( result )
  {
    v4 = *(_DWORD *)(v3 + 16);
    return v4 == *(_DWORD *)(a2 + 16)
        && (!memcmp((const void *)(v3 + 16), (const void *)(a2 + 16), 0x10u)
         || v4 == 4 && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(v3 + 24), *(_DWORD *)(a2 + 24)));
  }
  return result;
}
