int __thiscall sub_4DC900(_DWORD *this, int a2)
{
  int v3; // eax
  char v4; // cl

  v3 = this[16];
  if ( v3 >= 4 )
  {
    this[3 * v3 + 16] += *(char *)(a2 + 8);
  }
  else
  {
    if ( !v3 )
    {
      if ( *(_BYTE *)(a2 + 8) == 3 )
        this[18] = 8;
      else
        this[18] = 4;
      this[3 * this[16] + 19] = *(char *)(a2 + 9);
      this[3 * this[16]++ + 17] = *(char *)(a2 + 8);
      goto LABEL_14;
    }
    v4 = *(_BYTE *)(a2 + 8);
    if ( v4 == 1 )
    {
      if ( this[17] == 1 )
      {
        this[19] += 15;
        goto LABEL_14;
      }
      goto LABEL_12;
    }
    if ( this[17] != 1 && v4 == 2 )
    {
LABEL_12:
      this[18] = 4;
      this[19] = *(char *)(a2 + 9);
      this[17] = *(char *)(a2 + 8);
    }
  }
LABEL_14:
  if ( this[14] )
    sub_4DFED0(this);
  return sub_4C0AD0((_DWORD *)(*this + 16588), 1);
}
