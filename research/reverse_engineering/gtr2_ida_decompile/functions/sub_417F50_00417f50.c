char __thiscall sub_417F50(int this, __int16 a2, int a3, int a4)
{
  char result; // al
  int v6[2]; // [esp+20h] [ebp-18h] BYREF
  double v7; // [esp+28h] [ebp-10h]
  double v8; // [esp+30h] [ebp-8h]

  *(double *)v6 = 0.25;
  v7 = 0.2;
  v8 = 0.25;
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = a3;
  sub_470090(2.5, (int)v6);
  sub_46FE40(1425.6, 72.0, 0.800000011920929);
  result = a4;
  if ( a4 )
    return sub_417E90((_DWORD *)this, a4, 0);
  return result;
}
