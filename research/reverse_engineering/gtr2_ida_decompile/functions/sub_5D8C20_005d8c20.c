int __thiscall sub_5D8C20(void *this, int a2, int a3, int a4)
{
  float v6[16]; // [esp+8h] [ebp-40h] BYREF

  sub_5ABD7E();
  if ( a2 )
    return sub_5D7870(a2, v6, a4);
  else
    return sub_5D7870((int)this + 4, v6, a4);
}
