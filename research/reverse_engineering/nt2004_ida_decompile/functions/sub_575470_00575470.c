char __thiscall sub_575470(int *this, _DWORD *a2)
{
  if ( sub_576D90(a2) )
  {
    sub_574E40(this, (int)a2);
  }
  else
  {
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 44))(this, a2);
    sub_5742A0(this, a2);
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 92))(this, a2);
  }
  return 1;
}
