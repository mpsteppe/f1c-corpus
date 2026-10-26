const char **__thiscall VehicleSetupValueFormatter(int this, const char **a2)
{
  const char **result; // eax
  int v4; // esi
  int v5; // eax
  char v6; // cl
  _BYTE *v7; // ebx
  const char *v8; // esi
  int v9; // eax
  char v10; // cl
  bool v11; // cc
  int v12; // eax
  char v13; // cl
  int v14; // eax
  char v15; // cl
  int v16; // ebx
  int v17; // eax
  char v18; // cl
  int v19; // eax
  char v20; // cl
  _BYTE *v21; // esi
  _BYTE *v22; // esi
  int v23; // edx
  int v24; // eax
  int v25; // ebx
  int v26; // eax
  char v27; // cl
  _BYTE *v28; // esi
  int v29; // edx
  int v30; // edx
  _BYTE *v31; // esi
  int v32; // eax
  char v33; // cl
  const char *v34; // [esp+Ch] [ebp-6Ch]
  const char *v35; // [esp+Ch] [ebp-6Ch]
  int v36; // [esp+20h] [ebp-58h]
  double v37; // [esp+20h] [ebp-58h]
  double v38; // [esp+28h] [ebp-50h]
  double v39; // [esp+28h] [ebp-50h]
  double v40; // [esp+28h] [ebp-50h]
  double v41; // [esp+28h] [ebp-50h]
  int v42; // [esp+28h] [ebp-50h]
  int v43; // [esp+28h] [ebp-50h]
  int v44; // [esp+34h] [ebp-44h]
  int v45; // [esp+34h] [ebp-44h]
  int v46; // [esp+34h] [ebp-44h]
  char v47[64]; // [esp+38h] [ebp-40h] BYREF

  result = a2;
  v4 = ((_DWORD)a2 << 6) + this + 2992;
  switch ( (unsigned int)a2 )
  {
    case 0u:
      if ( BinarySearchInStringTable(byte_5EC4C0, aUnknown, byte_5EC4CC) )
      {
        v5 = 0;
        do
        {
          v6 = aUnknown[v5];
          byte_5EC4CC[v5++] = v6;
        }
        while ( v6 );
      }
      v7 = (_BYTE *)(v4 + 30);
      StringFormatWithBufferOverflowCheck((_BYTE *)(v4 + 30), (int)byte_5EC4CC);
      result = (const char **)TireBrandLookup(&dword_8AD254, this + 112);
      if ( result )
      {
        result = (const char **)CompoundIndexLookup(result, *(_DWORD *)(v4 + 20));
        if ( result )
        {
          v8 = *result;
          if ( !*result )
            v8 = byte_5EA438;
          if ( BinarySearchInStringTable(byte_5EC4C0, v8, byte_5EC4CC) )
          {
            if ( v8 )
              strcpy(byte_5EC4CC, v8);
            else
              byte_5EC4CC[0] = 0;
          }
          return (const char **)StringFormatWithBufferOverflowCheck(v7, (int)byte_5EC4CC);
        }
      }
      return result;
    case 1u:
    case 2u:
    case 0x1Fu:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%4.1f:%4.1f",
                              100.0
                            - ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 100.0,
                              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 100.0);
    case 3u:
      v38 = (double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
          + *(double *)(((_DWORD)a2 << 6) + this + 2992);
      if ( BinarySearchInStringTable(byte_5EC4C0, aTurns, byte_5EC4CC) )
      {
        v9 = 0;
        do
        {
          v10 = aTurns[v9];
          byte_5EC4CC[v9++] = v10;
        }
        while ( v10 );
      }
      return (const char **)StringFormatWithBufferOverflowCheck((_BYTE *)(v4 + 30), (int)"%.2f %s", v38, byte_5EC4CC);
    case 4u:
    case 0x34u:
    case 0x35u:
    case 0x36u:
      if ( a2 == (const char **)52 )
      {
        v11 = *(_DWORD *)(this + 6276) < 1;
      }
      else
      {
        if ( a2 != (const char **)53 )
        {
          if ( a2 != (const char **)54 || *(int *)(this + 6276) >= 3 )
            goto LABEL_24;
LABEL_33:
          if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3810, byte_5EC4CC) )
          {
            v14 = 0;
            do
            {
              v15 = *((_BYTE *)&off_5C3810 + v14);
              byte_5EC4CC[v14++] = v15;
            }
            while ( v15 );
          }
          return (const char **)StringFormatWithBufferOverflowCheck((_BYTE *)(v4 + 30), (int)"%s", byte_5EC4CC);
        }
        v11 = *(_DWORD *)(this + 6276) < 2;
      }
      if ( v11 )
        goto LABEL_33;
