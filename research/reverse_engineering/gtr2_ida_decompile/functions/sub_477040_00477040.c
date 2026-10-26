void __thiscall sub_477040(int this, int a2)
{
  char v3; // al
  char v4; // dl
  _BYTE *v5; // ecx
  int v6; // esi
  float v7; // [esp+1Ch] [ebp-83Ch]
  float v8; // [esp+20h] [ebp-838h]
  _BYTE v9[28]; // [esp+698h] [ebp-1C0h] BYREF
  _BYTE v10[176]; // [esp+6B4h] [ebp-1A4h] BYREF

  v3 = *(_BYTE *)(this + 302725);
  v4 = *(_BYTE *)(this + 302724);
  v5 = (_BYTE *)(this + 302704);
  *v5 = v4;
  v5[1] = v3;
  if ( *(_BYTE *)(this + 1185) )
  {
    if ( *(float *)(this + 1188) < 0.0 )
    {
      sub_473460(v9);
      if ( !(unsigned __int8)sub_473900() || (v6 = dword_BE1CD8 + 396 * dword_BE1CD4, v6 == sub_53A220(v10)) )
      {
        v7 = dbl_FB1D18;
        sub_51B2A0(4, 32, 20, 0, LODWORD(v7), 3);
        v8 = dbl_FB1D18;
        sub_4015C0(v8);
        off_16C9690(a2);
      }
    }
  }
}
