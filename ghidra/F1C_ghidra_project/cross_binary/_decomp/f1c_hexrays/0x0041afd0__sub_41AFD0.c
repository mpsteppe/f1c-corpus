// f1c  0x0041afd0  size=385
void __stdcall sub_41AFD0(int a1, int a2)
{
  float v2[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    sub_4144D0(v2);
    if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
    {
      switch ( a2 )
      {
        case 0:
          sub_4144F0(v2, 106, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 1:
          sub_4144F0(v2, 107, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 2:
          sub_4144F0(v2, 109, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 3:
          sub_4144F0(v2, 110, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 4:
          sub_4144F0(v2, 108, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 5:
          sub_4144F0(v2, 111, -1, -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    else if ( dword_7C56A8 != 8 )
    {
      switch ( a2 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
          sub_4144F0(v2, 221, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        case 4:
          sub_4144F0(v2, 222, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        case 5:
          sub_4144F0(v2, 223, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    sub_418560(flt_5EA618, v2);
  }
}
