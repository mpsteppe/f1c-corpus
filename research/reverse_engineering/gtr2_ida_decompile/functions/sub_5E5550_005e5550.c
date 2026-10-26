int __thiscall sub_5E5550(int *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, int a6)
{
  unsigned __int64 v6; // rax
  double v7; // st7
  float v9; // [esp+8h] [ebp-4h]

  LODWORD(v6) = a6;
  v7 = 1.0;
  v9 = 1.0;
  if ( (a6 & 0x4000) != 0 )
  {
    LODWORD(v6) = dword_FB27A4;
    v7 = (double)*(int *)(dword_FB27A4 + 9408);
    v9 = (float)*(int *)(dword_FB27A4 + 9412);
  }
  if ( a2 )
  {
    v6 = (unsigned __int64)((double)this[30] * v7);
    *a2 = v6;
  }
  if ( a3 )
  {
    v6 = (unsigned __int64)((double)this[29] * v9);
    *a3 = v6;
  }
  if ( a4 )
  {
    v6 = (unsigned __int64)((double)this[25] * v7);
    *a4 = v6;
  }
  if ( a5 )
  {
    v6 = (unsigned __int64)((double)this[26] * v9);
    *a5 = v6;
  }
  return v6;
}
