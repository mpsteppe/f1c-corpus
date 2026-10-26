int __thiscall sub_4F7EC0(_DWORD *this, char a2, char a3)
{
  int result; // eax
  int v5; // ebp
  int v6; // edi
  int v7; // ecx
  int v8; // eax

  result = this[72];
  v5 = 0;
  if ( result > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = v6 + this[73];
      if ( a2 )
        goto LABEL_11;
      if ( !a3 || !*(_BYTE *)(v7 + 11) || *this != ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
        break;
      sub_4F7DD0((_DWORD *)v7, 0);
LABEL_13:
      result = this[72];
      ++v5;
      v6 += 768;
      if ( v5 >= result )
        goto LABEL_14;
    }
    v8 = *(_DWORD *)dword_B640C8;
    if ( *(_DWORD *)dword_B640C8 != 6 && *(_DWORD *)dword_B640C8 )
LABEL_11:
      v8 = 1;
    else
      LOBYTE(v8) = 0;
    sub_4F7C90(v7, v8);
    goto LABEL_13;
  }
LABEL_14:
  if ( this[75] )
    result = sub_5DA8C0(0, 0);
  if ( a2 )
    this[3] |= 0x20u;
  this[3] &= 0xFFFFFFFC;
  return result;
}
