void __thiscall sub_4605C0(int this)
{
  int v1; // eax
  _DWORD *v2; // esi
  int v3; // edx
  char *v4; // eax

  if ( *(float *)(this + 652) >= 0.667 && !byte_76617C )
  {
    v1 = 20;
    v2 = &unk_763C34;
    v3 = 880;
    while ( !*v2 )
    {
      v3 += 44;
      ++v1;
      v2 += 11;
      if ( v3 > 1364 )
        return;
    }
    v4 = (char *)dword_766424[7 * v1];
    if ( !v4 )
      v4 = &byte_629120;
    sub_460490((_DWORD *)this, v4, 1);
  }
}
