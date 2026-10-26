// f1c  0x00599dd9  size=136
int __thiscall sub_599DD9(_DWORD *this, _WORD *a2, int a3)
{
  int v5; // eax
  _WORD *v6; // ecx
  _WORD *v7; // edx
  int v9; // [esp+Ch] [ebp-4h]
  int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  while ( a3 > 0 )
  {
    v5 = this[8];
    v6 = *(_WORD **)v5;
    if ( *(_DWORD *)v5 && (v5 = (2 * *(_DWORD *)this[12]) >> 1, v5 > 0) )
    {
      if ( a3 < v5 )
        v5 = a3;
      v7 = a2;
      v10 = v5;
      do
      {
        *v6++ = *v7++;
        --v10;
      }
      while ( v10 );
      v9 += v5;
      a3 -= v5;
      a2 += v5;
      sub_59A428(v5);
    }
    else
    {
      LOWORD(v5) = *a2;
      if ( (*(unsigned __int16 (__thiscall **)(_DWORD *, int))(*this + 4))(this, v5) == 0xFFFF )
        return v9;
      ++a2;
      ++v9;
      --a3;
    }
  }
  return v9;
}
