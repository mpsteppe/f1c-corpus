_DWORD *__fastcall sub_5BA500(int a1, int a2, __int16 a3)
{
  _DWORD *v4; // esi
  int v6; // eax

  v4 = malloc(0x24u);
  if ( !v4 )
    return 0;
  v6 = sub_5BDF40(4, sub_5BA5A0, sub_5BA050, sub_5BA580);
  v4[6] = v6;
  if ( v6 )
  {
    *v4 = a2;
    *((_WORD *)v4 + 2) = a3;
    *((_BYTE *)v4 + 20) = 0;
    *((_BYTE *)v4 + 21) = 0;
    v4[8] = 0;
    v4[7] = 0;
    v4[4] = 0;
    v4[2] = 0;
    *((_WORD *)v4 + 6) = 0;
    return v4;
  }
  else
  {
    sub_5C1B88(v4);
    return 0;
  }
}
