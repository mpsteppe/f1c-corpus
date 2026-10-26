char __thiscall sub_4159E0(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[6]; // [esp+8h] [ebp-18h] BYREF

  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = a3;
  v6[0] = 0;
  v6[1] = 1070596096;
  v6[2] = -1717986918;
  v6[3] = 1070176665;
  v6[4] = 0;
  v6[5] = 1070596096;
  sub_45AA70(2.5, (int)v6);
  sub_45AAB0(1717986919, 1083590246, 0, 1079115776, -1610612736, 1072273817);
  result = a4;
  if ( a4 )
    return sub_415860((_DWORD *)this, a4, 0);
  return result;
}
