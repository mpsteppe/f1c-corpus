bool __thiscall sub_614460(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  bool v6; // bl
  char String2[1024]; // [esp+Ch] [ebp-400h] BYREF

  v4 = 0;
  this[21] = 0;
  while ( *(_BYTE *)(a2 + v4) == Str2[v4] )
  {
    if ( ++v4 >= 2 )
    {
      this[5] = 5;
      goto LABEL_6;
    }
  }
  this[5] = 1;
LABEL_6:
  (*(void (__thiscall **)(_DWORD *))(*this + 20))(this);
  sub_617930(1024);
  if ( this[5] == 5 )
    v5 = sub_6140D0((int **)&unk_FB4138, String2);
  else
    v5 = sub_62AD30(String2);
  v6 = v5 != 0;
  this[1] = v5;
  this[4] = a3;
  *((_BYTE *)this + 28) = 1;
  if ( v5 )
  {
    sub_615860(String2);
    sub_614160((int)this);
  }
  return v6;
}
