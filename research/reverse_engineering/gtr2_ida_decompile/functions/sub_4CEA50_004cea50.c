int __thiscall sub_4CEA50(_BYTE *this)
{
  int v3; // eax
  int v4; // eax
  int v5; // edx
  int v6; // edx
  int v7; // eax

  if ( this[100] )
    return -1;
  v3 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 172))(this);
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 5);
      v4 = *(_DWORD *)this;
      *((_DWORD *)this + 209) = 0;
      (*(void (__thiscall **)(_BYTE *, int))(v4 + 180))(this, 1);
      v5 = *(_DWORD *)this;
      this[268] = 0;
      (*(void (__thiscall **)(_BYTE *))(v5 + 168))(this);
    }
  }
  else
  {
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 4);
    v6 = *(_DWORD *)this;
    *((_DWORD *)this + 209) = 0;
    (*(void (__thiscall **)(_BYTE *, _DWORD))(v6 + 180))(this, 0);
    v7 = *(_DWORD *)this;
    this[268] = 0;
    (*(void (__thiscall **)(_BYTE *))(v7 + 168))(this);
  }
  if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 144))(this) )
    sub_4CD570();
  return 0;
}
