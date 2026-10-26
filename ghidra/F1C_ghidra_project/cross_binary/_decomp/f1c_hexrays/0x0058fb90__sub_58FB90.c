// f1c  0x0058fb90  size=132
int __cdecl sub_58FB90(unsigned int *a1, _BYTE *a2)
{
  unsigned int *v2; // edx
  _BYTE *v3; // ecx
  unsigned int v4; // eax
  bool v5; // cf
  unsigned int v6; // eax
  __int16 v8; // ax

  v2 = a1;
  v3 = a2;
  if ( ((unsigned __int8)a1 & 3) == 0 )
  {
LABEL_2:
    while ( 1 )
    {
      v4 = *v2;
      v5 = (unsigned __int8)*v2 < *v3;
      if ( (unsigned __int8)*v2 != *v3 )
        break;
      if ( !(_BYTE)v4 )
        return 0;
      v5 = BYTE1(v4) < v3[1];
      if ( BYTE1(v4) != v3[1] )
        break;
      if ( !BYTE1(v4) )
        return 0;
      v6 = HIWORD(v4);
      v5 = (unsigned __int8)v6 < v3[2];
      if ( (_BYTE)v6 != v3[2] )
        break;
      if ( !(_BYTE)v6 )
        return 0;
      v5 = BYTE1(v6) < v3[3];
      if ( BYTE1(v6) != v3[3] )
        break;
      v3 += 4;
      ++v2;
      if ( !BYTE1(v6) )
        return 0;
    }
    return -2 * v5 + 1;
  }
  if ( ((unsigned __int8)a1 & 1) != 0 )
  {
    v2 = (unsigned int *)((char *)a1 + 1);
    v5 = *(_BYTE *)a1 < *a2;
    if ( *(_BYTE *)a1 != *a2 )
      return -2 * v5 + 1;
    v3 = a2 + 1;
    if ( !*(_BYTE *)a1 )
      return 0;
    if ( ((unsigned __int8)v2 & 2) == 0 )
      goto LABEL_2;
  }
  v8 = *(_WORD *)v2;
  v2 = (unsigned int *)((char *)v2 + 2);
  v5 = (unsigned __int8)v8 < *v3;
  if ( (_BYTE)v8 != *v3 )
    return -2 * v5 + 1;
  if ( !(_BYTE)v8 )
    return 0;
  v5 = HIBYTE(v8) < v3[1];
  if ( HIBYTE(v8) == v3[1] )
  {
    if ( HIBYTE(v8) )
    {
      v3 += 2;
      goto LABEL_2;
    }
    return 0;
  }
  return -2 * v5 + 1;
}
