int __thiscall sub_51D6C0(_DWORD **this, _DWORD *a2, _DWORD *a3)
{
  int result; // eax
  float v5; // [esp+0h] [ebp-14h]
  float v6; // [esp+0h] [ebp-14h]
  float v7; // [esp+4h] [ebp-10h]
  float v8; // [esp+4h] [ebp-10h]

  sub_5E5190(1);
  sub_4CD350(this[1], 0);
  v7 = (float)(int)a2[2];
  v5 = (float)(int)a2[1];
  sub_5E53E0(0.0, 0.0, v5, v7, 0);
  sub_5E55E0(a2);
  *a2 |= 0x40u;
  sub_5E5190(1);
  sub_4CD350(*this, 0);
  v8 = (float)(int)a3[2];
  v6 = (float)(int)a3[1];
  sub_5E53E0(0.0, 0.0, v6, v8, 0);
  result = sub_5E55E0(a3);
  *a3 |= 0x40u;
  return result;
}
