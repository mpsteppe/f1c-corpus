bool __thiscall sub_45DFA0(unsigned __int8 *this, unsigned int a2, float *a3, float a4)
{
  bool result; // al
  int v6; // edx
  signed int v7; // ebx
  double v8; // st7
  double v9; // st7
  int v10; // eax
  int v11; // edi
  bool v12; // cc
  int v13; // edx
  int v14; // edx
  float v15; // [esp+0h] [ebp-40h]
  float v16; // [esp+1Ch] [ebp-24h]
  _WORD Base[16]; // [esp+20h] [ebp-20h] BYREF

  if ( dword_630030[6326 * a2] != 2 )
  {
    *a3 = 0.0;
    return 1;
  }
  v7 = sub_45DD00(this, a2);
  if ( !v7 )
  {
    *a3 = 9.9989996;
    return 0;
  }
  if ( *(float *)&this[4 * v6 + 2080] > 0.0 )
  {
    *a3 = *(float *)&this[4 * v6 + 2080];
    return 1;
  }
  result = v7 == 16;
  if ( LOBYTE(a4) && v7 != 16 )
  {
    *a3 = 9.9989996;
    return result;
  }
  qmemcpy(Base, &this[32 * v6 + 510], sizeof(Base));
  qsort(Base, v7, 2u, (_CoreCrtNonSecureSearchSortCompareFunction)sub_45DCE0);
  v8 = (double)v7 * 0.33399999;
  if ( v8 < 1.0 )
    v8 = 1.0;
  LODWORD(a4) = (__int64)v8;
  v9 = 1.0 / (double)SLODWORD(a4);
  v10 = (v7 - LODWORD(a4)) / 2;
  v11 = v10 + LODWORD(a4);
  v12 = v10 < v10 + LODWORD(a4);
  *a3 = 0.0;
  v13 = v10;
  if ( v12 )
  {
    do
    {
      sub_45DD40(Base[v13], &a4);
      v13 = v14 + 1;
      v16 = v9;
      *a3 = a4 * v16 + *a3;
    }
    while ( v13 < v11 );
  }
  if ( v7 == 16 )
  {
    *(float *)&this[4 * a2 + 2080] = *a3;
    if ( flt_769A90 < (double)*a3 )
    {
      v15 = flt_769A90 - *a3;
      sub_45DD20(v15, &this[2 * a2 + 2276]);
      return v7 == 16;
    }
    sub_45DD20(0.0, &this[2 * a2 + 2276]);
  }
  return v7 == 16;
}
