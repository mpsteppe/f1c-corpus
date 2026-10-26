int __thiscall sub_553700(unsigned int *this, int a2)
{
  int result; // eax
  unsigned int v4; // eax
  int v5; // eax
  signed int v6; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // eax
  signed int v10; // edx
  int v11; // ecx
  _DWORD *v12; // eax
  int v13[10]; // [esp+1Ch] [ebp-224h] BYREF
  _DWORD v14[16]; // [esp+44h] [ebp-1FCh] BYREF
  _DWORD v15[111]; // [esp+84h] [ebp-1BCh] BYREF

  result = this[1];
  if ( result > 0 )
  {
    if ( (BYTE1(*this) & 0x80u) != 0 )
    {
      v4 = *this & 0xFFFF7FFF;
      *this = v4;
      if ( (v4 & 1) != 0 )
      {
        v5 = sub_540F00(dword_8B78A0, (_DWORD *)this[5], 96, 0, 0);
        v6 = 0;
        if ( (int)this[1] > 0 )
        {
          v7 = 0;
          v8 = (_DWORD *)(v5 + 8);
          do
          {
            *(v8 - 2) = *(_DWORD *)(v7 + this[6]);
            *(v8 - 1) = *(_DWORD *)(v7 + this[6] + 4);
            *v8 = *(_DWORD *)(v7 + this[6] + 8);
            v8[2] = *(_DWORD *)(v7 + this[6] + 16);
            v8[3] = *(_DWORD *)(v7 + this[6] + 20);
            v8[1] = *(_DWORD *)(v7 + this[6] + 12);
            ++v6;
            v7 += 24;
            v8 += 6;
          }
          while ( v6 < (int)this[1] );
        }
      }
      else if ( (v4 & 2) != 0 )
      {
        v9 = sub_540F00(dword_8B78A0, (_DWORD *)this[5], 96, 0, 0);
        v10 = 0;
        if ( (int)this[1] > 0 )
        {
          v11 = 0;
          v12 = (_DWORD *)(v9 + 8);
          do
          {
            *(v12 - 2) = *(_DWORD *)(v11 + this[6]);
            *(v12 - 1) = *(_DWORD *)(v11 + this[6] + 4);
            *v12 = *(_DWORD *)(v11 + this[6] + 8);
            v12[1] = *(_DWORD *)(v11 + this[6] + 12);
            v12[3] = *(_DWORD *)(v11 + this[6] + 20);
            v12[4] = *(_DWORD *)(v11 + this[6] + 24);
            v12[2] = *(_DWORD *)(v11 + this[6] + 16);
            ++v10;
            v11 += 28;
            v12 += 7;
          }
          while ( v10 < (int)this[1] );
        }
      }
      sub_540F90(dword_8B78A0, this[5]);
    }
    if ( !dword_8B8DF0 )
      sub_5550A0(dword_8B78A0);
    if ( a2 != dword_8B8DC8 )
    {
      sub_55CDF0(dword_8B78A0);
      sub_53B130(v13);
      sub_55CA40(2, v14);
      v14[0] = 1059256707;
      v14[5] = 1059256707;
      v14[10] = 1038323257;
      v14[11] = 1065353216;
      v14[14] = -1137308831;
      v14[15] = 0;
      sub_55CA40(4, v14);
      sub_55CA90(a2, 1);
      nullsub_6();
    }
    if ( dword_8B8CEC > 1 )
    {
      sub_5418B0(v15);
      sub_542200((int)v15, flt_8B8CF0, 0.0, flt_8B8CF4, 1.0, 0);
      sub_55CC20(v15);
      j_nullsub_3(v15);
    }
    sub_541120(dword_8B78A0, dword_8B8F28, this[5], 0, this[1], this[4], this[2], this[3], 3, 2);
    if ( !dword_8B8DF0 )
      sub_5550C0(dword_8B78A0);
    result = dword_8B8DC8;
    if ( a2 != dword_8B8DC8 )
    {
      sub_55CA90(dword_8B8DC8, 1);
      return sub_55CE50(dword_8B78A0);
    }
  }
  return result;
}
