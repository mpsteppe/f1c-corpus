void __thiscall sub_404F30(void *this)
{
  int v1; // ecx
  _DWORD *v3; // ecx

  sub_4A0250(&unk_7CE24C);
  SystemOSAPICall(&unk_7CE24C);
  if ( ConditionalFlagReturn(this) )
    LookupDispatch(aMainMenu, -1);
  v3 = *(_DWORD **)this;
  if ( *(_BYTE *)(*(_DWORD *)this + 20) && v3[8] == 1 )
  {
    dword_7D2E44 = v3[20];
    v1 = v3[21];
    dword_7D0410 = v1;
    if ( v1 >= dword_7D0418 )
    {
      if ( v1 > dword_7D041C )
        dword_7D0410 = dword_7D041C;
    }
    else
    {
      dword_7D0410 = dword_7D0418;
    }
    byte_5EA53E = 0;
    SafeDivisionWithZeroGuard(0.1);
    if ( flt_7CF380 > 0.0 )
      VirtualDispatchStateReset(&byte_8AC494);
  }
}
