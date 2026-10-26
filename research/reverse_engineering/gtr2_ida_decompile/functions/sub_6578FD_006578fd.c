void __thiscall sub_6578FD(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // edx
  _DWORD *v7; // esi
  _DWORD *v8; // edi

  v4 = (unsigned __int8 *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *v8 = v7[1] )
  {
    v7 = (_DWORD *)(this[14] + 16 * *v4);
    *a4 = *v7++;
    a4[1] = *v7++;
    a4[2] = *v7;
    v8 = a4 + 3;
    ++v4;
    a4 += 4;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
