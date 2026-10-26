char __thiscall sub_463540(int this, char *a2, int *a3)
{
  int v3; // eax
  unsigned int v4; // eax
  char *v5; // eax
  int v6; // edx
  char v7; // cl
  char result; // al
  char *retaddr; // [esp+0h] [ebp+0h]

  if ( (*(_BYTE *)(this + 640) & 1) == 0 || *(int *)(this + 3212) <= 0 )
    return 0;
  v3 = *(unsigned __int8 *)(this + 3216);
  *a3 = v3;
  if ( v3 > 128 )
  {
    v4 = v3 - 128;
    if ( v4 < 0x58 )
    {
      v5 = &asc_758958[16 * v4];
      v6 = a2 - v5;
      do
      {
        v7 = *v5;
        v5[v6] = *v5;
        ++v5;
      }
      while ( v7 );
      return 1;
    }
    return 0;
  }
  if ( (unsigned int)v3 >= 0x5A )
    return 0;
  switch ( v3 )
  {
    case 0:
    case 1:
    case 14:
    case 15:
    case 28:
    case 29:
    case 42:
      strcpy(a2, &aPause[16 * v3]);
      result = 1;
      break;
    default:
      if ( v3 >= 54 )
      {
        strcpy(a2, &aPause[16 * v3]);
      }
      else
      {
        String[4] = sub_45E670();
        strcpy(retaddr, _strupr(String));
      }
      result = 1;
      break;
  }
  return result;
}
