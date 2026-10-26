void __thiscall sub_4D98A0(int *this, float a2, _DWORD *a3)
{
  void *v4; // edi
  int v5; // ebp
  float v6; // eax
  double v7; // st7
  float *v8; // edx
  char v9; // bl
  char *v10; // eax
  CHAR *v11; // eax
  char *v12; // eax
  float v13; // [esp+0h] [ebp-18h]
  float v14; // [esp+4h] [ebp-14h]
  char v15; // [esp+14h] [ebp-4h]

  if ( !byte_76617C && (dword_75CBB0 != 7 || dword_75CBB4 >= 5) && flt_7DA9B0 == 0.0 )
  {
    if ( *(_BYTE *)(*this + 2068) )
    {
      if ( sub_41F230(dword_62A170, aInstantReplays, Destination) )
      {
        strncpy(Destination, aInstantReplays, 0x1FFu);
        byte_62A37B = 0;
      }
      sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
    }
    else
    {
      v15 = byte_75CBB8;
      sub_42FA50(&dword_75CBA8, 1);
      v4 = (void *)sub_40C460(&dword_6291CC);
      v5 = *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248);
      v6 = a2;
      *a3 = 2;
      *(float *)(*this + 2152) = v6;
      if ( sub_4D8450(*this) )
      {
        v7 = a2;
        if ( a2 >= 10.0 )
        {
          if ( v7 > 180.0 )
            v7 = 180.0;
        }
        else
        {
          v7 = 10.0;
        }
        v14 = dbl_7DA9D0 - v7;
        sub_4D9E10(LODWORD(v14));
        *(float *)(*this + 2156) = sub_4D9E20(this);
        sub_40C410(&dword_6291CC, aTrackside, 0);
        v8 = (float *)*this;
        LODWORD(a2) = 2;
        do
        {
          v9 = sub_4D8860(v8, &a2);
          a2 = COERCE_FLOAT(sub_4D8960());
        }
        while ( v9 );
        v13 = dbl_7DA9D0;
        sub_4D9E10(LODWORD(v13));
        sub_42DB60(v5);
        if ( v4 )
        {
          v10 = sub_459BA0(v4);
          sub_40C410(&dword_6291CC, v10, 0);
          v11 = sub_459BA0(v4);
          if ( _strcmpi(v11, aTrackside) )
          {
            v12 = sub_459B80((CHAR ***)v4);
            sub_40C400((int ***)&dword_6291CC, v12);
          }
        }
        sub_4D8670(*this);
      }
      *a3 = 1;
      sub_42FA50(&dword_75CBA8, v15);
      if ( v15 )
        sub_4F0190(&byte_7D6B78);
      else
        sub_4F01B0(&byte_7D6B78);
    }
  }
}
