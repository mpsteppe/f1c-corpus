int __stdcall sub_4B0220(const char *a1, int a2)
{
  unsigned int v2; // kr04_4
  const char *i; // eax
  _BYTE v5[512]; // [esp+8h] [ebp-200h] BYREF

  if ( !a1 || !a2 )
    return -1;
  sub_568620(512);
  sub_587DD0(a1, v5, a2 - 1);
  a1[a2 - 1] = 0;
  v2 = strlen(a1) + 1;
  if ( (int)(v2 - 1) > 0 )
  {
    for ( i = &a1[v2 - 2]; i >= a1; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  return 0;
}

