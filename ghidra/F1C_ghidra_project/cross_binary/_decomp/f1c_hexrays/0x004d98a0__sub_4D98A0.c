// f1c  0x004d98a0  size=316
int __thiscall sub_4D98A0(float *this)
{
  int v2; // edi
  unsigned int v3; // eax
  CHAR *v4; // eax
  CHAR v5; // cl
  CHAR *v6; // eax
  CHAR v7; // dl
  CHAR SrcStr[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_8AFE98;
  v2 = dword_7C54E0;
  if ( dword_7C54E0 )
  {
    v3 = *(_DWORD *)(dword_7C54E0 + 16480) - 1;
    if ( v3 <= 0x18 )
    {
      sub_58815F(SrcStr, "%c", (char)(v3 + byte_5D4AE8));
      sub_4D7E40((int)SrcStr, 100, 818, 0xFFFFFF, 0, 3, 3.0, 3.0);
    }
    v4 = (CHAR *)(v2 + 18168);
    do
    {
      v5 = *v4;
      SrcStr[(_DWORD)v4 - 18168 - v2] = *v4;
      ++v4;
    }
    while ( v5 );
    sub_589901(SrcStr);
    sub_4D7E40((int)SrcStr, 210, 818, 0xFFFFFF, 0, 0, 1.0, 1.0);
    v6 = (CHAR *)(v2 + 18104);
    do
    {
      v7 = *v6;
      SrcStr[(_DWORD)v6 - 18104 - v2] = *v6;
      ++v6;
    }
    while ( v7 );
    sub_589901(SrcStr);
    sub_4D7E40((int)SrcStr, 210, 858, 4762291, 0, 0, 1.0, 1.0);
  }
  return 0;
}
