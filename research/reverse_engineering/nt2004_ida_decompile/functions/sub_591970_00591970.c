int __thiscall sub_591970(void *this, int a2, int a3, int a4, char a5)
{
  char *v6; // eax
  void *v7; // eax
  int v8; // eax
  void *v9; // eax
  void *v10; // eax
  int v11; // eax

  dword_7E8D58 = 0;
  v6 = &byte_7E4CCC;
  do
  {
    *v6 = 0;
    v6 += 132;
  }
  while ( (int)v6 < (int)&dword_7E5D4C );
  dword_7E5D54 = 0;
  ElementCount = 0;
  dword_7E8E10 = -1;
  dword_7E8D60 = -1;
  dword_7E5D5C = 1;
  dword_7E8D38 = 1;
  dword_7E8D50 = 0;
  dword_7E8D40 = 1;
  dword_7E5D50 = 0;
  dword_7E8D70 = 0;
  dword_7E5EB8 = 0;
  dword_7E8D3C = 0;
  dword_7E8D5C = 0;
  dword_7E6B40 = 0;
  dword_7E8D4C = 0;
  dword_7E8D74 = 0;
  dword_7E5D48 = 0;
  dword_7E5EBC = 0;
  dword_7E8D48 = 0;
  dword_7E4CC0 = 0;
  dword_7E8CD8 = 0;
  dword_7E8CDC = 0;
  dword_7E8CE0 = 0;
  dword_7E8CE4 = 0;
  dword_7E8E4C = 0;
  dword_7E8E50 = 0;
  dword_7E8E54 = 0;
  if ( (a5 & 2) != 0 )
    goto LABEL_10;
  if ( (a5 & 4) != 0 )
  {
    dword_7E8C00 = 2;
    dword_7E8C04 = 1056964608;
    dword_7E8C08 = 1056964608;
LABEL_8:
    sub_5A47F0(-1, -1, 16000, 12000);
    goto LABEL_9;
  }
  if ( (a5 & 8) != 0 )
  {
    dword_7E8C00 = 3;
    dword_7E8C04 = 1051374440;
    dword_7E8C08 = 1051374440;
    goto LABEL_8;
  }
LABEL_9:
  sub_5A45F0((int)&unk_7E6B48);
  sub_5A96B0(a4, a5 & 1);
LABEL_10:
  v7 = operator new(0xA0u);
  if ( v7 )
    v8 = sub_5B75D0(v7);
  else
    v8 = 0;
  dword_7E8E38 = v8;
  sub_5B7620(this);
  sub_590460();
  sub_5ACA00(this);
  nullsub_6(this);
  dword_7E8D44 = 0;
  dword_7E5EC0 = 0;
  dword_7E8D54 = 0;
  dword_7E5D58 = 0;
  v9 = operator new(0xCu);
  if ( v9 )
    dword_7E8E60 = sub_5B1340(v9);
  else
    dword_7E8E60 = 0;
  v10 = operator new(0xCCu);
  if ( v10 )
    v11 = sub_5ADF00(v10);
  else
    v11 = 0;
  dword_7FBE80 = v11;
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)v11 + 4))(v11, aTahomaTtf);
  return 0;
}
