void __thiscall sub_4FAF90(int this, int a2)
{
  *(_BYTE *)(this + 161) = 0;
  *(float *)(this + 148) = dbl_7DA9D0;
  *(_DWORD *)(this + 152) = *(_DWORD *)(a2 + 12);
  sub_42F950(&dword_75CBA8, *(_DWORD *)(a2 + 8));
  if ( *(_DWORD *)(a2 + 8) == 3 )
    sub_45D100(&byte_764D68, (int)aBeginningPaceL, 3, 16909060, 0);
}
