char __thiscall sub_4FA1A0(_BYTE *this)
{
  char v2; // bl
  unsigned int v4; // eax
  char *v5; // esi
  double v6; // st7
  _DWORD *v7; // ecx
  int v8; // esi
  float *v9; // ecx
  double v10; // st7
  double v11; // st6
  int v12; // [esp+0h] [ebp-34h]
  int v13; // [esp+0h] [ebp-34h]
  float v14; // [esp+14h] [ebp-20h]
  float v15; // [esp+18h] [ebp-1Ch]
  float v16[3]; // [esp+1Ch] [ebp-18h] BYREF
  _DWORD v17[3]; // [esp+28h] [ebp-Ch] BYREF

  v2 = this[189];
  this[189] = 0;
  if ( off_5FD348 && *((int *)off_5FD348 + 6312) >= 0 && (unsigned __int8)sub_4BBF20() )
    return 0;
  v4 = sub_4F83E0(byte_7D758C, 0);
  if ( v4 >= 0x30 )
  {
LABEL_28:
    if ( dbl_7DA9D0 >= flt_7D7898 + 5.0 )
      return 1;
    this[189] = 1;
    return 0;
  }
  v5 = (char *)&unk_62BF68 + 25304 * v4;
  v6 = sub_51C900(v5 + 84);
  v14 = v6;
  v15 = flt_6290D0;
  if ( v6 >= flt_6290D0 * 0.75 )
  {
    sub_404590(&flt_628F60, 0, v16, v17);
    if ( v16[0] != 0.0 || v16[1] != 0.0 || v16[2] != 0.0 )
    {
      v9 = sub_403D10(&flt_628F60, v16, *((_DWORD *)v5 + 4771));
      if ( v9 )
      {
        if ( v15 - 20.0 > v14 )
        {
          v10 = v14;
          v11 = v15 * 0.5;
          if ( v9[29] + v11 >= v14 )
          {
            if ( v14 < v9[29] - v11 )
              v10 = v15 + v14;
          }
          else
          {
            v10 = v14 - v15;
          }
          if ( v10 < v9[29] + 20.0 )
            return 0;
        }
      }
    }
    goto LABEL_28;
  }
  if ( *((_DWORD *)v5 + 5279) != 1 || !v2 )
    return 0;
  v7 = (_DWORD *)dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v12 = dbl_7DA9D0;
  sub_4D0D00(v7, 4, 40, 0, 63, v12, 3);
  if ( !sub_463490(dword_764D70) )
  {
    sub_45D100(&byte_764D68, (int)aWithholdingGre, 3, 16909060, 0);
    return 0;
  }
  v8 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v13 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v8, 4, 6, 54, 63, v13, 0);
  strcpy((char *)(v8 + 8), aWithholdingGre);
  return 0;
}
