int __thiscall sub_496750(void *this)
{
  BOOL v2; // esi
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  int v6; // ecx
  char *v7; // eax
  int v8; // eax

  v2 = 1;
  v3 = (_DWORD *)sub_616840("UnlockGold");
  if ( v3 )
  {
    v4 = sub_48D380(v3);
    v2 = atol(v4) <= dword_B76220;
  }
  v5 = (_DWORD *)sub_616840("UnlockPass");
  if ( v5 )
  {
    v7 = sub_48D380(v5);
    v8 = atol(v7);
    v6 = dword_B76220;
    if ( v8 > dword_B76220 + dword_B76224 )
      v2 = 0;
  }
  LOBYTE(v6) = v2;
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, v6);
  return 0;
}
