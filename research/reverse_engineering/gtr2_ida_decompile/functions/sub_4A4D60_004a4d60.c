int __thiscall sub_4A4D60(void *this)
{
  char *v1; // eax
  int v3; // edi
  _BYTE v5[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v6; // [esp+45h] [ebp-3h]
  char v7; // [esp+47h] [ebp-1h]

  v1 = dword_B6F708;
  if ( !dword_B6F708 )
    v1 = (char *)WindowName;
  v3 = sub_539670(v1);
  (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 184))(this, *(_DWORD *)(v3 + 132));
  (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 180))(this, *(_DWORD *)(v3 + 136));
  memset(v5, 0, sizeof(v5));
  v6 = 0;
  v7 = 0;
  sub_615860(v5);
  return 0;
}
