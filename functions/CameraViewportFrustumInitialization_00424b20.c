int __thiscall sub_424B20(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edx
  int result; // eax
  int v6; // [esp+Ch] [ebp-4h]

  *(_DWORD *)(this + 16700) = 2139095039;
  *(_DWORD *)(this + 17520) = 0;
  *(_DWORD *)(this + 17528) = 0;
  *(_DWORD *)(this + 17524) = 1148829696;
  v2 = (_DWORD *)(this + 16820);
  v3 = (_DWORD *)(this + 17100);
  v4 = 5;
  do
  {
    *(v2 - 3) = 1232348144;
    *v3 = 0;
    *v2 = -1;
    *(v2 - 16) = 0;
    v3 += 7;
    v2 += 17;
    --v4;
  }
  while ( v4 );
  *(_DWORD *)(this + 17468) = 0;
  *(_DWORD *)(this + 17456) = 0;
  *(_DWORD *)(this + 17700) = 0;
  *(_DWORD *)(this + 17504) = -1082130432;
  *(_DWORD *)(this + 17508) = 1065353216;
  AIClearStateFlags(this);
  *(_DWORD *)(this + 17496) = -1;
  *(_DWORD *)(this + 17584) = -1;
  v6 = -*(_DWORD *)(this + 4);
  *(_DWORD *)(this + 17452) = 0;
  *(_DWORD *)(this + 17540) = 1232348144;
  *(_DWORD *)(this + 17720) = 1232348144;
  *(float *)(this + 17492) = (double)v6 * 7.0;
  *(_DWORD *)(this + 17728) = 1086324736;
  *(_DWORD *)(this + 17732) = 1;
  *(_BYTE *)(this + 17736) = 0;
  *(_DWORD *)(this + 17740) = 0;
  *(_DWORD *)(this + 17744) = 0;
  *(_DWORD *)(this + 17748) = 1065353216;
  *(_DWORD *)(this + 17680) = 0;
  *(_DWORD *)(this + 17752) = 50;
  *(_DWORD *)(this + 17760) = 0;
  *(_DWORD *)(this + 17764) = 0;
  *(_DWORD *)(this + 17412) = -1082130432;
  *(_DWORD *)(this + 17516) = 0;
  *(_DWORD *)(this + 17400) = 0;
  *(_BYTE *)(this + 17908) = 0;
  *(_DWORD *)(this + 17948) = 1232348144;
  AICommandMessageQueueDispatcher(0, 0);
  *(_DWORD *)(this + 17484) = 0;
  AIRingBufferFieldInit(this);
  result = sub_426430(this);
  *(_BYTE *)(this + 17796) = 0;
  return result;
}
