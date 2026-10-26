int __thiscall std::streambuf::xsputn(_DWORD **this, unsigned __int8 *Src, int a3)
{
  void *v5; // eax
  signed int v6; // esi
  int v8; // [esp+4h] [ebp-4h]

  v8 = 0;
  while ( a3 > 0 )
  {
    v5 = (void *)*this[8];
    if ( v5 && (v6 = *this[12], v6 > 0) )
    {
      if ( a3 < v6 )
        v6 = a3;
      memcpy_0(v5, Src, v6);
      v8 += v6;
      a3 -= v6;
      *this[12] -= v6;
      Src += v6;
      *this[8] += v6;
    }
    else
    {
      if ( ((int (__thiscall *)(_DWORD **, _DWORD))(*this)[1])(this, *Src) == -1 )
        return v8;
      ++Src;
      ++v8;
      --a3;
    }
  }
  return v8;
}
