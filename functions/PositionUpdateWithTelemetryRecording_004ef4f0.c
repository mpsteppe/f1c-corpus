void __thiscall sub_4EF4F0(int this)
{
  _DWORD *v1; // eax

  if ( dbl_8AFEA0 > *(float *)(this + 16404) + 4.5 )
  {
    *(float *)(this + 16404) = dbl_8AFEA0;
    if ( dword_83EE60 >= 1023 )
    {
      v1 = (_DWORD *)dword_8AAE64;
    }
    else
    {
      ++dword_83EE60;
      v1 = (_DWORD *)dword_8AAE64;
      dword_8AAE64 += 432;
    }
    ProgressBarEventEncode(v1, 2, 0, 0, *(_DWORD *)(this + 4), *(_DWORD *)(this + 13484), 0);
  }
}
