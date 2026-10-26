char __thiscall sub_5503D0(_BYTE *this)
{
  char v2; // bl
  int v4; // eax
  char *v5; // esi
  _DWORD *v6; // eax
  char *v7; // eax
  char *v8; // esi
  char *v9; // eax
  int v10; // [esp+4h] [ebp-34h]
  int v11; // [esp+4h] [ebp-34h]
  float v12[3]; // [esp+20h] [ebp-18h] BYREF
  int v13[3]; // [esp+2Ch] [ebp-Ch] BYREF

  v2 = this[280];
  this[280] = 0;
  if ( off_757C18 && *((int *)off_757C18 + 5617) >= 0 && byte_9034D0 )
    return 0;
  if ( dword_FAE5A8 > 0 && (v4 = dword_FAE268, dword_FAE268 >= 0)
    || dword_FAE264 > 0 && (v4 = dword_FADF24, dword_FADF24 >= 0) )
  {
    if ( v4 >= 104 )
    {
LABEL_20:
      if ( dbl_FB1D18 >= flt_FAE5AC + 5.0 )
        return 1;
      this[280] = 1;
      return 0;
    }
  }
  else
  {
    v4 = 0;
  }
  v5 = (char *)&unk_9204A0 + 22616 * v4;
  if ( sub_577D40(v5 + 16) >= flt_91BDE4 * 0.75 )
  {
    sub_4013C0(&flt_91BCA0, 0, v12, v13);
    if ( !sub_4011C0(v12) )
      return off_16C9430();
    goto LABEL_20;
  }
  if ( *((_DWORD *)v5 + 4888) == 1 && v2 )
  {
    v6 = (_DWORD *)sub_416730(&dword_82F4A0);
    *(float *)&v10 = dbl_FB1D18;
    sub_51B2A0(v6, 4, 36, 0, 255, v10, 3);
    if ( (unsigned __int8)sub_4735A0() )
    {
      v7 = (char *)sub_416730(&dword_82F4A0);
      *(float *)&v11 = dbl_FB1D18;
      v8 = v7;
      sub_51B2A0(v7, 4, 6, 23, 255, v11, 0);
      strcpy(v8 + 8, "Cannot Wave Green Yet");
      return 0;
    }
    v9 = sub_41D840(&byte_91CC38, "Cannot Wave Green Yet");
    sub_4730C0((int **)&dword_B6CB98, v9, 3, (int)&byte_1020304, 1084227584);
  }
  return 0;
}
