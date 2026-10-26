int __thiscall sub_54BE60(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // edi
  _DWORD *v3; // ebx
  int v4; // ebp
  int v5; // ebx
  _DWORD *v6; // edi
  const CHAR *v7; // eax
  _DWORD *v9; // [esp+14h] [ebp-14h]

  v1 = &this[994654 * this[994657]];
  *v1 = dword_B64140;
  v1[37] = dword_B64134;
  v1[35] = dword_B640C0;
  v1[36] = *(_DWORD *)dword_B640C8;
  *((_BYTE *)v1 + 152) = byte_B6F118;
  v9 = v1 + 39;
  *((float *)v1 + 34) = sub_552900(&unk_FADD40);
  sub_54B910();
  sub_553730(v1 + 188);
  sub_52B1B0(&byte_9034D0, (int)(v1 + 648));
  sub_5945B0(v1 + 994215);
  v2 = 0;
  if ( dword_757C10 > 0 )
  {
    v3 = v1 + 880;
    do
    {
      ((void (__thiscall *)(_DWORD, _DWORD *, _DWORD *))dword_53F290)(*(&dword_91E088 + v2++), v3, v9);
      v3 += 9460;
    }
    while ( v2 < dword_757C10 );
  }
  sub_439E20((int)&dbl_B66040, (int)(v1 + 654));
  v4 = 0;
  if ( dword_757C14 > 0 )
  {
    v5 = 0;
    v6 = v1 + 984720;
    do
    {
      ((void (__thiscall *)(char *, _DWORD *))dword_53F290)((char *)off_757C18 + v5, v6);
      ++v4;
      v6 += 9460;
      v5 += 22616;
    }
    while ( v4 < dword_757C14 );
  }
  *((_BYTE *)v1 + 3976720) = *(_DWORD *)(dword_91E084 + 14820) == 1;
  v7 = sub_410A10(&dword_91BF20);
  sub_630FE0(v1 + 994183, v7, 127);
  *((_BYTE *)v1 + 3976859) = 0;
  sub_410B50(&dword_91BF20);
  return off_16C9834();
}
