int __thiscall sub_597680(void *this, int *a2, int a3, int a4)
{
  void *v5; // eax
  int v6; // esi

  v5 = operator new(0xD0u);
  if ( v5 && (v6 = sub_5B58D0(v5)) != 0 )
  {
    if ( sub_5B5950(a3, a4) )
    {
      return -1;
    }
    else
    {
      sub_597730(v6, a4);
      if ( a2 )
        *a2 = v6;
      return 0;
    }
  }
  else
  {
    sub_591C60((int)this, -1, aCouldNotCreate_1);
    return -1;
  }
}
