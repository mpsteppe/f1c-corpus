int __usercall sub_4CDAD0@<eax>(_DWORD *a1@<ecx>, double a2@<st0>)
{
  int result; // eax
  int i; // esi
  int v5; // ecx
  float v6; // [esp+8h] [ebp-4h]

  if ( dword_8AB6E4 == 2 )
  {
    sub_4B9CE0(&dword_8AB6EC);
    result = a1[25];
    for ( i = 0; i < result; ++i )
    {
      v5 = *(_DWORD *)(a1[26] + 4 * i);
      v6 = a2;
      if ( v6 < (double)*(float *)(v5 + 8) )
      {
        sub_4CB5A0(a1, (_DWORD *)v5);
        --i;
      }
      result = a1[25];
    }
  }
  return result;
}
