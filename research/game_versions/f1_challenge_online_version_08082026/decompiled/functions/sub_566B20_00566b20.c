bool __thiscall sub_566B20(int *this, int a2, int a3)
{
  int v4; // eax
  bool v5; // bl
  char v7[1024]; // [esp+8h] [ebp-400h] BYREF

  sub_566B90(this);
  sub_568620(1024);
  v4 = sub_534B00();
  v5 = v4 != 0;
  *this = v4;
  this[4] = 1;
  this[3] = a3;
  *((_BYTE *)this + 24) = 1;
  if ( v4 )
    sub_566650((int)(this + 1), v7);
  return v5;
}
