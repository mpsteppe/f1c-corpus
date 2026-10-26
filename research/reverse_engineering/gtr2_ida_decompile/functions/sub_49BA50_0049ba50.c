int __thiscall sub_49BA50(void *this)
{
  int v2; // eax
  char v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  if ( *(_DWORD *)dword_B72314 == 4 )
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 40))(this, 1);
  else
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
  v2 = sub_532D20(&unk_B76270);
  if ( v2 && *(_DWORD *)(v2 + 95732) != 1 )
    v4 = 0;
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 36))(this, v4);
  return 0;
}
