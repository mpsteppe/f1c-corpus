int __thiscall sub_6A6C14(_DWORD *this)
{
  unsigned int v1; // ebx
  int v2; // esi
  _DWORD *v3; // edi
  int v4; // edx

  v1 = 0;
  v2 = 0;
  if ( !this[3] )
  {
LABEL_9:
    this[288] = v1;
    return 1 << v1;
  }
  v3 = this + 276;
  while ( 1 )
  {
    if ( !sub_6A2293(**(_DWORD **)(this[6] + 4 * v2) & 0xFFF00000) && v4 != 1913651200 && v4 != 285212672 )
      goto LABEL_8;
    if ( v1 >= 0xC )
      return -1;
    *v3 = v2;
    ++v1;
    ++v3;
LABEL_8:
    if ( (unsigned int)++v2 >= this[3] )
      goto LABEL_9;
  }
}
