int __fastcall sub_5642F0(int a1, __int16 a2, int a3, int a4)
{
  int v6; // esi
  int v7; // eax

  v6 = sub_58A935(20);
  *(_DWORD *)v6 = a1;
  *(_WORD *)(v6 + 4) = a2;
  *(_WORD *)(v6 + 6) = 9999;
  *(_DWORD *)(v6 + 8) = a3;
  switch ( a3 )
  {
    case 0:
      v7 = 2;
      break;
    case 1:
      v7 = 2;
      break;
    case 2:
    case 3:
      v7 = 2;
      break;
    default:
      v7 = 4;
      break;
  }
  *(_DWORD *)(v6 + 12) = sub_5646D0(v7, sub_5645F0, sub_564620, 0);
  *(_DWORD *)(v6 + 16) = a4;
  return v6;
}
