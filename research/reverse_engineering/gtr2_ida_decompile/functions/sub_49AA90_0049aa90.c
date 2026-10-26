int __thiscall sub_49AA90(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  unsigned int v5; // edi
  _DWORD *v6; // edi
  int v7; // eax
  int v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  if ( (int)this[150] >= 0 || this[153] == 3 )
  {
    this[150] = -1;
  }
  else
  {
    sub_4DE540(&v9, &v10);
    if ( (*(int (__thiscall **)(_DWORD *))(*this + 12))(this) <= 0 )
      (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
    v2 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v9 < v2 )
    {
      v3 = this[142];
      this[146] = -1;
      if ( v3 > 0 )
        this[146] = sub_4D0D20(v10);
      v4 = (const char *)sub_4CE1C0(this);
      if ( v4 )
      {
        v5 = atol(v4);
        if ( v5 < 0x68 )
        {
          if ( !this[153] )
            (*(void (__thiscall **)(_DWORD *))(*this + 132))(this);
          v6 = (_DWORD *)((char *)&unk_9204A0 + 22616 * v5);
          v7 = v6[3705];
          if ( v7 != -1 && (int)v6[4821] >= 1 && v7 != 4 )
          {
            this[150] = v6[5617];
            this[146] = -1;
            return 0;
          }
        }
      }
    }
  }
  this[146] = -1;
  return 0;
}
