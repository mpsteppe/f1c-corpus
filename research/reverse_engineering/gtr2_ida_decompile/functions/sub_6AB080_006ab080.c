int __thiscall sub_6AB080(_DWORD *this, int a2, unsigned int *a3)
{
  unsigned int v3; // edx
  int v4; // eax

  v3 = *(unsigned __int8 *)(a2 + 109);
  v4 = (unsigned __int8)*(_DWORD *)(a2 + 108);
  switch ( v4 )
  {
    case 1:
      if ( v3 < this[10] )
      {
LABEL_3:
        *a3 = v3;
        return 0;
      }
      break;
    case 3:
      if ( v3 < this[15] )
      {
        v3 += 2;
        goto LABEL_3;
      }
      break;
    case 5:
      *a3 = 12;
      return 0;
  }
  return -2147467259;
}
