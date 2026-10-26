// f1c  0x00477aa0  size=199
int __thiscall sub_477AA0(char *this)
{
  char *v2; // esi
  _BYTE *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // esi
  int v9; // [esp-4h] [ebp-10h]

  v2 = this + 384;
  v3 = (_BYTE *)sub_49A2B0(this + 384);
  if ( sub_5681F0(aGameFilter) )
  {
    v9 = sub_5681F0(aGameFilter);
    v4 = sub_49A2B0(v2);
    if ( !sub_588410(v4, v9) )
      goto LABEL_7;
LABEL_6:
    (*(void (__thiscall **)(char *))(*(_DWORD *)this + 160))(this);
    goto LABEL_7;
  }
  if ( v3 && *v3 )
    goto LABEL_6;
LABEL_7:
  v5 = sub_48F590(this);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 60);
    if ( v6 )
    {
      v7 = (const char *)dword_7CE5EC;
      if ( !dword_7CE5EC )
        v7 = byte_5EA438;
      if ( strcmp((const char *)(v6 + 260), v7) )
        sub_477BA0(this);
    }
  }
  return 0;
}
