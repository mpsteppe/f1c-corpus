int __thiscall sub_4CEC00(void *this)
{
  int v2; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  sub_4DE540(v5, v4);
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 172))(this);
  if ( v2 )
  {
    if ( v2 == 1 )
      (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(3);
    else
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this + 44))(0);
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 44))(this, 2);
    return 0;
  }
}
