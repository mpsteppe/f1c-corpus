int __thiscall sub_490D60(void *this)
{
  _DWORD *v1; // eax
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v4; // [esp+45h] [ebp-3h]
  char v5; // [esp+47h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v4 = 0;
  v5 = 0;
  v1 = (_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 188))(this);
  if ( v1 )
    sprintf(Buffer, "%d%s", *v1, " s");
  sub_615860(Buffer);
  return 0;
}
