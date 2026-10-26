void __thiscall sub_4FE060(int this, int a2)
{
  float *v3; // ecx

  if ( (dword_7C56A0 & 1) == 0 || dword_8AB6E4 == 2 && !sub_4B9A00(&dword_8AB6EC) )
  {
    sub_4FC910((float *)(this + 32), a2);
    if ( fabs(*(float *)(this + 8) - *v3) <= 0.5 )
      *(_DWORD *)(this + 4) = 0x40000000;
    else
      *(_DWORD *)(this + 4) = 0;
    sub_4FD6F0((float *)this);
  }
}
