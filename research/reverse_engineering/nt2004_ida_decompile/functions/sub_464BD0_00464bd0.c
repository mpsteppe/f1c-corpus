bool __thiscall sub_464BD0(void *this, int a2)
{
  bool v3; // bl
  int v4; // edi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  v4 = sub_56A5B0(*(_DWORD *)(*(_DWORD *)this + 6708));
  if ( !sub_56A610(v4) )
  {
    v6 = 92;
    sub_569F60(a2, &v6);
    v3 = v6 == 92;
  }
  sub_56A5E0(*(_DWORD *)(*(_DWORD *)this + 6708), v4);
  return v3;
}
