void __thiscall sub_4FA450(float *this)
{
  float *v1; // edi
  size_t v2; // ecx
  signed int v3; // esi
  int v4; // eax
  int v5; // ecx
  float v6; // [esp+0h] [ebp-2Ch]
  float v7; // [esp+Ch] [ebp-20h]
  float v9; // [esp+14h] [ebp-18h] BYREF
  float v10; // [esp+18h] [ebp-14h]
  float v11; // [esp+1Ch] [ebp-10h]
  _DWORD v12[3]; // [esp+20h] [ebp-Ch] BYREF

  v1 = this;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  memset(v12, 0, sizeof(v12));
  sub_404590(&flt_628F60, 0, &v9, v12);
  if ( v9 != 0.0 || v10 != 0.0 || v11 != 0.0 )
  {
    v2 = NumOfElements;
    v3 = 0;
    if ( (int)NumOfElements > 0 )
    {
      v7 = v1[46];
      do
      {
        v4 = *(_DWORD *)(dword_75AAD0[v3] + 20876) - 1;
        v5 = v2 - 1;
        if ( v4 >= 0 )
        {
          if ( v4 > v5 )
            v4 = v5;
        }
        else
        {
          v4 = 0;
        }
        sub_404590(&flt_628F60, v4, &v9, v12);
        sub_51BE20(&v9, v12);
        sub_51F160(v7);
        sub_4C1BA0((_DWORD *)(dword_75AAD0[v3] + 16588));
        *(_DWORD *)(dword_75AAD0[v3] + 20852) = 2;
        *(_DWORD *)(dword_75AAD0[v3] + 21116) = 0;
        sub_42CB20(dword_75AAD0[v3]);
        v2 = NumOfElements;
        ++v3;
      }
      while ( v3 < (int)NumOfElements );
      v1 = this;
    }
    sub_4BBDC0(&unk_766220, 0);
    if ( sub_42DBA0() )
    {
      if ( *(_DWORD *)(dword_75AACC + 16584) == 1 )
        sub_45D100(&byte_764D68, (int)aPrepareForManu, 3, 16909060, 0);
    }
    sub_42F950(&dword_75CBA8, 5);
    v6 = dbl_7DA9D0;
    sub_4FAFF0(LODWORD(v6), -1);
    *((_BYTE *)v1 + 188) = 1;
    sub_51BC20(1, 1);
    sub_42CB20(dword_75AACC);
    dword_7DA9B4 = 1080033280;
    flt_7DA9B0 = 3.5;
    sub_42DD60(dbl_7DA9D0);
  }
}
