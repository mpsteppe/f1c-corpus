void __thiscall sub_599270(int this, char a2)
{
  char v2; // bl
  const char *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  int v10; // ebp
  int v11; // ebx
  int v12; // ecx
  double v13; // st7
  float v14; // [esp+Ch] [ebp-11Ch]
  int v15; // [esp+18h] [ebp-110h]
  int v16; // [esp+1Ch] [ebp-10Ch]
  int v17; // [esp+20h] [ebp-108h]
  int v18; // [esp+24h] [ebp-104h]
  char Buffer[256]; // [esp+28h] [ebp-100h] BYREF

  v2 = a2;
  if ( !a2 )
    sub_596A40();
  *(_DWORD *)(this + 24) = 0;
  sub_5DD280(16);
  *(_BYTE *)(dword_FB27A4 + 9053) = dword_B70618[0] != 1;
  if ( (dword_B640C4 & 1) == 0 || dword_BE1204 == 2 )
  {
    *(_DWORD *)(this + 16) = 0;
  }
  else
  {
    if ( byte_B7075C[0] )
      *(float *)this = flt_FADE28;
    else
      *(_DWORD *)this = 1065353216;
    if ( !a2 )
    {
      if ( dword_B70618[0] )
        goto LABEL_13;
      v4 = (const char *)dword_91CAF8;
      if ( !dword_91CAF8 )
        v4 = WindowName;
      sprintf(Buffer, "%sweather.txt", v4);
      if ( sub_593F50() )
      {
LABEL_13:
        if ( dword_B70618[0] == 2 )
        {
          if ( *(_DWORD *)dword_B72314 == 8 || *(_DWORD *)dword_B72314 == 4 )
            v14 = 0.85000002;
          else
            v14 = flt_B70858 * 0.30000001 + 0.69999999;
        }
        else if ( dword_B70618[0] == 3 )
        {
          v14 = 0.96999997;
        }
        else
        {
          v14 = 0.2;
        }
        sub_596A40();
        v5 = operator new(0x10u);
        if ( v5 )
          v6 = sub_592940(v5);
        else
          v6 = 0;
        *(_DWORD *)(this + 64) = v6;
        *v6 = 0;
        *(_DWORD *)(*(_DWORD *)(this + 64) + 4) = 1101004800;
        *(float *)(*(_DWORD *)(this + 64) + 8) = v14;
        *(_DWORD *)(*(_DWORD *)(this + 64) + 12) = 0;
        sub_592B20(this, *(float *)(*(_DWORD *)(this + 64) + 8));
        v7 = *(_DWORD *)(this + 64);
        v8 = *(_DWORD *)(this + 40);
        *(_DWORD *)(this + 44) = v8;
        *(_DWORD *)(this + 48) = v8;
        v9 = *(float *)(v7 + 4);
        *(float *)(this + 52) = *(float *)(v7 + 4);
        *(float *)(this + 56) = v9;
      }
      v10 = *(_DWORD *)(this + 36);
      v11 = *(_DWORD *)(this + 40);
      v15 = *(_DWORD *)(this + 44);
      v16 = *(_DWORD *)(this + 48);
      v18 = *(_DWORD *)(this + 56);
      v17 = *(_DWORD *)(this + 52);
      sub_598630();
      *(_DWORD *)(this + 36) = v10;
      *(_DWORD *)(this + 40) = v11;
      v2 = a2;
      *(_DWORD *)(this + 44) = v15;
      *(_DWORD *)(this + 48) = v16;
      *(_DWORD *)(this + 52) = v17;
      *(_DWORD *)(this + 56) = v18;
    }
    v12 = *(_DWORD *)(this + 36);
    *(_DWORD *)(this + 60) = *(_DWORD *)(this + 64);
    *(_DWORD *)(this + 496) = 0;
    *(_DWORD *)(this + 4) = 0;
    *(_DWORD *)(this + 8) = v12;
    *(_BYTE *)(this + 68) = 1;
    *(_DWORD *)(this + 72) = -8388609;
    *(_WORD *)(this + 78) = -1;
    *(_WORD *)(this + 80) = -1;
    *(_WORD *)(this + 76) = 0;
    *(_WORD *)(this + 82) = 0;
    *(_WORD *)(this + 84) = 0x7FFF;
    *(_WORD *)(this + 86) = 0x8000;
    *(_DWORD *)(this + 16) = *(float *)(this + 48) > 0.0;
    v13 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.050000001;
    *(float *)(this + 492) = v13;
    if ( !v2 )
    {
      sub_592990((float *)this);
      if ( (dword_B640C4 & 1) != 0 && dword_BE1204 != 2 )
      {
        if ( strcmp((const char *)(this + 692), byte_FADE3E) )
        {
          sub_4152E0();
          sub_5930F0();
        }
      }
    }
    *(_DWORD *)(this + 704) = 0;
    *(_DWORD *)(this + 28) = -1;
    *(_DWORD *)(this + 32) = -1031798784;
  }
}
