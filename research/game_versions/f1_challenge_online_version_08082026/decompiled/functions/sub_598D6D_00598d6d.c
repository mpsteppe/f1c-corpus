int __thiscall sub_598D6D(_DWORD **this, _BYTE *a2, int a3)
{
  unsigned int v5; // eax
  signed int v6; // esi
  int v8; // [esp+4h] [ebp-4h]

  v8 = 0;
  while ( a3 > 0 )
  {
    v5 = *this[8];
    if ( v5 && (v6 = *this[12], v6 > 0) )
    {
      if ( a3 < v6 )
        v6 = a3;
      sub_58CC00(v5, a2, v6);
      v8 += v6;
      a3 -= v6;
      *this[12] -= v6;
      a2 += v6;
      *this[8] += v6;
    }
    else
    {
      if ( ((int (__thiscall *)(_DWORD **, _DWORD))(*this)[1])(this, (unsigned __int8)*a2) == -1 )
        return v8;
      ++a2;
      ++v8;
      --a3;
    }
  }
  return v8;
}
