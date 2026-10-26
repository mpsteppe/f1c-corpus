void __thiscall sub_600480(int this)
{
  int v2; // edi
  int v3; // eax

  sub_5FEB00((unsigned int *)this);
  if ( (*(_DWORD *)this & 0x40000) != 0 )
  {
    v2 = *(_DWORD *)dword_FB27A4;
    v3 = sub_5E2E00(*(_DWORD **)(this + 268), 0);
    (*(void (__thiscall **)(int, int, int))(v2 + 336))(dword_FB27A4, v3, 1);
  }
  *(_DWORD *)this = *(_DWORD *)this & 0xFFFBFFFB | 4;
}
