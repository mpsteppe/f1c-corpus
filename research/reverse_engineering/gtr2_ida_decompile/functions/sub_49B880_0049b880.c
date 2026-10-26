int __thiscall sub_49B880(void *this)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  _DWORD *v6; // eax
  char *v7; // eax
  char v9; // [esp+4h] [ebp-4h]

  v9 = 0;
  v2 = sub_532D20(&unk_B76270);
  if ( v2 && *(_DWORD *)(v2 + 95732) == 2 )
    v3 = sub_4CFC00(1);
  else
    v3 = sub_4CFC00(0);
  sub_615860(v3);
  v4 = (_DWORD *)sub_616840("UnlockGold");
  if ( v4 )
  {
    v5 = sub_48D380(v4);
    if ( atol(v5) > dword_B76220 )
      v9 = 1;
  }
  v6 = (_DWORD *)sub_616840("UnlockPass");
  if ( v6 )
  {
    v7 = sub_48D380(v6);
    if ( atol(v7) > dword_B76220 + dword_B76224 )
      v9 = 1;
  }
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 36))(this, v9);
  return 0;
}
