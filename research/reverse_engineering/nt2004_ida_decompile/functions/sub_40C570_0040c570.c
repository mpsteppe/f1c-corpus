int __fastcall sub_40C570(int a1, unsigned int a2)
{
  int v4; // edi
  int v5; // eax
  char *v6; // eax

  if ( !a1 )
    return -1;
  v4 = 0;
  if ( ((int (*)(void))sub_57A6E0)() <= 0 )
    return -1;
  while ( 1 )
  {
    v5 = sub_57A700(v4);
    if ( v5 )
    {
      v6 = (char *)sub_57A6C0(v5);
      if ( sub_40C4D0(v6, a2) )
        break;
    }
    if ( ++v4 >= sub_57A6E0(a1) )
      return -1;
  }
  return v4;
}
