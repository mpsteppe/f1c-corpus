void __thiscall sub_4FAFF0(int *this, int a2, int a3)
{
  signed int i; // esi
  _DWORD *v5; // ecx

  this[37] = a2;
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_4DC260((int *)(dword_75AAD0[i] + 20836), a2, a3);
  v5 = (_DWORD *)dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  sub_4D0D00(v5, 4, 38, 0, 63, this[37], 3);
  sub_45D100(&byte_764D68, (int)aGreenFlag, 3, 16909060, 0);
  sub_41BA10(0, -1);
}
