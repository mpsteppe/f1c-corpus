int __thiscall sub_477EF0(void *this)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  dword_76842C = 0;
  if ( dword_768434 <= 0 )
  {
    if ( dword_768438 < 0 )
      dword_76842C = dword_768438;
  }
  else
  {
    dword_76842C = dword_768434;
  }
  sub_4AE870(&v5, v6);
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
  if ( v5 < v2 )
  {
    v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
    if ( v5 < v3 )
      sub_477F70(1, 1);
  }
  return 0;
}
