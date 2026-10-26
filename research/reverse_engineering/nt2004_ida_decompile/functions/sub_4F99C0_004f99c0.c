int __thiscall sub_4F99C0(int this, int a2, int a3)
{
  int v4; // eax
  signed int v5; // edx
  signed int i; // eax
  signed int j; // esi
  signed int k; // esi
  signed int m; // esi
  signed int n; // eax
  char Buffer[125]; // [esp+10h] [ebp-100h] BYREF
  __int16 v14; // [esp+8Dh] [ebp-83h]
  char v15; // [esp+8Fh] [ebp-81h]
  char ArgList[125]; // [esp+90h] [ebp-80h] BYREF
  __int16 v17; // [esp+10Dh] [ebp-3h]
  char v18; // [esp+10Fh] [ebp-1h]

  v4 = *(_DWORD *)(this + 280);
  if ( v4 && !a2 || v4 != 7 && a2 == 7 )
    sub_51F3D0(0, 4);
  if ( a2 || *(_DWORD *)(this + 280) )
  {
    sub_41BA10(a2, *(_DWORD *)(this + 280));
    if ( a2 == 7 )
    {
      sub_45D270(&byte_764D68, aWithholdingGre, 1);
      if ( sub_4EED40((_DWORD *)dword_75AACC) )
        sub_4DF490((_DWORD *)(dword_75AACC + 20836), 0.0, 1);
      goto LABEL_11;
    }
    if ( a2 == 1 )
    {
      for ( i = 0; i < (int)NumOfElements; ++i )
        *(_DWORD *)(dword_75AAD0[i] + 21116) = 0;
      *((_DWORD *)off_5FD348 + 5279) = 0;
      dword_766228 = 0;
      byte_766222 = 0;
      dword_766224 = 1;
      sub_4F7ED0((_DWORD *)(this + 356));
      goto LABEL_11;
    }
    if ( a2 )
    {
LABEL_11:
      v5 = NumOfElements;
      goto LABEL_12;
    }
  }
  v5 = NumOfElements;
  for ( j = 0; j < (int)NumOfElements; ++j )
  {
    sub_4DEA70(dword_75AAD0[j] + 20836, 0);
    v5 = NumOfElements;
  }
LABEL_12:
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v14 = 0;
  v15 = 0;
  switch ( a2 )
  {
    case 0:
      sub_405480(Buffer, 0x7Fu, aGreenFlagResum);
      break;
    case 1:
      if ( a3 < 0 )
      {
        sub_405480(Buffer, 0x7Fu, aYellowFlagDete_0);
      }
      else
      {
        ArgList[0] = byte_629120;
        memset(&ArgList[1], 0, 0x7Cu);
        v17 = 0;
        v18 = 0;
        sub_4EDE00((_DWORD *)&unk_62BF68 + 6326 * a3, ArgList, 127);
        sub_405480(Buffer, 0x7Fu, "Yellow Flag: Detected (Car #%s), Pits Closed", ArgList);
      }
      for ( k = 0; k < (int)NumOfElements; ++k )
        sub_427260((_DWORD *)dword_75AAD0[k]);
      break;
    case 2:
      sub_405480(Buffer, 0x7Fu, aYellowFlagPits);
      for ( m = 0; m < (int)NumOfElements; ++m )
        sub_427260((_DWORD *)dword_75AAD0[m]);
      break;
    case 3:
      sub_405480(Buffer, 0x7Fu, aYellowFlagPits_0);
      break;
    case 4:
    case 5:
      sub_405480(Buffer, 0x7Fu, aYellowFlagPits_1);
      break;
    case 6:
      for ( n = 0; n < v5; ++n )
      {
        if ( *(_DWORD *)(dword_75AAD0[n] + 20848) >= *(_DWORD *)(this + 144) - 1 )
          break;
      }
      if ( n == v5 )
        sub_405480(Buffer, 0x7Fu, aYellowFlagPrep);
      sub_4F84C0((_DWORD *)(this + 356));
      break;
    case 7:
      if ( !*(_BYTE *)(this + 163) )
        sub_405480(Buffer, 0x7Fu, aGreenFlagMayPa);
      break;
    case 8:
      sub_405480(Buffer, 0x7Fu, aRedFlagDetecte);
      break;
    default:
      break;
  }
  sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
  if ( !a2 || a2 == 7 )
  {
    sub_42F950(&dword_75CBA8, 5);
  }
  else
  {
    if ( a2 == 8 )
    {
      sub_42F950(&dword_75CBA8, 7);
      goto LABEL_51;
    }
    sub_42F950(&dword_75CBA8, 6);
  }
  if ( a2 == 2 && (unsigned __int8)sub_4BBF20() )
    flt_76622C = sub_4BBF40();
LABEL_51:
  *(_DWORD *)(this + 280) = a2;
  return sub_4F9F50(this);
}
