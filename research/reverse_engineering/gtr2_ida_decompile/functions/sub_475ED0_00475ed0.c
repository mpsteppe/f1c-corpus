int sub_475ED0()
{
  int v0; // ebp
  int v1; // ebx
  int v2; // edi
  int v3; // esi
  float v5; // [esp+0h] [ebp-370h]
  _BYTE v6[839]; // [esp+29h] [ebp-347h] BYREF

  v0 = dword_757C10;
  memset(v6, 0, 0x68u);
  v1 = 0;
  v2 = 0;
  if ( dword_757C10 > 0 )
  {
    do
    {
      v3 = *(&dword_91E088 + v2);
      if ( v3 )
      {
        v6[*(_DWORD *)(v3 + 22468)] = (unsigned __int64)*(float *)(v3 + 16084);
        if ( *(_DWORD *)(v3 + 22468) > v1 )
          v1 = *(_DWORD *)(v3 + 22468);
      }
      ++v2;
    }
    while ( v2 < v0 );
  }
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 9585) )
  {
    sub_561210((int)byte_FAE910, "Sending penalties for %d slots....", v1);
  }
  v5 = dbl_FB1D18;
  sub_51B2A0(4, 50, v1 + 2, 0, LODWORD(v5), 3);
  return sub_4745E0();
}
