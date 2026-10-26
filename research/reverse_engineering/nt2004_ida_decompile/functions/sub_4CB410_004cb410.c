void __thiscall sub_4CB410(int this, float a2)
{
  int v3; // edx
  int v4; // ecx
  double v5; // st7
  bool v6; // c0
  bool v7; // c3

  v3 = *(_DWORD *)(this + 8280);
  *(float *)(this + 8268) = a2;
  sub_4CF410(v3);
  v4 = *(_DWORD *)(this + 8268);
  switch ( v4 )
  {
    case 1:
      *(_DWORD *)(this + 17136) = 0;
      *(_DWORD *)(this + 17140) = 205;
      *(_DWORD *)(this + 17108) = 0;
      *(_DWORD *)(this + 17112) = 203;
      *(_DWORD *)(this + 17052) = 0;
      *(_DWORD *)(this + 17056) = 200;
      *(_DWORD *)(this + 17080) = 0;
      *(_DWORD *)(this + 17084) = 208;
      *(_DWORD *)(this + 17164) = 0;
      *(_DWORD *)(this + 17168) = 56;
      *(_DWORD *)(this + 17192) = 0;
      *(_DWORD *)(this + 17196) = 184;
      *(_DWORD *)(this + 17248) = 0;
      *(_DWORD *)(this + 17252) = 23;
      *(_DWORD *)(this + 17276) = 0;
      *(_DWORD *)(this + 17280) = 37;
      *(_DWORD *)(this + 17304) = 0;
      *(_DWORD *)(this + 17308) = 38;
      *(_DWORD *)(this + 17332) = 0;
      *(_DWORD *)(this + 17336) = 36;
      a2 = 0.75;
      sub_4CEF90(&a2);
      goto LABEL_11;
    case 2:
      *(_DWORD *)(this + 17136) = 1;
      *(_DWORD *)(this + 17140) = 1;
      *(_DWORD *)(this + 17108) = 1;
      *(_DWORD *)(this + 17112) = 2;
      *(_DWORD *)(this + 17052) = 1;
      *(_DWORD *)(this + 17056) = 4;
      *(_DWORD *)(this + 17080) = 1;
      *(_DWORD *)(this + 17084) = 3;
      *(_DWORD *)(this + 17164) = 1;
      *(_DWORD *)(this + 17168) = 13;
      *(_DWORD *)(this + 17196) = 14;
      break;
    case 3:
      *(_DWORD *)(this + 17136) = 1;
      *(_DWORD *)(this + 17140) = 30;
      *(_DWORD *)(this + 17108) = 1;
      *(_DWORD *)(this + 17112) = 31;
      *(_DWORD *)(this + 17052) = 1;
      *(_DWORD *)(this + 17056) = 33;
      *(_DWORD *)(this + 17080) = 1;
      *(_DWORD *)(this + 17084) = 32;
      *(_DWORD *)(this + 17164) = 1;
      *(_DWORD *)(this + 17168) = 42;
      *(_DWORD *)(this + 17196) = 43;
      break;
    default:
      goto LABEL_11;
  }
  *(_DWORD *)(this + 17192) = 1;
  *(_DWORD *)(this + 17252) = 200;
  *(_DWORD *)(this + 17248) = 0;
  *(_DWORD *)(this + 17280) = 208;
  *(_DWORD *)(this + 17276) = 0;
  *(_DWORD *)(this + 17308) = 205;
  *(_DWORD *)(this + 17304) = 0;
  *(_DWORD *)(this + 17336) = 203;
  *(_DWORD *)(this + 17332) = 0;
  v5 = *(float *)(this + 1704);
  *(_DWORD *)(this + 1696) = *(_DWORD *)(this + 1700);
  v6 = v5 < *(float *)(this + 1696);
  v7 = v5 == *(float *)(this + 1696);
  a2 = *(float *)(this + 1708);
  if ( v6 || v7 )
  {
    if ( *(float *)(this + 1696) > (double)a2 )
      *(float *)(this + 1696) = a2;
  }
  else
  {
    *(float *)(this + 1696) = v5;
  }
LABEL_11:
  if ( *(_DWORD *)(this + 8268) )
  {
    *(_DWORD *)(this + 17220) = 0;
    *(_DWORD *)(this + 17224) = 16;
    *(_DWORD *)(this + 17444) = 0;
    *(_DWORD *)(this + 17448) = 47;
    *(_DWORD *)(this + 17388) = 0;
    *(_DWORD *)(this + 17392) = 46;
    *(_DWORD *)(this + 17416) = 0;
    *(_DWORD *)(this + 17420) = 48;
    *(_DWORD *)(this + 18312) = 0;
    *(_DWORD *)(this + 18316) = 26;
    *(_DWORD *)(this + 18340) = 0;
    *(_DWORD *)(this + 18344) = 27;
    *(_DWORD *)(this + 18368) = 0;
    *(_DWORD *)(this + 18372) = 89;
    *(_DWORD *)(this + 17472) = 0;
    *(_DWORD *)(this + 17476) = 19;
    *(_DWORD *)(this + 17528) = 0;
    *(_DWORD *)(this + 17532) = 17;
    *(_DWORD *)(this + 18200) = 0;
    *(_DWORD *)(this + 18204) = 89;
    *(_DWORD *)(this + 17556) = 0;
    *(_DWORD *)(this + 17560) = 15;
    *(_DWORD *)(this + 17500) = 0;
    *(_DWORD *)(this + 17504) = 25;
    *(_DWORD *)(this + 17360) = 0;
    *(_DWORD *)(this + 17364) = 24;
    *(_DWORD *)(this + 17584) = 0;
    *(_DWORD *)(this + 17588) = 20;
    *(_DWORD *)(this + 17612) = 0;
    *(_DWORD *)(this + 17616) = 2;
    *(_DWORD *)(this + 17640) = 0;
    *(_DWORD *)(this + 17644) = 3;
    *(_DWORD *)(this + 17668) = 0;
    *(_DWORD *)(this + 17672) = 4;
    *(_DWORD *)(this + 17696) = 0;
    *(_DWORD *)(this + 17700) = 5;
    *(_DWORD *)(this + 17724) = 0;
    *(_DWORD *)(this + 17728) = 6;
    *(_DWORD *)(this + 17752) = 0;
    *(_DWORD *)(this + 17756) = 7;
    *(_DWORD *)(this + 17780) = 0;
    *(_DWORD *)(this + 17784) = 8;
    *(_DWORD *)(this + 17808) = 0;
    *(_DWORD *)(this + 17812) = 9;
    *(_DWORD *)(this + 17836) = 0;
    *(_DWORD *)(this + 17840) = 10;
    *(_DWORD *)(this + 17864) = 0;
    *(_DWORD *)(this + 17868) = 11;
    *(_DWORD *)(this + 17892) = 0;
    *(_DWORD *)(this + 17896) = 12;
    *(_DWORD *)(this + 17920) = 0;
    *(_DWORD *)(this + 17924) = 13;
  }
}
