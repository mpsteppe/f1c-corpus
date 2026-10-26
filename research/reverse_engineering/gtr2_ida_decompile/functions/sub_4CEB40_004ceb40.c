int __thiscall sub_4CEB40(void *this)
{
  int v3; // eax
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  if ( *((_BYTE *)this + 100) )
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 6);
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
    return 0;
  }
  if ( *((_DWORD *)this + 33) == 6
    || (sub_4DE540(&v5, &v4), !(*(int (__thiscall **)(void *, int, int))(*(_DWORD *)this + 20))(this, v5, v4)) )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 44))(this, 0);
  }
  else
  {
    v3 = *((_DWORD *)this + 33);
    if ( v3 >= 0 && (v3 <= 3 || v3 == 6) )
    {
      (*(void (__thiscall **)(void *))(*(_DWORD *)this + 52))(this);
      (*(void (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
      return 0;
    }
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
  return 0;
}
