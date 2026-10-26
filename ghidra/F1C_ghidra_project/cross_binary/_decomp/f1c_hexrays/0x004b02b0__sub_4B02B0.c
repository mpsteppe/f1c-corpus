// f1c  0x004b02b0  size=214
int __thiscall sub_4B02B0(_DWORD *this, char *a2, unsigned int a3)
{
  const char *v4; // esi
  char *v5; // ecx

  if ( !a2 || !a3 )
    goto LABEL_13;
  sub_4B0220(a2, a3);
  v4 = (const char *)this[2023];
  if ( !v4 )
    v4 = byte_5EA438;
  if ( a3 <= strlen(a2) + strlen(v4) )
    goto LABEL_13;
  strcat(a2, v4);
  v5 = &a2[strlen(a2)];
  if ( v5 > a2 )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= a2 )
        goto LABEL_11;
    }
    *v5 = 0;
  }
LABEL_11:
  if ( a3 > strlen(a2) + 5 )
  {
    strcat(a2, ".bch");
    return 0;
  }
  else
  {
LABEL_13:
    *a2 = 0;
    return -1;
  }
}
