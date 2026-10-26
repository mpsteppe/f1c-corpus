// f1c  0x00598cf9  size=116
int __thiscall sub_598CF9(_DWORD **this, _BYTE *a2, int a3)
{
  _BYTE *v5; // eax
  signed int v6; // esi
  int v7; // eax
  int v9; // [esp+4h] [ebp-4h]

  v9 = 0;
  while ( a3 > 0 )
  {
    v5 = (_BYTE *)*this[7];
    if ( v5 && (v6 = *this[11], v6 > 0) )
    {
      if ( a3 < v6 )
        v6 = a3;
      sub_58CC00((unsigned int)a2, v5, v6);
      v9 += v6;
      a3 -= v6;
      *this[11] -= v6;
      a2 += v6;
      *this[7] += v6;
    }
    else
    {
      v7 = ((int (__thiscall *)(_DWORD **))(*this)[5])(this);
      if ( v7 == -1 )
        return v9;
      *a2++ = v7;
      ++v9;
      --a3;
    }
  }
  return v9;
}
