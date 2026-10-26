char __thiscall sub_415A80(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 1;
  *(_DWORD *)(this + 36) = a3;
  v6[0] = 0;
  v6[1] = 1071644672;
  v6[2] = -1717986918;
  v6[3] = 1069128089;
  v6[4] = 0;
  v6[5] = 1071644672;
  sub_45AA70(1.2, (int)v6);
  sub_45AAB0(0, 1081671680, 0, 1078198272, -1610612736, 1072273817);
  result = a4;
  if ( a4 )
    return sub_415860((_DWORD *)this, a4, 0);
  return result;
}
