int __thiscall sub_599D52(_DWORD **this, _WORD *a2, int a3)
{
  _WORD *v5; // edx
  int v6; // eax
  _WORD *v7; // ecx
  __int16 v8; // ax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  v10 = 0;
  while ( a3 > 0 )
  {
    v5 = (_WORD *)*this[7];
    if ( v5 && (v6 = (2 * *this[11]) >> 1, v6 > 0) )
    {
      if ( a3 < v6 )
        v6 = a3;
      v7 = a2;
      v11 = v6;
      do
      {
        *v7++ = *v5++;
        --v11;
      }
      while ( v11 );
      v10 += v6;
      a3 -= v6;
      a2 += v6;
      PointerAdjustment(v6);
    }
    else
    {
      v8 = ((int (__thiscall *)(_DWORD **))(*this)[5])(this);
      if ( v8 == -1 )
        return v10;
      *a2++ = v8;
      ++v10;
      --a3;
    }
  }
  return v10;
}
