int __thiscall sub_4B82D0(_DWORD *this)
{
  int v1; // edx
  int v2; // esi
  __int16 *v3; // edi
  int result; // eax
  int v5; // ecx

  v1 = -1;
  if ( ((dword_761FF8 & 1) == 0 || (byte_762119 & 2) == 0) && ((dword_761FF8 & 1) == 0 || (byte_762199 & 2) == 0) )
  {
    v2 = 0;
    v3 = word_762A08;
    while ( v2 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
    {
      switch ( *v3 )
      {
        case '>':
          v1 = 0;
          ++v2;
          ++v3;
          break;
        case '?':
          ++v2;
          v1 = 1;
          ++v3;
          break;
        case '@':
          v1 = 2;
          ++v2;
          ++v3;
          break;
        case 'A':
          ++v2;
          v1 = 3;
          ++v3;
          break;
        case 'B':
          v1 = 4;
          goto LABEL_13;
        default:
LABEL_13:
          ++v2;
          ++v3;
          break;
      }
    }
  }
  if ( dword_75CBB0 != 5 && dword_75CBB0 != 7 )
  {
    if ( v1 == 2 )
      v1 = -1;
    if ( this[6] == 2 )
      this[6] = -1;
  }
  if ( v1 >= 0 )
  {
    if ( v1 == this[6] )
      this[6] = -1;
    else
      this[6] = v1;
  }
  result = this[6];
  if ( result >= 0 )
  {
    v5 = this[result + 1];
    if ( v5 )
      return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 16))(v5);
  }
  return result;
}