LABEL_24:
      v39 = (double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
          + *(double *)(((_DWORD)a2 << 6) + this + 2992);
      if ( *(double *)(this + 6548) == 0.0 )
      {
        if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3810, byte_5EC4CC) )
        {
          v12 = 0;
          do
          {
            v13 = *((_BYTE *)&off_5C3810 + v12);
            byte_5EC4CC[v12++] = v13;
          }
          while ( v13 );
        }
        StringFormatWithBufferOverflowCheck(v47, (int)"(%s)", byte_5EC4CC);
      }
      else
      {
        v16 = CRTFtol(v39 * *(double *)(this + 6548));
        if ( v16 == 1 )
        {
          if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3804, byte_5EC4CC) )
          {
            v17 = 0;
            do
            {
              v18 = *((_BYTE *)&off_5C3804 + v17);
              byte_5EC4CC[v17++] = v18;
            }
            while ( v18 );
          }
          StringFormatWithBufferOverflowCheck(v47, (int)"(1 %s)", byte_5EC4CC);
        }
        else
        {
          if ( BinarySearchInStringTable(byte_5EC4C0, aLaps, byte_5EC4CC) )
          {
            v19 = 0;
            do
            {
              v20 = aLaps[v19];
              byte_5EC4CC[v19++] = v20;
            }
            while ( v20 );
          }
          StringFormatWithBufferOverflowCheck(v47, (int)"(%d %s)", v16, byte_5EC4CC);
        }
      }
      if ( *(_DWORD *)(this + 4) == 1 )
        return (const char **)StringFormatWithBufferOverflowCheck(
                                (_BYTE *)(v4 + 30),
                                (int)"%4.1f %s %s",
                                v39 * 0.2641720372841846,
                                (const char *)(this + 88),
                                v47);
      else
        return (const char **)StringFormatWithBufferOverflowCheck(
                                (_BYTE *)(v4 + 30),
                                (int)"%d %s %s",
                                (int)v39,
                                (const char *)(this + 88),
                                v47);
    case 5u:
    case 6u:
      if ( *(_BYTE *)(this + 6537) )
        return (const char **)SetupValueFormatDS(this, ((_DWORD)a2 << 6) + this + 2992);
      v22 = (_BYTE *)(((_DWORD)a2 << 6) + this + 3022);
      v35 = (const char *)(this + 24);
      v41 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
           + *(double *)(((_DWORD)a2 << 6) + this + 2992))
          * 100.0;
      if ( *(_DWORD *)(this + 4) )
        return (const char **)StringFormatWithBufferOverflowCheck(v22, (int)"%.3f %s", v41 * 0.3937007874015748, v35);
      else
        return (const char **)StringFormatWithBufferOverflowCheck(v22, (int)"%.2f %s", v41, v35);
    case 7u:
    case 8u:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%.2f %s",
                              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 57.29577951308232,
                              this + 40);
    case 9u:
    case 0xAu:
      v21 = (_BYTE *)(((_DWORD)a2 << 6) + this + 3022);
      v34 = (const char *)(this + 24);
      v40 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
           + *(double *)(((_DWORD)a2 << 6) + this + 2992))
          * 100.0;
      if ( *(_DWORD *)(this + 4) )
        return (const char **)StringFormatWithBufferOverflowCheck(v21, (int)"%.2f %s", v40 * 0.3937007874015748, v34);
      else
        return (const char **)StringFormatWithBufferOverflowCheck(v21, (int)"%.1f %s", v40, v34);
    case 0xBu:
    case 0xCu:
    case 0x22u:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%.1f %s",
                              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 57.29577951308232,
                              this + 40);
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x15u:
      return (const char **)SetupValueFormatWithOffset(this, ((_DWORD)a2 << 6) + this + 2992, 0.0);
    case 0x10u:
    case 0x16u:
      return (const char **)SetupValueFormatDS(this, ((_DWORD)a2 << 6) + this + 2992);
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x17u:
    case 0x18u:
    case 0x19u:
    case 0x1Au:
      return (const char **)SetupValueFormat1fS(this, ((_DWORD)a2 << 6) + this + 2992);
    case 0x1Bu:
    case 0x1Cu:
      if ( (*(_BYTE *)(this + 6540) & 1) != 0 )
        return (const char **)StringFormatWithBufferOverflowCheck(
                                (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                                (int)"%d",
                                *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d %s",
                              (int)((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                                  * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                                  + *(double *)(((_DWORD)a2 << 6) + this + 2992)),
                              (const char *)(this + 40));
    case 0x1Du:
      if ( (*(_BYTE *)(this + 6540) & 2) != 0 )
        return (const char **)StringFormatWithBufferOverflowCheck(
                                (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                                (int)"%d",
                                *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d%%",
                              (int)(100.0
                                  - ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                                   * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                                   + *(double *)(((_DWORD)a2 << 6) + this + 2992))));
    case 0x1Eu:
    case 0x26u:
    case 0x28u:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d",
                              *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
    case 0x20u:
    case 0x21u:
    case 0x23u:
    case 0x24u:
    case 0x25u:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d%%",
                              (int)(((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                                   * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                                   + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                                  * 100.0));
    case 0x27u:
      v44 = (int)(((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                 + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                * 9.549296585513721);
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d%03d",
                              v44 / 1000,
                              v44 % 1000);
    case 0x29u:
    case 0x33u:
      return (const char **)StringFormatWithBufferOverflowCheck(
                              (_BYTE *)(((_DWORD)a2 << 6) + this + 3022),
                              (int)"%d",
                              *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012));
    case 0x2Au:
      v45 = ArrayElementGetter((_DWORD *)(this + 6512), *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012));
      v24 = BoundedArrayElementAccessor((_DWORD *)(this + 6512), v23);
      v25 = *(_DWORD *)(this + 6528);
      v42 = v24;
      v36 = *(_DWORD *)(this + 6532);
      if ( BinarySearchInStringTable(byte_5EC4C0, aBevel, byte_5EC4CC) )
      {
        v26 = 0;
        do
        {
          v27 = aBevel[v26];
          byte_5EC4CC[v26++] = v27;
        }
        while ( v27 );
      }
      v28 = (_BYTE *)(v4 + 30);
      if ( (*(_BYTE *)(this + 6540) & 4) != 0 )
        return (const char **)StringFormatWithBufferOverflowCheck(
                                v28,
                                (int)"%2d/%2d (%s %2d/%2d)",
                                v45,
                                v42,
                                byte_5EC4CC,
                                v25,
                                v36);
      else
        return (const char **)StringFormatWithBufferOverflowCheck(
                                v28,
                                (int)"%.2f:1",
                                (double)(v42 * v36) / (double)(v45 * v25));
    case 0x2Bu:
    case 0x2Cu:
    case 0x2Du:
    case 0x2Eu:
    case 0x2Fu:
    case 0x30u:
    case 0x31u:
    case 0x32u:
      if ( *(_BYTE *)(((_DWORD)a2 << 6) + this + 3020) )
      {
        v43 = BoundedArrayAccessor((int *)(this + 6512), *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012));
        v46 = BoundsCheckedArrayLookup((int *)(this + 6512), v29);
        v37 = RatioCalculator((int *)(this + 6512), v30, *(_DWORD *)(this + 5700));
        v31 = (_BYTE *)(v4 + 30);
        if ( (*(_BYTE *)(this + 6540) & 4) != 0 )
          return (const char **)StringFormatWithBufferOverflowCheck(v31, (int)"%2d/%2d (%.3f)", v43, v46, v37);
        else
          return (const char **)StringFormatWithBufferOverflowCheck(
                                  v31,
                                  (int)"%.2f (%.2f)",
                                  (double)v46 / (double)v43,
                                  v37);
      }
      else
      {
        if ( BinarySearchInStringTable(byte_5EC4C0, (const char *)&off_5C3810, byte_5EC4CC) )
        {
          v32 = 0;
          do
          {
            v33 = *((_BYTE *)&off_5C3810 + v32);
            byte_5EC4CC[v32++] = v33;
          }
          while ( v33 );
        }
        return (const char **)StringFormatWithBufferOverflowCheck((_BYTE *)(v4 + 30), (int)"%s", byte_5EC4CC);
      }
    default:
      return result;
  }
}
