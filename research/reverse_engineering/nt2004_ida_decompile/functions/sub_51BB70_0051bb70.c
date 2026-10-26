void __thiscall sub_51BB70(int this)
{
  _DWORD *v1; // eax

  if ( dbl_7DA9D0 > *(float *)(this + 20724) + 4.5 )
  {
    *(float *)(this + 20724) = dbl_7DA9D0;
    if ( dword_79FC40 >= 1023 )
    {
      v1 = (_DWORD *)dword_7D3C44;
    }
    else
    {
      ++dword_79FC40;
      v1 = (_DWORD *)dword_7D3C44;
      dword_7D3C44 += 208;
    }
    sub_4D0D00(v1, 2, 0, 0, *(_DWORD *)(this + 4), *(_DWORD *)(this + 17480), 0);
  }
}
