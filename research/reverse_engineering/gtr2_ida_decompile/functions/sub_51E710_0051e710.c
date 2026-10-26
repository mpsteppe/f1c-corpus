int __fastcall sub_51E710(int a1, int a2, int a3)
{
  int v5; // esi
  int v6; // eax

  if ( (dword_B70618[0] != 1 || *(_DWORD *)dword_B72314 == 8)
    && ((v5 = (unsigned __int8)((*(unsigned __int16 (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 576))(dword_FB27A4) >> 8),
         v6 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 576))(dword_FB27A4),
         v5 > 1)
     || v6 >= 4) )
  {
    return sub_51E780(a1, a2, a3);
  }
  else
  {
    return 1;
  }
}
