int __thiscall sub_429200(int this, int a2)
{
  int v3; // eax
  BOOL v4; // edx
  _DWORD *v5; // eax
  bool v6; // cc
  bool v7; // zf
  double v8; // st7
  double v9; // st7
  int result; // eax
  _BYTE v11[12]; // [esp+14h] [ebp-Ch] BYREF
  int v12; // [esp+24h] [ebp+4h]

  if ( (unsigned __int8)sub_54FE30(*(_DWORD *)this, v11, v11) )
    *(_DWORD *)(this + 20572) = 1176256410;
  else
    *(_DWORD *)(this + 20572) = 0;
  *(float *)(this + 20900) = (double)(rand() % 8) + 2.0;
  v3 = rand();
  *(_DWORD *)(this + 20392) = 0;
  *(_DWORD *)(this + 20756) = 0;
  *(_DWORD *)(this + 20384) = 0;
  *(_DWORD *)(this + 20552) = 0;
  *(_DWORD *)(this + 20560) = 0;
  *(_DWORD *)(this + 20556) = 1148829696;
  *(_DWORD *)(this + 19648) = 2139095039;
  *(float *)(this + 20904) = (double)(v3 % 50) * 0.0049999999 + 0.1;
  *(_DWORD *)(this + 19756) = 1232348144;
  *(_DWORD *)(this + 20048) = 0;
  *(_DWORD *)(this + 19768) = -1;
  *(_DWORD *)(this + 19704) = 0;
  *(_DWORD *)(this + 19824) = 1232348144;
  *(_DWORD *)(this + 20076) = 0;
  *(_DWORD *)(this + 19836) = -1;
  *(_DWORD *)(this + 19772) = 0;
  *(_DWORD *)(this + 19892) = 1232348144;
  *(_DWORD *)(this + 20104) = 0;
  *(_DWORD *)(this + 19904) = -1;
  *(_DWORD *)(this + 19840) = 0;
  *(_DWORD *)(this + 19960) = 1232348144;
  *(_DWORD *)(this + 20132) = 0;
  *(_DWORD *)(this + 19972) = -1;
  *(_DWORD *)(this + 19908) = 0;
  *(_DWORD *)(this + 20028) = 1232348144;
  *(_DWORD *)(this + 20160) = 0;
  *(_DWORD *)(this + 20040) = -1;
  *(_DWORD *)(this + 19976) = 0;
  *(_DWORD *)(this + 20516) = 2139095039;
  *(_DWORD *)(this + 20520) = 2139095039;
  *(_DWORD *)(this + 20472) = 0;
  *(_DWORD *)(this + 20456) = 0;
  *(_DWORD *)(this + 20788) = 0;
  *(_DWORD *)(this + 20508) = -1082130432;
  *(_DWORD *)(this + 20512) = 0;
  *(_DWORD *)(this + 20524) = 0;
  *(_DWORD *)(this + 20528) = 0;
  *(_DWORD *)(this + 20532) = 0;
  *(_DWORD *)(this + 20536) = 1065353216;
  *(_DWORD *)(this + 20540) = 1065353216;
  *(_DWORD *)(this + 20184) = 0;
  *(_DWORD *)(this + 20188) = 0;
  *(_DWORD *)(this + 20192) = 0;
  *(_DWORD *)(this + 20196) = 0;
  *(_DWORD *)(this + 20200) = 0;
  *(_DWORD *)(this + 20204) = 0;
  *(_DWORD *)(this + 20208) = 0;
  *(_DWORD *)(this + 20212) = 0;
  *(_DWORD *)(this + 20216) = 0;
  *(_DWORD *)(this + 20220) = 0;
  *(_DWORD *)(this + 20224) = 0;
  *(_DWORD *)(this + 20228) = 0;
  *(_DWORD *)(this + 20232) = 0;
  *(_DWORD *)(this + 20236) = 0;
  *(_DWORD *)(this + 20240) = 0;
  *(_DWORD *)(this + 20244) = 0;
  *(_DWORD *)(this + 20248) = 0;
  *(_DWORD *)(this + 20252) = 0;
  *(_DWORD *)(this + 20256) = 0;
  *(_DWORD *)(this + 20260) = 0;
  *(_DWORD *)(this + 20452) = 0;
  *(_DWORD *)(this + 20576) = 1232348144;
  v4 = a2 != 0;
  v12 = -*(_DWORD *)(this + 4);
  *(_DWORD *)(this + 20828) = 1232348144;
  *(_DWORD *)(this + 21560) = 1232348144;
  v5 = *(_DWORD **)(this + 20612);
  *(_DWORD *)(this + 20424) = 0;
  *(_DWORD *)(this + 20836) = 1086324736;
  *(float *)(this + 20496) = (double)v12 * 7.0;
  *(_DWORD *)(this + 20840) = 1;
  *(_BYTE *)(this + 20844) = 0;
  *(_DWORD *)(this + 20848) = 0;
  *(_DWORD *)(this + 20852) = v4;
  *(_DWORD *)(this + 20768) = 0;
  *(_DWORD *)(this + 20856) = 50;
  *(_DWORD *)(this + 20864) = 0;
  *(_DWORD *)(this + 20868) = 0;
  *(_DWORD *)(this + 20364) = -1082130432;
  *(_DWORD *)(this + 20500) = -1;
  *(_DWORD *)(this + 20620) = -1;
  *(_DWORD *)(this + 20548) = 0;
  *(_BYTE *)(this + 21516) = 0;
  if ( v5 )
  {
    v6 = *(_DWORD *)(this + 20616) <= 0;
    *(_DWORD *)(this + 20620) = 0;
    if ( v6 )
    {
      *(_DWORD *)(this + 20620) = -1;
    }
    else
    {
      *v5 = 0;
      *(_DWORD *)(*(_DWORD *)(this + 20612) + 8 * *(_DWORD *)(this + 20620) + 4) = 0;
      sub_427710(this);
      v7 = *(_DWORD *)(this + 19380) == 2;
      *(_DWORD *)(this + 20620) = -1;
      if ( v7 )
        *(_BYTE *)(this + 21516) = 0;
    }
  }
  *(_DWORD *)(this + 20488) = 0;
  v8 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
  *(float *)(this + 20484) = v8 + 0.15000001 - (double)dword_B71FD8 * 0.0099999998 * 0.1;
  sub_427DB0((char *)this);
  v9 = *(float *)(this + 20448);
  result = *(_DWORD *)(*(_DWORD *)(this + 20184) + 28);
  *(float *)(this + 20380) = *(float *)(this + 20448);
  *(float *)(this + 20388) = v9;
  *(_BYTE *)(this + 20908) = 0;
  *(_DWORD *)(this + 20376) = result;
  *(_DWORD *)(this + 20396) = 1065353216;
  return result;
}
