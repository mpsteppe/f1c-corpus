void __thiscall sub_4742B0(int this)
{
  int v2; // edi
  void **v3; // eax
  void **v4; // esi
  char *v5; // eax
  float v6; // [esp+0h] [ebp-360h]
  char v7; // [esp+8h] [ebp-358h]
  unsigned int v8; // [esp+10h] [ebp-350h] BYREF

  v6 = dbl_FB1D18;
  sub_51B2A0(4, 42, 0, 255, LODWORD(v6), 3);
  v2 = sub_59B480(*(_DWORD *)(this + 113316));
  *(_BYTE *)(v2 + 4) = 1;
  sub_59B7F0((char)&v8, ((v8 >> 8) & 0x3FF) + 8, v2, 1, 1, -1, 0);
  sub_59B490(*(_DWORD *)(this + 113316), v2);
  *(_BYTE *)(this + 1185) = 0;
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
  sub_615860("*** Closing track");
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 5623) )
  {
    v5 = (char *)*v4;
    if ( !*v4 )
      v5 = (char *)WindowName;
    sub_561210((int)byte_FAE910, v5, v7);
  }
  if ( v4 )
  {
    if ( *v4 )
      j_j__free(*v4);
    j__free(v4);
  }
}
