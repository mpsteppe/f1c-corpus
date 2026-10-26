void __thiscall sub_4F93E0(int this)
{
  int v1; // ebx
  int v2; // esi
  signed int v3; // ebp
  int v4; // ecx
  float *v5; // eax
  char v6; // al
  int v7; // ecx
  char v8; // bl
  long double v9; // st7
  signed int v10; // eax
  char v11; // [esp+Dh] [ebp-Fh]
  bool v12; // [esp+Eh] [ebp-Eh]
  char v13; // [esp+Fh] [ebp-Dh]
  char i; // [esp+10h] [ebp-Ch]
  float v15; // [esp+14h] [ebp-8h]

  v1 = this;
  v2 = 0;
  if ( (int)NumOfElements > 0 )
  {
    i = 0;
    if ( *(_DWORD *)(this + 280) )
      goto LABEL_28;
    if ( dword_75CBB0 != 7 || dword_75CBB4 != 5 || (v11 = 1, *(float *)(this + 148) + 10.0 <= dbl_7DA9D0) )
      v11 = 0;
    v3 = NumOfElements;
    v4 = (int)NumOfElements / dword_6119AC * dword_7D78F0;
    if ( dword_7D78F0 != dword_6119AC - 1 )
      v3 = v4 + (int)NumOfElements / dword_6119AC;
    v2 = (int)NumOfElements / dword_6119AC * dword_7D78F0;
    if ( v4 < v3 )
    {
      while ( 1 )
      {
        v5 = (float *)dword_75AAD0[v2];
        v15 = sqrt(v5[4407] * v5[4407] + v5[4408] * v5[4408] + v5[4409] * v5[4409]);
        v6 = sub_51C730(v5 + 21);
        v7 = dword_75AAD0[v2];
        v8 = *(_BYTE *)(v7 + 17412);
        v12 = *(_DWORD *)(v7 + 17416) == 3;
        v13 = v6;
        if ( v15 < 0.1 && !v11 && !v6 && !v8 )
          break;
        if ( *(float *)(v7 + 20776) > 0.0 )
          break;
        v9 = fabs(sub_51C630(v7 + 84));
        if ( v15 > 0.1 && v9 < 0.5 && !v12 && !v8 && !v13 )
          break;
        if ( ++v2 >= v3 )
          goto LABEL_25;
      }
      v10 = 0;
      for ( i = 1; v10 < (int)NumOfElements; ++v10 )
      {
        if ( !*(_BYTE *)(dword_75AAD0[v10] + 20872) )
          break;
      }
      if ( v10 == NumOfElements )
        i = 0;
LABEL_25:
      v1 = this;
    }
    dword_7D78F0 = (dword_7D78F0 + 1) % dword_6119AC;
    if ( i || *(_DWORD *)(v1 + 280) )
LABEL_28:
      sub_4F9670(i, v2);
  }
}
