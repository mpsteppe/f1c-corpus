char __thiscall sub_4646E0(void *this, int a2, int a3)
{
  if ( sub_56A2B0(*(_DWORD *)(*(_DWORD *)this + 6708), a2, a3) )
    return 0;
  *(_BYTE *)(*(_DWORD *)this + 33) = 1;
  sub_4CE760(&unk_7663E0);
  *(float *)(*(_DWORD *)this + 16) = 5.0;
  *(_DWORD *)(*(_DWORD *)this + 6720) = 4;
  return 1;
}
