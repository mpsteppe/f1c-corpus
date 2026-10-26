char __thiscall sub_40EBD0(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 4;
  *(_DWORD *)(this + 32) = a3;
  v6[0] = 0;
  v6[1] = 1072693248;
  v6[2] = 0;
  v6[3] = 1071644672;
  v6[4] = 0;
  v6[5] = 1073217536;
  sub_459950(10.0, (int)v6);
  sub_459990(0, 1085022208, 0, 1078853632, 0x40000000, 1071854387);
  result = a4;
  if ( a4 )
    return sub_40E770((_DWORD *)this, a4, 0);
  return result;
}
