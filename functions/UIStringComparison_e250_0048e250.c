int __thiscall sub_48E250(_DWORD *this, int a2, int a3, int a4, int a5)
{
  const char *v6; // esi
  const char *v7; // eax
  int v9; // eax
  int v10; // [esp-Ch] [ebp-18h]
  int v11; // [esp-8h] [ebp-14h]

  v6 = (const char *)this[44];
  if ( !v6 )
    v6 = byte_5EA438;
  v7 = (const char *)this[58];
  if ( !v7 )
    v7 = byte_5EA438;
  if ( !strcmp(v7, v6) )
  {
    if ( !this[57] )
    {
      if ( this[56] )
      {
        v11 = this[1];
        v10 = this[3];
        v9 = GlobalAccessor_5150(&unk_7CDE00);
        BinkVideoFrameRender(v9, v10, v11, 32);
        (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      }
    }
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *))(*this + 160))(this);
    return 0;
  }
}
