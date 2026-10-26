int __thiscall sub_407A60(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edx

  (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
  sub_53C170();
  AIL_startup();
  AIL_set_preference(31, 0);
  v3 = this[21];
  if ( v3 )
    v4 = v3 != 1 ? 44100 : 22050;
  else
    v4 = 11025;
  v5 = AIL_open_digital_driver(v4, 16, 2, 0);
  this[36] = v5;
  if ( v5 )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 56))(this, 12);
    AIL_set_DirectSound_HWND(this[36], a2);
    this[22] = 0;
    this[23] = 0;
    this[24] = 0;
    this[28] = 0;
    this[29] = 0;
    this[30] = 0;
    this[31] = 0;
    this[32] = 0;
    this[33] = 0;
    AIL_set_file_callbacks(sub_405D00, 4218288, 4218384, 4218672);
    this[34] = 1;
    return 0;
  }
  else
  {
    v6 = *this;
    this[36] = 0;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(v6 + 56))(this, 0);
    AIL_shutdown();
    this[34] = 0;
    return 1;
  }
}
