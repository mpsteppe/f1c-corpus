__int16 __fastcall sub_5B9A60(int a1, int a2, int a3, int a4)
{
  int v4; // eax

  switch ( a2 )
  {
    case 0:
      LOWORD(v4) = (*(int (__fastcall **)(int, _DWORD, int, _DWORD))(a4 + 1560))(a4, 0, a3, *(_DWORD *)(a4 + 1564));
      if ( (*(_BYTE *)(a3 + 20) & 3) == 0 )
      {
        v4 = *(_DWORD *)(a4 + 1548);
        if ( !v4 )
        {
          if ( *(_DWORD *)(a4 + 72) && *(_DWORD *)(a4 + 60) )
            LOWORD(v4) = sub_5BBB80(0, 0);
          else
            LOWORD(v4) = sub_5BBB80(0, 1);
        }
      }
      break;
    case 1:
      if ( (*(_BYTE *)(a3 + 20) & 3) != 0 )
        LOWORD(v4) = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 1, a3, *(_DWORD *)(a4 + 1564));
      else
        LOWORD(v4) = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 2, a3, *(_DWORD *)(a4 + 1564));
      break;
    case 2:
      if ( (*(_BYTE *)(a3 + 20) & 0xC) != 0 )
        sub_5BC100(a4, a3);
      LOWORD(v4) = (*(int (__fastcall **)(int, int, int, _DWORD))(a4 + 1560))(a4, 3, a3, *(_DWORD *)(a4 + 1564));
      break;
    case 3:
      v4 = *(_DWORD *)(a4 + 1544);
      if ( v4 )
        LOWORD(v4) = sub_5BC800();
      break;
    case 5:
      LOWORD(v4) = (*(int (__fastcall **)(int, int, _DWORD, _DWORD))(a4 + 1560))(a4, 5, 0, *(_DWORD *)(a4 + 1564));
      break;
    case 6:
      LOWORD(v4) = sub_5BBB20(a4, *(_DWORD *)(a4 + 1240));
      break;
    default:
      break;
  }
  if ( a3 )
  {
    v4 = *(_DWORD *)(a4 + 1552);
    if ( *(_DWORD *)a3 == v4 )
    {
      LOWORD(v4) = *(_WORD *)(a3 + 4);
      if ( (_WORD)v4 == *(_WORD *)(a4 + 1556) )
        *(_DWORD *)(a4 + 1552) = 0;
    }
  }
  return v4;
}
