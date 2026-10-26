int __thiscall sub_6825A9(_DWORD *this)
{
  unsigned int v2; // edi
  int i; // ebx
  int v4; // eax
  _WORD *v5; // ecx
  int v6; // ecx

  v2 = 0;
  for ( i = 0; v2 < this[3]; ++v2 )
  {
    v4 = this[6];
    v5 = *(_WORD **)(v4 + 4 * v2);
    if ( (v5[1] & 0xFFF0) != 0 )
      *(_DWORD *)(v4 + 4 * i++) = v5;
    else
      sub_66238F(v5, 1);
  }
  v6 = this[3];
  if ( i == v6 )
    return 1;
  memset((void *)(this[6] + 4 * i), 0, 4 * ((unsigned int)(4 * (v6 - i)) >> 2));
  this[3] = i;
  return 0;
}
