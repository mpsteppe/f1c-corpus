_DWORD *__thiscall sub_4E4790(int this)
{
  _DWORD *result; // eax
  int v3; // edx

  if ( !*(_DWORD *)(this + 12988) )
    WheelDynamicsInit((int)&dbl_7C7428);
  if ( *(_DWORD *)(this + 14756) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 14756));
    *(_DWORD *)(this + 14756) = 0;
  }
  *(_DWORD *)(this + 13548) = 0;
  *(_DWORD *)(this + 13552) = 0;
  *(_DWORD *)(this + 13556) = 0;
  *(_DWORD *)(this + 13560) = 0;
  *(_DWORD *)(this + 13564) = 0;
  *(_DWORD *)(this + 13568) = 0;
  *(_DWORD *)(this + 13572) = 0;
  *(_DWORD *)(this + 13576) = 0;
  *(_DWORD *)(this + 13580) = 0;
  *(_DWORD *)(this + 13620) = 0;
  *(_DWORD *)(this + 13624) = 0;
  *(_DWORD *)(this + 13628) = 0;
  *(_DWORD *)(this + 13632) = 0;
  *(_DWORD *)(this + 13636) = 0;
  *(_DWORD *)(this + 13640) = 0;
  *(_DWORD *)(this + 13644) = 0;
  *(_DWORD *)(this + 13648) = 0;
  *(_DWORD *)(this + 13652) = 0;
  *(_DWORD *)(this + 13656) = 0;
  *(_DWORD *)(this + 13660) = 0;
  *(_DWORD *)(this + 13664) = 0;
  *(_DWORD *)(this + 13680) = 0;
  *(_DWORD *)(this + 13684) = 0;
  *(_DWORD *)(this + 13688) = 0;
  *(_DWORD *)(this + 15004) = 0;
  result = (_DWORD *)(this + 13728);
  v3 = 4;
  do
  {
    *(result - 2) = 0;
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    result[4] = 0;
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
    result[8] = 0;
    result[9] = 0;
    result[13] = 0;
    result[14] = 0;
    result[24] = 0;
    result[22] = 1065353216;
    result[23] = 1065353216;
    result[25] = 0;
    result[26] = 0;
    result[27] = 0;
    result[39] = 1065353216;
    result[40] = 0;
    result[46] = 0;
    result[47] = 0;
    result[48] = 0;
    result[49] = 0;
    result[50] = 0;
    result += 62;
    --v3;
  }
  while ( v3 );
  *(_DWORD *)(this + 14692) = 0;
  *(_DWORD *)(this + 14740) = 0;
  *(_DWORD *)(this + 14752) = 0;
  *(_DWORD *)(this + 14792) = 0;
  *(_DWORD *)(this + 14832) = 0;
  *(_DWORD *)(this + 14836) = -2;
  return result;
}

