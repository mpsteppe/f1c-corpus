// f1c  0x0040eb30  size=151
char __thiscall sub_40EB30(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 3;
  *(_DWORD *)(this + 32) = a3;
  v6[0] = 1717986918;
  v6[1] = 1072064102;
  v6[2] = 0;
  v6[3] = 1071644672;
  v6[4] = 0;
  v6[5] = 1071644672;
  sub_459950(15.0, (int)v6);
  sub_459990(0, 1085667584, 0, 1078362112, 0, 1072693248);
  result = a4;
  if ( a4 )
    return sub_40E770((_DWORD *)this, a4, 0);
  return result;
}
