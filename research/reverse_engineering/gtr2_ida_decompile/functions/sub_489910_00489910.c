char __thiscall sub_489910(unsigned int **this, char **a2)
{
  unsigned int *v2; // ebx
  unsigned int v3; // edx
  unsigned int v4; // eax
  int v5; // edi
  _DWORD *i; // esi
  char v7; // cl

  v2 = *this;
  v3 = **this;
  v4 = v3 >> 29;
  v5 = 0;
  for ( i = (_DWORD *)(dword_B6D678 + 164); ; ++i )
  {
    if ( v4 == 4 && ((v3 >> 18) & 0x3F) < 2 )
      return 1;
    v7 = **a2;
    if ( (_BYTE)v3 == 0xFF )
    {
      if ( v7 != -1 )
        return 1;
    }
    else if ( v7 == -1 )
    {
      return 0;
    }
    if ( *i == v2[211] )
      break;
    if ( *i == *((_DWORD *)*a2 + 211) )
      return 1;
    if ( ++v5 >= 208 )
      return 1;
    v4 = v3 >> 29;
  }
  return 0;
}
