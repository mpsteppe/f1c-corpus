int __thiscall sub_479170(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi
  LPVOID *v5; // edi
  bool v6; // zf
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // [esp+10h] [ebp-328h]
  int v11; // [esp+14h] [ebp-324h] BYREF
  int v12; // [esp+18h] [ebp-320h] BYREF
  _DWORD v13[98]; // [esp+1Ch] [ebp-31Ch] BYREF
  char v14; // [esp+1A4h] [ebp-194h]
  int v15; // [esp+1ACh] [ebp-18Ch]
  int v16; // [esp+1B0h] [ebp-188h]
  int v17; // [esp+1B4h] [ebp-184h]
  _BYTE v18[384]; // [esp+1B8h] [ebp-180h] BYREF

  memset(v18, 0, sizeof(v18));
  v13[97] = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 1;
  v11 = 0;
  result = sub_587DB0(a2, aRt);
  v4 = this[89];
  v10 = result;
  if ( v4 )
  {
    do
    {
      v5 = (LPVOID *)v4;
      v6 = *(_BYTE *)(v4 + 8) == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        sub_587BCF(*v5);
      sub_587BCF(v5);
    }
    while ( v4 );
    result = v10;
  }
  this[89] = 0;
  this[90] = 0;
  this[91] = 0;
  this[92] = 0;
  this[85] = 0;
  if ( result )
  {
    if ( (*(_BYTE *)(result + 12) & 0x10) == 0 )
    {
      do
      {
        v7 = (_DWORD *)sub_587C03(12);
        sub_587CA0(v18, 384, v10);
        sub_565760(aNumcoordinates, &v11, 0, 0, 0);
        if ( v11 > 0 && sub_565760(aCoordinate, &v12, v13, 0, 0) )
        {
          *v7 = v12;
          v7[1] = v13[0];
          v8 = sub_587C03(12);
          if ( v8 )
          {
            *(_DWORD *)v8 = v7;
            *(_DWORD *)(v8 + 4) = 0;
            *(_BYTE *)(v8 + 8) = 1;
          }
          else
          {
            v8 = 0;
          }
          if ( this[89] )
          {
            *(_DWORD *)(this[90] + 4) = v8;
          }
          else
          {
            this[89] = v8;
            this[91] = v8;
          }
          v9 = this[92] + 1;
          this[90] = v8;
          this[92] = v9;
          ++this[85];
        }
      }
      while ( (*(_BYTE *)(v10 + 12) & 0x10) == 0 );
      result = v10;
    }
    return sub_587D02(result);
  }
  return result;
}
