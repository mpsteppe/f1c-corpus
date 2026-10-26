int __thiscall sub_600A80(int *this, char a2)
{
  int result; // eax
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // edx

  result = *this;
  if ( a2 )
  {
    if ( (result & 1) != 0 )
      return result;
    v3 = result | 1;
  }
  else
  {
    if ( (result & 1) == 0 )
      return result;
    v3 = result & 0xFFFFFFFE;
  }
  *this = v3;
  result = this[5] - 2;
  switch ( this[5] )
  {
    case 2:
      v4 = this[57];
      v5 = *(_DWORD *)(v4 + 748);
      if ( a2 )
        result = v5 + 1;
      else
        result = v5 - 1;
      *(_DWORD *)(v4 + 748) = result;
      break;
    case 3:
      result = this[57];
      v6 = *(_DWORD *)(result + 768);
      if ( a2 )
        v7 = v6 + 1;
      else
        v7 = v6 - 1;
      *(_DWORD *)(result + 768) = v7;
      *(_DWORD *)this[57] |= (unsigned int)&dword_1000000;
      break;
    case 4:
      v8 = this[57];
      v9 = *(_DWORD *)(v8 + 808);
      if ( a2 )
        result = v9 + 1;
      else
        result = v9 - 1;
      *(_DWORD *)(v8 + 808) = result;
      break;
    case 5:
      result = this[57];
      v10 = *(_DWORD *)(result + 788);
      if ( a2 )
        v11 = v10 + 1;
      else
        v11 = v10 - 1;
      *(_DWORD *)(result + 788) = v11;
      *(_DWORD *)this[57] |= (unsigned int)&dword_2000000;
      break;
    default:
      return result;
  }
  return result;
}
