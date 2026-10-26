char __thiscall sub_567F40(_DWORD *this, int a2, int a3)
{
  char v4; // bl
  int v6[7]; // [esp+8h] [ebp-1Ch] BYREF

  v4 = 0;
  sub_5668B0(v6);
  sub_566B20(v6, a2, 0);
  if ( v6[0] )
  {
    sub_567E10(this, (int)v6);
    v4 = sub_567BB0(v6, a3);
    sub_566B90(v6);
  }
  sub_5668D0(v6);
  return v4;
}
