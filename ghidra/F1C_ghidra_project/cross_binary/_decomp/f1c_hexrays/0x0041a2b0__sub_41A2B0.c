// f1c  0x0041a2b0  size=235
void __thiscall sub_41A2B0(_DWORD *this, int a2)
{
  unsigned __int8 v3; // al
  int v4; // ecx
  int v5; // ecx
  float v6[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
  {
    sub_4144D0(v6);
    v3 = *(_BYTE *)(a2 + 16444) + 1;
    v4 = dword_7C56A4;
    if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a2 + 18580) )
      goto LABEL_15;
    if ( dword_7C56A4 == 5 )
    {
      if ( v3 < 0xCu )
      {
        if ( *(_BYTE *)(a2 + 16444) == 0xFF )
          goto LABEL_15;
        v5 = 21;
      }
      else
      {
        v5 = 22;
      }
    }
    else
    {
      if ( dword_7C56A4 <= 5 || dword_7C56A4 > 7 )
        goto LABEL_15;
      v5 = 178;
      if ( *(_DWORD *)(a2 + 16480) == 1 )
        v5 = 179;
    }
    sub_4144F0(v6, v5, *(_DWORD *)(a2 + 18588), v3, -1, -1, -2.0, -2.0);
    sub_418560(flt_5EA618, v6);
    v4 = dword_7C56A4;
LABEL_15:
    if ( v4 == 5 )
      sub_4198B0(this, (_DWORD *)a2);
  }
}
