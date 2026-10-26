int __thiscall sub_4C2A80(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  float v6; // ebx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // [esp+8h] [ebp-4h]

  result = sub_42BC10();
  if ( !(_BYTE)result || dword_8AB6E4 == 2 )
    return result;
  v3 = dword_8AC490 + 396 * dword_8AC48C;
  if ( v3 )
    v4 = sub_4C28D0(this, v3 + 4);
  else
    v4 = v11;
  if ( !v4 )
    goto LABEL_11;
  *(_DWORD *)(v4 + 16) += *(_DWORD *)(dword_7C54E8 + 16444);
  v5 = dword_7C54E8;
  if ( *(float *)(dword_7C54E8 + 16540) > 0.0
    && (*(float *)(dword_7C54E8 + 16540) < (double)*(float *)(v4 + 20) || *(float *)(v4 + 20) <= 0.0) )
  {
    *(float *)(v4 + 20) = *(float *)(dword_7C54E8 + 16540);
LABEL_11:
    v5 = dword_7C54E8;
  }
  result = sub_4C2BE0(*(_DWORD *)(v5 + 16444));
  if ( dword_7C56A4 == 7 )
  {
    v6 = *(float *)(dword_7C54E8 + 16480);
    sub_4C2CB0(v6);
    if ( LODWORD(v6) == 1 )
      sub_4C2C20(this);
    result = dword_7D0410;
    if ( dword_7D0410 == 4 || dword_7D0410 == 3 )
    {
      v7 = dword_7C54E8;
      v8 = 0;
      if ( *(_DWORD *)(dword_7C54E8 + 16484) != 3
        && *(_DWORD *)(v7 + 16444) >= sub_587BDC((double)dword_8ACF8C * 0.89999998)
        && sub_568210(aSeasonscoringi) )
      {
        v9 = sub_5679A0(LODWORD(v6) - 1);
        if ( v9 )
        {
          v10 = sub_567970(v9);
          v8 = sub_587ECE(v10);
        }
      }
      return sub_4C2C00(v8);
    }
  }
  return result;
}
