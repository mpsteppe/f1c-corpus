int __thiscall sub_418900(int this, char *Str)
{
  int v3; // ebp
  int v4; // edi
  int v5; // eax
  char *i; // eax
  int v8; // [esp-4h] [ebp-18h]
  _BYTE v9[4]; // [esp+10h] [ebp-4h] BYREF

  sub_4189D0();
  v3 = 0;
  sub_578870(v9);
  sub_578A30(aHdr, 1, Str, 1);
  v4 = sub_578A20(v9);
  if ( v4 > 0 )
  {
    *(_DWORD *)this = operator new(48 * v4);
    *(_DWORD *)(this + 4) = v4;
    v5 = 0;
    do
    {
      *(_WORD *)(v5 + *(_DWORD *)this) = -1;
      *(_BYTE *)(v5 + *(_DWORD *)this + 2) = 0;
      *(_DWORD *)(v5 + *(_DWORD *)this + 44) = 0;
      v5 += 48;
      --v4;
    }
    while ( v4 );
    for ( i = (char *)sub_578D80(v9); i; i = (char *)sub_578D80(v9) )
    {
      v8 = v3++;
      sub_418720((_DWORD *)this, Str, i, v8);
      sub_5789D0(v9);
    }
    strcpy((char *)(this + 8), Str);
  }
  return sub_5788D0(v9);
}
