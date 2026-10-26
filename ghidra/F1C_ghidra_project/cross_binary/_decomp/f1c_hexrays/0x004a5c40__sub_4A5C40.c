// f1c  0x004a5c40  size=60
int __thiscall sub_4A5C40(int *this)
{
  int v1; // edx
  int v2; // esi
  int v3; // eax
  int v4; // ecx

  v1 = *this;
  v2 = *(_DWORD *)(*this + 18596);
  v3 = 0;
  if ( dword_5C329C <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = dword_7C54F0[v3];
    if ( *(_DWORD *)(v4 + 18596) == v2 && v4 != v1 )
      break;
    if ( ++v3 >= dword_5C329C )
      return 0;
  }
  return *(_DWORD *)(v4 + 13392);
}
