int __thiscall sub_406BA0(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // edi
  void *v4; // ebp
  int j; // edi
  LPVOID **v6; // ebp
  bool v7; // zf
  int k; // edi
  _DWORD *v9; // ebp
  int m; // edi
  _DWORD *v11; // ebp

  *this = &off_59E530;
  result = AudioSystemShutdown();
  for ( i = (_DWORD *)this[14]; i; result = FreeWrapper_7bcf(v4) )
  {
    v4 = i;
    i = (_DWORD *)i[1];
    UtilityFunction(v4);
  }
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  for ( j = this[10]; j; result = FreeWrapper_7bcf(v6) )
  {
    v6 = (LPVOID **)j;
    v7 = *(_BYTE *)(j + 8) == 0;
    j = *(_DWORD *)(j + 4);
    if ( !v7 && *v6 )
      ConditionalFreeWithBit0Flag(*v6, 1);
  }
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  for ( k = this[6]; k; result = FreeWrapper_7bcf(v9) )
  {
    v9 = (_DWORD *)k;
    v7 = *(_BYTE *)(k + 8) == 0;
    k = *(_DWORD *)(k + 4);
    if ( !v7 && *v9 )
      (**(void (__thiscall ***)(_DWORD, int))*v9)(*v9, 1);
  }
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  for ( m = this[2]; m; result = FreeWrapper_7bcf(v11) )
  {
    v11 = (_DWORD *)m;
    v7 = *(_BYTE *)(m + 8) == 0;
    m = *(_DWORD *)(m + 4);
    if ( !v7 && *v11 )
      (**(void (__thiscall ***)(_DWORD, int))*v11)(*v11, 1);
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  *this = &off_59E598;
  return result;
}

