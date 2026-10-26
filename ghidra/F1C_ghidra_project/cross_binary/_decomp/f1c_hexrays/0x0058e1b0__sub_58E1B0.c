// f1c  0x0058e1b0  size=123
char *__cdecl sub_58E1B0(_DWORD *a1)
{
  _DWORD *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = a1;
  if ( ((unsigned __int8)a1 & 3) == 0 )
    goto LABEL_4;
  do
  {
    v2 = *(_BYTE *)v1;
    v1 = (_DWORD *)((char *)v1 + 1);
    if ( !v2 )
      return (char *)((char *)v1 - 1 - (char *)a1);
  }
  while ( ((unsigned __int8)v1 & 3) != 0 );
  while ( 1 )
  {
    do
    {
LABEL_4:
      v3 = (*v1 + 2130640639) ^ ~*v1;
      ++v1;
    }
    while ( (v3 & 0x81010100) == 0 );
    v4 = *(v1 - 1);
    if ( !(_BYTE)v4 )
      break;
    if ( !BYTE1(v4) )
      return (char *)((char *)v1 - 3 - (char *)a1);
    if ( (v4 & 0xFF0000) == 0 )
      return (char *)((char *)v1 - 2 - (char *)a1);
    if ( (v4 & 0xFF000000) == 0 )
      return (char *)((char *)v1 - 1 - (char *)a1);
  }
  return (char *)((char *)(v1 - 1) - (char *)a1);
}
