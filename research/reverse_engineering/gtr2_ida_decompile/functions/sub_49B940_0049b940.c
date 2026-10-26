int __thiscall sub_49B940(void *this)
{
  int v2; // eax
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  bool v8; // [esp+4h] [ebp-4h]

  v8 = 1;
  v2 = sub_532D20(&unk_B76270);
  if ( v2 )
    v8 = *(_DWORD *)(v2 + 95732) != 2;
  v3 = (_DWORD *)sub_616840("UnlockGold");
  if ( v3 )
  {
    v4 = sub_48D380(v3);
    if ( atol(v4) > dword_B76220 )
      v8 = 1;
  }
  v5 = (_DWORD *)sub_616840("UnlockPass");
  if ( v5 )
  {
    v6 = sub_48D380(v5);
    if ( atol(v6) > dword_B76220 + dword_B76224 )
      v8 = 1;
  }
  (*(void (__thiscall **)(void *, bool))(*(_DWORD *)this + 36))(this, v8);
  return 0;
}
