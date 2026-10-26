char __thiscall sub_418190(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[2]; // [esp+20h] [ebp-18h] BYREF
  double v7; // [esp+28h] [ebp-10h]
  double v8; // [esp+30h] [ebp-8h]

  *(double *)v6 = 0.7;
  v7 = 0.5;
  v8 = 0.5;
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 3;
  *(_DWORD *)(this + 36) = a3;
  sub_470090(15.0, (int)v6);
  sub_46FE40(5625.0, 45.0, 1.0);
  result = a4;
  if ( a4 )
    return sub_417E90((_DWORD *)this, a4, 0);
  return result;
}
