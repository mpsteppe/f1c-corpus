int __thiscall sub_5697F0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // [esp-Ch] [ebp-10h]
  int v6; // [esp-8h] [ebp-Ch]

  v2 = sub_587C03(56 * this[139]);
  v6 = 132 * this[141];
  this[140] = v2;
  this[139] = 0;
  v3 = sub_587C03(v6);
  v5 = 88 * this[143];
  this[142] = v3;
  this[141] = 0;
  result = sub_587C03(v5);
  this[144] = result;
  this[143] = 0;
  return result;
}
