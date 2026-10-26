int __thiscall sub_49A830(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  unsigned int v5; // eax
  char *v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // eax
  const char *v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  unsigned int v15; // edi
  int v16; // eax
  int v18; // [esp+8h] [ebp-Ch] BYREF
  int v19; // [esp+Ch] [ebp-8h] BYREF
  int v20; // [esp+10h] [ebp-4h] BYREF

  if ( this[153] == 3 || this[150] != -1 )
  {
    v7 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 62);
    if ( v7 )
    {
      sub_4DE540(&v19, &v18);
      if ( (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) <= 0 )
        (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
      v8 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      if ( v19 < v8 )
      {
        v9 = this[142];
        this[146] = -1;
        if ( v9 > 0 )
          this[146] = sub_4D0D20(v18);
        v10 = (const char *)sub_4CE1C0(this);
        if ( v10 )
        {
          sub_4E2AF0(v7[3], this[1] + this[146] * this[142]);
          v11 = atol(v10);
          if ( v11 < 0x68 )
            sub_4918B0(v7, v11);
        }
        else
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*v7 + 40))(v7, 0);
        }
      }
    }
  }
  else
  {
    sub_4DE540(&v19, &v20);
    if ( (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
    v2 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v19 < v2 )
    {
      v3 = this[142];
      this[146] = -1;
      if ( v3 > 0 )
        this[146] = sub_4D0D20(v20);
      v4 = (const char *)sub_4CE1C0(this);
      if ( v4 )
      {
        v5 = atol(v4);
        if ( v5 < 0x68 )
        {
          v6 = (char *)&unk_9204A0 + 22616 * v5;
          if ( *((_DWORD *)v6 + 3705) != -1 )
            sub_414450(&dword_91BF20, *((_DWORD *)v6 + 5617));
        }
      }
    }
  }
  this[146] = -1;
  if ( (unsigned __int8)sub_4745A0(&dword_B6CBA8) )
  {
    sub_4DE540(&v20, &v19);
    if ( (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
    v12 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v20 < v12 )
    {
      v13 = this[142];
      this[146] = -1;
      if ( v13 > 0 )
        this[146] = sub_4D0D20(v19);
      v14 = (const char *)sub_4CE1C0(this);
      if ( v14 )
      {
        v15 = atol(v14);
        if ( v15 < 0x68 )
        {
          v16 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 123);
          if ( v16 )
          {
            *(_DWORD *)(v16 + 276) = v15;
            sub_407620();
          }
        }
      }
    }
  }
  sub_4D4540(this);
  return 0;
}
