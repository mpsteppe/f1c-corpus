// f1c  0x004630d0  size=101
bool __thiscall sub_4630D0(void *this, int a2)
{
  bool v3; // bl
  int v4; // edi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  v4 = sub_57A880(*(_DWORD *)(*(_DWORD *)this + 16312));
  if ( !sub_57A8E0(v4) )
  {
    v6 = 128;
    sub_57A230(a2, &v6);
    v3 = v6 == 128;
  }
  sub_57A8B0(*(_DWORD *)(*(_DWORD *)this + 16312), v4);
  return v3;
}
