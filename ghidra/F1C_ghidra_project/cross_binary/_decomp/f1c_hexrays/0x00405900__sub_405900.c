// f1c  0x00405900  size=236
int __thiscall sub_405900(_DWORD *this, int a2, int a3, float a4, float a5, int a6, int a7)
{
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD *v12; // ecx
  int v13[3]; // [esp+Ch] [ebp-Ch] BYREF

  if ( sub_405E60(a5, a6, a3, SLODWORD(a4), (int)&a4, (int)v13) )
    return 1;
  v9 = a7;
  if ( !this[22] )
  {
    v10 = (_DWORD *)sub_4070E0(a2, a4, a7);
    this[22] = v10;
    if ( !v10 )
      return 1;
    *v10 = this;
    v11 = *(_DWORD *)(this[22] + 16);
    if ( v11 )
    {
      v12 = (_DWORD *)this[23];
      if ( v12 )
      {
        AIL_set_sample_file(v11, *v12, -1);
        if ( this[5] == 1 )
          AIL_set_sample_loop_count(*(_DWORD *)(this[22] + 16), 0);
        else
          AIL_set_sample_loop_count(*(_DWORD *)(this[22] + 16), 1);
        sub_4060C0(this);
      }
    }
  }
  *(_DWORD *)(this[22] + 4) = a2;
  *(float *)(this[22] + 8) = a4;
  *(_BYTE *)(this[22] + 12) = 1;
  if ( v9 )
  {
    sub_405B90(this);
    *(_BYTE *)(this[22] + 12) = 0;
  }
  return 0;
}
