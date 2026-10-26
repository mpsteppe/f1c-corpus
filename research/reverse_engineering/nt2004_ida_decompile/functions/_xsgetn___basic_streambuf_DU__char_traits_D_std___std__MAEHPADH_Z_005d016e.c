int __thiscall std::streambuf::xsgetn(_DWORD **this, char *a2, int a3)
{
  const void *v5; // eax
  signed int v6; // esi
  int v7; // eax
  int v9; // [esp+4h] [ebp-4h]

  v9 = 0;
  while ( a3 > 0 )
  {
    v5 = (const void *)*this[7];
    if ( v5 && (v6 = *this[11], v6 > 0) )
    {
      if ( a3 < v6 )
        v6 = a3;
      memcpy_0(a2, v5, v6);
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
