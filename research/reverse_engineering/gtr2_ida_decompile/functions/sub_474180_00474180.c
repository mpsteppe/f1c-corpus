void __thiscall sub_474180(int this)
{
  int v2; // edi
  void **v3; // eax
  void **v4; // esi
  char *v5; // eax
  float v6; // [esp+30h] [ebp-3A0h]
  int v7; // [esp+34h] [ebp-39Ch] BYREF
  char ArgList; // [esp+3Ch] [ebp-394h] BYREF
  unsigned int v9; // [esp+80h] [ebp-350h] BYREF

  v6 = dbl_FB1D18;
  sub_51B2A0(4, 43, 0, 255, LODWORD(v6), 3);
  v2 = sub_59B480(*(_DWORD *)(this + 113316));
  v7 = 0;
  *(_BYTE *)(v2 + 4) = 1;
  sub_59B7F0((char)&v9, ((v9 >> 8) & 0x3FF) + 8, v2, 1, 1, -1, v7);
  sub_59B490(*(_DWORD *)(this + 113316), v2);
  *(_BYTE *)(this + 1185) = 1;
  v3 = (void **)operator new(8u);
  if ( v3 )
  {
    *v3 = 0;
    v3[1] = (void *)-1;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  sub_615860("*** Opening ");
  sub_53A390(&unk_BE1CFD);
  sub_615A50(&v7);
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 5587) )
  {
    v5 = (char *)*v4;
    if ( !*v4 )
      v5 = (char *)WindowName;
    sub_561210((int)byte_FAE910, v5, (char)&ArgList);
  }
  if ( v4 )
  {
    if ( *v4 )
      j_j__free(*v4);
    j__free(v4);
  }
}
