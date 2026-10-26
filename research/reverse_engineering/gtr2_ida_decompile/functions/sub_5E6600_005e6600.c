unsigned int __thiscall sub_5E6600(_DWORD *this, unsigned int *a2)
{
  int v3; // ebx
  unsigned int **v4; // eax
  int *v5; // ecx
  unsigned int **v6; // eax
  unsigned int v7; // ecx
  unsigned int result; // eax

  v3 = this[15];
  v4 = *(unsigned int ***)(v3 + 596);
  v5 = (int *)(v3 + 596);
  if ( v4 )
  {
    while ( !*v4 || *v4 != a2 )
    {
      v4 = (unsigned int **)v4[1];
      if ( !v4 )
        goto LABEL_7;
    }
    if ( *v4 )
      goto LABEL_13;
  }
LABEL_7:
  v6 = *(unsigned int ***)(v3 + 612);
  v5 = (int *)(v3 + 612);
  if ( v6 )
  {
    while ( !*v6 || *v6 != a2 )
    {
      v6 = (unsigned int **)v6[1];
      if ( !v6 )
        goto LABEL_14;
    }
    if ( *v6 )
LABEL_13:
      sub_5DB630(v5, (int)a2, 0);
  }
LABEL_14:
  a2[16] = (unsigned int)this;
  sub_5FDFB0(a2, 1);
  v7 = a2[11];
  result = *a2 & 0xFFFFFFF3 | 4;
  *a2 = result;
  if ( v7 )
  {
    sub_5FEB00();
    result = sub_5FFC10(a2[11], 1);
    *this |= 0x40u;
  }
  return result;
}
