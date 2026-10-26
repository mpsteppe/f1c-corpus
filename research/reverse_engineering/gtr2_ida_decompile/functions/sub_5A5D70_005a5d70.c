char __thiscall sub_5A5D70(int *this, _DWORD *a2)
{
  if ( sub_5A6C10(a2) )
  {
    sub_5A4700();
  }
  else
  {
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 44))(this, a2);
    sub_5A5000(this, a2);
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 92))(this, a2);
  }
  return 1;
}
