// f1c  0x00432cf0  size=250
int __stdcall sub_432CF0(int a1, int a2, int a3)
{
  int v3; // eax
  char *v4; // eax
  char v6[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( !a1 )
    return 1;
  v3 = sub_4B0B10();
  sub_587DD0(v6, v3, 255);
  v6[255] = 0;
  v4 = &v6[strlen(v6)];
  if ( v4 > v6 )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= v6 )
        goto LABEL_7;
    }
    *v4 = 0;
  }
LABEL_7:
  if ( strlen(v6) + strlen(off_5C3F84[0]) >= 0x100 )
    return 1;
  strcat(v6, off_5C3F84[0]);
  sub_587DD0(a2, v6, a3 - 1);
  *(_BYTE *)(a3 - 1 + a2) = 0;
  return 0;
}
