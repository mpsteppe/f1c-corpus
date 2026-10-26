int __thiscall sub_5E7F70(void *this, int a2)
{
  char v4; // [esp+0h] [ebp-4h]

  if ( a2 )
  {
    if ( (*(_DWORD *)(a2 + 108))-- == 1 )
    {
      sub_5E6DD0();
      sub_5DB730((int *)&dword_FB289C, a2, 1);
    }
    return 0;
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid surface pointer", v4);
    return -1;
  }
}
