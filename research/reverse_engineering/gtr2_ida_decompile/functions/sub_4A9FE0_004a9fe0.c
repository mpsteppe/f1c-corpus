int __thiscall sub_4A9FE0(void *this)
{
  int v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    v2 = sub_532D20(&unk_B76270);
    if ( v2 )
      v4 = *(_DWORD *)(v2 + 95732) != 3;
  }
  return (*(int (__thiscall **)(void *, bool))(*(_DWORD *)this + 40))(this, v4);
}
