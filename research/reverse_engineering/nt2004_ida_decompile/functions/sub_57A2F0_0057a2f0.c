bool __thiscall sub_57A2F0(int *this, char *Source, int a3)
{
  int v4; // eax
  bool v5; // bl
  char v7[1024]; // [esp+8h] [ebp-400h] BYREF

  sub_57A360(this);
  sub_57B040(Source, 1024);
  v4 = sub_536110();
  v5 = v4 != 0;
  *this = v4;
  this[4] = 1;
  this[3] = a3;
  *((_BYTE *)this + 24) = 1;
  if ( v4 )
    sub_578600((int)(this + 1), v7);
  return v5;
}
