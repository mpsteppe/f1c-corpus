void __thiscall sub_51E980(float *this)
{
  _DWORD *v1; // ecx
  int v3; // edi
  int v4; // eax
  double v5; // st7
  _DWORD *v6; // ecx
  int v7; // ecx
  float v8; // [esp+4h] [ebp-4h]

  if ( dword_B70618[0] != 1 || *(_DWORD *)dword_B72314 == 8 )
  {
    v3 = (unsigned __int8)((*(unsigned __int16 (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 576))(dword_FB27A4) >> 8);
    v4 = (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 576))(dword_FB27A4);
    if ( v3 > 1 || v4 >= 4 )
    {
      *((_DWORD *)this + 1) = sub_410A80(&dword_91BF20);
      this[57] = 0.44999999;
      this[57] = (1.0 - flt_FB20E8) * 0.44999999;
      if ( this[57] >= 0.0 )
      {
        if ( this[57] > 0.44999999 )
          this[57] = 0.44999999;
      }
      else
      {
        this[57] = 0.0;
      }
      v8 = sub_592980(&dword_FB1EF8);
      v5 = sub_592980(&dword_FB1EF8);
      v6 = *(_DWORD **)this;
      this[56] = v5 * v8 * flt_B7177C;
      sub_51E5E0(v6);
      sub_51D420((int)this);
      sub_51D490(v7);
      v1[38] = 1065353216;
      v1[39] = 0;
      v1[40] = 0;
      v1[41] = 0;
      v1[42] = 0;
      v1[43] = -1082130432;
      v1[44] = 0;
      v1[45] = 0;
      v1[46] = 0;
      v1[47] = 0;
      v1[48] = 1065353216;
      v1[49] = 0;
      v1[50] = 0;
      v1[51] = 0;
      v1[52] = 0;
      v1[53] = 1065353216;
    }
  }
}
