// Address: 0x004cdad0
// Size: 78 bytes
// Name: sub_4CDAD0
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4CDAD0(_DWORD *this)
{
  double v2; // st7
  int result; // eax
  int i; // esi
  int v5; // ecx
  float v6; // [esp+8h] [ebp-4h]

  if ( dword_8AB6E4 == 2 )
  {
    v2 = sub_4B9CE0(&unk_8AB6EC);
    result = this[25];
    for ( i = 0; i < result; ++i )
    {
      v5 = *(_DWORD *)(this[26] + 4 * i);
      v6 = v2;
      if ( v6 < (double)*(float *)(v5 + 8) )
      {
        sub_4CB5A0(v5);
        --i;
      }
      result = this[25];
    }
  }
  return result;
}
