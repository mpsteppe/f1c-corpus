int __thiscall sub_5434A0(_DWORD *this, float a2, signed int a3, float a4, float a5, int a6)
{
  double v7; // st7
  int v8; // eax
  double v9; // st6
  int result; // eax
  int v11; // [esp+4h] [ebp-8h] BYREF
  int v12; // [esp+8h] [ebp-4h] BYREF

  v7 = (double)(int)this[7];
  v8 = CRTFtol(v7);
  v9 = (double)(int)this[8];
  v12 = v8;
  a2 = v9;
  v11 = CRTFtol(v7);
  *(float *)&a3 = COERCE_FLOAT(CRTFtol(v7 * a4));
  a2 = COERCE_FLOAT(CRTFtol(a2 * a5));
  result = sub_543540(&v12, &v11, &a3, &a2);
  if ( a3 > 0 )
  {
    result = LODWORD(a2);
    if ( SLODWORD(a2) > 0 )
    {
      result = F_2DSurfaceBlitFill(dword_8B78A0, this, v12, v11, a3, (char *)LODWORD(a2), a6);
      this[6] &= ~0x400u;
    }
  }
  return result;
}

