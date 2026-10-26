// f1c  0x0058cf35  size=280
int __cdecl sub_58CF35(unsigned __int8 a1, _DWORD *a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  char *v6; // eax
  signed int v7; // edi
  _BYTE *v8; // eax

  v2 = a2;
  v3 = a2[3];
  v4 = a2[4];
  if ( (v3 & 0x82) == 0 || (v3 & 0x40) != 0 )
    goto LABEL_24;
  if ( (v3 & 1) == 0 )
    goto LABEL_6;
  a2[1] = 0;
  if ( (v3 & 0x10) == 0 )
  {
LABEL_24:
    LOBYTE(v3) = v3 | 0x20;
    v2[3] = v3;
    return -1;
  }
  LOBYTE(v3) = v3 & 0xFE;
  *v2 = v2[2];
  v2[3] = v3;
LABEL_6:
  v5 = v2[3];
  v2[1] = 0;
  a2 = 0;
  LOBYTE(v5) = v5 & 0xED | 2;
  v2[3] = v5;
  if ( (v5 & 0x10C) == 0 && (v2 != (_DWORD *)&unk_5E6768 && v2 != (_DWORD *)&unk_5E6788 || !sub_596007(v4)) )
    sub_5957BD(v2);
  if ( (v2[3] & 0x108) != 0 )
  {
    v6 = (char *)v2[2];
    v7 = *v2 - (_DWORD)v6;
    *v2 = v6 + 1;
    v2[1] = v2[6] - 1;
    if ( v7 <= 0 )
    {
      if ( v4 == -1 )
        v8 = &unk_5E7898;
      else
        v8 = (_BYTE *)(dword_8D4920[v4 >> 5] + 36 * (v4 & 0x1F));
      if ( (v8[4] & 0x20) != 0 )
        sub_58C724(v4, 0, 2u);
    }
    else
    {
      a2 = (_DWORD *)sub_58E22B(v4, v6, v7);
    }
    *(_BYTE *)v2[2] = a1;
  }
  else
  {
    v7 = 1;
    a2 = (_DWORD *)sub_58E22B(v4, &a1, 1u);
  }
  if ( a2 == (_DWORD *)v7 )
    return a1;
  v2[3] |= 0x20u;
  return -1;
}
