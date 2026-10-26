char __thiscall sub_418B00(char *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  unsigned int v5; // eax
  _DWORD *v6; // eax
  void *v7; // eax
  char Buffer[253]; // [esp+Ch] [ebp-100h] BYREF
  __int16 v10; // [esp+109h] [ebp-3h]
  char v11; // [esp+10Bh] [ebp-1h]

  v2 = sub_58D360(22050, 16, 0);
  sub_58D410((char *)&loc_418BEF + 1, 0, v2);
  v3 = sub_4188C0(this);
  v4 = v3;
  if ( v3 > 0 )
  {
    v5 = sub_58CDB0(v3);
    dword_629314 = (int)operator new(v5);
    sub_58CDC0(v4, dword_629314);
  }
  v6 = (_DWORD *)sub_58D330();
  *v6 = nullsub_6;
  v6[1] = sub_47DE30;
  v6[2] = sub_418AF0;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v10 = 0;
  v11 = 0;
  sprintf(Buffer, "%s%s", this, aEventdatEvents);
  v7 = sub_418840(Buffer, 0);
  dword_629318 = (int)v7;
  if ( !v7 || !sub_58D210(v7, 0) )
    return 0;
  sub_418900((int)&unk_629248, this);
  return 1;
}
