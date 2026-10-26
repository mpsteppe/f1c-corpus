int __thiscall sub_42DE10(int *this, int a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // [esp-8h] [ebp-338h]
  _BYTE v15[4]; // [esp+10h] [ebp-320h] BYREF
  _BYTE v16[4]; // [esp+14h] [ebp-31Ch] BYREF
  _BYTE v17[384]; // [esp+18h] [ebp-318h] BYREF
  int v18; // [esp+198h] [ebp-198h]
  char v19; // [esp+19Ch] [ebp-194h]
  int v20; // [esp+1A4h] [ebp-18Ch]
  int v21; // [esp+1A8h] [ebp-188h]
  int v22; // [esp+1ACh] [ebp-184h]
  _BYTE v23[384]; // [esp+1B0h] [ebp-180h] BYREF

  memset(v23, 0, sizeof(v23));
  v18 = 0;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 1;
  ScoreSlotDeallocator(this);
  result = sub_587DB0(a2, aR);
  v4 = result;
  if ( result )
  {
    if ( FileReadUntilNewline(v23, 384, result) )
    {
      do
      {
        if ( !sub_5651B0(v17) )
        {
          if ( sub_587C20(v23, aGearRatios) )
          {
            *this = 0;
            while ( FileReadUntilNewline(v23, 384, v4) )
            {
              v5 = sub_5651B0(v17);
              if ( v5 == 1 || v5 == 4 )
                break;
              if ( !v5 && sub_565760(aRatio, v15, v16, 0, 0) )
                ++*this;
            }
          }
          else if ( sub_587C20(v23, aFinalDrive) )
          {
            this[2] = 0;
            while ( FileReadUntilNewline(v23, 384, v4) )
            {
              v6 = sub_5651B0(v17);
              if ( v6 == 1 || v6 == 4 )
                break;
              if ( !v6 && sub_565760(aRatio, v15, v16, 0, 0) )
                ++this[2];
            }
          }
        }
      }
      while ( FileReadUntilNewline(v23, 384, v4) );
    }
    v7 = OperatorNewNhMallocWrapper(8 * *this);
    v14 = 8 * this[2];
    this[1] = v7;
    this[3] = OperatorNewNhMallocWrapper(v14);
    sub_587F64(v4, 0, 0);
    while ( FileReadUntilNewline(v23, 384, v4) )
    {
      if ( !sub_5651B0(v17) )
      {
        if ( sub_587C20(v23, aGearRatios) )
        {
          if ( FileReadUntilNewline(v23, 384, v4) )
          {
            v8 = 0;
            do
            {
              v9 = sub_5651B0(v17);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 )
              {
                if ( sub_565760(aRatio, v8 + this[1], v8 + this[1] + 4, 0, 0) )
                  v8 += 8;
              }
            }
            while ( FileReadUntilNewline(v23, 384, v4) );
          }
          v10 = *this;
          v11 = this[1];
LABEL_44:
          sub_5890AA(v11, v10, 8, (char *)&loc_42DC1F + 1);
          continue;
        }
        if ( sub_587C20(v23, aFinalDrive) )
        {
          if ( FileReadUntilNewline(v23, 384, v4) )
          {
            v12 = 0;
            do
            {
              v13 = sub_5651B0(v17);
              if ( v13 == 1 || v13 == 4 )
                break;
              if ( !v13 )
              {
                sub_565760(aBevel, this + 4, this + 5, 0, 0);
                if ( sub_565760(aRatio, v12 + this[3], v12 + this[3] + 4, 0, 0) )
                  v12 += 8;
              }
            }
            while ( FileReadUntilNewline(v23, 384, v4) );
          }
          v10 = this[2];
          v11 = this[3];
          goto LABEL_44;
        }
      }
    }
    return FileCloseWithLock(v4);
  }
  return result;
}

